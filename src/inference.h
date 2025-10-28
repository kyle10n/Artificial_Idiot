#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <random>
using namespace std;

class Inference {
public:
    Inference(const unordered_map<string, map<char, int>>& data);

    string generate(size_t length, size_t n);

private:
    unordered_map<string, vector<pair<char, int>>> transitions;
    unordered_map<string, int> totalWeights;
    mt19937 rng;

    char weighted_pick(const string& context);
    char pick_next(string context);
    string random_context();
};
