#include<stdio.h>

int main(){
    int num, s=0, rem[10], originalnum, i=1, j, k, a=1, rev[10];
    printf("Enter a number :");
    scanf("%d", &num);
    originalnum = num;
    while (num > 0) {
        rem[i] = num % 10;
        num = num / 10;
        i++;
    }
    for(j=1, k=i-1; j<=i-1 && k>=1 ;j++ , k--){
        rev[k] = rem[j];
    }
    for (int l=1; l<=i ; l++){
        if (rev[l]!=rem[l]){
            a = 0;
            break;
        }
    }
    if (a == 1) {
        printf("The number is a palindrome.");
    } else {
        printf("The number is not a palindrome.");
    }
    return 0;
}