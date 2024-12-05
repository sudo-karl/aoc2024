#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comp(const void *a, const void *b) {
  const int *A = a, *B = b;
  return (*A > *B) - (*A < *B);
}

int main() {
  clock_t begin = clock();
  char *filename = "aoc1.txt";
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Could not open file %s", filename);
    return 1;
  }

  char tmpstr[256];
  char left[5][1000];
  char right[5][1000];

  for (int i = 0; i < 1000; i++) {
    fgets(tmpstr, sizeof(tmpstr), fp);
    for (int j = 0; j < 5; j++) {
      left[j][i] = tmpstr[j];
    }
    for (int k = 8; k < 13; k++) {
      right[k - 8][i] = tmpstr[k];
    }
  }

  int leftint[1000];
  int rightint[1000];

  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < 5; j++) {
      leftint[i] = leftint[i] * 10 + (left[j][i] - '0');
      rightint[i] = rightint[i] * 10 + (right[j][i] - '0');
    }
  }
  qsort(leftint, 1000, sizeof(int), comp);
  qsort(rightint, 1000, sizeof(int), comp);
  int sum = 0;
  for (int i = 0; i < 1000; i++) {
    sum += abs(leftint[i] - rightint[i]);
  }
  int count[1000];
  printf("Sum: %d\n", sum);
  int sum2 = 0;
  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < 1000; j++) {
      if (leftint[i] == rightint[j]) {
        count[i]++;
      }
    }
    sum2 = leftint[i] * count[i] + sum2;
  }

  printf("Sum2: %d\n", sum2);

  fclose(fp);
  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Time elapsed: %f\n", time_spent);
  return 0;
}
