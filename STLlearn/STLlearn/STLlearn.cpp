#include<iostream>
#include<string>
#include<vector>
#include<list>
using namespace std;

// ����+�޸�
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

	// ��������2��������
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

	// ����3����Χfor���Զ�����������Զ��жϽ���
	for (auto& e : s) // Ҫ�޸�������ַ���Ҫȡ��������
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
	//���������
	string s1("hello world");
	//string::reverse_iterator rit = s1.rbegin();
	auto rit = s1.rbegin();// �����Զ��Ƶ�
	while (rit != s1.rend()) // rend��λ�÷���������ĸ
	{
		cout << *rit << " ";
		++rit;//���ű���Ҳ��++
	}
	cout << endl;
}

void TestPushBack()
{
	string s("hello world");
	size_t sz = s.capacity();
	s.reserve(1000);// ���֪���Լ�Ҫ���ٵ����飬ֱ�����룬�Ͳ���Ҫһֱ������
	// reserve ���ռ�
	// resize(100,x)  ���ռ仹��һ����ֵ�����޸ľ���\0��
	
	
	// ��ӡ�ַ���(���������)
	cout << s << endl;
	cout << s.c_str() << endl;// ���ص�ַ�������������õ��ļ�����
	

	//// Ҫ��ȡ���ļ��ĺ�׺��
	//string file("test.txt");
	////FILE* fout = fopen(file.c_str(), 'w');
	//size_t pos = file.find('.'); //�������ͬ���ģ����ص�һ����λ��
	//if (pos != string::npos)
	//{
	//	// substr(��ʼλ�ã�ĩλ��) ���������ַ���
	//	string suffix = file.substr(pos, file.size() - pos);
	//	cout << suffix << endl;
	//}

	//// Ҫ��ȡ���ļ��ĺ�׺��
	//string file1("test.txt.zip");
	////FILE* fout = fopen(file.c_str(), 'w');
	//size_t pos1 = file1.rfind('.'); // �������
	//if (pos1 != string::npos)
	//{
	//	// substr(��ʼλ�ã�ĩλ��) ���������ַ���
	//	string suffix1 = file1.substr(pos1, file1.size() - pos);
	//	cout << suffix1 << endl;
	//}

	string url("http://www.cplusplus.com/rewoohd/");
	size_t pos1 = url.find(':');
	string protocol = url.substr(0, pos1 - 0);
	cout << protocol << endl;

	size_t pos2 = url.find('/', pos1 + 3);// ǰ����Ҫ�ҵģ�������find1����ʼλ��
	string domain = url.substr(pos1 + 3, pos2 - pos1 - 3);
	cout << domain << endl;

}

void test_strings()
{
	string s("hello world");
	s += ' ';
	s += "!!!";
	cout << s << endl;

	// ͷ�� Ч��O(N),���£����鲻��
	s.insert(0, 1, 'x');
	s.insert(s.begin(), 'x');// ������λ��
	s.insert(0, "test ");
	cout << s << endl;

	// �м�λ�ò���
	s.insert(4, "%%%%");
	cout << s << endl;

}

void test_string1()
{
	string s("hello world");
	// ͷɾ ���ã���ΪҪŲ�����ݣ�Ч�ʵ�
	s.erase(0, 1);
	// βɾ
	s.erase(s.size() - 1, 1);
	cout << s << endl;
	s.erase(3); // �ӵ�����λ��ɾ������
	cout << s << endl;

}

// /*�������*/
//#include <iostream>
//using namespace std;
//int main()
//{
//	string s;
//	//cin>>s; //cin�޷���ȡ�ո�
//	getline(cin, s);
//	size_t pos = s.rfind(' ');//������ʱ��λ����Ҳ�����ո�
//	if (pos == string::npos)
//	{
//		cout << s.size() << endl;
//	}
//	else
//	{//������ʱ��λ����Ҳ�����ո�
//		cout << s.size() - pos - 1;
//	}
//	return 0;
//}

int main()
{
	//string s1;//�޲ι���
	//string s2("hello world");//�вι���
	//string s3(s2);//�����ַ���
	//string s4(s2, 2, 6);//�ӿ���s2�ַ����ڶ����������г�ʼ��
	//string s5(s2, 2);//�ӵڶ��������һ��
	//string s6(s2, 2, 100);//ͬ�ϣ�100����s2���ܳ��ȣ�

	//string s1;
	//cin >> s1;
	//// �����������Ϊ��β��ʶ����\0����Ч�ַ�����
	////����
	//cout << s1.size() << endl;
	//cout << s1.length() << endl;
	//cout << s1.max_size() << endl;
	////����
	//cout << s1.capacity() << endl;
	////������Ч����,����û����
	//s1.clear();
	//cout << s1.capacity() << endl;


	//string s1 = "hello world";
	//for (size_t i = 0; i < s1.size(); ++i)
	//{
	//	//���Զ�
	//	cout << s1[i] << " ";
	//}
	//cout << endl;

	//for (size_t i = 0; i < s1.size(); ++i)
	//{
	//	//����д(�޸�ÿ��λ�õ��ַ�)
	//	s1[i] += 1;
	//}

/*β��*/
	//string s1;
	//s1.push_back('a'); // �ַ�β��
	//s1.append("abcd"); // �ַ���β��
	//cout << s1 << endl;
	///*�߼�����*/
	//s1 += ':';
	//s1 += "abcd";
	//cout << s1 << endl;

	//test_stringbl();

	//TestPushBack();
	//test_strings();
	test_string1();
	return 0;
}
