
//Write a program that reads a 2D metrics and checks if the metrics is a symmetric metrics
//or not.

#include<stdio.h>


int takeData(int size, int mat[size][size]){

    printf("Enter the %dx%d matrics:\n",size,size);
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    return 0;
}


int isSymmetric(int s, int mat[s][s]){
    int flag = 1;
    for(int i=0;i<s;i++){
        for(int j=0;j<i;j++){
            if(mat[i][j] != mat[j][i]){
                flag = 0;
                break;
            }
        }
    }
    return flag;
}

int main(){

    int size, result;
    printf("Enter size of square matrics:\n");
    scanf("%d",&size);
    int matrics[size][size];
    takeData(size,matrics);
    result = isSymmetric(size,matrics);
    if(result == 0) printf("not symmectric\n");
    else printf("symmetric");
    return 0;
}


