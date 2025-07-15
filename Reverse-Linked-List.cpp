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
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* prev=nullptr;
        ListNode* curr=head;

         while (curr != nullptr) {
            ListNode* next = curr->next; // Step 1: Store next node
            curr->next = prev;           // Step 2: Reverse current node's pointer
            prev = curr;                 // Step 3: Move prev forward
            curr = next;                 // Step 4: Move curr forward
        }

        return prev; // prev will be the new head
    }
};