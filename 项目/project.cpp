#include <stdio.h>
#include <WinSock.h>
#include <Windows.h>
#include <mysql.h>
#include<iostream>
using namespace std;


MYSQL mysql;  //mysql����   ȫ�ֱ�������
MYSQL_RES* res; //һ��������ṹ��   
MYSQL_ROW row; //char** ��ά���飬���һ������¼  

const char DataBase_UserName[] = "root";    //���ݿ��û���username
const char DataBase_Password[] = "caohui123";   //���ݿ����룬���Լ�������
const char DataBase_Host[] = "localhost";  //���ݿ����ӵ�ַ
//ע����ʱ��ʹ������ip�ᱨ����ʱ���Խ�ip��Ϊlocalhost
const char DataBase_Name[] = "csz";  //database name
unsigned int DataBase_Port = 3306;            //server port

bool ConnectDatabase(); //��������
void FreeConnect();   //�ͷ���Դ
class contacts
{
	char name[200];      //�û���
	char phone_number[200];     //�绰����
	char address[200];          //��ַ
	char Email[200];          //����
	char sort[200];          //��ϵ����
	char QQ[200];          //QQ
public:
	void show_table();      //��Ϣչʾ
	int main_menu();    //���˵�

	void input();    //��Ϣ����
	//int xiu_gai();  //�޸���Ϣ
	//int cha_xun();   //��ѯ��Ϣ
	
};
//ͨѶ¼��Ķ���
class Xu_gai :public contacts//�޸���
{
public:
	//void xiu_gai_name();
	void xiu_gai_phone_number();
	void xiu_gai_address();
};
//�޸���Ķ���
class Cha_xun :public contacts//��ѯ��
{
public:
	void name_cha_xun();   //��������ѯ
	void address_cha_xun();//����ַ��ѯ
};
//��ѯ��Ķ���
class Shan_chu :public contacts//ɾ����
{
public:
	void address_shan_chu();    //����ַɾ��
	void name_shan_chu();    //������ɾ��
};
//ɾ����Ķ���

void Shan_chu::name_shan_chu()//������ɾ��
{
	system("pause");
	system("cls");
	MYSQL mysql;
	mysql_init(&mysql);
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "utf8");
	if (!mysql_real_connect(&mysql, "localhost", "root", "caohui123", "csz", 3306, NULL, 0))
	{
		printf("\n���ݿ����ӷ�������!");
	}
	else
	{
		char std[220];
		char  na[200];
		cout << "������Ҫɾ��ͨѶ¼��Ϣ���û�����: " << endl;
		cin >> na;
		sprintf_s(std, "delete from contacts where name='%s';", na);
		if (mysql_query(&mysql, std))
		{
			cout << "���ݲ�ѯ��������" << endl;
		}
		else
		{
			cout << "ɾ���ɹ���" << endl;
		}
	}
}
//������ɾ��

void Shan_chu::address_shan_chu()//����ַɾ��
{
	system("pause");
 	system("cls");
	MYSQL mysql;
	mysql_init(&mysql);
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "utf8");
	if (!mysql_real_connect(&mysql, "localhost", "root", "caohui123", "csz", 3306, NULL, 0))
	{
		printf("\n���ݿ����ӷ�������!");
	}
	else
	{
		char std[220];
		int  na;
		cout << "������Ҫɾ��ͨѶ¼��Ϣ���û���ַ: " << endl;
		cin >> na;
		sprintf_s(std, "delete from contacts where address=%d;",na);
		mysql_query(&mysql, "set names utf8");
		if (mysql_query(&mysql, std))
		{
			cout << "���ݲ�ѯ��������" << endl;
		}
		else
		{
			cout << "ɾ���ɹ���" << endl;
		}
	}
}
//����ַ����ɾ��


