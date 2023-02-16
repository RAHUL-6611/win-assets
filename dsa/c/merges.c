#include <stdio.h>


 void merge(int arr[],int l,int r,int size)
{
        int low =l; int high=r; int k = l; int i;
        int sorted_array[20];

        while ((low<r) && (high<size+l)){
            if (arr[low]> arr[high] && high<size+l){
                sorted_array[k++] = arr[high++];
            }
            else{
                sorted_array[k++] = arr[low++];
            }
        }
        while(high<size+l)
            {
                sorted_array[k++] = arr[high++];
            }
        while(low<r){
            sorted_array[k++] = arr[low++];
        }
        for(i = l;i<l+size;i++){
            arr[i] = sorted_array[i];
        }

    }


 void mergesort(int arr[],int l,int r, int n){
            int m;
            if(l < r){
                 m = l + (r-l)/2;
                mergesort(arr,l,m,m-l+1); //sorting left
                mergesort(arr,m+1,r,r-m); //sorting right
                merge(arr,l,m+1,r-l+1);   //merging both side
            }
    }


    void printArray(int arr[],int size){
        for (int i=0; i<size;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
    }

    int main(){
              int size,arr[5],i;
            printf("Enter the size of array");
            scanf("%d", &size);
            printf("enter the elements");
            for(i=0;i<size;i++){
                scanf("%d",&arr[i]);
            }

            printArray(arr,size);
            mergesort(arr,0,size-1, size);
            printArray(arr,size);

            getch();
            return 0;
    }
