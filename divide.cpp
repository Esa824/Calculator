#include "add.h"
#include "multiply.h"
#include "reverse.h"
#include "subtract.h"
#include "compare.h"
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iterator>
#include <string>
using namespace std;
// -1 if number1 is less than number2 1 if number1
// greater number2
void divide(const char *number1, const char *number2, char *answer) {
  int a = compare(number1, number2);
  if (strlen(number1) > 128) {
    a = -2;
  }
  if (strlen(number2) > 128) {
    a = -2;
  }
  int caries = 0;
  int found = 0;
  int check2 = 0;
  int check = 0;
  int counts = 0;
  int counter = 0;
  int m = -1;
  const char *p = number1;
  const char *o = number2;
  if (*o == '-') {
    check2 = 2;
    o++;
  }
  while (*o != 0) {
    if (*o > '9' && *o < '0') {
      check2 = 1;
    }
    o++;
  }
  if (*p == '-') {
    check = 2;
    p++;
  }
  while (*p != 0) {
    if (*p > '9' && *p < '0') {
      check = 1;
    }
    p++;
  }
  if (a == 0 && check == 0 && check2 == 0) {
    *answer = '1';
  }
  const char *f = number1;
  const char *l = number2;
  char x[128] = {0};
  char *x_ptr = x;
  char *answer_ptr = answer;
  counter = strlen(number1);
  counts = strlen(number2);
  int result_compare = 0;
  if (a == 1 && check == 0 && check2 == 0) {
    char sv[128] = {0};
    char number2_copy[128] = {0};
    char *number2_copy_ptr = number2_copy;
    const char *number2_ptr = number2;
    while (*number2_ptr != 0) {
      *number2_copy_ptr = *number2_ptr;
      number2_copy_ptr++;
      number2_ptr++;
    }
    for (;;) {
      result_compare = compare(x, number2);
      if (result_compare == -1 && found == 0) {
        found = 1;
        char *x_ptr = x;
        while (*x_ptr != 0) {
          x_ptr++;
        }
        *answer_ptr = '0';
        answer_ptr++;
        if (*f != 0) {
          *sv = '0';
          *x_ptr = *f, f++;
          x_ptr++;
          multiply(number2_copy, sv, number2_copy);
          subtract(x, number2_copy, x);
          result_compare = compare(x, number2);
        }
      }
      if (*f == 0 && result_compare == -1) {
        break;
      }
      result_compare = compare(x, number2);
      if (result_compare == 1 && found == 0) {
        char plus[128] = {0};
        found = 1;
        char plus2[128] = {0};
        for (;;) {
          add(plus, number2, plus);
          result_compare = compare(plus, x);
          if (result_compare == 1) {
            break;
          }
          add(plus2, "1", plus2);
        }
        for (;;) {
          char plus3[128] = {0};
          subtract(x, number2, plus3);
          char *x_ptr = x;
          while (*x_ptr != 0) {
            *x_ptr = 0;
            x_ptr++;
          }
          strcpy(x, plus3);
          result_compare = compare(x, number2);
          if (result_compare == -1) {
            break;
          }
        }
        char *x_ptr = x;
        while (*x_ptr != 0) {
          x_ptr++;
        }
        *answer_ptr = *plus2;
        answer_ptr++;
        result_compare = compare(x, number2);
        if (*f == 0 && result_compare == -1) {
          break;
        }
        result_compare = compare(x, number2);
        if (result_compare == 0 || result_compare == 1) {
          break;
        }
        *x_ptr = *f;
        f++;
        x_ptr++;
      }
      if (result_compare == 0 && found == 0) {
        *answer_ptr = '1';
        found = 1;
        answer_ptr++;
        char *s = x;
        while (*s != 0) {
          *s = 0;
          s++;
        }
      }
      found = 0;
    }
    reverse(answer);
    char *answer_ptr = answer;
    while (*answer_ptr != 0) {
      answer_ptr++;
    }
    answer_ptr--;
    while (*answer_ptr == '0') {
      *answer_ptr = 0;
      answer_ptr--;
    }
    reverse(answer);
  }
  if (a == 1 && check == 2 && check2 == 2) {
    char sv[128] = {0};
    char number2_copy[128] = {0};
    char *number2_copy_ptr = number2_copy;
    const char *number2_ptr = number2;
    number2_ptr++;
    while (*number2_ptr != 0) {
      *number2_copy_ptr = *number2_ptr;
      number2_copy_ptr++;
      number2_ptr++;
    }
    char number2_copy_copy[128] = {0};
    char *number2_copy_copy_ptr = number2_copy_copy;
    const char *number2_r_ptr = number2;
    number2_r_ptr++;
    while (*number2_r_ptr != 0) {
      *number2_copy_copy_ptr = *number2_r_ptr;
      number2_copy_copy_ptr++;
      number2_r_ptr++;
    }
    f++;
    for (;;) {
      result_compare = compare(x, number2_copy_copy);
      if (result_compare == -1 && found == 0) {
        found = 1;
        char *x_ptr = x;
        while (*x_ptr != 0) {
          x_ptr++;
        }
        *answer_ptr = '0';
        answer_ptr++;
        if (*f != 0) {
          *sv = '0';
          *x_ptr = *f, f++;
          x_ptr++;
          multiply(number2_copy, sv, number2_copy);
          subtract(x, number2_copy, x);
        }
      }
      result_compare = compare(x, number2_copy_copy);
      if (*f == 0 && result_compare == -1) {
        break;
      }
      if (result_compare == 1 && found == 0) {
        char plus[128] = {0};
        found = 1;
        char plus2[128] = {0};
        for (;;) {
          add(plus, number2_copy_copy, plus);
          result_compare = compare(plus, x);
          if (result_compare == 1) {
            break;
          }
          add(plus2, "1", plus2);
        }
        for (;;) {
          char plus3[128] = {0};
          subtract(x, number2_copy_copy, plus3);
          char *x_ptr = x;
          while (*x_ptr != 0) {
            *x_ptr = 0;
            x_ptr++;
          }
          strcpy(x, plus3);
          result_compare = compare(x, number2_copy_copy);
          if (result_compare == -1) {
            break;
          }
        }
        char *x_ptr = x;
        while (*x_ptr != 0) {
          x_ptr++;
        }
        *answer_ptr = *plus2;
        answer_ptr++;
        result_compare = compare(x, number2_copy_copy);
        if (*f == 0 && result_compare == -1) {
          break;
        }
        *x_ptr = *f;
        f++;
        x_ptr++;
      }
      if (result_compare == 0 && found == 0) {
        *answer_ptr = '1';
        found = 1;
        answer_ptr++;
        char *s = x;
        while (*s != 0) {
          *s = 0;
          s++;
        }
      }
      found = 0;
    }
    reverse(answer);
    char *answer_ptr = answer;
    while (*answer_ptr != 0) {
      answer_ptr++;
    }
    answer_ptr--;
    while (*answer_ptr == '0') {
      *answer_ptr = 0;
      answer_ptr--;
    }
    reverse(answer);
  }
  if (a == 1 && check == 2 && check2 == 0) {
    char sv[128] = {0};
    char number2_copy[128] = {0};
    char *number2_copy_ptr = number2_copy;
    const char *number2_ptr = number2;
    while (*number2_ptr != 0) {
      *number2_copy_ptr = *number2_ptr;
      number2_copy_ptr++;
      number2_ptr++;
    }
    f++;
    for (;;) {
      result_compare = compare(x, number2);
      if (result_compare == -1 && found == 0) {
        found = 1;
        char *x_ptr = x;
        while (*x_ptr != 0) {
          x_ptr++;
        }
        *answer_ptr = '0';
        answer_ptr++;
        if (*f != 0) {
          *sv = '0';
          *x_ptr = *f, f++;
          x_ptr++;
          multiply(number2_copy, sv, number2_copy);
          subtract(x, number2_copy, x);
          result_compare = compare(x, number2);
        }
      }
      if (*f == 0 && result_compare == -1) {
        break;
      }
      result_compare = compare(x, number2);
      if (result_compare == 1 && found == 0) {
        char plus[128] = {0};
        found = 1;
        char plus2[128] = {0};
        for (;;) {
          add(plus, number2, plus);
          result_compare = compare(plus, x);
          if (result_compare == 1) {
            break;
          }
          add(plus2, "1", plus2);
        }
        for (;;) {
          char plus3[128] = {0};
          subtract(x, number2, plus3);
          char *x_ptr = x;
          while (*x_ptr != 0) {
            *x_ptr = 0;
            x_ptr++;
          }
          strcpy(x, plus3);
          result_compare = compare(x, number2);
          if (result_compare == -1) {
            break;
          }
        }
        char *x_ptr = x;
        while (*x_ptr != 0) {
          x_ptr++;
        }
        *answer_ptr = *plus2;
        answer_ptr++;
        result_compare = compare(x, number2);
        if (*f == 0 && result_compare == -1) {
          break;
        }
        result_compare = compare(x, number2);
        if (result_compare == 0 || result_compare == 1) {
          break;
        }
        *x_ptr = *f;
        f++;
        x_ptr++;
      }
      if (result_compare == 0 && found == 0) {
        *answer_ptr = '1';
        found = 1;
        answer_ptr++;
        char *s = x;
        while (*s != 0) {
          *s = 0;
          s++;
        }
      }
      found = 0;
    }
    reverse(answer);
    char *answer_ptr = answer;
    while (*answer_ptr != 0) {
      answer_ptr++;
    }
    answer_ptr--;
    while (*answer_ptr == '0') {
      *answer_ptr = 0;
      answer_ptr--;
    }
    while (*answer_ptr != 0) {
      answer_ptr++;
    }
    *answer_ptr = '-';
    reverse(answer);
  }
  if (a == 1 && check == 0 && check2 == 2) {
    char sv[128] = {0};
    char number2_copy[128] = {0};
    char *number2_copy_ptr = number2_copy;
    const char *number2_ptr = number2;
    number2_ptr++;
    while (*number2_ptr != 0) {
      *number2_copy_ptr = *number2_ptr;
      number2_copy_ptr++;
      number2_ptr++;
    }
    char number2_copy_copy[128] = {0};
    char *number2_copy_copy_ptr = number2_copy_copy;
    const char *number2_r_ptr = number2;
    number2_r_ptr++;
    while (*number2_r_ptr != 0) {
      *number2_copy_copy_ptr = *number2_r_ptr;
      number2_copy_copy_ptr++;
      number2_r_ptr++;
    }
    for (;;) {
      result_compare = compare(x, number2_copy_copy);
      if (result_compare == -1 && found == 0) {
        found = 1;
        char *x_ptr = x;
        while (*x_ptr != 0) {
          x_ptr++;
        }
        *answer_ptr = '0';
        answer_ptr++;
        if (*f != 0) {
          *sv = '0';
          *x_ptr = *f, f++;
          x_ptr++;
          multiply(number2_copy, sv, number2_copy);
          subtract(x, number2_copy, x);
        }
      }
      result_compare = compare(x, number2_copy_copy);
      if (*f == 0 && result_compare == -1) {
        break;
      }
      if (result_compare == 1 && found == 0) {
        char plus[128] = {0};
        found = 1;
        char plus2[128] = {0};
        for (;;) {
          add(plus, number2_copy_copy, plus);
          result_compare = compare(plus, x);
          if (result_compare == 1) {
            break;
          }
          add(plus2, "1", plus2);
        }
        for (;;) {
          char plus3[128] = {0};
          subtract(x, number2_copy_copy, plus3);
          char *x_ptr = x;
          while (*x_ptr != 0) {
            *x_ptr = 0;
            x_ptr++;
          }
          strcpy(x, plus3);
          result_compare = compare(x, number2_copy_copy);
          if (result_compare == -1) {
            break;
          }
        }
        char *x_ptr = x;
        while (*x_ptr != 0) {
          x_ptr++;
        }
        *answer_ptr = *plus2;
        answer_ptr++;
        result_compare = compare(x, number2_copy_copy);
        if (*f == 0 && result_compare == -1) {
          break;
        }
        *x_ptr = *f;
        f++;
        x_ptr++;
      }
      if (result_compare == 0 && found == 0) {
        *answer_ptr = '1';
        found = 1;
        answer_ptr++;
        char *s = x;
        while (*s != 0) {
          *s = 0;
          s++;
        }
      }
      found = 0;
    }
    reverse(answer);
    char *answer_ptr = answer;
    while (*answer_ptr != 0) {
      answer_ptr++;
    }
    answer_ptr--;
    while (*answer_ptr == '0') {
      *answer_ptr = 0;
      answer_ptr--;
    }
    while (*answer_ptr != 0) {
      answer_ptr++;
    }
    *answer_ptr = '-';
    reverse(answer);
  }
}
