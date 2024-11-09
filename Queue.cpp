#include "Queue.h"
#include <iostream>


struct Queue
{
    unsigned int* elements;
    unsigned int capacity;
    unsigned int headIndex;
    unsigned int tailIndex;
    unsigned int currentSize;
};


void initQueue(Queue* q, unsigned int maxCapacity)
{
    q->elements = new unsigned int[maxCapacity]; 
    q->capacity = maxCapacity;
    q->headIndex = 0;
    q->tailIndex = 0;
    q->currentSize = 0;
}


void cleanQueue(Queue* q)
{
    if (q->elements != NULL)
    {
        delete[] q->elements;
        q->elements = NULL;
    }
    q->capacity = 0;
    q->headIndex = 0;
    q->tailIndex = 0;
    q->currentSize = 0;
}


bool isEmpty(Queue* q)
{
    if (q->currentSize == 0)
    {
        return true;
    }
    return false;
}


bool isFull(Queue* q)
{
    if (q->currentSize == q->capacity)
    {
        return true;
    }
    return false;
}


void enqueue(Queue* q, unsigned int newElement)
{
    if (isFull(q))
    {
        std::cout << "Queue is full cant add no more" << newElement << std::endl;
        return;
    }

    q->elements[q->tailIndex] = newElement; 
    q->tailIndex = (q->tailIndex + 1) % q->capacity;
    q->currentSize++;
}


int dequeue(Queue* q)
{
    if (isEmpty(q))
    {
        std::cout << "Nothing in queue cant really remove nothing" << std::endl;
        return -1;
    }

    int frontElement = q->elements[q->headIndex];
    q->headIndex = (q->headIndex + 1) % q->capacity;
    q->currentSize--;

    return frontElement;
}