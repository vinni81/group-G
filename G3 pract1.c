#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 1000

int main()
{
    char line[MAX_LENGTH];
    int matching_indices[MAX_LENGTH];
    int count = 0;

    printf("input data: ");
    fgets(line, sizeof(line), stdin);
    line[strcspn(line, "\n")] = '\0';

    int line_length = strlen(line);
    if (line_length <= 1)
    {
        printf("string is empty or single symbol.\n");
        return 0;
    }
    char last_char = line[line_length - 1];

    for (int i = 0; i < line_length - 1; i++)
    {
        if (line[i] == last_char)
        {
            matching_indices[count++] = i;
        }
    }

    if (count == 0)
    {
        printf("there are no matched symbols.\n");
        return 0;
    }
    FILE *fp_input = fopen("input.txt", "w");
    fprintf(fp_input, "%s\n", line);
    fclose(fp_input);

    FILE *fp_output = fopen("output.txt", "w");
    for (int i = 0; i < count; i++)
    {
        fprintf(fp_output, "%d ", matching_indices[i]);
    }
    fclose(fp_output);

    printf("output data: ");
    for (int i = 0; i < count; i++)
    {
        printf("%d ", matching_indices[i]);
    }
    printf("\n");
    return 0;
}

