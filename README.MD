# DNA Markov Analysis

Naive implementation of training a "language model" by taking user command of "word" sizes and producing number of words for the user. The language model is trained on text to find the probability of a character appearing based on the previous character given the length of characters by the user.

Let n(w, c) be the number of times character c follows word w in the input text,
and let n(w) be the total number of occurrences of w. We then estimate the
conditional probability as:

P (c|w) = n(w, c) / n(w)

If the word sizing is = 2 and the input text is “ababac”, then the word frequencies are:

|word    |frequency|
| ------ |:-------:|
|ab      |0.2|
|ba      |0.2|
|ac      |0.1|

This is because there are five words of size 2 in the input text, and “ab” and
“ba” appears twice, while “ac” appears once.

Here are the character transition frequencies:

|word    |next    |char frequency|
| ------ |:-------:|:-------:|
|ab      |a       |1.0|
|ba      |b       |0.5|
|ba      |c       |0.5|

However, if you notice in the repo there are animal .txt files which represent DNA sequences. If you are curious like myself, then you can see how this naive implementation of a language model can create experiments. For example for a given length of sequences recorded from a specific animal, is the distribution of the sequence similar or disimlar to another. Or given a distribution, and generation of new sequences, how likely is the new sequence to look like the original animal versus another. In other words a person with no DNA knowledge or biological knowledge can begin to experiment using computers.

# Usage
download the repo and run
>make

# Commands: 
then run your training txt file and word size, and how many words you would like to generate

>./slm 2 ./text/ababac.txt 10

slm <int #of_word_size> <string filename.txt> <int #of_characters>

# Requirements
c++, and make, and g++ compiler.

## Files and short Explanation

The training.cpp and training.h are files for training the model
training class
    ingest the text
    go through with the window size of words and save to a map the counts, go through entire text.
    for each word save a next character
    save as a "model"

The inference.cpp and inference.h are files for generating the next token
inferencing class
    take the model
    take number of words to generate as given
    generate a random words based on the model

main code to command the command line
    take user commands
    make a training model with user commands
    create an inferencing model with user commands
    call the inference N times

make code to make the entire process