#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	// λ����
	/*
	��������һ�ĸ���
	*/
	int N = 0;
	cin >> N;
	int count = 0;
	for (int i = 0; i < 32; ++i)
	{
		if (((N >> i) & 1) == 1)
			count++;
	}
	cout << count << endl;

	count = 0;
	while (N != 0)
	{
		N = N & (N - 1);
		count++;
	}
	cout << count << endl;

	return 0;
}