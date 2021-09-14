#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

char** getSplitCommand(int stringLength, char* userCommand) {
    char delimiter[] = " ";
    int numberOfParameters = 0;

    char *commandCopy = malloc(sizeof(char) * (stringLength + 1));
    strcpy(commandCopy, userCommand);

    char *token = strtok(commandCopy, delimiter);

    while (token != NULL) {
        numberOfParameters++;
        token = strtok(NULL, delimiter);
    }

    char **arrayOfParameters = malloc((numberOfParameters + 1) * sizeof(char *));

    token = strtok(userCommand, delimiter);
    int i = 0;
    while (token != NULL) {

        arrayOfParameters[i] = malloc(strlen(token) * sizeof(char));
        strcpy(arrayOfParameters[i], token);

        token = strtok(NULL, delimiter);
        i++;
    }

    arrayOfParameters[i] = NULL;
    return arrayOfParameters;
}

void promptForInput() {
    printf(">>> ");
}

int main() {

    char userCommand[50];

    while (strcmp(userCommand, "exit")) {
        promptForInput();
        fgets(userCommand, sizeof(userCommand), stdin);
        userCommand[strcspn(userCommand, "\n")] = 0;
        char **args = getSplitCommand(strlen(userCommand), userCommand);

        int n = fork();
        if (n == 0) {
            execvp(args[0], args);
        }

        fflush(stdin);
        free(args);
    }
    return 0;
}


