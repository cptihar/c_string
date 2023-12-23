#include "bsc_string.h"
#include <stdio.h>

int main(void){

    char str[] = "1234";
    bsc_string myString = bsc_initString();

    bsc_strSet(&myString.character_buffer, "GamerLOL");

    bsc_strErase(&myString.character_buffer, 1);


    printf("%s", myString.character_buffer);
    bsc_strDelete(&myString.character_buffer);
    return 0;
}