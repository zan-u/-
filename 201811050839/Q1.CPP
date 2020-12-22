//编写一个fun函数
#include<stdio.h>
#include<iostream.h>
int main()
{
    int fun(int a,int b);
	void fun2(int &x,int &y,int &z);
	void fun3(int *x,int *y,int *z);
    int a,b,c;
    //printf("Please enter 两个两位数 a,b:\n");
   // scanf("%d,%d",&a,&b);  //接收正整数a
	cout<<"请输入两个正整数a b"<<endl;
    cin>>a>>b;
    c=fun(a,b);  //通过返回值将c值传给主参数
    printf("合成数 c is %d\n",c);  //输出正整数c
	
	printf("Please enter 两个两位数 a,b:\n");
    scanf("%d,%d",&a,&b);  //接收正整数

    fun2(a,b,c);
    printf("合成数2 c is %d\n",c);
	cout<<"请输入两个正整数a b"<<endl;
    cin>>a>>b;
	fun3(&a,&b,&c);
    printf("合成数 c is %d\n",c);  //输出正整数c

    return 0;
}
int fun(int a,int b)
{
    int c1,c2,c3,c4;  //c1、c2、c3、c4分别对应c的千位、百位、十位、个位
    c1=a%10;
    c2=b%10;
    c3=a/10;
    c4=b/10;
    return (c1*1000+c2*100+c3*10+c4);
}
//参数传递
void fun2(int &x,int &y,int &z)
{
    int c1,c2,c3,c4;  //c1、c2、c3、c4分别对应c的千位、百位、十位、个位
    c1=x%10;
    c2=y%10;
    c3=x/10;
    c4=y/10;
	z=c1*1000+c2*100+c3*10+c4;
}
//指针传递
void fun3(int *x,int *y,int *z)
{
    int c1,c2,c3,c4;  //c1、c2、c3、c4分别对应c的千位、百位、十位、个位
    c1=*x%10; //实际调用时，x得到的实参是a的地址&a，所以*x代表的就是a
    c2=*y%10;
    c3=*x/10;
    c4=*y/10;
	*z=c1*1000+c2*100+c3*10+c4;
}