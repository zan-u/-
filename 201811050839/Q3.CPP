#include <stdio.h>
#include <iostream>
using namespace std;
int i,j;
struct score
{
int chinese;
int math;
int english;
//int sum;
//int id;
};
struct score2
{
int sum;
int id;
};
score student[16];
score2 stu[16];

int main()
{
//void fun (stu *a,stu *b)
int n;
cout<<"请输入此次参加评选的学生个数n"<<endl;
cin>>n;
for(i=1;i<=n;i++)
{
cout<<"请按照语文，数学，英语的次序输入成绩"<<endl;
cin>>student[i].chinese>>student[i].math>>student[i].english;

stu[i].sum=student[i].chinese+student[i].math+student[i].english;
stu[i].id=i;

}


for(i=1;i<=n;i++)
for(j=i+1;j<=n;j++)
if(stu[i].sum==stu[j].sum)
{
if(student[i].chinese<student[j].chinese)//则交换两个学生的位置

swap (stu[i],stu[j]);
}
else if(stu[i].sum<stu[j].sum)
{
swap(stu[i],stu[j]);
}


for (i=1;i<=5;i++)
{
	cout<<"前五名学生的学号成绩"<<endl;
cout<<stu[i].id<<" "<<stu[i].sum<<endl;
}
return 0;
}


/*void fun (stu *a,stu *b)
{
stu t;
t=*a;
*a=*b;
*b=t;
return 0;
}
*/