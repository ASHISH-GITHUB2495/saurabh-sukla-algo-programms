#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct ArrayQueue
{
	int front,rear;
	int capacity;
	int* array;
};
struct ArrayQueue* createQueue (int capacity)
{
	struct ArrayQueue* Q;
	Q=(struct ArrayQueue*)malloc(sizeof(struct ArrayQueue));
	Q->capacity=capacity;
	Q->front=-1;
	Q->rear=-1;
	Q->array=malloc(Q->capacity*sizeof(int));
	return Q;
	
}
int isEmpty(struct ArrayQueue* Q)
{
	if(Q->front==-1)
	   return 1;
	else 
	   return 0;
}
int isFullQueue(struct ArrayQueue* Q)
{
	if((Q->rear+1)%Q->capacity==Q->front)
	  return 1;
	else
	  return 0;
}
int queueSize(struct ArrayQueue* Q)
{
   return((Q->capacity - Q->front + Q->rear +1)%Q->capacity);
	  
}
void enQueue(struct ArrayQueue *Q,int data)
{
	if(isFullQueue(Q))
	  printf("Overflow");
	else
	{
		Q->rear=(Q->rear+1)%Q->capacity;
		Q->array[Q->rear]=data;
		if(Q ->front==-1)
		 Q->front=Q->rear;
	}
}

int deQueue (struct ArrayQueue* Q)
{
	int data=-1;
   if(isEmpty(Q)) {
   	printf("Queue is empty\n");
   	 return (-1);
   }
   else
    {
    	data=Q->array[Q->front];
    	if(Q->front==Q->rear)
    	  {
		Q->front=-1;
    	  Q->rear=-1;}
    	else
    	  Q->front=(Q->front+1)%Q->capacity;
	}
	return data;
}

void deleteQueue(struct ArrayQueue *Q)
{
	if(Q)
	 {
	 	if(Q->array)
	 	 {free(Q->array);
	 	  
		  }
		  free(Q);
		  
	 }
}


int main()
{
	struct ArrayQueue *queue;
       queue=createQueue(4);
	int choice;int item;
	while(1)
	{
	
	system("CLS");
	printf("\n1 EnQueue");
	printf("\n2 DeQueue");
	printf("\n3 exit");
	printf("\nenter your choice");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
				printf("Enter a number\n");
				scanf("%d",&item);
				enQueue(queue,item);
				sleep(1);
				break;
	    case 2:
	    	  item=deQueue(queue);
	    	  if(item==-1)
	    	   printf("queue is empty\n");
	    	 else
	    	  printf("Poped value is %d",item);
	    	  sleep(1);
	    	  break;
	    case 3:
	    	 exit(0);


	}
}
	return 0;
}






