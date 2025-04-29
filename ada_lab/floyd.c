#include <stdio.h>
#define INF 99999 // A large value representing infinity

int a[10][10], D[10][10], n;

// Function declarations
void floyd(int [][10], int);
int min(int, int);

int main() {
    int i, j;

    // Input number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Input cost adjacency matrix
    printf("Enter the cost adjacency matrix (use 99999 for no direct path):\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Run Floyd-Warshall algorithm
    floyd(a, n);

    // Output final distance matrix
    printf("Distance Matrix after applying Floyd-Warshall Algorithm:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(D[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", D[i][j]);
        }
        printf("\n");
    }

    // Fix: clear input buffer to avoid instant closing
    while (getchar() != '\n'); // flush leftover newline

    // Pause before exit (for IDEs like Code::Blocks)
    printf("Press Enter to exit...");
    getchar(); // wait for actual Enter key

    return 0;
}

// Floyd-Warshall algorithm
void floyd(int a[][10], int n) {
    int i, j, k;

    // Initialize distance matrix D with input matrix a
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            D[i][j] = a[i][j];
        }
    }

    // Main Floyd-Warshall logic
    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                // Only update if paths through k are not INF
                if(D[i][k] != INF && D[k][j] != INF) {
                    D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
                }
            }
        }
    }
}

// Returns the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}
