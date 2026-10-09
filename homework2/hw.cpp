#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <list>
#include <deque>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int M = 13;
const int N = 3000;

float f(int x, int k) {
    return sqrt(abs(x) + abs(k));
}

int rnd() {
    return rand() % (2 * N + 1) - N;
}

int main() {
    srand(time(0));

    array<int, M> a;
    vector<int> v(M);
    list<int> l(M);
    deque<int> d(M);

    int k = rnd();
    cout << "k = " << k << endl;

    for (int i = 0; i < M; i++) a[i] = rnd();
    for (auto it = v.begin(); it != v.end(); it++) *it = rnd();
    for (auto &x : l) x = rnd();
    for (int i = 0; i < M; i++) d[i] = rnd();

    vector<float> ra(M);
    list<float> rv(M);
    deque<float> rl(M);
    array<float, M> rd;

    for (int i = 0; i < M; i++) ra[i] = f(a[i], k);

    auto irv = rv.begin();
    for (auto x : v) {
        *irv = f(x, k);
        irv++;
    }

    auto il = l.begin();
    auto irl = rl.begin();
    for (; il != l.end(); il++, irl++) *irl = f(*il, k);

    for (int i = 0; i < M; i++) rd[i] = f(d[i], k);

    ofstream fout("result.txt");

    auto p1 = a.begin();
    auto p2 = v.begin();
    auto p3 = l.begin();
    auto p4 = d.begin();
    auto q1 = ra.begin();
    auto q2 = rv.begin();
    auto q3 = rl.begin();
    auto q4 = rd.begin();

    for (int i = 0; i < M; i++) {
        fout << i + 1 << " " << *p1++ << " " << *p2++ << " " << *p3++ << " " << *p4++
             << " " << *q1++ << " " << *q2++ << " " << *q3++ << " " << *q4++ << endl;
    }

    fout.close();

    cout << "готово" << endl;
    return 0;
}