#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 20000
#define ASCI_SIZE 128

typedef struct entry_t {
    char *key;
    char *value;
    struct entry_t *next;
} entry_t;

typedef struct char_entry{
    char *key; 
    int value; 
    struct char_entry *next; 
} char_entry;

typedef struct {
    char_entry **entries; // pointer to a pointer to char_entry
} hmap;

typedef struct {
    entry_t **entries;
} ht_t;

unsigned int hash_char(const char* key){
    unsigned int number = *key;
    return number;
}

unsigned int hash(const char *key) {
    unsigned long int value = 0;
    unsigned int i = 0;
    unsigned int key_len = strlen(key);

    // do several rounds of multiplication
    for (; i < key_len; ++i) {
        value = value * 37 + key[i];
    }

    // make sure value is 0 <= value < TABLE_SIZE
    value = value % TABLE_SIZE;

    return value;
}

char_entry *hmap_pair(const char *key, int value){
    // allocating the entry 
    char_entry *entry = malloc(sizeof(char_entry) * 1);
    entry->key = malloc(strlen(key)+1);
    // entry->value = malloc(sizeof(value));
    strcpy(entry->key, key);
    entry->value = value;
    entry->next = NULL; 
    return entry;
}

entry_t *ht_pair(const char *key, const char *value) {
    // allocate the entry
    entry_t *entry = malloc(sizeof(entry_t) * 1);
    entry->key = malloc(strlen(key) + 1);
    entry->value = malloc(strlen(value) + 1);

    // copy the key and value in place
    strcpy(entry->key, key);
    strcpy(entry->value, value);

    // next starts out null but may be set later on
    entry->next = NULL;

    return entry;
}

hmap *hmap_create(void){
    hmap *hashtable = malloc(sizeof(hmap) * 1);
    hashtable->entries = malloc(sizeof(entry_t*)*ASCI_SIZE);

    int i = 0; 
    for(; i<ASCI_SIZE; ++i){
        hashtable->entries[i] = NULL;
    }
    return hashtable;
}

ht_t *ht_create(void) {
    // allocate table
    ht_t *hashtable = malloc(sizeof(ht_t) * 1);

    // allocate table entries
    hashtable->entries = malloc(sizeof(entry_t*) * TABLE_SIZE);

    // set each to null (needed for proper operation)
    int i = 0;
    for (; i < TABLE_SIZE; ++i) {
        hashtable->entries[i] = NULL;
    }

    return hashtable;
}
void hmap_set_update(hmap *hashtable, const char* key){
    unsigned int slot = hash_char(key);
    char_entry *entry = hashtable->entries[slot];
    if(entry == NULL){
        hashtable->entries[slot] = hmap_pair(key, 1);
        return;
    }
    entry->value += 1;
    return;
}
void hmap_set(hmap *hashtable, const char *key, int value){
    unsigned int slot = hash_char(key);

    // See if this slot exists 
    char_entry *entry = hashtable->entries[slot];

    // If no entry, we insert in that slot 
    if (entry == NULL){
        // printf("%d \n",value);
        hashtable->entries[slot] = hmap_pair(key,value);
        return;
    }
}

void ht_set(ht_t *hashtable, const char *key, const char *value) {
    unsigned int slot = hash(key);

    // try to look up an entry set
    entry_t *entry = hashtable->entries[slot];

    // no entry means slot empty, insert immediately
    if (entry == NULL) {
        hashtable->entries[slot] = ht_pair(key, value);
        return;
    }

    entry_t *prev;

    // walk through each entry until either the end is
    // reached or a matching key is found
    while (entry != NULL) {
        // check key
        if (strcmp(entry->key, key) == 0) {
            // match found, replace value
            free(entry->value);
            entry->value = malloc(strlen(value) + 1);
            strcpy(entry->value, value);
            return;
        }

        // walk to next
        prev = entry;
        entry = prev->next;
    }

    // end of chain reached without a match, add new
    prev->next = ht_pair(key, value);
}
int hmap_get(hmap *hashtable, const char *key) {
    unsigned int slot = hash(key);
    char_entry *entry = hashtable->entries[slot];
    if(entry == NULL){
        return -1; 
    }
    return entry->value;
}

