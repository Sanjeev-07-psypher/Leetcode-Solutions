class Solution {
public:
    vector<vector<int>> up;
    vector<int> farReach;

    void buildLifting(int n){
        int LOG=18;
        up.assign(LOG,vector<int>(n));

        for(int i=0;i<n;i++) up[0][i]=farReach[i];

        for(int k=1;k<LOG;k++){
            for(int i=0;i<n;i++){
                up[k][i]=up[k-1][up[k-1][i]];
            }
        }
    }

    int getDistance(int l,int r){
        if(l==r) return 0;

        int ans=0;

        for(int k=17;k>=0;k--){
            if(up[k][l]<r){
                l=up[k][l];
                ans+=(1<<k);
            }
        }

        return ans+1;
    }

    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> v;

        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }

        sort(v.begin(),v.end());

        vector<int> pos(n);
        vector<int> comp(n);

        for(int i=0;i<n;i++){
            pos[v[i].second]=i;
        }

        int id=0;
        comp[0]=0;

        for(int i=1;i<n;i++){
            if(v[i].first-v[i-1].first>maxDiff) id++;
            comp[i]=id;
        }

        farReach.assign(n,0);

        int r=0;

        for(int l=0;l<n;l++){
            while(r+1<n && v[r+1].first-v[l].first<=maxDiff){
                r++;
            }
            farReach[l]=r;
        }

        buildLifting(n);

        vector<int> ans;

        for(auto &q:queries){
            int u=pos[q[0]];
            int vv=pos[q[1]];

            if(u>vv) swap(u,vv);

            if(comp[u]!=comp[vv]){
                ans.push_back(-1);
            }
            else{
                ans.push_back(getDistance(u,vv));
            }
        }

        return ans;
    }
};