//
// Created by tiit on 08.04.2016.
//

#include "modern.h"

auto sq(int n);

auto sq(int n)
{
    return n * n;
}


int modern(int x, int y) {
    int aval = 7;
    int bval = 8;
    auto c = aval + bval;
    int arr[] = {6, 1, 2, 3, 4};
    for (auto i : arr)
    {
        c += sq(i + x);
    }
    return c + y;
}
