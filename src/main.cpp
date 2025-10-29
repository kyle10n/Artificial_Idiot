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
        cerr << "Usage: " << argv[0] << "<ngram_length> <input_file><output_length>\n";
        return 1;
    }

    int n_gram_length = stoi(argv[1]);
    string input_data = read_file(argv[2]);
    int stringout = stoi(argv[3]);

    Training model(input_data, n_gram_length);
    Inference gen(model.get_data());
    cout << gen.generate(stringout, n_gram_length) << endl;
}


// take main arguments

// train on the text file and create the probability distribution

// based on the arguments given of n-gram length and length of output

// make a for loop over output length

// have a output length to append to

// counter = 0
// while counter < length of output
//     temp = ""
//     if counter > 0 temp = temp + " "
//     roll for a new ngram
//     tmp = temp + ngram