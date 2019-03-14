#include <stdio.h>
#include <string.h>
#include <unistd.h>

//g++ -o StringSimple StringSimple.cpp

class String
{
public:
	String(const char* pStr = "")//构造函数
		:_pStr(new char[strlen(pStr)+1])
	{
		if(0 == *pStr)//字符串为空
		{
			*_pStr = '\0';
		}
		else//字符串不为空
		{
			strcpy(_pStr,pStr);
		}
	}
	String(const String& s)//拷贝构造函数
	{
		_pStr = s._pStr;
	}
	String& operator=(const String& s)//赋值运算符重载
	{
		if(_pStr != s._pStr)//判断是不是自己给自己赋值
		{
			_pStr = s._pStr;
		}
		return *this;
	}
	~String()//析构函数
	{
		if(NULL == _pStr)
		{
			return;
		}
		else
		{
			delete []_pStr;
			_pStr = NULL;
		}
	}
  char* getStrPoint() {
      return _pStr;
    }
private:
	char* _pStr;

};


int main()
{
    String str1("abcdeaaaaa");
    String str2(str1);
    String str3;
    str3 = str1;

    //三个地址是一样的
    printf(" str1: %lx\n", (long)str1.getStrPoint());
    printf(" str2: %lx\n", (long)str2.getStrPoint());
    printf(" str3: %lx\n", (long)str3.getStrPoint());

    sleep(5);
    return 0;
}
