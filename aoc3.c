#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  char *filename = "aoc3.txt";
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Could not open file %s", filename);
    return 1;
  }
  char current = 0;
  char buf[20000];
  int i = 0;
  while (current != EOF) {
    current = fgetc(fp);
    buf[i] = current;
    i++;
  }
  i = 0;
  int mul1 = 0;
  int mul1Exists = 0;
  int mul2 = 0;
  int mul2Exists = 0;
  long int sum = 0;
  printf("%s\n", buf);
  while (buf[i] != EOF) {
    if (buf[i] == 'm' && buf[i + 1] == 'u' && buf[i + 2] == 'l' &&
        buf[i + 3] == '(') {
      i += 4;
      mul1 = 0;
      mul1Exists = 0;
      mul2 = 0;
      mul2Exists = 0;
      while (isdigit(buf[i])) {
        mul1Exists = 1;
        mul1 = mul1 * 10 + buf[i] - '0';
        i++;
      }
      if (buf[i] == ',' && mul1Exists == 1) {
        i++;
        while (isdigit(buf[i])) {
          mul2Exists = 1;
          mul2 = mul2 * 10 + buf[i] - '0';
          i++;
        }
      }
      if (buf[i] == ')' && mul1Exists && mul2Exists) {
        printf("mul(%d,%d) = %d\n", mul1, mul2, mul1 * mul2);
        sum += mul1 * mul2;
      }
    } else {
      i++;
    }
  }
  printf("Sum: %ld\n", sum);
  return 0;
}
