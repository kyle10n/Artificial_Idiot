#include "training.h"
#include <unordered_set>

Training::Training(string data_input, int ngram_length) {
    learn_from_data(data_input, ngram_length);
    insert_min_1_char(ngrams);
}

void Training::learn_from_data(const string& data_input, int ngram_length) {
    for (int i = 0; i + ngram_length < (int)data_input.size(); ++i) {
        string key = data_input.substr(i, ngram_length);
        char next = data_input[i + ngram_length];
        auto& entry = ngrams[key];
        entry.count++;
        entry.next_char[next]++;
    }
}

// add all missing chars with +1 count so it doesnt get stuck
void Training::insert_min_1_char(unordered_map<string, NGramEntry>& ngrams) {
    unordered_set<char> all_chars;

    for (const auto& [key, entry] : ngrams) {
        for (char c : key) all_chars.insert(c);
        for (const auto& [c, _] : entry.next_char) all_chars.insert(c);
    }

    for (auto& [key, entry] : ngrams) {
        for (char c : all_chars)
            if (!entry.next_char.count(c))
                entry.next_char[c] = 1;
    }
}

const unordered_map<string, map<char, int>> Training::get_data() const {
    unordered_map<string, map<char, int>> result;
    for (const auto& [k, e] : ngrams)
        result[k] = e.next_char;
    return result;
}
