#include"clib.h"
void gotoxy(int x, int y)
{
       COORD pos = {x,y};                 
       HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);    
       SetConsoleCursorPosition(hOut, pos);      
}
