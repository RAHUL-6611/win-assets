    #include <stdio.h>
    #include <conio.h>

    void swap(int *a, int *b){
        int swapper = *a;
        *a = *b;
        *b = swapper;
    }


    void selectionsort(int arr[],int n){
        int i,last,j,max;
        for (i=0; i<n;i++){
            last = n-i-1;
            max = i;
            for (j=0;j<=last;j++){
                if (arr[max]>arr[j]){
                    max = j;
                }
            }
                swap(&arr[max],&arr[last]);
        }

    }

    void printArray(int arr[],int n){
        for (int i=0; i<n;i++){
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

            selectionsort(arr,size);
            printArray(arr,size);

            getch();
            return 0;
    }
