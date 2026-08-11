class Solution {
public:
    int missingInteger(vector<int>& v) {
        int n=v.size();
        int sum=v[0];
        for(int i=1;i<n;i++){
            if(v[i]==v[i-1]+1) sum+=v[i];
            else break;
        }
        set<int> s(v.begin(),v.end());
        while(s.count(sum)) sum++;
        return sum;
    }
};