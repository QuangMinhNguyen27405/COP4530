#ifndef MY_MEMORY_H
#define MY_MEMORY_H

#include "MyMemoryBlock.h"
#include "List.h"

namespace cop4530 {

    class MyMemory {
        public: 
            MyMemory(int num = 0, int len = 0);
            ~MyMemory();

            void resize(int num = 100, int len = 100);
            int req_mem(int len);
            bool release_mem(int ind, int len);
            void merge_mem();
            void dump();
        private: 
            List <MyMemoryBlock> mlist;

            int max_index;
            int block_size;
    };

#include "MyMemory.hpp"
}

#endif

