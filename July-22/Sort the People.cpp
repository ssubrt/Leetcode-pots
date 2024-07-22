------------------>>>>>>>>>>>>>>>> Approach <<<<<<<<<<<<<<<<----------------------
// time complexity - O(NLogN)
// space complexity - O(N)


class Solution {
public:
   vector<std::string> sortPeople(vector<string>& names, vector<int>& heights) {
    int n = names.size();
    vector<pair<int,string>> people;

    // Creating pairs of height and names
    for (int i = 0; i < n; ++i) {
        people.push_back({heights[i], names[i]});
    }

    // Sorting the pairs in descending order of height
    sort(people.begin(), people.end(), [](pair<int,string>& a,pair<int,string>& b) {
        return a.first > b.first;
    });

    // Extracting the names from sorted pairs
    vector<string> sortedNames;
    for (const auto& person : people) {
        sortedNames.push_back(person.second);
    }

    return sortedNames;
    }
};