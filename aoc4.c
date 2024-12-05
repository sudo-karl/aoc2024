#include <stdio.h>
#include <stdlib.h>

int check(int i, int j, char buf[140][150]) {
  int count = 0;
  if (buf[i][j + 1] == 'M' && buf[i][j + 2] == 'A' && buf[i][j + 3] == 'S')
    count++;
  if (buf[i][j - 1] == 'M' && buf[i][j - 2] == 'A' && buf[i][j - 3] == 'S')
    count++;
  if (buf[i + 1][j] == 'M' && buf[i + 2][j] == 'A' && buf[i + 3][j] == 'S')
    count++;
  if (buf[i - 1][j] == 'M' && buf[i - 2][j] == 'A' && buf[i - 3][j] == 'S')
    count++;
  if (buf[i + 1][j + 1] == 'M' && buf[i + 2][j + 2] == 'A' &&
      buf[i + 3][j + 3] == 'S')
    count++;
  if (buf[i + 1][j - 1] == 'M' && buf[i + 2][j - 2] == 'A' &&
      buf[i + 3][j - 3] == 'S')
    count++;
  if (buf[i - 1][j + 1] == 'M' && buf[i - 2][j + 2] == 'A' &&
      buf[i - 3][j + 3] == 'S')
    count++;
  if (buf[i - 1][j - 1] == 'M' && buf[i - 2][j - 2] == 'A' &&
      buf[i - 3][j - 3] == 'S')
    count++;
  return count;
}
int main() {
  char *filename = "aoc4.txt";
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Could not open file %s", filename);
    return 1;
  }
  int sum = 0;
  char buf[140][150];
  for (int i = 0; i < 140; i++) {
    fgets(buf[i], sizeof(buf[i]), fp);
  }
  for (int i = 0; i < 140; i++) {
    for (int j = 0; j < 140; j++) {
      printf("%c", buf[i][j]);
      if (buf[i][j] == 'X') {
        sum += check(i, j, buf);
      }
    }
    printf("\n");
  }
  printf("sum: %d\n", sum);
  fclose(fp);
  return 0;
}
