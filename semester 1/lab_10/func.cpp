#include "func.hpp"

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

void insertNode(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

bool hasThreeEvenDigit(Node* head) {
    Node* current = head;
    while (current) {
        int num = current->data;
        if (num >= 100 && num <= 999) {
            bool allEven = true;
            int temp = num;
            while (temp > 0) {
                if ((temp % 10) % 2 != 0) {
                    allEven = false;
                    break;
                }
                temp /= 10;
            }
            if (allEven) return true;
        }
        current = current->next;
    }
    return false;
}

void sortByFirstDigit(Node* head) {
    if (!head || !head->next) return;
    
    Node *i, *j;
    for (i = head; i; i = i->next) {
        for (j = i->next; j; j = j->next) {
            if (getFirstDigit(i->data) > getFirstDigit(j->data)) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void processEvenLengthAndDuplicate(Node*& head) {
    Node* current = head;
    Node* prev = nullptr;
    
    while (current) {
        int digits = countDigits(current->data);
        if (digits % 2 == 0) {
            Node* temp = current;
            if (prev) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            current = current->next;
            delete temp;
        } else {
            Node* newNode = createNode(current->data);
            newNode->next = current->next;
            current->next = newNode;
            prev = newNode;
            current = newNode->next;
        }
    }
}

void displayList(Node* head) {
    Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int getFirstDigit(int num) {
    while (num >= 10) {
        num /= 10;
    }
    return num;
}

int countDigits(int num) {
    int count = 0;
    while (num > 0) {
        count++;
        num /= 10;
    }
    return count;
}

void freeList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}