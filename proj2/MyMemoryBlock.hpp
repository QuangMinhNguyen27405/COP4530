/*
MINH NGUYEN
COP 4530
Implementation for MyMemoryBlock class
*/
#include "MyMemory.h"

using namespace cop4530;

// Constructor
MyMemoryBlock::MyMemoryBlock(int ind, int len) : index{ind}, length{len} {}

// member functions
int MyMemoryBlock::get_length() const {
    return length;
}

int MyMemoryBlock::get_index() const {
    return index;
}

int MyMemoryBlock::allocate_mem(int len) {
    if(length >= len) {
        length -= len;
        return length;
    } 

    return -1;
}

void MyMemoryBlock::free_mem(int len) {
    length += len;
}
