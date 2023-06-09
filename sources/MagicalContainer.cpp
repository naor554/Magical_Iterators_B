#include "MagicalContainer.hpp"

namespace ariel {

    // add element to the container
    void MagicalContainer::addElement(int element) {
        elements.push_back(element);
    }

    // remove element from the container
    void MagicalContainer::removeElement(int element) {
        auto position = std::find(elements.begin(), elements.end(), element);
        if (position != elements.end()) {
            elements.erase(position);
        }
        else {
            throw std::runtime_error("Element not found!");
        }
    }

    // return the size of the container
    int MagicalContainer::size() const {
        return elements.size();
    }

    // constructor for the AscendingIterator
    MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer &container)
        : BaseIterator(container, "ascending") {
        if (container.size() == 0) {
            return;
        }
        for (auto &element : container.elements) {
            elements.push_back(&element);
        }
        std::sort(elements.begin(), elements.end(), [](const int *a, const int *b) { return *a < *b; });
    }

    // constructor for the SideCrossIterator
    MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer &container)
        : BaseIterator(container, "cross") {
        if (container.size() == 0) {
            return;
        }

        for (int i = 0, j = container.size() - 1; i <= j; ++i, --j) {
            elements.push_back(&container.elements[(size_t)i]);
            if (i != j) {
                elements.push_back(&container.elements[(size_t)j]);
            }
        }
    }

    // constructor for the PrimeIterator
    MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer &container)
        : BaseIterator(container, "prime") {
        if (container.size() == 0) {
            return;
        }
        for (auto &element : container.elements) {
            if (isPrime(element)) {
                elements.push_back(&element);
            }
        }
    }

    // check if a number is prime
    bool isPrime(int num) {
        if (num <= 1) return false;
        if (num <= 3) return true;
        if (num % 2 == 0 || num % 3 == 0) return false;
        for (int i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0) return false;
        }
        return true;
    }
}
