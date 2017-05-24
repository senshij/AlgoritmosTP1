#include "output.h"
#define MSG_ERROR_INVALID_DATA "El dato leído es inválido."
#define MSG_ERROR_EOF "Fin de archivo."
#define MSG_ERROR_INVALID_ARGS "Los argumentos ingresados son inválidos."
#define MSG_ERROR_NULL_POINTER "Error del sistema."

void print_time(stuct tm time, format_t format){
    switch(format){
        case GREGORIAN_FORMAT:
            printf("%i%i%i%i%i%i\n",\
		   1900+time.tm_year,\
		   1+time.tm_mon,\
		   time.tm_mday,\
		   time.tm_hour,\
		   time.tm_min,\
		   time.tm_sec\
		  );
	    break;
	case JULIAN_FORMAT:
	    printf("%i%i%i%i%i\n",\
		   1900+time.tm_year,\
		   1+time.tm_yday,\
		   time.tm_hour,\
		   time.tm_min,\
		   time.tm_sec\
		  );
	    break;
    } /* switch */
}

void print_error_message(status_t st){
    switch(st){
	case ERROR_INVALID_ARGS:
	    fprintf(stderr, "%s\n", MSG_ERROR_INVALID_ARGS);
	    break;
	case ERROR_EOF:
	    fprintf(stderr, "%s\n", MSG_ERROR_EOF);
	    break;
	case ERROR_INVALID_DATA:
	    fprintf(stderr, "%s\n", MSG_ERROR_INVALID_DATA);
	    break;
	case ERROR_NULL_POINTER:
	    fprintf(stderr, "%s\n", MSG_ERROR_NULL_POINTER);
	    break;
    } /* switch */
} 
