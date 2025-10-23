/*
 * Exercise 2: Insertion Sort for Singly Linked List
 * Assignment 8 - IPFCE 2025
 * 
 * Implement insertion sort for a singly linked list of integers.
 * The list should be sorted in-place from smallest to largest.
 * No new nodes should be allocated - only pointers should be changed.
 */

#include "exercise2.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/* 
 * Sort a singly linked list in-place using insertion sort
 * list: pointer to the first node of the list
 * 
 * The function should sort the list by rearranging pointers,
 * not by creating new nodes or swapping data values.
 * Returns pointer to the new head of the sorted list.
 */
node* isort(node* list) {

    assert(list != NULL); //sikrer listen eksisterer

    node* sorted = NULL; //starter med at lave en tom sorteret liste
    node* current = list; //går gennem listen

    while(current != NULL){

        node* next = current->next; //gemmer den næste node

        //Her vil current indsættes i den sorteret liste
        if(sorted == NULL || current->data < sorted->data){

            //Her vil det næste tal blive sat forrest, hvis den sorterede liste er tom
            //eller hvis den aktuelle node (current) er mindre end den første node i den sorterede liste
            current->next = sorted;
            sorted = current;

        } else {

            //Find den korrekte placering ellers
            node* temp = sorted;

            while(temp->next != NULL && temp->next->data<current->data){
                temp = temp->next;
            }

            //Indsæt current efter temp i den sortereded liste
            current->next = temp->next;
            temp->next=current;
        }

        current = next; //går videre til den næste node

    }

    return sorted; 

}

/* Helper function to print the list */
void print_list(node* list) {
    node* current = list;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf(" -> NULL\n");
}

/* Helper function to create a node */
node *create_node(int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    if (!new_node)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

/* Helper function to free the list */
void free_list(node *list)
{
    node *current = list;
    node *next_node;

    while (current != NULL)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }
}
