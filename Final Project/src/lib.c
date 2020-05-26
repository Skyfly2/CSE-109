#include "benchmarker.h"
#include <time.h>
#include "hashset.h"
#define BILLION 1000000000.0

// I consulted the provided repl.it at https://repl.it/repls/QuarterlyWelltodoChapters for the timing
double calcListInsertTime(List* list, void* item){
    struct timespec start, end;

    // Get start time
    clock_gettime(CLOCK_REALTIME, &start);
    insertAtTail(list, item);
    // Get end time
    clock_gettime(CLOCK_REALTIME, &end);

    // Calculate difference
    double time = (end.tv_sec - start.tv_sec) * BILLION + (end.tv_nsec - start.tv_nsec);
    return time;
}

// I consulted the provided repl.it at https://repl.it/repls/QuarterlyWelltodoChapters for the timing
double calcHashSetInsertTime(HashSet* hs, void* item, unsigned int size){
    struct timespec start, end;

    // Get start time
    clock_gettime(CLOCK_REALTIME, &start);
    insertItem(hs, item, size);
    // Get end time
    clock_gettime(CLOCK_REALTIME, &end);

    // Calculate difference
    double time = (end.tv_sec - start.tv_sec) * BILLION + (end.tv_nsec - start.tv_nsec);
    return time;
}

// I consulted the provided repl.it at https://repl.it/repls/QuarterlyWelltodoChapters for the timing
double calcListFindTime(List* list, int index){
    struct timespec start, end;

    // Get start time
    clock_gettime(CLOCK_REALTIME, &start);
    itemAtIndex(list, index);
    // Get end time
    clock_gettime(CLOCK_REALTIME, &end);

    // Calculate difference
    double time = (end.tv_sec - start.tv_sec) * BILLION + (end.tv_nsec - start.tv_nsec);
    return time;
}

// I consulted the provided repl.it at https://repl.it/repls/QuarterlyWelltodoChapters for the timing
double calcHashSetFindTime(HashSet* hs, void* item, int size){
    struct timespec start, end;

    // Get start time
    clock_gettime(CLOCK_REALTIME, &start);
    findItem(hs, item, size);
    // Get end time
    clock_gettime(CLOCK_REALTIME, &end);

    // Calculate difference
    double time = (end.tv_sec - start.tv_sec) * BILLION + (end.tv_nsec - start.tv_nsec);
    return time;
}