# TP3 - Sockets

# Authors
- [Francisco Bernad](https://github.com/FrBernad)
- [Nicolás Rampoldi](https://github.com/NicolasRampoldi) 

# User manual

Compile the program and try to solve all the different ***challenges*** the ***server*** presents.

# Compilation

Execute `make` or `make all` command on your shell to compile all source files.
This will create one executable file: 
  + **server**
    
To remove these files, run `make clean` on the directory make was executed

# Testing
To test with **PVS-Studio**, **Cppcheck** and **Valgrind** run the following command:
```bash
 make test
```
The tests results can be found in the following files:
 * **PVS-Studio:** *report.tasks*
 * **Valgrind:** *results.valgrind*
 * **Cppcheck:** *output.cppOut*

To remove these files, run `make cleanTest` on the directory where `make test` was run.

