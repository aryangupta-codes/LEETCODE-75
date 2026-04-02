#include <stdbool.h>
#include <stdio.h>

bool isSubsequence(char * s, char * t) {
    while (*s && *t) {
        if (*s == *t) {
            s++;
        }
        t++;
    }
    return *s == '\0';
}

int main() {
    char *s1 = "abc";
    char *t1 = "ahbgdc";
    
    if (isSubsequence(s1, t1)) {
        printf("Example 1: true\n");
    } else {
        printf("Example 1: false\n");
    }

    return 0;
}