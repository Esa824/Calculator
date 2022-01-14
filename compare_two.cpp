#include <cstdio>
#include "compare.h"
#include <cstring>
#include <iostream>
#include <iterator>
#include <string>
using namespace std;
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
