#include<stdio.h>
#include<stdlib.h>

#define MS 5

typedef struct queue
{
    int front;
    int arr[MS];
    int rear;
} queue;

void init(queue *q)
{
    q->front = -1;
    q->rear = -1;
}
void push(queue*q, int x)
{
    if(q->rear == MS -1)
    {
        printf("chal nikal yaha se\n");
        return;
    }
    if(q->front == -1 && q->rear == -1)
    {
        q->front = q->front + 1;
        q->rear = q->rear +1;
    }
    else
    {
        q->rear = q->rear+1;
    }
    q->arr[q->rear] = x;
}
void display(queue*q)
{
    if(q->rear == -1 && q->front == -1)
    {
        return;
    }
    for(int i=q->front; i<=q->rear; i++)
    {
        printf("%d",q->arr[i]);
    }
    printf("\n");
}
void pop(queue*q)
{
   if(q->front == -1 && q->rear == -1)
   {
    printf("underflow ho gya hai brother\n");
    return;
   } 
   if(q->front == q->rear)
   {
    q->front = -1;
    q->rear = -1;
    return;
   }
   q->front=q->front+1;
}
int main()
{
    queue q;
    init(&q);
    push(&q,10);
    display(&q);

    push(&q,20);
    display(&q);

    push(&q,30);
    display(&q);

    push(&q,40);
    display(&q);

    push(&q,50);
    display(&q);

    push(&q,60);
    display(&q);

    pop(&q);
    display(&q);

    pop(&q);
    display(&q);
    
    pop(&q);
    display(&q);

    pop(&q);
    display(&q);

    pop(&q);
    display(&q);

    pop(&q);
    display(&q);
    
}
