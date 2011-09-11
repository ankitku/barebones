#include "system.h"

void kmain( void* mbd, unsigned int magic )
{
   if ( magic != 0x2BADB002 )
   {
      /* Something went not according to specs. Print an error */
      /* msg and halt, but do *not* rely on the multiboot */
      /* data structure. */
   }
   
/* Print a letter to screen to see everything is working: */
   kprint("\a\a\a");
   kclrscr(); /*clearing screen */
   kprint("Hi! \n Ankit is too \t  coooool, YOOOOOOO",12);
}


