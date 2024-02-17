#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 1000

int main() {
    char line[MAX_LENGTH];
    char longest_word[MAX_LENGTH] = "";
    int longest_length = 0;

    printf("enter string: ");
    fgets(line, sizeof(line), stdin);

    FILE* fp = fopen("input.txt", "w");
    fprintf(fp, "%s", line);
    fclose(fp);

    char* token = strtok(line, " ");
    while (token != NULL) {
        int current_length = strlen(token);
        if (current_length > longest_length) {
            longest_length = current_length;
            strcpy(longest_word, token);
        }
        token = strtok(NULL, " ");
    }

    fp = fopen("output.txt", "w");
    fprintf(fp, "%s", longest_word);
    fclose(fp);

    printf("%s\n", longest_word);

    return 0;
}

