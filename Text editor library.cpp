// FCAI – Programming 1 – 2022 - Assignment 4
// Program Name: Text_Editor_library.cpp
// Last Modification Date: 11/5/2022
// Author1 and ID and Group: Abdulrahman Gamal 20210223
// Author2 and ID and Group: Ali Tariq 20210252
// Author3 and ID and Group: Khaled Salah 20211033
// Teaching Assistant: Eng. Yousra & Eng. Eman

#include <iostream>
#include <cstdio>
#include <algorithm>
#include "Text editor library.h"
#include <conio.h>

using namespace std;

#define red     "\033[31m"
#define green   "\033[32m"
#define WHITE   "\033[37m"
#define BLACK   "\033[30m"

void displayMenu() {
    cout << "Select What You Want To Do From The Following \n ";
    cout << "1-Add new text to the end of the file \n "
            "2-Display the content of the file \n "
            "3-Empty the file \n "
            "4-Encrypt the file content  \n "
            "5-Decrypt the file content \n "
            "6-Merge another file \n "
            "7-Count the number of words in the file. \n "
            "8-Count the number of characters in the file \n "
            "9-Count the number of lines in the file \n "
            "10-Search for a word in the file \n "
            "11-Count the number of times a word exists in the file \n "
            "12-Turn the file content to upper case \n "
            "13-Turn the file content to lower case \n "
            "14-Turn file content to 1'st caps \n "
            "15-Save The File \n "
            "16-Exit The Program \n";
}

void open() {
    cout << "Please, enter the name of the file.\n>>";
    cin >> file1_name;
    file1.open(file1_name, ios::in);
    if (file1.fail()) {
        cout << "File does not exist."
                "\nA new file is created.";
    } else {
        cout << green << "The file is opened successfully.\n";
    }
}

void append() {
    file1.open(file1_name, ios::app);
    file1 << '\n';
    cout << "Type the content you want to append to the file (press ctrl+z to end)\n";
    char c;
    c = getch();
    while (c != 26) {
        if (c == 13)cout << '\n';
        cout << c;
        file1 << c;
        c = getch();
    }
    file1.close();
    cout << "Content has been added successfully\n";
}

void displayContent() {
    file1.close();
    file1.open(file1_name, ios::in);
    cout << "The content of the file:\n";
    while (!file1.eof()) {
        char c = file1.get();
        cout << c;
        if (c == 13)cout << '\n';
    }
    file1.close();
}

void empty() {
    file1.close();
    file1.open(file1_name, ios::out);
    file1.close();
    cout << "Your file has been emptied successfully\n";
}

void encrypt() {
    file1.open(file1_name, ios::app | ios::in);
    char ch;
    string token;
    file1.clear();
    file1.seekg(0, ios::beg);
    while (!file1.eof()) {
        ch = file1.get();
        if (ch == EOF)
            break;
        token.push_back((char) (ch + (ch != 13)));
    }
    file1.close();
    file1.open(file1_name, ios::out);
    file1 << token;
    file1.close();
    cout << "Your file has been encrypted successfully\n";
}

void decrypt() {
    file1.open(file1_name, ios::app | ios::in);
    char ch;
    string token;
    file1.clear();
    file1.seekg(0, ios::beg);
    while (!file1.eof()) {
        ch = file1.get();
        if (ch == EOF)
            break;
        token.push_back((char) (ch - (ch != 13)));
    }
    file1.close();
    file1.open(file1_name, ios::out);
    file1 << token;
    file1.close();
    cout << "Your file has been decrypted successfully\n";
}

void MergeFiles() {
    file1.open(file1_name, ios::app);
    fstream file2;
    string file_name2;
    char token[1000];
    while (true) {
        cout << "Enter the second file's name:\n";
        cin >> file_name2;
        file2.open(file_name2, ios::in);
        if (file2)
            break;
        cout << "Invalid file name to merge, enter a valid file name:\n";
    }

    while (!file2.eof()) {
        file2.getline(token, 1000, '\n');
        file1 << token;
    }
    file2.close();
    cout << "Your file has been merged successfully\n";
}

