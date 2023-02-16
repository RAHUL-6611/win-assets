#include <iostream>
using namespace std;


int main(){
        int n,steps=0;
        cout << "input n";
        cin >> n;


        while(n !=0){

        if (n%2 ==0 ){
            n = n/2;
            steps++;
        }
        if (n%2 != 0){
            n = n-1;
            steps++;
        }
        }
    cout << steps;
    return 0;
}
