class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int initialZeros=0;
        int mx=0;
        int prev=0;
        int n=s.size();
        int i=0;
        while(i<n){
            int j=i;
            while(j<n && s[i]==s[j]){
                j++;
            }
            int len=j-i;
            if(s[i]=='1'){
                initialZeros+=len;

            } else {
                if(prev>0)mx=max(mx,prev+len);
                prev=len;
            }
            i=j;
        }
        return initialZeros+mx;
    }
};