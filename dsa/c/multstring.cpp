#include <iostream>
using namespace std;

int main(){
    string a = "4321";
    char b = '8';
    int carry = 0;
    for (char av : a){
            a.push_back(av + '0');
//            cout << (b-'0')*(av-'0') + carry;
//            cout << endl;
//    cout << (av-'0')*(b-'0');
    }
    cout << a;
    return 0;
}
