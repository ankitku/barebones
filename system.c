#include "system.h"

unsigned char *memcpy(unsigned char *dest, const unsigned char *src, int count)
{
for(;count>0;count--)
	*dest++ = *src++; 
return dest;
}

unsigned char *memset(unsigned char *dest, unsigned char val, int count)
{
for(;count>0;count--)
	*dest++ = val;
return dest;
}

unsigned short *memsetw(unsigned short *dest, unsigned short val, int count)
{
    for( ; count != 0; count--) *dest++ = val;
    return dest;
}

int strlen(const char *str)
{
int sz;
for(sz=0; *str!='\0';str++) sz++;
return sz;
}


void kclrscr()
{
	char* vidmem = (char*) 0xb8000;
	unsigned int i = 0;
	int attrib = 0x0F;
	unsigned blank  = blank = 0x20 | (attrib << 8);

        for(i = 0; i < 25; i++)
        memsetw ((unsigned short*)vidmem + i * 80, blank, 80);

}
unsigned int  kprint(char* msg,unsigned int line)
{
	unsigned int i = line*80*2;
	char* vidmem = (char*) 0xb8000;
	
	while(*msg!=0)
	{
		if(*msg=='\n') // check for a new line
		{
			line++;
			i=(line*80*2);
			*msg++;
		} else 
		{
			vidmem[i]=*msg;
			*msg++;
			i++;
			vidmem[i]=WHITE_TXT;
			i++;
		};
	}
	return 1;
}

/* We will use this later on for reading from the I/O ports to get data
*  from devices such as the keyboard. We are using what is called
*  'inline assembly' in these routines to actually do the work */
unsigned char inportb (unsigned short _port)
{
    unsigned char rv;
    __asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));
    return rv;
}

/* We will use this to write to I/O ports to send bytes to devices. This
*  will be used in the next tutorial for changing the textmode cursor
*  position. Again, we use some inline assembly for the stuff that simply
*  cannot be done in C */
void outportb (unsigned short _port, unsigned char _data)
{
    __asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
}

