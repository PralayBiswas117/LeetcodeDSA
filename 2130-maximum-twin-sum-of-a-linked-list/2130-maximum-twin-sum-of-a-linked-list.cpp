class Solution {
public:

    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL) {
            ListNode* next = curr->next;

            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    int pairSum(ListNode* head) {

        // Find the beginning of the second half
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half
        ListNode* pntr1 = head;
        ListNode* pntr2 = reverse(slow);

        int maxi = 0;

        // Calculate maximum twin sum
        while(pntr2 != NULL) {
            maxi = max(maxi, pntr1->val + pntr2->val);

            pntr1 = pntr1->next;
            pntr2 = pntr2->next;
        }

        return maxi;
    }
};