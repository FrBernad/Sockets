#ifndef __LEVELS_H__
#define __LEVELS_H__

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>

int level1(FILE* clientFile, char** response, size_t size);
int level2(FILE* clientFile, char** response, size_t size);
int level3(FILE* clientFile, char** response, size_t size);
int level4(FILE* clientFile, char** response, size_t size);
int level5(FILE* clientFile, char** response, size_t size);
int level6(FILE* clientFile, char** response, size_t size) __attribute__((section(".RUN_ME")));
int level7(FILE* clientFile, char** response, size_t size);
int level8(FILE* clientFile, char** response, size_t size);
int level9(FILE* clientFile, char** response, size_t size);
int level10(FILE* clientFile, char** response, size_t size);
int level11(FILE* clientFile, char** response, size_t size);
int level12(FILE* clientFile, char** response, size_t size);

#endif