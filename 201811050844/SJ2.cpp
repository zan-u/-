
#include<iostream>
#include<fstream>
using namespace std;
#define m 12 
void main()
{
	int n,z=0,f;
	cout<<"mΪ12";
	cout<<"����n"<<endl;
	cin>>n;
	int h[m],i,j;
	for(i=1;i<=m;i++)
	{
		h[i-1]=i;	
	}
	for(j=1;j<m;j++)
	{
		z+=n-1;
		if(z>=m)z-=m;
		if(h[z]==0)z++;
		h[z]=0;
	}
	for(f=0;f<m;f++)
	{
		if(h[f]!=0){cout<<h[f]<<"�ź����Ǵ���"<<endl;}
	}
}

/*
#include <iostream>
using namespace std;
struct Monkey
{
    int num;  //���ӵı��
    struct Monkey *next; //��һֻ����
};

int main()
{
    int m,n,i,j,king;
    Monkey *head, *p1,*p2;
    cout<<"��������Ӹ���m�ͱ���n:";
    cin>>m>>n;
    if(n==1)
    {
        king=m;
    }
    else
    {
        //��������Χ�ɵ�ԲȦ
        p1=p2=new Monkey;
        head = p1;
        p1->num=1;
        for(i=1; i<m; i++)  //����m-1ֻ����
        {
            p1=new Monkey;  //p1�������ӵ�
            p1->num=i+1;
            p2->next=p1;
            p2=p1;          //p2������һֻ
        }
        p2->next=head;      //���һֻ��ָ���һֻ������һ��ԲȦ

        //����Ҫ��ʼ����
        p1=head;
        for(i=1; i<m; i++)  //ѭ��m-1�Σ���̭m-1ֻ����
        {
            //��p1��ʼ����n-1ֻ���ҵ���nֻ��
            for(j=1; j<n-1; j++)  //ʵ�����ҵ���n-1ֻ����һֻ���Ǳ���̭��
                p1=p1->next;    //Χ��Ȧ�ģ������ٿ�ʼ�ӵ�һֻ���������δ����̭�Ļ�

            //�ҵ��ˣ�
            p2=p1->next;  //p2����ɾ��
            //cout<<"��"<<i<<"����̭"<<p2->num<<endl;   //���������۲��м���
            p1->next=p2->next;  //p2�����������ܿ��ˡ�
            p1=p2->next;  //��һ�������������
            delete p2;  //�����������еĽ�������
        }
        king=p1->num;
        delete p1;
    }
    cout<<"���Ӵ���:"; 
    cout<<king;
    return 0;
}*/
