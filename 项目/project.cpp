#include <stdio.h>
#include <WinSock.h>
#include <Windows.h>
#include <mysql.h>
#include<iostream>
using namespace std;


MYSQL mysql;  //mysql连接   全局变量定义
MYSQL_RES* res; //一个结果集结构体   
MYSQL_ROW row; //char** 二维数组，存放一条条记录  

const char DataBase_UserName[] = "root";    //数据库用户名username
const char DataBase_Password[] = "caohui123";   //数据库密码，填自己的密码
const char DataBase_Host[] = "localhost";  //数据库连接地址
//注意有时候使用主机ip会报错，此时可以将ip改为localhost
const char DataBase_Name[] = "csz";  //database name
unsigned int DataBase_Port = 3306;            //server port

bool ConnectDatabase(); //函数申明
void FreeConnect();   //释放资源
class contacts
{
	char name[200];      //用户名
	char phone_number[200];     //电话号码
	char address[200];          //地址
	char Email[200];          //邮箱
	char sort[200];          //关系分类
	char QQ[200];          //QQ
public:
	void show_table();      //信息展示
	int main_menu();    //主菜单

	void input();    //信息输入
	//int xiu_gai();  //修改信息
	//int cha_xun();   //查询信息
	
};
//通讯录类的定义
class Xu_gai :public contacts//修改类
{
public:
	//void xiu_gai_name();
	void xiu_gai_phone_number();
	void xiu_gai_address();
};
//修改类的定义
class Cha_xun :public contacts//查询类
{
public:
	void name_cha_xun();   //按姓名查询
	void address_cha_xun();//按地址查询
};
//查询类的定义
class Shan_chu :public contacts//删除类
{
public:
	void address_shan_chu();    //按地址删除
	void name_shan_chu();    //按姓名删除
};
//删除类的定义

void Shan_chu::name_shan_chu()//按姓名删除
{
	system("pause");
	system("cls");
	MYSQL mysql;
	mysql_init(&mysql);
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "utf8");
	if (!mysql_real_connect(&mysql, "localhost", "root", "caohui123", "csz", 3306, NULL, 0))
	{
		printf("\n数据库连接发生错误!");
	}
	else
	{
		char std[220];
		char  na[200];
		cout << "请输入要删除通讯录信息的用户姓名: " << endl;
		cin >> na;
		sprintf_s(std, "delete from contacts where name='%s';", na);
		if (mysql_query(&mysql, std))
		{
			cout << "数据查询发生错误" << endl;
		}
		else
		{
			cout << "删除成功！" << endl;
		}
	}
}
//按姓名删除

void Shan_chu::address_shan_chu()//按地址删除
{
	system("pause");
 	system("cls");
	MYSQL mysql;
	mysql_init(&mysql);
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "utf8");
	if (!mysql_real_connect(&mysql, "localhost", "root", "caohui123", "csz", 3306, NULL, 0))
	{
		printf("\n数据库连接发生错误!");
	}
	else
	{
		char std[220];
		int  na;
		cout << "请输入要删除通讯录信息的用户地址: " << endl;
		cin >> na;
		sprintf_s(std, "delete from contacts where address=%d;",na);
		mysql_query(&mysql, "set names utf8");
		if (mysql_query(&mysql, std))
		{
			cout << "数据查询发生错误" << endl;
		}
		else
		{
			cout << "删除成功！" << endl;
		}
	}
}
//按地址进行删除


void Cha_xun::address_cha_xun()//按照地址进行查询
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
		cout << "数据库连接错误！" << endl;
	}
	else
	{
		char std[200];
		char n[200];
		cout << "请输入要查的用户地址：" << endl;
		cin >> n;
		sprintf_s(std, "select * from contacts where address='%s';", n);
		if (mysql_query(&mysql, std))
		{
			printf("\n数据查询发生错误\n");
		}
		else
		{
			resultset = mysql_store_result(&mysql);
			if (mysql_num_rows(resultset) != NULL)
			{
				int numFields = mysql_num_fields(resultset);//**获得表中的字段
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
				cout << "显示无果！";
			}
		}
		//mysql_free_result(resultset);
	}
}
//按地址查询


