class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& arr, int freeStart, int freeEnd) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> merged;
        for(auto &x : arr){
            int l = x[0];
            int r = x[1];
            if(merged.empty() || l > merged.back()[1] + 1){
                merged.push_back({l,r});
            }else{
                merged.back()[1] = max(merged.back()[1], r);
            }
        }
        vector<vector<int>> ans;
        for(auto &x : merged){
            int l = x[0];
            int r = x[1];
            if(r < freeStart || l > freeEnd){
                ans.push_back({l,r});
                continue;
            }
            if(l < freeStart){
                ans.push_back({l, freeStart - 1});
            }
            if(r > freeEnd){
                ans.push_back({freeEnd + 1, r});
            }
        }
        return ans;
    }
};