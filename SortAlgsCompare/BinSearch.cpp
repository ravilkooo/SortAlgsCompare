#include "BinSearch.h"

int binSearch(int* a, int len, int num) {
    int ind;
    int b = 0, e = len - 1;
    int m = (b + e) / 2;
    while (b != e) {
        if (num <= a[m]) {
            e = m;
        }
        else {
            b = m + 1;
        }
        m = (b + e) / 2;
        //printf("(%i,%i)\n", b, e);
    }
    if (num == a[b]) {
        ind = b;
    }
    else {
        ind = -b;
    }
    return ind;
}
