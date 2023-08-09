#include <stdio.h>
#include <string.h>

int checkNegative(const char *number) { return (number[0] == '-'); }

void subtract(char *number1, char *number2, char *answer) {
  int len1 = strlen(number1);
  int len2 = strlen(number2);
  int ifnn = checkNegative(number1);
  int isnn = checkNegative(number2);

  int difference = (strlen(number1) > strlen(number2))
                       ? strlen(number1) - strlen(number2)
                       : strlen(number2) - strlen(number1);

  // Skip negative sign when processing
  if (ifnn)
    number1++;
  if (isnn)
    number2++;

  int i;
  for (i = len1 - 1; i >= 0; i--) {
    int digitDifference;
    if (number1[i] >= number2[i - difference]) {
      digitDifference = (number1[i] - '0') - (number2[i - difference] - '0');
    } else {
      int j = i - 1;
      while (number1[j] == '0' && j >= 0) {
        j--;
      }
      number1[j]--;
      digitDifference = (number1[i] - '0' + 10) - (number2[i - difference] - '0');
    }
    answer[i] = digitDifference + '0';
  }

  // Apply negative sign if needed
  if (ifnn || isnn) {
    memmove(answer + 1, answer, len1);
    answer[0] = '-';
  }
  answer[len1] = '\0'; // Null-terminate the string
}

