#include <string>
#include <map>
using namespace std;

class Training
{

    Training(string data_input, int ngram_length); // regular constructor

    struct NGramEntry
    {
        int count = 0;
        map<char, int> next_char;
    };

    map<std::string, NGramEntry> ngrams;

    void learn_from_data(const string &data_input, int ngram_length,
                         map<string, struct NGramEntry> &ngrams);

    void insert_min_1_char(map<string, struct NGramEntry> &ngrams);
    
};

// for example ababac as input code

// create a k-length slider

// process entire text, and sliding the context window, that is k-long

// for each k-gram store in a map to create a probability distribution of
// the k-grams for how often the k-gram appears compared to the corpus of kgrams
// so create a count then create a probaiblity

// for each k-gram also store the character that appears right after the k-gram
// to store the count and probability

// output this map:

// ababac
// AB and then next A {AB: {1,{A: 1}}}
// BA and then next B {AB: {1,{A: 1}}, BA: {1,{B: 1}}}
// AB and then next A {AB: {2,{A: 2}}, BA: {1,{B: 1}}}
// BA and then next C {AB: {2,{A: 2}}, BA: {2,{B: 1, C: 1}}}
// AC {AB: {2,{A: 2}}, BA: {2,{B: 1, C: 1}}, AC: {1}}

// then scan across each to add a minimum 1 extra occurrence to each n-gram of all
// missing next characters.

// find a list of all characters
//  {a, b, c}, insert one of each missing
//{AB: {2,{A: 2, B:1, C:1}}, BA: {2,{B: 1, C: 1, A:1}}, AC: {1}}

// which is a map<string map<string, int>>