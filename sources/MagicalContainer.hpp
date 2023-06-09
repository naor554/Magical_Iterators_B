#ifndef MAGICAL_CONTAINER_HPP
#define MAGICAL_CONTAINER_HPP

#include <vector>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include "BaseIterator.hpp"

// This class is a container that holds integers and allows iterating over them in different ways:
// 1. Ascending order
// 2. Side cross order
// 3. Prime numbers order
//
// each iterator is a different class that inherits from BaseIterator


namespace ariel {

    class MagicalContainer {

    public:

        void addElement(int element);
        void removeElement(int element);
        int size() const;

        class AscendingIterator : public BaseIterator {
        public:
            AscendingIterator(const MagicalContainer &container);
        };

        class SideCrossIterator : public BaseIterator {
        public:
            SideCrossIterator(const MagicalContainer &container);
        };

        class PrimeIterator : public BaseIterator {
        public:
            PrimeIterator(const MagicalContainer &container);
        };
        
    private:
        std::vector<int> elements;
    };

    // Global helper function
    bool isPrime(int num);
}

#endif //MAGICAL_CONTAINER_HPP
