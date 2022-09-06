#include<iostream>
#include<algorithm>
#include<vector>// 顺序表
using namespace std;

void test_vector1()// 初始化
{
	vector<int> v1;
	vector<int> v2(10, 8);
	vector<int> v3(++v2.begin(), --v2.end());
	vector<int> v4(v3);

	string s("hello world");
	vector<char>v5(s.begin(), s.end());
}

void test_vector2()// 头插
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	// 遍历
	for (size_t i = 0; i < v.size(); ++i)
	{
		v[i] += 1;
		cout << v[i] << " ";
	}
	cout << endl;

	// 迭代器
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		*it -= 1;
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// 范围for
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}


void test_vector3()// 扩容
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	//v.reserve(100);
	//v.resize(100, 5);// 扩容加初始化 或 删除数据

	//搜索  在算法头文件里
	vector<int>::iterator ret = find(v.begin(), v.end(), 2);
	if (ret != v.end()) //找不到就返回最左边
	{
		cout << "找到了" << endl;
		v.insert(ret, 30); // 插入
	}

	// 头插
	v.insert(v.begin(), -1);

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	// 删除（要查找判断是否存在，不然迭代器会失效）
	vector<int>::iterator pos = find(v.begin(), v.end(), 2);
	if (ret != v.end()) //找不到就返回最左边
	{
		v.erase(pos);
	}

	// 清理所有数据
	v.clear();
}


int main()
{
	test_vector2();
	return 0;
}