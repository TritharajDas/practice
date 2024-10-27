//Write a program to store marks for n numbers of students in an array and print their marks.

#include<stdio.h>

int takeData(int arr[], int n){

    for(int i=0;i<n;i++){
        printf("Enter the narks for student number %d: ",i);
        scanf("%d",&arr[i]);
    }
    return 0;
}

void showData(int arr[], int n){
    for(int i=0;i<n;i++){
        printf("Marks of Student number %d is: %d\n",i,arr[i]);
    }
}

int main(){

    int n;
    printf("Enter the number of students:\n");
    scanf("%d",&n);
    int arr[n];

    takeData(arr,n);
    showData(arr,n);
    return 0;
}