#ifndef MY_MEMORY_BLOCK
#define MY_MEMORY_BLOCK

namespace cop4530 {

    class MyMemoryBlock {
        public: 
            // Constructor
            MyMemoryBlock(int ind = 0, int len = 0);

            // member functions
            int get_length() const;
            int get_index() const;
            int allocate_mem(int len);
            void free_mem(int len);

        private: 
            int index;
            int length;
    };

#include "MyMemoryBlock.hpp"
}

#endif