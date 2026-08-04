class Solution {
public:
    bool canJump(vector<int>& v) {
        int n=v.size();
        int mx=0;
        for(int i=0;i<n;i++){
            if(i>mx) return false;
            mx=max(mx,i+v[i]);
        }
        return true;

    }
};