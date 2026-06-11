#include<stdio.h>
#include<stdlib.h>

#define max 10
typedef struct queue
{
    int data[max];
    int top;
    int rear;
    int size;
}Q;

void init(Q *s){ s->top = 0; s->rear = 0; s->size = 0;}
int isfull(Q *s){
    if(s->size == max){
        return 1;
    }else{
        return 0;
    }
}
int isempty(Q *s){if(s->size == 0){return 1;}else{return 0;}}
void enqueue(Q *s, int a)
{
    if(isfull(s) == 1){printf("Queue is full");}
    else 
    {
        s->data[s->rear] = a;
        s->rear = (s->rear + 1) % max;
        s->size++;
    }
}

int dequeue(Q *s)
{
    int a = s->data[s->top];
    s->top = (s->top + 1) % max;
    s->size--;
    return a;
}

void print(Q *s)
{
    int i = s->top;
    int count = 0;
    while(count < s->size)
    {
        printf(" %d ",s->data[i]);
        i = (i + 1) % max;
        if( i == s->rear){break;}
        count++;
    }
}

int main(void){
    // printf("Hello ");
    Q adamu;
    init(&adamu);
    enqueue(&adamu, 1);
    enqueue(&adamu, 2);
    enqueue(&adamu, 3);
    enqueue(&adamu, 4);
    enqueue(&adamu, 5);
    enqueue(&adamu, 6);
    enqueue(&adamu, 7);
    enqueue(&adamu, 8);
    enqueue(&adamu, 9);
    enqueue(&adamu, 10);
    dequeue(&adamu);
    dequeue(&adamu);
    dequeue(&adamu);
    dequeue(&adamu);
    dequeue(&adamu);
    dequeue(&adamu);
    dequeue(&adamu); 
    enqueue(&adamu, 10);
    enqueue(&adamu, 11);
    enqueue(&adamu, 12);
    enqueue(&adamu, 13);
    enqueue(&adamu, 14);
    enqueue(&adamu, 15);
    print(&adamu);
    
    return 0;
}