#include <stdio.h>
#include <string.h>

int is_valid(char *str) {
  int len = strlen(str);

  if (len < 5) {
    return 0;
  }

  if (str[0] != '1' || str[1] != '0' || str[2] != '1') {
    return 0;
  }

  int i = 3;
  while (i < len && (str[i] == '0' || str[i] == '1')) {
    i++;
  }

  if (i == len) {
    return 0;
  }

  int j = len - 1;
  while (j > i && (str[j] == '0' || str[j] == '1')) {
    j--;
  }

  if (j == i) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  char str[100];
  printf("Enter a string: ");
  scanf("%s", str);

  if (is_valid(str)) {
    printf("The string belongs to the language defined by the CFG\n");
  } else {
    printf("The string does not belong to the language defined by the CFG\n");
  }

  return 0;
}
