#include <stack>

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
        stack<ListNode*> s;
        ListNode* ptr = head;
        while (ptr) {
            s.push(ptr);
            ptr = ptr->next;
        }
        if (!s.empty()) {
            head = s.top();
            s.pop();
        }
        ListNode* prev = head;
        while (!s.empty()) {
            ptr = s.top();
            s.pop();
            prev->next = ptr;
            prev = ptr;
        }
        if (prev) {
            prev->next = nullptr;
        }

        return head;
    }
};
