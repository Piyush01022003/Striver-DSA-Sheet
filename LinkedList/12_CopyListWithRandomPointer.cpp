/*
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.
Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.
For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
*/

class Solution {
public:
    void insertCopyInBetween(Node* head){
        Node* temp=head;
        while(temp!=NULL){
            Node* nextElement=temp->next;
            Node* copy= new Node(temp->val);
            copy->next=nextElement;
            temp->next=copy;

            temp=nextElement;
        }
    }

    void connectRandomPointers(Node* head){
        Node* temp=head;
        while(temp!=NULL){
            Node* copyNode= temp->next;
            if(temp->random){
                copyNode->random=temp->random->next; //This works because every copied node is immediately after the original node, so temp->random->next is the copied node.
            }else{
                copyNode->random=NULL;
            }
            temp=temp->next->next;
        }
    }

    Node* getDeepCopyList(Node* head){
        Node* temp=head;
        Node* dummyNode=new Node(-1);
        Node* res=dummyNode;

        while(temp!=NULL){
            //creating new list
            res->next=temp->next;
            res=res->next;

            //disconnectiing and going back to initial state of LL
            temp->next=temp->next->next;
            temp=temp->next;
        }
        return dummyNode->next;
    }

    Node* copyRandomList(Node* head) {
        insertCopyInBetween(head);
        connectRandomPointers(head);
        return getDeepCopyList(head);
    }
};