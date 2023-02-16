#include <stdio.h>

int main(){
int n,i,j,m;
    printf("enter no of rows: \n");
    scanf("%d",&n);
    m=n;
    for(i=0;i<=m;i++){
        for(j=n;j>=0;j--){
            printf("*");
        }
        --n;
        printf("\n");
    }

    return 0;
}
