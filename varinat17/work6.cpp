#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <cctype>

using namespace std;

// ===================== ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ =====================

int inputInt(const string& text, int minValue, int maxValue) {
    int x;

    while (true) {
        cout << text;
        cin >> x;

        if (!cin.fail() && x >= minValue && x <= maxValue) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return x;
        }

        cout << "Ошибка ввода! Введите число от "
             << minValue << " до " << maxValue << ".\n";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// ===================== ЗАДАНИЕ 1 =====================
// Вводится строка произвольного текста.
// Заменить все строчные буквы на первую цифру их ASCII-кода.
// Если в строке нет строчных букв, оставить строку без изменений.
// Копаленко Никитка

void task1() {
    cout << "\n========== Задание 1 ==========\n";
    cout << "Замена строчных букв на первую цифру их ASCII-кода.\n\n";

    string s;

    cout << "Введите строку:\n";
    getline(cin, s);

    bool hasLower = false;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            hasLower = true;

            int code = static_cast<int>(s[i]);

            while (code >= 10) {
                code /= 10;
            }

            s[i] = static_cast<char>('0' + code);
        }
    }

    cout << "\nПреобразованная строка:\n";
    cout << s << endl;

    if (!hasLower) {
        cout << "\nСтрочных английских букв в строке не было, строка не изменилась.\n";
    }
}

// ===================== ЗАДАНИЕ 2 =====================
// Вводится строка произвольного текста.
// Удалить в этой строке заданную букву.
// Вывести преобразованную строку.

void task2() {
    cout << "\n========== Задание 2 ==========\n";
    cout << "Удаление заданной буквы из строки.\n\n";

    string s;
    char letter;

    cout << "Введите строку:\n";
    getline(cin, s);

    cout << "Введите букву, которую нужно удалить: ";
    cin >> letter;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = "";

    for (int i = 0; i < s.length(); i++) {
        if (s[i] != letter) {
            result += s[i];
        }
    }

    cout << "\nПреобразованная строка:\n";
    cout << result << endl;
}

// ===================== ЗАДАНИЕ 3 =====================
// Вводится строка символов.
// Определить количество букв в среднем слове,
// предполагая, что количество слов во вводимой строке нечетное.

void task3() {
    cout << "\n========== Задание 3 ==========\n";
    cout << "Определение количества букв в среднем слове.\n\n";

    string s;

    cout << "Введите строку:\n";
    getline(cin, s);

    vector<string> words;
    string word = "";

    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ') {
            word += s[i];
        } else {
            if (word != "") {
                words.push_back(word);
                word = "";
            }
        }
    }

    if (word != "") {
        words.push_back(word);
    }

    if (words.empty()) {
        cout << "\nВ строке нет слов.\n";
        return;
    }

    if (words.size() % 2 == 0) {
        cout << "\nКоличество слов чётное. По условию количество слов должно быть нечётным.\n";
        return;
    }

    int middleIndex = words.size() / 2;
    int lettersCount = 0;

    for (int i = 0; i < words[middleIndex].length(); i++) {
        if (isalpha(static_cast<unsigned char>(words[middleIndex][i]))) {
            lettersCount++;
        }
    }

    cout << "\nСреднее слово: " << words[middleIndex] << endl;
    cout << "Количество букв в среднем слове: " << lettersCount << endl;
}

// ===================== ЗАДАНИЕ 4 =====================
// Вводится строка символов, разделённых на слова.
// Пробелы являются разделителями между словами.
// Слова могут разделяться несколькими пробелами.
// В начале и конце строки пробелы также допускаются.
// Вывести на экран все слова.

void task4() {
    cout << "\n========== Задание 4 ==========\n";
    cout << "Вывод всех слов из строки.\n\n";

    string s;

    cout << "Введите строку:\n";
    getline(cin, s);

    cout << "\nСлова в строке:\n";

    string word = "";
    bool hasWords = false;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ') {
            word += s[i];
        } else {
            if (word != "") {
                cout << word << endl;
                hasWords = true;
                word = "";
            }
        }
    }

    if (word != "") {
        cout << word << endl;
        hasWords = true;
    }

    if (!hasWords) {
        cout << "Слов нет.\n";
    }
}

// ===================== ГЛАВНОЕ МЕНЮ =====================

int main() {
    setlocale(LC_ALL, "Russian");

    int choice;

    do {
        cout << "\n========================================\n";
        cout << "              РАБОТА 6\n";
        cout << "========================================\n";
        cout << "1 — Задание 1\n";
        cout << "2 — Задание 2\n";
        cout << "3 — Задание 3\n";
        cout << "4 — Задание 4\n";
        cout << "0 — Выход\n";

        choice = inputInt("Выберите пункт меню: ", 0, 4);

        switch (choice) {
            case 1:
                task1();
                break;

            case 2:
                task2();
                break;

            case 3:
                task3();
                break;

            case 4:
                task4();
                break;

            case 0:
                cout << "\nВыход из программы.\n";
                break;
        }

    } while (choice != 0);

    return 0;
}