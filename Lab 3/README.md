# Makefile Lab

### Asher Hamrick

The purpose of this lab was to experiment and learn how to use makefiles in order to more easily compile projects that are developed in C. By using a Makefile, terminal commands can be entered and altered much more quickly and easily than by manually typing all of them out. This allows for better project management and a more efficient allocation of time by automating certain terminal commands.

## Build Instructions
In order to build the project run
```bash
$> make
```
This command will create a directory called build.
In build will be a directory called 'bin', containing the executable file for the project called "hello" as well as a folder called 'objects' containing the unlinked object files for all of the code in the project.

In order to clear the current build of the project run
```bash
$> make clear
```
Which will result in the build directory being cleared.