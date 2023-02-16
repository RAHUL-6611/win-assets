#include <stdio.h>

int swap(int* a,int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void print(int arr[],int n){
    for (int i=0; i<n;i++){
        printf("%d",arr[i]);
    }
}

void bubblesort(int arr[],int n){
    int i,j;
    for (i=0;i<=n-1;i++){

        for (j=0;j<=n-i-1;j++){
            if (arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }

}

void selectionsort(int arr[],int n){
    int i,j,min_ind;
    for ( i=0;i<n-1;i++){
        min_ind=i;

        for (j=i+1;j<n;j++){
            if (arr[j]< arr[min_ind]){
                min_ind = j;
                //arr[min_ind] = arr[j];
            }
        }
            swap(&arr[min_ind],&arr[i]);
    }

}

void insertionsort( int arr[], int n){
    int i,j,key;

    for (i=1;i<n;i++){
        key = arr[i];
        j = i-1;

        while (j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]= key;
    }

}

int main(){
    int arr[20],n;

    printf("Enter n");
    scanf("%d",&n);
    printf("\nEnter the elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    //bubblesort(arr,n);
    //selectionsort(arr,n);
    insertionsort(arr,n);
    print(arr,n);
    return 0;


}
