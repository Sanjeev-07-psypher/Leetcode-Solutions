class Solution {
public:
    int longestSubsequence(vector<int>& v) {
        int n=v.size();
        int ans=0;
        // int ans2=v[l];
        // for(int i=1;i<n;i++){
        //     ans2^=v[i];
        // }
        // if(ans2!=0){
        //     return n;
        // }
        for(int x : v){
            ans^=x;
        }
        if(ans!=0) return n;
        for(int r=0;r<n;r++){
            if(v[r]!=0){
                return n-1;
            }            
        }
        return 0;
    }
};