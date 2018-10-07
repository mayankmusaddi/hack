#include<stdio.h>
int main()
{
	unsigned int n;
	int k;
	scanf("%u %d",&n,&k);
	unsigned int a=n^(~(1<<k));
	printf("%u\n",a);
	unsigned int b=a^(~(1<<k));
	printf("%u\n",b);
	return 0;
}
