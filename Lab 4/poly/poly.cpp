#include <iostream>
#include <cassert>
#include <cmath>
#include <climits>
#include "poly.h"

namespace coen79_lab4
{
    /* ----------- HELPER MEMBER FUNCTIONS ----------- */
    void polynomial::update_current_degree() {
        for(int i = MAXIMUM_DEGREE; i >= 0; i--) {
            // iterates through entire poly array
            // looks for largest exponent with non-zero coefficient
            if(poly[i] != 0.0) {
                current_degree = i; // update current_degree and break
                break;
            }
        }
    }

    /* ----------- CONSTRUCTOR ----------- */
    polynomial::polynomial(double c, unsigned int exponent) {
        assert(exponent <= MAXIMUM_DEGREE);
        clear();
        poly[exponent] = c;
        current_degree = exponent;
    }

    /* ----------- MODIFICATION MEMBER FUNCTIONS ----------- */
    void polynomial::assign_coef(double coefficient, unsigned int exponent) {
        assert(exponent <= MAXIMUM_DEGREE);
        poly[exponent] = coefficient;
        update_current_degree();
    }

    void polynomial::add_to_coef(double amount, unsigned int exponent) {
        assert(exponent <= MAXIMUM_DEGREE);
        poly[exponent] += amount;
        update_current_degree();
    }

    void polynomial::clear() {
        for(int i = 0; i <= MAXIMUM_DEGREE; i++) {
            // iterates through poly array, setting all values to 0.0
            poly[i] = 0.0;
        }
        current_degree = 0; // reset current_degree to 0
    }

    /* ----------- CONSTANT MEMBER FUNCTIONS ----------- */
    polynomial polynomial::antiderivative() const {
        assert(degree() < MAXIMUM_DEGREE);
        polynomial temp; // create a temporary polynomial object
        for(int i = current_degree; i >= 0; i--) {
            // iterate through values of poly array
            // if coefficient is non-zero, set +1 index in temp to antiderivative
            if (poly[i] != 0.0) temp.poly[i+1] = poly[i]/(i+1);
        }
        temp.update_current_degree();
        return temp;
    }

    double polynomial::coefficient(unsigned int exponent) const {
        // return 0.0 if exponent outside of max degree range
        // otherwise, return coefficient of exponent
        if(exponent > MAXIMUM_DEGREE) return 0.0;
        return poly[exponent];
    }

    double polynomial::definite_integral(double x0, double x1) const {
        polynomial integral; // create temporary polynomial object called integral
        double x_0, x_1;
        integral = antiderivative(); // set integral to antiderivative of polynomial
        x_0 = eval(x0); // evaluate integral for x0
        x_1 = eval(x1); // evaluate integral for x1
        return x_1 - x_0; // return the difference
    }

    unsigned int polynomial::degree() const {
        return current_degree;
    }

    polynomial polynomial::derivative() const {
        assert(current_degree <= MAXIMUM_DEGREE);
        polynomial temp; // create temporary polynomial object
        for(int i = current_degree; i > 0; i--) {
            // iterate through poly array starting at current degree
            // set -1 index in temp to derivative of coefficient in poly
            temp.poly[i-1] = i * poly[i];
        }
        temp.update_current_degree();
        return temp;
    }

    double polynomial::eval(double x) const {
        double value = 0.0;
        for(int i = 0; i <= current_degree; i++) {
            // calculate x^i * coefficient for each value in poly array
            value += poly[i] * power(x, i);
        }
        return value;
    }

    bool polynomial::is_zero() const {
        // if the current degree and first coefficient are 0, then polynomial is zero
        if(current_degree == 0 && poly[0] == 0.0) return true;
        return false;
    }

    unsigned int polynomial::next_term(unsigned int e) const {
        for(int i = e; i <= current_degree; i++) {
            // start index in poly array at e and iterate upwards
            // look for first non-zero coefficient and return index/exponent
            if(poly[i] != 0.0) return (unsigned int)i;
        }
        return 0; // if we can't find an exponent greater than e, return 0
    }

