#include<stdio.h>
int main(){
    int i, n;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements to be entered : ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int maxElementPos = findMaxElement(a,n);
    //printf("\nThe maximum element position: %d", maxElementPos);
    int minElementPos = findMinElement(a,n);
    //printf("\nThe minimum element position: %d", minElementPos);
    swapMaxMinElement(a, maxElementPos, minElementPos);
    printf("\nThe array after swap is : ");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    return 0;
}
int findMaxElement(int a[],int n){
    int i, pos=0;
    int maxVal = a[0];
    for(i=0;i<n;i++){
        if(a[i]>maxVal){
            maxVal = a[i];
            pos=i;
        }
    }
    return pos;
}
int findMinElement(int a[],int n){
    int i, pos=0;
    int minVal = a[0];
    for(i=0;i<n;i++){
        if(a[i] < minVal){
            minVal = a[i];
            pos=i;
        }
    }
    return pos;
}
void swapMaxMinElement(int a[], int maxElementPos, int minElementPos){
    int temp;
    temp = a[maxElementPos];
    a[maxElementPos] = a[minElementPos];
    a[minElementPos] = temp;
}