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

bool is_allergic_to(allergen_t allergen, uint32_t score);
void get_allergens(uint32_t score, allergen_list_t * allergen_list);

#endif
