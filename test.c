/*************************************************************************
	> File Name: test.c
	> Course: 
	> Author: Mendy 
	> Mail: dolai_c@163.com
	> Created Time: 四  7/25 18:15:36 2019
 ************************************************************************/

#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct HashTable {
    char **elem;
    int size;
} HashTable;

void init(HashTable *h);
int hash(HashTable *h, char value[]);

void init(HashTable *h) {
    h->size = 2000;
    h->elem = (char **)malloc(sizeof(char *) * h->size);
    for (int i = 0; i < h->size; i++) {
        h->elem[i] = NULL;
    }
}

// 请在下面实现构造哈希函数函数 hash
int hash(HashTable *h, char value[]){
    int code = 0;
    for(size_t i = 0; i < strlen(value); i++){
        printf("%d", value[i]);
    }
    return 0;
}

void clear(HashTable *h) {
    for (int i = 0; i < h->size; ++i) {
        if (h->elem[i] != NULL) {
            free(h->elem[i]);
        }
    }
    free(h->elem);
    free(h);
}

int main() {
    HashTable *hashtable = (HashTable*)malloc(sizeof(HashTable));
    init(hashtable);
    char buff[10] = "abc";
    printf("%d%d%d\n", buff[0], buff[1], buff[2]);
    clear(hashtable);
    return 0;
}
