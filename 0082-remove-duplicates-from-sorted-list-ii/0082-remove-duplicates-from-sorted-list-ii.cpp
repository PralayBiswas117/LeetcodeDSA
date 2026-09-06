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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode();
        ListNode* iter = dummy;

        while (head) {
            bool duplicate = false;

            while (head->next && head->val == head->next->val) {
                head = head->next;
                duplicate = true;
            }

            if (!duplicate) {
                iter->next = head;
                iter = iter->next;
            }

            head = head->next;
        }

        iter->next = nullptr;
        return dummy->next;
    }
};