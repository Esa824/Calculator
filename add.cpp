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
void test_add(const char *number1, const char *number2,
              const char *expected_answer) {
  char result[128] = {0};
  add(number1, number2, result);
  printf("number1 : %s, result: %s number2 : %s expected_answer : %s, "
         "(%s)\n",
         number1, result, number2, expected_answer,
         strcmp(result, expected_answer) == 0 ? "correct" : "wrong");
}
int main (){
  test_add("-11", "-10", "-21");
  test_add(
      "10000000000000000000000000000",
      "1000000000000000000000000000000000000000000000000000000000000000000000",
      "1000000000000000000000000000000000000000010000000000000000000000000000");
  test_add("2", "-1000", "-998");
  test_add("11", "-10", "1");
  test_add("-10", "11", "1");
  test_add("-11", "10", "-1");
  test_add(
      "-11",
      "1000000000000000000000000000000000000000000000000000000000000000000"
      "00000",
      "99999999999999999999999999999999999999999999999999999999999999999999\
989");
  test_add(
      "-18998900888929482094801840328470984983240884000003942843204832428903284"
      "9038408904839248039840284444444444444444092840984301",
      "-888420084928402480913402840938240990",
      "-1899890088892948209480184032847098498324088400000394284320483242890\
32849038408904839248928260369372846925357846933779225291");
  test_add("1000", "1", "1001");
  test_add("9", "1", "10");
  test_add("-9", "-1", "-10");
  test_add("4839408209483444444444444444444444483092840328409238402384029384023"
           "8492384092384902384092",
           "-238209381938123801238329183019283093801",
           "4839408209483444444444444444444444483092840328409214581445835571643"
           "7254054909365619290291");
  test_add(
      "982039812039820381093810238019238091830100485833724839408209483444444444"
      "4444444444444830928403284092384023840293840238492384092384902384092",
      "-48982340984098340938409284093840923840932840932849038444445473597698281"
      "490893829038928398492498374827483799243777772488493840293844423843928402"
      "834989024930493248234802384093842093840938490384924888888888290488888888"
      "82034823048294823048234839483209488888880",
      "");
  test_add("-483940820938928310483444444444444444444444483092840328409238402384"
           "0293840238492384092384902384092",
           "403940234902238209381938123801238329183019283093801",
           "-483940820938928310483444444444444444444444483052446304919014581445"
           "8355716437254054909365619290291");
  test_add("-10", "2", "-8");
  test_add(
      "-48394082093892831048344444444444444444444448309284032840923840238402938"
      "40238492384092384902384092",
      "-40839482841984028492814928401284092840093940234902238209381938123801238"
      "329183019283093801",
      "-4839408250228765946818472937259372845728537671022343518994622233222\
231964039730713275404185477893");
  test_add(
      "-928489189248675991933447178393193384938420984983940284093840",
      "-12839213848390840841904893843574827489329218392183838239218384777798319"
      "238928310983190129038120380128309283418",
      "-1283921384839084084190489384357482748932921839218476672840763345379\
0252686106704176575067459105364068593377258");
}
