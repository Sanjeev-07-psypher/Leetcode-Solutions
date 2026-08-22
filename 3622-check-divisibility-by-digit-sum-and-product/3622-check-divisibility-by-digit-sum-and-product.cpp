class Solution {
public:
    long long productOfdig(int n){
        n=(long long)n;
        long long p=1;
        while(n>0){
            long long rem=n%10;
            p*=rem;
            n/=10;
        }
        return p;
    }
    long long sumOfdig(int n){
        n=(long long)n;
        long long s=0;
        while(n>0){
            long long rem = n%10;
            s+=rem;
            n/=10;
        }
        return s;
    }
    bool checkDivisibility(int n) {
        long long sum = sumOfdig(n);
        long long product = productOfdig(n);
        if((long long)n%(sum+product)==0) return true;
        return false;
    }
};