void Cha_xun::name_cha_xun()//按照姓名查询
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
		cout << "数据库连接错误！" << endl;
	}
	else
	{
		char std[200];
		char n[50];
		cout << "请输入要查的姓名：" << endl;
		cin >> n;
		cout << "--------------显示查询------------------" << endl;
		cout << "   姓名  " << "电话 " << "住址 "  << endl;
		cout << "----------------------------------------" << endl;
		sprintf_s(std, "select * from contacts where name='%s';", n);
		if (mysql_query(&mysql, std))
		{
			printf("\n数据查询发生错误\n");
		}
		else
		{
			resultset = mysql_store_result(&mysql);
			if (mysql_num_rows(resultset) != NULL)
			{
				int numFields = mysql_num_fields(resultset);//**获得表中的字段
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
				cout << "显示无果！";
			}
		}
		
	}
}
//按姓名查询
void Xu_gai::xiu_gai_address()//修改住址
{
	system("cls");
	//system("pause");
	cout << "显示学生数据" << endl;
	//Xu_gai zhao;
	//zhao.show_table();
	MYSQL mysql;
	mysql_init(&mysql);
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "latin1");
	if (!mysql_real_connect(&mysql, "localhost", "root", "caohui123", "csz", 3306, NULL, 0))
	{
		cout << "数据库连接错误！" << endl;
	}
	else
	{
		char std[200];
		char m[50];
		char n[50];
		cout << "请输入要修改的系统用户的姓名：" << endl;
		cin >> n;
		cout << "请输入要新的住址：" << endl;
		cin >> m;
		sprintf_s(std, "update contacts set address='%s' where name='%s';", m, n);
		if (mysql_query(&mysql, std))
		{
			printf("\n数据库更改发生错误\n");
		}
		else
		{
			printf("\n数据库更改数据成功\n");
		}
	}
}
//修改住址

void Xu_gai::xiu_gai_phone_number()//修改电话
{
	system("cls");
	system("pause");
	//cout << "显示学生数据" << endl;
	MYSQL mysql;
	mysql_init(&mysql);
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "latin1");
	if (!mysql_real_connect(&mysql, "localhost", "root", "caohui123", "csz", 3306, NULL, 0))
	{
		cout << "数据库连接错误！" << endl;
	}
	else
	{
		char std[150];
		char m[150];
		char n[150];
		cout << "请输入要修改的系统用户的姓名：" << endl;
		cin >> n;
		cout << "请输入要修改的新的电话：" << endl;
		cin >> m;
		sprintf_s(std, "update contacts set phone_number='%s' where name='%s';", m, n);
		if (mysql_query(&mysql, std))
		{
			printf("\n数据库更改发生错误\n");
		}
		else
		{
			printf("\n数据库更改数据成功\n");
		}
	}
}
//修改电话号码


//void Xu_gai::xiu_gai_name()//修改QQ号
//{
//	system("cls");
//	system("pause");
//	cout << "显示学生数据" << endl;
//	Xu_gai zhao;
//	zhao.show_table();
//	MYSQL mysql;
//	mysql_init(&mysql);
//	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "latin1");
//	if (!mysql_real_connect(&mysql, "localhost", "root", "caohui123", "csz", 3306, NULL, 0))
//	{
//		cout << "数据库连接错误！" << endl;
//	}
//	else
//	{
//		char std[200];
//		char m[200];
//		int n;
//		cout << "对目标学号信息进行修改：" << endl;
//		cin >> n;
//		cout << "请输入要新的QQ号：" << endl;
//		cin >> m;
//		sprintf(std, "update xueji set QQ='%s' where id=%d;", m, n);
//		if (mysql_query(&mysql, std))
//		{
//			printf("\n数据库更改发生错误\n");
//		}
//		else
//		{
//			printf("\n数据库更改数据成功\n");
//		}
//	}
//}
////修改姓名
//


void contacts::show_table()//信息表数据的显示
{
	system("cls");
	MYSQL mysql;
	MYSQL_RES *resultset;
	MYSQL_ROW row;
	mysql_init(&mysql);
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "latin1");
	if (!mysql_real_connect(&mysql, "localhost", "root", "caohui123", "csz", 3306, NULL, 0))
	{
		cout << "\n数据库连接发生错误！";
	}
	else
	{
		if (mysql_query(&mysql, "select * from contacts"))
		{
			cout << "表格数据显示失败！";
		}
		else
		{
			cout << "--------------------------------------显示信息------------------------------------" << endl;
			cout << "  姓名    " << "  电话  " << "   住址  " << "   分类  " << "   Email  "<<"   QQ  " << endl;
			cout << "----------------------------------------------------------------------------------" << endl;
			resultset = mysql_store_result(&mysql);
			if (mysql_num_rows(resultset) != NULL)
			{
				int k = 0;
				int numFields = mysql_num_fields(resultset);//**获得表中的字段
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
				cout << "显示无果！";
			}
		}
	}


}
//显示表信息
int contacts::main_menu()//主菜单
{
	system("pause");
	system("cls");
	int s;
	cout << endl << endl << endl << endl << endl << endl << endl
		<< "                        1:   录入用户信息           " << endl
		<< "                        2:   按地址删除用户信息           " << endl
		<< "                        3:   按姓名删除用户信息           " << endl
		<< "                        4:   按地址查询用户信息           " << endl
		<< "                        5:   按姓名查询用户信息           " << endl
		<< "                        6:   修改用户电话号码             " << endl
		<< "                        7:   修改用户住址                 " << endl
		<< "                        8:   用户信息表显示              " << endl
		<< "                        0:   退出系统                   " << endl
		<< "                        请选择:";
	cin >> s;
	return s;
}
//主菜单


