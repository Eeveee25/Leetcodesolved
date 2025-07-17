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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroupTail = &dummy;
        ListNode* curr = head;

        while (true) {
            // Step 1: Check if there are at least k nodes left
            ListNode* check = curr;
            for (int i = 0; i < k; ++i) {
                if (!check) return dummy.next; // Fewer than k nodes remaining
                check = check->next;
            }

            // Step 2: Reverse k nodes
            ListNode* prev = nullptr;
            ListNode* tail = curr; // Will become the tail of the reversed segment
            for (int i = 0; i < k; ++i) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            // Step 3: Connect previous part with reversed group
            prevGroupTail->next = prev;
            tail->next = curr;
            prevGroupTail = tail;
        }

        return dummy.next;
    }
};
