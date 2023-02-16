#define N 4
#include <stdbool.h>
#include <stdio.h>

bool isSafe(int board[N][N],int col,int row){
    int i,j;
    //check left horizon of that row
    for(i=0;i<col;i++){
        if (board[row][i]){
            return false;
        }
    }

    //check left top diagonal
    for(i=row,j=col;i>=0 && j>=0;i--,j--){
        if (board[i][j]){
            return false;
        }
    }

    //check left bottom diagonal
    for(i=row,j=col;j>=0 && i<N; i++,j--){
        if (board[i][j]){
            return false;
        }
    }

    return true;
}

bool queen(int board[N][N], int col, int size){


    if (col >=N){
        return true;
        // all queen places or no queen places
    }

    for (int i=0;i<N;i++){

        if ( isSafe(board,col,i ))
        {
            //try with 1st col
            board[i][col] = 1;

            //now put in recursion
            if (queen(board,col+1,size)){
                return true;
            }
            //if this col didnt work, remove queen //backtracking
            board[i][col] = 0;
        }
    }

    return false;
    //no solutions
}

void print(int board[N][N],int row){
 for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}

int main(){
    //int N = 4;
    int board[N][N] = { { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 } };

     if (queen(board,0,N) == false){
        printf("no solutions");
        return 1;
        }

    print(board,N);


    return 0;
}
