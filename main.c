#include "add.h"
#include "divide.h"
#include "multiply.h"
#include "subtract.h"
#include "compare.h"
#include <stdio.h>
#include <string.h>

int main() {
    for (;;) {
        char str1[128] = {0};
        printf("Enter str1: ");
        scanf("%127s", str1);  // Limit input to 127 characters

        char do_what[128] = {0};
        printf("you put: ");
        scanf("%127s", do_what);  // Limit input to 127 characters

        char str2[128] = {0};
        printf("Enter str2: ");
        scanf("%127s", str2);  // Limit input to 127 characters

        char expected_answer[128] = {0};
        if (*do_what == '+') {
            add(str1, str2, expected_answer);
        }
        if (*do_what == '*') {
            multiply(str1, str2, expected_answer);
        }
        if (*do_what == '/') {
            divide(str1, str2, expected_answer);
        }
        if (*do_what == '-') {
            subtract(str1, str2, expected_answer);
        }
        printf("%s\n", expected_answer);
    }
    return 0;
}
