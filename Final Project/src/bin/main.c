#include "benchmarker.h"
#include <stdio.h>
#include "hashset.h"
// I consulted my Homework 2 to remind myself about taking input from the command line
int main(int argc, char** argv)
{
    // I consulted https://www.tutorialspoint.com/cprogramming/c_file_io.htm for reading a file
    FILE *file;
    FILE *output;
    char mode = 'r';
    // Open the file
    file = fopen(argv[1], &mode);

    // Declare and initialize structures
    HashSet *hs1 = malloc(sizeof(HashSet));
    HashSet *hs2 = malloc(sizeof(HashSet));
    HashSet *hs3 = malloc(sizeof(HashSet));
    HashSet *hs4 = malloc(sizeof(HashSet));
    List *list = malloc(sizeof(List));
    initList(list);
    initHashSet(hs1, 1000);
    initHashSet(hs2, 10000);
    initHashSet(hs3, 100000);
    initHashSet(hs4, 1000000);

    // Data variables
    double ihs1Time, ihs2Time, ihs3Time, ihs4Time, ilistTime, fhs1Time, fhs2Time, fhs3Time, fhs4Time, flistTime;
    int count = 0;
    char* curr;
    
    // Loop through file
    while(fgets(curr, 255, (FILE*)file))
    {
        // Insert data into each structure and add time it takes to total time for each
        ilistTime += calcListInsertTime(list, curr);
        ihs1Time += calcHashSetInsertTime(hs1, curr, sizeof(curr));
        ihs2Time += calcHashSetInsertTime(hs2, curr, sizeof(curr));
        ihs3Time += calcHashSetInsertTime(hs3, curr, sizeof(curr));
        ihs4Time += calcHashSetInsertTime(hs4, curr, sizeof(curr));
        // Count number of URLS
        count++;
    }
    
    // Calculate average insert time
    ilistTime /= count;
    ihs1Time /= count;
    ihs2Time /= count;
    ihs3Time /= count;
    ihs4Time /= count;

    int count2 = 0;
    // Find every item
    while(count2 < count){
        // Find item in linked list
        flistTime += calcListFindTime(list, count2);
        char* item = itemAtIndex(list, count2);
        //Find item in hashsets based off of the linked list item
        fhs1Time += calcHashSetFindTime(hs1, item, sizeof(item));
        fhs2Time += calcHashSetFindTime(hs2, item, sizeof(item));
        fhs3Time += calcHashSetFindTime(hs3, item, sizeof(item));
        fhs4Time += calcHashSetFindTime(hs4, item, sizeof(item));
        count2++;
    }

    // Calculate average find time
    flistTime /= count;
    fhs1Time /= count;
    fhs2Time /= count;
    fhs3Time /= count;
    fhs4Time /= count;

    // Close file
    fclose(file);

    // Print insert times
    printf("Average Insert Time (ns)\n");
    printf("LinkedList      HashSet 1e3     HashSet 1e4     HashSet 1e5     HashSet 1e6\n");
    printf("%f\t%f\t%f\t%f\t%f\n\n", ilistTime, ihs1Time, ihs2Time, ihs3Time, ihs4Time);

    // Print find times
    printf("Average Find Time (ns)\n");
    printf("LinkedList      HashSet 1e3     HashSet 1e4     HashSet 1e5     HashSet 1e6\n");
    printf("%f\t%f\t%f\t%f\t%f\n", flistTime, fhs1Time, fhs2Time, fhs3Time, fhs4Time);
    
    
    // Free all structures (not super necessary for this program, but I guess its good practice)
    free(hs1);
    free(hs2);
    free(hs3);
    free(hs4);
    free(list);
    return 0;
}

// I recieved a segfault after the program finished executing that according to this: https://stackoverflow.com/questions/35832579/libc-start-c-no-such-file-or-directory-after-core-dump
// is not an issue with my program, but with some thing in my environment, so I was still able to get the data by 
// breaking in gdb at line 93