#include "config.h"
#include "date.h"

status_t merge_time(struct tm input_time, struct tm *actual_time){
    if(actual_time == NULL)
	return ERROR_NULL_POINTER;
    (*actual_time).tm_hour = input_time.tm_hour;
    (*actual_time).tm_min  = input_time.tm_min;
    (*actual_time).tm_sec  = input_time.tm_sec;
    return OK;
}
