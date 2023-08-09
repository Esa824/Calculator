#include <stdio.h>
#include <string.h>

int checkNegative(const char *number) { return (number[0] == '-'); }

void multiply(const char *number1, const char *number2, char *answer) {
  int len1 = strlen(number1);
  int len2 = strlen(number2);
  int ifnn = checkNegative(number1);
  int isnn = checkNegative(number2);
  int totalLen = len1 + len2;

  // Initialize the answer as 0
  for (int i = 0; i < totalLen; i++) {
    answer[i] = '0';
  }
  answer[totalLen] = '\0';

  for (int i = len2 - 1; i >= 0; i--) {
    int carry = 0;
    for (int j = len1 - 1; j >= 0; j--) {
      if (number1[j] == '.') {
        continue;
      }
      int product = (number1[j] - '0') * (number2[i] - '0') + carry +
                    (answer[i + j + 1] - '0');
      carry = product / 10;
      answer[i + j + 1] = (product % 10) + '0';
    }
    answer[i] += carry;
  }
}