void Cha_xun::address_cha_xun()//���յ�ַ���в�ѯ
{
	system("cls");
	system("pause");
	MYSQL mysql;
	mysql_init(&mysql);
	MYSQL_RES *resultset;
	MYSQL_ROW row;
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "latin1");
	if (!mysql_real_connect(&mysql, "localhost", "root", "caohui123", "csz", 3306, NULL, 0))
	{
		cout << "���ݿ����Ӵ���" << endl;
	}
	else
	{
		char std[200];
		char n[200];
		cout << "������Ҫ����û���ַ��" << endl;
		cin >> n;
		sprintf_s(std, "select * from contacts where address='%s';", n);
		if (mysql_query(&mysql, std))
		{
			printf("\n���ݲ�ѯ��������\n");
		}
		else
		{
			resultset = mysql_store_result(&mysql);
			if (mysql_num_rows(resultset) != NULL)
			{
				int numFields = mysql_num_fields(resultset);//**��ñ��е��ֶ�
				while (row = mysql_fetch_row(resultset))
				{
					int i = 0;
					for (i = 0; i < numFields; i++)
					{
						mysql_query(&mysql, "SET NAMES LATIN1");
						cout << " " << row[i] << " ";
					}
					cout << endl;
				}
			}
			else
			{
				cout << "��ʾ�޹���";
			}
		}
		//mysql_free_result(resultset);
	}
}
//����ַ��ѯ


void Cha_xun::name_cha_xun()//����������ѯ
{
	system("cls");
	system("pause");
	MYSQL mysql;
	mysql_init(&mysql);
	MYSQL_RES *resultset;
	MYSQL_ROW row;
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "latin1");
	if (!mysql_real_connect(&mysql, "localhost", "root", "caohui123", "csz", 3306, NULL, 0))
	{
		cout << "���ݿ����Ӵ���" << endl;
	}
	else
	{
		char std[200];
		char n[50];
		cout << "������Ҫ���������" << endl;
		cin >> n;
		cout << "--------------��ʾ��ѯ------------------" << endl;
		cout << "   ����  " << "�绰 " << "סַ "  << endl;
		cout << "----------------------------------------" << endl;
		sprintf_s(std, "select * from contacts where name='%s';", n);
		if (mysql_query(&mysql, std))
		{
			printf("\n���ݲ�ѯ��������\n");
		}
		else
		{
			resultset = mysql_store_result(&mysql);
			if (mysql_num_rows(resultset) != NULL)
			{
				int numFields = mysql_num_fields(resultset);//**��ñ��е��ֶ�
				while (row = mysql_fetch_row(resultset))
				{
					int i = 0;
					for (i = 0; i < numFields; i++)
					{
						mysql_query(&mysql, "SET NAMES LATIN1");
						cout << " " << row[i] << " ";
					}
					cout << endl;
				}
				cout << "------------------------------------------------------------------------" << endl;
			}
			else
			{
				cout << "��ʾ�޹���";
			}
		}
		
	}
}
//��������ѯ
void Xu_gai::xiu_gai_address()//�޸�סַ
{
	system("cls");
	//system("pause");
	cout << "��ʾѧ������" << endl;
	//Xu_gai zhao;
	//zhao.show_table();
	MYSQL mysql;
	mysql_init(&mysql);
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "latin1");
	if (!mysql_real_connect(&mysql, "localhost", "root", "caohui123", "csz", 3306, NULL, 0))
	{
		cout << "���ݿ����Ӵ���" << endl;
	}
	else
	{
		char std[200];
		char m[50];
		char n[50];
		cout << "������Ҫ�޸ĵ�ϵͳ�û���������" << endl;
		cin >> n;
		cout << "������Ҫ�µ�סַ��" << endl;
		cin >> m;
		sprintf_s(std, "update contacts set address='%s' where name='%s';", m, n);
		if (mysql_query(&mysql, std))
		{
			printf("\n���ݿ���ķ�������\n");
		}
		else
		{
			printf("\n���ݿ�������ݳɹ�\n");
		}
	}
}
//�޸�סַ