    unsigned int polynomial::previous_term(unsigned int e) const {
        for(int i = e; i >= 0; i--) {
            // start index in poly array at e and iterate downwards
            // look for first non-zero coefficient and return index/exponent
            if(poly[i] != 0.0) return (unsigned int)i;
        }
        return UINT_MAX; // if we can't find an exponent smaller than e, return 
    }

    /* ----------- CONSTANT OPERATORS ----------- */
    double polynomial::operator()(double x) const {
        double value;
        // evaluates polynomial at x using eval() member function
        value = eval(x);
        return value;
    }

    /* ----------- NON-MEMBER BINARY OPERATORS ----------- */
    polynomial operator +(const polynomial& p1, const polynomial& p2) {
        polynomial temp; // create temporary polynomial object
        for(int i = 0; i < polynomial::MAXIMUM_DEGREE; i++) {
            // for each exponent in p1 and p2, add their coefficients together
            // put this value into temp and return
            temp.add_to_coef(p1.coefficient(i) + p2.coefficient(i), i);
        }
        temp.update_current_degree();
        return temp;
    }

    polynomial operator -(const polynomial& p1, const polynomial& p2) {
        polynomial temp; // create temporary polynomial object
        for(int i = 0; i < polynomial::MAXIMUM_DEGREE; i++) {
            // for each exponent in p1 and p2, subtract their coefficients
            // put this value into temp and return
            temp.add_to_coef(p1.coefficient(i) - p2.coefficient(i), i);
        }
        temp.update_current_degree();
        return temp;
    }

    polynomial operator *(const polynomial& p1, const polynomial& p2) {
        // make sure that sum of p1 and p2 degrees <= max degree
        assert((p1.degree() + p2.degree()) <= polynomial::MAXIMUM_DEGREE);
        polynomial temp; // create temporary polynomial object
        double temp_coeff, temp_exp; // temp coefficient and exp vars
        for(int i = 0; i <= p1.degree(); i++) {
            // multiply each coefficient in p2 by p1 and add exponent values together
            for(int j = 0; j <= p2.degree(); j++) {
                temp_coeff = p1.coefficient(i) * p2.coefficient(j);
                temp_exp = i + j;
                // store coefficient and exponent in temp object
                temp.add_to_coef(temp_coeff, temp_exp);
            }
        }
        temp.update_current_degree();
        return temp;
    }

    double power(double x, int n) {
        // need this function in order to do power calculations on doubles
        double pow = 1.0;
        // do pow *= x n times to get pow(x, n)
        for(int i = 0; i < n; i++) pow *= x;
        return pow;
    }

    /* ----------- NON-MEMBER OUTPUT FUNCTIONS ----------- */
    std::ostream& operator <<(std::ostream& out, const polynomial& p) {
        double i = p.degree();
        double coeff;

        // for first coefficient in polynomial
        if(p.coefficient(i) != 0.0) {
            // if coefficient in non-zero, print it
            out << p.coefficient(i);
            // if exponent is 1, only print x
            if (i == 1) out << "x";
            // if exponent > 1, print x^exponent
            else if (i > 1) out << "x^" << i; 
        } else if(i == 0)
            // if first coefficient is non-zero, return
            return out; 
        i--; // decrement degree by one for printing next values in polynomial

        for(i; i >= 0; i--) {
            // for remaining values in polynomial
            coeff = p.coefficient(i);
            // if the coefficient is non-zero, print it
            if(coeff != 0.0) {
                // if the coefficient is positive, print + before it
                if (coeff > 0.0) out << " + " << coeff;
                // if the coefficient is negative, print - before it
                else if (coeff < 0.0) out << " - " << std::abs(coeff);
                // if the exponent is one, print x instead of x^1
                if (i == 1) out << "x";
                // otherwise, print x^exponent
                else if (i > 1) out << "x^" << i;
            }
        }
        return out;
    }
}