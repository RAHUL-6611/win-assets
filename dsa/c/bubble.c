    #include <stdio.h>
    #include <conio.h>


    void bubblesort(int arr[],int n){
    int i,j,temp;
    for (i=0;i<n-1;i++){
        for (j=0;j<n-1-i;j++){

            if (arr[j]> arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }

        }
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

            //int arr[20] = {12,2,131,44,69};
            bubblesort(arr,size);
            printArray(arr,size);

            getch();
            return 0;
    }
