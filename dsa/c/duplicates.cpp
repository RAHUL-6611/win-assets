#include <iostream>
#include <vector>
using namespace std;

void duplicateZeros(vector<int>& arr) {
        int no_of_zeroes = 0; // count total no of zeroes
        for(int i=0;i<arr.size();i++){ // counting no of zeroes
            if(arr[i]==0) no_of_zeroes++;
        }
        for(int i=arr.size()-1;i>=0;i--){   // traverse array and update it
            if(arr[i]!=0 && i+no_of_zeroes<arr.size()){ // if arr[i] != 0 && new index < arr.size() then update new index
                arr[i+no_of_zeroes] = arr[i];
            }
            if(arr[i]==0) {  // else if arr[i] == 0
                if(i+no_of_zeroes<arr.size()){ // update new index and also new - 1 index because we have to insert new 0
                    arr[i+no_of_zeroes] = arr[i];
                    arr[i+no_of_zeroes-1] = arr[i];
                }
                else if(i+no_of_zeroes==arr.size())  arr[i+no_of_zeroes-1] = arr[i]; // corner cases if new index is == arr.size() then we have to only update new-1 index to 0
                no_of_zeroes--; // decrease no of zeroes
            }
        }

    }

int main(){
    vector<int> arr = {1,2,3,4,0,0,0,0,5};
//    for (auto i = arr.begin(); i != arr.end(); ++i)
//        cout << *i << " ";
        duplicateZeros(arr);
      for (int &x: arr){
        cout << x;
      }

return 0;
}
