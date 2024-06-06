------------------->>>>>>>>>>>> Approach <<<<<<<<<<<<<<<<<<<<<----------------------

// Time Complexity - O(n)
// Space Complexity - O(n)


class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> mpp;

        for(int i=0;i<hand.size();i++){
            mpp[hand[i]]++;
        }

        for(auto x=mpp.begin(); x!=mpp.end(); ){
            if(x->second >0){
                for(int i=0; i<groupSize;i++){
                    if(mpp[x->first+i]>0){
                        mpp[x->first+i]--;
                    }
                    else{
                        return false;
                    }
                }
            }
            else{
                x++;
            }
        }
        return true;
    }
};