#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int min(int a, int b) {
    if (a < b) {
        return a;
    }

    return b;
}


void fib(int m, int n) {
    double golden_ratio = (1+sqrt(5))/2;
    double coef = 1/sqrt(5);

    for (int i=m; i<=n; i++) {
        int fib = (int)((coef * pow(golden_ratio, i-1)) + 0.5);

        if (i < n) {
            printf("%d,", fib);
        } else {
            printf("%d\n", fib);
        }
    }
}


void fork_fib(int m, int n) {
    int forks = 3;
    int step = (n-m+1)/forks;
    for (int i=m; i<=n; i+=step) {
        int pid = vfork();
        if (pid == 0) {
            fib(i, min(n, i+step-1));
            exit(0);
        } else if (pid < 0) {
            printf("Error: fork failed\n");
            exit(1);
        }
    }
    for (int i=m; i<=n; i+=step) {
        wait(NULL);
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

    fork_fib(m, n);

    return 0;
}
