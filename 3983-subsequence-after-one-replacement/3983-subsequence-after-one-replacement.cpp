class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n=s.size(),m=t.size();
        vector<int> left(n,-1),right(n,-1);
        int j=0;
        for(int i=0;i<n;i++){
            while(j<m && t[j]!=s[i])j++;
            if(j==m) break;
            left[i]=j++;
        }
        if(left[n-1]!=-1) return true;
        j=m-1;
        for(int i=n-1;i>=0;i--){
            while(j>=0 && t[j]!=s[i]) j--;
            if(j<0) break;
            right[i]=j--;
        }
        for(int i=0;i<n;i++){
            int l=(i==0? -1 : left[i-1]);
            int r=(i==n-1 ? m : right[i+1]);
            if((l!=-1||i==0) && (r!=-1||i==n-1)){
                if(l+1<r) return true;
            }
        }
        return false;
    }
};