void contacts::input()//录入学生信息
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
		cout << "数据库连接错误！" << endl;
	}
	else
	{
		cout << "请录入用户信息数据" << endl << endl << "录入格式说明：输入一项按Enter键进行下一项的输入" << endl << endl;
		mysql_query(&mysql, "SET NAMES LATIN1");
		cout << "姓名  " << "电话   " << "住址  " <<"  Email  "<<"  关系  "<<"  QQ  "<< endl;
		cin >>  lu_ru.name >> lu_ru.phone_number>> lu_ru.address>>lu_ru.Email>> lu_ru.sort>> lu_ru.QQ;
		sprintf_s(std, "insert into contacts VALUES('%s','%s','%s','%s','%s','%s');", lu_ru.name , lu_ru.phone_number ,lu_ru.address, lu_ru.Email , lu_ru.sort , lu_ru.QQ);
		mysql_query(&mysql, std);
		cout << "添加成功" << endl;
	}
}    
//录入通讯录信息



//int contacts::xiu_gai()//定义修改函数
//{
//	cout << "进入修改系统..." << endl;
//	int h;
//	Xu_gai geng_zheng;
//	system("pause");
//	system("cls");
//	MYSQL mysql;
//	mysql_init(&mysql);
//	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "utf8");
//	if (!mysql_real_connect(&mysql, "localhost", "root", "caohui123", "csz", 3306, NULL, 0))
//	{
//		cout << "数据库连接错误！" << endl;
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
//				cout << "请选择正确的菜单项进行操作。多谢合作!" << endl;
//			}
//		}
//	}
//	return 0;
//}
//修改函数定义
//int contacts::cha_xun()//查询
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
//		cout << "数据库连接错误！" << endl;
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
//				cout << "请选择正确的菜单项进行操作。多谢合作!" << endl;
//			}
//		}
//	}
//	return 0;
//}
////信息查询




int main()
{
	int n;
	int m=0;
	ConnectDatabase();	//连接数据库
	//查询数据
	mysql_query(&mysql, "use csz;");
	//获取结果集
	Shan_chu del;  //删除类的结构体定义
	contacts user;  //系统用户结构体定义
	Cha_xun found;   //查询类定义
	Xu_gai rectify;   //修改类结构体定义
	while (1)
	{
		
		n = user.main_menu();
		switch (n)
		{
		case 1:
		{
			cout << "请输入要录入用户信息条数" << endl;
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
			cout << "                      ··········" << endl;
			cout << "                   ***···谢谢使用···***" << endl;
			cout << "                      ··········" << endl << endl << endl << endl << endl << endl;
			exit(1);
			break;

		default:
			cout << "请选择正确的菜单项进行操作。谢谢合作!" << endl;
		}
	}
	//	getchar();
		return 0;
}

	bool ConnectDatabase()
	{
		//初始化mysql
		mysql_init(&mysql);   //连接mysql，数据库
		if (!(mysql_real_connect(&mysql, DataBase_Host, DataBase_UserName, DataBase_Password, DataBase_Name, DataBase_Port, NULL, 0))) //中间分别是主机，用户名，密码，数据库名，端口号（可以写默认0或者3306等），可以先写成参数再传进去
		{
			printf("Error connecting to database:%s\n", mysql_error(&mysql));
			return false;
		}
		else
		{
			MessageBoxA(NULL, "连接MYSQL数据成功！", "消息", MB_OK);
			printf("Connected...\n");
			return true;
		}
	}

//释放资源
void FreeConnect()
{
	//释放资源
	//mysql_free_result(res);
	mysql_close(&mysql);
}
