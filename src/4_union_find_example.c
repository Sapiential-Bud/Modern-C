//
// Created by WinterRain_Bud on 5/11/2025.
//
#include <stdio.h>
#include <stdlib.h>

void MakeSet(size_t N, size_t parent[static N]) {
    for (size_t i = 0; i < N; i++) {
        parent[i] = i;
    }
}

// Find with path compression
size_t Find(size_t x, size_t parent[]) {
    if (parent[x] != x) {
        parent[x] = Find(parent[x], parent);  // Path compression
    }
    return parent[x];
}

// Union by setting one root as the parent of another
void Union(size_t x, size_t y, size_t parent[]) {
    size_t rootX = Find(x, parent);
    size_t rootY = Find(y, parent);
    if (rootX != rootY) {
        parent[rootY] = rootX;  // Merge sets
    }
}

// Print the current state of the parent array
void PrintParents(size_t N, size_t parent[]) {
    printf("Parents: ");
    for (size_t i = 0; i < N; ++i) {
        printf("%zu ", parent[i]);
    }
    printf("\n");
}

int main() {
    const size_t N = 10;
    size_t parent[N];

    MakeSet(N, parent);
    PrintParents(N, parent);

    // Union some pairs
    Union(0, 1, parent);
    Union(1, 2, parent);
    Union(3, 4, parent);
    Union(4, 5, parent);
    Union(2, 4, parent);  // now all 0-5 are connected

    PrintParents(N, parent);

    // Find roots
    for (size_t i = 0; i < 6; ++i) {
        printf("Find(%zu) = %zu\n", i, Find(i, parent));
    }
    PrintParents(N, parent);

    return EXIT_SUCCESS;
}
