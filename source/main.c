#include <stdio.h>
#include <elib.h>
#include <stdlib.h>

typedef struct{
    char eapi_in;
    char *eapi_out;
    int eapi_int;
}eapi_handler_info;

typedef struct{
    int screenWidth;
    int screenHeight;
}eapi_screenInfo;

eapi_screenInfo eapi_screen_size;

eapi_handler_info eapi_io;

int eapi_handler_leave = 0;

FILE *eapi_apihandlerin;
FILE *eapi_apihandlerout;
FILE *eapi_apihandlerint;
FILE *eapi_getscreen;

int main(int argc, char* args[]){
    printf("This is the Empyrean data handler!\nIt is of no use to anyone but developers!\n");
    malloc(&eapi_out, sizeof(char*));
    eapi_apihandlerin = fopen("api_input.aio", "w+");
    eapi_apihandlerout = fopen("api_output.aio", "w+");
    eapi_apihandlerint = fopen("api_integer.aio", "w+");

    while(eapi_handler_leave == 0){
        fread(&eapi_io.eapi_in, sizeof(char), 1, eapi_apihandlerin);
        if(eapi_io.eapi_in == 'w'){
            eapi_getscreen = fopen("../../screen.sys", "r");
            fread(&eapi_screen_size, sizeof(eapi_screenInfo), 1, eapi_getscreen);
            eapi_io.eapi_int = eapi_screen_size.screenWidth;
            fclose(eapi_getscreen);
        }
        else if(eapi_io.eapi_in == 'h'){
            eapi_getscreen = fopen("../../screen.sys", "r");
            fread(&eapi_screen_size, sizeof(eapi_screenInfo), 1, eapi_getscreen);
            eapi_io.eapi_int = eapi_screen_size.screenWidth;
            fclose(eapi_getscreen);
        }
        else if(eapi_io.eapi_in == 'u'){
            eapi_io.eapi_out = "Username API not available!";
        }
        fwrite(&eapi_io.eapi_out, sizeof(char*), 1, eapi_apihandlerout);
        fwrite(&eapi_io.eapi_int, sizeof(int), 1, eapi_apihandlerint);
        fseek(eapi_apihandlerin, 0, 0);
        fseek(eapi_apihandlerout, 0, 0);
        fseek(eapi_apihandlerint, 0, 0);
    }
    return 0;
}
