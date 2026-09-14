// LeetCode 21 - Merge Two Sorted Lists
// Approach: Two Pointers / Iterative Merge
// Time Complexity: O(n + m)
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) {
            return list2;
        }
        if(list2 == nullptr) {
            return list1;
        }
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        
        ListNode* p1 = list1;
        ListNode* p2 = list2;

        if(p1 -> val < p2 -> val) {
            head = p1;
            tail = p1;
            p1 = p1 -> next;
        }
        else {
            head = p2;
            tail = p2;
            p2 = p2 -> next;
        }

       while(p1 != nullptr && p2 != nullptr) {
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
        return head;
    }
};
