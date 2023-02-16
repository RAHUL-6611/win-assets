#include <stdio.h>

void star1(int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<=i; j++){
            printf("* ");
        }
        printf("\n");
    }
}

void star2(int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<=n; j++){
            printf("* ");
        }
        printf("\n");
    }
}

void star3(int n){
    for (int i=0; i<n; i++){
        for (int j=n-i; j>0; j--){
        //for (int j=0; j<n-i; j++){
            printf("* ");
        }
        printf("\n");
    }
}

void star4(int n){
    for (int i=1; i<=n; i++){
        for (int j=1; j<=i; j++){
            printf("%d ",j);
        }
        printf("\n");
    }
}

void star5(int n){

    for (int i=0;i<2*n;i++){
        int total_rows = i > n ? 2 * n - i : i;
        for (int j=0;j<=total_rows;j++){
            printf("* ");
        }
        printf("\n");

    }
}


int main(){
    int n=14;

    star5(n);

    return 0;
}
