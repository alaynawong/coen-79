/*
Names: Arren Leung and Alayna Wong
Date: April 29, 2021
Title: Lab 5, mystring.cpp
*/

#include <stdio.h>
#include <iostream>
#include <cassert>
#include <string.h>
#include <cctype>
#include "mystring.h"

using namespace std;

namespace coen79_lab5
{
    // Constructor
    // Precondition: str is an ordinary null-terminated string
    // The string contains the sequence of chars from str
    string::string(const char str[])
    {

    }

    // The string contains c and then the null character
    string::string(char c)
    {

    }

    // Copy constructor
    // The string becomes a copy of the source string
    string::string(const string& source)
    {

    }
    
    // Destructor
    // Destroys characters array on the heap
    string::~string()
    {

    }

    // Addend has been catenated to the end of the string
    void operator +=(const string& addend)
    {

    }

    // Precondition: addend is an ordinary null-terminated string
    // Addend has been catenated to the end of the string
    void operator +=(const char addend[])
    {

    }

    // The single character addend has been catenated to the end of the string
    void operator +=(char addend)
    {

    }

    // All functions will now work efficiently (without allocating new memory) until n characters are in the string
    void reserve(size_t n)
    {

    }

    // Assigns source to a string pointer ???
    string& operator =(const string& source)
    {

    }

    // Precondition: position <= length()
    // The source string is inserted into this string before the character at the given index
    void insert(const string& source, unsigned int position)
    {

    }
    
    // Precondition: (position + num) <= length()
    // Num charaacters are deleted from the sequence, starting at the index position
    void dlt(unsigned int position, unsigned int num)
    {

    }

    // Precondition: position < length()
    // The character at the given position in the string is replaced with c
    void replace(char c, unsigned int position)
    {

    }

    // Precondition: (position + source.length()) <= length()
    // The characters in this string starting at position are replaced with those in the source string
    void replace(const string& source, unsigned int position)
    {

    }


    // The return value is the number of characters in the string
    size_t length() const
    {
        return current_length;
    }

    // Precondition: position < length()
    // The vaalue returned is the character at the specified position of the string
    // A string's position start from 0 at the start of the sequence and go up to length()-1 at the right end
    char operator [](size_t position) const
    {

    }

    // The location of the first occurence of the character c within this string is returned
    // If the string does not contain c, -1 is returned
    int search(char c) const
    {

    }

    // Returns the index of the start of the first instance of the given substring inside of this string
    // If the substring is not found, this function returns -1
    int search(const string& substring) const
    {

    }

    // The count of the occurence of the character c within this string is returned
    unsigned int count(char c) const
    {

    }


    // 
    friend std::ostream& operator <<(std::ostream& outs, const string& source);
    friend bool operator ==(const string& s1, const string& s2);
    friend bool operator !=(const string& s1, const string& s2);
    friend bool operator > (const string& s1, const string& s2);
    friend bool operator < (const string& s1, const string& s2);
    friend bool operator >=(const string& s1, const string& s2);
    friend bool operator <=(const string& s1, const string& s2);

    // The string returned is the catenation of string s1 and s2
    string operator +(const string& s1, const string& s2)
    {

    }

    // The string returned is the catenation of string s1 and char array addend[]
    string operator +(const string& s1, const char addend[]);
    std::istream& operator >> (std::istream& ins, string& target);
}