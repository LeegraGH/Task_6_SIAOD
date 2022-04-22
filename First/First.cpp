#include <iostream>
#include <string>
#include "Windows.h"

// Дана строка. Выполнить переворот строки(записать наоборот) на ее же месте в памяти.

using namespace std;

void turnOver(string& text, int& first, int& last)
{
    if (size(text) == 1 || size(text) == 0) return;
    swap(text[first], text[last]);
    first += 1;
    last -= 1;
    if ((first == last) || (first > last)) return;
    else turnOver(text, first, last);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Rus");
    string text;
    cout << "Введите текст: ";
    getline(cin, text);
    int first = 0, last = size(text) - 1;
    turnOver(text, first, last);
    cout << "Текст наоборот: " << text;
    return 0;
}