/*
Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curr1=headA;
        ListNode* curr2=headB;
        ListNode* result_node;
        int count1=0,count2=0,diff_count=0;
        
        while(curr1 != NULL || curr2 != NULL){
            if(curr1){
                curr1 = curr1 -> next;
                count1++;
            }
            if(curr2){
                curr2 = curr2 -> next;
                count2++;
            }
        }

        curr1=headA;
        curr2=headB;

        if(count1>count2){
            diff_count=count1-count2;
            for(int i=0;i<diff_count;i++){
                curr1=curr1->next;
            }
        }
        else{
            diff_count=count2-count1;
            for(int i=0;i<diff_count;i++){
                curr2=curr2->next;
            }
        }
        while(curr1!=NULL){
            if(curr1==curr2){
                result_node=curr1;
                break;
            }
            curr1=curr1->next;
            curr2=curr2->next;
        }
        return result_node;
    }
};