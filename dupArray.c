//check duplicate numbers in the array

#include<stdio.h>
#include<string.h>

int takeData(int arr1[],int n){
    printf("Enter an array of numbers:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr1[i]);
    }
    return 0;
}

int checkDuplicate(int arr1[],int n){
    printf("\nduplicate elements:\n");
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr1[i]==arr1[j]){
                printf("%d",arr1[j]);
            }
        }
    }
}

int main(){

    int n;
    printf("no. of lements:\n");
    scanf("%d",&n);

    int arr1[n];
    takeData(arr1,n);
    checkDuplicate(arr1,n);

    return 0;
}