#include<stdio.h>
int func(int x,int y)
{
	if(x<y)
	 return 0;
	return func(x-y,y)+1;

}
int main()
{
	int a,b;
	printf("Enter First number:");
	scanf("%d",&a);
	printf("Enter second number:");
	scanf("%d",&b);

	printf("Result:%d",func(a,b));
	return 0;
}
/*Enter First number:100
Enter second number:20
Result:5*/
