#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct ListNode{
	int vertexNo;
	struct ListNode* next;
};
struct Graph{
	int V;
	int E;
	struct ListNode* Adj;
};

struct Graph* adjListOfGraph(){
	int i,x,y;
	struct ListNode* temp,* t;
	struct Graph* G;
	G=(struct Graph*)malloc(sizeof(struct Graph));
	printf("Enter number of vertices and number of edges:\n");
	scanf("%d%d",&G->V,&G->E);
	 G->Adj=(struct ListNode*) malloc(G->V * sizeof(struct ListNode));
	 for(i=0;i<G->V;i++)
	 {
	 	(G->Adj+i)->vertexNo=i;
	    (G->Adj+i)->next = G->Adj+i;//////maniulated
	 }
     for(i=0;i<G->E;i++)
     { printf("Enter edge (src to dest):\n");
       scanf("%d%d",&x,&y);
       temp=(struct ListNode*)malloc(sizeof(struct ListNode));
       temp->vertexNo=y;
       temp->next=G->Adj+x;
       //
       t=G->Adj+x;
       while(t->next!=G->Adj+x)
         t=t->next;  
        
        t->next=temp;
     	
	 }
	 return (G);
}
void printAdjList(struct Graph* G )
{  int i,j; struct ListNode* t;
	for(i=0;i<G->V;i++)
	{ printf("head %d ",i);t=G->Adj+i;
	    do
	   {
	   	 printf(" -> %d",t->vertexNo);
	   	 t=t->next;
	   }while(t->next!=G->Adj+i);
	    printf("\n");
	   
	}
}

int main()
{  struct Graph *G=adjListOfGraph();
    printAdjList(G);
    
	
	
	return 0;
}






