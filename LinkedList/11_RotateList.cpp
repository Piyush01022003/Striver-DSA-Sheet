/**
 Given the head of a linked list, rotate the list to the right by k places.

Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
 */

class Solution {
public:
    ListNode* findKthNode(ListNode* head, int k){
        k=k-1;
        while(head!=NULL && k>0){
            head=head->next;
            k--;
        }
        return head;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0){
            return head;
        }
        ListNode* tail=head;
        int len=1;
        while(tail->next!=NULL){
            len=len+1;
            tail=tail->next;
        }
        if(k%len==0){
            return head;
        }
        k=k%len;
        ListNode* newLastNode=findKthNode(head,len-k);
        tail->next=head;
        head=newLastNode->next;
        newLastNode->next=NULL;

        return head;
    }
};