/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=nullptr;
        ListNode* temp=head;
        ListNode* forward;
        while(temp!=nullptr){
            forward=temp->next; //store the node
            temp->next=prev; //change the links
            prev=temp;
            temp=forward;
           
        }
        return prev;
    }
};