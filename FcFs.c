#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
    int *arr;
    int size;
    int front;
    int rear;
}q;

q* initialize(int size){
    q* newq = (q* )malloc(sizeof(q));
    newq->size = size;
    newq->arr = (int* )malloc(size*sizeof(int));
    newq->front = -1;
    newq->rear = -1;
    return newq;
}

void enqueue(q* queue,int data){
    if(queue->rear == queue->size-1){
        printf("Queue is full....Sorry!!\n");
        return;
    }
    if(queue->front == -1){
        queue->front+=1;
    }
    queue->rear+=1;
    queue->arr[queue->rear] = data;
}

int dequeue(q* queue){
    if(queue->front == queue->rear){
        printf("Queue is empty....Sorry!!\n");
        return -1;
    }
    return queue->arr[queue->front];
}

void display(q*queue){
    for(int i=0;i<queue->size;i++){
        printf("%d ",queue->arr[i]);
    }
    printf("\n");
}

int main(){

    int n,data;
    printf("Enter number of processes:- ");
    scanf("%d",&n);

    q* queue = initialize(n);
    for(int i=0;i<n;i++){
        printf("Enter process %d:- ",i+1);
        scanf("%d",&data);
        enqueue(queue,data);
    }

    int start;
    printf("Enter the starting track of process:- ");
    scanf("%d",&start);

    int ans = 0;
    for(int i=0;i<n;i++){
        ans+=abs(queue->arr[i] - start);
        start = queue->arr[i];
    }

    printf("Displaying All Processes....\n");
    display(queue);

    printf("Total number of Tracks travelled:- %d\n",ans);

    return 0;
}