class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        vector<int> freq(26,0);
        int l=0;
        int ans=2;
        for(int r=0;r<n;r++){
            freq[s[r]-'a']++;
            if(freq[s[r]-'a']>2){
                while(freq[s[r]-'a']>2){
                    freq[s[l]-'a']--;
                    l++;
                }
                
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};