class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& v) {
        int n=v.size();
        if(n==0){
            return {};
        }
        vector<pair<int,int>> p;
        for(int i=0;i<n;i++){
            p.push_back({v[i],i});
        }
        sort(p.begin(),p.end());
        vector<pair<int,int>> p2(n);
        int rank=1;
        p2[0].first=p[0].second;
        p2[0].second=rank;
        for(int i=1;i<n;i++){
            if(p[i].first>p[i-1].first){
                rank++;
            }
            p2[i].first=p[i].second;
            p2[i].second=rank;
        }
        sort(p2.begin(),p2.end());
        vector<int> ans;
        for(auto &x:p2){
            ans.push_back(x.second);
        }
        return ans;
    }
};