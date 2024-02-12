class Solution {
public:

    bool isPossibleToGiveXCandies(vector<int>& candies, long long k, int x) {
        long long sum = 0;
        for(int i=0;i<candies.size();i++) {
            sum += (candies[i]/x);
            if(sum>=k) {
                return true;
            }
        }
        return false;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int ans = 0;
        int low = 1, high = INT_MAX, mid;
        while(low<=high) {
            mid = low + (high-low)/2;
            if(isPossibleToGiveXCandies(candies, k, mid)) {
                ans = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        return ans;
    }
};