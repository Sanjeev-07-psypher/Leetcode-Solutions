class Solution{
public:
    int stoneGameV(vector<int>&a){
        int n=a.size();
        vector<int>p(n+1);

        for(int i=0;i<n;i++) p[i+1]=p[i]+a[i];
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i=1;i<n;i++){ 

            for(int j=0;j+i<n;j++){
                int r=j+i;

                for(int k=j;k<r;k++){

                    int x=p[k+1]-p[j];
                    int y=p[r+1]-p[k+1];

                    if(x<y) 
                        dp[j][r]=max(dp[j][r],x+dp[j][k]);
                    else if(x>y)
                        dp[j][r]=max(dp[j][r],y+dp[k+1][r]);
                    else dp[j][r]=max(dp[j][r],x+max(dp[j][k],dp[k+1][r]));
                }
            }
        }
        return dp[0][n-1];
    }
};