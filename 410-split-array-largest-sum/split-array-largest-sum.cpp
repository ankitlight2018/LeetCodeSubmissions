class Solution {
public:

    bool isPossibleToKeepMaxSumUptoX(vector<int>& nums, int k, int x) {
        int currSum = 0, totalParts = 1;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]>x) {
                return false;
            }
            if((currSum+nums[i])<=x) {
                currSum+=nums[i];
            } else {
                totalParts++;
                if(totalParts>k) {
                    return false;
                }
                currSum = nums[i];
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int ans = INT_MAX;
        int low = 0, high = INT_MAX, mid;
        while(low<=high) {
            mid = (low + (high-low)/2);
            if(isPossibleToKeepMaxSumUptoX(nums,k,mid)) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return ans;
    }
};