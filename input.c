#include "config.h"
#include "input.h"
#include <string.h>
#include <ctype.h>

#define ID_MSG "$GPGGA"
#define FIELD_SPAN_ID_MSG 6
#define FIELD_SPAN_TIME 6
#define FIELD_POS_TIME 7
#define MAX_LINE 100

status_t _parse_field_time(char *, struct tm *);

status_t parse_line(struct tm *time_struct){
    status_t st;
    char line[MAX_LINE];
    char field_time[MAX_LINE];
    size_t i;
     
    if(time_struct == NULL)
        return ERROR_NULL_POINTER;
    if(fgets(line, MAX_LINE - 2 ,stdin) == NULL)
        return ERROR_EOF;
    if(!strncmp(line, ID_MSG, FIELD_SPAN_ID_MSG)){
        for(i = 0; i < FIELD_SPAN_TIME; i++){
            if (!isdigit(line[i + FIELD_POS_TIME]))
                return ERROR_READ_LINE;
            field_time[i] = line[i + FIELD_POS_TIME]; 
        }
        field_time[FIELD_SPAN_TIME + 1] = '\0'; 
       if((st  = _parse_field_time(field_time, time_struct)) != OK)
           return ERROR_INVALID_DATA;
       return FOUND;
    }
    return NOT_FOUND;
}

status_t _parse_field_time(char field[], struct tm *time_struct){     
    int aux;
    int value;

    value = atoi (field);
    aux = (value /10000);
    if(aux > 23)
        return ERROR_INVALID_DATA;
    (*time_struct).tm_hour = aux;
    aux = (value%10000)/100;
    if(aux > 60)
        return ERROR_INVALID_DATA;
    (*time_struct).tm_min = aux;
 aux = (value%100);
    if(aux > 60)
        return ERROR_INVALID_DATA;
    (*time_struct).tm_sec = aux;

    return OK;
}   
     

