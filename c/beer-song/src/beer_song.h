/*
 * beer_song.h
 * Copyright (C) 2018 Damian Ciecinski <damianciecinski@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef BEER_SONG_H
#define BEER_SONG_H

#include <stdint.h>

void verse(char * response, uint8_t verse);
void sing(char * response, uint8_t verse_start, uint8_t verse_stop);

#endif /* !BEER_SONG_H */
