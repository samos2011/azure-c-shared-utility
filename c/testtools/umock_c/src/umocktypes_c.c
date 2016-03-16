// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <stdlib.h>
#ifdef _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif
#include <stdio.h>
#include <string.h>
#include "macro_utils.h"
#include "umocktypes.h"
#include "umocktypes_c.h"

int umocktypes_c_register_types(void)
{
    int result;

    if (umocktypes_register_type("int", (UMOCKTYPE_STRINGIFY_FUNC)umocktypes_stringify_int, (UMOCKTYPE_ARE_EQUAL_FUNC)umocktypes_are_equal_int, (UMOCKTYPE_COPY_FUNC)umocktypes_copy_int, (UMOCKTYPE_FREE_FUNC)umocktypes_free_int) != 0)
    {
        result = __LINE__;
    }
    else
    {
        result = 0;
    }

    return result;
}

#define IMPLEMENT_STRINGIFY(type, function_postfix, printf_percent) \
    char* C2(umocktypes_stringify_,function_postfix)(const type* value) \
    { \
        char* result; \
        if (value == NULL) \
        { \
            result = NULL; \
        } \
        else \
        { \
            char temp_buffer[32]; \
            int length = sprintf(temp_buffer, "%d", *value); \
            if (length < 0) \
            { \
                result = NULL; \
            } \
            else \
            { \
                result = (char*)malloc(length + 1); \
                if (result != NULL) \
                { \
                    (void)memcpy(result, temp_buffer, length + 1); \
                } \
            } \
        } \
        return result; \
    }

#define IMPLEMENT_ARE_EQUAL(type, function_postfix) \
    int C2(umocktypes_are_equal_,function_postfix)(const type* left, const type* right) \
    { \
        int result; \
        if ((left == NULL) || (right == NULL)) \
        { \
            result = -1; \
        } \
        else \
        { \
            result = ((*left) == (*right)) ? 1 : 0; \
        } \
        return result; \
    }

#define IMPLEMENT_COPY(type, function_postfix) \
    int C2(umocktypes_copy_,function_postfix)(type* destination, const type* source) \
    { \
        int result; \
        if ((destination == NULL) || \
            (source == NULL)) \
        { \
            result = __LINE__; \
        } \
        else \
        { \
            *destination = *source; \
            result = 0; \
        } \
        return result; \
    }

#define IMPLEMENT_FREE(type, function_postfix) \
    void C2(umocktypes_free_,function_postfix)(type* value) \
    { \
    }

#define IMPLEMENT_TYPE_HANDLERS(type, function_postfix, printf_percent) \
    IMPLEMENT_STRINGIFY(type, function_postfix, printf_percent) \
    IMPLEMENT_ARE_EQUAL(type, function_postfix) \
    IMPLEMENT_COPY(type, function_postfix) \
    IMPLEMENT_FREE(type, function_postfix)

/* Codes_SRS_UMOCKTYPES_C_01_002: [ umocktypes_stringify_char shall return the string representation of value. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_003: [ If value is NULL, umocktypes_stringify_char shall return NULL. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_005: [ If any other error occurs when creating the string representation, umocktypes_stringify_char shall return NULL. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_004: [ If allocating a new string to hold the string representation fails, umocktypes_stringify_char shall return NULL. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_006: [ umocktypes_are_equal_char shall compare the 2 chars pointed to by left and right. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_007: [ If any of the arguments is NULL, umocktypes_are_equal_char shall return -1. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_008: [ If the values pointed to by left and right are equal, umocktypes_are_equal_char shall return 1. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_009: [ If the values pointed to by left and right are different, umocktypes_are_equal_char shall return 0. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_010: [ umocktypes_copy_char shall copy the char value from source to destination. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_012: [ If source or destination are NULL, umocktypes_copy_char shall return a non-zero value. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_011: [ On success umocktypes_copy_char shall return 0. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_013: [ umocktypes_free_char shall do nothing. ]*/
IMPLEMENT_TYPE_HANDLERS(char, char, "%c")

