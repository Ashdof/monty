#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIMS " \n\a\b\t"
#define INIT_STACK 0

extern char **op_toks;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* main functions */
int parse(FILE *);
int initStack(stack_t **);
void (*parseCmd(char *))(stack_t **, unsigned int);
void freeStack(stack_t **);
void freeTokens(void);
void push(stack_t **, unsigned int);
void pall(stack_t **, unsigned int);
void pint(stack_t **, unsigned int);
void pop(stack_t **, unsigned int);
void swap(stack_t **, unsigned int);
void add(stack_t **, unsigned int);
void sub(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void monty_div(stack_t **, unsigned int);
void monty_mul(stack_t **, unsigned int);
void monty_mod(stack_t **, unsigned int);
void pchar(stack_t **, unsigned int);
void pstr(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);

/* miscellaneous functions */
unsigned int tokArrLen(void);
char *getInt(int);
unsigned int _abs(int);
int getNumBaseLen(unsigned int, unsigned int);
void fillNumbaseBuff(unsigned int, unsigned int, char *, int);

/* error message */
int mallocErr(void);
void setOpTokErr(int);
int noIntErr(unsigned int);
int usageErr(void);
int openFileErr(char *);
int opCodeErr(unsigned int, char *);
int pintErr(unsigned int);
int popErr(unsigned int);
int shortStackErr(unsigned int, char *);
int divErr(unsigned int);
int pcharErr(unsigned int, char *);

#endif /* MONTY_H */
