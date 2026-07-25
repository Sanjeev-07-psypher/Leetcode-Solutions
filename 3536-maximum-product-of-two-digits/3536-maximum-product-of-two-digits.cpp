class Solution {
public:
    int maxProduct(int n) {
        vector<int> v;
        
        while(n>0){
            int rem=n%10;
            v.push_back(rem);
            n/=10;
        }
        sort(v.rbegin(),v.rend());
        return v[0]*v[1];
    }
};