class Solution {
public:
    int n;
    vector<vector<int>> dp;
    vector<int> suf;

    int rec(int i,int M){
        if(i>=n)return 0;
        if(dp[i][M]!=-1)return dp[i][M];

        int ans=0;
        for(int X=1;X<=2*M && i+X<=n;X++){
            ans=max(ans,suf[i]-rec(i+X,max(M,X)));
        }
        return dp[i][M]=ans;
    }

    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        dp.assign(n,vector<int>(n+1,-1));
        suf.resize(n+1,0);

        for(int i=n-1;i>=0;i--)
            suf[i]=suf[i+1]+piles[i];

        return rec(0,1);
    }
};