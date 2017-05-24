#include "config.h"
#include "input.h"
#include "output.h"
#include "date.h"
#include <stdlib.h>

status_t validate_args(int argc, char *argv[], *config_t);


int main(int argc, char * argv[]){
    status_t st;
    time_t machine_time;
    struct tm time_struct;
    char gps_time[MAX];

    if(st=(validate_args(argc,argv, &config)) != OK){
        print_error_message(st);
        return EXIT_FAILURE;
    } 
    if (time(&machine_time) == -1){	/* Se compara con -1 porque así está definido en el estándar ANSI C '89 */
        print_error_message(ERROR_MACHINE_TIME);
        return EXIT_FAILURE;
    }   
    time_struct = localtime(&machine_time);
    while ((st = parse_line(gps_time)) =! EOF)
    { 
        if (st == ERROR_READ_LINE)
            show_error_message(st);
        if (st == FOUND){        {
           parse_time (gps_time, time_struct);
           print_time(time_struct, config.format);
        }
    }
    printf("%s\n",MSG_PROGRAM_END);
    return EXIT_SUCCESS;
}
/*recordar validar pasaje de */
/*punteros                   */


