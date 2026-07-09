class Solution {
public:
    int maxValidPairSum(vector<int>& v, int k) {
        int n=v.size();
        long long mx=v[0];
        int l=0;
        long long ans;
        for(int r=l+k;r<n;r++){
            mx=max(mx,(long long)v[l]);
            ans=max(ans,(long long)v[r]+mx);
            l++;
        }
        return (int)ans;
    }
};