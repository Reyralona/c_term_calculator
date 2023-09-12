#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "conio.h"
#include "tc.h"
#include "tinyexpr.h"

#define EQUALS 10
#define CLEAR 99
#define BACKSPACE 127
#define QUIT 113

void draw_calculator()
{
    tc_clear_screen();
    printf("%s\t\n\
        --------------------------------------\n\
        |                                    |\n\
        |------------------------------------|\n\
        |   7    |    8    |    9   |    +   |\n\
        |--------|---------|--------|---------\n\
        |   4    |    5    |    6   |    -   |\n\
        |--------|---------|--------|---------\n\
        |   1    |    2    |    3   |    *   |\n\
        |--------|---------|--------|---------\n\
        |   .    |    0    |    =   |    /   |\n\
        |________|_________|________|________|\n%s", TC_GRN, TC_NRM);
}

void write_sc(char *str)
{
    tc_move_cursor(12, 3);
    printf("%s%s%s", TC_GRN, str, TC_NRM);
}
void clear_buffer(char *buff)
{
    strcpy(buff, "");
}
void double_to_char(double f, char *buffer)
{
    gcvt(f, 10, buffer);
}
void delete_last(char *buff){
    int size = strlen(buff); 
    buff[size-1] = '\0';
}

int main()
{
    int currentindex = 0;
    char bufferstring[100];
    char outbuff[50];
    char option[2];
    do
    {
        tc_move_cursor(0, 0);
        draw_calculator();
        write_sc(bufferstring);
        option[0] = c_getch();

        switch (option[0])
        {
        case EQUALS:
            clear_buffer(outbuff);
            double res = te_interp(bufferstring, 0);
            double_to_char(res, outbuff);
            clear_buffer(bufferstring);
            strcat(bufferstring, outbuff);
            break;
        case CLEAR:
            clear_buffer(bufferstring);
            break;
        case BACKSPACE:
            delete_last(bufferstring);
            break;
        default:
            strcat(bufferstring, option);
            break;
        }
    } while (option[0] != QUIT);
    tc_clear_screen();

    return 0;
}