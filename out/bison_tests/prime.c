#include "lambdalib.h"
#include <stdbool.h>
int limit, num, counter;
bool prime(int n) {
    int i;
    bool result, isPrime;
    if (n < 0) {
        result = prime(n);
    } else {
        if (n < 2) {
            result = false;
        } else {
            if (n == 2) {
                result = true;
            } else {
                if (n % 2 == 0) {
                    result = false;
                } else {
                    i = 3;
                    isPrime = true;
                    while (isPrime && i < n / 2) {
                        isPrime = n % i != 0;
                        i = i + 2;
                    }
                    result = isPrime;
                }
            }
        }
    }
    return result;
}
int main() {
    limit = readInteger();
    writeInteger(2);
    writeStr(" ");
    counter = 1;
    /* ERROR */
    writeInteger(num);
    writeStr(" ");
    /* ERROR */
    /* ERROR */
    writeStr("\nThe total number of primes found is:");
    writeInteger(counter);
    writeStr("\n");
};
