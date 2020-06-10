//printing permutations of all string
#include<stdio.h>
#include<stdlib.h>

void swap(char *x,char *y)
{
	char ch;
	ch=*x;
	*x=*y;
	*y=ch;
	
}
void permutation(char *s,int i,int n)
{printf("yup1");
	static int count;int j;
	if(i==n)
	{
		count++;
		printf("(%d)%s\t",count,s);
		
	}
	else
	{
		for(j=i;j<=n;j++)
		{ printf("yup");
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
	gets(str);
	printf("yupM");
	permutation(str,0,2);
	
	return 0;
}
