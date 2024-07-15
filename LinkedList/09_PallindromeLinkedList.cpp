/*
Given the head of a singly linked list, return true if it is a  palindrome or false otherwise.

Input: head = [1,2,2,1]
Output: true
 */

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)
        return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* prev = NULL;
        ListNode* curr = slow;
        ListNode* newNode;

        while(curr!=NULL){
             newNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = newNode;
        }
        ListNode* firstHalf = head;
        ListNode* secondHalf = prev;

    while (secondHalf != NULL) {
        if (firstHalf->val != secondHalf->val)
            return false;

        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
    }
};