/*В текстовом файле input.txt записан английский текст. Найти в тексте слова, содержащие ровно одну из 10 наиболее часто 
встречающихся букв текста записать их заглавными буквами и указать после каждого такого слова в скобках найденную букву. 
Полученный текст записать в файл output.txt. Весь текст, кроме найденных слов, должен остаться неизменным, 
включая и знаки препинания.*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isLetter(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

void sortLetterArrays(int* counts, char* letters, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (counts[j] < counts[j + 1]) {
                int tempCount = counts[j];
                counts[j] = counts[j + 1];
                counts[j + 1] = tempCount;
                
                char tempLetter = letters[j];
                letters[j] = letters[j + 1];
                letters[j + 1] = tempLetter;
            }
        }
    }
}

string toUpper(string word) {
    string result = word;
    for (int i = 0; i < result.length(); i++) {
        if (isLetter(result[i])) {
            if (result[i] >= 'a' && result[i] <= 'z') {
                result[i] = result[i] - 'a' + 'A';
            }
        }
    }
    return result;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    
    int letterCounts[26] = {0};
    char letters[26];
    
    for (int i = 0; i < 26; i++) {
        letters[i] = 'a' + i;
    }
    
    char ch;
    while (fin.get(ch)) {
        if (isLetter(ch)) {
            if (ch >= 'A' && ch <= 'Z') {
                ch = ch - 'A' + 'a';
            }
            letterCounts[ch - 'a']++;
        }
    }
    
    sortLetterArrays(letterCounts, letters, 26);
    
    fin.clear();
    fin.seekg(0); // в начало файла
    
    string word;
    while (fin.get(ch)) {
        if (isLetter(ch)) {
            word += ch;
        } else {
            if (word != "") {
                int topLetterCount = 0;
                char foundLetter = 0;
                
                for (char c : word) {
                    char lowerC = (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c;
                    for (int i = 0; i < 10; i++) {
                        if (lowerC == letters[i]) {
                            topLetterCount++;
                            foundLetter = letters[i];
                            break;
                        }
                    }
                }
                
                if (topLetterCount == 1) {
                    fout << toUpper(word) << "(" << foundLetter << ")";
                } else {
                    fout << word;
                }
                word.clear();
            }
            fout << ch;
        }
    }
    
    // Последнее слово
    if (word != "") {
        int topLetterCount = 0;
        char foundLetter = 0;
        
        for (char c : word) {
            char lowerC = (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c;
            for (int i = 0; i < 10; i++) {
                if (lowerC == letters[i]) {
                    topLetterCount++;
                    foundLetter = letters[i];
                    break;
                }
            }
        }
        
        if (topLetterCount == 1) {
            fout << toUpper(word) << "(" << foundLetter << ")";
        } else {
            fout << word;
        }
    }
    
    fin.close();
    fout.close();
    return 0;
}