#include <iostream>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <stdio.h>

using namespace std;
string choices[]{"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16"};

void mergeFile(ofstream &file, string fileName);

int numOfLines(ifstream &file, string fileName);

int numOfChar(ifstream &file, string fileName);

int numOfWord(ifstream &file, string fileName);

void searchOfWord(ifstream &file, string fileName);

int main() {
    string textFileName;
    string choice;
    cout << "Enter The File Name You Want to Open: " << endl;
    cin >> textFileName;
    textFileName += ".txt";
    ifstream myFile(textFileName);
    if (myFile.is_open()) {
        cout << "This File Already Exists" << endl;
    } else {
        cout << "This is New File!,I Created it for you" << endl;
        ofstream myFile(textFileName, ios::ate);
    }
    myFile.close();
    while (true) {
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
                "15-Save The Image \n "
                "16-Exit The Program \n";

        cin >> choice;
        bool flag = true;
        while (flag) {
            for (auto item: choices) {
                if (item == choice) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << "Invalid Choice,Enter a Valid one \n";
                cin >> choice;
            }
        }

        if (choice == "1") {}
        else if (choice == "2") {}
        else if (choice == "3") {}
        else if (choice == "4") {}
        else if (choice == "5") {}
        else if (choice == "6") {

            ofstream myFile(textFileName, ios::app);
            mergeFile(myFile, textFileName);
        } else if (choice == "7") {
            myFile.open(textFileName);
            cout << "The Number Of Words is: " << numOfWord(myFile, textFileName) << endl;
        } else if (choice == "8") {
            myFile.open(textFileName);
            cout << "The Number Of Characters is: " << numOfChar(myFile, textFileName) << endl;
        } else if (choice == "9") {
            myFile.open(textFileName);
            cout << "The Number Of Lines is: " << numOfLines(myFile, textFileName) << endl;
        } else if (choice == "10") {
            myFile.open(textFileName);
            searchOfWord(myFile, textFileName);
        } else if (choice == "11") {}
        else if (choice == "12") {}
        else if (choice == "13") {}
        else if (choice == "14") {}
        else if (choice == "15") {}
        else if (choice == "16") {
            break;
        }
    }
}

void mergeFile(ofstream &file, string fileName) {
    string secondFileName, secondFileContents = "";
    cout << "Enter The Second File Text Name: " << endl;
    cin >> secondFileName;
    secondFileName += ".txt";
    ifstream file2(secondFileName);

    while (getline(file2, secondFileName)) {
        secondFileContents += secondFileName;
        secondFileContents += "\n";
    }

    file << "\n" << secondFileContents;
    file.close();
}

int numOfLines(ifstream &file, string fileName) {
    int numOfLines = 0;
    while (getline(file, fileName)) {
        numOfLines += 1;
    }
    file.close();
    return numOfLines;
}

int numOfChar(ifstream &file, string fileName) {
    int numOfChar = 0;
    while (getline(file, fileName)) {
        for (int i = 0; i < fileName.length(); ++i) {
            if (fileName[i] == ' ') {
                continue;
            } else
                numOfChar += 1;
        }
    }
    file.close();
    return numOfChar;
}

int numOfWord(ifstream &file, string fileName) {
    int numOfWord = 0;
    while (getline(file, fileName)) {
        for (int i = 1; i < fileName.length(); ++i) {
            if (fileName[i] == ' ' || fileName[i]=='\n') {
                if (fileName[i + 1] != ' ' ||fileName[i]=='\n') {
                    numOfWord += 1;
                }
            }

        }
    }
    file.close();
    return numOfWord;
}

void searchOfWord(ifstream &file, string fileName) {
    string word, temp = "temp.txt";
    size_t flag;
    bool found = true;
    cout << "Enter The Word You Want To Search For: ";
    cin >> word;
    transform(word.begin(), word.end(), word.begin(), ::tolower);

    ofstream tempFile("temp.txt", ios::ate);
    while (getline(file, fileName)) {
        transform(fileName.begin(), fileName.end(), fileName.begin(), ::tolower);
        tempFile << fileName << endl;
    }
    tempFile.close();
    ifstream tempfile(temp);
    while (getline(tempfile, temp)) {
        flag = temp.find(word);
        if (flag != string::npos && found) {
            found = false;
            cout << "Word Was Found In The File" << endl;

        }
    }
    if (flag == string::npos) {
        cout << "Word Wasn't Found in The File" << endl;
    }
    tempfile.close();
    file.close();
    remove("temp.txt");


}
