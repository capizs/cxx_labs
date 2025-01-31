/*Ввести последовательность натуральных чисел. Если в последовательности нет ни одного простого числа, 
упорядочить последовательность по невозрастанию. В противном случае удалить из последовательности числа, 
состоящие только из нечетных цифр, и продублировать числа, состоящие только из четных цифр. 
Последовательность хранить в двусвязном циклическом списке с фиктивным элементом.*/

#include <iostream>

using namespace std;

struct Node
{
    int info;    
    Node* next;  
    Node* prev;  
};

void append_number(Node *sent, int x)
{
    Node *q = new Node; 
    q->info = x;        
    q->next = sent;       
    q->prev = sent->prev; 
    sent->prev->next = q; 
    sent->prev = q;
}

void print_list(Node *sent)
{
    Node *p = sent->next; 
    while (p != sent)
    {
        cout << p->info << " ";
        p = p->next;
    }
}

bool is_prime(int num)
{
    if (num <= 1)
        return false;
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

bool all_digits_is_even(int num)
{
    while (num > 0)
    {
        if ((num % 10) % 2 != 0)
            return false;
        num /= 10;
    }
    return true;
}

bool all_digits_is_odd(int num)
{
    while (num > 0)
    {
        if ((num % 10) % 2 == 0)
            return false;
        num /= 10;
    }
    return true;
}

bool have_prime(Node *sent)
{
    Node *p = sent->next;
    while (p != sent)
    {
        if (is_prime(p->info))
            return true;
        p = p->next;
    }
    return false;
}

void sort_list(Node *sent)
{
    for (Node *a = sent->next; a->next != sent; a = a->next)
        for (Node *b = a->next; b != sent; b = b->next)
            if (a->info < b->info)
                swap(a->info, b->info);
}

void remove_odd_numbers(Node *sent)
{
    Node *p = sent->next;
    while (p != sent)
    {
        if (all_digits_is_odd(p->info))
        {
            p->prev->next = p->next;
            p->next->prev = p->prev;
            Node *temp = p;
            p = p->next;
            delete temp; 
        }
        else
        {
            p = p->next;
        }
    }
}

void duplicate_even_numbers(Node *top)
{
    Node *p = top->next;
    while (p != top)
    {
        if (all_digits_is_even(p->info))
        {
            Node *q = new Node;
            q->info = p->info;
            q->next = p->next;
            q->prev = p;
            p->next = q;
            q->next->prev = q;
            p = q->next;
        }
        else
        {
            p = p->next;
        }
    }
}

int main()
{
    Node *sent = new Node;
    sent->info = -1;
    sent->next = sent;
    sent->prev = sent;

    int n;
    cin >> n; 

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        append_number(sent, x);
    }

    if (have_prime(sent))
    {
        remove_odd_numbers(sent);
        duplicate_even_numbers(sent);
    }
    else
    {
        sort_list(sent);
    }

    print_list(sent);
}