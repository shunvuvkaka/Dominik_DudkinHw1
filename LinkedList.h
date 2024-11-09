#pragma once
#ifndef LINKED_LIST_H
#define LINKED_LIST_H


struct Node
{
    int data;        
    Node* next;
};

struct LinkedList
{
    Node* head;       
};


void initList(LinkedList* list);
void addToList(LinkedList* list, int value);
int removeFromList(LinkedList* list);
bool isEmpty(const LinkedList* list);
void printList(const LinkedList* list);
void cleanList(LinkedList* list);

#endif LINKED_LIST_H 