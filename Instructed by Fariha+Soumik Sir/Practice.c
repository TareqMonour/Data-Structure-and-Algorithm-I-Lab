#include<stdio.h>

int main(){
    /// Take the integer n as input from a user.

    int n;
    scanf("%d",&n);

    /// Then take n integers as input from the user
    /// and store those in an array.
    int numbers[n];
    for (int i=0;i<n;i++){
        scanf("%d",&numbers[i]);
    }

    /// Finally, print the array.
    for (int i=0;i<n;i++){
        printf("%d\n",numbers[i]);
    }


    /// Take an integer X
    int x;
    scanf("%d",&x);

    /// linear search
    int present = 0; /// 0 means not present
    for (int i=0;i<n;i++){
        if (numbers[i]==x){
            present = 1;
            break;
        }
    }

    if (present==1) {
        printf("present\n");
    } else {
        printf("not present");
    }

}
