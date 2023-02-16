#include <stdio.h>

int partition(int arr[],int lb,int ub){
    int temp;
    int fp =lb;
    lb++;

    while (lb <=ub && ub>=0){

        while (arr[lb]<arr[fp] && (lb <= ub))
            lb++;
        while (arr[ub]>arr[fp] && (ub>=0))
            ub--;
        if (lb < ub){
            temp = arr[ub];
            arr[ub]=arr[lb];
            arr[lb]=temp;
        }
        temp = arr[ub];
        arr[ub]= arr[fp];
        arr[fp] = temp;

    }

    return ub;

}

int quicksort(int arr[],int lb, int ub){
    int pivot;
    if (lb < ub){
        pivot = partition(arr,lb,ub);
        quicksort(arr,lb,pivot-1);
        quicksort(arr,pivot+1,ub);
    }

}

int main(){

    int i, count, arr[25];
    printf("Number of Elements: ");
    scanf("%d",&count);

    printf("Enter %d elements: ", count);
    for(i=0;i<count;i++)
      scanf("%d",&arr[i]);

      quicksort(arr,0,count-1);
      printf("Order of Sorted elements: ");
    for(i=0;i<count;i++)
      printf(" %d",arr[i]);

    return 0;
}
