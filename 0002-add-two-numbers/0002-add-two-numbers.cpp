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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy= new ListNode(-1);
        ListNode* temp=dummy;
        int carry=0;
        int sum=0;
        while(l1 || l2 || carry){
            int l1val=(l1!=nullptr)?l1->val:0;
            int l2val=(l2!=nullptr)?l2->val:0;
            int sum=l1val+l2val+carry;
            carry=sum/10;
            temp->next=new ListNode(sum%10);
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
            temp=temp->next;

        }
        return dummy->next;

        
    }
};