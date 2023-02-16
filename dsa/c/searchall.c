#include <stdio.h>

int binarysearchr(int arr[],int low,int high,int x){
    int mid;
    if (low <= high){
        mid = (low+high)/2;

        if (arr[mid] == x){
            return mid;
        }
        if (arr[mid] > x){
            return binarysearchr(arr,low,mid-1,x);
        }

        return binarysearchr(arr,mid+1,high,x);

    }
    return -1;
}

int binarysearchi(int arr[],int low,int high,int x){
    //int mid;
    while(low <= high){
       int mid = low+(high-1)/2;

        if (arr[mid] == x){
            return mid;
        }
        if (arr[mid] > x){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return -1;
}



int main(){
    int arr[20],n,x,res;

    printf("Enter n");
    scanf("%d",&n);
    printf("\nEnter the elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter element to search");
    scanf("%d",&x);

    res=binarysearchi(arr,0,n-1,x);
    printf("element found at index %d",res);
    //print(arr,0,n,);
    return 0;


}

