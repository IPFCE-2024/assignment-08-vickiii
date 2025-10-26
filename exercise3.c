/*
 * Exercise 3: Queue Implementation using Singly-Linked Lists
 * Assignment 8 - IPFCE 2025
 * 
 * Implement a queue using singly-linked lists.
 * The queue should maintain FIFO (First-In, First-Out) order.
 */

#include "exercise3.h"
#include <stdio.h>
#include <stdlib.h> //for malloc() og free()
#include <assert.h>

/* 
 * Initialize an empty queue
 * q: pointer to the queue structure
 * 
 * Post-condition: queue is empty with front and rear set to NULL
 */
void initialize(queue *q) {
    
    q->front = NULL; //fronten sættes til NULL, da køen er tom
    q->rear = NULL; //Bagenden af køen sættes til NULL, da der er ingen elementer

}

/* 
 * Insert item x at the back of queue q
 * q: pointer to the queue structure
 * x: item to be inserted
 * 
 * Pre-condition: queue is not full
 * Post-condition: x is added to the rear of the queue
 */
void enqueue(queue *q, int x) {
    
    //Opretter ny node
    node *newNode = malloc(sizeof(node));
    assert(newNode != NULL); //det sikrer at hukommelsen bliver allokeret korrekt

    newNode->data = x; //gemmer x i den nye node
    newNode->next = NULL; //den nye node skal være bagerst -> next = NULL

    //Hvis køen er tom
    if(q->rear == NULL){
        q->front = newNode; //front peger på den nye node
        q->rear = newNode; //rear peger på den nye node
    } else { //Hvis køen ikke er tom
        q->rear->next = newNode; //det tidligere bagerste node peger på det nye node
        q->rear = newNode; //rear flyttes, så den kan pege på den nye
    }
}

/* 
 * Return (and remove) the front item from queue q
 * q: pointer to the queue structure
 * 
 * Pre-condition: queue must not be empty
 * Post-condition: front item is removed and returned
 */
int dequeue(queue *q) {
    
    assert(q->front != NULL); //sørger for køen ikke er tom, for at kunne fjerne elementer

    node *temp = q->front; //midlertidigt pege på den første node
    int value = temp->data; //gemmer data fra front

    q->front = q->front->next; //flytter front til det næste element i køen

    //I tilfælde af tom kø efter fjernet element
    if(q->front == NULL){
        q->rear = NULL; //rear skal sættes til NULL
    }

    free(temp); //frigøre hukommelsen for den gamle front

    return value;  //returnerer det fjernede værdi
}

/* 
 * Check if the queue is empty
 * q: pointer to the queue structure
 * Returns: true if queue is empty, false otherwise
 */
bool empty(const queue *q) {
    
    return (q->front == NULL); // tom kø, hvis front == NULL
}

/* 
 * Check if the queue is full
 * q: pointer to the queue structure
 * Returns: true if queue is full, false otherwise
 */
bool full(const queue *q) {
   
    return false;
}

/* Helper function to print the queue */
void print_queue(const queue *q) {
    printf("Queue (front to rear): ");
    node *current = q->front;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" <- ");
        }
        current = current->next;
    }
    printf("\n");
}

