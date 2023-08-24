#include <stdio.h>

void custom_init(void) __attribute__ ((constructor));

/**
 * custom_init - prints a custom message before the main function is executed
 */
void custom_init(void)
{
    printf("This is a custom initialization message.\n");
    printf("Before the main function starts running.\n");
}
