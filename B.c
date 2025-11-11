#include <stdio.h>

int main() {
    int l = 1, r = 1000000000;

    while (l <= r) {
        int md = l + (r - l) / 2;
        printf("%d\n", md);
        fflush(stdout);

        char x;
        scanf(" %c", &x);

        if (x == '=') {
            printf("! %d\n", md);
            fflush(stdout);
            break;
        } else if (x == '<') {
            r = md - 1;
        } else {
            l = md + 1;
        }
    }

    return 0;
}
