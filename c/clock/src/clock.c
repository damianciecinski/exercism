/*
 * clock.c
 * Copyright (C) 2019 Damian Ciecinski <damianciecinski@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */
#include <stdio.h>
#include <string.h>

#include "clock.h"

/**
 * @brief Parses clock in string format to minutes as integer type.
 *
 * @param clock   clock to parse
 *
 * @return int    total minutes of clock
 */
static int clock_parse(clock_t * clock)
{
   int minutes, hours;
   sscanf(clock->text, "%d:%d", &hours, &minutes);

   return minutes + hours * 60;
}

/**
 * @brief Creates clock_t struct from hour and minute as integer.
 *
 * @param hour       given hour
 * @param minute     given minute
 *
 * @return clock_t   created clock
 */
clock_t clock_create(int hour, int minute)
{
   int totalMinutes, minutes, hours;

   /* calc total minutes */
   totalMinutes = (hour * 60 + minute) % (24 * 60);
   if (totalMinutes < 0)
   {
      /* add 24 hours as total minutes is negative */
      totalMinutes += 24 * 60;
   }

   /* calc hours */
   hours = totalMinutes / 60;

   /* calc minutes */
   minutes = totalMinutes - hours * 60;

   clock_t cl;

   snprintf (cl.text, CLOCK_MAX_STR_LEN, "%02d:%02d", hours, minutes);

   return cl;
}

/**
 * @brief Adds minutes to clock.
 *
 * @param clock         main clock to which minutes will be added
 * @param minute_add    minutes to add
 *
 * @return clock_t      new clock with added minutes
 */
clock_t clock_add(clock_t * clock, int minute_add)
{
   return clock_create(0, clock_parse(clock) + minute_add);
}

/**
 * @brief Subtracts minutes from clock.
 *
 * @param clock            main clock to which minutes will be subtracted
 * @param minute_subtract  minutes to subtract
 *
 * @return clock_t         new clock with subtracted minutes
 */
clock_t clock_subtract(clock_t * clock, int minute_subtract)
{
   return clock_create(0, clock_parse(clock) - minute_subtract);
}

/**
 * @brief Compares to clocks and return result.
 *
 * @param a       first clock to compare
 * @param b       second clock to compare
 *
 * @return true   clocks are the same
 * @return false  clocks are different
 */
bool clock_is_equal(clock_t * a, clock_t * b)
{
   return (0 == strcmp(clock_create(0, clock_parse(a)).text,
                       clock_create(0, clock_parse(b)).text));
}