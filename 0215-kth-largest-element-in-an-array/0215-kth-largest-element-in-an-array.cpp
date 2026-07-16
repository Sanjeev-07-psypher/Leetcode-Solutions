class Solution {
public:
    int findKthLargest(vector<int>& v, int k) {
        sort(v.rbegin(),v.rend());
        return v[k-1];
    }
};