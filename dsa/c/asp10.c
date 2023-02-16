#include <stdio.h>

int v,cost[10][10],A[10][10],i,j;
void init(){
    printf("Enter no. of vertices");
    scanf("%d",&v);

    printf("Enter values of cost adjacency matrix");
    //cost[0][0]= 0;
    for(i=0;i<v;i++){
        for(j=i+1;j<v;j++)
        {
            if(i==j){
                cost[i][j] = 0; continue;
            }
            printf("\ncost[%d][%d] : ",i,j);
            scanf("%d",&cost[i][j]);

            cost[j][i] =cost[i][j];
        }
    }
}

 int min(int i,int j)
{
	return i<=j?i:j;
}

void asp(){
    int i,j,k;

    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            A[i][j] = cost[i][j];
        }
    }

    for(k=0;k<v;k++)
        {
        for(i=0;i<v;i++)
        {
            for (j=0;j<v;j++)
            {
                   A[i][j] = min(A[i][j],A[i][k]+A[k][j]);
                }
        }
         printf("\nA%d",k);
         for(i=0;i<v;i++){
                printf("\n");
            for(j=0;j<v;j++){
                printf("%d",A[i][j]);
        }
        }
    }

}



int main(){
    init();
    asp();

    return 0;
}
