#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <stdbool.h>
#include <time.h> 
#include "headers.h"
#include UTIL_HEADER
#define LINE_BUFFER 256
#define MAX_FILE_SIZE 1024

#define CHAR_COUNT 0
#define LINE_COUNT 1
#define LETTER_COUNT 2
#define WORD_COUNT 3

FILE* open_file(char* path);
void char_count(FILE* file);
void line_count(FILE* file);
void letter_count(char e, FILE* file);
//void word_count(char** word, FILE* file);


int main(int argc, char** argv) 
{   
    srand(time(NULL));

    if(argc < 2)
    {
        print_string("No arguments");
        exit(0);
    }

    FILE* file = open_file(argv[2]);
    
    int action = atoi(argv[1]);

    switch (action)
    {
    case CHAR_COUNT:
        char_count(file);
        break;
    
    case LINE_COUNT:
        line_count(file);
        break;

    case LETTER_COUNT:

        if(argv[2] == null)
        {
            print_string("No letter to search..");
            exit(0);
        }

        letter_count(argv[3][0], file);
        break;

    case WORD_COUNT:
        //word_count(" ", file);
        break;

    default:
        print_string("Unknow action");
        break;
    }

    fclose(file);
    return 0;
}

FILE* open_file(char* path)
{
    FILE* file = fopen(path,"r");

    if(file == null)
    {
        print_string("File does not exist / cannot open file");
        exit(0);
    };

    return file;
}

void letter_count(char e, FILE* file)
{
    char char_buffer[MAX_FILE_SIZE];

    memset(&char_buffer[0], 0, MAX_FILE_SIZE);

    int letter_counter = 0;

    while (1)
    {
        char* bytes_read = fgets(char_buffer, MAX_FILE_SIZE, file);

        if(bytes_read == null)
            break;
    }

    for(int i = 0; i < MAX_FILE_SIZE; i++)
        if(char_buffer[i] == e) letter_counter++;

    printf("'%c' was found %i times", e, letter_counter);
}

// void word_count(char* word, FILE* file)
// {

// }

void line_count(FILE* file)
{
    int line_count = 0;
    
    char char_buffer[LINE_BUFFER];

    memset(&char_buffer[0], 0, LINE_BUFFER);

    while (1)
    {
        if(fgets(char_buffer,LINE_BUFFER,file) != null)
            line_count++;
        else 
            break;
    }
    
    printf("%i lines in file", line_count);
}

void char_count(FILE* file)
{
    int char_count = 0;

    while (1)
    {
        char char_buffer[LINE_BUFFER]; 
        
        if(fgets(char_buffer,LINE_BUFFER,file) == null) break;

        char_count += strlen(char_buffer);
    }

    printf("%i characters in file", char_count);
}
