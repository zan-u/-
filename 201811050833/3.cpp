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
}stu[A];//����ѧ������ṹ��
 
int main()
{
    int n;
    cin>>n;//����ѧ������
    for(i=0;i<n;i++)
    {
        cin>>stu[i].china>>stu[i].math>>stu[i].english;
        stu[i].sum=stu[i].china+stu[i].math+stu[i].english;
        stu[i].id=i+1;//¼�����Ƴɼ�
    }
 
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(stu[i].sum<stu[j].sum)//�Ƚ��ܳɼ�
            {
                swap(stu[i].sum,stu[j].sum);
                swap(stu[i].china,stu[j].china);
                swap(stu[i].id,stu[j].id);//���бȽ�
            }
            if(stu[i].sum==stu[j].sum)//���ܳɼ���ȣ��Ƚ����ĳɼ�
            {
                if(stu[i].china<stu[j].china)
                {
                    swap(stu[i].sum,stu[j].sum);
                    swap(stu[i].id,stu[j].id);
                    swap(stu[i].china,stu[j].china);
                }
            }
            if(stu[i].sum==stu[j].sum&&stu[i].china==stu[j].china)//���ܳɼ������ĳɼ�����ȣ���ѧ������
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