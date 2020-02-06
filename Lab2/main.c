#include <stdio.h>
#include <stdbool.h>
#include <string.h> // for strcmp
#include <dirent.h>

int main(int argc, char **argv)
{

    // Set up flag variables
    bool a_flag = false;
    bool l_flag = false;

    // Check to see if flags are set in argv
    for (int c = 0; c < argc; c++)
    {
        if (strcmp(argv[c], "-a") == 0)
        {
            a_flag = true;
        }
        if (strcmp(argv[c], "-l") == 0)
        {
            l_flag = true;
        }
    }

    // Open dir
    DIR *dir = opendir(".");
    struct dirent *entry;
    // Read file
    while ((entry = readdir(dir)) != NULL)
    {
        // get name and type
        char *name = entry->d_name;
        char t = entry->d_type;

        // Convert type to C-String
        char *type;
        if (t == 4)
        {
            type = "Folder";
        }
        else
        {
            type = "File";
        }

        // Print results
        if (a_flag && l_flag)
        {
            // Print all files with file type
            printf("Name: %s\t Type: %s\n", name, type);
        }
        else if (a_flag)
        {
            // Print all files
            printf("Name: %s\n", name);
        }
        else if (l_flag)
        {
            // Compare first character of name to the ASCII value of a "."
            if (name[0] != 46)
            {
                // Assuming the file isn't hidden, print it with extra info
                printf("Name: %s\t Type: %s\n", name, type);
            }
        }
        else
        {
            // Compare first character of name to the ASCII value of a "."
            if (name[0] != 46)
            {
                // Print files that aren't hidden
                printf("Name: %s\n", name);
            }
        }
    }

    return 0;
}