#include <stdio.h>
#include <stdlib.h>

/*
 * Data Structures - Implementing a Queue for Interrupt Handling
 * Problem: Implement a queue data structure using a linked list in C, and then simulate a basic interrupt 
 *          handling mechanism in embedded systems where multiple interrupt requests (IRQs) are queued and 
 *          processed in order. Each interrupt will be represented by a priority level (higher number 
 *          indicates higher priority).
 *
 * Steps:
 * - Implement a queue to enqueue and dequeue interrupt requests
 * - Write a function to process interrupt requests based on their priority level
 * - Demonstrate the functionality by simulating a series of interrupt requests
 */

 /* Define the structure for a queue node */

typedef struct Node 
{
    /* Priority of the interrupt */
    int priority;
    /* Pointer to the next node in the queue */
    struct Node* next;
} Node;

/* Define the structure for the queue */
typedef struct
{
    /* Pointer to the front node */
    struct Node* front;
    /* Pointer to the rear node */
    struct Node* rear;
} Queue;

/* Function to create a new Queue */
Queue* createQueue(void)
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL)
    {
        printf("Failed to allocate memory for the queue!\n");
        return NULL;
    }

    queue->front = queue->rear = NULL;
    
    return queue;
}

/* Function to enqueue an element */
void enqueue(Queue* queue, int priority)
{
    if (queue == NULL)
    {
        printf("Queue is not initialized!\n");
        return;
    }
    
    /* Create a new node */
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    temp->priority = priority;
    temp->next = NULL;

    /* If the queue is empty, initialize the front and rear */
    if (queue->rear == NULL)
    {
        queue->front = queue->rear = temp;
        /* Make it circular */
        queue->rear->next = queue->front;
    }
    else
    {
        /* Add the node at the end of the queue */
        queue->rear->next = temp;
        queue->rear       = temp;
        /* Maintain circular connection */
        queue->rear->next = queue->front;
    }
}

/* Function to dequeue an element */
int dequeue(Queue* queue)
{
    int priority;
    
    if (queue == NULL) || (queue->front == NULL)
    {
        printf("Queue is empty or not initialized!\n");
        return -1;
    }

    if (q->front == q->rear)
    {
        /* Only one element in queue */
        priority = queue->front->priority;
        free(queue->front);
        /* Queue becomes empty */
        q->front = q->rear = NULL;
    }
    else
    {
        /* More than one element */
        Node *temp = queue->front;
        proirity = temp->priority;
        queue->front = queue->front->next;
        q->rear->next = queue->front;
        free(temp);
    }


}