void Xu_gai::xiu_gai_phone_number()//�޸ĵ绰
{
	system("cls");
	system("pause");
	//cout << "��ʾѧ������" << endl;
	MYSQL mysql;
	mysql_init(&mysql);
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "latin1");
	if (!mysql_real_connect(&mysql, "localhost", "root", "caohui123", "csz", 3306, NULL, 0))
	{
		cout << "���ݿ����Ӵ���" << endl;
	}
	else
	{
		char std[150];
		char m[150];
		char n[150];
		cout << "������Ҫ�޸ĵ�ϵͳ�û���������" << endl;
		cin >> n;
		cout << "������Ҫ�޸ĵ��µĵ绰��" << endl;
		cin >> m;
		sprintf_s(std, "update contacts set phone_number='%s' where name='%s';", m, n);
		if (mysql_query(&mysql, std))
		{
			printf("\n���ݿ���ķ�������\n");
		}
		else
		{
			printf("\n���ݿ�������ݳɹ�\n");
		}
	}
}
//�޸ĵ绰����


//void Xu_gai::xiu_gai_name()//�޸�QQ��
//{
//	system("cls");
//	system("pause");
//	cout << "��ʾѧ������" << endl;
//	Xu_gai zhao;
//	zhao.show_table();
//	MYSQL mysql;
//	mysql_init(&mysql);
//	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "latin1");
//	if (!mysql_real_connect(&mysql, "localhost", "root", "caohui123", "csz", 3306, NULL, 0))
//	{
//		cout << "���ݿ����Ӵ���" << endl;
//	}
//	else
//	{
//		char std[200];
//		char m[200];
//		int n;
//		cout << "��Ŀ��ѧ����Ϣ�����޸ģ�" << endl;
//		cin >> n;
//		cout << "������Ҫ�µ�QQ�ţ�" << endl;
//		cin >> m;
//		sprintf(std, "update xueji set QQ='%s' where id=%d;", m, n);
//		if (mysql_query(&mysql, std))
//		{
//			printf("\n���ݿ���ķ�������\n");
//		}
//		else
//		{
//			printf("\n���ݿ�������ݳɹ�\n");
//		}
//	}
//}
////�޸�����
//


void contacts::show_table()//��Ϣ�����ݵ���ʾ
{
	system("cls");
	MYSQL mysql;
	MYSQL_RES *resultset;
	MYSQL_ROW row;
	mysql_init(&mysql);
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "latin1");
	if (!mysql_real_connect(&mysql, "localhost", "root", "caohui123", "csz", 3306, NULL, 0))
	{
		cout << "\n���ݿ����ӷ�������";
	}
	else
	{
		if (mysql_query(&mysql, "select * from contacts"))
		{
			cout << "���������ʾʧ�ܣ�";
		}
		else
		{
			cout << "--------------------------------------��ʾ��Ϣ------------------------------------" << endl;
			cout << "  ����    " << "  �绰  " << "   סַ  " << "   ����  " << "   Email  "<<"   QQ  " << endl;
			cout << "----------------------------------------------------------------------------------" << endl;
			resultset = mysql_store_result(&mysql);
			if (mysql_num_rows(resultset) != NULL)
			{
				int k = 0;
				int numFields = mysql_num_fields(resultset);//**��ñ��е��ֶ�
				while (row = mysql_fetch_row(resultset))
				{
					k++;
					if (k % 10 != 0)
					{
						int i = 0;
						for (i = 0; i < numFields; i++)
						{
							mysql_query(&mysql, "SET NAMES LATIN1");
							cout << " " << row[i] << " ";
						}
						cout << endl;
					}
					else
					{
						int i = 0;
						for (i = 0; i < numFields; i++)
						{
							mysql_query(&mysql, "SET NAMES LATIN1");
							cout << " " << row[i] << " ";
						}
						cout << endl<<endl<<endl;
						cout << "---------------------------------------------------------------------------" << endl;					
					}
					/*cout << endl;
					cout << "---------------------------------------------------------------------------" << endl;*/
				}
			}
			else
			{
				cout << "��ʾ�޹���";
			}
		}
	}


}
//��ʾ����Ϣ
int contacts::main_menu()//���˵�
{
	system("pause");
	system("cls");
	int s;
	cout << endl << endl << endl << endl << endl << endl << endl
		<< "                        1:   ¼���û���Ϣ           " << endl
		<< "                        2:   ����ַɾ���û���Ϣ           " << endl
		<< "                        3:   ������ɾ���û���Ϣ           " << endl
		<< "                        4:   ����ַ��ѯ�û���Ϣ           " << endl
		<< "                        5:   ��������ѯ�û���Ϣ           " << endl
		<< "                        6:   �޸��û��绰����             " << endl
		<< "                        7:   �޸��û�סַ                 " << endl
		<< "                        8:   �û���Ϣ����ʾ              " << endl
		<< "                        0:   �˳�ϵͳ                   " << endl
		<< "                        ��ѡ��:";
	cin >> s;
	return s;
}
//���˵�


