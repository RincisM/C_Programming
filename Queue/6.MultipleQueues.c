#include <stdio.h>
#include <stdlib.h>
# define max 20
int insq (int queue[max], int qno, int rear[], int limit[], int *data) {
    if (rear[qno] == limit[qno])
        return(-1);
    else {
        rear[qno]++; //... rear[qno] = rear[qno] + 1;
        queue[ rear[qno] ] = *data;
        return(1);
    } // else
} // insq
int delq (int queue[max], int qno, int front[], int rear[], int *data) {
    if( front[qno] == rear[qno] )
        return(-1);
    else {
        front[qno]++; //... front[qno] = front[qno] + 1;
        *data = queue[ front[qno] ];
        return(1);
    } // else
} // delq
int getQueueNumber(int n) {
    int qNo=0;
    Inva:
    printf("\nEnter a Queue Number (1 to %d) : ", n);
    scanf("%d", &qNo);
    if (qNo<1 || qNo >n) {
        printf("Invalid Queue Number. Please try again.\n");
        goto Inva;
    }
    return qNo;
}
void main() {
    int queue[max],  data;
    int bott[10], limit[10], f[10], r[10];
    int i, n, qno, size, option, reply;
    printf("\nHow Many Queues to create?: ");
    scanf("%d", &n);
    size = max / n; //... Get Max. size for each Queue
    //... Initialize bottom for each Queue
    bott[0] = -1; //... Bottom of first Queue is -1
    for(i = 1; i < n; i++)
        bott[i] = bott[i-1] + size;
    //... Initialize Limit of each Queue
    for(i = 0; i < n; i++) //... Limit of i'th Queue is equal to bottom of i'th Queue + Size
        limit[i] = bott[i] + size;
    //... Initialize Front & Rear of each Queue
    //... Initial value of Front & Rear of each Queue is same as its Bottom Value
    for(i = 0; i < n; i++)
        f[i] = r[i] = bott[i];
    //... Process the Queues
    do {
        printf("\n1. Insert in a Queue");
        printf("\n2. Delete from a Queue");
        printf("\n3. Print from a Queue");
        printf("\n4. Exit \n");
        printf("\nChoose one of the options: ");
        scanf("%d", &option);
        switch(option) {
            case 1 : //... Insert
                qno    = getQueueNumber(n);
                printf("\nEnter Data : ");
                scanf("%d", &data);
                reply = insq(queue, qno-1, r, limit, &data);
                if( reply == -1)
                    printf("\nQueue %d is Full \n", qno); 
                break;
            case 2 : //... Delete
                qno    = getQueueNumber(n);
                reply = delq(queue, qno-1, f, r, &data);
                if( reply == -1)
                    printf("\nQueue %d is Empty \n", qno);
                break;
            case 3:
                qno    = getQueueNumber(n);
                printf("\nElements of Queue %d are as : ", qno);
                if (f[qno-1]==r[qno-1]) {
                    printf("Queue is empty");
                    break;
                }
                for (i=f[qno-1]+1; i<=r[qno-1]; i++)
                    printf("%d\t", queue[i]);
                printf("\n");
                break;
            case 4 :
                break;
            default:
                printf("Invalid input. Please try again.");
        } // switch
    }while(option!=4);
}