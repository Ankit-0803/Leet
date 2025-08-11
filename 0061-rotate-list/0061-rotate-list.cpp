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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head; // No rotation needed
        
        // Step 1: Find length and tail
        int len = 1; // Start with 1 because we are already at head
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            len++;
        }
        
        // Step 2: Make it circular
        tail->next = head;
        
        // Step 3: Find effective rotations
        k = k % len;
        int stepsToNewHead = len - k;
        
        // Step 4: Move to new tail (stepsToNewHead - 1 steps)
        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewHead; i++) {
            newTail = newTail->next;
        }
        
        // Step 5: Set new head and break the circle
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        
        return newHead;
    }
};
