
//Write a C program to pass an array to a function using Call by Value, update the array
//values in the function, print the array elements both in the function and in the calling
//function.

#include<stdio.h>

int update(int arr[]){
    int u,v;
    printf("Which index do you want to update?\n");
    scanf("%d",&u);
    printf("What is the updated value?\n");
    scanf("%d",&v);
    arr[u]=v;
    for(int i=0;i<5;i++)
    printf("%d",arr[i]);
    return 0;
}

int takeData(int arr[]){
    int i,j;
    printf("Enter a string of 5 charecters:\n");
    for(int i=0;i<5;i++){
        scanf("\n%d",&arr[i]);
    }   
    return 0;
}

int main(){
    int arr[100];
    takeData(arr);
    update(arr);
    for(int i=0;i<5;i++)
    printf("%d",arr[i]);
}