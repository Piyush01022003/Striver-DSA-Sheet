/*
Given the head of a singly linked list, reverse the list, and return the reversed list.
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* prev=NULL;
        ListNode* front=head->next;
        while(head!=NULL){
            if(front==NULL){
                head->next=prev;
                prev=head;
                break;
            }
            head->next=prev;
            prev=head;
            head=front;
            front=front->next;
        }
        return prev;
    }
};