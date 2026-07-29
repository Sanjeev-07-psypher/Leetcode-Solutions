class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(),v.end(),[](const vector<int> &a,const vector<int> &b){
            return a[0]<b[0];
        });
        int l=v[0][0];
        int r=v[0][1];
        vector<vector<int>> ans;
        for(int i=1;i<v.size();++i){
            if(v[i][0]<=r){
                r=max(r,v[i][1]);
            }
            else {
                ans.push_back({l,r});
                l=v[i][0];
                r=v[i][1];
            }
        }
        ans.push_back({l,r});
        return ans;
    }
};