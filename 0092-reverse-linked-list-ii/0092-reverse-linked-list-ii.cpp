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
        ListNode* prev=nullptr;
        ListNode* temp=head;
        while(temp!=nullptr){
            ListNode* fwd=temp->next; //save next node
            temp->next=prev; //exchange links
            prev=temp;
            temp=fwd;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head||left==right)return head;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* prev = &dummy;


        for(int i=0; i<left-1; i++){
            prev=prev->next;
        }
        ListNode* reverseHead=prev->next;
        ListNode* reverseTail=reverseHead;
        for(int i=0; i<right-left; i++){
            reverseTail=reverseTail->next;
        }
        ListNode* nextNode= reverseTail->next;
        reverseTail->next=nullptr;
        prev->next=reverse(reverseHead);
        reverseHead->next=nextNode;
        return dummy.next;

    }
  
};