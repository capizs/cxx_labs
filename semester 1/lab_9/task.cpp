/*Дано целое число типа short, выведите на экран содержимое каждого из его байтов, 
используя знания по указателям. Дайте обоснование полученному результату.*/

#include <iostream>

int main() {
    short num;
    std::cin >> num;

    unsigned char* p = (unsigned char*)&num; //адрес
    
    for (int i = 0; i < sizeof(num); i++) {
        int t = *(p + i); //байт       
        if (t < 16)
            std::cout << "0";
        std::cout << std::hex << t << " ";
    }
    //00000100.00000110
    return 0;
}