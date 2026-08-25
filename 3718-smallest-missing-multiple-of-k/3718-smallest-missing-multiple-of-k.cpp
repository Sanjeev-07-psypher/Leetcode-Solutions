class Solution {
public:
    int missingMultiple(vector<int>& v, int k) {
        unordered_set<int> s(v.begin(),v.end());
        
        int ans=k;
        while(s.count(ans)){
            ans+=k;
        }
        
        return ans;
    }
};