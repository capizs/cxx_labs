/*Ввести последовательность натуральных чисел. Если в последовательности есть трехзначные числа, 
состоящие только из четных цифр, упорядочить последовательность по неубыванию первой цифры. 
В противном случае удалить из последовательности числа с четным количеством цифр и продублировать остальные числа. 
Последовательность хранить в односвязном списке.*/

#include "func.hpp"

int main() {
    Node* head = nullptr;
    int num;
    
    while (true) {
        std::cin >> num;
        if (num == 0) break;
        insertNode(head, num);
    }

    if (hasThreeEvenDigit(head)) {
        sortByFirstDigit(head);
    } else {
        processEvenLengthAndDuplicate(head);
    }

    displayList(head);
    
    freeList(head);
    return 0;
}