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
    ListNode* partition(ListNode* head, int x) {
        ListNode* slist = new ListNode(0); // stores nodes < x
        ListNode* blist = new ListNode(0); // stores nodes >= x
        ListNode* small = slist; // pointer for small list
        ListNode* big = blist;   // pointer for big list
        while (head != nullptr) {
            if (head->val < x) {
                small->next = head; // append to small list
                small = small->next;
            } else {
                big->next = head; // append to big list
                big = big->next;
            }
            head = head->next; // move forward
        }
        small->next = blist->next; // connect small list to big list
        big->next = nullptr; // terminate big list
        ListNode* result = slist->next; // head of merged list
        delete slist; // free dummy
        delete blist; // free dummy
        return result;
    }
};
