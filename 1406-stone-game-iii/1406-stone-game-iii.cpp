class Solution {
public:
        int dp[50005];
        int solve(vector<int>& v, int i) {
            if (i>=v.size())return 0;
            if (dp[i]!=-1) return dp[i];
            int ans=-1e9;
            int x=0;
            for(int k=0;k<3 && i+k<v.size();k++){
                x+=v[i+k];
                ans=max(ans,x-solve(v,i+k+1));
            }
            return dp[i]=ans;
        }
    string stoneGameIII(vector<int>& stoneValue) {
        memset(dp,-1,sizeof(dp));
        int res=solve(stoneValue,0);
        if(res>0){
            return "Alice";
        }
        if(res<0){
            return "Bob";
        }
        return "Tie";
    }
};