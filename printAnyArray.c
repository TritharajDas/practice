#include<stdio.h>
#include<stdlib.h>

int getData(int arr[]){
    printf("Enter an Array of 5\n");
    for(int i=0;i<5;i++){
        scanf("%d",&arr[i]);
    }
    return 0;
}

int showData(int arr[]){
    for(int i=0;i<5;i++){
        printf("%d ", arr[i]);
    }
    return 0;
}

int main(){
    int arr[5];
    getData(arr);
    showData(arr);
    return 0;
}