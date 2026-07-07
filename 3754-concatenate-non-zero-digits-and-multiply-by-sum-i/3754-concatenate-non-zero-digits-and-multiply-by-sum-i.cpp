class Solution {
public:
    long long sum(int n){
        long long ans=0;
        while(n>0){
            long long rem=n%10;
            ans+=rem;
            n/=10;
        }
        return ans;
    }
    long long sumAndMultiply(int n) {
        if(n==0) return 0;
        string s=to_string(n);
        string t;
        for(int i=0;i<s.size();i++){
            if(s[i]!='0') t.push_back(s[i]);
        }
        long long ans = stoll(t);
        ans=ans*sum(n);
        return ans;
    }
};