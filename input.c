#include "input.h"
#include <string.h>
#include <ctype.h>

#define ID_MSG "$GPGGA"
#define FIELD_SPAN_ID_MSG 6
#define FIELD_SPAN_TIME 6
#define FIELD_POS_TIME 7


status_t    parse_line(struct tm* time_struct){
    char line[];
     
    if (time_struct == NULL)
        return ERROR_NULL_POINTER;
    if (fgets(line, MAX - 2 ,stdin) == EOF)
        return ERROR_EOF;
    if !(strncmp (line,FIELD_SPAN_ID_MSG ,ID_MSG)){
        for(i = 0, i < FIELD_SPAN_TIME , i++){
            if (!isdigit(line[i + FIELD_POS_TIME]))
                return ERROR_READ_LINE;
            field_time[i] = line[i + FIELD_POS_TIME]; 
        }
        field_time[FIELD_SPAN_TIME + 1] = '\0'; 
       if ((st  = _parse_field_time(field_time, time_struct)) != OK)
           return ERROR_INVALID_DATA;
    }
    return OK;
}

status_t _parse_field_time(char field[], struct tm *time_struct){     
    int aux;
    int value;

    value = atoi (field);
    aux = (value /10000);
    if (aux > 23)
        return ERROR_INVALID_DATA;
    (*time_struct).tm_hour = aux;
    aux = (value%10000)/100;
    if (aux > 60)
        return ERROR_INVALID_DATA;
    (*time_struct).tm_min = aux;
 aux = (value%100);
    if (aux > 60)
        return ERROR_INVALID_DATA;
    (*time_struct).tm_sec = aux;

    return OK;
}   
     

