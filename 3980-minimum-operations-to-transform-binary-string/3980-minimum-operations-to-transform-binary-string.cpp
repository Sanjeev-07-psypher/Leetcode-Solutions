class Solution {
public:
    int minOperations(string s1, string s2) {
        int n=s1.size();
        if(n==1 && s1.front()=='1' && s2.front()=='0') return -1;
        int ans=0;
        for(int i=0;i<n;i++){
            if(s1[i]=='0' && s2[i]=='1'){
                ans++;
                s1[i]='1';
            }
        }
        int i=0;
        while(i<n){
            int j=i;
            if(s1[i]==s2[i]){
                i++;
                continue;
            }
            while(j<n && s2[j]=='0'){
                j++;
            }
            int k=i;
            while(k<j){
                if(s1[k]=='0'){
                    k++;
                    continue;
                }
                int x=k;
                while(x<j && s1[x]=='1'){
                    x++;
                }
                ans+= (x-k)/2;
                if((x-k)&1){
                    ans+=2;
                }
                k=x;
            }
            i=j;
        }
        return ans;
    }
};