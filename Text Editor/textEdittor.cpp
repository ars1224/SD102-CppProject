#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string filePath = "";
bool isModified = false;
string documentContent = "";

void SaveFile() {
    if (filePath.empty()) {
        cout << "Enter file name to save as: ";
        cin.ignore(); // Clear buffer
        getline(cin, filePath);
    }
    ofstream file(filePath);
    if (file) {
        file << documentContent;
        file.close();
        isModified = false;
        cout << "File saved successfully.\n";
    }
    else {
        cout << "Error saving file.\n";
    }
}

void NewFile() {
    if (isModified) {
        cout << "Do you want to save changes? (y/n): ";
        string choice;
        cin >> choice;
        cin.ignore();
        if (choice == "y") {
            SaveFile();
        }
    }
    cout << "Enter new content (end with a single line containing 'Submit'):\n";
    string line;
    documentContent.clear();
    cin.ignore(); // Ensure input buffer is cleared
    while (true) {
        getline(cin, line);
        if (line == "Submit") break;
        documentContent += line + "\n";
    }
    SaveFile();
}
void EditDocument() {
    cout << "Enter new content (end with a single line containing 'END'):\n";
    string line;
    documentContent.clear();
    cin.ignore(); // Ensure input buffer is cleared
    while (true) {
        getline(cin, line);
        if (line == "END") break;
        documentContent += line + "\n";
    }
    isModified = true;
    cout << "Document edited successfully.\n";
}
void OpenFile() {
    if (isModified) {
        cout << "Do you want to save changes? (yes/no): ";
        string choice;
        cin >> choice;
        cin.ignore();
        if (choice == "yes") SaveFile();
    }
    cout << "Enter file name to open: ";
    getline(cin, filePath);
    ifstream file(filePath);
    if (file) {
        documentContent.assign((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
        isModified = false;
        file.close();
        cout << "File loaded successfully.\n";
        cout << "Current Content:\n" << documentContent << "\n";
        cout << "Do you want to edit the document? (yes/no): ";
        string editChoice;
        cin >> editChoice;
        cin.ignore();
        if (editChoice == "yes") EditDocument();
    }
    else {
        cout << "Failed to open file.\n";
    }
}

void ExitApp() {
    if (isModified) {
        cout << "Do you want to save changes before exiting? (yes/no): ";
        string choice;
        cin >> choice;
        cin.ignore();
        if (choice == "yes") SaveFile();
    }
    cout << "Exiting program...\n";
    exit(0);
}

int main() {
    do {
        int choice;
        while (true) {
            cout << "\nMenu:\n1. New File\n2. Open File\n3. Save File\n4. Edit Document\n5. Exit\nChoose an option: ";
            cin >> choice;
            cin.ignore(); // Clear newline character from buffer

            switch (choice) {
            case 1: NewFile(); break;
            case 2: OpenFile(); break;
            case 3: SaveFile(); break;
            case 4: EditDocument(); break;
            case 5: ExitApp(); break;
            default: cout << "Invalid choice, try again.\n";
            }
        }
    } while (false); {
        cout << "Invalid input";
    }
    return 0;
}
