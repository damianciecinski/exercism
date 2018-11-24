/*
 * allergies.c
 * Copyright (C) 2018 Damian Ciecinski <damianciecinski@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "allergies.h"

/**
 * @brief Calculate alergen value.
 * 
 */
#define ALLERGEN_VALUE(ALLERGEN) (1 << (ALLERGEN))

/**
 * @brief Size of list will be allocated for allergens.
 * 
 */
#define MAX_ALLEGRENS_IN_LIST (32)

/**
 * @brief Align to the allowed score, it removes allergens 
 *        from out of scale.
 * 
 * @param score     allergy score
 */
static inline void align_to_allowed_score(uint32_t * score)
{
    *score &= ALLERGEN_VALUE(ALLERGEN_COUNT) - 1;
}

/**
 * @brief Determine the count of allergens in person's allergy score, 
 *        if allergens are found, the score is decreased about the value 
 *        of considered allergen.
 * 
 * @param score     pointer to allergy score
 * @param allergen  allergen to be considered
 * 
 * @return uint32_t count of allergens in person's score
 */
static inline uint32_t is_allergen(uint32_t * score, allergen_t allergen)
{
    uint32_t allergen_score = ALLERGEN_VALUE(allergen), count_allergen = 0;

    while(*score >= allergen_score) 
    {
        count_allergen++;
        *score -= allergen_score;
    }

    return count_allergen;
}

/**
 * @brief Base on the person's allergy score, determine 
 *        whether or not they're allergic to a given item.
 * 
 * @param allergen  allergen to be considered
 * @param score     allergy score
 * 
 * @return true     person is allergic to a given allergen
 * @return false    person is not allergic to a given allergen
 */
bool is_allergic_to(allergen_t allergen, uint32_t score)
{
    bool res = false;

    if(allergen < ALLERGEN_COUNT)
    {
        align_to_allowed_score(&score);

        for(int8_t a = (ALLERGEN_COUNT - 1); a >= 0; a--)
        {
            uint32_t count_allergen = is_allergen(&score, a);
            if(allergen == (uint8_t)(a))
            {
                if(count_allergen > 0)
                {
                    res = true;
                }
                break;
            }
        }
    }

    return res;
}

/**
 * @brief Base on the person's allergy score determine full list of allergies.
 * 
 * @param score             allergy score
 * @param allergen_list     pointer to allergen list through which the result 
 *                          will be returned
 */
void get_allergens(uint32_t score, allergen_list_t * allergen_list)
{
    if(allergen_list != NULL)
    {
        uint8_t allergen_counter = 0;
        allergen_list->count = 0;
        allergen_list->allergens = calloc(MAX_ALLEGRENS_IN_LIST, sizeof(allergen_t));
        
        align_to_allowed_score(&score);

        for(int8_t a = (ALLERGEN_COUNT - 1); a >= 0; a--)
        {
            uint32_t count_allergen = is_allergen(&score, a);
            if(count_allergen > 0 && allergen_counter < MAX_ALLEGRENS_IN_LIST)
            {
                allergen_list->count += count_allergen;
                allergen_list->allergens[allergen_counter++] = a;
            }
        }
    }
}