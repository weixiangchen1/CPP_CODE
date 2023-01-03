#include <iostream>
#include <thread>
#include <time.h>
using namespace std;

//double Division(int a, int b)
//{
//	// 当b == 0时抛出异常
//	if (b == 0)
//		throw "Division by zero condition!";
//	else
//		return ((double)a / (double)b);
//}
//
//void Func1()
//{
//	int len, time;
//	cin >> len >> time;
//	cout << Division(len, time) << endl;
//}
//
//int main()
//{
//	try
//	{
//		Func1();
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//	catch (...)
//	{
//		cout << "unknown error" << endl;
//	}
//
//	return 0;
//}

//
//double Division(int a, int b)
//{
//	// 当b == 0时抛出异常
//	if (b == 0)
//		throw "Division by zero condition!";
//	else
//		return ((double)a / (double)b);
//}
//
//void Func1()
//{
//	int* ptr = new int[10];
//	try {
//		int len, time;
//		cin >> len >> time;
//		cout << Division(len, time) << endl;
//	}
//	catch (...) {
//		cout << "delete: " << ptr << endl;
//		delete[] ptr;
//
//		throw;  // 异常重新抛出
//	}
//}
//
//int main()
//{
//	try
//	{
//		Func1();
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//	catch (...)
//	{
//		cout << "unknown error" << endl;
//	}
//
//	return 0;
//}

class Execption
{
public:
	Execption(const string& errmsg, int id)
		:_errmsg(errmsg)
		, _id(id)
	{}

	virtual string what() const
	{
		return _errmsg;
	}

protected:
	string _errmsg;
	int _id;
};

class HttpServerExecption : public Execption
{
public:
	HttpServerExecption(const string& errmsg, int id, string type)
		:Execption(errmsg, id)
		, _type(type)
	{}

	virtual string what() const
	{
		string errmsg;
		errmsg += "HttpServerException: ";
		errmsg += _type;
		errmsg += ":";
		errmsg += _errmsg;
		return errmsg;
	}

private:
	string _type;
};

class CacheExecption : public Execption
{
public:
	CacheExecption(const string& errmsg, int id)
		:Execption(errmsg, id)
	{}

	virtual string what() const
	{
		string errmsg;
		errmsg += "CacheException: ";
		errmsg += _errmsg;
		return errmsg;
	}
};

class SqlExecption : public Execption
{
public:
	SqlExecption(const string& errmsg, int id, string sql)
		:Execption(errmsg, id)
		, _sql(sql)
	{}

	virtual string what() const
	{
		string errmsg;
		errmsg += "SqlException: ";
		errmsg += _errmsg;
		errmsg += " -> ";
		errmsg += _sql;
		return errmsg;
	}
private:
	string _sql;
};

void SqlMgr()
{
	srand(time(0));
	if (rand() % 7 == 0) {
		throw SqlExecption("权限不足", 100, "select * from table where name='jack'");
	}
}


void CacheMgr()
{
	srand(time(0));
	if (rand() % 5 == 0) {
		throw CacheExecption("权限不足", 100);
	}
	else if (rand() % 6 == 0) {
		throw CacheExecption("数据不存在", 101);
	}
	SqlMgr();
}


void HttpServer()
{
	srand(time(0));
	if (rand() % 3 == 0) {
		throw HttpServerExecption("请求资源不存在", 100, "get");
	}
	else if (rand() % 4 == 0) {
		throw HttpServerExecption("权限不足", 200, "post");
	}

	CacheMgr();
}

void ServerStart()
{
	while (true) {
		this_thread::sleep_for(chrono::seconds(1));

		try {
			HttpServer();
		}
		catch (const Execption& e) {
			cout << e.what() << endl;
		}
		catch (...) {
			cout << "Unknown error" << endl;
		}
	}
}


int main()
{
	ServerStart();

	return 0;
}