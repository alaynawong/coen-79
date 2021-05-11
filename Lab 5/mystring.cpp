/*
Names: Arren Leung and Alayna Wong
Date: April 29, 2021
Title: Lab 5, mystring.cpp
*/

#include <iostream>
#include <cassert>
#include <string.h>
#include <cstring>
#include "mystring.h"

using namespace std;

namespace coen79_lab5
{
    /* ---------- CONSTRUCTOR ---------- */
    // Precondition: str is an ordinary null-terminated string
    // The string contains the sequence of chars from str
    string::string(const char str[ ]) {
        current_length = strlen(str); // length becomes length of new string
        allocated = current_length + 1;
        characters = new char[allocated];
        strncpy(characters, str, allocated); // copy the string
        characters[current_length] = '\0';  // add null to end of string
    }

    // The string contains c and then the null character
    string::string(char c) {
        current_length = 1;
        allocated = 2;
        characters = new char[allocated];
        characters[0] = c;
        characters[1] = '\0';
    }

    // Copy constructor
    // The string becomes a copy of the source string
    string::string(const string& source) {
        current_length = source.current_length; // set length to source's length
        allocated = source.allocated; // set allocated to source's allocated
        characters = new char[allocated];
        strncpy(characters, source.characters, source.current_length); // copy the string
    }

    // Destructor
    // Destroys characters array on the heap
    string::~string() {
        current_length = 0;
        allocated = 0;
        delete[] characters;
    }

    /* ---------- MODIFICATION MEMBER FUNCTIONS ---------- */
    // Addend has been catenated to the end of the string
    void string::operator +=(const string& addend) {
        reserve(current_length + addend.current_length); 
        strncat(characters, addend.characters, allocated); // append addend to string
        current_length += addend.current_length; // update current_length
    }

    // Precondition: addend is an ordinary null-terminated string
    // Addend has been catenated to the end of the string
    void string::operator +=(const char addend[]) {
        reserve(current_length + strlen(addend));
        strncat(characters, addend, allocated); // append addend to string
        current_length += strlen(addend); // update current_length
    }

    // The single character addend has been catenated to the end of the string
    void string::operator +=(char addend) {
        reserve(current_length);
        characters[current_length] = addend; // append character to string
        current_length++; // update current_length by one
        characters[current_length] = '\0'; // add null to end of string
    }

    // All functions will now work efficiently (without allocating new memory)
    // until n characters are in the string
    void string::reserve(size_t n) {
        char* temp = new char[n + allocated]; // temp is assigned proper amount of memory
        strncpy(temp, characters, allocated); // add memory equal to size of the two string
        delete[] characters; // clear current characters in string
        characters = temp; // assign temp to characters
        allocated += n; // update allocated
    }

    // Assigns source to a string pointer
    string& string::operator =(const string& source)
    {
        this->dlt(0, current_length);

        if (current_length != source.current_length)
        {
            allocated = source.allocated;
            reserve(allocated);
        }

        strncpy(characters, source.characters, source.current_length);
        current_length = source.current_length;

        return *this;
    }

    // Precondition: position <= length()
    // The source string is inserted into this string before the character at the given index
    void string::insert(const string& source, unsigned int position) {
        assert(position <= length());
        string temp = source; // create temporary string from source
        for(size_t i = position; i < current_length; i++) {
            // append characters in string to temp starting at position
            // resulting string is source + other half of string
            temp += characters[i];
        }
        current_length += source.length(); // update current_length
        for(size_t j = 0; j < temp.length(); position++, j++) {
            // append temp to characters starting at position
            // resutling string is half of string + source + other half of string
            characters[position] = temp[j];
        }
    }

    // Precondition: (position + num) <= length()
    // Num characters are deleted from the sequence, starting at the index position
    void string::dlt(unsigned int position, unsigned int num) {
        assert((position + num) <= length());
        for(size_t i = position; i <= current_length - num; i++) {
            // shift all characters over to replace
            characters[i] = characters[i + num];
        }
        characters[current_length] = '\0'; // add null to end of string
        current_length -= num; // update current_length
    }

