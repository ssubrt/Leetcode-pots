--------------->>>>>>>>>>>>>>>> Approach <<<<<<<<<<<<<<<<<<<---------------------

// Time Complexity - O(N)
// Space Complexity - O(1)

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
    ListNode* mergeNodes(ListNode* head) {
        if(!head) return NULL;
       ListNode* temp = head;
        ListNode* curr = head->next;
        while (curr != NULL) {
            int sum = 0;
            // Traverse until the next zero node
            while (curr->val != 0) {
                sum += curr->val;
                curr = curr->next;
            }
            // Now curr points to a zero node, we need to move temp to this position
            temp->val = sum;  // Update the value of temp to the sum of the segment
            temp->next = curr->next;  // Skip the zero node
            temp = temp->next;  // Move temp to the next segment
            curr = curr->next;  // Move curr to the next segment
        }
        return head;
    }
};