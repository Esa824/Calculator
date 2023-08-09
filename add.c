#include <stdio.h>
#include <string.h>

int checkNegative(const char *number) { return (number[0] == '-'); }

int hasDecimal(const char *number) {
  while (*number) {
    if (*number == '.') {
      return 1; // Decimal point found
    }
    number++;
  }
  return 0; // No decimal point found
}

void add(const char *number1, const char *number2, char *answer) {
  int ifnn = checkNegative(number1);
  int isnn = checkNegative(number2);
  int dfnhd = hasDecimal(number1);
  int dsnhd = hasDecimal(number2);

  int N =
      (strlen(number1) > strlen(number2)) ? strlen(number1) : strlen(number2);
  int difference = (strlen(number1) > strlen(number2))
                       ? strlen(number1) - strlen(number2)
                       : strlen(number2) - strlen(number1);

  int carry = 0;
  int i;
  for (i = N - 1; i >= 0; i--) {
    if (number1[i] == '.' || number2[i - difference] == '.') {
      answer[i] = '.';
      if ((dfnhd && !dsnhd) || (!dfnhd && dsnhd)) {
        difference -= N - i;
      }
      dfnhd = 0;
      dsnhd = 0;
      continue;
    }

    int sum = 0;
    if ((i - difference) < 0 || number2[i - difference] == '-' ||
        (dfnhd && !dsnhd)) {
      sum = (number1[i] - '0') + carry;
    } else if (dsnhd && !dfnhd) {
      sum = (number2[i] - '0') + carry;
    } else {
      sum = (number1[i] - '0') + (number2[i - difference] - '0') + carry;
    }

    if (sum >= 10) {
      carry = 1;
      sum %= 10;
    } else {
      carry = 0;
    }

    answer[i] = sum + '0';
  }

  if (carry == 1) {
    answer[N + 1] = '\0';
    answer[0] = '1';
  } else {
    answer[N] = '\0';
  }

  if (ifnn == 1 || isnn == 1) {
    memmove(answer + 1, answer, strlen(answer) + 1);
    answer[0] = '-';
  }
}

