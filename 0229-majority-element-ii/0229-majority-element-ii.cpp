class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
        int n=v.size();
        unordered_map<int,int> mp;
        for(auto &x:v){
            mp[x]++;
        }
        vector<int> ans;
        for(auto &x:mp){
            if(x.second>n/3){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};