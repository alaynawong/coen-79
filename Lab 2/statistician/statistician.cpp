// FILE: statistician.cpp
// CLASS IMPLEMENTED: statistician (see stats.h for documentation)

#include <cassert>   // Provides assert
#include <iostream>  // Provides istream class
#include "statistician.h"

using namespace std;

namespace coen79_lab2
{
    // initializing statistician object when ctor is called
    statistician::statistician(int in_len, double in_total, double in_min, double in_max) {
        len = in_len;
        total = in_total;
        min = in_min;
        max = in_max;
    }

    void statistician::next(double r) {
        // checks if inputted value is greater than max or min and updates
        if (r > max) {
            max = r;
        }
        if (r < min) {
            min = r;
        }
        total += r; // adding value to total
        len++;  // increasing length by one
    }

    // initializing object with default ctor values
    void statistician::reset() {
        len = 0;
        total = 0;
        min = 9999;
        max = -9999;
    }

    int statistician::length() const {
        return len;
    }

    double statistician::sum() const {
        return total;
    }

    double statistician::mean() const {
        assert(len > 0);
        return total/len;
    }

    double statistician::minimum() const {
        return min;
    }

    double statistician::maximum() const {
        return max;
    }

    statistician operator +(const statistician& s1, const statistician& s2) {
        int len_new;
        double total_new, min_new, max_new;

        len_new = s1.length() + s2.length(); // adding both obj lengths together
        total_new = s1.sum() + s2.sum(); // adding both obj sums together

        // compares which min/max is smaller/greater
        min_new = (s1.minimum() < s2.minimum()) ? s1.minimum() : s2.minimum();
        max_new = (s1.maximum() > s2.maximum()) ? s1.maximum() : s2.maximum();

        statistician s_new(len_new, total_new, min_new, max_new);
        return s_new;
    }

    statistician operator *(double scale, const statistician& s) {
        int len_new;
        double total_new, min_new, max_new;

        len_new = s.length(); // length stays the same

        // multiplying all values by inputted scale
        total_new = s.sum() * scale;

        // flips new max and min when scale is negative
        if (scale < 0) {
            max_new = s.minimum() * scale;
            min_new = s.maximum() * scale;
        } else {
            max_new = s.minimum() * scale;
            min_new = s.maximum() * scale;
        }

        statistician s_new(len_new, total_new, min_new, max_new);
        return s_new;
    }

    bool operator ==(const statistician& s1, const statistician& s2) {
        if (s1.length() == 0 && s2.length() == 0) {
            return true;
        }

        // checks if all values in both objects are equal
        if (s1.length() == s2.length() &&
            s1.mean() == s2.mean() &&
            s1.minimum() == s2.minimum() &&
            s1.maximum() == s2.maximum() &&
            s1.sum() == s2.sum()) {
            return true;
        }
        return false;
    }
}


