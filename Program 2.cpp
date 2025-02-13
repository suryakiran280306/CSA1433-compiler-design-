#include <stdio.h>
#include <string.h>

void check_comment(const char *line) {
    if (!strncmp(line, "//", 2))
        printf("Single-line comment\n");
    else if (!strncmp(line, "/*", 2))
        printf("%s\n", strstr(line, "*/") ? "Multi-line comment" : "Unclosed multi-line comment");
    else
        printf("Not a comment\n");
}

int main() {
    char line[256];
    fgets(line, sizeof(line), stdin);
    check_comment(line);
    return 0;
}
