#include <stdio.h>
#include <string.h>

int is_valid(char *str) {
  int len = strlen(str);
  int i = 0;

  while (i < len) {
    if (str[i] == '0') {
      int j = i + 1;
      while (j < len && str[j] == '1') {
        j++;
      }
      if (j < len && str[j] == '0') {
        i = j + 1;
      } else {
        return 0;
      }
    } else if (str[i] == '1') {
      i++;
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
