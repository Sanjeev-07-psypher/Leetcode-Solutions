class Solution {
public:
    int largestInteger(vector<int>& v, int k) {
        map<int,int> mp;
        int l=0;
        vector<bool> visited(52,false);
        int n=v.size();
        for(int i=k-1;i<n;i++){
            for(int j=l;j<=i;j++){
                if(!visited[v[j]]){
                    mp[v[j]]++;
                    visited[v[j]]=true;
                }
            }
            for(int i=0;i<visited.size();i++){
                visited[i]=false;
            }
            l++;
        }
        int ans=-1;
        for(auto &x: mp){
            if(x.second==1){
                ans=max(ans,x.first);
            }
        }
        return ans;
    }
};