//Write a program to display n number of elements. Memory should be allocated  dynamically using calloc( ). 

#include<stdio.h>
#include<stdlib.h>

int *takeData(int n){
    
    int *arr = (int*) calloc(n , sizeof(int));
    printf("Enter the %d element(s):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

int showData(int *data, int n){
    for(int i=0;i<n;i++){
        printf("%d",data[i]);
    }
    return 0;
}

int main(){
    int n;
    printf("Enter no. of elements:\n");
    scanf("%d",&n);
    int *data = takeData(n);
    showData(data,n);
    return 0;
}