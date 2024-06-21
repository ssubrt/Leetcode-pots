-------------------------->>>>>>>>>>>>>>>>>>>> Approach <<<<<<<<<<<<<<<<<<<<<<<<<<------------------------------
// time complexity of the code is O(n).
// space complexity is O(1).


class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
         int n = customers.size();
    int alwaysSatisfied = 0;
    int potentialGain = 0;

    // Calculate the number of customers that are always satisfied
    for (int i = 0; i < n; ++i) {
        if (grumpy[i] == 0) {
            alwaysSatisfied += customers[i];
        }
    }

    // Calculate the potential gain in the first window of 'minutes' length
    for (int i = 0; i < minutes; ++i) {
        if (grumpy[i] == 1) {
            potentialGain += customers[i];
        }
    }

    int maxGain = potentialGain;

    // Use sliding window to find the maximum potential gain
    for (int i = minutes; i < n; ++i) {
        if (grumpy[i] == 1) {
            potentialGain += customers[i];
        }
        if (grumpy[i - minutes] == 1) {
            potentialGain -= customers[i - minutes];
        }
        maxGain = max(maxGain, potentialGain);
    }

    return alwaysSatisfied + maxGain;
    }
};