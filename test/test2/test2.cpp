////#include <stdafx.h>
//#include <stdio.h>
//#include <iostream>
//#include <WinSock.h>
//#include <Windows.h>
//#include <mysql.h>
//
//MYSQL mysql;  //mysql����
//
//const char DataBase_UserName[] = "root";    //���ݿ��û���username
//const char DataBase_Password[] = "zyh3986239Az";   //���ݿ�����
//const char DataBase_Host[] = "localhost";  //���ݿ����ӵ�ַ
////ע����ʱ��ʹ������ip�ᱨ����ʱ���Խ�ip��Ϊlocalhost
//const char DataBase_Name[] = "test1";  //database name
//unsigned int DataBase_Port = 3306;            //server port
//
//bool ConnectDatabase(); //��������
//void FreeConnect();   //�ͷ���Դ
//
//int main()
//{
//	ConnectDatabase();
//	FreeConnect(); //�ͷ���Դ
//	system("pause");
//
//	return 0;
//}
//
//bool ConnectDatabase()
//{
//	//��ʼ��mysql
//	mysql_init(&mysql);   //����mysql�����ݿ�
//	if (!(mysql_real_connect(&mysql, DataBase_Host, DataBase_UserName, DataBase_Password, DataBase_Name, DataBase_Port, NULL, 0))) //�м�ֱ����������û��������룬���ݿ������˿ںţ�����дĬ��0����3306�ȣ���������д�ɲ����ٴ���ȥ
//	{
//		printf("Error connecting to database:%s\n", mysql_error(&mysql));
//		return false;
//	}
//	else
//	{
//		MessageBoxA(NULL, "����MYSQL���ݳɹ���", "��Ϣ", MB_OK);
//		printf("Connected...\n");
//		return true;
//	}
//}
////�ͷ���Դ
//void FreeConnect()
//{
//	//�ͷ���Դ
//	//mysql_free_result(res);
//	mysql_close(&mysql);
//}
//
//

#include <map>
#include <set>
#include <string>
#include<vector>
#include <iostream>
using namespace std;

int main(void){
	int k;
	cout << k << endl;
	return 0;
}