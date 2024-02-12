class Solution {
public:

    bool isPossibleToMakeBouquetsOnDayX(vector<int>& bloomDay, int m, int k, int x) {
        int curr = 0, totalBouq = 0;
        for(int i=0;i<bloomDay.size();i++) {
            if(bloomDay[i]<=x) {
                curr++;
                if(curr==k) {
                    curr = 0;
                    totalBouq++;
                    if(totalBouq==m) {
                        return true;
                    }
                }
            } else {
                curr=0;
            }
        }
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int ans = -1;
        int low = 1, high = INT_MAX-1, mid;
        while(low<=high) {
            mid = low + (high-low)/2;
            if(isPossibleToMakeBouquetsOnDayX(bloomDay,m,k,mid)) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return ans;
    }
};