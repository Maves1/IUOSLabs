#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

int main() {

    FILE *f = fopen("ex2.txt", "w");

    char *dir = "/";

    DIR *dp = opendir(dir);
    struct dirent *entry;
    struct stat statbuf;
    chdir(dir);

    while ((entry = readdir(dp)) != NULL) {
        lstat(entry->d_name, &statbuf);
        if (strcmp(".", entry->d_name) != 0 && strcmp("..", entry->d_name) != 0) {
            printf("%s\n", entry->d_name);
            fprintf(f, "%s\n", entry->d_name);
        }
    }

    fclose(f);
    return 0;
}




