#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>

using namespace std;

// читает все числа из файла в вектор (запятые и переносы = разделители)
vector<int> readFile(const string& name) {
    ifstream f(name);
    vector<int> v;
    string line;
    while (getline(f, line)) {
        for (char& c : line) {
            if (c == ',') c = ' ';
        }
        istringstream iss(line);
        int x;
        while (iss >> x) v.push_back(x);
    }
    return v;
}

// выводит частоты: "число: количество"
void printFreq(const map<int, int>& freq) {
    for (auto [num, cnt] : freq) {
        cout << num << ": " << cnt << endl;
    }
}

// собирает числа, встречающиеся не меньше minCount раз
vector<int> filterByFreq(const map<int, int>& freq, int minCount) {
    vector<int> res;
    for (auto [num, cnt] : freq) {
        if (cnt >= minCount) res.push_back(num);
    }
    return res;
}

int main() {
    // чтение
    vector<int> v1 = readFile("s04_v1_43_1.txt");
    vector<int> v2 = readFile("s04_v1_43_2.txt");

    // больший вектор — первый
    if (v1.size() < v2.size()) swap(v1, v2);

    cout << "1: размер " << v1.size() << endl;
    cout << "2: размер " << v2.size() << endl;
    cout << endl;

    // 3. сколько раз встречается
    // а
    map<int, int> freq1, freq2;
    for (int x : v1) freq1[x]++;
    for (int x : v2) freq2[x]++;

    // б
    vector<int> uniq1 = v1, uniq2 = v2;
    sort(uniq1.begin(), uniq1.end());
    sort(uniq2.begin(), uniq2.end());
    uniq1.erase(unique(uniq1.begin(), uniq1.end()), uniq1.end());
    uniq2.erase(unique(uniq2.begin(), uniq2.end()), uniq2.end());

    map<int, int> freq1_alg, freq2_alg;
    for (int x : uniq1) freq1_alg[x] = count(v1.begin(), v1.end(), x);
    for (int x : uniq2) freq2_alg[x] = count(v2.begin(), v2.end(), x);

    cout << "1 (а):" << endl;
    printFreq(freq1);
    cout << "1 (б):" << endl;
    printFreq(freq1_alg);
    cout << endl;

    cout << "2 (а):" << endl;
    printFreq(freq2);
    cout << "2 (б):" << endl;
    printFreq(freq2_alg);
    cout << endl;

    // 4. Сумма всех значений
    // а
    int sum1_a = accumulate(v1.begin(), v1.end(), 0);
    int sum2_a = accumulate(v2.begin(), v2.end(), 0);

    // б
    int sum1_b = 0, sum2_b = 0;
    for_each(v1.begin(), v1.end(), [&](int x) { sum1_b += x; });
    for_each(v2.begin(), v2.end(), [&](int x) { sum2_b += x; });

    cout << "1: сумма (а) = " << sum1_a
         << ", (б) = " << sum1_b << endl;
    cout << "2: сумма (а) = " << sum2_a
         << ", (б) = " << sum2_b << endl;
    cout << endl;

    // 5. Сумма первых 10 элементов
    int sum10_1 = accumulate(v1.begin(), v1.begin() + min<size_t>(v1.size(), 10), 0);
    int sum10_2 = accumulate(v2.begin(), v2.begin() + min<size_t>(v2.size(), 10), 0);
    cout << "1: сумма первых 10 = " << sum10_1 << endl;
    cout << "2: сумма первых 10 = " << sum10_2 << endl;
    cout << endl;

    // дз

    // 1. Бинарная операция
    int mult1 = accumulate(v1.begin(), v1.end(), 1, multiplies<int>());
    int mult2 = accumulate(v2.begin(), v2.end(), 1, multiplies<int>());
    cout << "1: произведение " << mult1 << endl;
    cout << "2: произведение " << mult2 << endl;
    cout << endl;

    // 2. Числа во втором >= 2 раз и в первом > 3 раз
    vector<int> dup2 = filterByFreq(freq2, 2);
    vector<int> dup1 = filterByFreq(freq1, 4); // > 3 == >= 4

    cout << "2 (>= 2 раз): ";
    for (int x : dup2) cout << x << " ";
    cout << endl;

    cout << "1 (> 3 раз): ";
    for (int x : dup1) cout << x << " ";
    cout << endl;
    cout << endl;

    // 3. Общие числа (1: > 3 раз, 2: >= 2 раз)
    // а
    cout << "3 (а):" << endl;
    for (int num : dup1) {
        bool est = false;
        for (int y : dup2) if (y == num) { est = true; break; }
        if (est) {
            int c1 = 0, c2 = 0;
            for (int x : v1) if (x == num) c1++;
            for (int x : v2) if (x == num) c2++;
            cout << num << ": 1 = " << c1 << ", 2 = " << c2 << endl;
        }
    }
    cout << endl;

    // б
    cout << "3 (б):" << endl;
    for_each(dup1.begin(), dup1.end(), [&](int num) {
        if (find(dup2.begin(), dup2.end(), num) == dup2.end()) return;
        int c1 = count(v1.begin(), v1.end(), num);
        int c2 = count(v2.begin(), v2.end(), num);
        cout << num << ": 1 = " << c1 << ", 2 = " << c2 << endl;
    });

    return 0;
}