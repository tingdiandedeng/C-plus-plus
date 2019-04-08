#include <winsock.h>
#include <iostream>  
#include <string>  
#include <mysql.h>  
using namespace std;

#pragma comment(lib, "ws2_32.lib")  
#pragma comment(lib, "libmysql.lib")  

//����ִ�У����뵥��ִ�о�ע�͵�  
#define STEPBYSTEP  

int main() {
	cout << "****************************************" << endl;

#ifdef STEPBYSTEP  
	system("pause");
#endif  

	//�ر���һ�����ݽṹ  
	MYSQL mydata;

	//��ʼ�����ݿ�  
	if (0 == mysql_library_init(0, NULL, NULL)) {
		cout << "mysql_library_init() succeed" << endl;
	}
	else {
		cout << "mysql_library_init() failed" << endl;
		return -1;
	}

#ifdef STEPBYSTEP  
	system("pause");
#endif  

	//��ʼ�����ݽṹ  
	if (NULL != mysql_init(&mydata)) {
		cout << "mysql_init() succeed" << endl;
	}
	else {
		cout << "mysql_init() failed" << endl;
		return -1;
	}

#ifdef STEPBYSTEP  
	system("pause");
#endif  

	//���������ݿ�֮ǰ�����ö��������ѡ��  
	//�������õ�ѡ��ܶ࣬���������ַ����������޷���������  
	if (0 == mysql_options(&mydata, MYSQL_SET_CHARSET_NAME, "gbk")) {
		cout << "mysql_options() succeed" << endl;
	}
	else {
		cout << "mysql_options() failed" << endl;
		return -1;
	}

#ifdef STEPBYSTEP  
	system("pause");
#endif  

	//�������ݿ�  
	if (NULL
		!= mysql_real_connect(&mydata, "localhost", "root", "123456", "test", 3306, NULL, 0))
		//����ĵ�ַ���û��������룬�˿ڿ��Ը����Լ����ص��������  
	{
		cout << "mysql_real_connect() succeed" << endl;
	}
	else {
		cout << "mysql_real_connect() failed" << endl;
		return -1;
	}

#ifdef STEPBYSTEP  
	system("pause");
#endif  

	//sql�ַ���  
	string sqlstr;

	//����һ����  
	sqlstr = "CREATE TABLE IF NOT EXISTS user_info";
	sqlstr += "(";
	sqlstr +=
		"user_id INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY COMMENT 'Unique User ID',";
	sqlstr +=
		"user_name VARCHAR(100) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NULL COMMENT 'Name Of User',";
	sqlstr +=
		"user_second_sum INT UNSIGNED NOT NULL DEFAULT 0 COMMENT 'The Summation Of Using Time'";
	sqlstr += ");";
	if (0 == mysql_query(&mydata, sqlstr.c_str())) {
		cout << "mysql_query() create table succeed" << endl;
	}
	else {
		cout << "mysql_query() create table failed" << endl;
		mysql_close(&mydata);
		return -1;
	}

#ifdef STEPBYSTEP  
	system("pause");
#endif  

	//����в�������  
	sqlstr =
		"INSERT INTO user_info(user_name) VALUES('��˾����'),('һ������'),('��������'),('����С��'),('����');";
	if (0 == mysql_query(&mydata, sqlstr.c_str())) {
		cout << "mysql_query() insert data succeed" << endl;
	}
	else {
		cout << "mysql_query() insert data failed" << endl;
		mysql_close(&mydata);
		return -1;
	}

#ifdef STEPBYSTEP  
	system("pause");
#endif  

	//��ʾ�ղŲ��������  
	sqlstr = "SELECT user_id,user_name,user_second_sum FROM user_info";
	MYSQL_RES *result = NULL;
	if (0 == mysql_query(&mydata, sqlstr.c_str())) {
		cout << "mysql_query() select data succeed" << endl;

		//һ����ȡ�����ݼ�  
		result = mysql_store_result(&mydata);
		//ȡ�ò���ӡ����  
		int rowcount = mysql_num_rows(result);
		cout << "row count: " << rowcount << endl;

		//ȡ�ò���ӡ���ֶε�����  
		unsigned int fieldcount = mysql_num_fields(result);
		MYSQL_FIELD *field = NULL;
		for (unsigned int i = 0; i < fieldcount; i++) {
			field = mysql_fetch_field_direct(result, i);
			cout << field->name << "\t\t";
		}
		cout << endl;

		//��ӡ����  
		MYSQL_ROW row = NULL;
		row = mysql_fetch_row(result);
		while (NULL != row) {
			for (int i = 0; i < fieldcount; i++) {
				cout << row[i] << "\t\t";
			}
			cout << endl;
			row = mysql_fetch_row(result);
		}

	}
	else {
		cout << "mysql_query() select data failed" << endl;
		mysql_close(&mydata);
		return -1;
	}

#ifdef STEPBYSTEP  
	system("pause");
#endif  

	//ɾ���ղŽ��ı�  
	sqlstr = "DROP TABLE user_info";
	if (0 == mysql_query(&mydata, sqlstr.c_str())) {
		cout << "mysql_query() drop table succeed" << endl;
	}
	else {
		cout << "mysql_query() drop table failed" << endl;
		mysql_close(&mydata);
		return -1;
	}
	mysql_free_result(result);
	mysql_close(&mydata);
	mysql_server_end();

	system("pause");
	return 0;
}