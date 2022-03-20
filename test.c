#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book *search[503];

struct book {
  char name[53];
  char author[23];
  char pub[23];
  int year;
} b[503];

int cmp(const void *a, const void *b) {
  printf("%p %p\n", a, b);
  // printf("%d %d\n", ((struct book *)a)->year, ((struct book *)b)->year);
  for (int i = 0; i < 53; i++) {
    if (((struct book *)a)->name[i] < ((struct book *)b)->name[i])
      return -1;
    else if (((struct book *)a)->name[i] > ((struct book *)b)->name[i])
      return 1;
  }
  return 0;
}

int main() {
  FILE *fin = fopen("book.txt", "r");
  char str[1025];
  int total;
  int i;
  for (total = 0; fgets(str, 1024, fin) != NULL; total++) {
    sscanf(str, "%s%s%s%d", b[total].name, b[total].author, b[total].pub, &b[total].year);
    search[total] = &b[total];
    printf("%p ", &b[total]);
  }
  printf("\n");
  for (i = 0; i < total; ++i) {
    printf("%s %s %s %d %p\n", search[i]->name, search[i]->author, search[i]->pub, search[i]->year, search[i]);
  }
  printf("%d\n", total);

  fclose(fin);
  qsort(search, total, sizeof(struct book*), cmp);
  for (i = 0; i < total; ++i) {
    printf("%s %s %s %d\n", search[i]->name, search[i]->author, search[i]->pub, search[i]->year);
  }
}