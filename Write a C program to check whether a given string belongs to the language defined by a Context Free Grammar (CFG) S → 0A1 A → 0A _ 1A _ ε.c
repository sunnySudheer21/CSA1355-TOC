#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int parse_A(char *input_string, int index)
{
    if (input_string[index] == '0')
        return parse_A(input_string, index + 1);
    else if (input_string[index] == '1')
        return parse_A(input_string, index + 1);
    else
        return index;
}

int parse_S(char *input_string)
{
    if (input_string[0] == '0') {
        int index = parse_A(input_string, 1);
        if (input_string[index] == '1')
            return index + 1;
    }
    return 0;
}

int main()
{
    char input_string[MAX_LEN];

    printf("Enter a string: ");
    scanf("%s", input_string);

    int len = strlen(input_string);
    int index = parse_S(input_string);

    if (index == len)
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}
