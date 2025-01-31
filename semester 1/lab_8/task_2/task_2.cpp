/*Дана строка, содержащая английский текст. Вывести в порядке, обратном к алфавитному, слова текста, 
содержащие не менее 3-х гласных, в остальных словах удалить гласные и продублировать согласные буквы.*/

#include <iostream>
#include <string>

using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int countVowels(const string& word) {
    int count = 0;
    for (char c : word) {
        if (isVowel(c)) count++;
    }
    return count;
}

string processWord(const string& word) {
    if (countVowels(word) >= 3) return word;
    
    string result;
    for (char c : word) {
        if (!isVowel(c)) {
            result += c;
            result += c;
        }
    }
    return result;
}

int main() {
    string text;
    getline(cin, text);
    
    string word;
    string words[1000];
    int wordCount = 0;
    
    for (char c : text) {
        if (isalpha(c)) {
            word += c;
        } else if (word != "") {
            words[wordCount++] = word;
            word.clear();
        }
    }
    if (!word.empty()) {
        words[wordCount++] = word;
    }
    
    for (int i = 0; i < wordCount - 1; i++) {
        for (int j = 0; j < wordCount - i - 1; j++) {
            if (countVowels(words[j]) >= 3 && countVowels(words[j + 1]) >= 3) {
                if (words[j] < words[j + 1]) {
                    swap(words[j], words[j + 1]);
                }
            }
        }
    }
    
    for (int i = 0; i < wordCount; i++) {
        cout << processWord(words[i]) << " ";
    }
    cout << endl;
    return 0;
}