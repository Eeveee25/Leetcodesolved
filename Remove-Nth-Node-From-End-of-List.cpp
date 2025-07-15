class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        // Move fast pointer n steps ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Move both pointers until fast reaches the end
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Now slow is just before the node to delete
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete;

        return dummy.next;
    }
};
