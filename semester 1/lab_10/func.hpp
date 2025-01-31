#pragma once
#include <iostream>

struct Node 
{
    int data;
    Node* next;
};

Node* createNode(int value);
void insertNode(Node*& head, int value);
bool hasThreeEvenDigit(Node* head);
void sortByFirstDigit(Node* head);
void processEvenLengthAndDuplicate(Node*& head);
void displayList(Node* head);
int getFirstDigit(int num);
int countDigits(int num);
void freeList(Node* head);