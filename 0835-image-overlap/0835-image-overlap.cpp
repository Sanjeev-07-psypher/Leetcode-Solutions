class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1,vector<vector<int>>& img2) {
        int n=img1.size();
        int ans=0;

        for(int x=-(n-1);x<n;x++){
            for(int y=-(n-1);y<n;y++){
                int count=0;

                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        int ni=i+x;
                        int nj=j+y;

                        if(ni>=0&&ni<n&&nj>=0&&nj<n){
                            if(img1[i][j]==1&&img2[ni][nj]==1){
                                count++;
                            }
                        }
                    }
                }
                ans=max(ans,count);
            }
        }
        return ans;
    }
};