class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: Find length and connect tail to head (make it circular)
        int length = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            length++;
        }
        tail->next = head; // Make it circular

        // Step 2: Find new tail: (length - k % length - 1)th node
        k = k % length;
        int stepsToNewTail = length - k;
        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewTail; ++i) {
            newTail = newTail->next;
        }

        // Step 3: Break the circle and return new head
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};
