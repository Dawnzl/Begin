#include<iostream>
#include<string>
#include<vector>
#include<list>
using namespace std;

// 遍历+修改
void test_stringbl()
{
	string s = "hello World";
	for (size_t i = 0; i < s.size(); ++i)
	{
		s[i] += 1;
	}

	for (size_t i = 0; i < s.size(); ++i)
	{
		cout << s[i] << " ";
	}
	cout << endl;

	// 遍历方法2：迭代器
	string::iterator it = s.begin();
	while (it != s.end())
	{
		*it -= 1;
		++it;
	}
	cout << endl;

	it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// 方法3：范围for，自动往后迭代，自动判断结束
	for (auto& e : s) // 要修改里面的字符，要取别名引用
	{
		e -= 1;
	}
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_stringdd2()
{
	//反向迭代器
	string s1("hello world");
	//string::reverse_iterator rit = s1.rbegin();
	auto rit = s1.rbegin();// 让他自动推导
	while (rit != s1.rend()) // rend的位置反而是首字母
	{
		cout << *rit << " ";
		++rit;//倒着遍历也是++
	}
	cout << endl;
}

void TestPushBack()
{
	string s("hello world");
	size_t sz = s.capacity();
	s.reserve(1000);// 如果知道自己要多少的数组，直接申请，就不需要一直增容了
	// reserve 开空间
	// resize(100,x)  开空间还赋一个初值（不修改就是\0）
	
	
	// 打印字符串(重载输出流)
	cout << s << endl;
	cout << s.c_str() << endl;// 返回地址的输入流，运用到文件处理
	

	//// 要求取出文件的后缀名
	//string file("test.txt");
	////FILE* fout = fopen(file.c_str(), 'w');
	//size_t pos = file.find('.'); //如果遇到同样的，返回第一个到位置
	//if (pos != string::npos)
	//{
	//	// substr(初始位置，末位置) 拷贝部分字符串
	//	string suffix = file.substr(pos, file.size() - pos);
	//	cout << suffix << endl;
	//}

	//// 要求取出文件的后缀名
	//string file1("test.txt.zip");
	////FILE* fout = fopen(file.c_str(), 'w');
	//size_t pos1 = file1.rfind('.'); // 逆序查找
	//if (pos1 != string::npos)
	//{
	//	// substr(初始位置，末位置) 拷贝部分字符串
	//	string suffix1 = file1.substr(pos1, file1.size() - pos);
	//	cout << suffix1 << endl;
	//}

	string url("http://www.cplusplus.com/rewoohd/");
	size_t pos1 = url.find(':');
	string protocol = url.substr(0, pos1 - 0);
	cout << protocol << endl;

	size_t pos2 = url.find('/', pos1 + 3);// 前者是要找的，后者是find1的起始位置
	string domain = url.substr(pos1 + 3, pos2 - pos1 - 3);
	cout << domain << endl;

}

void test_strings()
{
	string s("hello world");
	s += ' ';
	s += "!!!";
	cout << s << endl;

	// 头插 效率O(N),低下，建议不用
	s.insert(0, 1, 'x');
	s.insert(s.begin(), 'x');// 迭代器位置
	s.insert(0, "test ");
	cout << s << endl;

	// 中间位置插入
	s.insert(4, "%%%%");
	cout << s << endl;

}

void test_string1()
{
	string s("hello world");
	// 头删 少用，因为要挪动数据，效率低
	s.erase(0, 1);
	// 尾删
	s.erase(s.size() - 1, 1);
	cout << s << endl;
	s.erase(3); // 从第三个位置删到结束
	cout << s << endl;

}

// /*输入输出*/
//#include <iostream>
//using namespace std;
//int main()
//{
//	string s;
//	//cin>>s; //cin无法读取空格
//	getline(cin, s);
//	size_t pos = s.rfind(' ');//搜索到时的位数里也包括空格
//	if (pos == string::npos)
//	{
//		cout << s.size() << endl;
//	}
//	else
//	{//搜索到时的位数里也包括空格
//		cout << s.size() - pos - 1;
//	}
//	return 0;
//}

int main()
{
	//string s1;//无参构造
	//string s2("hello world");//有参构造
	//string s3(s2);//拷贝字符串
	//string s4(s2, 2, 6);//从拷贝s2字符串第二到第六进行初始化
	//string s5(s2, 2);//从第二个到最后一个
	//string s6(s2, 2, 100);//同上（100超过s2的总长度）

	//string s1;
	//cin >> s1;
	//// 不包含最后作为结尾标识符的\0，有效字符长度
	////长度
	//cout << s1.size() << endl;
	//cout << s1.length() << endl;
	//cout << s1.max_size() << endl;
	////容量
	//cout << s1.capacity() << endl;
	////清理有效数据,容量没清理
	//s1.clear();
	//cout << s1.capacity() << endl;


	//string s1 = "hello world";
	//for (size_t i = 0; i < s1.size(); ++i)
	//{
	//	//可以读
	//	cout << s1[i] << " ";
	//}
	//cout << endl;

	//for (size_t i = 0; i < s1.size(); ++i)
	//{
	//	//可以写(修改每个位置的字符)
	//	s1[i] += 1;
	//}

/*尾插*/
	//string s1;
	//s1.push_back('a'); // 字符尾插
	//s1.append("abcd"); // 字符串尾插
	//cout << s1 << endl;
	///*高级！！*/
	//s1 += ':';
	//s1 += "abcd";
	//cout << s1 << endl;

	//test_stringbl();

	//TestPushBack();
	//test_strings();
	test_string1();
	return 0;
}
