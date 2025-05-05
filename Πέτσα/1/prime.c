#include "mslib.h"
#include <stdio.h>
#include <math.h>


double limit, num, counter;
int prime(double n){
double i;
int result, isPrime;
if(n < 0) result = prime(-n);
else if(n < 2) result = 0;
else if(n == 2) result = 1;
else if((int)n % (int)2 == 0) result = 0;
else{
i = 3;
isPrime = 1;
while(isPrime && (i < n / 2))
{
isPrime = (int)n % (int)i != 0;
i = i + 2;
}

result = isPrime;
}



 return result ;
}
int main() {

limit = readNumber();
counter = 0;
num = 2;
while(num <= limit)
{
if(prime(num)){
counter = counter + 1;
writeNumber(num);
writeString(" ");
}

num = num + 1;
}

writeString("\n");
writeNumber(counter);
} 
