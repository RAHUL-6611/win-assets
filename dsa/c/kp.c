#include <stdio.h>

void knapsack(int n,float p[],float w[],float c){
    float x[20],total_p=0;
    int i,u;
    u = c;
    for (i=0;i<n;i++){
        x[i]= 0.0;
    }
    for (i=0;i<n;i++){
            if (u > w[i]){
                total_p += p[i];
                u -= w[i];
                x[i] = 1.0;
            }
            else{
                break;
            }

    }
    if (i<n){
            x[i] = u/w[i];
    }
        total_p += x[i]*p[i];



    printf("profit : %f",total_p);

}

void sorting(float p[],float w[],float r[],int n){
    int i,j,temp;
    for (i=0;i<n;i++){
        for (j=i+1;j<n;j++){
            if (r[i]<r[j]){
                temp = p[i];
                p[i]=p[j];
                p[j]=temp;

                temp = r[i];
                r[i]=r[j];
                r[j]=temp;

                temp = w[i];
                w[i]=w[j];
                w[j]=temp;

            }
            printf("%d",p[i]);
        }
    }


}

void findRatio(float p[],float w[],float r[],int n){
    int i;
    for (i=0;i<n;i++){
        r[i] = p[i]/w[i];
    }
}

int main(){

    int n,i,j,temp;
    float p[50],w[50],r[50],c;

    printf("Enter capacity:");
    scanf("%f",&c);

    printf("Enter no of items:");
    scanf("%d",&n);

    for(i=0;i<n;i++){

        printf("Enter profit and weight for item : %d \n", i+1);
        scanf("%f %f",&p[i],&w[i]);

    }

    for (i=0;i<n;i++){
        r[i] = p[i]/w[i];
    }


    for (i=0;i<n;i++){
        for (j=i+1;j<n;j++){
            if (r[i]<r[j]){
                temp = p[i];
                p[i]=p[j];
                p[j]=temp;

                temp = r[i];
                r[i]=r[j];
                r[j]=temp;

                temp = w[i];
                w[i]=w[j];
                w[j]=temp;

            }
            printf("%f",p[i]);
        }
    }


    //findRatio(p,w,r,n);
    //orting(p,w,r,n);
    knapsack(n,p,w,c);

    return 0;

}
