#include "LinkedList.h"
#include <iostream>


void initList(LinkedList* list)
{
    list->head = NULL;
}


void addToList(LinkedList* list, int value)
{
    if (value <= 0)
    {
        std::cout << "Only positive nums please." << std::endl;
        return;
    }

    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = list->head;
    list->head = newNode;
}


int removeFromList(LinkedList* list)
{
    if (isEmpty(list))
    {
        std::cout << "cant remove nothing dude" << std::endl;
        return -1;
    }

    Node* temp = list->head;
    int value = temp->data;
    list->head = list->head->next;
    delete temp;

    return value;
}


bool isEmpty(const LinkedList* list)
{
    return list->head == NULL;
}


void printList(const LinkedList* list)
{
    if (isEmpty(list))
    {
        std::cout << "list has nothing" << std::endl;
        return;
    }

    Node* current = list->head;
    while (current != NULL)
    {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "NULL" << std::endl;
}


void cleanList(LinkedList* list)
{
    while (!isEmpty(list))
    {
        removeFromList(list);
    }
}