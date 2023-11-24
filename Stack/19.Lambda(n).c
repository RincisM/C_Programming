#include <stdio.h>
int lamb(int n) {
    if(n==0)
      return 1;
    return lamb(n/2)+1;
}
int main() {
    int a;
    printf("Enter a value: ");
    scanf("%d", &a);
    printf("Lambda(%d) is %d\n", a, lamb(a));
    return 0;
}