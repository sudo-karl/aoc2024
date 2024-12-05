#include <stdio.h>
#include <stdlib.h>

int main() {
  char *filename = "aoc2.txt";
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Could not open file %s", filename);
    return 1;
  }
  char currentChar = '$';
  int currentInt = 0;
  int sum = 0;
  int num = 0;
  volatile int prevNum = 0;
  int status = 0;
  int tripped = 0;

  while (1) {
    currentChar = fgetc(fp);
    if (currentChar == '0' || currentChar == '1' || currentChar == '2' ||
        currentChar == '3' || currentChar == '4' || currentChar == '5' ||
        currentChar == '6' || currentChar == '7' || currentChar == '8' ||
        currentChar == '9')
      currentInt = currentInt * 10 + (currentChar - '0');
    if (currentChar == ' ' || currentChar == '\n') {
      prevNum = num;
      num = currentInt;
      currentInt = 0;
      printf("%d ", num);
      if (prevNum != 0) {
        if (status == 0 && num - prevNum > 0) {
          status = 1;
        }
        if (status == 0 && num - prevNum < 0) {
          status = -1;
        }
        if (tripped == 0) {
          if (status == 1) {
            if (num - prevNum < 1 || num - prevNum > 3) {
              tripped = 1;
            }
          }
          if (status == -1) {
            if (prevNum - num < 1 || prevNum - num > 3) {
              tripped = 1;
            }
          }
        }
      }
    }
    if (currentChar == '\n') {
      printf("status is %d, tripped is %d\n", status, tripped);
      num = 0;
      prevNum = 0;
      status = 0;
      currentInt = 0;
      if (tripped == 0) {
        sum += 1;
      }
      tripped = 0;
    }

    if (currentChar == EOF) {
      printf("sum is %d\n", sum);
      break;
    }
  }
  return 0;
}
