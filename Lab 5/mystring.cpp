#include <iostream>
#include <cassert>
#include <cstring>
#include "mystring.h"

using namespace std;

namespace coen79_lab5
{
    /* ---------- CONSTRUCTOR ---------- */
    string::string(const char str[] = "") {
        current_length = strlen(str); // length becomes length of new string
        allocated = current_length + 1;
        characters = new char[allocated];
        strncpy(characters, str, allocated); // copy the string
        characters[current_length] = '\0';  // add null to end of string
    }

    string::string(char c) {
        current_length = 1;
        allocated = 2;
        characters = new char[allocated];
        characters[0] = c;
        characters[1] = '\0';
    }

    string::string(const string& source) {
        current_length = source.current_length; // set length to source's length
        allocated = source.allocated; // set allocated to source's allocated
        characters = new char[allocated];
        strncpy(characters, source.characters, source.current_length); // copy the string
    }

    string::~string() {
        current_length = 0;
        allocated = 0;
        delete[] characters;
    }

    /* ---------- MODIFICATION MEMBER FUNCTIONS ---------- */
    void string::operator +=(const string& addend) {
        reserve(current_length + addend.current_length); 
        strncat(characters, addend.characters, allocated); // append addend to string
        current_length += addend.current_length; // update current_length
    }

    void string::operator +=(const char addend[]) {
        reserve(current_length + strlen(addend));
        strncat(characters, addend, allocated); // append addend to string
        current_length += strlen(addend); // update current_length
    }

    void string::operator +=(char addend) {
        reserve(current_length);
        characters[current_length] = addend; // append character to string
        current_length++; // update current_length by one
        characters[current_length] = '\0'; // add null to end of string
    }

    void string::reserve(size_t n) {
        char* temp = new char[n + allocated]; // temp is assigned proper amount of memory
        strncpy(temp, characters, allocated); // add memory equal to size of the two string
        delete[] characters; // clear current characters in string
        characters = temp; // assign temp to characters
        allocated += n; // update allocated
    }

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
            characters[position] += temp[j];
        }
    }

    void string::dlt(unsigned int position, unsigned int num) {
        assert((position + num) <= length());
        for(size_t i = position; i <= current_length - num; i++) {
            // shift all characters over to replace
            characters[i] = characters[i + num];
        }
        characters[current_length] = '\0'; // add null to end of string
        current_length -= num; // update current_length
    }

    void string::replace(char c, unsigned int position) {
        assert(position < length());
        characters[position] = c;
    }

    void string::replace(const string& source, unsigned int position) {
        assert((position + source.length()) <= length());
        size_t i, j = 0;
        for(i = position; i < (position + source.length()); i++, j++) {
            // replace characters in string with source starting at position
            characters[i] = source[j];
        }
    }

    /* ---------- CONSTANT MEMBER FUNCTIONS ---------- */
    size_t string::length() const {

    }

    char string::operator [](size_t position) const {
        assert(position < length());

    }

    int string::search(char c) const {

    }

    int string::search(const string& substring) const {

    }

    unsigned int string::cout(char c) const {

    }

    /* ---------- FRIEND FUNCTIONS ---------- */
    ostream& operator <<(ostream& outs, const string& source) {

    }
    
    bool operator ==(const string& s1, const string& s2) {

    }

    bool operator !=(const string& s1, const string& s2) {
        
    }

    bool operator >(const string& s1, const string& s2) {
        
    }

    bool operator <(const string& s1, const string& s2) {
        
    }

    bool operator >=(const string& s1, const string& s2) {
        
    }

    bool operator <=(const string& s1, const string& s2) {
        
    }

    /* ---------- NON-MEMBER FUNCTIONS ---------- */
    string operator +(const string& s1, const string& s2) {

    }

    string operator +(const string& s1, const char addend[]) {

    }

    ostream& operator >>(ostream& outs, const string& source) {

    }
}
