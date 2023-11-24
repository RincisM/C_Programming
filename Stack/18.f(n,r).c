#include<stdio.h>
int fun(int n,int r)
{
	if(r==0)
	  return 1;
	if(n==0)
	  return 1;
	return fun(n-1,r)+fun(n-1,r-1);

}
int main()
{
	int a,b;
	printf("Enter First number:");
	scanf("%d",&a);
	printf("Enter second number:");
	scanf("%d",&b);

	printf("Result:%d",fun(a,b));
	return 0;
}
/*Enter First number:100
Enter second number:20
Result:5*/
