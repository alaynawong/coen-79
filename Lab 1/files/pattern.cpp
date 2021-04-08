/*
 Arren Leung
 COEN 79L - Lab 1: Output pattern
 4/1/2021
 */

#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    string numbers;
    int flag = 1; // flag for while loop
    int digflag = 0; // flag to detect non-numeric chars

    cout << "Input 10 numbers with no spaces:\n";

    while (flag) {
        getline(cin, numbers);
        
        // traverses each character in the string and flags for
        // any character that isn't a number
        for (int i = 0; i < numbers.length(); i++) {
            if (!(isdigit(numbers[i]))) {
                digflag++;
            }
        }

        // if length != 10 or there is a non-numeric number in
        // the input, ask user to try again. If not, proceed.
        if ((numbers.length() != 10) || (digflag > 0)) {
            cout << "Input invalid. Try again.\n";
            continue;
        }
        else {
            flag = 0;
        }
    }

    // stores the input into new string rev and reverses it
    string rev = numbers;
    reverse(rev.begin(), rev.end());

    // prints numbers and rev with setw value 11 through 16 
    for (int i = 11; i < 17; i++) {
        cout << setw(i) << numbers;
        cout << setw(20) << rev << endl;
    }

    return 0;
}
