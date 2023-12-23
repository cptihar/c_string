#include "bsc_string.h"

/**************************************************
    Initializes a bsc_string struct
        -> Creates basic char buffer with size 0
        -> Has '\0'
    Return: bsc_string
**************************************************/
bsc_string bsc_initString()
{
    size_t defaultSize = 3;
    char* buffer = (char*)malloc(CHAR_SIZE * defaultSize);
    if(buffer != NULL){
        buffer[defaultSize-1] = '\0';
    }
    bsc_string ret;
    ret.character_buffer = buffer;
    return ret;
}

/**************************************************
    Returns the size of a null terminated string
    Return: size_t
**************************************************/   
size_t bsc_strLength(const char *buffer)
{
    size_t length = 0;
    if(buffer == NULL) return length;

    while(buffer[length] != '\0'){
        ++length;
    }
    return length;
}

/****************************************************
    Checks if a character is in the string
    Return: bool
            true = character is in the string
            false = character is not in the string
****************************************************/
bool bsc_strContains(const char *character_buffer, char value)
{
    if(character_buffer == NULL) return false;

    size_t buffer_size = bsc_strLength(character_buffer);
    for(size_t i = 0; i < buffer_size; ++i){
        if(character_buffer[i] == value)
            return true;
    }
    return false;
}

/*******************************************
    Checks if 2 strings are equal
    Return: bool
            true  = strings are equal
            false = strings are not equal
*******************************************/
bool bsc_strCmp(const char *character_buffer, const char *string)
{
    if(character_buffer == NULL || string == NULL) return false;
    
    size_t str1_length = bsc_strLength(character_buffer);
    size_t str2_length = bsc_strLength(string);

    if(str1_length != str2_length) return false;

    for(size_t i = 0; i < str1_length; ++i){
        if(character_buffer[i] != string[i]) 
            return false;
    }
    return true;
}

/**********************************************************
    Creates a null terminated string with a given size
    Memory needs to be freed manually (free())
    Return: char* or
            NULL -> Allocation failed
**********************************************************/
char *bsc_strAlloc(const size_t amount)
{
    char* buffer = (char*)malloc(CHAR_SIZE * amount);
    
    if(buffer != NULL){
        if(amount == 0) buffer[0] = '\0';
        else buffer[amount-1] = '\0';
        return buffer;
    }
    return NULL;
}

/**********************************************************
    Erases a character from a string at a given position
    Return: void
**********************************************************/
void bsc_strErase(char **character_buffer, size_t position)
{
    if (*character_buffer == NULL) return;

    size_t buff_size = bsc_strLength(*character_buffer);
    if (position >= buff_size) return;

    char *new_buffer = (char*)malloc(CHAR_SIZE * (buff_size));
    if (new_buffer != NULL) {
        memmove(new_buffer, *character_buffer, position);
        memmove(new_buffer + position, *character_buffer + position + 1, buff_size - position);
        free(*character_buffer);
        *character_buffer = new_buffer;
        (*character_buffer)[buff_size - 1] = '\0';
    }
}

/***********************
    Reverses a string
    Return: void
************************/
void bsc_strReverse(char *character_buffer)
{
    if(character_buffer == NULL) return;
    
    size_t str_len = bsc_strLength(character_buffer);
    if(str_len == 0) return;

    size_t l = 0;
    size_t h = str_len - 1;

    while(l < h){
        char temp = character_buffer[l];
        character_buffer[l] = character_buffer[h];
        character_buffer[h] = temp;
        --h;
        ++l;
    }
}

/******************************
    Concatenates two strings
    Adds '\0' to the end
    Return: void
******************************/
void bsc_strCat(char **character_buffer, const char *string)
{
    if(*character_buffer == NULL || string == NULL) return;
    
    size_t buffer_length = bsc_strLength(*character_buffer);
    size_t append_length = bsc_strLength(string);

    size_t alloc_size = buffer_length + append_length + 1;
    char* newBuffer = (char*)malloc(CHAR_SIZE * alloc_size);
    
    if(newBuffer != NULL){
        memmove(newBuffer, *character_buffer, buffer_length);
        memmove(newBuffer+buffer_length, string, append_length);
        free(*character_buffer);
        *character_buffer = newBuffer;
        (*character_buffer)[alloc_size-1] = '\0';
    }
}

/***************************************
    Sets character buffer to a string
    Adds '\0' to the end
    Return: void
***************************************/
void bsc_strSet(char **character_buffer, const char *string)
{
    if(*character_buffer == NULL || string == NULL) return;

    size_t string_length = bsc_strLength(string);
    free(*character_buffer);
    *character_buffer = (char*)malloc(CHAR_SIZE * (string_length + 1));

    if(*character_buffer != NULL){
        memmove(*character_buffer, string, string_length);
        (*character_buffer)[string_length] = '\0';
    }
}

/*************************************************
    Frees memory that was allocated to a string
    Return: void
*************************************************/
void bsc_strDelete(char** character_buffer)
{
    if(character_buffer != NULL && *character_buffer != NULL){
        free(*character_buffer);
        *character_buffer = NULL;
    }
}

/********************************************************************
    Inserts a character(value) at the given position in the buffer
    Return: void
********************************************************************/
void bsc_strInsert(char **character_buffer, size_t position, char value)
{
    if(*character_buffer == NULL) return;

    size_t buffer_length = bsc_strLength(*character_buffer);

    if(position > buffer_length) return;

    char* newBuffer = (char*)malloc(CHAR_SIZE * (buffer_length + 2));
    if(newBuffer !=  NULL){
        memmove(newBuffer, *character_buffer, position);
        newBuffer[position] = value;
        memmove(newBuffer + position + 1, *character_buffer + position, (buffer_length - position + 1));
        free(*character_buffer);
        *character_buffer = newBuffer;
        (*character_buffer)[buffer_length+1] = '\0';
    }
}
