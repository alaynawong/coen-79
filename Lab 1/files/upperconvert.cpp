/*
 Arren Leung
 COEN 79L - Lab 1: Convert and display 10 char words
 4/1/2021
 */

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char const* argv[])
{
    // checks if user has inputted a file name
    if (argc != 2) {
        cout << "Please input a file.\n";
        return 1;
    }

    string word, temp, filename;
    fstream fp;

    // store name of file in filename and open into file stream fp
    filename = argv[1];
    fp.open(filename.c_str());

    while(fp >> temp)
    {
        // store each word from fp into temp and reset word string
        word = "";
        
        // if a character in the word is alphanumeric, change to 
        // uppercase and put it into word string
        for (int i = 0; i < temp.length(); i++) {
            if (isalnum(temp[i])) {
                word += toupper(temp[i]);
            }
        }

        // if the length of word is 10 or greater, print word
        if (word.length() >= 10) {
            cout << word << endl;
        }
    }

    return 0;
}