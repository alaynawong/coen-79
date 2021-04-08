/*
 Arren Leung
 COEN 79L - Lab 1: Counting character types
 4/1/2021
 */

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int alpha = 0;
    int non_alpha = 0;

    // asks user to input a sentence and stores in string sentence
    cout << "Input a sentence:\n";
    string sentence;
    getline(cin, sentence);

    for(int i = 0; i < sentence.length(); i++) {
        // for each character in the sentence that is not a space,
        // add to alpha or add to non_alpha
        if (sentence[i] != ' ') {
            if (isalpha(sentence[i])) {
                alpha++;
            }
            else {
                non_alpha++;
            }
        }
    }

    cout << "\"" << sentence << "\" has " << alpha << " alphanumeric characters and " << non_alpha << " non-alphanumeric characters.\n";

    return 0;
}
