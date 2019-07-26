/*************************************************************************
	> File Name: allocator.h
	> Course: 
	> Author: Mendy 
	> Mail: dolai_c@163.com
	> Created Time: 五  7/26 14:46:57 2019
 ************************************************************************/
#pragma once

namespace haizei {

    template <bool clear_memory>
    class newAllocator {
        void * alloc(size_t n);

        void * dealloc(void *p, size_t n);

        void * realloc(void *p, size_t old_size, size_t new_size);
    };




}
