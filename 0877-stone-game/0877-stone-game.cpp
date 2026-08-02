class Solution {
public:
    int dp[501][501];

    int solve(vector<int>& nums, int i, int j) {
        if (i==j)return nums[i];
        if (dp[i][j]!=-1) return dp[i][j];

        int left=nums[i]-solve(nums,i+1,j);
        int right=nums[j]-solve(nums,i,j-1);
        return dp[i][j]=max(left,right);
    }

    bool stoneGame(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,nums.size()-1)>=0;
    }
};