#include<stdio.h>

int main(){
    int a;
    a = 5;

    int b;
    scanf("%d", &b);


    printf("\ninserted %d\n", b);


    int arr[5];
//    arr[0] = 0;
//    arr[1] = 1;
//    arr[2] = 2;
//    arr[3] = 3;
//    arr[4] = 4;

    /// initialize an array
    for (int i=0;i<5;i++){
        arr[i] = i;
    }

    /// print an array
    printf("\nThe array is\n");
    for (int i=0;i<5;i++){
        printf("%d\n", arr[i]);
    }




}
