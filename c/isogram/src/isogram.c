#include "isogram.h"
#include <ctype.h>
#include <string.h>
#include <stdint.h>

bool is_isogram(const char phrase[])
{
    uint8_t len = strlen(phrase);
    bool res = true;
    for(uint8_t i = 0U; i < len; i++)
    {
        if(isalpha(phrase[i]))
        {
            for(uint8_t j = i + 1; j < len; j++)
            {
                if(tolower(phrase[i]) == tolower(phrase[j]))
                {
                    res = false;
                    break;
                }
            }
        }
        
        if(false == res)
        {
            break;
        }
    }

    return res;
}

