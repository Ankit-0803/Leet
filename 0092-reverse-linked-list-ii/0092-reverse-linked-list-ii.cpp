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
    ListNode* reverse(ListNode* head){
        while(head!=nullptr){
            ListNode* prev=nullptr;
            ListNode* forward=nullptr;
            ListNode* temp->next=forward; //store the node
            forward->next=temp //exchange the links
            prev=temp;
            temp=forward;
        }
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
             ListNode* prev=head;
             while(prev->next!=head)prev=prev->next;
             right=left;
             for(int i=left; i<right-left; i++){
                right++;
             }
             ListNode* nextnode=right->next;
             right->next=nullptr;
             ListNode* reverseHead = reverse(left);
             prev->next=reverseHead;
             head->next=nextn
             

    }
};