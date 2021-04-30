#include <iostream>
#include <cassert>
#include "mystring.h"

using namespace std;

namespace coen79_lab5
{
    /* ---------- CONSTRUCTOR ---------- */
    string::string(const char str[] = "") {

    }

    string::string(char c) {
        
    }

    string::string(const string& source) {

    }

    /* ---------- MODIFICATION MEMBER FUNCTIONS ---------- */
    void string::operator +=(const string& addend) {

    }

    void string::operator +=(const char addend[]) {

    }

    void string::operator +=(char addend) {

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
}