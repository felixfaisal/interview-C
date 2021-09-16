#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCII_SIZE 128

typedef struct entry_c{
    char *key;
    int value;
}entry_c;

typedef struct{
    entry_c** entries;
}hmap;

hmap *create(void){
    hmap *hashtable = malloc(sizeof(hmap)*1);
    hashtable->entries = malloc(sizeof(entry_c*)*ASCII_SIZE);
    for(int i=0; i<ASCII_SIZE; i++){
        hashtable->entries[i] = NULL;
    }
    return hashtable;
}
unsigned int hash(char *key){
    unsigned int number = *key;
    return number;
}
entry_c *create_entry(char *key, int value){
    entry_c* entry = malloc(sizeof(entry_c)*1);
    entry->key = malloc(strlen(key)+1);
    entry->value = value;
    strcpy(entry->key, key);
    return entry;
}
void hmap_set(hmap *hashtable, char *key, int value){
    unsigned int slot = hash(key);
    entry_c* entry = hashtable->entries[slot];
    if(entry == NULL){
        hashtable->entries[slot] = create_entry(key,value);
        return;
    }
    entry->value = value;
    return;

}
void hmap_dump(hmap *hashtable){
    for(int i=0; i<ASCII_SIZE; i++){
        entry_c* entry = hashtable->entries[i];
        if(entry==NULL){
            continue;
        }
        printf("[%s]->%d \n",entry->key, entry->value);
    }
}
int hmap_get(hmap *hashtable, char *key){
    int slot = hash(key);
    entry_c* entry = hashtable->entries[slot];
    if (entry == NULL){
        return -1;
    }
    return entry->value;
}
void hmap_del(hmap *hashtable, char *key){
    int slot = hash(key);
    entry_c* entry = hashtable->entries[slot];
    if(entry == NULL){
        return; 
    }
    hashtable->entries[slot] = NULL;
    free(entry->key);
    free(entry);
    return;
}

void main(){
    hmap *hm = create();
    hmap_set(hm, "a", 10);
    hmap_set(hm, "d", 5);
    hmap_dump(hm);
    hmap_del(hm, "a");
    hmap_dump(hm);
}