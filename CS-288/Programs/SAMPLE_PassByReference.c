#include <stdio.h>

/*
void func(int a, int b) {
   a += b;
   printf("func: a = %d     b = %d\n", a, b);
}

void main() {
   int x = 5, y = 7;
   func(x, y);
   printf("main: x = %d     y = %d\n", x, y);
}
*/

void func(int *a, int *b) {
   *a += *b;
   printf("func: a = %d     b = %d\n", *a, *b);
}

void main() {
   int x = 5, y = 7;
   func(&x, &y);
   printf("main: x = %d     y = %d\n", x, y);
}