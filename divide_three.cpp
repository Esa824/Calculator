#include <cstdio>
#include <cstring>
#include <iostream>
#include <iterator>
#include <string>
using namespace std;
// -1 if number1 is less than number2 1 if number1
// greater number2

void log(const char *msg) {
  time_t rawtime;
  struct tm *timeinfo;
  time(&rawtime);
  timeinfo = localtime(&rawtime);
  printf("> %s : %s\n", asctime(timeinfo), msg);
}

int compare(const char *number1, const char *number2) {
  int check2 = 0;
  int check = 0;
  const char *f = number1;
  const char *l = number2;
  const char *p = number1;
  const char *o = number2;
  int count = strlen(number1);
  int counter = strlen(number2);
  if (*o == '-') {
    l++;
    counter--;
  }
  if (*p == '-') {
    f++;
    count--;
  }
  if (count < counter) {
    return -1;
  }
  if (count > counter) {
    return 1;
  }
  if (count == counter) {
    for (int i = 0; i < count; i++) {
      if (*f < *l) {
        return -1;
      }
      if (*f > *l) {
        return 1;
      }
      l++;
      f++;
    }
  }
  return 0;
}
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
  if(strlen(number1) > 128){
    a = -2;
  }
  if(strlen(number2) > 128){
    a = -2;
  }
  char A[strlen(number1) + 1];
  strcpy(A, number1);
  char *S = A;
  while (*S != 0) {
    S++;
  }
  S--;
  char Q[strlen(number2)];
  strcpy(Q, number2);
  char *D = Q;
  while (*D != 0) {
    D++;
  }
  D--;
  int caries = 0;
  int count = 0;
  int found_two = 0;
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
  const char *b = A;
  const char *f = A;
  const char *d = Q;
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
      if (found_two == 0) {
        fer = *f;
        fer += *l;
      }
      fer += caries;
      if (found_two == 0) {
        if (m >= counter) {
          fer -= 48;
        }
      }
      if (found_two == 0) {
        if (m < counter) {
          fer -= 96;
        }
      }
      int fere = fer;
      fer %= 10;
      char t = fer + 48;
      *answer_ptr = t;
      f--;
      l--;
      answer_ptr++;
      fere /= 10;
      caries = fere;
      if (caries > 0 && i == counts - 1) {
        counts++;
        found_two = 1;
      }
    }
    reverse(answer);
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
      if (m < counter) {
        fer += *l;
        l--;
      }
      if (found_two == 0) {
        if (m >= counter) {
          fer -= 48;
        }
      }
      if (found_two == 0) {
        if (m < counter) {
          fer -= 96;
        }
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
        counts++;
        found_two = 1;
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
      if (m >= counts && found_two == 0) {
        fer -= 48;
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
        counter++;
        found_two = 1;
      }
    }
    reverse(answer);
  }
}
void multiply(const char *number1, const char *number2, char *answer) {
  int a = compare(number1, number2);
  int found_two = 0;
  int count = 0;
  int spe = 0;
  int m = -1;
  int cari = 0;
  int found = 0;
  int found2 = 0;
  const char *o = number1;
  const char *p = number2;
  int check = 0, check2 = 0;
  if (*o == '-') {
    o++;
    check = 2;
  }
  while (*o != 0) {
    if (*o >= '0' && *o <= '9') {
    } else {
      check = 1;
    }
    o++;
  }
  if (*p == '-') {
    check2 = 2;
    p++;
  }

  while (*p != 0) {
    if (*p >= '0' && *p <= '9') {
    } else {
      check2 = 1;
    }
    p++;
  }
  const char *f = number1;
  const char *l = number2;
  char *s = answer;
  while (*s != 0) {
    *s = 0;
    s++;
  }
  char *e = answer;
  *e = '0';
  while (*f != 0) {
    f++;
  }
  while (*l != 0) {
    l++;
  }
  f--;
  l--;
  int counts = strlen(number1);
  int counter = strlen(number2);
  if (check == 0 && check2 == 0 || check == 2 && check2 == 2 ||
      check == 0 && check2 == 2 ||
      check == 2 && check2 == 0 && *number1 != '0') {
    if (check2 == 2 && check == 2) {
      counts--;
      counter--;
    }
    if (check2 == 0 && check == 2) {
      counter--;
    }
    if (check2 == 2 && check == 0) {
      counts--;
    }
    int g = 0;
    char M[128] = {0};
    char P[128] = {0};
    char O[128] = {0};
    for (int i = 0; i < counter + counter; i++) {
      g++;
      if (found == 1) {
        found = 0;
        char *f_f = P;
        int founds_count = strlen(P);
        int founds_count2 = strlen(O);
        if (i > 1) {
          while (*f_f != 0) {
            f_f++;
          }
          f_f--;
        }
        if (i == 1) {
          char *V = O;
          reverse(P);
          for (int i = 0; i < founds_count; i++) {
            int fer = *f_f - 48;
            char m = fer + 48;
            *V = m;
            V++;
            f_f++;
          }
          if (i == counter + counter - 1) {
            char *v = O;
            char *mm = answer;
            while (*v != 0) {
              *mm = *v;
              v++;
              mm++;
            }
          }
          V -= founds_count;
          spe = founds_count;
        }
        if (i > 1) {
          if (i >= 3) {
            reverse(P);
          }
          add(P, O, M);
          char *O_ptr = O;
          char *M_ptr = M;
          while (*M_ptr != 0) {
            *O_ptr = *M_ptr;
            O_ptr++;
            M_ptr++;
          }
          char *v = P;
          while (*v != 0) {
            *v = 0;
            v++;
          }
          if (i == counter + counter - 1) {
            char *answer_ptr = answer;
            char *M_ptr = M;
            while (*M_ptr != 0) {
              *answer_ptr = *M_ptr;
              answer_ptr++;
              M_ptr++;
            }
          }
        }
      } else {
        char *L = P;
        if (i > 1) {
          for (int j = 0; j < i / 2; j++) {
            *L = '0';
            L++;
          }
        }
        for (int j = 0; j < counts; j++) {
          int fer = 0;
          int ferr = 0;
          if (found_two == 0) {
            fer = *f - 48;
            ferr = *l - 48;
            fer *= ferr;
          }
          fer += cari;
          int fere = fer;
          fer %= 10;
          char m = fer + 48;
          *L = m;
          fere /= 10;
          cari = fere;
          f--;
          L++;
          fer = 0;
          if (cari > 0 && j == counts - 1) {
            counts++;
            found_two = 1;
          }
          if (found_two == 1 && j == counts - 1) {
            f += counts;
            counts--;
          }
        }
        l--;
        if (found_two != 1) {
          f += counts;
        }
        found_two = 0;
        L--;
        found = 1;
      }
    }
    if (check == 0 && check2 == 2 || check == 2 && check2 == 0) {
      char *l = answer;
      while (*l != 0) {
        l++;
      }
      *l = '-';
    }
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
}
void divide(const char *number1, const char *number2, char *answer) {
  int a = compare(number1, number2);
if(strlen(number1) > 128){
    a = -2;
  }
  if(strlen(number2) > 128){
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
void test_divide(const char *number1, const char *number2,
                 const char *expected_answer) {
  char result[128] = {0};
  divide(number1, number2, result);
  printf("number1 : %s, result: %s number2 : %s expected_answer : %s, "
         "(%s)\n",
         number1, result, number2, expected_answer,
         strcmp(result, expected_answer) == 0 ? "correct" : "wrong");
}
int main() {
  test_divide("130000000000000", "9", "14444444444444");
  test_divide("383838", "2847", "134");
  test_divide("9999999999999", "383838", "26052657");
  test_divide("2202929", "8598", "256");
  test_divide("229929202929", "89999598", "2554");
  test_divide("10381239", "89999598", "");
  test_divide("99999999999999999", "383838", "260526576316");
  test_divide("448281018998098939", "89999598", "4980922459");
  test_divide(
      "-9999999999999999999999999999999999999999999999999999999999999999",
      "-89999598", "111111607409624207432570976594806567913781126000140578405");
  test_divide("-99999894320849999999", "-89999598", "1111114899878");
  test_divide("-99950290199894320849999999", "-832092191899999598",
              "120119250");
  test_divide(
      "-9999999999999999999999999999999999999999999999999999999999999999",
      "89598", "-111609634143619277216009285921560749123864371972588673854327");
  test_divide("9999999999999", "-383838", "-26052657");
  test_divide("99999999981022221831093209999999999212931039199999999999",
              "-888888888383838",
              "-112500000042570502709167665262925978790883");
  test_divide(
      "999999999999999999999999999999999999999999999999999999999999999999999999"
      "99999999999999999999999999999999999999999999999999999999",
      "954939380912",
      "104718688954367507258541200154726497360376356462895857227962447425823247"
      "489960250973371996777727125400057186494024202");
}
