#include <stdio.h>

int mat[10][10],v,visited[10],cost;

void init(){

    int i,j;
    printf("Enter no of cities : ");
    scanf("%d",&v);

    for(i=1;i<=v;i++){
            printf("\n");
        for(j=i;j<=v;j++){
            if (i==j){
                mat[i][j] = 0; continue;
            }
            printf("cost[%d][%d]",i,j);
            scanf("%d",&mat[i][j]);
            mat[j][i] = mat[i][j];
            }
    }
}

int tsp(int c){
    int i,min=99,temp,nc=99;
    for (i=1;i<=v;i++){
        if (mat[c][i]!=0 && visited[i] !=1){

            if (mat[c][i] < min){
                temp = mat[c][i];
                min = mat[c][i];
                nc = i;
            }
        }
    }
    if (nc != 99) cost += temp;
    return nc;
}

void mincost(int c){
    int nc;
    visited[c]=1;
    printf("%d >>",c);
     nc = tsp(c);

     if(nc == 99){
        printf("1");
        cost+= mat[c][1];
        return;
     }

     mincost(nc);
}

int main(){
    init();
    mincost(1);

    printf("cost : %d",cost);
}

