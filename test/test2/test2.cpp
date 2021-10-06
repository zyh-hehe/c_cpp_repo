////#include <stdafx.h>
//#include <stdio.h>
//#include <iostream>
//#include <WinSock.h>
//#include <Windows.h>
//#include <mysql.h>
//
//MYSQL mysql;  //mysql连接
//
//const char DataBase_UserName[] = "root";    //数据库用户名username
//const char DataBase_Password[] = "zyh3986239Az";   //数据库密码
//const char DataBase_Host[] = "localhost";  //数据库连接地址
////注意有时候使用主机ip会报错，此时可以将ip改为localhost
//const char DataBase_Name[] = "test1";  //database name
//unsigned int DataBase_Port = 3306;            //server port
//
//bool ConnectDatabase(); //函数申明
//void FreeConnect();   //释放资源
//
//int main()
//{
//	ConnectDatabase();
//	FreeConnect(); //释放资源
//	system("pause");
//
//	return 0;
//}
//
//bool ConnectDatabase()
//{
//	//初始化mysql
//	mysql_init(&mysql);   //连接mysql，数据库
//	if (!(mysql_real_connect(&mysql, DataBase_Host, DataBase_UserName, DataBase_Password, DataBase_Name, DataBase_Port, NULL, 0))) //中间分别是主机，用户名，密码，数据库名，端口号（可以写默认0或者3306等），可以先写成参数再传进去
//	{
//		printf("Error connecting to database:%s\n", mysql_error(&mysql));
//		return false;
//	}
//	else
//	{
//		MessageBoxA(NULL, "连接MYSQL数据成功！", "消息", MB_OK);
//		printf("Connected...\n");
//		return true;
//	}
//}
////释放资源
//void FreeConnect()
//{
//	//释放资源
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