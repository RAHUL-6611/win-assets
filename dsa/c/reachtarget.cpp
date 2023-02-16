#include <iostream>
using namespace std;

int minMoves(int target, int maxDoubles) {
        if(target==1)   return 0;
        if(maxDoubles==0)
            return target-1;
        if(target%2)
            return minMoves(target-1, maxDoubles)+1;
        else
            return minMoves(target/2, maxDoubles-1)+1;
    }
int main(){
    int target= 19,maxDoubles=2;
    int res = minMoves(19,2);
    cout << res;

return 0;
}
