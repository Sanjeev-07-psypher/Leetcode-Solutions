class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& v, int k) {
        int n=v.size();
        int m=v[0].size();
        k%=(n*m);
        if(k==0){
            return v;
        }
        int idx=0,jdx=0;
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                count++;
                if(count==k+1) {
                    idx=i;
                    jdx=j;
                    break;
                }
            }
        }
        vector<vector<int>> ans(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(jdx==m){
                    idx++;
                    jdx=0;
                }
                if(idx==n){
                    idx=0;
                }
                ans[idx][jdx]=v[i][j];
                jdx++;
            }
        }
        return ans;
    }
};