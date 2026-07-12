class Solution {
public:
    int maxDistance(string s) {
        int x=0,y=0,underscore=0;
        for(auto &c: s){
            if(c=='L') x=x-1;
            else if(c=='R') x=x+1;
            else if(c=='U') y=y+1;
            else if(c=='D') y=y-1;
            else underscore++;
        }
        if(underscore&1){
            if(x<0){
                x=x-1;
            } else {
                x++;
            }
        } 
        if(x<0){
            x=x-underscore/2;
        } else {
            x=x+underscore/2;
        }
        if(y<0){
            y=y-underscore/2;
        }
        else {
            y=y+underscore/2;
        }
        return abs(x)+abs(y);
    }
};