#ifndef BASE_ITERATOR_HPP
#define BASE_ITERATOR_HPP

#include <vector>
#include <string>
#include <stdexcept>

// This class is a base class for all iterators of MagicalContainer class 
// It holds a reference to the MagicalContainer and a vector of pointers to the elements of the container
// It also holds the type of the iterator (ascending, cross or prime)

namespace ariel {

    // Forward declare MagicalContainer class so it can be used in the iterator
    class MagicalContainer;

    class BaseIterator {
    public:
        
        explicit BaseIterator(const MagicalContainer &container, const std::string &type);
        BaseIterator(const BaseIterator &other);
        virtual ~BaseIterator() = default;

        BaseIterator& operator=(const BaseIterator &other);
        BaseIterator& operator++();
        bool operator==(const BaseIterator &other) const;
        bool operator!=(const BaseIterator &other) const;
        bool operator>(const BaseIterator &other) const;
        bool operator<(const BaseIterator &other) const;
        int operator*() const;
        BaseIterator begin();
        BaseIterator end();

    protected:
        std::vector<const int*> elements;
        const MagicalContainer &container;
        size_t position;
        std::string type;
    };
}

#endif //BASE_ITERATOR_HPP
