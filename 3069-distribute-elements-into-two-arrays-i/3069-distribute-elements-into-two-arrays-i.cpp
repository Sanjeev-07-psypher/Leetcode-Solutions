class Solution {
public:
    vector<int> resultArray(vector<int>& v) {
        int n=v.size();
        vector<int> a,b;
        a.push_back(v[0]);
        b.push_back(v[1]);
        int ai=0,bi=0;
        for(int i=2;i<n;i++){
            if(a[ai]>=b[bi]){
                a.push_back(v[i]);
                ai++;
            } else {
                b.push_back(v[i]);
                bi++;
            }
        }
        for(int x:b){
            a.push_back(x);
        }
        return a;
    }
};