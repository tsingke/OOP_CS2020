/*----------------------------------*
		 Class Definition
*-----------------------------------*/
//�ַ���:ȫ�����ַ�����ʵ��
class Mystring
{
private:
	char *ps;

public:
	/*----------����һ��--------*/
	Mystring();
	Mystring(const char *pt);

	Mystring(const Mystring &r);
	~Mystring();

	/*----------��ͨ����--------*/
	Mystring& stringCat(const Mystring &r);//�ַ�����������
	int stringCmp(const Mystring &r);//�ַ�������Ƚ�

	Mystring& stringInsert(const Mystring &r, int pos);//�ַ�������
	Mystring& stringDelete(int pos);//�ַ�ɾ��
	Mystring& stringModify(int pos);//�ַ��޸�
	int   stringSearch();//�����ַ�

	Mystring& stringReverse();//�ַ�����ת
	int   stringLength();//�ַ������С

	Mystring& show();

	char * getPS();
	
};




