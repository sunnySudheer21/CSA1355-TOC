#include <stdio.h>
#include <string.h>

int is_valid(char *str) {
  int len = strlen(str);
  int i = 0, j = len - 1;

  while (i <= j) {
    if (str[i] == '0' && str[j] == '0') {
      i++;
      j--;
    } else if (str[i] == '1' && str[j] == '1') {
      i++;
      j--;
    } else {
      return 0;
    }
  }

  return 1;
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
