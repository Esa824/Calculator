#include <cstdio>
#include <cstring>
#include <string>
#include "compare.h"
#include "reverse.h"
#include "add.h"
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
void test_multiply(const char *number1, const char *number2,
                   const char *result2) {
  char answer[128] = {0};
  multiply(number1, number2, answer);
  printf("number1 %s number2 %s result %s result2 %s(%s)\n", number1, number2,
         answer, result2,
         strcmp(answer, result2) == 0 ? "it is correct" : "it is wrong");
}
int main() {
  test_multiply("383838", "2847", "1000");
  test_multiply("-9909409312034203038383888888882018302130938018", "-28479402934902044209", "282214060644292528804232966701060943704665003735670569810874837762");
    test_multiply("-9909409390482094023842012034203038383888888882018302130938018", "-284794402984092380888889423409283002934902044209", "-9909409390481809229439027941822149494465479599015367228893809");
    test_multiply("-990940939048888888888138904803980943234822094023842012034203038383888888882018302130938018", "-2847944409328409283402830402984092380888889423409283002934902044209", "-9909409390488888888881360568595716148255386911934390279418221494944\
65479599015367228893809");
    test_multiply("99094093904888483902888408888888138904803980943234822094023842012034203038383888888882018302130938018", "-28479444093284092834028304029840923808888894234092594805289083002934902044209", "99094093904888483902888437368332232188896814971538851934947650900928\
437130978694177965021237032982227");

}
