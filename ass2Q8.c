//Write a program to allocate memory using malloc ( )
//and then reallocate the previously  allocated memory using realloc( ).
//Display the elements which have been taken after  reallocation

#include<stdio.h>
#include<stdlib.h>

int reData(int *data, int n){
    // Reallocation of memory
    int m;
    printf("\nEnter the additional number of elements to reallocate: ");
    scanf("%d", &m);
    data = (int*)realloc(data, (n + m) * sizeof(int));
    if (data == NULL) {
        printf("Memory reallocation failed\n");
        return 1;
    }

    // Input additional elements after reallocation
    printf("\nEnter %d additional elements:\n", m);
    for (int i = n; i < n + m; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &data[i]);
    }

    // Display all elements in the reallocated array
    printf("\nThe elements in the array are:\n");
    for (int i = 0; i < n + m; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    free(data);
}

int *takeData(int n){
    
    int *arr = (int*) malloc(n*sizeof(int));
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
    reData(data,n);
    return 0;
}