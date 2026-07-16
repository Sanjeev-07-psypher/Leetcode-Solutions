class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        int n=v.size();
        int l=0,r=n-1;
        vector<int> ans(2);
        while(l<r){
            if(v[l]+v[r]==target){
                ans[0]=l+1;
                ans[1]=r+1;
                break;
            } else if(v[l]+v[r]<target){
                l++;
            } else {
                r--;
            }
        }
        return ans;
    }
};