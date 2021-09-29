#include <stdio.h>

int main () {
    // I don't really know what is implied here, so I will simply use malloc to fix everything
    char **s = malloc(sizeof(char) * 1000);
    char foo[] = "Hello World";
    *s = foo;
    printf ( "s is %s\n", s);
    s[0] = foo;
    printf ( "s[0] is %s\n", s[0]) ;
    return (0) ;
}