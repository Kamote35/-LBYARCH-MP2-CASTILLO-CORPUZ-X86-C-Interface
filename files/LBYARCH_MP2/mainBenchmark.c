#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define MAX_ROWS 10000
#define TRIALS 30

// External assembly function
extern int computeAcceleration(float Vinit, float Vfinal, float time);

void runBenchmark(int size) {
    float array[MAX_ROWS][3]; // Vi, Vf, Time
    int output[MAX_ROWS];
    LARGE_INTEGER freq, start, end;
    double totalElapsed = 0.0;

    // Generate random input
    for (int i = 0; i < size; i++) {
        array[i][0] = (float)(rand() % 100);                  // Vinit: 0–99
        array[i][1] = array[i][0] + (float)(rand() % 50 + 1); // Vfinal > Vinit
        array[i][2] = (float)(rand() % 10 + 1);               // Time: 1–10
    }

    QueryPerformanceFrequency(&freq);

    for (int trial = 0; trial < TRIALS; trial++) {
        QueryPerformanceCounter(&start);

        for (int i = 0; i < size; i++) {
            output[i] = computeAcceleration(array[i][0], array[i][1], array[i][2]);
        }

        QueryPerformanceCounter(&end);

        double elapsed = (double)(end.QuadPart - start.QuadPart) * 1e9 / freq.QuadPart;
        totalElapsed += elapsed;
    }

    double avgTime = totalElapsed / TRIALS;
    printf("Input size: %d, Average Execution Time (30 runs): %.0f ns\n", size, avgTime);
}

int main() {
    srand((unsigned int)time(NULL));

    int sizes[] = { 10, 100, 1000, 10000 };

    for (int i = 0; i < 4; i++) {
        runBenchmark(sizes[i]);
    }

    return 0;
}
