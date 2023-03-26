#include <stdio.h>
#include <omp.h>
#include <time.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int phi(int n) {
    int result = 1;
    for (int i = 2; i < n; i++) {
        if (gcd(i, n) == 1) {
            result++;
        }
    }
    return result;
}

int main() {
    int n = 1000;
    int num_threads = 16;

    double start_time = omp_get_wtime();

    int sum = 0;
    #pragma omp parallel for num_threads(num_threads) schedule(dynamic) reduction(+: sum)
    for (int i = 2; i <= n; i++) {
        sum += phi(i);
    }

    double end_time = omp_get_wtime();  
    double elapsed_time = end_time - start_time;

    printf("Sum of Euler totient values from 2 to %d: %d\n", n, sum);
    printf("Number of threads: %d\n", num_threads);
    printf("Execution time: %f seconds\n", elapsed_time);

    return 0;
}
