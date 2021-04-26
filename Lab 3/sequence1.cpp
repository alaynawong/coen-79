// Arren Leung
// COEN 79L: Lab 3
// 4/18/2021

#include <cassert>
#include <iostream>
#include <cmath>
#include "sequence1.h"

using namespace std;

namespace coen79_lab3
{
    /* ---------- CONSTRUCTOR ---------- */
    sequence::sequence() {
        this->len = 0;
        this->cur = 0;
    }

    /* ---------- MODIFICATION MEMBER FUNCTIONS ---------- */
    void sequence::start() {
        cur = 0;
    }

    void sequence::end() {
        cur  = len - 1;
    }

    void sequence::last() {
        cur = CAPACITY - 1;
    }

    void sequence::advance() {
        assert(is_item());
        if(cur < len) {
            cur++;
        } else {
            cout << "You are at the end of the sequence." << endl;
        }
    }

    void sequence::retreat() {
        if(cur > 0) {
            cur--;
        } else {
            cout << "You are at the beginning of the sequence." << endl;
        }
    }

    void sequence::insert(const value_type& entry) {
        assert(size() < CAPACITY);
        if(!is_item()) {
            // if no current item, entry inserted at front
            data[0] = entry;
            cur = 0;
        } else {
            // move all items up by one, starting at cur
            for(int i = len; i >= cur + 1; i--) {
                data[i] = data[i - 1];
            }
            // set current to entry
            data[cur] = entry;
        }
        len++; // increase len by one
    }

    void sequence::attach(const value_type& entry) {
        assert(size() < CAPACITY);
        if(!is_item()) {
            // if no current item, entry attached to the end
            data[len] = entry;
            cur = len;
        } else {
            // move all items up by one, starting at elt in front of cur
            for(int i = len; i > cur + 1; i--) {
                data[i] = data[i - 1];
            }
            // set the elt after current to entry and increase cur
            data[cur + 1] = entry;
            cur++;
        }
        len++; // increase len by one
    }

    void sequence::remove_current() {
        assert(is_item());
        // shifts all items down starting from current
        for(int i = cur + 1; i < len; i++) {
            data[i - 1] = data[i];
        }
        len--; // decrease the len by one
    }

    void sequence::insert_front(const value_type& entry) {
        assert(size() < CAPACITY);
        cur = 0; // set current to first position in sequence
        insert(entry); // insert entry into sequence
    }

    void sequence::attach_back(const value_type& entry) {
        assert(size() < CAPACITY);
        data[len] = entry; // insert entry at the end of the sequence
        len++; // increase the len by one
    }

    void sequence::remove_front() {
        assert(is_item());
        cur = 0; // set current to first position in sequence
        remove_current(); // remove current item
    }

    void sequence::operator +=(const sequence& rhs) {
        assert((len + rhs.len) < CAPACITY);
        size_type temp = rhs.len;
        for(int i = 0; i < temp; i++) {
            data[len++] = rhs.data[i];
        }
    }

    /* ---------- CONSTANT MEMBER FUNCTIONS ---------- */
    sequence::size_type sequence::size() const {
        return len;
    }

    bool sequence::is_item() const {
        // there is a current item if its position is less than len
        if(cur < len) {
            return true;
        }
        return false;
    }

    sequence::value_type sequence::current() const {
        assert(is_item());
        return data[cur];
    }

    sequence::value_type sequence::operator[](int index) const {
        assert(index < len);
        return data[index];
    }

    double sequence::mean() const {
        sequence::value_type sum = 0.0;
        // add all items in sequence together
        for(int i = 0; i < len; i++) {
            sum += data[i];
        }
        return sum / len; // return the mean by dividing sum by len
    }

    double sequence::standardDeviation() const {
        sequence::value_type var = 0.0;
        sequence::value_type mean = sequence::mean();
        // variance = average of squared differences from mean
        // stdev = sqrt of variance
        for(int i = 0; i < len; i++) {
            var += pow(data[i] - mean, 2);
        }
        var /= len;
        return sqrt(var);
    }

    /* ---------- NON-MEMBER FUNCTIONS ---------- */
    sequence operator +(const sequence& lhs, const sequence& rhs) {
        // make sure that contents of both sequences fit in capacity
        assert((lhs.size() + rhs.size()) <= sequence::CAPACITY);
        sequence(temp); // create temporary sequence
        // add lhs and rhs to temp
        temp += lhs;
        temp += rhs;
        return temp;
    }

    sequence::value_type summation(const sequence &s) {
        // creates a temporary sequence object copied from input
        sequence temp = s;
        sequence::value_type sum = 0.0;
        temp.start();
        // for each value in temp, add to the sum and advance to next pos
        for(int i = 0; i < temp.size(); i++) {
            sum += temp.current();
            temp.advance();
        }
        return sum;
    }
}