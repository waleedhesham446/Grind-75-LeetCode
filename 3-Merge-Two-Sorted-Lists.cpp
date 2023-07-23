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
        ListNode *merged_head = nullptr;
        ListNode *merged_iterator = nullptr;

        ListNode* new_node = nullptr;
        if (list1 && list2 && list1->val < list2->val) {
            new_node = new ListNode(list1->val);
            list1 = list1->next;
        } else if (list1 && list2 && list1->val >= list2->val) {
            new_node = new ListNode(list2->val);
            list2 = list2->next;
        } else if (list1) {
            new_node = new ListNode(list1->val);
            list1 = list1->next;
        } else if (list2) {
            new_node = new ListNode(list2->val);
            list2 = list2->next;
        }
        merged_head = new_node;
        merged_iterator = merged_head;
        
        while(list1 && list2) {
            new_node = nullptr;
            if (list1->val < list2->val) {
                new_node = new ListNode(list1->val);
                list1 = list1->next;
            } else {
                new_node = new ListNode(list2->val);
                list2 = list2->next;
            }
            merged_iterator->next = new_node;
            merged_iterator = merged_iterator->next;
        }

        while(list1) {
            new_node = new ListNode(list1->val);
            list1 = list1->next;
            
            merged_iterator->next = new_node;
            merged_iterator = merged_iterator->next;
        }

        while(list2) {
            new_node = new ListNode(list2->val);
            list2 = list2->next;
            
            merged_iterator->next = new_node;
            merged_iterator = merged_iterator->next;
        }

        return merged_head;
    }
};
