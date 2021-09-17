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
}
void dump(node_t* head){
    node_t* cur = head;
    while(cur!=NULL){
        printf("%d->", cur->data);
        cur = cur->next;
    }
    printf("\n");
}
node_t* insert_at_pos(node_t* head, int pos, int data){
    int idx = 0;
    node_t* cur = head;
    node_t* prev = NULL;

    while(cur!=NULL && idx!=pos){
        idx++;
        prev = cur;
        cur = cur->next;
    }
    // if head
    if(idx==0){
        node_t* temp = create_node(data);
        temp->next = head;
        head = temp;
        return head;
        //free(temp);
    }
    // if last
    if(cur==NULL){
        prev->next = create_node(data);
        return head;
    }
    //middle 
    node_t* temp = create_node(data);
    prev->next = temp;
    temp->next = cur;
    return head;

}
node_t* partition(node_t* head,int key){
    node_t* new_list = create();
    node_t* cur = head;
    // node_t* prev = NULL;
    while(cur!=NULL){
        node_t* temp = cur;
        int data = temp->data;
        cur = cur->next;
        if(temp->data<key) new_list = insert_at_pos(new_list,0,data);
        else new_list = insert_at_pos(new_list,-1,data);
        temp->next = NULL;
        free(temp);
    }
    // `dump(new_list);
    return new_list;
}
node_t* sum_of(node_t* list1, node_t* list2){
    int carry = 0;
    node_t* sumlist = create();
    node_t* cur1 = list1;
    node_t* cur2 = list2;
    while(cur1 != NULL && cur2 != NULL){
        int sum = cur1->data + cur2->data + carry;
        carry = sum/10;
        sum = sum%10;
        sumlist = insert_at_pos(sumlist,-1,sum);
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return sumlist;
}

void main(){
    node_t* list1 = create();
    node_t* list2 = create();
    list1 = insert_at_pos(list1,0,1);
    list1 = insert_at_pos(list1,0,7);
    list1 = insert_at_pos(list1,0,8);
    list2 = insert_at_pos(list2,0,3);
    list2 = insert_at_pos(list2,-1,4);
    list2= insert_at_pos(list2,0,5);
    dump(list1);
    //list = partition(list, 5);
    dump(list2);
    // node_t* sum = sum_of(list1,list2);
    dump(sum_of(list1,list2));
    // 178 + 435 = 613
}