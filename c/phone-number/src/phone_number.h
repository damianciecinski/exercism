/*
 * phone_number.h
 * Copyright (C) 2019 Damian Ciecinski <damianciecinski@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef _PHONE_NUMBER_H_
#define _PHONE_NUMBER_H_

/**
 * @brief Clean up differently formatted telephone numbers by removing
 *        punctuation and the country code (1) if present.
 *
 * @param input   number as text
 * @return char*  cleaned number (has to be freed)
 */
char * phone_number_clean(const char * input);

#endif /* _PHONE_NUMBER_H_ */