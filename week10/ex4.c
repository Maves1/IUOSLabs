#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

int main() {

    FILE *f = fopen("ex4.txt", "w");

    char *dir = "./tmp";

    DIR *dp = opendir(dir);
    struct dirent *entry;
    struct stat statbuf;
    chdir(dir);

    while ((entry = readdir(dp)) != NULL) {
        lstat(entry->d_name, &statbuf);
        if (statbuf.st_nlink > 1 && strcmp(".", entry->d_name) != 0 && strcmp("..", entry->d_name) != 0) {
            printf("%s —– ", entry->d_name);
            fprintf(f, "%s —– ", entry->d_name);

            char *newDir = ".";
            DIR *newDp = opendir(newDir);
            struct dirent *newEntry;
            struct stat newStat;

            while ((newEntry = readdir(newDp)) != NULL) {
                lstat(newEntry->d_name, &newStat);

                if (newStat.st_ino == statbuf.st_ino) {
                    printf("%s ", newEntry->d_name);
                    fprintf(f, "%s ", newEntry->d_name);
                }
            }
            printf("\n");
            fprintf(f, "\n");
        }
    }

    fclose(f);
    return 0;
}




