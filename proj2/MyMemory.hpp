/*
MINH NGUYEN
COP 4530
Implementation for MyMemory class
*/
#include "MyMemoryBlock.h"
#include "List.h"

using namespace cop4530;
using namespace std;

MyMemory::MyMemory(int num, int len) : max_index(num - 1), block_size(len) {
    for(int i = 0; i < num; ++i) {
        mlist.push_back(MyMemoryBlock(i, len));
    }
}

MyMemory::~MyMemory() {
    mlist.clear();
}

void MyMemory::resize(int num, int len) {
    if(!mlist.empty()) {
        mlist.clear();
    }

    max_index = num;
    block_size = len;

    for(int i = 0; i < num; ++i) {
        mlist.push_back(MyMemoryBlock(i, len));
    }
}

int MyMemory::req_mem(int len) {

    for(auto itr = mlist.begin(); itr != mlist.end(); ++itr) {
        if(itr->allocate_mem(len) != -1) {
            int save_index = itr->get_index();
            if(itr->get_length() == 0) {
                mlist.erase(itr);
            }
            return save_index;
        }
    }
    // if the memory index is not found
    return -1;
}

bool MyMemory::release_mem(int ind, int len) {
    if(0 > len || len > block_size) {
        return false;
    }

    if(0 > ind || ind > max_index) {
        return false;
    }


    for(auto itr = mlist.begin(); itr != mlist.end(); itr++) {
        // if the memory index is found
        if(itr->get_index() == ind) {
            itr->free_mem(len);
            return true;
        }
        // if the memory is not found
        if(itr->get_index() > ind) {
            mlist.insert(--itr, MyMemoryBlock(ind, len));
            return true;
        }
    }

    return false;
}

void MyMemory::merge_mem() {
    for(auto itr = mlist.begin(); itr != mlist.end(); ) {
        if(itr != mlist.begin()) {
            auto prev_itr = itr;
            prev_itr--;

            int prev_mem = prev_itr->get_length();
            int curr_mem = itr->get_length();

            if(prev_mem + curr_mem <= block_size) {
                prev_itr->free_mem(curr_mem); 
                itr = mlist.erase(itr); 
            } else {
                ++itr;
            }
        } else {
            ++itr;
        }
    }
}

void MyMemory::dump() {
    cout << "Number of blocks: " << mlist.size() << "\n";
    for(auto itr = mlist.begin(); itr != mlist.end(); ++itr) {
        cout << "Block(index = " << itr->get_index() << "): " << itr->get_length() << "\n";
    }
}
