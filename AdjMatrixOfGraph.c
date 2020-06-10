#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct Graph{
	int V;
	int E;
	int **Adj;
};

struct Graph* adjMatrixOfGraph(){
	int u,v,i;
	struct Graph* G=(struct Graph*)malloc(sizeof(struct Graph));
	if(!G)
	 {
	 printf("Memory Error\n");
	  return;
	  }
	printf("Enter number of nodes and no. of edges:");
	scanf("%d%d",&G->V,&G->E);
    G->Adj=(int**)malloc(sizeof(int*)*(G->V));
      for(i=0;i<(G->V);i++)
         G->Adj[i]=(int*)malloc(sizeof(int)*(G->V));
    printf("\nhelloc\n");
	 for(u=0;u<G->V;u++)
	   for(v=0;v<G->V;v++)
	     G->Adj[u][v]=0;
	     printf("\nhelloc\n");
	printf("Enter node number in a pair that connects an edge:\n");
	 for(i=0;i<G->E;i++){
	   scanf("%d%d",&u,&v);
	   G->Adj[u][v]=1;
	   G->Adj[v][u]=1;
	   
       }
	return G;
}

void printAdjMatrix(struct Graph* G)
{ int i,j;
	for(i=0;i<G->V;i++)
	 {
	   for(j=0;j<G->V;j++)
	    printf("%d  ",G->Adj[i][j]);
	      printf("\n");
        }   
}
int main()
{
  struct Graph* G=adjMatrixOfGraph();
  printAdjMatrix(G);
	
	
	return 0;
}

