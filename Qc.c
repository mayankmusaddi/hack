#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int lsb=(n/4)%2;
	printf("%d\n",lsb);
	return 0;
}
