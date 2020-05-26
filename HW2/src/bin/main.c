#include "whichtools.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char **argv)
{
    // Create bool to check for -a flag and whether the file exists
    bool a_flag = false;
    bool exists = false;
    char *name;

    // Loop through all arguments beyond the name of the program to get flags and file name
    for (int c = 1; c < argc; c++)
    {
        // Check to see if -a flag
        if (strcmp(argv[c], "-a") == 0)
        {
            a_flag = true;
        }
        else
        {
            name = argv[c];
        }
    }

    // If there are more arguments than possible or a third argument that is '-a' return 2
    if (argc > 3 || (argc == 3 && a_flag == false))
    {
        return 2;
    }

    // Set path
    char *path = getenv("PATH");
    // Start separating path by the ':'
    char *curr = strtok(path, ":");
    while (curr != NULL)
    {
        // Show all directories the file is in
        if (a_flag)
        {
            // If the file is in the directory, print the path and set the exists flag to true
            if (file_exists(curr, name))
            {
                printf("%s%s%s\n", curr, "/", name);
                exists = true;
            }
        }
        // Non flagged functionality
        else
        {
            // If the file exists, print the path and set the exist flag to true
            if (file_exists(curr, name))
            {
                printf("%s%s%s\n", curr, "/", name);
                exists = true;
                // End after first find
                break;
            }
        }
        curr = strtok(NULL, ":");
    }
    // If the file was found, return 0
    if (exists)
    {
        return 0;
    }
    // If the file wasn't found, return 1
    else
    {
        return 1;
    }
}
