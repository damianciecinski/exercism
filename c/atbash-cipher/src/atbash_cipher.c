/*
 * atbash_cipher.c
 * Copyright (C) 2019 Damian Ciecinski <damianciecinski@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>

#include "atbash_cipher.h"

/**
 * @brief Encypts single char using atbash cipher.
 *
 */
#define ENCRYPT_CHAR_TO_ATBASH(c) ('z' - ((c) - 'a'))

/**
 * @brief Collection of atbash cipher actions.
 *
 */
typedef enum
{
   ATBASH_ENCODE = 0,
   ATBASH_DECODE = 1
} atbash_action_t;


/**
 * @brief Decodes or encodes input text using atbash cipher.
 *
 * @param input   input text to encode/decode
 * @param action  action to do: ATBASH_ENCODE or ATBASH_DECODE
 * @return char*  encoded/decoded text (has to be freed)
 */
static char * atbash_converter(const char * input, atbash_action_t action)
{
   assert(action == ATBASH_ENCODE || action == ATBASH_DECODE);

   char * output = NULL;

   if(NULL != input)
   {
      uint32_t len = strlen(input);

      if(len > 0)
      {
         uint32_t it = 0, it_5 = 0;
         uint32_t output_size = len + 1;

         if(ATBASH_ENCODE == action)
         {
            output_size += (len/5);
         }
         else
         {
            output_size -= (len/5);
         }

         output = calloc(output_size, sizeof(char));

         assert(output != NULL);

         for(uint32_t i = 0; i < len; i++)
         {
            if(isalpha(input[i]) || isdigit(input[i]))
            {
               if(ATBASH_ENCODE == action)
               {
                  if(it != 0 && (it - it_5) % 5 == 0)
                  {
                     output[it++] = ' ';
                     it_5++;
                  }
               }

               if(isalpha(input[i]))
               {
                  output[it++] = ENCRYPT_CHAR_TO_ATBASH(tolower(input[i]));
               }
               else
               {
                  output[it++] = input[i];
               }
            }
         }
      }
   }

   return output;
}

/**
 * @brief Encodes input text using atbash cipher.
 *
 * @param input   input text to encode
 * @return char*  encoded text (has to be freed)
 */
char * atbash_encode(const char * input)
{
   return atbash_converter(input, ATBASH_ENCODE);
}

/**
 * @brief Decodes input text using atbash cipher.
 *
 * @param input   input text to decode
 * @return char*  decoded text (has to be freed)
 */
char * atbash_decode(const char *input)
{
   return atbash_converter(input, ATBASH_DECODE);
}