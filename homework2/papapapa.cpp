#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

int main(){
    const int M=13;
    const int N=3000;

    // ===== Задание 1: указатель на одно значение и на массив =====
    int* s = new int(42);
    std::cout << *s << "\n";

    int* arr = new int[M];
    float* arr1 = new float[N];

    std::srand(std::time(nullptr));
    for(int i=0; i<M; i++) arr[i] = std::rand()%100;
    for(int i=0; i<N; i++) arr1[i] = (std::rand()%1000)/10.0f;

    std::cout << "arr: ";
    for(int i=0; i<M; i++) std::cout << arr[i] << " ";
    std::cout << "\n";

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "arr1 (first 10): ";
    for(int i=0; i<10; i++) std::cout << arr1[i] << " ";
    std::cout << "\n";

    // ===== Задание 2: висячий указатель =====
    int* p1 = new int(99);
    int* p2 = p1;
    delete p1;
    p1 = nullptr;
    std::cout << "p2 dangling\n";

    // ===== Задание 3: вставка в середину arr =====
    int size = M;
    int pos = size/2;
    int val = 777;

    int* newArr = new int[size+1];
    for(int i=0; i<pos; i++) newArr[i] = arr[i];
    newArr[pos] = val;
    for(int i=pos; i<size; i++) newArr[i+1] = arr[i];

    delete[] arr;
    arr = newArr;
    size++;

    std::cout << "arr after insert: ";
    for(int i=0; i<size; i++) std::cout << arr[i] << " ";
    std::cout << "\n";

    // ===== Задание 4: очистка памяти =====
    delete s;      s = nullptr;
    delete[] arr;  arr = nullptr;
    delete[] arr1; arr1 = nullptr;

    return 0;
}