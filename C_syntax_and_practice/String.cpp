#include <stdio.h>
#include <cstring>

int main(int argc, char *argv[])
{
    printf("***************************************\n");

    // Print several lines in one printf
    int value = 5;
    printf("+LOG: %d\n\r%s\n", value, "OK");

    printf("-------------------------\n");

    // Define string that contains several lines
    // "/" character is not considered as part of the string
    const char* msg{ "\n+PERIOD: 12345\n\rOK\n\r" };
    printf("Msg length: %d\n", strlen(msg));

    printf("-------------------------\n");

    // Check how many digits are inside number by using snprintf
    int num1 = 12345;
    int length1 = snprintf( NULL, 0, "%d", num1 );
    printf("Amount of digits = %d\n", length1);

    printf("-------------------------\n");

    // Check the size of C-style string symbolic constant
    //  - the size in this case is actually only the size of a pointer
    const char* msg2{ "123456789" };
    printf("Msg size: %d\n", sizeof(msg2));
    printf("Msg length: %d\n", strlen(msg2));

    printf("-------------------------\n");

    // Check the size of C-style string
    //  - compiler adds null terminator at the end
    //  - hence, the lenght is always (size - 1)
    const char msg3[]{ "123456789" };
    printf("Msg size: %d\n", sizeof(msg3));
    printf("Msg length: %d\n", strlen(msg3));

    printf("-------------------------\n");

    int num2 = 59;
    int length2 = snprintf( NULL, 0, "%X", num2 );
    printf("Amount of HEX digits = %d\n", length2);

    printf("***************************************\n");
    return 0;
}