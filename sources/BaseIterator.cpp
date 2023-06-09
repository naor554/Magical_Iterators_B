#include "BaseIterator.hpp"
#include <iostream>

namespace ariel {

    // constructor
    BaseIterator::BaseIterator(const MagicalContainer &container, const std::string &type)
        : container(container), type(type), position(0) {}

    // copy constructor
    BaseIterator::BaseIterator(const BaseIterator &other)
        : container(other.container), type(other.type) {}

    // assignment operator
    BaseIterator& BaseIterator::operator=(const BaseIterator &other) {
        if (this != &other) {
            // Ensure that both iterators are for the same container
            if (&container != &other.container) {
                throw std::runtime_error("Iterators are not for the same container");
            }
            position = other.position;
            elements = other.elements;  // copy all the elements from 'other' to 'this'
        }
        return *this;
    }


    // compare two iterators
    bool BaseIterator::operator==(const BaseIterator &other) const {
        return &container == &other.container && position == other.position && type == other.type;
    }

    // increment iterator
    BaseIterator& BaseIterator::operator++() {
        if (position >= elements.size()) {
            throw std::runtime_error("Iterator position is out of range");
        }
        position++;
        return *this;
    }

    // compare two iterators
    bool BaseIterator::operator!=(const BaseIterator &other) const {
        return !(*this == other);
    }

    // compare two iterators by their position
    bool BaseIterator::operator<(const BaseIterator &other) const {
        if(&container != &other.container || type != other.type) {
            throw std::runtime_error("Comparison not valid!");
        }
        return position < other.position;
    }

    // compare two iterators by their position
    bool BaseIterator::operator>(const BaseIterator &other) const {
        if(&container != &other.container || type != other.type) {
            throw std::runtime_error("Comparison not valid!");
        }
        return position > other.position;
    }

    // dereference iterator
    int BaseIterator::operator*() const {
        if (position >= elements.size()) {
            throw std::out_of_range("Iterator position is out of range");
        }
        return *elements[position];
    }

    // return iterator to the first element
    BaseIterator BaseIterator::begin() {
        BaseIterator it(container, type);
        it.elements = elements;
        it.position = 0;
        return it;
    }

    // return iterator to the last element
    BaseIterator BaseIterator::end() {
        BaseIterator it(container, type);
        it.elements = elements;
        it.position = elements.size();
        return it;
    }
}
