#include <stdio.h>
#include <stdlib.h>

void Merge(int a[], int left, int mid, int right) {
    int i, j, k;
    int size1 = mid - left + 1;
    int size2 = right - mid;
    int Left[size1], Right[size2];
    for(i=0; i<size1; i++) {
        Left[i] = a[left+i];
    }
    for(j=0; j<size2; j++) {
        Right[j] = a[mid+j+1];
    }
    i=0, j=0, k= left;
    while(i<size1 && j<size2) {
        if(Left[i]<=Right[j]) {
            a[k] = Left[i];
            i++;
        }
        else{
            a[k] = Right[j];
            j++;
        }
        k++;
    }
    while(i<size1) {
        a[k] = Left[i];
        i++;
        k++;
    }
    while(j<size2) {
        a[k] = Right[j];
        j++;
        k++;
    }
}

void Merge_sort(int a[], int left, int right) {
    if(left<right) {
        int mid = left + (right-left)/2;
        printf("\nThe Divided Array (from index %d to %d) is: \n", left, right);
        for(int i=left; i<=right; i++) {
            printf("%d ", a[i]);
        }
        Merge_sort(a, left, mid);
        Merge_sort(a, mid+1, right);
        printf("\nThe Combined Array (from index %d to %d) is: \n", left, right);
        for(int i=left; i<=right; i++) {
            printf("%d ", a[i]);
        }
        Merge(a, left, mid, right);
    }
}

void main() {
    int size, i;
    printf("Enter the Size of the Array: ");
    scanf("%d", &size);
    int a[size];
    printf("Enter the Elements in the Array: ");
    for(i=0; i<size; i++) {
        scanf("%d", &a[i]);
    }
    Merge_sort(a, 0, size-1);
    printf("\nThe Sorted Array is: \n");
    for(i=0; i<size; i++) {
        printf("%d ", a[i]);
    }
}