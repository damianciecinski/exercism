/*
 * meetup.h
 * Copyright (C) 2018 Damian Ciecinski <damianciecinski@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef MEETUP_H
#define MEETUP_H

#include <stdint.h>

int meetup_day_of_month(uint16_t year, uint8_t month, const char * descriptor, const char * day);

#endif /* !MEETUP_H */
