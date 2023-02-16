#include <iostream>

using namespace std;

int max(int a,int b){
    return a>b?a:b;
}

//int maxSumOfArray(int arr[],int n){
//    int count=0,max=0;
//
//    for(int i=0; i<n;i++){
//        count = arr[i] + count;
//        if (count < 0){
//            count = 0;
//        }
//        if (max <count){
//            max = count;
//        }
//        }
//    return max;
//}

int maxSumOfArray(int arr[],int n){
    int count=0,max=0;
    int start=0,s=0,end=0;

    for(int i=0; i<n;i++){
        count = arr[i] + count;

        if (max <count){
            max = count;
            start = s;
            end = i;
        }
        if (count < 0){
            count = 0;
            s = i+1;

        }
        }
        cout <<"start"<<start;
        cout <<"end"<<end;

    return max;
}

//int maxSumOfArray(int arr[], int n){
//    int count=0,maxi=0;
//
//    for(int i=0; i<n;i++){
//        count = max(0,arr[i] + count);
//        maxi = max(maxi,count);
//    }
//    return maxi;
//}

//int maxSumOfArray(int arr[], int n){
//    int count=0, maxi=0;
//
//    for (int i=0; i<n;i++){
//    //if the number im adding gets reduced when im adding it to count means count was negative
//    if (arr[i] <= count + arr[i]){
//        count += arr[i];
//    }
//
//    if (maxi < count){
//        maxi=count;
//    }
//
//    }
//    return maxi;
//
//}

int main(){
    int arr[]={-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int r = maxSumOfArray(arr,n);
    cout << r;
    return 0;
}
