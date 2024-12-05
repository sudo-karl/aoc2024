
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp(const void *a, const void *b) {
  const int *A = a, *B = b;
  return (*A > *B) - (*A < *B);
}
int charToInt(char buf[]) {
  int numCount = strlen(buf) / 3;
  int current = 0;
  int nums[numCount];
  for (int i = 0; i < strlen(buf); i++) {
    if (buf[i] == '0' || buf[i] == '1' || buf[i] == '2' || buf[i] == '3' ||
        buf[i] == '4' || buf[i] == '5' || buf[i] == '6' || buf[i] == '7' ||
        buf[i] == '8' || buf[i] == '9')
      current = current * 10 + (buf[i] - '0');
    if (buf[i] == ' ' || buf[i] == '\n') {
      nums[i] = current;
    }
    i++;
  }
  for (int i = 0; i < numCount; i++) {
    printf("%d ", nums[i]);
  }
  printf("\n");
  return 0;
}
int main() {
  char *filename = "aoc2.txt";
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Could not open file %s", filename);
    return 1;
  }

  char tmpstr[256];

  for (int i = 0; i < 1000; i++) {
    fgets(tmpstr, sizeof(tmpstr), fp);
    charToInt(tmpstr);
  }

  return 0;
}