    // Precondition: position < length()
    // The character at the given position in the string is replaced with c
    void string::replace(char c, unsigned int position) {
        assert(position < length());
        characters[position] = c;
    }

    // Precondition: (position + source.length()) <= length()
    // The characters in this string starting at position are replaced
    void string::replace(const string& source, unsigned int position) {
        assert((position + source.length()) <= length());
        size_t i, j = 0;
        for(i = position; i < (position + source.length()); i++, j++) {
            // replace characters in string with source starting at position
            characters[i] = source[j];
        }
    }

    /* ---------- CONSTANT MEMBER FUNCTIONS ---------- */
    // Precondition: position < length()
    // The value returned is the character at the specified position of the string
    // A string's position start from 0 at the start of the sequence and go up to length()-1 at the right end
    char string::operator [](size_t position) const
    {
        assert(position < length());
        return characters[position];
    }

    // The location of the first occurence of the character c within this string is returned
    // If the string does not contain c, -1 is returned
    int string::search(char c) const
    {
        int i;

        for (i = 0; i < length(); i++)
        {
            if (characters[i] == c)
                return i;
        }

        return -1;
    }

    // Returns the index of the start of the first instance of the given substring inside of this string
    // If the substring is not found, this function returns -1
    int string::search(const string& substring) const
    {
        char *temp = strstr(characters, substring.characters);      // Returns a pointer to where substring starts
        int index = -1;

        if (temp != NULL)
            index = *temp - *characters;

        return index;       // Returns the index if substring is found; if it doesn't it will return -1
    }

    // The count of the occurence of the character c within this string is returned
    unsigned int string::count(char c) const
    {
        unsigned int count;
        int i;

        for (i = 0; i < length(); i++)
        {
            if (characters[i] == c)
                count++;
        }

        return count;
    }

    /* ---------- NON-MEMBER FUNCTIONS ---------- */
    // The string returned is the catenation of string s1 and s2
    string operator +(const string& s1, const string& s2)
    {
        string temp;

        temp.reserve(s1.length() + s2.length() + 1);
        temp += s1;
        temp += s2;

        return temp;
    }

    // The string returned is the catenation of string s1 and char array addend[]
    string operator +(const string& s1, const char addend[])
    {
       string temp;

        temp.reserve(s1.length() + strlen(addend) + 1);
        temp += s1;
        temp += addend;

        return temp; 
    }

    // A string has been read from the istream ins, and the istream ins is then returned by the function
    // The reading operation skips white space at the start of ins. Then the string is read up to the next white space or the end of the file
    // The white space character that terminates the string has not been read
    std::istream& operator >>(std::istream& ins, string& target)
    {
        char *hold = new char[500];

        while (ins && isspace(ins.peek()))
            ins.ignore();

        ins >> hold;
        target = string(hold);
        return ins;
    }

    /* ---------- FRIEND FUNCTIONS ---------- */
    // The sequence of characters in source has been written to outs. The return value is the ostream outs
    std::ostream& operator <<(std::ostream& outs, const string& source)
    {
        outs << source.characters;
        return outs;
    }

    // Comparison operators
    bool operator ==(const string& s1, const string& s2)
    {
        return (strcmp(s1.characters, s2.characters) == 0);
    }

    bool operator !=(const string& s1, const string& s2)
    {
        return (strcmp(s1.characters, s2.characters) != 0);
    }

    bool operator > (const string& s1, const string& s2)
    {
        return (strcmp(s1.characters, s2.characters) > 0);
    }

    bool operator < (const string& s1, const string& s2)
    {
        return (strcmp(s1.characters, s2.characters) < 0);
    }

    bool operator >=(const string& s1, const string& s2)
    {
        return ((s1 > s2) || (s1 == s2));
    }

    bool operator <=(const string& s1, const string& s2)
    {
        return ((s1 < s2) || (s1 == s2));
    }
}
