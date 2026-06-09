#include<stdio.h>
#include<stdlib.h>

// int main(void)
// {
//     int arr[] = {3,5,1,9,5};
//     int *p = arr;
//     int n = sizeof(arr) / sizeof(arr[5]);
//     for(int i=0; i<= n; i++)
//     {
//         printf(" %d,", *p);
//         p++;
//     }
//     printf("\n");
//     int dimens[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
//     for(int i=0; i<3; i++)
//     {
//         for(int j=0; j< 3; j++)
//         {
//             printf(" %d,",dimens[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }

typedef struct node
{
    int value;
    struct node *next;
}node; 

typedef struct list
{
    node *top;
    int size;
}list;

void init(list *l){l->top = NULL;}

void enlist(list *l,int a)
{
    struct node *new = malloc(sizeof(node));
    new->value = a;
    new->next = NULL; 
    if(l->top == NULL){l->top = new;}
    else
    {
        node *cur = l->top;
        while(cur->next != NULL){cur = cur->next;}
        cur->next = new;
    }
}

void print(list *l)
{
    node *cur = l->top;
    while(cur->next != NULL){printf(" %d,", cur->value); cur = cur->next;} 
}

int main(void)
{
    list adamu;
    init(&adamu);
    enlist(&adamu,1);
    enlist(&adamu,2);
    enlist(&adamu,3);
    enlist(&adamu,4);
    enlist(&adamu,5);
    enlist(&adamu,6);
    enlist(&adamu,7);
    enlist(&adamu,8);
    enlist(&adamu,9);
    print(&adamu);
}