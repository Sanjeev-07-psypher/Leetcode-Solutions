class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& v, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> segments;
        if(n==1){
            segments.push_back({0,0});
        }
        else {
            int l=0,currl=0;
            for(int i=1;i<n;i++){
                if(v[i]-v[currl]<=maxDiff){
                    if(i==n-1){
                        segments.push_back({l,i});
                    }
                    currl=i;
                } else {
                    segments.push_back({l,currl});
                    l=i;
                    currl=i;
                    if(i==n-1){
                        segments.push_back({i,i});
                    }
                }
            }
        }
        vector<bool> ans(queries.size(),false);
        for(int i=0;i<queries.size();i++){
            int l=min(queries[i][0],queries[i][1]);
            int r=max(queries[i][0],queries[i][1]);

            auto it = upper_bound(segments.begin(),segments.end(),make_pair(l,INT_MAX));
            if(it==segments.begin()){
                ans[i]=false;
            } else {
                --it;
                ans[i]=it->second>=r;
            }
        }
        return ans;
    }
};