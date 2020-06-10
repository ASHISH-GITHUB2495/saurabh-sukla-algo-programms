#include<iostream>
#include<malloc.h>
#include<conio.h>
using namespace std;
//stack implementation through array........
struct ArrayStack
{
	int top;
	int capacity;
	int *array;
};

struct ArrayStack* createStack(int cap)
 {
 	struct ArrayStack* stack = (struct ArrayStack* ) malloc (1*sizeof (struct ArrayStack ));
 	stack->capacity=cap;
 	stack->top = -1;
      stack->array = (int*)malloc(sizeof(int)*stack->capacity);
     //stack->array = (int*)malloc(stack->capacity * sizeof(int)); 
 	return (stack);
 }

 int isFull(struct ArrayStack *stack)
  {
  	if(stack->top==stack->capacity-1)
  	 return 1;
  	else
  	  return 0;

  }
  int isEmpty(struct ArrayStack *stack)
   {
   	if(stack->top==-1)
   	 return 1;
   	else
   	  return 0;
   }
   void push(struct ArrayStack *stack,int item)
   {
   	if (!isFull(stack))
   	  {
   	  	stack->top=stack->top+1;
   	  	stack->array[stack->top]=item;
		 }
     
   }


int pop(struct ArrayStack *stack)
   { int temp;
   	if(!isEmpty(stack))
   	{
   		temp=stack->array[stack->top];
   		stack->top--;
   		return temp;

	   }
	   else
	     return -1;

   }


int main()
{
	struct ArrayStack *stack;
	stack=createStack(4);
	int choice;int item;
	while(1)
	{
	
	system("CLS");
	printf("\n1 push");
	printf("\n2 pop");
	printf("\n3 exit");
	printf("\nenter your choice");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
				printf("Enter a number\n");
				scanf("%d",&item);
				push(stack,item);
				break;
	    case 2:
	    	  item=pop(stack);
	    	  if(item==-1)
	    	   printf("stack is empty\n");
	    	 else
	    	  printf("Poped value is %d",item);
	    	  break;
	    case 3:
	    	 exit(0);


	}
}
	return 0;
}


