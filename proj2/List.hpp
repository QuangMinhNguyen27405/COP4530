/*
MINH NGUYEN
COP 4530
Implementation for List class
*/
#include <iostream>

#include "List.h"

using namespace cop4530;

// MEMBER FUNCTION OF NESTED CONST_ITERATOR CLASS

// const_iterator constructor
template<typename T>
List<T>::const_iterator::const_iterator() : current{nullptr} {}

// const_iterator reference
template<typename T>
const T& List<T>::const_iterator::operator*() const {
    return const_iterator::retrieve();
}

// const_iterator pointer
template<typename T>
const T* List<T>::const_iterator::operator->() const {
    return &const_iterator::retrieve();
}

// const_iterator pre-increment
template<typename T>
typename List<T>::const_iterator& List<T>::const_iterator::operator++() {
    this->current = this->current->next;
    return *this;
}

// const_iterator post-increment
template<typename T>
typename List<T>::const_iterator List<T>::const_iterator::operator++(int) {
    const_iterator temp = *this;
    ++(*this);
    return temp;
}

// const_iterator pre-decrement
template<typename T>
typename List<T>::const_iterator& List<T>::const_iterator::operator--() {
    this->current = this->current->prev;
    return *this;
}

// const_iterator post-decrement
template<typename T>
typename List<T>::const_iterator List<T>::const_iterator::operator--(int) {
    const_iterator temp = *this;
    --(*this);
    return temp;
}

// const_iterator equal sign
template<typename T>
bool List<T>::const_iterator::operator==(const const_iterator &rhs) const {
    return current == rhs.current;
}

// const_iterator NOT equal sign
template<typename T>
bool List<T>::const_iterator::operator!=(const const_iterator &rhs) const {
    return !(*this == rhs);
}

// const_iterator retrieve
template<typename T>
T& List<T>::const_iterator::retrieve() const {
    return current->data;
}

// const_iterator parameterized constructor
template<typename T>
List<T>::const_iterator::const_iterator(Node* p) : current{p} {}

// MEMBER FUNCTION OF NESTED ITERATOR CLASS

// iterator constructor
template<typename T>
List<T>::iterator::iterator() {}

// iterator reference
template<typename T>
T & List<T>::iterator::operator*() {
    return const_iterator::retrieve();
}

template<typename T>
const T & List<T>::iterator::operator*() const {
    return const_iterator::retrieve();
}

// iterator pointer
template<typename T>
T* List<T>::iterator::operator->() {
    return &const_iterator::retrieve();
}

template<typename T>
const T* List<T>::iterator::operator->() const {
    return &const_iterator::retrieve();
}

// iterator pre-increment
template<typename T>
typename List<T>::iterator & List<T>::iterator::operator++() {
    this->current = this->current->next;
    return *this;
}

// iterator post-increment
template<typename T>
typename List<T>::iterator List<T>::iterator::operator++(int) {
    iterator temp = *this;
    ++(*this);
    return temp;
}

// iterator pre-decrement
template<typename T>
typename List<T>::iterator& List<T>::iterator::operator--() {
    this->current = this->current->prev;
    return *this;
}

// iterator post-decrement
template<typename T>
typename List<T>::iterator List<T>::iterator::operator--(int) {
    iterator temp = *this;
    --(*this);
    return temp;
}

// iterator parameterized constructor
template<typename T>
List<T>::iterator::iterator(Node* p) : const_iterator{p} {}

// MEMBER FUNCTION OF LIST CLASS

// constructor, desctructor, copy constructor
template<typename T>
List<T>::List()   // default zero parameter constructor
{
    init();
} 

template<typename T>
List<T>::List(const List &rhs)   // copy constructor
{ 
    init();
    for( auto &x : rhs ) {
        push_back(x);
    }
} 

template<typename T>
List<T>::List(List && rhs) : theSize{ rhs.theSize }, head{ rhs.head }, tail{ rhs.tail } // move constructor
{
    rhs.theSize = 0;
    rhs.head = nullptr;
    rhs.tail = nullptr;
}

// num elements with value of val
template<typename T>
List<T>::List(int num, const T& val) {
    init();

    for(int i = 0; i < num; ++i) {
        push_back(val);
    }
}

// constructs with elements [start, end)
template<typename T>
List<T>::List(const_iterator start, const_iterator end) 
{
    init();

    for(auto it = start; it != end; it++){
        push_back(*it);
    }
}

template<typename T>
List<T>::~List() // destructor
{
    clear();
    delete head;
    delete tail;
}

