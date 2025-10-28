#include <string>
#include <unordered_map>
#include <map>
using namespace std;

class Training {
public:
    Training(string data_input, int ngram_length);

    const unordered_map<string, map<char, int>> get_data() const;

private:
    struct NGramEntry {
        int count = 0;
        map<char, int> next_char;
    };

    unordered_map<string, NGramEntry> ngrams;

    void learn_from_data(const string& data_input, int ngram_length);

    void insert_min_1_char(unordered_map<string, NGramEntry>& ngrams);
};