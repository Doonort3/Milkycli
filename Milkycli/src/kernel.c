
#define LIN 25
#define COL 85
#define SCREEN LIN * COL

int current_loc_yoke = 0;
char *vidptr = (char*)0xb8000;
int i = 0;

void clear_screen(int i)
{
    while (i < SCREEN * 2)
    {
        vidptr[i++] = ' ';
        vidptr[i++] = 0x1f;
    }
    
}
void kprint(int i, const char *string)
{
    while (string[i] != '\0')
    {
        vidptr[current_loc_yoke++] = string[i++]; // First byte
        vidptr[current_loc_yoke++] = 0x1f;        // Second byte
    } 
}

void kmain(void)
{
    clear_screen(i);
    kprint(i ,"Hello, World");
}