char *ht_get(ht_t *hashtable, const char *key) {
    unsigned int slot = hash(key);

    // try to find a valid slot
    entry_t *entry = hashtable->entries[slot];

    // no slot means no entry
    if (entry == NULL) {
        return NULL;
    }

    // walk through each entry in the slot, which could just be a single thing
    while (entry != NULL) {
        // return value if found
        if (strcmp(entry->key, key) == 0) {
            return entry->value;
        }

        // proceed to next key if available
        entry = entry->next;
    }

    // reaching here means there were >= 1 entries but no key match
    return NULL;
}

void hmap_del(hmap *hashtable, const char *key){
    unsigned int slot = hash_char(key);
    char_entry *entry = hashtable->entries[slot];
    if(entry == NULL){
        return; 
    }
    hashtable->entries[slot] = NULL;
    // free(entry->value);
    free(entry->key);
    free(entry);
}
void ht_del(ht_t *hashtable, const char *key) {
    unsigned int bucket = hash(key);

    // try to find a valid bucket
    entry_t *entry = hashtable->entries[bucket];

    // no bucket means no entry
    if (entry == NULL) {
        return;
    }

    entry_t *prev;
    int idx = 0;

    // walk through each entry until either the end is reached or a matching key is found
    while (entry != NULL) {
        // check key
        if (strcmp(entry->key, key) == 0) {
            // first item and no next entry
            if (entry->next == NULL && idx == 0) {
                hashtable->entries[bucket] = NULL;
            }

            // first item with a next entry
            if (entry->next != NULL && idx == 0) {
                hashtable->entries[bucket] = entry->next;
            }

            // last item
            if (entry->next == NULL && idx != 0) {
                prev->next = NULL;
            }

            // middle item
            if (entry->next != NULL && idx != 0) {
                prev->next = entry->next;
            }

            // free the deleted entry
            free(entry->key);
            free(entry->value);
            free(entry);

            return;
        }

        // walk to next
        prev = entry;
        entry = prev->next;

        ++idx;
    }
}

void hmap_dump(hmap *hashtable){
    for(int i=0; i<ASCI_SIZE;++i){
        char_entry *entry = hashtable->entries[i];
        if (entry == NULL){
            continue;
        }
        printf("[%d]:[%s]=%d \n",i,entry->key,entry->value);
    } 
}


void ht_dump(ht_t *hashtable) { // This is quite costly 
    for (int i = 0; i < TABLE_SIZE; ++i) {
        entry_t *entry = hashtable->entries[i];

        if (entry == NULL) {
            continue;
        }

        printf("slot[%4d]: ", i);

        for(;;) {
            printf("%s=%s ", entry->key, entry->value);

            if (entry->next == NULL) {
                break;
            }

            entry = entry->next;
        }

        printf("\n");
    }
}
int check_if_permutation_palindrom(hmap *hashtable, int size){
    int flag = 0;
    for(int i =0; i<ASCI_SIZE; i++){
        char_entry* entry = hashtable->entries[i];
        if(entry == NULL){
            continue;
        }
        if (size%2 != 0){
            if (entry->value%2 !=0){
                if(flag==0){
                    flag = 1;
                }
                else{
                    return -1;
                }
            }
        }
        else{
            if(entry->value%2 == 0){
                return -1;
            }
        }
    }
    return 0;
}

void main() {
    /* ht_t *ht = ht_create();

    ht_set(ht, "name1", "em");
    ht_set(ht, "name2", "russian");
    ht_set(ht, "name3", "pizza");
    ht_set(ht, "name4", "doge");
    ht_set(ht, "name5", "pyro");
    ht_set(ht, "name6", "joost");
    ht_set(ht, "name7", "kalix");*/
    // char *faisal = ht_get(ht, "name2");
    hmap *hm = hmap_create();
    /*hmap_set(hm, "f",6);
    hmap_set(hm, "a",2);
    hmap_set(hm, "e",1);*/
    printf("%d \n",hmap_get(hm,"f"));
    hmap_dump(hm);
    char* c = "taco catod";
    // int len = strlen(c);
    int len = 0;
    for (int i = 0; c[i] != 0; i++) { // O(N)
        if(c[i] == ' '){
            continue;
        }
        char key = c[i];
        len++;
        hmap_set_update(hm,&key); // O(1)
    }
    // hmap_set(hm,"k",10);
    printf("%d \n",check_if_permutation_palindrom(hm,len)); // O(128)
    hmap_dump(hm);
    // ht_dump(ht);
}
// Time Complexity = O(N+1+128) = O(N)
