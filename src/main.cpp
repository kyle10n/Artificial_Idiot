#include <string>
#include <iostream>
#include <fstream>

#include "training.h"
#include "inference.h"

using namespace std;


// read whole file
string read_file(const string& filename) {
    ifstream file(filename);
    return string((istreambuf_iterator<char>(file)),
                  istreambuf_iterator<char>());
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        cerr << "Usage: " << argv[0] << " <ngram_length> <input_file> <output_length>\n";
        return 1;
    }

    int n_gram_length = stoi(argv[1]);
    string input_data = read_file(argv[2]);
    int output_length = stoi(argv[3]);

    Training model(input_data, n_gram_length);
    Inference gen(model.get_data());
    cout << gen.generate(output_length) << endl;
}