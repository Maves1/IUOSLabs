#include <linux/input.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {

    printf("Press ESC to exit and save output to ex3.txt\n");
    printf("Try C+A+P, P+E, A+E and see what happens!\n");

    FILE *output = fopen("ex3.txt", "w");

    int keysQuantity = 300;
    int *keysPressed = calloc(sizeof(int) * keysQuantity, 0);

    int keyboard = open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY);
    struct input_event inputEvent;

    int shortcutExecuted = 0;
    while (1) {
        read(keyboard, &inputEvent, sizeof(inputEvent));

        if(inputEvent.type == EV_KEY && inputEvent.value == 0) {
            shortcutExecuted = 0;
            keysPressed[(int) inputEvent.code] = 0;
        }
        if(inputEvent.type == EV_KEY && inputEvent.value == 1) {
            keysPressed[(int) inputEvent.code] = 1;
        }

        for (int i = 0; i < keysQuantity; i++) {
            if (keysPressed[46] == 1 && keysPressed[30] == 1 && keysPressed[25] == 1 && shortcutExecuted == 0) {
                shortcutExecuted = 1;
                fprintf(output, "Get some cappuccino!\n");
                printf("Get some cappuccino!\n");
            }
            if (keysPressed[25] == 1 && keysPressed[18] == 1 && shortcutExecuted == 0) {
            	shortcutExecuted = 1;
                fprintf(output, "I passed the exam!\n");
                printf("I passed the exam!\n");
            }
            if (keysPressed[18] == 1 && keysPressed[30] == 1 && shortcutExecuted == 0) {
            	shortcutExecuted = 1;
                fprintf(output, "Even aced the exam!\n");
                printf("Even aced the exam!\n");
            }
        }

        if (inputEvent.type == EV_KEY && inputEvent.code == KEY_ESC) {
            break;
        }
    }
    fclose(output);
    close(keyboard);

    return 0;
}
