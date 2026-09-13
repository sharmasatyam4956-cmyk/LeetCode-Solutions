// LeetCode 141 - Linked List Cycle
// Approach: Floyd's Cycle Detection (Slow and Fast Pointers)
// Time Complexity: O(n)
// Space Complexity: O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast -> next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;

            if(slow == fast) {
                return true;
            }
        }
        return false;
    }
};
