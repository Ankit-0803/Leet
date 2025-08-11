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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Create a dummy node to simplify result list building
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy; // Pointer to build the list
        
        int carry = 0; // Carry for addition
        
        // Loop while there is a node in l1 or l2 or carry is non-zero
        while (l1 || l2 || carry) {
            
            // Get current values from both lists (or 0 if list ended)
            int l1val = (l1 != nullptr) ? l1->val : 0;
            int l2val = (l2 != nullptr) ? l2->val : 0;
            
            // Calculate sum for this digit
            int sum = l1val + l2val + carry;
            
            // Update carry for next position
            carry = sum / 10;
            
            // Create new node with the current digit (sum % 10)
            temp->next = new ListNode(sum % 10);
            
            // Move temp pointer forward
            temp = temp->next;
            
            // Move l1 and l2 forward if they are not null
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        
        // Return the actual head of the result list
        return dummy->next;
    }
};
