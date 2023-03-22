#include <stdio.h>
#include <string.h>

int main() {
    char s[20] = "Hello";
    strcat(s, "World!");
    printf("%s\n", s);
}
