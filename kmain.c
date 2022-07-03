/**
 * @file kmain.c
 * @author Doonort3 (github.com/Doonort3)
 * @brief A kernel, clear display and write text
 * @version 0.1
 * @date 2022-07-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */


// Variables
unsigned int i = 0;
unsigned int j = 0;

char *vidptr = (char*)0xb8000;

void clear_screen(unsigned int j);
void print_string(unsigned int j, unsigned int i, const char *string);

// Entrance point. Calls the functions to clear the screen and output the string
void kmain(void) 
{
    // const char *string = "Hello, World! Yes it work!";

    clear_screen(j);
    print_string(j, i, "Hello, World! Yes it's work!");


    return;
}

// The function responsible for clearing the screen (Filling with spaces)
void clear_screen(unsigned int j) 
{
    while (j < 80 * 25 * 2) // Reserve 25 lines of 80 ASCII characters each
    {
        vidptr[j] = ' '; 
        vidptr[j+1] = 0x1f; // Color of kernel back and fore
        j = j + 2;
    }
    j = 0;
}

// The function responsible for displaying the string on the screen (Asymbolic)
void print_string(unsigned int j, unsigned int i, const char *string)  
{
    while (string[j] != '\0') // Line ending check
    {
        vidptr[i] = string[j];  // Give ascii code
        vidptr[i+1] = 0x1f;    // Set attribute-byte
        ++j; // Next char
        i = i + 2;
    }
}

