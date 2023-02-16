    #include <stdio.h>
    #include <conio.h>


    int arr[] = {1,22,4,5,6,7,8,9};

    int sorted(int arr[],int index,int n){

    if (index == 7){
            printf("sorted");
            return 1;
        }
        return arr[index]<arr[index+1] && sorted(arr,index+1,n);
    }

    int main(){
      int res = sorted(arr,0,8);
       res == 0 && printf("not sorted");
        return 0;
    }
