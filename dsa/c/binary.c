#include <stdio.h>
#include <string.h>

int binary(int arr[],int l ,int r,int x){
        int mid;
        if (l <= r){
                mid = (l+r)/2;

                if (mid == x){
                    return x;
                }
                else if (arr[mid]< x){
                    return binary(arr,mid+1,r,x);
                }
                else{
                    return binary(arr,l,mid-1,x);
                }
        }

}

int main(){
    int i,arr[100],x,size,res;

    printf("enter set size to search element: ");
    scanf("%d", &size);

    printf("enter set elements");

    for (int i=0; i<size; i++){
        scanf("%d",&arr[i]);
    }

    printf("element to search");
    scanf("%d",&x);

    //binary(arr,0,size-1,x);
    //or
    res = binary(arr,0,strlen(arr),x);
    printf("elem found at index %d",res);

    return 0;
}
