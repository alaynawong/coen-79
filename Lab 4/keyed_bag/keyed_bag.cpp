#include <iostream>
#include <cassert>
#include "keyed_bag.h"

namespace coen79_lab4 {

    /* ---------- Constructor for the keyed_bag class ---------- */
    keyed_bag::keyed_bag() {
        total = 0;
        for(int i = 0; i < CAPACITY; i++) {
            data[i] = 0;
            keys[i] = '\0';
        }
    }

    /* ---------- Modification Member Functions for the keyed_bag class ---------- */
    void keyed_bag::erase() {
        total = 0;
        for(int i = 0; i < CAPACITY; i++) {
            data[i] = 0;
            keys[i] = '\0';
        }
    }

    bool keyed_bag::erase(const key_type& key) {
        // iterate through the contents of the bag until a matching key is found
        for(int i = 0; i < size(); i++) {
            if(keys[i] == key) {
                for(int j = i; j < size(); j++) {
                    // starting at where key was found, shift all items in bag down one
                    keys[j] = keys[j+1];
                    data[j] = data[j+1];
                }
                --total; // decrement the total
                return true;
            }
        }
        return false;
    }

    void keyed_bag::insert(const value_type& entry, const key_type& key) {
        // assert that the size < capacity and that the bag does not have a matching key
        assert((size() < CAPACITY) && !(has_key(key)));
        // inserts new entry and key into next empty spot in bag
        data[total] = entry;
        keys[total] = key;
        ++total; // increment the total
    }

    void keyed_bag::operator +=(const keyed_bag& addend) {
        // assert that the size of both bags <= capacity and that the bag & addend to not have duplicate keys
        assert(((size() + addend.size()) <= CAPACITY) && !(hasDuplicateKey(addend)));
        for(int i = 0; i < addend.size(); i++) {
            // adds all of addend's data and keys to the end of the bag
            data[total] = addend.data[i];
            keys[total] = addend.keys[i];
            ++total; // increment the total after every addition
        }
    }

    /* ---------- Constant Member Functions for the keyed_bag class ---------- */
    bool keyed_bag::has_key(const key_type& key) const {
        for(int i = 0; i < size(); i++) {
            // if the key is found in the bag, return true
            if(keys[i] == key) return true;
        }
        return false;
    }

    keyed_bag::value_type keyed_bag::get(const key_type& key) const {
        assert(has_key(key));
        for(int i = 0; i < size(); i++) {
            // if the key is found in the bag, return its corresponding data
            if(keys[i] == key) return data[i];
        }
    }

    keyed_bag::size_type keyed_bag::size() const {
        return total;
    }

    keyed_bag::size_type keyed_bag::count(const value_type& target) const {
        size_type occurences = 0;
        for(int i = 0; i < size(); i++) {
            // go through contents of the bag and count occurences of target
            if(data[i] == target) ++occurences;
        }
        return occurences;
    }

    bool keyed_bag::hasDuplicateKey(const keyed_bag& otherBag) const {
        for(int i = 0; i < size(); i++) {
            for(int j = 0; j < otherBag.size(); j++) {
                // cross-checks each key in the bag and otherBag
                // returns true if two keys match
                if(keys[i] == otherBag.keys[j]) return true;
            }
        }
        return false;
    }

    /* ---------- Nonmember Functions for the keyed_bag class ---------- */
    keyed_bag operator+(const keyed_bag& b1, const keyed_bag& b2) {
        // assert that the size of boths bags <= capacity
        // assert that both bags don't have duplicate keys
        assert(((b1.size() + b2.size()) <= keyed_bag::CAPACITY) && !(b1.hasDuplicateKey(b2)));
        keyed_bag(temp); // create a temporary bag object
        // add contents of b1 and b2 to temp bag
        temp += b1;
        temp += b2;
        return temp;
    }

}