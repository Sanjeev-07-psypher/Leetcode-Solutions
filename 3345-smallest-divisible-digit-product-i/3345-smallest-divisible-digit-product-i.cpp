class Solution {
public:
    int smallestNumber(int n, int t) {
        int x=n;
        while(true){
            int product=1;
            x=n;
            while(x){
                int rem=x%10;
                product*=rem;
                x/=10;
            }
            if(product%t==0){
                break;
            }
            n++;
        }
        return n;
    }
};