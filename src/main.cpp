extern "C" {
// Add the header files required to run your main
#include "insertion_sort.h"
#include "linked_list.h"
#include "list_queue.h"
}

// File for sandboxing and trying out code
int main(int argc, char **argv) {
queue q;
    int x = 3;
    int x0 = 12;
    int x1 = 22;
    int y;
    int y0;
    int y1;

    // Test A
    printf("Test A: \n");
    init_queue(&q);
    if (empty(&q) == 1) {
        printf("Test A Succeded\n\n");
    } else {
        printf("Test A failed\n\n");
        abort;
    }

    // Test B
    printf("\nTest B:\n");
    enqueue(&q, x);
    y = dequeue(&q);
    if (x == y && empty(&q) == 1) {
        printf("Test B Succeded \n\n");
    } else {
        printf("Test B failed\n\n");
        abort;
    }

    // Test C
    printf("\nTest C:\n");
    enqueue(&q, x0);
    enqueue(&q, x1);
    y0 = dequeue(&q);
    y1 = dequeue(&q);
    if (x0 == y0 && x1 == y1 && empty(&q)) {
        printf("Test C Succeded \n\n");
    } else {
        printf("Test C failed\n\n");
        abort;
    } 

    return 0;
}
