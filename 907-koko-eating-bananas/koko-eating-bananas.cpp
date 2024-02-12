class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = INT_MAX;
        int low=1, high=INT_MAX, mid;
        while(low<=high) {
            mid = low+(high-low)/2;
            int totalTime=0;
            for(int i=0;i<piles.size();i++) {
                totalTime += (piles[i]+mid-1)/mid;
            }
            if(totalTime>h) {
                low = mid+1;
            } else {
                ans = mid;
                high = mid-1;
            }
        }
        return ans;
    }
};