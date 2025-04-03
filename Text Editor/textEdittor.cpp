#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<string> documentContent;
string filePath;
bool isModified = false;

// Load file content into a vector
void OpenFile() {
    cout << "Enter file name to open: ";
    cin >> filePath;
    cin.ignore();

    ifstream file(filePath);
    if (file) {
        documentContent.clear();
        string line;
        while (getline(file, line)) {
            documentContent.push_back(line);
        }
        file.close();
        isModified = false;
        cout << "File loaded successfully.\n";
    }
    else {
        cout << "Failed to open file.\n";
    }
}

// Save the file
void SaveFile() {
    if (filePath.empty()) {
        cout << "Enter file name to save: ";
        cin >> filePath;
    }

    ofstream file(filePath);
    if (file) {
        for (const auto& line : documentContent) {
            file << line << endl;
        }
        file.close();
        isModified = false;
        cout << "File saved successfully.\n";
    }
    else {
        cout << "Error saving file.\n";
    }
}

// Edit the file content live
void EditDocument() {
    if (documentContent.empty()) {
        cout << "No content loaded. Open a file first.\n";
        return;
    }

    int lineNumber;
    string newText;

    while (true) {
        cout << "\n--- Document Content ---\n";
        for (size_t i = 0; i < documentContent.size(); i++) {
            cout << i + 1 << ": " << documentContent[i] << endl;
        }

        cout << "\nEnter line number to edit (or 0 to exit): ";
        cin >> lineNumber;
        cin.ignore();

        if (lineNumber == 0) break;
        if (lineNumber < 1 || lineNumber > documentContent.size()) {
            cout << "Invalid line number.\n";
            continue;
        }

        cout << "Enter new text for line " << lineNumber << ": ";
        getline(cin, newText);
        documentContent[lineNumber - 1] = newText;
        isModified = true;
    }

    // Ask if user wants to save changes
    cout << "Do you want to save the changes? (Y/N): ";
    char choice;
    cin >> choice;
    cin.ignore();
    if (choice == 'Y' || choice == 'y') {
        SaveFile();
    }
}

// View file without editing
void ViewDocument() {
    if (documentContent.empty()) {
        cout << "No content loaded. Open a file first.\n";
        return;
    }

    cout << "\n--- Document Content ---\n";
    for (size_t i = 0; i < documentContent.size(); i++) {
        cout << i + 1 << ": " << documentContent[i] << endl;
    }

    // Ask if user wants to edit
    char choice;
    cout << "\nDo you want to edit this file? (Y/N): ";
    cin >> choice;
    if (choice == 'Y' || choice == 'y') {
        EditDocument();
    }
}

// Main menu
int main() {
    while (true) {
        cout << "\nMenu:\n1. New File\n2. Open File\n3. Exit\nChoose an option: ";
        char choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case '1':
            documentContent.clear();
            filePath = "";
            cout << "Enter new file content (end with 'SUBMIT'):\n";
            {
                string line;
                while (true) {
                    getline(cin, line);
                    if (line == "SUBMIT") break;
                    documentContent.push_back(line);
                }
            }
            SaveFile();
            break;
        case '2':
            OpenFile();
            char subChoice;
            cout << "\nView (V) or Edit (E) the document? ";
            cin >> subChoice;
            cin.ignore();
            if (subChoice == 'V' || subChoice == 'v') {
                ViewDocument();
            }
            else if (subChoice == 'E' || subChoice == 'e') {
                EditDocument();
            }
            else {
                cout << "Invalid choice. Returning to menu.\n";
            }
            break;
        case '3':
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice, try again.\n";
        }
    }
}
