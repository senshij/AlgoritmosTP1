#include "config.h"
#include "input.h"
#include "output.h"
#include "date.h"
#include <stdlib.h>
#include <string.h>
#define MAX_STR 100
#define NUMBER_ARGS 3
#define FORMAT_FLAG_POSITION 1
#define FORMAT_FLAG_SPAN 4
#define FORMAT_FLAG "-fmt"
#define FORMAT_TYPE_POSITION 2
#define FORMAT_TYPE_GREGORIAN "AAAAMMDDHHmmSS"
#define FORMAT_TYPE_JULIAN "AAAADDDHHmmSS"
#define FORMAT_TYPE_GREGORIAN_SPAN 14
#define FORMAT_TYPE_JULIAN_SPAN 13

status_t validate_args(int argc, char *argv[], config_t *);
extern config_t config;

int main(int argc, char *argv[]){
    status_t st;
    time_t machine_time;
    struct tm *time_struct;
    struct tm gps_time;

    if((st=(validate_args(argc,argv, &config))) != OK){
        print_error_message(st);
        return EXIT_FAILURE;
    } 
    if (time(&machine_time) == -1){	/* Se compara con -1 porque así está definido en el estándar ANSI C '89 */
        print_error_message(ERROR_MACHINE_TIME);
        return EXIT_FAILURE;
    }   
    time_struct = localtime(&machine_time);
    while((st = parse_line(&gps_time)) != END_OF_FILE){
        if(st == ERROR_READ_LINE)
            print_error_message(st);
        if(st == FOUND){
           merge_time(gps_time, time_struct);
           print_time(*time_struct, config.format);
        }
    }
    return EXIT_SUCCESS;
}

status_t validate_args(int argc, char *argv[], config_t *config){
    if(argv == NULL || config == NULL)
	return ERROR_NULL_POINTER;
    if(argc != NUMBER_ARGS)
	return ERROR_INVALID_NUMBER_ARGS;
    if(strncmp(argv[FORMAT_FLAG_POSITION], FORMAT_FLAG, FORMAT_FLAG_SPAN))
	return ERROR_INVALID_ARGS;
    if(!strncmp(argv[FORMAT_TYPE_POSITION], FORMAT_TYPE_GREGORIAN, FORMAT_TYPE_GREGORIAN_SPAN)){
	(*config).format = GREGORIAN_FORMAT;
	return OK;
    }
    if(!strncmp(argv[FORMAT_TYPE_POSITION], FORMAT_TYPE_JULIAN, FORMAT_TYPE_JULIAN_SPAN)){
	(*config).format = JULIAN_FORMAT;
	return OK;
    }
    return ERROR_INVALID_ARGS;
}