void contacts::input()//¼��ѧ����Ϣ
{
	//system("pause");
	system("cls");
	contacts lu_ru;
	char std[200];
	MYSQL mysql;
	mysql_init(&mysql);
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "utf8");
	//mysql_query(&mysql, "set names 'utf8'");
	if (!mysql_real_connect(&mysql, "localhost", "root", "caohui123", "csz", 3306, NULL, 0))
	{
		cout << "���ݿ����Ӵ���" << endl;
	}
	else
	{
		cout << "��¼���û���Ϣ����" << endl << endl << "¼���ʽ˵��������һ�Enter��������һ�������" << endl << endl;
		mysql_query(&mysql, "SET NAMES LATIN1");
		cout << "����  " << "�绰   " << "סַ  " <<"  Email  "<<"  ��ϵ  "<<"  QQ  "<< endl;
		cin >>  lu_ru.name >> lu_ru.phone_number>> lu_ru.address>>lu_ru.Email>> lu_ru.sort>> lu_ru.QQ;
		sprintf_s(std, "insert into contacts VALUES('%s','%s','%s','%s','%s','%s');", lu_ru.name , lu_ru.phone_number ,lu_ru.address, lu_ru.Email , lu_ru.sort , lu_ru.QQ);
		mysql_query(&mysql, std);
		cout << "��ӳɹ�" << endl;
	}
}    
//¼��ͨѶ¼��Ϣ



