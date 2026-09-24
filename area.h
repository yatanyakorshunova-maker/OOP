#ifndef AREA_H
#define AREA_H

#include <random>

namespace just {
    template <typename Ret, typename T>
    Ret area(const T& a, const T& b) {
        return static_cast<Ret>(a * b);
    }
}

namespace Modify {
    template <typename Ret, typename T>
    Ret area(const T& a, const T& b) {
        Ret s = a * b;
        int monetka = std::random_device{}() % 2;
        if (monetka == 0) {
            int rand_num = std::random_device{}() % 100 + 1;
            return static_cast<Ret>(s + rand_num); }
        else {
            return s;
        }
    }
}

#endif