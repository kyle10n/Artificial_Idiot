#include <string>
#include <map>
#include <random>
#include "inference.h"
using namespace std;

string Inference::generate(size_t max_length, size_t n)
{
    if (transitions.empty())
        return "";

    string context = random_context();
    string output = context;
    size_t counter = output.size();

    while (counter < max_length)
    {
        char next = pick_next(context);
        string new_ngram = context.substr(1) + next;

        string tmp;
        if (!output.empty())
            tmp += " ";
        tmp += new_ngram;

        output += tmp;
        counter += tmp.size();

        context = new_ngram;
    }

    if (output.size() > max_length)
        output = output.substr(0, max_length);

    return output;
}

Inference::Inference(const unordered_map<string, map<char, int>>& data) {
    random_device rd;
    rng = mt19937(rd());

    for (const auto& [context, freqMap] : data) {
        int total = 0;
        vector<pair<char, int>> cumulativeTable;
        cumulativeTable.reserve(freqMap.size());

        for (const auto& [ch, count] : freqMap) {
            total += count;
            cumulativeTable.push_back({ch, total});
        }

        transitions[context] = move(cumulativeTable);
        totalWeights[context] = total;
    }
}

char Inference::weighted_pick(const string& context) {
    const auto& table = transitions.at(context);
    int total = totalWeights.at(context);

    uniform_int_distribution<int> dist(1, total);
    int roll = dist(rng);

    for (const auto& [ch, cumulative] : table)
        if (roll <= cumulative)
            return ch;

    return table.back().first; // fallback
}

char Inference::pick_next(string context) {
    while (!context.empty()) {
        if (transitions.count(context))
            return weighted_pick(context);
        context.erase(0, 1); // backoff
    }
    return weighted_pick(random_context());
}

string Inference::random_context() {
    int totalSum = 0;
    for (const auto& [_, total] : totalWeights)
        totalSum += total;

    uniform_int_distribution<int> dist(1, totalSum);
    int roll = dist(rng);

    for (const auto& [context, total] : totalWeights) {
        roll -= total;
        if (roll <= 0)
            return context;
    }

    return totalWeights.begin()->first;
}
