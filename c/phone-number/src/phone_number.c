/*
 * phone_number.c
 * Copyright (C) 2019 Damian Ciecinski <damianciecinski@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>

#include "phone_number.h"

/**
 * @brief Define the digit number for numbers w/o the country code.
 *
 */
#define PHONE_NUM_DIGIT_NUM_W_COUNTRY_CODE  (11u)
#define PHONE_NUM_DIGIT_NUM_WO_COUNTRY_CODE (10u)

/**
 * @brief Defines the country code for NANP.
 *
 */
#define PHONE_NUM_COUNTRY_CODE ('1')

/**
 * @brief Defines indexes of AREA and EXCHANGE codes in the phone number.
 *
 */
#define PHONE_NUM_AREA_CODE_IDX     (0u)
#define PHONE_NUM_EXCHANGE_CODE_IDX (3u)

/**
 * @brief Define the range of possible values for EXCHANGE CODE.
 *
 */
#define PHONE_NUM_EXCHANGE_CODE_RANGE_MIN ('2')
#define PHONE_NUM_EXCHANGE_CODE_RANGE_MAX ('9')

/**
 * @brief Define the range of possible values for AREA CODE.
 *
 */
#define PHONE_NUM_AREA_CODE_RANGE_MIN ('2')
#define PHONE_NUM_AREA_CODE_RANGE_MAX ('9')


char * phone_number_clean(const char * input)
{
   size_t input_len = strlen(input);
   size_t output_it = 0;
   bool invalidNumber = false;
   char * output = calloc((PHONE_NUM_DIGIT_NUM_W_COUNTRY_CODE + 1), sizeof(char));

   assert(output != NULL);

   for(size_t i = 0; i < input_len; i++)
   {
      if(isalpha(input[i]))
      {
         invalidNumber = true;
         break;
      }
      else if(isdigit(input[i]))
      {
         if(output_it < PHONE_NUM_DIGIT_NUM_W_COUNTRY_CODE)
         {
            output[output_it++] = input[i];
         }
         else
         {
            invalidNumber = true;
            break;
         }
      }
   }

   if(false == invalidNumber)
   {
      do
      {
         /* validation of the length of the number phone */
         if(output_it < PHONE_NUM_DIGIT_NUM_WO_COUNTRY_CODE)
         {
            invalidNumber = true;
            break;
         }

         /* validation of the country code */
         if(output_it == PHONE_NUM_DIGIT_NUM_W_COUNTRY_CODE)
         {
            if(output[0] != PHONE_NUM_COUNTRY_CODE)
            {
               invalidNumber = true;
               break;
            }
            else
            {
               for(size_t i = 0; i < PHONE_NUM_DIGIT_NUM_W_COUNTRY_CODE; i++)
               {
                  output[i] = output[i + 1];
               }
            }
         }

         /* validation of AREA CODE */
         if(!(output[PHONE_NUM_AREA_CODE_IDX] >= PHONE_NUM_AREA_CODE_RANGE_MIN &&
          output[PHONE_NUM_AREA_CODE_IDX] <= PHONE_NUM_AREA_CODE_RANGE_MAX))
         {
            invalidNumber = true;
            break;
         }

         /* validation of EXCHANGE CODE */
         if(!(output[PHONE_NUM_EXCHANGE_CODE_IDX] >= PHONE_NUM_EXCHANGE_CODE_RANGE_MIN &&
          output[PHONE_NUM_EXCHANGE_CODE_IDX] <= PHONE_NUM_EXCHANGE_CODE_RANGE_MAX))
         {
            invalidNumber = true;
            break;
         }

      } while (0);
   }

   if(invalidNumber)
   {
      memset (output, '0', PHONE_NUM_DIGIT_NUM_WO_COUNTRY_CODE * sizeof(char));
      output[PHONE_NUM_DIGIT_NUM_WO_COUNTRY_CODE] = 0;
   }

   return output;
}