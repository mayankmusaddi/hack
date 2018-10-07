#include<stdio.h>
int main()
{
	int x;
	scanf("%d",&x);
	int sum=0;
	while(x!=0)
	{
		if(x%2==1)
			sum++;
		x=x/2;
	}
	printf("%d\n",sum++);
	return 0;
}
