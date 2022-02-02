#include "add.h"
#include "divide.h"
#include "multiply.h"
#include "subtract.h"
#include <cstdio>
#include <cstring>
#include <iostream>
#include "compare.h"
using namespace std;
int main() {
  for(;;){
  char str1[128] = {0};
  cout << "Enter str1: ";
  cin >> str1;
  char do_what[128] = {0};
  cout << "you put: ";
  cin >> do_what;
  char str2[128];
  cout << "Enter str2: ";
  cin >> str2;
  char expected_answer[128] = {0};
  if (*do_what == '+') {
    add(str1, str2, expected_answer);
  }
  if (*do_what == '*') {
    multiply(str1, str2, expected_answer);
  }
  if (*do_what == '/') {
    divide(str1, str2, expected_answer);
  }
  if (*do_what == '-') {
    subtract(str1, str2, expected_answer);
  }
  printf("%s\n", expected_answer);
  }
}
