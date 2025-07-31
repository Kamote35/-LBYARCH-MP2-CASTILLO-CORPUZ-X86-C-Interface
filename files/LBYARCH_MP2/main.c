#include <stdio.h>
#include <windows.h>

// External function implemented in assembly
extern int computeAcceleration(float Vinit, float Vfinal, float time);

#define MAX_ROWS 1000
#define TRIALS 30

int main() {
    int row;
    float array[MAX_ROWS][3];     // Vi, Vf, Time
    int output[MAX_ROWS];

    LARGE_INTEGER freq, start, end;
    double totalTime = 0.0;

    QueryPerformanceFrequency(&freq);

    // Read how many rows (with input check)
    if (scanf_s("%d", &row) != 1 || row <= 0 || row > MAX_ROWS) {
        printf("Invalid number of rows.\n");
        return 1;
    }

    // Read input values for each row
    for (int i = 0; i < row; i++) {
        if (scanf_s("%f %f %f", &array[i][0], &array[i][1], &array[i][2]) != 3) {
            printf("Error: Invalid input at row %d.\n", i + 1);
            return 1;
        }
    }

    // Compute acceleration with 30 trials each
    for (int i = 0; i < row; i++) {
        double sum = 0.0;

        for (int j = 0; j < TRIALS; j++) {
            QueryPerformanceCounter(&start);
            output[i] = computeAcceleration(array[i][0], array[i][1], array[i][2]);
            QueryPerformanceCounter(&end);

            double elapsed = (double)(end.QuadPart - start.QuadPart) * 1e9 / freq.QuadPart;
            sum += elapsed;
        }

        totalTime += sum;
    }

    // Print computed results
    for (int i = 0; i < row; i++) {
        printf("%d\n", output[i]);
    }

 

    return 0;
}