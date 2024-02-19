/*
 * Background and foreground processes
   - this example shows how program execution can be paused and put to background,
     and later on can be continued
   - execution steps:
     1. Open terminal
     2. Run the binary
     3. Pause (stop) the program execution (foreground process) and put it to background
       - execute 'Ctrl + z' in terminal
     4. Continue the program execution i.e. put the program back to foreground
       - execute 'fg' in terminal
     5. Input a number
   - process is put to:
     - background - via 'Ctrl + z'
     - foreground - via 'fg'
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