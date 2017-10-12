






#ifndef STACK_H_
#define STACK_H_
#include <stdint.h>
#define MAXSIZE 3
#define StackEntry uint32_t
typedef struct stack
{
    StackEntry entry[MAXSIZE];
    int top;
}g_stack_t;

typedef enum Error_Stack{
	PASS_STACK,STACK_IS_FULL,STACK_IS_EMPTY
}g_errorStack_t;

g_errorStack_t CreateStack(g_stack_t* ps);
g_errorStack_t Push(g_stack_t* ps , StackEntry value );
char StackIsFull(g_stack_t* ps);
g_errorStack_t pop(g_stack_t* ps , StackEntry* value );
char StackIsEmpty(g_stack_t* ps);
g_errorStack_t GetStackTop(g_stack_t* ps,StackEntry* value );
uint32_t StackSize(g_stack_t* ps);
g_errorStack_t ClearStack(g_stack_t* ps);
g_errorStack_t TraverseStack(g_stack_t* ps, void (*pfun)(StackEntry));
#endif
