#include <stdio.h>
#include <conio.h>

int arr[100],min,max;

void minmax(int l,int h){

    int min1,max1,mid;

    if (l == h){
        min=max=arr[l];
    }
    else if (l == h-1){
        if (arr[l] > arr[h]){
            max = arr[l];
            min= arr[h];
        }
        else{
            min = arr[l];
            max= arr[h];
        }

    }
    else{
        mid = (l+h)/2;
        minmax(l,mid);
        max1= max;
        min1= min;
        minmax(mid+1,h);

        if (min > min1){
            min = min1;
        }
        if (max1 > max){
            max = max1;
        }
    }
}

int main(){
    int i,n;
    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    minmax(0,n-1);
    printf("max :%d",max);
    printf("min: %d",min);
    return 0;

}
