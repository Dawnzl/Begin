#include<iostream>
#include<algorithm>
#include<vector>// ˳���
using namespace std;

void test_vector1()// ��ʼ��
{
	vector<int> v1;
	vector<int> v2(10, 8);
	vector<int> v3(++v2.begin(), --v2.end());
	vector<int> v4(v3);

	string s("hello world");
	vector<char>v5(s.begin(), s.end());
}

void test_vector2()// ͷ��
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	// ����
	for (size_t i = 0; i < v.size(); ++i)
	{
		v[i] += 1;
		cout << v[i] << " ";
	}
	cout << endl;

	// ������
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		*it -= 1;
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// ��Χfor
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}


void test_vector3()// ����
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	//v.reserve(100);
	//v.resize(100, 5);// ���ݼӳ�ʼ�� �� ɾ������

	//����  ���㷨ͷ�ļ���
	vector<int>::iterator ret = find(v.begin(), v.end(), 2);
	if (ret != v.end()) //�Ҳ����ͷ��������
	{
		cout << "�ҵ���" << endl;
		v.insert(ret, 30); // ����
	}

	// ͷ��
	v.insert(v.begin(), -1);

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	// ɾ����Ҫ�����ж��Ƿ���ڣ���Ȼ��������ʧЧ��
	vector<int>::iterator pos = find(v.begin(), v.end(), 2);
	if (ret != v.end()) //�Ҳ����ͷ��������
	{
		v.erase(pos);
	}

	// ������������
	v.clear();
}


int main()
{
	test_vector2();
	return 0;
}