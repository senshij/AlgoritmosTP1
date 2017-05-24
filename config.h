#include <stdio.h>

typedef enum{
    GREGORIAN_FORMAT,
    JULIAN_FORMAT,
} format_t;

typedef struct{
    format_t format
} config_t;

typedef enum{
    OK,
    ERROR_INVALID_ARGS,
    ERROR_EOF,
    ERROR_INVALID_DATA,
    ERROR_NULL_POINTER,
} status_t;
