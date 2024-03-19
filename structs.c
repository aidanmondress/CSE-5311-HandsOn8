/*
 * structs.c
 *
 *  Created on: Mar 19, 2024
 *      Author: aimon
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

typedef struct stack
{
    int arr[MAX_SIZE];
    int top;
} stack;

void stack_init(stack* s) 
{
    s->top = -1;
}

int stackFull(stack* s) 
{
    if(s->top == MAX_SIZE - 1)
        return 1;
    else
        return 0;
}

int stackEmpty(stack* s) 
{
    if(s->top == -1)
    	return 1;
    else
    	return 0;
}

void push(stack* s, int x) 
{
    if(stackFull(s)) 
        return;
    s->arr[++s->top] = x;
}

int pop(stack* s) 
{
    if (stackEmpty(s)) 
        return -1;
    return s->arr[s->top--];
}



typedef struct queue
{
    int arr[MAX_SIZE];
	int head;
    int tail;
} queue;

void queue_init(queue* q) 
{
    q->head = 0;
    q->tail = -1;
}

int queueFull(queue* q) 
{
    if(q->tail == MAX_SIZE - 1)
    	return 1;
    else
    	return 0;
 
}

int queueEmpty(queue* q) 
{
	if(q->tail < q->head)
		return 1;
	else
		return 0;
}

void enqueue(queue* q, int x) 
{
    if(queueFull(q)) 
        return;
    q->arr[++q->tail] = x;
}

int dequeue(queue* q) 
{
    if (queueEmpty(q)) 
        return -1;
    return q->arr[q->head++];
}



typedef struct node
{
    int data;
    struct Node* next;
} node;

node* node_init(int d) 
{
    node* n = (node*)malloc(sizeof(node));
    n->data = d;
    n->next = NULL;
    return n;
}

void insert(node** head, int d) 
{
    node* n = node_init(d);

    node* x = *head;
    while(x->next != NULL) 
    {
        x = x->next;
    }
    x->next = n;
}

void delete(node** head, int i) 
{
    node* x = *head;
    node* prev;
    
    if(x->data == i) 
    {
        *head = x->next;
        free(x);
        return;
    }
    
    while(x->data != i) 
    {
        prev = x;
        x = x->next;
    }
    
    if (x == NULL)
    	return;
    
    prev->next = x->next;
    free(x);
}
