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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head; // No change needed if empty list or only one element in range
        ListNode dummy(0); // Dummy node to simplify edge cases
        dummy.next = head;
        ListNode* prev = &dummy; // Node before the reversal segment
        for (int i = 0; i < left - 1; ++i) { // Move prev to the node before the 'left' position
            prev = prev->next;
        }
        ListNode* current = prev->next; // First node in the reversal segment
        for (int i = 0; i < right - left; ++i) { // Reverse nodes between left and right
            ListNode* next_node = current->next; // Node to be moved to the front
            current->next = next_node->next; // Remove next_node from its current position
            next_node->next = prev->next; // Insert next_node right after prev
            prev->next = next_node; // Update prev->next to the moved node
        }
        return dummy.next; // Return new head
    }
};
