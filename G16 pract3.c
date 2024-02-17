
#include <stdio.h>
#include <string.h>
#define SIZE 1000

void changeName(char *strExt, char *buffer)
{
    int count = 0;
    for (int i = 0; i < strlen(strExt); i++)
    {
        if (!memcmp(strExt + i, "Ling", 4))
        {
            strcat(buffer, "Cao");
            count += 3;
            i += 3;
        }
        else
        {
            buffer[count++] = strExt[i];
        }
    }
}

int main(int argc, char **argv)
{
    char str[SIZE] = {0}, strFinal[SIZE] = {0};

    printf("enter string:");
    fgets(str, SIZE, stdin);
    str[strcspn(str, "\n")] = '\0';

    FILE *inputFile = fopen("input.txt", "w");
    fprintf(inputFile, "%s", str);
    fclose(inputFile);

    changeName(str, strFinal);

    FILE *outputFile = fopen("output.txt", "w");
    fprintf(outputFile, "%s", strFinal);
    fclose(outputFile);

    printf("%s\n", strFinal);

    return 0;
}

