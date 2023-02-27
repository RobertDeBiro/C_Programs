// Background and foreground processes
// - this example must be run from terminal
// - bringing the process to the backgroung actually means stopping the process
// - process is put to:
//    - background - via Ctrl + z
//    - foregroung - via fg

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    int x;
    printf("Input number: ");
    scanf("%d", &x);
    printf("Result %d * 5 = %d\n", x, x * 5);
    return 0;
}