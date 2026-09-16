// LeetCode 148 - Sort List
// Approach: Merge Sort using Slow/Fast Pointers
// Time Complexity: O(n log n)
// Space Complexity: O(log n) due to recursion
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
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) {
            return head;
        }
        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast -> next != nullptr) {
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        prev -> next = nullptr;
        
        ListNode* left = head;
        ListNode* right = slow;
        left = sortList(left);
        right = sortList(right);

        ListNode* p1 = left;
        ListNode* p2 = right;

        ListNode* newhead = nullptr;
        ListNode* tail = nullptr;

        if(p1 -> val < p2 -> val) {
            newhead = p1;
            tail = p1;
            p1 = p1 -> next;
        }
        else {
            newhead = p2;
            tail = p2;
            p2 = p2 -> next;
        }
        while (p1 != nullptr && p2 != nullptr) {
            if(p1 -> val < p2 -> val) {
                tail -> next = p1;
                tail = p1;
                p1 = p1 -> next;
            }
            else {
                tail -> next = p2;
                tail = p2;
                p2 = p2 -> next;
            }
        }
        if(p1 == nullptr) {
            tail -> next = p2;
        }
        else {
            tail -> next = p1;
        }


        return newhead;
    }
};
