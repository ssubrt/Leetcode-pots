-------------->>>>>>>>>>>>> Approach <<<<<<<<<<<<<<<<<<<<<<-----------------------


class Solution {
public:
    int minDifference(vector<int>& arr) {
         int n = arr.size();
    if (n <= 4) {
        return 0;  // If there are 4 or fewer elements, you can make all elements equal in 3 moves.
    }

    sort(arr.begin(), arr.end());

    // Calculate the minimum difference for the four scenarios
    int diff1 = arr[n-4] - arr[0];  // Remove three largest elements
    int diff2 = arr[n-1] - arr[3];  // Remove three smallest elements
    int diff3 = arr[n-3] - arr[1];  // Remove two largest elements and one smallest element
    int diff4 = arr[n-2] - arr[2];  // Remove two smallest elements and one largest element

    return min({diff1, diff2, diff3, diff4});
    }
};


------------>>>>>>>>>>>>>>> Approach -2 <<<<<<<<<<<<<<<<---------------------


class Solution {
public:
    int minDifference(vector<int>& arr) {
         int n = arr.size();
    if (n <= 4) {
        return 0;  // If there are 4 or fewer elements, you can make all elements equal in 3 moves.
    }

    std::sort(arr.begin(), arr.end());

    // We want to find the minimum difference in a window of size n - 3
    int min_diff = INT_MAX;
    for (int i = 0; i <= 3; ++i) {
        min_diff = std::min(min_diff, arr[n - 4 + i] - arr[i]);
    }

    return min_diff;
    }
};