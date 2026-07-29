class Solution{
public:
    static const long long LIMIT=1000000;

    long long comb(long long n,long long r){
        if(r<0||r>n)return 0;
        r=min(r,n-r);

        __int128 res=1;
        for(long long i=1;i<=r;i++){
            res=res*(n-r+i)/i;
            if(res>LIMIT)return LIMIT+1;
        }

        return(long long)res;
    }

    long long count(vector<int>&freq){
        int total=0;
        for(int x:freq)total+=x;

        long long ways=1;

        for(int x:freq){
            if(x==0)continue;

            long long cur=comb(total,x);

            if(ways>LIMIT/cur)return LIMIT+1;
            ways*=cur;

            if(ways>LIMIT)return LIMIT+1;

            total-=x;
        }

        return ways;
    }

    string smallestPalindrome(string s,int k){
        vector<int> half(26,0);
        char mid=0;

        for(char c:s)half[c-'a']++;

        int len=0;
        for(int i=0;i<26;i++){
            if(half[i]&1)mid=char('a'+i);
            half[i]/=2;
            len+=half[i];
        }

        if(count(half)<k)return "";

        string left;

        for(int pos=0;pos<len;pos++){
            for(int c=0;c<26;c++){
                if(half[c]==0)continue;

                half[c]--;

                long long ways=count(half);

                if(ways>=k){
                    left.push_back(char('a'+c));
                    break;
                }

                k-=ways;
                half[c]++;
            }
        }

        string right=left;
        reverse(right.begin(),right.end());

        if(mid)return left+mid+right;
        return left+right;
    }
};