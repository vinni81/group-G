#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 1000

void deleteSpaces(char* str)
{
    int length = strlen(str);
    bool prevSpace = false;
    int j = 0;

    for (int i = 0; i < length; i++)
    {
        if (str[i] != ' ')
        {
            str[j++] = str[i];
            prevSpace = false;
        }
        else
        {
            if (!prevSpace)
            {
                str[j++] = str[i];
            }
            prevSpace = true;
        }
    }

    str[j] = '\0';
}

int main() {
    char input[MAX_LENGTH];
    printf("enter stringi:");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    FILE* inputFile = fopen("input.txt", "w");
    fprintf(inputFile, "%s", input);
    fclose(inputFile);

    deleteSpaces(input);

    FILE* outputFile = fopen("output.txt", "w");
    fprintf(outputFile, "%s", input);
    fclose(outputFile);

    printf("%s\n", input);

    return 0;
}

