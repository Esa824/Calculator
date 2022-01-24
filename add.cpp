#include "compare.h"
#include "reverse.h"
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
// -1 if number1 is less than number2 1 if number1
// greater number2
void add(const char *number1, const char *number2, char *answer) {
  int a = compare(number1, number2);
  if (strlen(number1) > 128 || strlen(number2) > 128 ||
      strlen(number1) == 0 && strlen(number2) == 0) {
    a = -2;
  }
  char A[strlen(number1) + 1];
  strcpy(A, number1);
  char *S = A;
  while (*S != 0) {
    S++;
  }
  S--;
  char Q[strlen(number2) + 1];
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
  char *s = answer;
  s += 127;
  while (*f != 0) {
    f++;
  }
  while (*l != 0) {
    l++;
  }
  int number = 10;
  f--;
  l--;
  if (a == 0 && check == 0 && check2 == 2) {
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
      int fer = 0;
      fer += caries;
      if (found_two == 0) {
        fer += *f - 48;
        fer += *l - 48;
      }
      caries = fer;
      fer %= 10;
      caries /= 10;
      char t = fer + 48;
      *answer_ptr = t;
      f--;
      l--;
      answer_ptr++;
      if (caries > 0 && i == counts - 1) {
        found_two = 1;
        counts++;
      }
    }
    if (*s != 0) {
      *s = '0';
    }
    char *d = answer;
    while (*d != 0) {
      d++;
    }
    reverse(answer);
  }
  if (a == 0 && check == 2 && check2 == 2) {
    while (*b != 0) {
      b++;
      counts++;
    }
    while (*d != 0) {
      d++;
      counter++;
    }
    counts--;
    for (int i = 0; i < counts; i++) {
      m++;
      int fer = 0;
      fer += caries;
      if (found_two == 0) {
        fer += *f - 48;
        fer += *l - 48;
      }
      caries = fer;
      fer %= 10;
      caries /= 10;
      char t = fer + 48;
      *answer_ptr = t;
      f--;
      l--;
      answer_ptr++;
      if (caries > 0 && i == counts - 1) {
        found_two = 1;
        counts++;
      }
    }
    while (*answer_ptr != 0) {
      answer_ptr++;
    }
    *answer_ptr = '-';
    if (*s != 0) {
      *s = '0';
    }
    char *d = answer;
    while (*d != 0) {
      d++;
    }
    reverse(answer);
  }

  if (a == 0 && check == 2 && check2 == 0) {
    *answer_ptr = '0';
  }
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
      if (found_two == 0) {
        if (m < counter) {
          fer += *l;
          l--;
        }
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
  if (a == 0 && check == 0 && check2 == 0) {
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
      fer += caries;
      if (found_two == 0) {
        fer += *f - 48;
        fer += *l - 48;
      }
      caries = fer;
      fer %= 10;
      caries /= 10;
      char t = fer + 48;
      *answer_ptr = t;
      f--;
      l--;
      answer_ptr++;
      if (caries > 0 && i == counts - 1) {
        found_two = 1;
        counts++;
      }
    }
    if (*s != 0) {
      *s = '0';
    }
    char *d = answer;
    while (*d != 0) {
      d++;
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
        counter++;
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
    counter--;
    counts--;
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
        counter++;
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
    counter--;
    counts--;
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
    char *u = answer;
    while (*u != 0) {
      u++;
    }
    *u = '-';
    reverse(answer);
  }
  if (a == 1 && check == 2 && check2 == 0) {
    while (*d != 0) {
      d++;
      counter++;
    }
    int counts = strlen(A);
    counts--;
    for (int i = 0; i < counts; i++) {
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
      if (i == counts - 1 && fer != 0) {
        char L = fer + 48;
        *answer_ptr = L;
      }
      if (i != counts - 1) {
        char L = fer + 48;
        *answer_ptr = L;
        answer_ptr++;
      }
      f--;
      l--;
      S--;
      count = 0;
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
      if (i == counter - 1 && *f == *l) {
        break;
      }
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
        *answer_ptr = L;
      }
      if (i != counter - 1) {
        char L = fer + 48;
        *answer_ptr = L;
        answer_ptr++;
      }
      f--;
      l--;
      D--;
      count = 0;
    }
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
    counter--;
    for (int i = 0; i < counter; i++) {
      if (i == counter - 1 && *f == *l) {
        break;
      }
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
      if (i == counter - 1 && fer != 0) {
        char L = fer + 48;
        *answer_ptr = L;
      }
      if (i != counter - 1) {
        char L = fer + 48;
        *answer_ptr = L;
        answer_ptr++;
      }
      f--;
      l--;
      D--;
      count = 0;
    }
    while (*answer_ptr != 0) {
      answer_ptr++;
    }
    *answer_ptr = '-';
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
      if (i == counts - 1 && *f == *l) {
        break;
      }
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
        *answer_ptr = L;
      }
      if (i != counts - 1) {
        char L = fer + 48;
        *answer_ptr = L;
        answer_ptr++;
      }
      f--;
      l--;
      S--;
      count = 0;
    }
    reverse(answer);
  }
}
