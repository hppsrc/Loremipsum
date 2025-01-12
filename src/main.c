
// * Loremipsum Interpreter Source Code, created by Hppsrc

// * Program that converts a string to an ASCII character.

// * Source code on: https://github.com/hppsrc/loremipsum
// * Under LGPLv3 license feel free to modify, distribute and use this code for any purpose.

#define VERSION "0.1.0-alpha"
#define BUILD "250112151"
#define STRING "Loremipsum"

#define ERROR printf_clrstr("error:", RED, NONE, END)

#include <stdio.h>
#include <stdlib.h>

#include "lib/CLRSTR.h"

// TODO file check action

int main(int argc, char *argv[]) {

    argc--;

    int o_flag = 0;
    int no_cap_flag = 0;
    int intr_flag = 0;

    if( argc == 0 ) {

        printf( "Loremipsum: %s no input files\n", printf_clrstr( "error:", RED, NONE, END) );

    } else if ( argc == 1 ) {

        // is parameter?
        if ( argv[1][0] == '-' ) { 

            if ( !strcmp(argv[1], "--help") ) {

                printf("OVERVIEW: Loremipsum Interpreter\n\nUSAGE: %s [option] file...\n\nOPTIONS:\n\n", printf_clrstr("lintr.exe", YELLOW, NONE, END));
                printf("  %s\t\tTranscribe the .loremipsum file into a .txt.\n", printf_clrstr("--o", CYAN, NONE, END));
                printf("  %s\t\tOpen Loremipsum github repo.\n", printf_clrstr("--git", CYAN, NONE, END));
                printf("  %s\tGet this message.\n", printf_clrstr("--help", CYAN, NONE, END));
                printf("  %s\tGet the executable version.\n", printf_clrstr("--version", CYAN, NONE, END));
                printf("  %s\tIgnore whether a string is capitalized or not.\n", printf_clrstr("--no_cap", CYAN, NONE, END));
                printf("\n");

            } else if ( !strcmp(argv[1], "--version") ) {

                printf("Loremipsum Interpreter Version %s (Build %s)\n", printf_clrstr(VERSION, GREEN, NONE, END),
                                                                         printf_clrstr(BUILD, CYAN, NONE, END));
                printf("Copyright (c) 2025 %s. Licensed under the %s License.\n",printf_clrstr("Hppsrc", YELLOW, NONE, END),
                                                                         printf_clrstr("LGPLv3", GREEN, NONE, END));

            } else if ( !strcmp(argv[1], "--git") ) {

                #ifdef _WIN32
                    system("start https://github.com/hppsrc/loremipsum");
                #else
                    system("xdg-open https://github.com/hppsrc/loremipsum");
                #endif

            } else if ( !strcmp(argv[1], "--o") ) {

                printf( "Loremipsum: %s file expected with '%s'\n", ERROR,
                                                                    printf_clrstr("--o", CYAN, NONE, END) );

            } else if ( !strcmp(argv[1], "--no_cap") ) {

                printf( "Loremipsum: %s file expected with '%s'\n", ERROR,
                                                                    printf_clrstr("--no_cap", CYAN, NONE, END));

            } else {

                printf( "Loremipsum: %s Unknown command '%s'\n", ERROR,
                                                                    printf_clrstr(argv[1], CYAN, NONE, END) );
                
            }

        } 

        // TODO is file .loremipsum file? if so, set intr to 1, else -1

    } else if ( argc == 2 ) {

        // TODO add 1st arg func check

        if (!strcmp(argv[1], "--o") || !strcmp(argv[1], "--no_cap")) {

            for (int i = 1; i <= argc; i++) {
                if (!strcmp(argv[i], "--o")) { o_flag = 1; }
                if (!strcmp(argv[i], "--no_cap")) { no_cap_flag = 1; }
            }

            if ( (o_flag + no_cap_flag == 1) && strcmp(argv[1], "") ) {

                printf("Loremipsum: %s Unexpected additional argument: '%s'\n", ERROR,
                                                                                printf_clrstr(argv[2], CYAN, NONE, END));

            } else if ( o_flag == 1 && no_cap_flag == 1 ) {
                printf( "Loremipsum: %s file expected with '%s' and '%s' \n", ERROR,
                                                                         printf_clrstr(argv[1], CYAN, NONE, END),
                                                                         printf_clrstr(argv[2], CYAN, NONE, END));
            } else if ( o_flag == 1 ) {
                // TODO is file .loremipsum file? if so, set intr to 1, else -1
            } else if ( no_cap_flag == 1 ) {
                // TODO is file .loremipsum file? if so, set intr to 1, else -1
            }

        }  else {

            printf("Loremipsum: %s Unexpected additional argument: '%s'\n", ERROR,
                                                                            printf_clrstr(argv[2], CYAN, NONE, END));

        }

    } else if ( argc == 3 ) {

        if (!strcmp(argv[1], "--o") || !strcmp(argv[1], "--no_cap")) {

            for (int i = 1; i <= argc; i++) {
                if (!strcmp(argv[i], "--o")) { o_flag = 1; }
                if (!strcmp(argv[i], "--no_cap")) { no_cap_flag = 1; }
            }
            
            // if flag = 2 and file = good
            // if flag = 2 and not file = error
            // if 

        }

    }  else {

        printf("Loremipsum: %s Too many arguments\n", ERROR);

    }

    // TODO if intr = 1 start action, else error

    return 0;

}