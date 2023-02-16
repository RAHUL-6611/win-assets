#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Job {
    char id;
    int dead;
    int profit;

} Job ;

int min(int a,int b){
    return a>b ? b:a;
}

void qqsort(Job arr[],int n){

    int i,j,temp;
    char temp2;
    for (i=0;i<n;i++){
        for (j=i+1;j<=n;j++)
        {
            if (arr[j].profit > arr[i].profit)
            {
                temp = arr[j].profit;
                arr[j].profit = arr[i].profit;
                arr[i].profit = temp;

                temp = arr[j].dead;
                arr[j].dead = arr[i].dead;
                arr[i].dead = temp;

                 temp2= arr[j].id;
                arr[j].id = arr[i].id;
                arr[i].id = temp2;
            }

        }
    }
}

void printJobScheduling(Job arr[],int n){

    qqsort(arr,n);
    for (int i=0;i<n;i++)
      printf("%c\t",arr[i].id);
      bool slot[n];
      int res[n];

      for (int i=0;i<n;i++){
            slot[i]= false;
            printf("%d ",slot[i]);
      }

    for (int i=0;i<n;i++){
      for (int j = min(n, arr[i].dead)-1; j>=0; j--){
            if (slot[j] == false){
                res[j] = i;
                slot[j] = true;
                break;
            }
      }
}

      for (int i=0;i<n;i++){
        if (slot[i]){
            printf("%c ",arr[res[i]].id);
      }
      }
}

int main(){
  Job arr[] = { { 'a', 2, 100 },
				{ 'b', 1, 19 },
				{ 'c', 2, 27 },
				{ 'd', 1, 25 },
				{ 'e', 3, 15 } };

   int n = sizeof(arr)/sizeof(arr[0]);

				printJobScheduling(arr,n);
				return 0;
}
