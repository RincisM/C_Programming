#include<stdio.h>
int fun(int m,int n)
{
	if(m==0 || m>=n>=1)
	  return 1;
	return fun(m-1,n)+fun(m-1,n-1);

}
int main()
{
	int a,b;
	printf("Enter First number:");
	scanf("%d",&a);
	printf("Enter second number:");
	scanf("%d",&b);

	printf("f(%d, %d) is %d\n", a, b, fun(a,b));
	return 0;
}
/*Enter First number:5
Enter second number:50
Result:32*/
