
// * Loremipsum Interpreter Source Code, created by Hppsrc

// * Program that converts a string to an ASCII character.

// * Source code on: https://github.com/hppsrc/loremipsum
// * Under LGPLv3 license feel free to modify, distribute and use this code for any purpose.

#define VERSION "0.2.0-alpha"
#define BUILD "250114191"
#define STRING "LOREMIPSUM" // String has to be uppercase

#define ERROR printf_clrstr("error:", RED, NONE, END)
#define WARNING printf_clrstr("warning:", YELLOW, NONE, END)

#define ICON "myicon.ico"

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "lib/CLRSTR.h"

char _STRING_[255];
char _LOW_STRING_[255];

char* run_file(char file_name[]) {

    FILE *file;
    char content[255];
    int arr[255];
    for (size_t i = 0; i < 255; i++) { arr[i] = 0; }

    char *token = strtok(file_name, ".");
    char *last_token = token;

    while (token != NULL) {
        last_token = token;
        token = strtok(NULL, ".");
    }

    for(int i = 0; last_token[i]; i++){ last_token[i] = tolower(last_token[i]); }
    
    if ( !strcmp(last_token, _LOW_STRING_ ) ) {

        sprintf(file_name, "%s.%s", file_name, _LOW_STRING_);
        
        file = fopen(file_name, "r");

        char temp[11];
        int index = 0;
        int Arri = 0;
        arr[Arri] = 0;

        while (fgets(content, sizeof(content), file) != NULL) {

            for (int i = 0; content[i] != '\0'; i++) {

                if ( !strcmp(temp, _LOW_STRING_) ) {

                    index = 0;
                    arr[Arri]++;
                    memset(temp, 0, sizeof(temp));

                } else if ( !strcmp(temp, _STRING_) ) {

                    index = 0;
                    arr[Arri]+=32;
                    memset(temp, 0, sizeof(temp));

                } else {

                    if (content[i] != '\n') {
                        temp[index] = content[i] ;
                    }
                    index++;

                }

                // printf("CHAR ACTUAL: \"%c\"\n",content[i]);
                // printf("TEMP ACTUAL: \"%s\"\n",temp);
                // printf("INDEX ACTUAL: %d\n",index);
                // printf("BUFFER ACTUAL: %d\n", Arri);
                // for (size_t i = 0; i < 5; i++) {
                //     printf("buffer %zu: %d\n", i, arr[i]);
                // }

                if (content[i] == '\n') {
                    Arri++;
                    index--;
                }
                
            }

        }

        fclose(file);

    }
    
    int i = 0;
    char result[255];
    int pos = 0;
    while (arr[i] != 0) {
        result[pos++] = (char)arr[i];
        i++;
    }
    result[pos] = '\0';

    return strdup(result);

}

int file_check(char file_name[]) {

    FILE *file;
    char content[255];
    int arr[255];
    for (size_t i = 0; i < 255; i++) { arr[i] = 0; }

    char *token = strtok(file_name, ".");
    char *last_token = token;

    while (token != NULL) {
        last_token = token;
        token = strtok(NULL, ".");
    }

    for(int i = 0; last_token[i]; i++){ last_token[i] = tolower(last_token[i]); }

    if ( !strcmp(last_token, _LOW_STRING_) ) {

        sprintf(file_name, "%s.%s", file_name, _LOW_STRING_);
        file = fopen(file_name, "r");

        if (file == NULL) {
            printf( "Loremipsum: %s Unable to open or doesn't exist\n", printf_clrstr( "error:", RED, NONE, END));
            return 1;
        }

    } else {
        printf( "Loremipsum: %s file '%s' not allowed\n", printf_clrstr( "error:", RED, NONE, END), printf_clrstr( file_name, CYAN, NONE, END) );
        return 1;
    }

    return 0;

}

int main(int argc, char *argv[]) {

    strcpy(_STRING_, STRING);
    for(int i = 0; _STRING_[i]; i++){ _LOW_STRING_[i] = tolower(_STRING_[i]); }

    argc--;

    int o_flag = 0;
    int no_cap_flag = 0;

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

        } else {

            if (file_check(argv[1]) == 0) {
                
                printf("%s",run_file(argv[1]));
                
            }

        }

    } else if ( argc == 2 ) {

        if (!strcmp(argv[1], "--o") || !strcmp(argv[1], "--no_cap")) {

            for (int i = 1; i <= argc; i++) {
                if (!strcmp(argv[i], "--o")) { o_flag = 1; }
                if (!strcmp(argv[i], "--no_cap")) { no_cap_flag = 1; }
            }

            if ( (o_flag + no_cap_flag == 1) && file_check(argv[2]) == 0 ) {

                // create txt file
                if (o_flag==1) { printf("%s",run_file(argv[2])); }

                // create temp file lowercased
                else { printf("%s",run_file(argv[2])); }

            } else if ( (o_flag + no_cap_flag == 1) && strcmp(argv[1], "") ) {

                printf("Loremipsum: %s Unexpected additional argument: '%s'\n", ERROR,
                                                                                printf_clrstr(argv[2], CYAN, NONE, END));

            } else if ( o_flag == 1 && no_cap_flag == 1 ) {
                printf( "Loremipsum: %s file expected with '%s' and '%s' \n", ERROR,
                                                                              printf_clrstr(argv[1], CYAN, NONE, END),
                                                                              printf_clrstr(argv[2], CYAN, NONE, END));
            } 

        }  else {

            printf("Loremipsum: %s Unexpected additional argument: '%s'\n", ERROR,
                                                                            printf_clrstr(argv[2], CYAN, NONE, END));

        }

    } else if ( argc == 3 ) {

        printf("Loremipsum: %s Not implemented yet\n", WARNING);

        // if (!strcmp(argv[1], "--o") || !strcmp(argv[1], "--no_cap")) {

        //     for (int i = 1; i <= argc; i++) {
        //         if (!strcmp(argv[i], "--o")) { o_flag = 1; }
        //         if (!strcmp(argv[i], "--no_cap")) { no_cap_flag = 1; }
        //     }
            
        //     // if flag = 2 and file = good
        //     // if flag = 2 and not file = error
        //     // if 

        // }

    }  else {

        printf("Loremipsum: %s Too many arguments\n", ERROR);

    }

    return 0;

}