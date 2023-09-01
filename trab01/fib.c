#include <stdlib.h>
#include <stdio.h>


void fib(int m, int n) {
    int seq[3] = {0, 1, 1};
    m -= 1;
    n -= 1;

    for (int i = 0; i <= n; i++) {
        if (i >= 2) {
            seq[2] = seq[0] + seq[1];
            seq[0] = seq[1];
            seq[1] = seq[2];
        }

        int cursor = 2;
        if (i < 3) cursor = i;

        if (i==m) {
            printf("%d", seq[cursor]);
        } else if (i > m) {
            printf(",%d", seq[cursor]);
        }
    }
}


int main(int argc, char *argv[]) {
    int m = 0;
    int n = 0;

    if (argc < 3) {
        printf("Usage: %s <m> <n>\n", argv[0]);
        return 1;
    }
     
    m = atoi(argv[1]);
    n = atoi(argv[2]);

    if (n < m) {
        printf("n must be greater than m\n");
        return 1;
    }
    if (n < 1 || m < 1) {
        printf("n and m must be greater than 0\n");
        return 1;
    }

    fib(m, n);
    printf("\n");

    return 0;
}
