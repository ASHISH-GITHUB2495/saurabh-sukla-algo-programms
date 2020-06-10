//binary tree representation using the traversals of preorder inorder postor
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

struct BinaryTreeNode
{
	int info;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
};

struct BinaryTreeNode* root=NULL;

struct BinaryTreeNode* createBTN()
{    int data;
	struct BinaryTreeNode* b;
	b=malloc(sizeof(struct BinaryTreeNode));
	printf("Enter info:");
	scanf("%d",&data);
	b->info=data;
   
	b->left=NULL;
	b->right=NULL;
	if(root==NULL)
	 root=b;
	else
	 { 
	    struct BinaryTreeNode* curr=root;
	    struct BinaryTreeNode* prev;
	   while(curr!=NULL)
	   { prev=curr;
	   	if((b->info)<(curr->info))
	   	  curr=curr->left;
	   	  else
	   	    curr=curr->right;
	   }
	 	if(b->info<prev->info)
	 	   prev->left=b;
	 	else
	 	   prev->right=b;

	 }
	return root;
}
void preOrder(struct BinaryTreeNode* root)
{   
   struct BinaryTreeNode* curr=root;
	if(curr!=NULL)
	{ printf("%d\t",curr->info);
	  preOrder(curr->left);
	  preOrder(curr->right);

	} 
	 
}
void inOrder(struct BinaryTreeNode* root)
{  
   struct BinaryTreeNode* curr=root;
	if(curr!=NULL)
 {
    inOrder(curr->left);
	printf("%d\t",curr->info);
    inOrder(curr->right);

	}
}
void postOrder(struct BinaryTreeNode* root)
{   
 struct BinaryTreeNode* curr=root;
	if(curr!=NULL)
	{
	  postOrder(curr->left);
	  postOrder(curr->right);
	  printf("%d\t",curr->info);
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// level Tree traversal ..with the help of queue structure and its functions
struct ArrayQueue
{
	int front,rear;
	int capacity;
	struct BinaryTreeNode** array;
};
struct ArrayQueue* createQueue (int capacity)
{
	struct ArrayQueue* Q;
	Q=(struct ArrayQueue*)malloc(sizeof(struct ArrayQueue));
	Q->capacity=capacity;
	Q->front=-1;
	Q->rear=-1;
	Q->array=malloc(Q->capacity*sizeof(struct BinaryTreeNode*));
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
void enQueue(struct ArrayQueue *Q,struct BinaryTreeNode* b)
{
	if(isFullQueue(Q))
	  return ;
	else
	{
		Q->rear=(Q->rear+1)%Q->capacity;
	    Q->array[Q->rear]=b;
		if(Q ->front==-1)
		 Q->front=Q->rear;
	}
}

struct BinaryTreeNode* deQueue (struct ArrayQueue* Q)
{
	struct BinaryTreeNode* data=NULL;
   if(isEmpty(Q)) {
  // 	printf("Queue is empty\n");
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
//Main Level Treaversal Funtion....
void levelOrder(struct BinaryTreeNode* root)
{
	struct BinaryTreeNode* temp;
	struct ArrayQueue *Q=createQueue(20);
	if(!root)
	 return;
	enQueue(Q,root);
	 while(!isEmpty(Q))
	  {
	  	temp=deQueue(Q);
	  	 printf("%d\t",temp->info);
	  	 if(temp->left)
	  	   enQueue(Q,temp->left);
	  	if(temp->right)
	  	  enQueue(Q,temp->right);
	  	  
	  }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// find operation by recursion(tail recursion)
struct BinaryTreeNode* find(struct BinaryTreeNode* root,int data)
{
	if(root==NULL)
	   return (NULL);
	if(data<root->info)
	    return(find(root->left,data));
    else if(data>root->info)
       return (find(root->right,data));
    return (root);
       
}
///delete operation..................
struct BinaryTreeNode* findMax(struct BinaryTreeNode* b)
{
  while(b->right )
    b=b->right;
     
    return (b);
}


struct BinaryTreeNode* deleteElement(struct BinaryTreeNode* root,int data)
{
	struct BinaryTreeNode* temp;
	 if(root==NULL)
	  printf("No such element exists\n");
	else if(data<root->info)
	 root->left=deleteElement(root->left,data);
	else if(data>root->info)
	root->right=deleteElement(root->right,data);
	else{
		if(root->left && root->right)
		   {
		   temp=findMax(root->left);
		   printf("\n max is %d",temp->info);
		    root->info=temp->info;
		     printf("hee1\n");
		    root->left=deleteElement(root->left,root->info);
		    printf("hee2\n");
		}
		else
		  {
		  	temp=root;
		  	if(root->left==NULL && root->right==NULL)
		  	 root=NULL;
		     else if(root->right==NULL)
		  	  root=root->left;
		  	   else
		  	     root=root->right;
		  	free(temp);
        	}	
	} return root;
	
}


///////////////////
void main()
{struct BinaryTreeNode* r=NULL;struct BinaryTreeNode* rr=NULL;
  //   r=createBTN();
     int choice,choice2,item;
	while(1)
	{
	    printf("\n1->Insetion\n");
	    printf("2->Traverse\n");
	    printf("3->FindElementAddress\n");
	    printf("4->DeleteElement\n");
	    printf("5->Exit\n");
		printf("Enter your choice:");
		 scanf("%d",&choice);
		switch(choice)
		{
			case 1: {  r = createBTN();
		         		break;
		          	}
			     
			        break;
		    case 2: 
			        printf("1- PreOrder\n");
		            printf("2- InOrder\n");
		            printf("3- PostOrder\n");
		            printf("4- LevelOrder\n");
		            scanf("%d",&choice2);
		            if(choice2==1)
		             preOrder(r);
		             else if(choice2==2)
		               inOrder(r);
		               else if(choice2==3)
		                 postOrder(r);
		                 else if(choice2==4)
		                   levelOrder(r);
		                   else
		                     printf("Wrong Input\n");
		             break;   
		    case 3:printf("Enter your element to find address\n");
		           scanf("%d",&item);
		           
				    rr=find(r,item);
		           if(rr!=NULL)
		             printf("found at %d",rr);
		            else
		              printf("this element not exists\n");
		         break;
		    case 4: printf("enter element to delete\n");
		             scanf("%d",&item);
		              rr=r;
		             r=deleteElement(rr,item);
		              sleep(2);
		    	  
		    	   break;
		    case 5: exit(0);
		}
	}
	return;
}













