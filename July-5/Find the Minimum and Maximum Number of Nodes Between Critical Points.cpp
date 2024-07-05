------------>>>>>>>>>>>>> Approach <<<<<<<<<<<<<<-------------------
//  time complexity of the code is O(n)
//  space complexity of the code is O(n)


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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head || !head->next || !head->next->next) return {-1,-1};

        vector<int>positions;
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* nextest = head->next->next;
        int position =1;

        while(nextest){
            if((curr->val > prev->val && curr->val > nextest->val) || 
            (curr->val < prev->val && curr->val < nextest->val)){
                positions.push_back(position);
            }
            prev = curr;
            curr = nextest;
            nextest = nextest->next;
            position++;
        }

        if(positions.size()<2) return {-1,-1};
         int minDistance = INT_MAX;
        for (int i = 1; i < positions.size(); ++i) {
            minDistance = min(minDistance, positions[i] - positions[i - 1]);
        }
        int maxDistance = positions.back() - positions.front();

        return {minDistance, maxDistance};
    }
};