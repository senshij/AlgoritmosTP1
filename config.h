typedef struct{
    format_t format
} config_t;

typedef enum{
    ERROR,
    OK,
    ERROR_READ,
    END_OF_FILE,
} status_t;

status_t validate_args(int argc, char *argv[], *config_t);
