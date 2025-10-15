// for example ababac as input code

// create a k-length slider

// process entire text, and sliding the context window, that is k-long

// for each k-gram store in a map to create a probability distribution of
// the k-grams for how often the k-gram appears compared to the corpus of kgrams
// so create a count then create a probaiblity

// for each k-gram also store the character that appears right after the k-gram
// to store the count and probability

// output this map:

k - grams
{
    {kgram - name : #Int}, {kgram - frequency : #Float}, next - char
}