// copy assignment operator
template<typename T>
const List<T>& List<T>::operator=(const List &rhs) {
    List copy = rhs;
    std::swap( *this, copy );
    return *this;

}

// move assignment operator
template<typename T>
List<T> & List<T>::operator=(List && rhs) {
    std::swap( theSize, rhs.theSize );
    std::swap( head, rhs.head );
    std::swap( tail, rhs.tail );
    
    return *this;
}

// member functions
template<typename T>
int List<T>::size() const // number of elements
{
    return theSize;
}

template<typename T>
bool List<T>::empty() const // check if list is empty
{
    return theSize == 0;
}

template<typename T>
void List<T>::clear() // delete all elements
{
    while(!empty()) {
        pop_front();
    }
}

template<typename T>
void List<T>::reverse() // reverse the order of the elements
{
    List<T> temp;
    while(!this->empty()) {
        temp.push_back(this->back());
        this->pop_back();
    }

    while(!temp.empty()) {
        this->push_back(temp.front());
        temp.pop_front();
    }
}

template<typename T>
T& List<T>::front() // reference to the first element
{
    return *begin();
}

template<typename T>
const T& List<T>::front() const
{
    return *begin();
}

template<typename T>
T& List<T>::back() // reference to the last element
{
    return *--end();
}

template<typename T>
const T & List<T>::back() const
{
    return *--end();    
} 

template<typename T>
void List<T>::push_front(const T & val) // insert to the beginning
{
    insert(begin(), val);
}

template<typename T>
void List<T>::push_front(T && val) // move version of insert
{
    insert(begin(), std::move(val));
}

template<typename T>
void List<T>::push_back(const T & val) // insert to the end
{
    insert(end(), val);
}

template<typename T>
void List<T>::push_back(T && val) // move version of insert
{
    insert(end(), std::move(val));
}

template<typename T>
void List<T>::pop_front() // delete first element
{
    erase(begin());
}

template<typename T>
void List<T>::pop_back() // delete last element
{
    erase(--end());
}

template<typename T>
void List<T>::remove(const T &val) // remove all elements with value = val
{
    for(auto it = begin(); it != end();) {
        if(*it == val) {
            it = erase(it);
        } else {
            it++;
        }
    }
}

// print out all elements. ofc is deliminitor
template<typename T>
void List<T>::print(std::ostream& os, char ofc) const
{
    for (auto itr = begin(); itr != end(); ++itr) os << *itr << ofc;
}

template<typename T>
typename List<T>::iterator List<T>::begin() // iterator to first element
{
    return iterator(head->next);
}

template<typename T>
typename List<T>::const_iterator List<T>::begin() const
{
    return const_iterator(head->next);
}

template<typename T>
typename List<T>::iterator List<T>::end() // end marker iterator
{
    return iterator(tail);
}

template<typename T>
typename List<T>::const_iterator List<T>::end() const
{
    return const_iterator(tail);
}

template<typename T>
typename List<T>::iterator List<T>::insert(iterator itr, const T& val) // insert val ahead of itr
{
    Node *p = itr.current;
    ++theSize;
    return iterator( p->prev = p->prev->next = new Node{ val, p->prev, p } );
}

template<typename T>
typename List<T>::iterator List<T>::insert(iterator itr, T && val) // move version of insert
{
    Node *p = itr.current;
    ++theSize;
    return iterator( p->prev = p->prev->next = new Node{ std::move(val), p->prev, p } );
}

template<typename T>
typename List<T>::iterator List<T>::erase(iterator itr) // erase one element
{
    Node *p = itr.current;
    iterator temp( p->next );
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
    --theSize;
    return temp;
}

template<typename T>
typename List<T>::iterator List<T>::erase(iterator start, iterator end) // erase [start, end)
{
    while (start != end) {
        start = erase(start);
    }

    return end;
}

template<typename T>
void List<T>::init() {
    theSize = 0;
    head = new Node;
    tail = new Node;
    head->next = tail;
    tail->prev = head;
}

// overloading comparison operators
template <typename T>
bool operator==(const List<T> & lhs, const List<T> &rhs)
{
    if(lhs.size() != rhs.size()) {
        return false;
    }

    for(auto itr1 = lhs.begin(), itr2 = rhs.begin(); itr1 != lhs.end(); ++itr1, ++itr2) {
        if(*itr1 != *itr2) {
            return false;
        }
    }

    return true;
}

template <typename T>
bool operator!=(const List<T> & lhs, const List<T> &rhs) {
    return !(lhs == rhs);
}

// overloading output operator
template <typename T>
std::ostream & operator<<(std::ostream &os, const List<T> &l) {
    l.print(os);
    return os;
}
