#include "training.h"
#include <string>
#include <map>
#include <unordered_set>
using namespace std;


Training::Training(string data_input, int ngram_length)
{

    learn_from_data(data_input, ngram_length, ngrams);
    insert_min_1_char(ngrams);
}

void Training::learn_from_data(const string &data_input, int ngram_length,
                               map<string, NGramEntry> &ngrams)
{
    for (int i = 0; i + ngram_length < data_input.size(); ++i)
    {
        string key = data_input.substr(i, ngram_length);
        char the_next_char = data_input[i + ngram_length];

        auto &entry = ngrams[key];
        entry.count++;
        entry.next_char[the_next_char]++;
    }
}

void Training::insert_min_1_char(map<string, NGramEntry> &ngrams)
{
    unordered_set<char> all_chars;
    for (const auto &[key, entry] : ngrams)
    {
        for (char c : key)
            all_chars.insert(c);
        for (const auto &[c, _] : entry.next_char)
            all_chars.insert(c);
    }

    for (auto &[key, entry] : ngrams)
    {
        for (char c : all_chars)
        {
            if (!entry.next_char.count(c))
            {
                entry.next_char[c] = 1;
            }
        }
    }
}

