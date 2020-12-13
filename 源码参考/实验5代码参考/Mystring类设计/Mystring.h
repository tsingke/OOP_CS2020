/*----------------------------------*
		 Class Definition
*-----------------------------------*/
//字符串:全部由字符数组实现
class Mystring
{
private:
	char *ps;

public:
	/*----------三构一析--------*/
	Mystring();
	Mystring(const char *pt);

	Mystring(const Mystring &r);
	~Mystring();

	/*----------普通函数--------*/
	Mystring& stringCat(const Mystring &r);//字符串对象连接
	int stringCmp(const Mystring &r);//字符串对象比较

	Mystring& stringInsert(const Mystring &r, int pos);//字符串增加
	Mystring& stringDelete(int pos);//字符删除
	Mystring& stringModify(int pos);//字符修改
	int   stringSearch();//查找字符

	Mystring& stringReverse();//字符串翻转
	int   stringLength();//字符数组大小

	Mystring& show();

	char * getPS();
	
};




