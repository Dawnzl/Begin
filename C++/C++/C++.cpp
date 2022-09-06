////命名空间及引用
//#include<stdio.h>
//namespace yzl
//{
//	int a = 1;
//	int add(int l, int r)
//	{
//		return l + r;
//	}
//	struct Note
//	{
//		struct Node* next;
//		int val;
//
//	};
//}
//
//int main()
//{
//	yzl::a;
//	struct yzl::Node;
//	yzl::add;
//	return 0;
//}

#include<iostream>
using namespace std;

//全缺省
void Func(int a = 10, int b = 20, int c = 30)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl << endl;

}
//部分缺省
void Func(int a, int b, int c = 30)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl << endl;

}

int main()
{
	cout << "hello world" << endl;//输出流，end1回车
	int i = 10;
	double d = 1.11;
	//自动识别类型
	cout << i << " " << d << endl;

	cin >> i >> d;
	cout << i << " " << d << endl;

	

	return 0;
}
