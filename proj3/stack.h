#ifndef STACK_H
#define STACK_H

#include <deque>
#include <list>

namespace cop4530 {

    template<typename T, class Container = std::deque<T>>
    class Stack
    {
    private:
        Container container;

    public:

        template<typename U, class C>
        friend bool operator==(const Stack<U, C>& lhs, const Stack<U, C>& rhs);

        template<typename U, class C>
        friend bool operator!=(const Stack<U, C>& lhs, const Stack<U, C>& rhs);

        template<typename U, class C>
        friend std::ostream& operator<<(std::ostream& os, const Stack<U, C>& l);

        template<typename U, class C>
        friend bool operator<=(const Stack<U>& a, const Stack<U, C>& b);

        // Constructors
        Stack();                    // Default constructor                   
        Stack(const Stack& rhs);    // Copy constructor
        Stack(Stack && rhs);        // Move constructor
        Stack& operator=(const Stack& rhs); // Copy assignment operator=
        Stack& operator=(Stack&& rhs);      // Move assignment operator=

        // Destructors
        ~Stack();

        // Member functions
        bool empty() const;
        void clear();
        void push(const T& val);
        void push(T && val);
        void pop();
        T& top();
        const T& top() const;
        int size() const;
        void print(std::ostream& os, char ofc = ' ') const;
    };

#include "stack.hpp"
}

#endif