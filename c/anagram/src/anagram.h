/*
 * anagram.h
 * Copyright (C) 2018 Damian Ciecinski <damianciecinski@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef ANAGRAM_H
#define ANAGRAM_H

/**
 * @brief max length of the examining strings
 * 
 */
#define MAX_STR_LEN 20

/**
 * @brief status of anagram
 * 
 */
enum anagram_status 
{
   UNCHECKED = -1,
   NOT_ANAGRAM = 0,
   IS_ANAGRAM = 1
};

/**
 * @brief candidate
 * 
 */
struct candidate 
{
   enum anagram_status is_anagram;
   const char *candidate;
};

/**
 * @brief list of candidates
 * 
 */
struct candidates 
{
   struct candidate *candidate;
   size_t count;
};

/**
 * @brief Determines if any of the words in the candidate 
 *        are anagrams for word.
 * 
 * @param word          reference word
 * @param candidates    list of canditates to be examined
 */
void anagrams_for(const char *word, struct candidates *candidates);

#endif