//int contacts::xiu_gai()//�����޸ĺ���
//{
//	cout << "�����޸�ϵͳ..." << endl;
//	int h;
//	Xu_gai geng_zheng;
//	system("pause");
//	system("cls");
//	MYSQL mysql;
//	mysql_init(&mysql);
//	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "utf8");
//	if (!mysql_real_connect(&mysql, "localhost", "root", "caohui123", "csz", 3306, NULL, 0))
//	{
//		cout << "���ݿ����Ӵ���" << endl;
//	}
//	else
//	{
//		while (1)
//		{
//			h = geng_zheng.xiu_gai_menu();
//			switch (h)
//			{
//			case 1:
//				geng_zheng.xiu_gai_xue_hao();
//				break;
//			case 2:
//				geng_zheng.xiu_gai_xing_ming();
//				break;
//			case 3:
//				geng_zheng.xiu_gai_xing_bie();
//				break;
//			case 4:
//				geng_zheng.xiu_gai_min_zu();
//				break;
//			case 5:
//				geng_zheng.xiu_gai_ji_guan();
//				break;
//			case 6:
//				geng_zheng.xiu_gai_shen_fen_zheng_hao();
//				break;
//			case 7:
//				geng_zheng.xiu_gai_QQ_hao();
//				break;
//			case 8:
//				geng_zheng.xiu_gai_dian_hua();
//				break;
//			case 9:
//				geng_zheng.xiu_gai_cheng_ji();
//				break;
//			case 0:
//				return 0;
//				break;
//			default:
//				cout << "��ѡ����ȷ�Ĳ˵�����в�������л����!" << endl;
//			}
//		}
//	}
//	return 0;
//}
//�޸ĺ�������
//int contacts::cha_xun()//��ѯ
//{
//	system("pause");
//	system("cls");
//	Cha_xun cha;
//	MYSQL mysql;
//	int h;
//	mysql_init(&mysql);
//	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "latin1");
//	if (!mysql_real_connect(&mysql, "localhost", "root", "123456", "student", 3306, NULL, 0))
//	{
//		cout << "���ݿ����Ӵ���" << endl;
//	}
//	else
//	{
//		while (1)
//		{
//			h = cha.cha_xun_menu();
//			switch (h)
//			{
//			case 1:
//				cha.xue_hao_cha_xun();
//				break;
//			case 2:
//				cha.xing_ming_cha_xun();
//				break;
//			case 0:
//				return 0;
//				break;
//			default:
//				cout << "��ѡ����ȷ�Ĳ˵�����в�������л����!" << endl;
//			}
//		}
//	}
//	return 0;
//}
////��Ϣ��ѯ




int main()
{
	int n;
	int m=0;
	ConnectDatabase();	//�������ݿ�
	//��ѯ����
	mysql_query(&mysql, "use csz;");
	//��ȡ�����
	Shan_chu del;  //ɾ����Ľṹ�嶨��
	contacts user;  //ϵͳ�û��ṹ�嶨��
	Cha_xun found;   //��ѯ�ඨ��
	Xu_gai rectify;   //�޸���ṹ�嶨��
	while (1)
	{
		
		n = user.main_menu();
		switch (n)
		{
		case 1:
		{
			cout << "������Ҫ¼���û���Ϣ����" << endl;
			cin >> m;
		for (m;m>0;m-- )
			user.input();   //ok
			break;

		}
		case 2:
			del.address_shan_chu();  //ok
			break;
		case 3:
			del.name_shan_chu();
			break;
		case 4:
			found.address_cha_xun();  
			break;
		case 5:
			found.name_cha_xun();
			break;
		case 6:
			rectify.xiu_gai_phone_number();
			break;
		case 7:
			rectify.xiu_gai_address();
			break;
		case 8:
			user.show_table();
			break;
		case 0:
			system("cls");
			cout << endl << endl << endl << endl << endl << endl << endl << endl;
			cout << "                      ��������������������" << endl;
			cout << "                   ***������ллʹ�á�����***" << endl;
			cout << "                      ��������������������" << endl << endl << endl << endl << endl << endl;
			exit(1);
			break;

		default:
			cout << "��ѡ����ȷ�Ĳ˵�����в�����лл����!" << endl;
		}
	}
	//	getchar();
		return 0;
}

	bool ConnectDatabase()
	{
		//��ʼ��mysql
		mysql_init(&mysql);   //����mysql�����ݿ�
		if (!(mysql_real_connect(&mysql, DataBase_Host, DataBase_UserName, DataBase_Password, DataBase_Name, DataBase_Port, NULL, 0))) //�м�ֱ����������û��������룬���ݿ������˿ںţ�����дĬ��0����3306�ȣ���������д�ɲ����ٴ���ȥ
		{
			printf("Error connecting to database:%s\n", mysql_error(&mysql));
			return false;
		}
		else
		{
			MessageBoxA(NULL, "����MYSQL���ݳɹ���", "��Ϣ", MB_OK);
			printf("Connected...\n");
			return true;
		}
	}

//�ͷ���Դ
void FreeConnect()
{
	//�ͷ���Դ
	//mysql_free_result(res);
	mysql_close(&mysql);
}
