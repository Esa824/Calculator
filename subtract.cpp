#include "compare.h"
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

void reverse(char *result) {
  int count = 0;
  char result2[128] = {0};
  char *a = result2;
  while (*result != 0) {
    result++;
    count++;
  }
  result -= count;
  for (int i = 0; i < count; i++) {
    *a = *result;
    result++;
    a++;
  }
  result -= count;
  a--;
  for (int i = 0; i < count; i++) {
    *result = *a;

    a--;
    result++;
  }
  result -= count;
}
void add(const char *number1, const char *number2, char *answer) {
  int a = compare(number1, number2);
  char A[128] = {0};
  strcpy(A, number1);
  char *S = A;
  while (*S != 0) {
    S++;
  }
  S--;
  char Q[128] = {0};
  strcpy(Q, number2);
  char *D = Q;
  while (*D != 0) {
    D++;
  }
  D--;
  int caries = 0;
  int pluser2 = 0;
  int found = 0;
  int count = 0;
  int check2 = 0;
  int check = 0;
  int found_two = 0;
  int counts = 0;
  int counter = 0;
  int m = -1;
  const char *p = number1;
  const char *o = number2;
  char *answer_ptr = answer;
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
  const char *b = A;
  const char *f = A;
  const char *d = Q;
  const char *l = Q;
  while (*f != 0) {
    f++;
  }
  while (*l != 0) {
    l++;
  }
  int number = 10;
  f--;
  l--;
  if (a == 1 && check == 0 && check2 == 0) {
    while (*b != 0) {
      b++;
      counts++;
    }
    while (*d != 0) {
      d++;
      counter++;
    }
    for (int i = 0; i < counts; i++) {
      m++;
      int fer = 0;
      if (found_two == 0) {
        fer = *f;
      }
      fer += caries;
      if (m < counter) {
        fer += *l;
        l--;
      }
      if (found_two == 0) {
        if (m >= counter) {
          fer -= 48;
        }
      }
      if (m < counter) {
        fer -= 96;
      }
      int fere = fer;
      fer %= 10;
      char t = fer + 48;
      *answer_ptr = t;
      f--;
      answer_ptr++;
      fere /= 10;
      caries = fere;
      if (caries > 0 && i == counts - 1) {
        found_two = 1;
        counts++;
      }
    }
    reverse(answer);
  }
  if (a == -1 && check == 0 && check2 == 0) {
    while (*b != 0) {
      b++;
      counts++;
    }
    while (*d != 0) {
      d++;
      counter++;
    }
    for (int i = 0; i < counter; i++) {
      m++;
      int fer = 0;
      if (found_two == 0) {
        fer = *l;
      }
      fer += caries;
      if (m < counts) {
        fer += *f;
        f--;
      }
      if (found_two == 0) {
        if (m >= counts) {
          fer -= 48;
        }
      }
      if (m < counts) {
        fer -= 96;
      }
      int fere = fer;
      fer %= 10;
      char t = fer + 48;
      *answer_ptr = t;
      l--;
      answer_ptr++;
      fere /= 10;
      caries = fere;
      if (caries > 0 && i == counter - 1) {
        found_two = 1;
        counts++;
      }
    }
    reverse(answer);
  }
  if (a == -1 && check == 2 && check2 == 2) {
    while (*b != 0) {
      b++;
      counts++;
    }
    while (*d != 0) {
      d++;
      counter++;
    }

    for (int i = 0; i < counter - 1; i++) {
      m++;
      int fer = *l;
      fer += caries;
      if (m < counts - 1) {
        fer += *f;
        f--;
      }
      if (m >= counts - 1) {
        fer -= 48;
      }
      if (m < counts - 1) {
        fer -= 96;
      }
      int fere = fer;
      fer %= 10;
      char t = fer + 48;
      *answer_ptr = t;
      l--;
      answer_ptr++;
      fere /= 10;
      if (caries > 0 && i == counter - 2) {
        found_two = 1;
        answer++;
        counts++;
      }
      caries = fere;
    }
    char *u = answer;
    while (*u != 0) {
      u++;
    }
    *u = '-';
    reverse(answer);
  }
  if (a == 1 && check == 2 && check2 == 2) {
    while (*b != 0) {
      b++;
      counts++;
    }
    while (*d != 0) {
      d++;
      counter++;
    }
    for (int i = 0; i < counter - 1; i++) {
      m++;
      int fer = *f;
      fer += caries;
      if (m < counts - 1) {
        fer += *l;
        l--;
      }
      if (m >= counts - 1) {
        fer -= 48;
      }
      if (m < counts - 1) {
        fer -= 96;
      }
      int fere = fer;
      fer %= 10;
      char t = fer + 48;
      *answer_ptr = t;
      f--;
      answer_ptr++;
      fere /= 10;
      caries += fere;
      if (caries > 0 && i == counter - 2) {
        found_two = 1;
        counts++;
      }
    }
    char *u = answer;
    while (*u != 0) {
      u++;
    }
    *u = '-';
    reverse(answer);
  }
  if (a == 1 && check == 2 && check2 == 0) {
    while (*b != 0) {
      b++;
      counts++;
    }
    while (*d != 0) {
      d++;
      counter++;
    }
    for (int i = 0; i < counts - 1; i++) {
      m++;
      int fer = *f;
      if (m < counter) {
        if (*f >= *l) {
          int ferr = *l;
          fer -= ferr;
        }
        if (*l > *f) {
          S--;
          while (*S == '0') {
            S--;
            count++;
          }
          int T = *S;
          T -= 48;
          T--;
          char B = T + 48;
          *S = B;
          S++;
          for (int i = 0; i < count + 1; i++) {
            if (i != count) {
              *S = '9';
              S++;
            }
            if (i == count) {
              fer -= 48;
              fer += 10;
              int fere = *l;
              fere -= 48;
              fer -= fere;
            }
          }
        }
      }
      if (m >= counter) {
        fer -= 48;
      }
      if (i == counts - 2 && fer != 0) {
        char L = fer + 48;
        *answer_ptr = L;
      }
      if (i != counts - 2) {
        char L = fer + 48;
        *answer_ptr = L;
        answer_ptr++;
      }
      f--;
      l--;
      S--;
    }
    char *u = answer;
    while (*u != 0) {
      u++;
    }
    *u = '-';
    reverse(answer);
  }
  if (a == -1 && check == 2 && check2 == 0) {
    while (*b != 0) {
      b++;
      counts++;
    }
    while (*d != 0) {
      d++;
      counter++;
    }
    for (int i = 0; i < counter; i++) {
      m++;
      int fer = *l;
      if (m < counts - 1) {
        if (*l >= *f) {
          int ferr = *f;
          fer -= ferr;
        }
        if (*f > *l) {
          D--;
          while (*D == '0') {
            D--;
            count++;
          }
          int T = *D;
          T -= 48;
          T--;
          char B = T + 48;
          *D = B;
          D++;
          for (int i = 0; i < count + 1; i++) {
            if (i != count) {
              *D = '9';
              D++;
            }
            if (i == count) {
              fer -= 48;
              fer += 10;
              int fere = *f;
              fere -= 48;
              fer -= fere;
            }
          }
        }
      }
      if (m >= counts - 1) {
        fer -= 48;
      }
      if (i == counter - 1 && fer != 0) {
        char L = fer + 48;
        *answer = L;
      }
      if (i != counter - 1) {
        char L = fer + 48;
        *answer = L;
        answer++;
      }
      f--;
      l--;
      D--;
    }
    answer -= counter;
    answer++;
    reverse(answer);
  }
  if (a == -1 && check == 0 && check2 == 2) {
    while (*b != 0) {
      b++;
      counts++;
    }
    while (*d != 0) {
      d++;
      counter++;
    }
    for (int i = 0; i < counter - 1; i++) {
      m++;
      int fer = *l;
      if (m < counts) {
        if (*l >= *f) {
          int ferr = *f;
          fer -= ferr;
        }
        if (*f > *l) {
          D--;
          while (*D == '0') {
            D--;
            count++;
          }
          int T = *D;
          T -= 48;
          T--;
          char B = T + 48;
          *D = B;
          D++;
          for (int i = 0; i < count + 1; i++) {
            if (i != count) {
              *D = '9';
              D++;
            }
            if (i == count) {
              fer -= 48;
              fer += 10;
              int fere = *f;
              fere -= 48;
              fer -= fere;
            }
          }
        }
      }
      if (m >= counts) {
        fer -= 48;
      }
      if (i == counter - 2 && fer != 0) {
        char L = fer + 48;
        *answer = L;
      }
      if (i != counter - 2) {
        char L = fer + 48;
        *answer = L;
        answer++;
      }
      f--;
      l--;
      D--;
    }
    *answer = '-';
    answer -= counter;
    answer += 2;
    reverse(answer);
  }
  if (a == 1 && check == 0 && check2 == 2) {
    while (*b != 0) {
      b++;
      counts++;
    }
    while (*d != 0) {
      d++;
      counter++;
    }
    for (int i = 0; i < counts; i++) {
      m++;
      int fer = *f;
      if (m < counter - 1) {
        if (*f >= *l) {
          int ferr = *l;
          fer -= ferr;
        }
        if (*l > *f) {
          S--;
          while (*S == '0') {
            S--;
            count++;
          }
          int T = *S;
          T -= 48;
          T--;
          char B = T + 48;
          *S = B;
          S++;
          for (int i = 0; i < count + 1; i++) {
            if (i != count) {
              *S = '9';
              S++;
            }
            if (i == count) {
              fer -= 48;
              fer += 10;
              int fere = *l;
              fere -= 48;
              fer -= fere;
            }
          }
        }
      }
      if (m >= counter - 1) {
        fer -= 48;
      }
      if (i == counts - 1 && fer != 0) {
        char L = fer + 48;
        *answer = L;
      }
      if (i != counts - 1) {
        char L = fer + 48;
        *answer = L;
      }
      answer++;
      f--;
      l--;
      S--;
    }
    answer -= counts;
    answer += 1;
    reverse(answer);
  }
}
void subtract(const char *number1, const char *number2, char *answer) {
  int a = compare(number1, number2);
  char A[128] = {0};
  strcpy(A, number1);
  char *S = A;
  while (*S != 0) {
    S++;
  }
  S--;
  char Q[128] = {0};
  strcpy(Q, number2);
  char *D = Q;
  while (*D != 0) {
    D++;
  }
  D--;
  int caries = 0;
  int pluser2 = 0;
  int found = 0;
  int count = 0;
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
  const char *f = A;
  const char *l = Q;
  char *answer_ptr = answer;
  while (*f != 0) {
    f++;
  }
  while (*l != 0) {
    l++;
  }
  f--;
  l--;
  counts = strlen(number1);
  counter = strlen(number2);
  if (a == 1 && check == 0 && check2 == 0 ||
      a == -1 && check == 0 && check2 == 0) {
    int found = 1;
    if (a == -1 && check == 0 && check2 == 0) {
      int counts2 = counts;
      counts = counter;
      counter = counts2;
      found = 0;
    }
    for (int i = 0; i < counts; i++) {
      if (i == counts - 1 && *f == '0' && *l == 0 ||
          i == counts - 1 && *f == 0 && *l == '0') {
        break;
      }
      m++;
      int fer = 0;
      if (found == 1) {
        fer = *f - 48;
      }
      if (found == 0) {
        fer = *l - 48;
      }
      if (m < counter) {
        int ferr = 0;
        if (found == 1) {
          ferr = *l - 48;
        }
        if (found == 0) {
          ferr = *f - 48;
        }
        if (fer >= ferr) {
          fer -= ferr;
        } else {
          if (fer < ferr) {
            if (found == 1) {
              S--;
            }
            if (found == 0) {
              D--;
            }
            count++;
            if (found == 1) {
              while (*S == '0') {
                S--;
                count++;
              }
            }
            if (found == 0) {
              while (*D == '0') {
                D--;
                count++;
              }
            }
            if (found == 1) {
              int inky = *S;
              inky--;
              char i_hate_this = inky;
              *S = i_hate_this;
              S++;
            }
            if (found == 0) {
              int inky = *D;
              inky--;
              char i_hate_this = inky;
              *D = i_hate_this;
              D++;
            }
            for (int i = 0; i < count; i++) {
              if (found == 1) {
                if (i != count - 1) {
                  *S = '9';
                  S++;
                }
              }
              if (found == 0) {
                if (i != count - 1) {
                  *D = '9';
                  D++;
                }
              }
              if (i == count - 1) {
                fer += 10;
                fer -= ferr;
              }
            }
          }
        }
      }
      char t = fer + 48;
      *answer_ptr = t;
      f--;
      l--;
      count = 0;
      if (found == 1) {
        S--;
      }
      if (found == 0) {
        D--;
      }
      if (found == 1) {
        if (i != counts - 1) {
          answer_ptr++;
        }
      }
      if (found == 0) {
        answer_ptr++;
      }
    }
    if (found == 0) {
      *answer_ptr = '-';
    }
    char *s = answer;
    while (*s != 0) {
      s++;
    }
    s--;
    while (*s == '0') {
      *s = 0;
      s--;
    }
    reverse(answer);
  }
  if (a == 1 && check == 2 && check2 == 2) {
    for (int i = 0; i < counts - 1; i++) {
      if (i == counts - 1 && *f == 0 && *l == '0' && i == counts - 1 &&
          *f == '0' && *l == 0) {
        break;
      }
      m++;
      int fer = *f - 48;
      if (m < counter - 1) {
        int ferr = *l - 48;
        if (fer >= ferr) {
          fer -= ferr;
        } else {
          if (fer < ferr) {
            S--;
            count++;
            while (*S == '0') {
              S--;
              count++;
            }
            int inky = *S;
            inky--;
            char i_hate_this = inky;
            *S = i_hate_this;
            S++;
            for (int i = 0; i < count; i++) {
              if (i != count - 1) {
                *S = '9';
                S++;
              }
              if (i == count - 1) {
                fer += 10;
                fer -= ferr;
              }
            }
          }
        }
      }
      char t = fer + 48;
      *answer_ptr = t;
      f--;
      l--;
      S--;
      count = 0;
      if (i != counts - 1) {
        answer_ptr++;
      }
    }
    answer_ptr--;
    while (*answer_ptr == '0') {
      *answer_ptr = 0;
      answer_ptr--;
    }
    answer_ptr++;
    *answer_ptr = '-';
    reverse(answer);
  }
  if (a == -1 && check == 2 && check2 == 2) {
    for (int i = 0; i < counter - 1; i++) {
      if (i == counter - 1 && *f == '0' && *l == 0 ||
          i == counter - 1 && *f == 0 && *l == '0') {
        break;
      }
      m++;
      int fer = *l - 48;
      if (m < counts - 1) {
        int ferr = *f - 48;
        if (fer >= ferr) {
          fer -= ferr;
        } else {
          if (fer < ferr) {
            D--;
            count++;
            while (*D == '0') {
              D--;
              count++;
            }
            int inky = *D;
            inky--;
            char i_hate_this = inky;
            *D = i_hate_this;
            D++;
            for (int i = 0; i < count; i++) {
              if (i != count - 1) {
                *D = '9';
                D++;
              }
              if (i == count - 1) {
                fer += 10;
                fer -= ferr;
              }
            }
          }
        }
      }
      char t = fer + 48;
      *answer_ptr = t;
      f--;
      l--;
      D--;
      count = 0;
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
    for (int i = 0; i < counts - 1; i++) {
      int fer = *f - 48;
      fer += caries;
      if (*l != 0) {
        int ferr = *l - 48;
        fer += ferr;
        l--;
      }
      caries = fer;
      caries /= 10;
      char l = fer + 48;
      *answer_ptr = l;
      answer_ptr++;
      f--;
    }
    *answer_ptr = '-';
    reverse(answer);
  }
  if (a == -1 && check == 2 && check2 == 0) {
    for (int i = 0; i < counter; i++) {
      m++;
      int fer = *l - 48;
      fer += caries;
      if (m < counts - 1) {
        int ferr = *f - 48;
        fer += ferr;
        f--;
      }
      caries = fer;
      caries /= 10;
      char M = fer + 48;
      *answer_ptr = M;
      answer_ptr++;
      l--;
    }
    *answer_ptr = '-';
    reverse(answer);
  }
  if (a == -1 && check == 0 && check2 == 2) {
    for (int i = 0; i < counter - 1; i++) {
      int fer = *l - 48;
      m++;
      fer += caries;
      if (m < counts) {
        int ferr = *f - 48;
        fer += ferr;
        f--;
      }
      caries = fer;
      caries /= 10;
      char M = fer + 48;
      *answer_ptr = M;
      answer_ptr++;
      l--;
    }
    reverse(answer);
  }
  if (a == 1 && check == 0 && check2 == 2) {
    char number1_copy[128];
    char *number1_ptr_copy = number1_copy;
    *number1_ptr_copy = '-';
    number1_ptr_copy++;
    const char *number1_ptr = number1;
    while (*number1_ptr != 0) {
      *number1_ptr_copy = *number1_ptr;
      number1_ptr_copy++;
      number1_ptr++;
    }
    add(number1_copy, number2, answer);
    reverse(answer);
  }
}
void test_subtract(const char *number1, const char *number2,
                   const char *expected_answer) {
  char result[128] = {0};
  subtract(number1, number2, result);
  printf("number1 : %s, result: %s number2 : %s expected_answer : %s, "
         "(%s)\n",
         number1, result, number2, expected_answer,
         strcmp(result, expected_answer) == 0 ? "correct" : "wrong");
}
int main() {
  test_subtract("9429402394444443324", "954939380912", "9429401439505062412");
  test_subtract("-903213092139223092849021333309109429402394444443324",
                "94901301239154939380912",
                "-903213092139223092849021333404010730641549383824236");
  test_subtract(
      "-90321309213922309284902133330910942940299903091982131203394444443324",
      "94948908320190321090000123201301239154939380912", "9429401439505062412");
  test_subtract("99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999", "954939380912", "104718688954367507258541200154726497360376356462895857227962447425823247489960250973371996777727125400057186494024202");
}
