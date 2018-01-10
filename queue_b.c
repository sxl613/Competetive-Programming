#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>   
typedef struct Queue {
    int* arr;
    int capacity;
    int size;
    int write;
    int read;
} Queue;

Queue* createQueue(int size)
{
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->size = 0;
    queue->capacity = size;
    queue->arr = (int*) malloc(sizeof(int)*size);
    queue->write = 0;
    queue->read = 0;
    return queue;
}
bool isFull(Queue* queue)
{
    return queue->size == queue->capacity;
}
bool isEmpty(Queue* queue)
{
    return queue->size == 0;
}
void enqueue(Queue* queue, int e)
{
    if (isFull(queue))    {printf("FULL QUEUE\n");}
    else
    {
        queue->arr[queue->write] = e;
        queue->write = (queue->write  + 1)% queue->capacity;
        queue->size++;
    }
}

int dequeue(Queue* queue)
{
    if (isEmpty(queue))  return -1;
    else
    {
        int e = queue->arr[queue->read];
        queue->read = (queue->read + 1) % queue->capacity;
        queue->size--;
        return e;
    }
}

int front(Queue* queue)
{
    if (isEmpty(queue))  return -1;
    else    return queue->arr[queue->read];
}
int back(Queue* queue)
{
    if (isEmpty(queue))  return -1;
    else    return queue->arr[queue->write-1];
}
int main()
{
    return 0;
}