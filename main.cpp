#include <iostream>
#include <fstream>
#include <string.h>
#include <string>

using namespace std;

int main() {

    int wordsf = 0;

    string nfile;

    cout << "File directory(example C:\\file.txt): ";

    cin >> nfile;

    ifstream f;
    f.open(nfile, ios::in);

    if (!f.is_open()) // если файл не открыт
        cout << "There is no file in the directory, error\n"; // сообщить об этом
    else
    {
        cout << "File is open" << endl;
        string s;

        while (!f.eof()) {
            getline(f, s, ' ');
            wordsf++;
        }

        cout << "Words n: " << wordsf;
    }

    system("pause");
    return 0;
}