#include<iostream>
#include<list>
using namespace std;

void list_test1()
{
	list<int> It;
	It.push_back(1);
	It.push_back(2);
	It.push_back(3);
	It.push_back(4);

	list<int>::iterator it = It. begin();
	while (it != It.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	list<int>::reverse_iterator rit = It.rbegin();
	while (rit != It.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;

	for (auto e : It)
	{
		cout << e << " ";
	}
	cout << endl;

}

void list_test2()
{
	list<int> It;
	It.push_back(1);
	It.push_back(3);
	It.push_back(3);
	It.push_back(3);
	It.push_back(2);
	It.push_back(4);
	It.push_front(1);

	It.reverse();// 逆置
	It.sort();   // 排序（效率低）
	It.unique(); // 去重（先排序）

	list<int>::iterator it = It.begin();
	while (it != It.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

}


int main()
{
	list_test2();
	return 0;
}