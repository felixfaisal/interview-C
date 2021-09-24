#include<stdio.h>
#include<stdlib.h>

typedef struct node_t{
    int data; 
    struct node_t* next;
} node_t;

node_t* create(){
    node_t* head = NULL;
    return head;
}

node_t* create_node(int data){
    node_t* node = malloc(sizeof(node_t)*1);
    node->data = data; 
    node->next = NULL;
    return node;
}

node_t* push(node_t* head, int data){
    if(head == NULL){
        head = create_node(data);
        return head;
    }
    // Not empty 
    node_t* node = create_node(data);
    node->next = head;
    head = node;
    return node;
}

void dump(node_t* head){
    node_t* temp = head;
    while(temp!= NULL){
        printf("%d<-",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int peek(node_t* head){
    node_t* temp = head;
    // printf("%d", temp->data);
    return temp->data;
}
node_t* pop(node_t* head){
    node_t* temp = head;
    head = head->next;
    free(temp);
    return head;
}
void min_stack(node_t* head){
    int min = head->data;
    node_t* temp = head;
    temp = pop(temp);
    while(temp!=NULL){
        if(peek(temp)<min){
            min = temp->data;
        }
        temp = pop(temp);
    }
    printf("%d\n",min);
}

int main(){
    node_t* stack = create();
    // stack = push(stack, 1);
    stack = push(stack, 2);
    stack = push(stack, 3);
    stack = push(stack, 5);
    stack = push(stack, 10);
    dump(stack);
    // peek(stack);
    stack = pop(stack);
    dump(stack);
    min_stack(stack);
    // dump(stack);
    return 0;
}
