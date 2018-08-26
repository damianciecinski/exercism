/*
 * bracket_push.c
 * Copyright (C) 2018 Damian Ciecinski <damianciecinski@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include "bracket_push.h"

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

bool is_paired(const char * inp_txt)
{
    bool res = true;

    if(inp_txt != NULL)
    {
        uint32_t len = strlen(inp_txt);

        if(len > 0)
        {
            uint32_t buf_counter = 0;
            bool is_paired = true;
            char * buf = calloc(len, sizeof(char));

            for(uint32_t c = 0U; c < len; c++)
            {
                switch(inp_txt[c])
                {
                    case '(':
                        {
                            buf[buf_counter++] = ')';
                            break;
                        }
                    case '{':
                        {
                            buf[buf_counter++] = '}';
                            break;
                        }
                    case '[':
                        {
                            buf[buf_counter++] = ']';
                            break;
                        }
                    case ')':
                    case '}':
                    case ']':
                        {
                            if(buf_counter > 0)
                            {
                                if(buf[--buf_counter] != inp_txt[c])
                                {
                                    is_paired = false;
                                }
                            }
                            else
                            {
                                is_paired = false;
                            }

                            break;
                        }
                    default:
                        {
                            /* nothing to do */
                            break;
                        }
                        
                }

                if(false == is_paired)
                {
                    break;
                }
            }

            if(true == is_paired && buf_counter == 0)
            {
                res = true;
            }
            else
            {
                res = false;
            }
        }
    }

    return res;
}

