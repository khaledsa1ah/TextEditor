// FCAI – Programming 1 – 2022 - Assignment 4
// Program Name: Text_Editor_header.cpp
// Last Modification Date: 11/5/2022
// Author1 and ID and Group: Abdulrahman Gamal 20210223
// Author2 and ID and Group: Ali Tariq 20210252
// Author3 and ID and Group: Khaled Salah 20211033
// Teaching Assistant: Eng. Yousra & Eng. Eman

#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
#ifndef ASSIGNMENT_4_TEXT_EDITOR_LIBRARY_H
#define ASSIGNMENT_4_TEXT_EDITOR_LIBRARY_H



fstream file1;
char file1_name[100];
set<string>choices{"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16"};

void displayMenu();
void append();
void displayContent();
void empty();
void encrypt();
void decrypt();
void MergeFiles();
void CountWords();
void CountCharacters();
void CountLines();
void searchOfWord();
void numberOfTimes();
void uppercase();
void lowercase();
void FirstLineUppercase();
void save();


#endif //ASSIGNMENT_4_TEXT_EDITOR_LIBRARY_H
