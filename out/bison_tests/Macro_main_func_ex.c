#include "lambdalib.h"
#include <stdbool.h>
#define pi 3.14
int main() {
    float x;
    float y;
    x = 1 + 2;
    y = x * pi;
    if (x > 1) {
        writeStr("x is bigger\n");
    } else {
        writeStr("x is not bigger\n");
    }
    return;
};
