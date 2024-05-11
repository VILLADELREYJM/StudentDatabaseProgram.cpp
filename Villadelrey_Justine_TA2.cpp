#include <iostream>
using namespace std;


int string_length(char *str) {
    char *ptr = str;
    while (*ptr != '\0') {
        ptr++;
    }
    return ptr - str;
}

int string_compare(char *s1, char *s2) {
    while (*s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

void string_concatenate(char *s1, char *s2) {
    while (*s1) {
        s1++;
    }
    while (*s2) {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
}

void formatMenu() {
    cout <<" -------------------------------- "<< endl;
    cout << "    What do you want to do?\n";
    cout << "--------------------------------"<< endl;
    cout << "1. Find the string length\n";
    cout << "2. Compare two strings\n";
    cout << "3. Concatenate two strings\n";
    cout << "4. Exit\n";
    cout << "\nEnter your choice: ";
}

int main() {
    char choice;
    do {
        formatMenu();
        cin >> choice;

        switch (choice) {
            case '1': {
                char str[100];
                cout << "Enter a string: ";
                cin.ignore(); 
                cin.getline(str, 100);
                int length = string_length(str);
                cout << "\nLength of the string is:" << length << endl;
                break;
            }
            case '2': {
                char str1[100], str2[100];
                cout << "Enter the first string: ";
                cin.ignore(); 
                cin.getline(str1, 100);
                cout << "Enter the second string: ";
                cin.getline(str2, 100);
                int result = string_compare(str1, str2);
                if (result == 0) {
                    cout << "Both strings are equal.\n";
                } else if (result < 0) {
                    cout << "The first string is smaller.\n";
                } else {
                    cout << "The first string is larger.\n";
                }
                break;
            }
            case '3': {
                char str1[100], str2[100];
                cout << "Enter the first string: ";
                cin.ignore(); 
                cin.getline(str1, 100);
                cout << "Enter the second string: ";
                cin.getline(str2, 100);
                string_concatenate(str1, str2);
                cout << "Concatenated string: " << str1 << endl;
                break;
            }
            case '4':
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

        cout << "\nTry again? [Y/N] ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    return 0;
}
