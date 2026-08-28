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

        // edge cases
        if (
            head == nullptr ||
            head->next == nullptr ||
            k == 1
        ) return head;


        // maintain start and end nodes
        ListNode *start = head, *end = head;

        // maintain start's and end's previous
        ListNode *start_prev = nullptr, *end_prev = nullptr;

        while (true) {

            // move end forward untill we get k nodes
            int cnt = 1;
            while (end != nullptr && cnt < k) {
                end_prev = end;
                end = end->next;
                cnt++;
            }

            // exit because we didnt find k nodes
            if (end == nullptr) break;

            // reverse all nodes between start and end
            // but dont reverse end yet
            ListNode* prev = start;
            for (auto i = start->next; i != end;) {
                auto nxt = i->next;
                i->next = prev;
                prev = i;
                i = nxt;
            }

            // start's previous will point to end
            if (start_prev != nullptr) {
                start_prev->next = end;
            } else {
                head = end;
            }

            // start's next will point to end's next
            start->next = end->next;

            // reverse end's direction
            end->next = end_prev;

            // go to the next nodes and repeat
            start_prev = start;
            start = start->next;
            end = start;
        }

        return head;
    }
};