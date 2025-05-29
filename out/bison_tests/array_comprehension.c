#include "lambdalib.h"
#include <stdbool.h>
const int N = 100;
int a[100];
int main() {
    for (int i = 0; i < N; i++) {
    	a[i] = i;
    
    }
    float* half = (float*)malloc(100 * sizeof(float));
    for (int x = 0; x < 100; ++x) {
        half[x] = x / 2;
    }
};
