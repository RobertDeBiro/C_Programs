/*
 * Background and foreground processes
 *  - this example must be run from terminal
 *      - run the binary, then type "Ctrl+z", then type "fg" and input a number
 *  - bringing the process to the background actually means stopping the process
 *  - process is put to:
 *      - background - via Ctrl + z
 *      - foreground - via fg
 */

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    printf("************************************************\n");

    int x;
    printf("Input number: ");
    scanf("%d", &x);
    printf("Result %d * 5 = %d\n", x, x * 5);

    printf("-----------------------------------------\n");
    return 0;
}