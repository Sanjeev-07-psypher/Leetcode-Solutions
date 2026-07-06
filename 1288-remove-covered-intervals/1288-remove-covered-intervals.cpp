class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& v) {
        int n=v.size();
        int cnt=0;
        vector<bool> marked(n,false);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(!marked[i]){
                    if(v[i][0]>=v[j][0] && v[i][1]<=v[j][1]){
                        cnt++;
                        marked[i]=true;
                    }
                }
                if(!marked[j]){
                    if(v[i][0]<=v[j][0] && v[i][1]>=v[j][1]){
                        cnt++;
                        marked[j]=true;
                    }
                }
            }
        }
        return n-cnt;
    }
};