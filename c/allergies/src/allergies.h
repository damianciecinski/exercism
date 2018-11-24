/*
 * allergies.h
 * Copyright (C) 2018 Damian Ciecinski <damianciecinski@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef ALLERGIES_H
#define ALLERGIES_H

#include <stdbool.h>

typedef enum {
   ALLERGEN_EGGS = 0,
   ALLERGEN_PEANUTS = 1,
   ALLERGEN_SHELLFISH = 2,
   ALLERGEN_STRAWBERRIES = 3,
   ALLERGEN_TOMATOES = 4,
   ALLERGEN_CHOCOLATE = 5,
   ALLERGEN_POLLEN = 6,
   ALLERGEN_CATS = 7,
   ALLERGEN_COUNT = 8
} allergen_t;

typedef struct {
   int count;
   allergen_t *allergens;
} allergen_list_t;

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
bool is_allergic_to(allergen_t allergen, uint32_t score);

/**
 * @brief Base on the person's allergy score determine full list of allergies.
 * 
 * @param score             allergy score
 * @param allergen_list     pointer to allergen list through which the result 
 *                          will be returned
 */
void get_allergens(uint32_t score, allergen_list_t * allergen_list);

#endif
