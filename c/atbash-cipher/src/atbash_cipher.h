/*
 * atbash_cipher.h
 * Copyright (C) 2019 Damian Ciecinski <damianciecinski@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef _ATBASH_CIPHER_H_
#define _ATBASH_CIPHER_H_

/**
 * @brief Encodes input text using atbash cipher.
 *
 * @param input   input text to encode
 * @return char*  encoded text (has to be freed)
 */
char * atbash_encode(const char * input);

/**
 * @brief Decodes input text using atbash cipher.
 *
 * @param input   input text to decode
 * @return char*  decoded text (has to be freed)
 */
char * atbash_decode(const char * input);

#endif /* _ATBASH_CIPHER_H_ */