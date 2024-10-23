//reverse the string

#include<stdio.h>
#include<string.h>

int takeData(char arr[],int size){
    printf("Enter a string:\n");
    fgets(arr, size, stdin);
    arr[strcspn(arr, "\n")] = '\0';
    return 0;
}

int revString(char arr[]){
    int len = strlen(arr);
    char rarr[len + 1];
    for(int i=0; i<len; i++){
        rarr[i] = arr[len-1-i];
    }
    rarr[len]='\0';
    printf("%s",rarr);
}

int main(){
    char arr[100];
    takeData(arr,sizeof (arr));
    revString(arr);

    return 0;
}