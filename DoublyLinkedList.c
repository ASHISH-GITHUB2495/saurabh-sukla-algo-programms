#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>


struct node
{
	int info;
	struct node *prev,*next;
};

struct node *start=NULL;

void insertAtFirstNode()
{

	struct node *n;
	n=(struct node*)malloc(sizeof(struct node)*1);
	printf("Enter a info:");
	scanf("%d",&n->info);
	n->prev=NULL;
	n->next=NULL;
	if(start==NULL)
	 {
	 start=n;
	 
     }
     else
       {
         n->next=start;
         start=n;
	   }
}
void deleteFirstNode()
{
	struct node *r;
 if(start==NULL)
   printf("List is empty\n");
else
  { r=start;
    start=start->next;
    start->prev=NULL;
     free(r);
  }

}

void viewList()
{
	struct node *t;
	 if(start==NULL)
	  printf("List is emplty\n");
	 else
	  {
	  	t=start;printf("\n");
	  	 while(t->next!=NULL)
	  	 {
	  	 	printf("%d\t",t->info);
	  	 	t=t->next;
		   }
	  }
}


void main()
{  system("CLS");
	int i;
	while(1)
	{
	
	printf("1->Insert At First\n");
	printf("2->Delete At First\n");
	printf("3->Show List\n");
	printf("4->Exit\n");
	scanf("%d",&i);
	
	switch(i)
	{
		case 1: insertAtFirstNode();
		        break;
		case 2: deleteFirstNode();
		        break;
		case 3: viewList();
		        break;
		case 4: exit(0);
		        
		
	}
	
	
	
}
	
}


