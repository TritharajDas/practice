#include <stdio.h>

int getData(int *a, int *b, int *c) {
    printf("Enter 3 numbers:\n");
    scanf("%d%d%d",a,b,c);
    return 0;
}

int findLargest(int x, int y, int z){
        //using if-else-if ladder
    // if (x>y && x>z) return x;
    // else if (x<y && y>z) return y;
    // else return z;

        //using nested ternary
    return (x>y)?((x>z)? x : z) :((y>z)? y : z);
}

int main() {
    int a, b, c, result;
    getData(&a, &b, &c);

    result = findLargest(a, b, c);
    printf("The largest number is %d",result);
    return 0;
}

