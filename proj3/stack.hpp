#ifndef STACK_HPP
#define STACK_HPP

#include "stack.h"
#include <deque>

using namespace cop4530;

// Default constructor     
template<typename T, class Container>
Stack<T, Container>::Stack() : container() {}

// Copy constructor
template <typename T, class Container>
Stack<T, Container>::Stack(const Stack& rhs) {
    container = Container(rhs.container);
}

// Move constructor
template <typename T, class Container>
Stack<T, Container>::Stack(Stack && rhs) {
    container = std::move(rhs.container);
}

// Copy assignment operator=
template <typename T, class Container>
Stack<T, Container>& Stack<T, Container>::operator=(const Stack& rhs) {
    if(this != &rhs) {
        container = Container(rhs.container);
    }
    return *this;
}

// Move assignment operator=
template <typename T, class Container>
Stack<T, Container>& Stack<T, Container>::operator=(Stack&& rhs) {
    if(this != &rhs) {
        container = std::move(rhs.container);
    }
    return *this;
}

// Destructor
template <typename T, class Container>
Stack<T, Container>::~Stack() {
    clear();
}


template <typename T, class Container>
bool Stack<T, Container>::empty() const {
    return container.empty();
}

template <typename T, class Container>
void Stack<T, Container>::clear() {
    container.clear();
}

template <typename T, class Container>
void Stack<T, Container>::push(const T& val) {
    container.push_back(val);
}

template <typename T, class Container>
void Stack<T, Container>::push(T && val) {
    container.push_back(std::move(val));
}

template <typename T, class Container>
void Stack<T, Container>::pop() {
    container.pop_back();
}

template <typename T, class Container>
T& Stack<T, Container>::top() {
    return container.back();
}

template <typename T, class Container>
const T& Stack<T, Container>::top() const {
    return container.back();
}

template <typename T, class Container>
int Stack<T, Container>::size() const {
    return container.size();
}

template <typename T, class Container>
void Stack<T, Container>::print(std::ostream& os, char ofc) const {
    for(auto itr = container.begin(); itr != container.end(); itr++) {
        os << *itr << ofc;
    }
}

template<typename T, class Container = std::deque<T>>
bool operator==(const Stack<T, Container>& lhs, const Stack<T, Container>& rhs) {
    if(lhs.container.size() != rhs.container.size()) {
        return false;
    }

    for(auto itrl = lhs.container.begin(), itrr = rhs.container.begin(); itrl != lhs.container.end(); itrl++, itrr++) {
        if(*itrr != *itrl) {
            return false;
        }
    }

    return true;
}

template<typename T, class Container = std::deque<T>>
bool operator!=(const Stack<T, Container>& lhs, const Stack<T, Container>& rhs) {
    return !(lhs == rhs);
}

template<typename T, class Container = std::deque<T>>
std::ostream & operator<<(std::ostream &os, const Stack<T, Container> &l) {
    l.print(os);
    return os;
}

template<typename T, class Container = std::deque<T>>
bool operator<=(const Stack<T>& a, const Stack<T, Container>& b) {
    if(a.size() > b.size()) {
        return false;
    }

    for(auto itra = a.container.begin(), itrb = b.container.begin(); itra != a.container.end(); itra++, itrb++) {
        if(*itra > *itrb) {
            return false;
        }
    }

    return true;
}

#endif