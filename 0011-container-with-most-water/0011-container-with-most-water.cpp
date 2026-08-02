class Solution {
public:
    int maxArea(vector<int>& v) {
        int n=v.size();
        int l=0,r=n-1;
        int ans=0;
        while(l<r){
            int mn=min(v[l],v[r]);
            int area=(r-l)*mn;
            ans=max(ans,area);
            if(v[l]<=v[r]){
                l++;
            } else {
                r--;
            }
        }
        return ans;
    }
};