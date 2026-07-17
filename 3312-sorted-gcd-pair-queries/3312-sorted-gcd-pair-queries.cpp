class Solution {
public:
    using ll=long long;

    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx=*max_element(nums.begin(),nums.end());
        vector<ll> f(mx+1),cnt(mx+1),g(mx+1);

        for(int x:nums) f[x]++;

        for(int i=1;i<=mx;i++){
            for(int j=i;j<=mx;j+=i){
                cnt[i]+=f[j];
            }
        }
        for(int i=mx;i>=1;i--){
            g[i]=cnt[i]*(cnt[i]-1)/2;
            for(int j=i+i;j<=mx;j+=i){
                g[i]-=g[j];
            }
        }
        vector<ll> pre(mx+1);

        for(int i=1;i<=mx;i++){
            pre[i]=pre[i-1]+g[i];
        }
        vector<int> ans;
        for(ll q:queries){
            ans.push_back(lower_bound(pre.begin()+1,pre.end(),q+1)-pre.begin());
        }

        return ans;
    }
};