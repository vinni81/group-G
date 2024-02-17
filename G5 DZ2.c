#include <stdio.h>
#include <ctype.h>
#define MAX_LENGTH 1000

int main()
{
    char line[MAX_LENGTH];

    printf("input data: ");
    fgets(line, sizeof(line), stdin);

    FILE *fp_input = fopen("input.txt", "w");
    fprintf(fp_input, "%s", line);
    fclose(fp_input);

    for (int i = 0; line[i] != '\0'; i++)
    {
        if (line[i] == 'a' || line[i] == 'A')
        {
            line[i] = (line[i] == 'a') ? 'b' : 'B';
        }
        else if (line[i] == 'b' || line[i] == 'B')
        {
            line[i] = (line[i] == 'b') ? 'a' : 'A';
        }
    }

    FILE *fp_output = fopen("output.txt", "w");
    fprintf(fp_output, "%s", line);
    fclose(fp_output);

    printf("output data: %s\n", line);

    return 0;
}
