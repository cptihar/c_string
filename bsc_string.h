#ifndef _BSCSTRING_
#define _BSCSTRING_

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define  CHAR_SIZE sizeof(char)

typedef struct{
    char* character_buffer;
}bsc_string;

bsc_string bsc_initString();

size_t  bsc_strLength(const char* buffer);
bool    bsc_strContains(const char* character_buffer, char value);
bool    bsc_strCmp(const char* character_buffer, const char* string);
char*   bsc_strAlloc(const size_t amount);

void    bsc_strErase(char** character_buffer, size_t position);
void    bsc_strReverse(char* character_buffer);
void    bsc_strCat(char** character_buffer, const char* string);
void    bsc_strSet(char** character_buffer, const char* string);
void    bsc_strDelete(char** character_buffer);
void    bsc_strInsert(char** character_buffer, size_t position, char value);
#endif