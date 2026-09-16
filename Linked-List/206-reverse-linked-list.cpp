// LeetCode 206 - Reverse Linked List
// Approach: Iterative pointer reversal
// Time Complexity: O(n)
// Space Complexity: O(1)
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
    ListNode* reverseList(ListNode* head) {
        ListNode* current = head;
        ListNode* previous = nullptr;
        while(current != nullptr) {
            ListNode* nextnode = current -> next;
            current -> next = previous;
            previous = current;
            current = nextnode; 
        }
        head = previous;
        return head;
    }
};
