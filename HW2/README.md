# Homework 2

For this assignment you will clone the `which` program and call it `my_which`. This program will search through your PATH variable to find the directory or directories in which a target program is found. For example:

```
$ my_which gcc
```

will have the output: `/usr/local/bin/gcc`. Here is the man page for which:

```
WHICH(1)                                                        General Commands Manual                                                        WHICH(1)

NAME
       which - locate a command

SYNOPSIS
       which [-a] filename ...

DESCRIPTION
       which returns the pathnames of the files (or links) which would be executed in the current environment, had its arguments been given as commands
       in a strictly POSIX-conformant shell.  It does this by searching the PATH for executable files matching the names of the arguments. It does  not
       canonicalize path names.

OPTIONS
       -a     print all matching pathnames of each argument

EXIT STATUS
       0      if all specified commands are found and executable

       1      if one or more specified commands is nonexistent or not executable

       2      if an invalid option is specified
```

Your clone should behave exactly the same way as which, including the flags and the output values. Write the logic of your function in a static library, and link to that library in `src/bin/main.c`. The library has been stubbed out with a single function that will return true if a file exists at a given path. You may implement more functions in your library as needed. Modify the Makefile to compile main.c to the executable `my_which`. Store this binary in build/bin. Store object files in build/objects. Store library in build/lib.

`make install` should move the `my_which` binary to `/root/bin`. Implement a make clean function which removes the `build` folder and all contents.



# Instructions

The process of working on assignments will proceed as follows:

1. Fork the relevant repository into your CSE 109 group namespace. [Instructions](https://docs.gitlab.com/ee/workflow/forking_workflow.html#creating-a-fork)

2. Clone your newly forked repository to your computer. Your repository should be hosted at 
```
https://gitlab.com/<your user name>-cse109/<assignment name>
```
You can use the following git command with the appropriate values substituted to customize it for you:
```
git clone https://gitlab.com/<your user name>-cse109/<assignment name>
```
[Instructions](https://docs.gitlab.com/ee/gitlab-basics/start-using-git.html#clone-a-repository) 

3. Write the necessary code to get your project to pass the tests.

4. Commit the changes you made locally to your gitlab repository. Follow the instructions [here](https://githowto.com/staging_and_committing) (read sections 6, 7 and 8) about staging and committing changes.

5. Check the status of your commit with the appropriate values substituted to customize it for you at: 
```
https://gitlab.com/<your user name>-cse109/<assignment name>/pipelines
```