#include <linux/input.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {

    printf("Press ESC to exit and save output to ex2.txt\n");

    FILE *output = fopen("ex2.txt", "w");

//    int *keysPressed = calloc(sizeof(int) * 300, 0);

    int keyboard = open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY);
    struct input_event inputEvent;

    while (1) {
        read(keyboard, &inputEvent, sizeof(inputEvent));

        if(inputEvent.type == EV_KEY && inputEvent.value == 0) {
            fprintf(output, "\nRELEASED Key: 0x%04x %i\n", inputEvent.code, inputEvent.code);
            printf("\nRELEASED Key: 0x%04x %i\n", inputEvent.code, inputEvent.code);
        }
        if(inputEvent.type == EV_KEY && inputEvent.value == 1) {
            fprintf(output, "\nPRESSED Key: 0x%04x %i\n", inputEvent.code, inputEvent.code);
            printf("\nPRESSED Key: 0x%04x %i\n", inputEvent.code, inputEvent.code);
        }

        if (inputEvent.type == EV_KEY && inputEvent.code == KEY_ESC) {
            break;
        }
    }
    fclose(output);
    close(keyboard);

    return 0;
}