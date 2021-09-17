#include<stdio.h>
#include<stdlib.h>

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
        printf("%d \t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void main(){
    insert_first(1);
    insert_first(2);
    insert_first(3);
    insert_last(10);
    insert_last(30);
    dump();
    delete_first();
    delete_last();
    delete_at_pos(1);
    dump();
}