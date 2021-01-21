#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct stack{
	int top;
	unsigned size;
	int *arr;
};
struct stack* create (unsigned size)
{
	struct stack* stack =(struct stack*)malloc(sizeof(struct stack));
	stack->size;
	stack->top = -1;
	stack->arr =(int*)malloc(stack->size*sizeof(int));
	return stack;
}
int isFull(struct stack* stack)
{
	return stack->top ==stack->size -1;
}
int isEmpty(struct stack* stack)
{
	return stack->top ==-1;
}
void push(struct stack* stack,int item) 
{
	if(isFull(stack))
		          return;
	
	stack->arr [++stack->top]= item;
}
int pop(struct stack* stack)
{
	if(isEmpty(stack))
		       return-1;
	return stack->arr[stack->top--];
}
int peek(struct stack* stack)
{
	if(isEmpty(stack))
	            return ;
INT_MIN;
         return stack->arr[stack->top]			    
}
int main()
{
	struct stack* stack = create(100);
	push(stack,10);
	push(stack,20);
	push(stack,20);
	printf("%d popped\n",pop(stack));
	printf("%d popped\n",pop(stack));
	(isEmpty(stack)==-1)?printf("empty"):printf("not empty");
	return 0;
	
}
