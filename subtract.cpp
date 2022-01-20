#include "compare.h"
#include "reverse.h"
#include "add.h"
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
void subtract(const char *number1, const char *number2, char *answer) {
  int a = compare(number1, number2);
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
  int found_two = 0;
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
    if (*o > '9' || *o < '0') {
      check2 = 1;
    }
    o++;
  }
  if (*p == '-') {
    check = 2;
    p++;
  }
  while (*p != 0) {
    if (*p > '9' || *p < '0') {
      check = 1;
    }
    p++;
  }
  int cohut = 0;
  char *f = A;
  char *l = Q;
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
    counts--;
    for (int i = 0; i < counts; i++) {
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
    while (*answer_ptr != 0) {
      answer_ptr++;
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
    counts -= 1;
    for (int i = 0; i < counts; i++) {
      m++;
      int fer = 0;
      if (found_two == 0) {
        fer = *f - 48;
      }
      fer += caries;
      if (m < counter) {
        int ferr = *l - 48;
        fer += ferr;
        l--;
      }
      caries = fer;
      fer %= 10;
      caries /= 10;
      char q = fer + 48;
      *answer_ptr = q;
      answer_ptr++;
      f--;
      if (caries > 0 && i == counts - 1) {
        found_two = 1;
        counts++;
      }
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
      fer %= 10;
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
      "94948908320190321090000123201301239154939380912",
      "-90321309213922309284997082239231133261389903215183432442549383824236");
  test_subtract(
      "999999999999999999999999999999999999999999999999999999999999999999999999"
      "99999999999999999999999999999999999999999999999999999999",
      "954939380912",
      "999999999999999999999999999999999999999999999999999999999999999999999999"
      "99999999999999999999999999999999999999999999045060619087");
  test_subtract(
      "948888888888888888888888888888888888888832222222222222444444488844444444"
      "4444444444444444444444444333920384-29402394444443324",
      "954939380912", "");
  test_subtract(
      "-98508092039023901239802983398402840398409283402834089028493284234802842"
      "94820480994328437897918239817390248023810004109909",
      "8928490832049830480324803284092384092384903284902954939380912",
      "-9850809203902390123980298339840284039840928340283408902849337351971\
116344650961319131721990302332202293532926764943490821");
  test_subtract(
      "-98451745801888884541578578130457938204983049814439052842908410284018402"
      "849184903888888812428491284938424899",
      "-801885890402483094802483204823948394828492840938954939380912",
      "-9845174580188888454157857813045793820498304981363716695250592718921\
5919644360955494060319587552329999043987");
  test_subtract(
      "-94294023944444809384092834981388012938091283981209182390182309183190381"
      "443324",
      "382938103820138318231283912830182319381312308131239081113091283195493938"
      "0912",
      "-98123404982646192566405674109689836131904407062521573201313222015145320"
      "824236");
  test_subtract("98483249832483948209482039480234884903840928309","-484838438409384083248394884922489384444480224293092048309489038","484838438409384181731644717406437593926519704527976952150417347");
}
