------------------------->>>>>>>>>>>>>>>>>>>> Approach <<<<<<<<<<<<<<<<<<<-----------------------------
//time complexity of this code is O(n log n)
// space complexity of this code is O(1)


class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
       sort(seats.begin(), seats.end());
       sort(students.begin(), students.end());
        int moves = 0;
        for( int i=0; i<seats.size(); i++)
            moves += abs(seats[i] - students[i]);
        
        return moves;
    }
};