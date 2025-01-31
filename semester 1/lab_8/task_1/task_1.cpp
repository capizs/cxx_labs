#include <iostream>
#include <string>
#include <fstream>

bool isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

char toLower(char c) {
    if (c >= 'A' && c <= 'Z') return c + 32;
    return c;
}

bool canFormWord(const std::string& word, const std::string& baseWord) {
    int letterCount[26] = {0};
    int baseCount[26] = {0};
    
    for (char c : baseWord) {
        baseCount[toLower(c) - 'a']++;
    }
    
    for (char c : word) {
        letterCount[toLower(c) - 'a']++;
    }
    
    int diffCount = 0;
    for (int i = 0; i < 26; i++) {
        if (letterCount[i] > baseCount[i]) {
            diffCount += letterCount[i] - baseCount[i];
        }
    }
    return diffCount == 1;
}

std::string cleanWord(const std::string& word) {
    std::string cleaned;
    for (char c : word) {
        if (isLetter(c)) {
            cleaned += c;
        }
    }
    return cleaned;
}

void insertSorted(std::string words[], int lengths[], int& count, const std::string& newWord, const int maxWords) {
    for (int i = 0; i < count; i++) {
        if (words[i] == newWord) return;
    }
    
    int newLength = newWord.length();
    int pos = count;
    
    while (pos > 0 && (lengths[pos-1] < newLength || 
           (lengths[pos-1] == newLength && words[pos-1] > newWord))) {
        if (pos < maxWords) {
            words[pos] = words[pos-1];
            lengths[pos] = lengths[pos-1];
        }
        pos--;
    }
    
    if (pos < maxWords) {
        words[pos] = newWord;
        lengths[pos] = newLength;
        if (count < maxWords) count++;
    }
}

int main() {
    const int MAX_WORDS = 2000;
    std::string baseWord = "executive";
    std::string words[MAX_WORDS];
    int lengths[MAX_WORDS];
    int wordCount = 0;
    
    std::ifstream inFile("input.txt");
    std::string word;
    
    while (inFile >> word) {
        word = cleanWord(word);
        if (word != "" && canFormWord(word, baseWord)) {
            insertSorted(words, lengths, wordCount, word, MAX_WORDS);
        }
    }
    inFile.close();
    
    std::ofstream outFile("output.txt");
    for (int i = 0; i < wordCount; i++) {
        outFile << words[i] << '\n';
    }
    outFile.close();
    
    return 0;
}