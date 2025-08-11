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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Step 1: Create a dummy node for easy handling of the head
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy; // Pointer to build the result list
        
        // Step 2: Pointers for traversing both lists
        ListNode* t1 = list1;
        ListNode* t2 = list2;

        // Step 3: Compare nodes from both lists until one becomes empty
        while (t1 != nullptr && t2 != nullptr) {
            if (t1->val < t2->val) {
                temp->next = t1; // Link t1 node to merged list
                t1 = t1->next;   // Move t1 forward
            } else {
                temp->next = t2; // Link t2 node to merged list
                t2 = t2->next;   // Move t2 forward
            }
            temp = temp->next; // Move merged list pointer forward
        }

        // Step 4: Attach remaining nodes from the non-empty list
        if (t1 != nullptr) {
            temp->next = t1;
        } else {
            temp->next = t2;
        }

        // Step 5: Get actual head of merged list
        ListNode* result = dummy->next;
        delete dummy; // Free the dummy node memory

        return result;
    }
};
