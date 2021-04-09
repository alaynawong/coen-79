#include "random.h"
#include <iostream>

using namespace std;

namespace coen79_lab2 {

    // ctor to initialize obj with inputted values
    rand_gen::rand_gen(int in_seed, int in_multiplier, int in_increment, int in_modulus) {
        seed = in_seed;
        multiplier = in_multiplier;
        increment = in_increment;
        modulus = in_modulus;
    }

    // sets seed to inputted number
    void rand_gen::set_seed(int newSeed) {
        seed = newSeed;
    }

    // set seed with linear congruence method and return as next_num
    int rand_gen::next() {
        int next_num = (multiplier * seed + increment) % modulus;
        set_seed(next_num);
        return next_num;
    }

    void rand_gen::print_info() {
        cout << "Seed: " << seed << endl;
        cout << "Multiplier: " << multiplier << endl;
        cout << "Increment: " << increment << endl;
        cout << "Modulus: " << modulus << endl;
    }

}