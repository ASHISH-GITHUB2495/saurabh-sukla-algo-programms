//printing permutations of all string
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void swap(char *x,char *y)
{
	char ch;
	ch=*x;
	*x=*y;
	*y=ch;
	
}
void permutation(char *s,int i,int n)
{
	static int count;int j;
	if(i==n)
	{
		count++;
		printf("(%d)%s\t",count,s);
		
	}
	else
	{
		for(j=i;j<=n;j++)
		{ 
			swap((s+i),(s+j));
			permutation(s,i+1,n);
			swap((s+i),(s+j));;//backtracking........
		}
	}
	
	
}


int main()
{
	
	char *str;
	printf("Enter a string\n");
	str=(char*)malloc(sizeof(char)*100);
    scanf("%s",str);
	permutation(str,0,2);
	
	return 0;
}
