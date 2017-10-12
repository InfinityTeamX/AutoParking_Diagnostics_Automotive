#include "stack.h"


g_errorStack_t CreateStack(g_stack_t* ps){
 ps->top=0;	
	return PASS_STACK;
}



g_errorStack_t Push(g_stack_t* ps , StackEntry value ){
	g_errorStack_t res= PASS_STACK;
	if(ps->top == MAXSIZE){
	  res=STACK_IS_FULL;
	}
	
	else{
	ps->entry[ps->top++]=value;
	}
	return res;
}

char StackIsFull(g_stack_t* ps){
	return (ps->top) >= MAXSIZE;
}

g_errorStack_t pop(g_stack_t* ps , StackEntry* value ){
	g_errorStack_t res=PASS_STACK;
	if(ps->top <= 0){
   res= STACK_IS_EMPTY;
	}
	else{
    *value = ps->entry[--(ps->top)];
	}
  return 	res;
	 
}

char StackIsEmpty(g_stack_t* ps){
	return (ps->top <=0);
	//return !(ps->top);
}

g_errorStack_t GetStackTop(g_stack_t* ps,StackEntry* value ){
		g_errorStack_t res=PASS_STACK;
	if(ps->top <= 0){
   res= STACK_IS_EMPTY;
	}
	else{
		 *value = ps->entry[(ps->top)-1];
	}
	return res;
}

uint32_t StackSize(g_stack_t* ps){
	
	return (ps->top);
}

g_errorStack_t ClearStack(g_stack_t* ps){
	
	ps->top =0;
	return PASS_STACK;
}


g_errorStack_t TraverseStack(g_stack_t* ps, void (*pfun)(StackEntry)){
	g_errorStack_t res=PASS_STACK;
	if(ps->top==0){
	 res=STACK_IS_EMPTY;
	}
	else{
		for(int i=ps->top ; i>0;i-- ){
			 (*pfun)(ps->entry[i-1]);
		}
  }
	return res;
	
}

