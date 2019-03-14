#include <stdio.h>
#include <string.h>



class String
{

 public:
  //构造函数
  String(const char* pStr = "")
    :_pStr(new char[strlen(pStr) + 1])
    ,_cnt(new int(0))
    {
      if (0 == *pStr) {
        *_pStr = '\0';
      }
      else //字符串 不为空
      {
        strcpy(_pStr, pStr);
      }
      (*_cnt)++;
      printf("==构造函数==\n");
    }

    String(const String& s) //拷贝构造函数
    {
      _pStr = s._pStr;
      _cnt = s._cnt;
      (*_cnt)++;
      printf("==拷贝构造函数==\n");
    }

    ~String() //析构函数
    {
      if(NULL == _pStr)
      {
        return ;
      }
      else
      {
        if ((--(*_cnt)) == 0)
        {
          delete _cnt;
          delete []_pStr;
          _cnt = NULL;
          _pStr = NULL;
        }
      }
      printf("==析构函数==\n");
    }

    String& operator=(const String& s) //赋值运算符
    {
      if(_pStr != s._pStr)
      {
        //先释放旧数据
        if (NULL != _pStr)
        {
          if ((--(*_cnt)) == 0)
          {
            delete _cnt;
            delete []_pStr;
            _cnt = NULL;
            _pStr = NULL;
            printf("==赋值函数,释放旧内存==\n");
          }
        }
        _pStr = s._pStr;
        _cnt = s._cnt;
        (*_cnt)++;
      }

      printf("==赋值函数==\n");
      return *this;
    }

 private:
  char* _pStr;
  int* _cnt;
};

int main()
{
    String str1("abcdeabbbb");
    String str2(str1);
    String str3;
    str3 = str1;

    return 0;
}
