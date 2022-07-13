//
//  Assignment10
//
//  Created by suppakorn rakna on 30/11/2563 BE.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Read_text_file(char filetext[], int data1[], int *count);
int Read_binary_file(char bin_file[], int data2[], int *count);
double cmp_scan(int data1[], int count1, int data2[], int count2);
int comparator(const void *a, const void *b);
double cmp_binsearch(int data1[], int count1, int data2[], int count2);
int Compare_Ref(int data1[], int count1, int data2[], int count2);

int main() {
  int count1, count2, data1[100010], data2[100010];
  char filetext[20], filebin[20];
  double time;
  Read_text_file("txt100000.txt", data1, &count1);
  Read_binary_file("bin100000.bin", data2, &count2);

  time = cmp_scan(data1, count1, data2, count2);
  printf("Time elapsed %g second(s)\n", time);

  qsort(data2, count2, sizeof(int), comparator);
  time = cmp_binsearch(data1, count1, data2, count2);
  printf("Time elapsed %g second(s)\n", time);

  qsort(data1, count1, sizeof(int), comparator);
  qsort(data2, count2, sizeof(int), comparator);
  time = Compare_Ref(data1, count1, data2, count2);
  printf("Time elapsed %g second(s)\n", time);
  return 0;
}

void Read_text_file(char filetext[], int data1[], int *count) {
  FILE *fp;
  double a;
  int success = 0;
  if ((fp = fopen(filetext, "r")) != NULL) {
    *count = 0;
    while (fscanf(fp, "%lf", &a) == 1) {
      data1[*count] = a;
      *count = *count + 1;
    }
    fclose(fp);
    printf("Read file %s %d records complete\n", filetext, *count);
    success = *count;
  } else {
    printf("\nError. Cannot read file %s", filetext);
    success = 0;
  }
}

int Read_binary_file(char binfile[], int data2[], int *count) {
  FILE *fp;
  int a;
  int success = 0;
  *count = 0;
  fp = fopen(binfile, "rb");
  if (fp != NULL) {
    while (!feof(fp))
      if (fread(&a, sizeof(int), 1, fp) == 1) {
        data2[*count] = a;
        *count = *count + 1;
      }
    fclose(fp);
    printf("Read file %s %d records complete.\n", binfile, *count);
    success = *count;
  } else {
    printf("\nError. Can't read file %s", binfile);
    success = 0;
  }
  return success;
}

double cmp_scan(int data1[], int count1, int data2[], int count2) {
  int i, j;
  double start, end, time;
  int count = 0;
  printf("\nMethod #1\n");
  start = clock();
  for (i = 0; i < count1; i++)
    for (j = 0; j < count2; j++)
      if (data1[i] == data2[j]) {
        printf("Found[%d] = %d\n", count + 1, data1[i]);
        count += 1;
      }
  end = clock();
  printf("End\n");
  printf("Found %d number(s)\n", count);
  time = (end - start) / CLOCKS_PER_SEC;
  return time;
}

int comparator(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

double cmp_binsearch(int data1[], int count1, int data2[], int count2) {
  double start, end, time;
  int i;
  int count = 0;
  printf("\nMethod #2\n");
  start = clock();
  for (i = 0; i < count1; i++)
    if ((int *)bsearch(&data1[i], data2, count2, sizeof(int), comparator) !=
        NULL) {
      printf("Found[%d] = %d\n", count + 1, data1[i]);
      count += 1;
    }
  end = clock();
  printf("End\n");
  printf("Found %d number(s)\n", count);
  time = (end - start) / CLOCKS_PER_SEC;
  return time;
}

int Compare_Ref(int data1[], int count1, int data2[], int count2) {
  int start, end, time;
  int i, j;
  int count = 0;
  printf("\nMethod #3\n");
  start = clock();
  for (i = 0, j = 0; i < count1 || j < count2;) {
    if (data1[i] < data2[j])
      i++;
    else if (data1[i] > data2[j])
      j++;
    else {
      printf("Found[%d] = %d\n", count + 1, data1[i]);
      count += 1;
      i++;
    }
  }
  end = clock();
  printf("End\n");
  printf("Found %d number(s)\n", count);
  time = (end - start) / CLOCKS_PER_SEC;
  return time;
}
