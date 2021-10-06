#include<iostream>
using namespace std;
struct ListNode{
    int val; 
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    // The numbers are in reverse
    // The numbers can be of different lenghts 
    // 2->4->3 = 342 
    // 5->6->4 = 654 
    // 342 + 465 = 807
    // Can we construct a number going backwards? 
    // 2 + 4*10 + 3*10^2 = 342 
    // 5 + 6*10 + 4*10^2 = 465
    // N+N 
    // 2+5 = 7, 4+6 = 10, Carry = 1 and
    // Let's add it to the second list 
    struct ListNode* cur1 = l1;
    struct ListNode* cur2 = l2;
    int carry = 0;
    while(cur1!=NULL && cur2!=NULL){
        if(carry==0){
            int sum = cur1->val + cur2->val;
            if(sum>10){
                carry = sum/10;
                sum = sum%10;
            }
            cur2->val = sum;
        }
        else{
            int sum = cur1->val + cur2->val + carry;
            if(sum>10){
                carry = sum/10;
                sum = sum%10;
            }
            cur2->val = sum;
        }
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return l2;
}