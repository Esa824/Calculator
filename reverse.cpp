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
