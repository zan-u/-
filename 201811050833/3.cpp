#include <iostream>
#include <string>
#define A 1000
using namespace std;
 
int i,j;
 
struct student
{
    int china;
    int math;
    int english;
    int sum;
    int id;
}stu[A];//定义学生数组结构体
 
int main()
{
    int n;
    cin>>n;//输入学生人数
    for(i=0;i<n;i++)
    {
        cin>>stu[i].china>>stu[i].math>>stu[i].english;
        stu[i].sum=stu[i].china+stu[i].math+stu[i].english;
        stu[i].id=i+1;//录入三科成绩
    }
 
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(stu[i].sum<stu[j].sum)//比较总成绩
            {
                swap(stu[i].sum,stu[j].sum);
                swap(stu[i].china,stu[j].china);
                swap(stu[i].id,stu[j].id);//进行比较
            }
            if(stu[i].sum==stu[j].sum)//若总成绩相等，比较语文成绩
            {
                if(stu[i].china<stu[j].china)
                {
                    swap(stu[i].sum,stu[j].sum);
                    swap(stu[i].id,stu[j].id);
                    swap(stu[i].china,stu[j].china);
                }
            }
            if(stu[i].sum==stu[j].sum&&stu[i].china==stu[j].china)//若总成绩和语文成绩都相等，则按学号排列
            {
                if(stu[i].id>stu[j].id)
                {
                    swap(stu[i].sum,stu[j].sum);
                    swap(stu[i].id,stu[j].id);
                    swap(stu[i].china,stu[j].china);
                }
            }
        }
    }
 
    for(i=0;i<5;i++)
    {
        cout<<stu[i].id<<" "<<stu[i].sum<<endl;
    }
 
 
    return 0;
}