#include <iostream>
#include <cassert>
#include <cstring>
#include "mystring.h"

using namespace std;

namespace coen79_lab5
{
    /* ---------- CONSTRUCTOR ---------- */
    string::string(const char str[] = "") {
        current_length = strlen(str);
        allocated = current_length + 1;
        characters = new char[allocated];
        strncpy(characters, str, allocated);
    }

    string::string(char c) {
        current_length = 1;
        allocated = 2;
        characters = new char[allocated];
        characters[0] = c;
        characters[1] = '/0';
    }

    string::string(const string& source) {
        current_length = source.current_length;
        allocated = source.allocated;
        characters = new char[allocated];
        strncpy(characters, source.characters, allocated);
    }

    string::~string() {
        delete[] characters;
        current_length = 0;
        allocated = 0;
    }

    /* ---------- MODIFICATION MEMBER FUNCTIONS ---------- */
    void string::operator +=(const string& addend) {
    
    }

    void string::operator +=(const char addend[]) {

    }

    void string::operator +=(char addend) {

    }

    string& string::operator = (const string& source) {

    }

    void string::reserve(size_t n) {

    }

    void string::insert(const string& source, unsigned int position) {
        assert(position <= length());

    }

    void string::dlt(unsigned int position, unsigned int num) {
        assert((position + num) <= length());

    }

    void string::replace(char c, unsigned int position) {
        assert(position < length());
        
    }

    void string::replace(const string& source, unsigned int position) {
        assert((position + source.length()) <= length());

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

    /* ---------- NON-MEMBER FUNCTIONS ---------- */
    string operator +(const string& s1, const string& s2) {

    }

    istream& operator >>(istream& ins, string& target) {

    }

    ostream& operator <<(ostream& outs, const string& source) {

    }

    /* ---------- COMPARISON OPERATORS ---------- */
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
}