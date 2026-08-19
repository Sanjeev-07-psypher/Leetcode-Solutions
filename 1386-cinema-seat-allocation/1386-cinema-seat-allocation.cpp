class Solution {
public:
    int maxNumberOfFamilies(int n,vector<vector<int>>& v) {
        unordered_map<int,int> m;
        m.reserve(v.size());

        for(auto x:v){
            int r=x[0]-1,s=x[1]-2;
            if(s<0||s>=8)continue;
            m[r]|=1<<s;
        }

        int ans=(n-m.size())*2;

        for(auto [r,x]:m){
            x=~x;

            bool a=(x&15)==15;
            bool b=(x&(15<<2))==(15<<2);
            bool c=(x&(15<<4))==(15<<4);

            if(a&&c)ans+=2;
            else if(a||b||c)ans++;
        }

        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();