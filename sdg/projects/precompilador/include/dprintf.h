 /**
 * @file dprintf.h
 * @brief Enable or disable debug comments. 
 * 
 * By defining the macro `DEBUG` we enable to print those lines intended to be debug comments that use the macro `DPRINTF()`.
 * If the macro `DEBUG` is not defined, those lines intended to be debug comments using the macro `DPRINTF()` will not be printed on the standard output.
 * 
 * @author Departamento de Ingenieria Electronica
 * @date 2022-09-11
 */

/**
 * @def DEBUG
 * @brief The macro to enable/disable debug comments.
 * 
 * Define it somewhere before including this header `\#include "dprintf.h"`. To do so: `\#define DEBUG` 
 */

/**
 * @def DPRINTF(fmt, args...)
 * @brief Macro that prints, or not, according to the definition of `DEBUG`.
 * 
 * This macro accepts the same arguments than printf. If `DEBUG` is not defined, the macro substitutes by "nothing".
 */

#ifndef DPRINTF_H_
#define DPRINTF_H_
#ifdef DEBUG
#include <stdio.h>
#define DPRINTF(fmt, args...) printf(fmt, ## args)
#else
#define DPRINTF(fmt, args...)
#endif
#endif