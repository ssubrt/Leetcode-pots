--------------------->>>>>>>>>>>>>>>>>> Approch <<<<<<<<<<<<<<<<<<<-------------------

   // Time complexity:O(m⋅n+plogp)

    //Space complexity:O(n)


    class Solution {
public:
   
vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    // Step 1: Store frequencies of elements in arr1
    unordered_map<int, int> freqMap;
    for (int num : arr1) {
        freqMap[num]++;
    }

    // Step 2: Identify elements in arr1 not present in arr2
    vector<int> temp;
    for (int num : arr1) {
        if (find(arr2.begin(), arr2.end(), num) == arr2.end()) {
            temp.push_back(num);
        }
    }

    // Step 3: Create the output vector with elements in the order of arr2
    vector<int> result;
    for (int num : arr2) {
        while (freqMap[num] > 0) {
            result.push_back(num);
            freqMap[num]--;
        }
    }

    // Step 4: Append the elements from temp vector to the result and sort them
    sort(temp.begin(), temp.end());
    for (int num : temp) {
        result.push_back(num);
    }

    return result;
}
};


-------------------->>>>>>>>>>>>>>>>>>> Approach-2 <<<<<<<<<<<<<<<<<<<<<-----------------------

 //   Time complexity:O(m+nlogn)

    // Space complexity:O(m)

class Solution {
public:
   vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    // Step 1: Store the order of elements in arr2
    unordered_map<int, int> orderMap;
    for (int i = 0; i < arr2.size(); ++i) {
        orderMap[arr2[i]] = i;
    }

    // Step 2: Custom sort function
    auto comparator = [&orderMap](int a, int b) {
        // If both elements are in arr2
        if (orderMap.count(a) && orderMap.count(b)) {
            return orderMap[a] < orderMap[b];
        }
        // If only a is in arr2
        if (orderMap.count(a)) {
            return true;
        }
        // If only b is in arr2
        if (orderMap.count(b)) {
            return false;
        }
        // If neither is in arr2, sort by natural order
        return a < b;
    };

    // Step 3: Sort arr1 using the custom comparator
    sort(arr1.begin(), arr1.end(), comparator);

    return arr1;
}
};
