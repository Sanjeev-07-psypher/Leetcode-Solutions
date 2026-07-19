class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.size();
        vector<int> lastOcc(26,0);
        vector<bool> vis(26,false);
        string ans;
        for(int i=0;i<n;i++){
            lastOcc[s[i]-'a']=i;
        }
        for(int i=0;i<n;i++){
            char c=s[i];
            if(vis[c-'a']) continue;

            while(!ans.empty() && ans.back()>c && lastOcc[ans.back()-'a']>i){
                vis[ans.back()-'a']=false;
                ans.pop_back();
            }
            ans.push_back(c);
            vis[c-'a']=true;
        }
        return ans;
    }
};