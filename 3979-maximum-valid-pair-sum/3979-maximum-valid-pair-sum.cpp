class Solution {
public:
    int maxValidPairSum(vector<int>& v, int k) {
        int n=v.size();
        long long ans=0;
        long long mx=v[0];
        for(int j=k;j<n;j++){
            mx=max(mx,(long long)v[j-k]);
            ans=max(ans,(long long)mx+v[j]);
        }
        return (int)ans;
    }
};