/*************************************************************************
	> File Name: allocator.cpp
	> Course: 
	> Author: Mendy 
	> Mail: dolai_c@163.com
	> Created Time: 五  7/26 15:06:30 2019
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <sys/mman.h>
#include "allocator.h"
namespace haizei{
    static size_t MMAP_THRESHOLD = 64 * (1ULL << 20);//左移20

    template <bool clear_memory>
    void * newAllocator<clear_memory>::alloc(size_t n) {
        void * buff;
        if(n < MMAP_THRESHOLD) {
            if(clear_memory) buff = ::calloc(n, 1);
            else buff = ::malloc(n);
            if(buff == nullptr) {
                throw "wrong alloc";
            }
        } else {
            buff = mmap(nullptr, n, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);//Any extension beyond the end of the mapped object will be zero-filled.
            if(MAP_FAILED == buff) throw "wrong alloc";
        
        }
        return buff;//返回地址
    }

    template<bool clear_memory>
    void * newAllocator<clear_memory>::dealloc(void *p, size_t n) {
        if(n < MMAP_THRESHOLD) {
            ::free(p);
        } else {
            if(0 != munmap(p, n)) {
                //munmap: remove a map,int munmap(void *attr, size_t len);
                throw("wrong free");
            }
        }
    }

    template<bool clear_memory>
    void * newAllocator<clear_memory>::realloc(void *p, size_t old_size, size_t new_size) {
        if(old_size > MMAP_THRESHOLD && new_size > MMAP_THRESHOLD ) {
            p = mremap(p, new_size, old_size, MREMAP_FIXED | MREMAP_MAYMOVE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
            //mremap：remap a virtual memory address, void *mremap(void *old_address, size_t old_size, size_t new_size, int flags, .../*void *new_address */)
            
        }
    }
}