/* Codes_SRS_UMOCKTYPES_C_01_014: [ umocktypes_stringify_unsignedchar shall return the string representation of value. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_015: [ If value is NULL, umocktypes_stringify_unsignedchar shall return NULL. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_017: [ If any other error occurs when creating the string representation, umocktypes_stringify_unsignedchar shall return NULL. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_016: [ If allocating a new string to hold the string representation fails, umocktypes_stringify_unsignedchar shall return NULL. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_018: [ umocktypes_are_equal_unsignedchar shall compare the 2 unsigned chars pointed to by left and right. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_019: [ If any of the arguments is NULL, umocktypes_are_equal_unsignedchar shall return -1. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_020: [ If the values pointed to by left and right are equal, umocktypes_are_equal_unsignedchar shall return 1. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_021: [ If the values pointed to by left and right are different, umocktypes_are_equal_unsignedchar shall return 0. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_022: [ umocktypes_copy_unsignedchar shall copy the unsigned char value from source to destination. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_024: [ If source or destination are NULL, umocktypes_copy_unsignedchar shall return a non-zero value. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_023: [ On success umocktypes_copy_unsignedchar shall return 0. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_025: [ umocktypes_free_unsignedchar shall do nothing. ]*/
IMPLEMENT_TYPE_HANDLERS(unsigned char, unsignedchar, "%c")

/* Codes_SRS_UMOCKTYPES_C_01_026: [ umocktypes_stringify_short shall return the string representation of value. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_027: [ If value is NULL, umocktypes_stringify_short shall return NULL. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_029: [ If any other error occurs when creating the string representation, umocktypes_stringify_short shall return NULL. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_028: [ If allocating a new string to hold the string representation fails, umocktypes_stringify_short shall return NULL. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_030: [ umocktypes_are_equal_short shall compare the 2 shorts pointed to by left and right. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_031: [ If any of the arguments is NULL, umocktypes_are_equal_short shall return -1. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_032: [ If the values pointed to by left and right are equal, umocktypes_are_equal_short shall return 1. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_033: [ If the values pointed to by left and right are different, umocktypes_are_equal_short shall return 0. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_034: [ umocktypes_copy_short shall copy the short value from source to destination. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_036: [ If source or destination are NULL, umocktypes_copy_short shall return a non-zero value. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_035: [ On success umocktypes_copy_short shall return 0. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_037: [ umocktypes_free_short shall do nothing. ]*/
IMPLEMENT_TYPE_HANDLERS(short, short, "%hd")

/* Codes_SRS_UMOCKTYPES_C_01_038: [ umocktypes_stringify_unsignedshort shall return the string representation of value. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_039: [ If value is NULL, umocktypes_stringify_unsignedshort shall return NULL. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_041: [ If any other error occurs when creating the string representation, umocktypes_stringify_unsignedshort shall return NULL. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_040: [ If allocating a new string to hold the string representation fails, umocktypes_stringify_unsignedshort shall return NULL. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_042: [ umocktypes_are_equal_unsignedshort shall compare the 2 unsigned shorts pointed to by left and right. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_043: [ If any of the arguments is NULL, umocktypes_are_equal_unsignedshort shall return -1. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_044: [ If the values pointed to by left and right are equal, umocktypes_are_equal_unsignedshort shall return 1. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_045: [ If the values pointed to by left and right are different, umocktypes_are_equal_unsignedshort shall return 0. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_046: [ umocktypes_copy_unsignedshort shall copy the unsigned short value from source to destination. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_048: [ If source or destination are NULL, umocktypes_copy_unsignedshort shall return a non-zero value. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_047: [ On success umocktypes_copy_unsignedshort shall return 0. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_049: [ umocktypes_free_unsignedshort shall do nothing. ]*/
IMPLEMENT_TYPE_HANDLERS(unsigned short, unsignedshort, "%hu")

/* Codes_SRS_UMOCKTYPES_C_01_002: [ umocktypes_stringify_int shall return the string representation of value. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_003: [ If value is NULL, umocktypes_stringify_int shall return NULL. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_005: [ If any other error occurs when creating the string representation, umocktypes_stringify_int shall return NULL. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_004: [ If allocating a new string to hold the string representation fails, umocktypes_stringify_int shall return NULL. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_006: [ umocktypes_are_equal_int shall compare the 2 ints pointed to by left and right. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_007: [ If any of the arguments is NULL, umocktypes_are_equal_int shall return -1. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_008: [ If the values pointed to by left and right are equal, umocktypes_are_equal_int shall return 1. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_009: [ If the values pointed to by left and right are different, umocktypes_are_equal_int shall return 0. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_010: [ umocktypes_copy_int shall copy the int value from source to destination. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_012: [ If source or destination are NULL, umocktypes_copy_int shall return a non-zero value. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_011: [ On success umocktypes_copy_int shall return 0. ]*/
/* Codes_SRS_UMOCKTYPES_C_01_013: [ umocktypes_free_int shall do nothing. ]*/
IMPLEMENT_TYPE_HANDLERS(int, int, "%d")