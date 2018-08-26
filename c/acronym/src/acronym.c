#include "acronym.h"
#include <string.h>
#include <stdint.h>
#include <ctype.h>
#include <stdlib.h>

char *abbreviate(const char *phrase)
{
    char * res = NULL;
    
    if(NULL != phrase)
    {
        uint32_t len = strlen(phrase);
        if(len > 0)
        {
            uint8_t ptr_writer = 0;
            char * acronym = (char *)calloc(2, sizeof(char));
            acronym[ptr_writer++] = toupper(phrase[0]);

            for(uint32_t i = 1U; i < len; i++)
            {
                if(phrase[i] == ' ' || phrase[i] == '-')
                {
                    acronym = realloc(acronym, ptr_writer + 2);
                    acronym[ptr_writer++] = toupper(phrase[i + 1]);
                }
            }

            acronym[ptr_writer++] = 0;
            res = acronym;
        }
    }

    return res;
}
