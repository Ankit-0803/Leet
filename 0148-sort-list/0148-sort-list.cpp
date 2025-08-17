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
    ListNode* sortList(ListNode* head) {
         // Base case: 0 or 1 node
        if (head == nullptr || head->next == nullptr)
            return head;
        //split in two halfes by finding the middle node
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=nullptr; //to keep track of the slow
        while(fast!=nullptr && fast->next!=nullptr){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=nullptr; //breaking the last
        //recursively sort the splitted list
        ListNode* left=sortList(head);
        ListNode* right=sortList(slow);
        //merge the sorted lists
         return merge(left, right);
    }
    private:
    // Helper function to merge two sorted linked lists
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        // Append remaining nodes
        tail->next = (l1 != nullptr) ? l1 : l2;
        return dummy.next;
    }
};