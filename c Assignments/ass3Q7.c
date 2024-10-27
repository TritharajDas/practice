//Write a program to find the smallest and the largest elements in an array.


#include<stdio.h>


int check(int arr[], int n) {
    if (n <= 0) {
        printf("Array is empty.\n");
        return -1; 
    }
    
    int max = arr[0];
    int min = arr[0];
    
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)   max = arr[i];
        if (arr[i] < min)   min = arr[i];
    }
    
    printf("%d is the greatest value\n", max);
    printf("%d is the minimum value\n", min);

    return 0;
}

int takeData(int arr[],int n){

    printf("Enter the %d number of elements:\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    return 0;
}


int main(){
    int n;
    printf("Enter the number of elemts: ");
    scanf("%d",&n);
    int arr[n];
    takeData(arr,n);
    check(arr,n);
}