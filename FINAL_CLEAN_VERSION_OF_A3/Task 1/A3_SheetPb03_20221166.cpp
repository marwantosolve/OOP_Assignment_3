// File name: A3_SheetPb03_20221166.cpp
// Purpose:
// Author: Menna Khaled
// ID: 20221166
// Section: S17,18
// Date: 9/12/2023

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

// Function to clean and process a word
string clean(const string& word) {
    string cleanedWord;
    for (char d : word) {
        if (isalnum(d) || d == '-') {
            cleanedWord.push_back(tolower(d));
        }
    }
    return cleanedWord;
}

int main() {
    string fileName;

    // Get the file name from the user
    cout << "Enter the name of the file: \n"
            ">>";
    cin >> fileName;
    fileName += ".txt";

    // Open the file
    ifstream file(fileName);

    // Check if the file is open
    if (!file.is_open()) {
        cout << "Error opening file!... Make sure that the file exists and try again. \n";
        return 0;
    }

    // Map to store word frequencies
    map<string, int> wordFrequency;

    // Read the file word by word
    string word; // to store each word read from the file.
    while (file >> word) // This while loop reads words from the file stream one by one until the end of the file
    {
        // Clean the word and update frequency
        string cleanedWord = clean(word);
        if (!cleanedWord.empty()) {
            wordFrequency[cleanedWord]++;
        }
    }

    // Close the file
    file.close();

    // Display the frequency table
    cout << "| Word Frequency Table | \n";
    for (auto w : wordFrequency) {
        cout << "| "<< w.first << ": " << w.second << " |\n";
    }

    return 0;
}