#include<stdio.h>
int main() {

    int i, n, a[100], num, pos=0;

    printf("Enter the size of array : ");
    scanf("%d",&n);

    printf("Enter the elements of the array : ");
    for (i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }

    printf("Enter the element to be entered : ");
    scanf("%d",&num);

    for(i=0; i<n; i++){
        if(a[i]<num){
            pos++;
        }else{
            break;
        }
    }

    /*printf("%d should be entered at position %d",num,pos); */

    for(i=n-1;i>=pos;i--) {
        a[i+1] = a[i];
    }
	
    a[pos] = num;

    printf("\nThe new array is : ");
    for(i=0;i<=n;i++) {
        printf("%d ", a[i]);
    }

    return 0;
}