#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCII_SIZE 128

typedef struct entry_c{
    int key;
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
unsigned int hash(int key){
    unsigned int number = key;
    return number;
}
entry_c *create_entry(int key, int value){
    entry_c* entry = malloc(sizeof(entry_c)*1);
    // entry->key = malloc(strlen(key)+1);
    entry->value = value;
    entry->key = key;
    //strcpy(entry->key, key);
    return entry;
}
void hmap_set(hmap *hashtable, int key, int value){
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
        printf("[%d]->%d \n",entry->key, entry->value);
    }
}
int hmap_get(hmap *hashtable, int key){
    int slot = hash(key);
    entry_c* entry = hashtable->entries[slot];
    if (entry == NULL){
        return -1;
    }
    return entry->value;
}
void hmap_del(hmap *hashtable, int key){
    int slot = hash(key);
    entry_c* entry = hashtable->entries[slot];
    if(entry == NULL){
        return; 
    }
    hashtable->entries[slot] = NULL;
    // free(entry->key);
    free(entry);
    return;
}
typedef struct node_t{
    int data; 
    struct node_t* next;
} node_t;

node_t *head = NULL;

void insert_at_pos(int pos,int data){
    node_t *node = malloc(sizeof(node_t)*1);
    node->data = data; 
    node->next = NULL;

    // If list is empty
    if(head == NULL){
        head = node;
        return;
    }

    int idx = 0;

    node_t* prev = NULL;
    node_t* cur = head;

    while(cur!=NULL && idx != pos){
        ++idx;
        prev = cur;
        cur = cur->next;
    }

    // Insertion point reached
    
    if(idx == 0){
        head = node;
        node->next = cur;
        return;
    }

    //end 
    if(cur == NULL){
        prev->next = node;
    }

    // middle
    prev->next = node;
    node->next = cur;
}
void delete_at_pos(int pos){
    if(head == NULL){
        return;
    }
    if(pos == 0){
        node_t* temp = head;
        head = head->next;
        free(temp);
        return;
    }
    int idx = 0;
    node_t* prev = NULL;
    node_t* cur = head;
    while(cur->next!=NULL && idx != pos){
        prev = cur;
        cur = cur->next;
        ++idx;
    }
    if(cur->next == NULL){
        prev->next = NULL;
        free(cur);
        return;
    }
    prev->next = cur->next;
    free(cur);
}

void delete_first(){
    delete_at_pos(0);
}
void delete_last(){
    delete_at_pos(-1);
}
void insert_first(int data){
    insert_at_pos(0,data);
}

void insert_last(int data){
    insert_at_pos(-1, data);
}

void dump(){
    node_t *temp = head;
    while(temp != NULL){
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void remove_dups(){
    hmap *hm = create();
    node_t* cur = head;
    node_t* prev = NULL;
    while(cur!=NULL){
        if(hmap_get(hm,cur->data) != -1){
            //printf("\n %d",cur->data);
            // if last element 
            if(cur->next == NULL){
                // printf("%d", cur->data);
                prev->next = NULL;
                free(cur);
                return;
            }
            // middle element
            node_t* temp = cur;
            prev->next = cur->next;
            cur = cur->next;
            free(temp);
            continue;
        }
        else{
            hmap_set(hm,cur->data,1);
        }
        prev = cur;
        cur = cur->next;
    }
}
int size_of_linked_list(node_t* head){
    int count = 0;
    node_t* cur = head;
    while(cur!=NULL){
        cur = cur->next;
        count++;
    }
    return count;
}
int kth_last(int k){
    if(k==0)k=k+1;
    int len = size_of_linked_list(head);
    int pos = len-k;
    node_t* cur = head;
    node_t* prev = NULL;
    int idx = 0;
    while(cur!=NULL && idx != pos){
        idx++;
        prev = cur;
        cur = cur->next;

    }
    if(cur!=NULL)return cur->data;
    return -1;
}
void delete_middle_nod(){
    int len = size_of_linked_list(head);
    int pos;
    if(len%2!=0)pos = (len+1)/2;
    else pos = len/2;

    int idx = 0;
    node_t* cur = head;
    node_t* prev = NULL;
    while(cur!=NULL && idx != pos){
        idx++;
        prev = cur;
        cur = cur->next;
    }
    // We can always assume it's going to be in middle
    prev->next = cur->next;
    free(cur);
}


void main(){
    insert_first(1);
    insert_last(3);
    insert_first(2);
    insert_first(2);
    insert_last(3);
    insert_first(3);
    insert_last(10);
    insert_last(10);
    insert_last(9);
    insert_last(20);
    dump();
    // remove_dups();
    // printf("%d\n",kth_last(0));
    delete_middle_nod();
    delete_middle_nod();
    dump();
}
/* void main(){
    hmap *hm = create();
    hmap_set(hm, "a", 10);
    hmap_set(hm, "d", 5);
    hmap_dump(hm);
    hmap_del(hm, "a");
    hmap_dump(hm);
}*/