#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
    string arr[10] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
public:
    void _letterCombinations(const string& digits, size_t i, string combinStr, vector<string>& strV)// ��������������ӣ��������ɱ��ַ����洢���ַ���˳���
    {
        // �����������������
        if (i == digits.size())
        {
            strV.push_back(combinStr);
            return;
        }

        // �ݹ����
        string str = arr[digits[i] - '0'];
        for (size_t j = 0; j < str.size(); ++j)
        {
            _letterCombinations(digits, i + 1, combinStr + str[j], strV);// i+1 �� combinStr + str[j] �ص㣺���� i++��combinStr += str[j]
        }
    }

    vector<string> letterCombinations(string digits) {
        string combinStr;
        vector<string> strV;
        // �п� �������
        if (digits.empty())
            return strV;

        _letterCombinations(digits, 0, combinStr, strV);

        return strV;
    }


};