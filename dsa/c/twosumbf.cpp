#include <iostream>
#include <vector>

using namespace std;
//vector <int> twoSum(vector<int> &a, int &target){
//    int i,j;
//    int n = a.size();
//    for (i=0;i<n;i++){
//    for (j=i+1;i<n;j++){
//            if (a[i]+a[j] == target){
//                return {i+1,j+1};
//            }
//    }
//
//
//    }
//    return {};
//
//}


    int main(){

    vector <int> a = {1,4,5,8,3,6};
    int target = 9;
    vector <int> :: iterator iv;
    iv = a.end() -1;
    //vector<int> x = twoSum(a,target);
//    for(int &x : twoSum(a , target))
//        cout << x << " ";
//    cout << '\n';
    cout << *iv;

    return 0;
}
