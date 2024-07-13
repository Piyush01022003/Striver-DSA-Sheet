/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL && n==1){
            return NULL;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        if(fast==NULL){
                return head->next;
                delete head;
            }
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;

        }
        ListNode* delNode=slow->next;
        slow->next=slow->next->next;
        delete delNode;
        return head;
    }
};