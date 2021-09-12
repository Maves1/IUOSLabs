#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main() {

    char userCommand[50];
    printf("> ");
    scanf("%s", userCommand);
    while (strcmp(userCommand, "exit")) {
        system(userCommand);
        scanf("%s", userCommand);
        printf("> ");
    }
    return 0;
}


