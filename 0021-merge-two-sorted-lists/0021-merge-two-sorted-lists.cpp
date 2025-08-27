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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
         // Stack-allocated dummy node
        // ListNode dummy(-1);
        // ListNode* temp = &dummy;
        while(l1!=nullptr && l2!=nullptr){
            // int l1val=(l1!=nullptr)?l1->val:0;
            // int l2val=(l2!=nullptr)?l2->val:0;
            if(l1->val<l2->val){
                temp->next=l1;
                l1=l1->next;
            }
            else{
                temp->next=l2;
                l2=l2->next;
            }
            temp=temp->next;
        }
        if(l1!=nullptr)temp->next=l1;
        if(l2!=nullptr)temp->next=l2;
        ListNode* mergedHead = dummy->next;
        delete dummy;
        return mergedHead;
        //return dummy.next;
    }
};
// When you use a stack-allocated dummy node like ListNode dummy(-1);, the memory for dummy is automatically allocated on the stack and automatically deallocated when the function exits. This means you don’t have to manually delete it, and there’s no risk of memory leaks. Stack allocation is fast, safe, and ideal for temporary helper nodes whose lifetime is limited to the function scope.

// In contrast, when you use a heap-allocated dummy node like ListNode* dummy = new ListNode(-1);, the memory is allocated on the heap. This memory persists until you explicitly free it using delete. If you forget to delete it, even after returning the merged list, the dummy node remains in memory, causing a memory leak. Heap allocation is useful for objects that need to live beyond the function scope or are very large, but it requires careful manual management.

// In short, stack allocation is preferred for temporary dummy nodes in linked list operations because it is simpler, safer, and automatically managed, while heap allocation introduces the risk of leaks and requires explicit deletion.