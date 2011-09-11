#ifndef SYSTEM_H
#define SYSTEM_H
#define WHITE_TXT 0x0C //background,foreground color

unsigned char *memcpy(unsigned char *dest, const unsigned char *src, int count);
unsigned char *memset(unsigned char *dest, unsigned char val, int count);
unsigned short *memsetw(unsigned short *dest, unsigned short val, int count);
int strlen(const char *str);
unsigned char inportb (unsigned short _port);
void outportb (unsigned short _port, unsigned char _data);
unsigned int  kprint(char* msg,unsigned int line);
void kclrscr();

#endif
