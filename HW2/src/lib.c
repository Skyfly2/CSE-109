#include "whichtools.h"
#include <stdbool.h>
#include <dirent.h>
#include <string.h>
#include <stdio.h>

bool file_exists(char *path, char *file)
{
    // Initialize the directory to the passed in path
    DIR *directory = opendir(path);
    struct dirent *entry;

    // Check to make sure directory exists
    if (directory)
    {
        // Loop through the directory checking each file
        while ((entry = readdir(directory)) != NULL)
        {
            // Get the name of each file
            char *name = entry->d_name;
            // If the name matches, return true for the file existing
            if (strcmp(name, file) == 0)
            {
                return true;
            }
        }
    }
    // If the file isn't found in the directory, it doesn't exist
    return false;
}