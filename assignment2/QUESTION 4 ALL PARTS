#include <iostream>
#include <string>
using namespace std;

int main() {
    // a part
    char str1[100], str2[100], result[200];
    int i = 0, j = 0;
    cout<<" enter two strings "<< endl ;
    cin >> str1;
    cin >> str2;

    while (str1[i] != '\0') {
        result[i] = str1[i];
        i++;
    }
    j = 0;
    while (str2[j] != '\0') {
        result[i] = str2[j];
        i++;
        j++;
    }
    result[i] = '\0';
    cout << "the answer is " << result << endl;

    // b part
    string str;
    cout << "Enter a string: " << endl;
    cin >> str;

    int n = str.length();
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }

    cout << "Reversed string: " << endl;
    cout << str << endl;

    // c part
    string s, resultStr = "";
    cout << "Enter a string: ";
    cin.ignore();
    getline(cin, s);

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' &&
            c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U') {
            resultStr += c;
        }
    }

    cout << "String after deleting vowels: " << resultStr << endl;

    // d part
    int m;
    cout << "Enter number of strings: ";
    cin >> m;
    cin.ignore();

    string arr[100];
    cout << "Enter strings: " << endl;
    for (int i = 0; i < m; i++) {
        getline(cin, arr[i]);
    }

    for (int i = 0; i < m - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            if (arr[i] > arr[j]) {
                string temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    cout << "Strings in alphabetical order: " << endl;
    for (int i = 0; i < m; i++) {
        cout << arr[i] << endl;
    }

    // e part
    char ch;
    cout << "Enter an uppercase character: ";
    cin >> ch;

    if (ch >= 'A' && ch <= 'Z') {
        ch = ch + 32;
        cout << "Lowercase: " << ch << endl;
    } else {
        cout << "Not an uppercase character." << endl;
    }

    return 0;
}
