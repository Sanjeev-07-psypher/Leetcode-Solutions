class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        map<char,int> mp;
        for(auto c:s){
            mp[c]++;
        }
        char c;
        bool flag=false;
        for(auto x:mp){
            if(x.second&1){
                c=x.first;
                flag=true;
                break;
            }
        }
        string ans;
        for(auto &x: mp){
            int count=x.second/2;
            x.second/=2;
            for(int i=0;i<count;i++){
                ans.push_back(x.first);
            }
        }
        if(flag){
            ans.push_back(c);
        }
        for(auto it=mp.rbegin();it!=mp.rend();it++){
            if(it->second!=0){
                for(int i=0;i<it->second;i++)
                    ans.push_back(it->first);
            }
        }
        return ans;
    }
};