void CountWords() {
    file1.open(file1_name, ios::in);
    char ch;
    int number_of_words = 0;
    file1.clear();
    file1.seekg(0, ios::beg);
    while (!file1.eof()) {
        file1.get(ch);
        cout << ch;
        if (ch == ' ' || ch == '\n' || file1.peek() == EOF)
            number_of_words++;
    }
    cout << "The number of the words in the file is " << number_of_words << " .\n";
}

void CountLines() {
    file1.open(file1_name, ios::app | ios::in);
    char ch;
    int number_of_lines = 0;
    file1.clear();
    file1.seekg(0, ios::beg);
    while (!file1.eof()) {
        file1.get(ch);
        if (ch == '.' || ch == '\n' || ch == ',' || file1.peek() == EOF)
            number_of_lines++;
    }
    cout << "The number of the lines in the file is " << number_of_lines << " .\n";
}

void CountCharacters() {
    file1.open(file1_name, ios::app | ios::in);
    char ch;
    int number_of_characters = 0;
    file1.clear();
    file1.seekg(0, ios::beg);
    while (!file1.eof()) {
        file1.get(ch);
        number_of_characters++;
    }
    cout << "The number of the characters in the file is " << number_of_characters << " .\n";
}

void uppercase() {
    file1.open(file1_name, ios::app | ios::in);
    char ch;
    string token;
    file1.clear();
    file1.seekg(0, ios::beg);
    while (!file1.eof()) {
        ch = file1.get();
        if (ch == EOF)
            break;
        token += toupper(ch);
    }
    file1.close();
    file1.open(file1_name, ios::out);
    file1 << token;
    file1.close();
    cout << "Your file has been converted to uppercase successfully\n";
}

void lowercase() {
    file1.open(file1_name, ios::app | ios::in);
    char ch;
    string token;
    file1.clear();
    file1.seekg(0, ios::beg);
    while (!file1.eof()) {
        ch = file1.get();
        if (ch == EOF)
            break;
        token += tolower(ch);
    }
    file1.close();
    file1.open(file1_name, ios::out);
    file1 << token;
    file1.close();
    cout << "Your file has been converted to lowercase successfully\n";
}

void FirstLineUppercase() {
    file1.open(file1_name, ios::in);
    char ch;
    string token;
    file1.clear();
    file1.seekg(0, ios::beg);
    while (!file1.eof()) {
        ch = file1.get();
        if (ch == EOF)
            break;
        token += ch;
    }
    token[0] = toupper(token[0]);
    for (int i = 0; i < token.size() - 2; ++i) {
        if ((token[i] == ' ' || token[i] == '\n') && isalpha(token[i + 1]))
            token[i + 1] = toupper(token[i + 1]);
    }

    file1.close();
    file1.open(file1_name, ios::out);
    file1 << token;
    file1.close();
    cout << "Your file has been converted to 1st caps successfully\n";
}


void numberOfTimes() {
    string word, token;
    int counter = 0;
    cout << "Enter the word you want you count for: ";
    cin >> word;
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    file1.clear();
    file1.seekg(0, ios::beg);
    while (file1 >> token) {
        transform(token.begin(), token.end(), token.begin(), ::tolower);
        if (word == token)
            counter++;
    }

    if (counter == 0) {
        cout << "Word does not exist in the file" << endl;
    } else
        cout << "The number of times the word exists in the file is " << counter << " .";

}

void searchOfWord() {
    string word;
    string token;
    bool found = false;
    cout << "Enter The Word You Want To Search For: ";
    cin >> word;
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    while (file1 >> token) {
        transform(token.begin(), token.end(), token.begin(), ::tolower);
        if (word == token) {
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Word Wasn't Found in The File" << endl;
    } else {
        cout << "Word Was Found In The File" << endl;
    }
}

void save() {
    char newName[100];
    cout << "Enter new name : ";
    cin >> newName;
    strcat(newName, ".txt");
    rename(file1_name, newName);
}