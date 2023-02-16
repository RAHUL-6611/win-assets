#include <stdio.h>
#include <stdlib.h>

int cost[10][10], i,j,a,b,u,v,ne=1,n,min,mincost=0,visited[100];

int main()
{


    printf("Enter the value for n: ");
    scanf("%d", &n);

    printf("Enter the cost of adjecency matrix: \n");

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0) cost[i][j]=999;
        }
    }

    printf("the edges of minimum cost spanning tree!!\n");
    visited[1]=1;
    while(ne < n)
    {

        for(i=1,min=999; i<=n; i++)
        {
            for(j=1; j <= n; j++)
            {
                if(cost[i][j] < min)
                {
                    if(visited!=0)
                    {
                        min=cost[i][j];
                        a=u=i;
                        b=v=j;

                    }

                }

            }
        }

                if(visited[u]==0 || visited[v]==0)
                {
                    printf("%d cost(%d %d) =%d", ne++, a,b,min);
                    mincost+=min;
                    visited[b]=1;
                }
                cost[a][b]=cost[b][a]=9999;
    }



    printf("mincost=%d", mincost);

}
