#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
    string arr[10] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
public:
    void _letterCombinations(const string& digits, size_t i, string combinStr, vector<string>& strV)// 引用数字输入句子，层数，可变字符串存储，字符串顺序表
    {
        // 结束条件，归的条件
        if (i == digits.size())
        {
            strV.push_back(combinStr);
            return;
        }

        // 递归过程
        string str = arr[digits[i] - '0'];
        for (size_t j = 0; j < str.size(); ++j)
        {
            _letterCombinations(digits, i + 1, combinStr + str[j], strV);// i+1 和 combinStr + str[j] 重点：不是 i++，combinStr += str[j]
        }
    }

    vector<string> letterCombinations(string digits) {
        string combinStr;
        vector<string> strV;
        // 判空 极限情况
        if (digits.empty())
            return strV;

        _letterCombinations(digits, 0, combinStr, strV);

        return strV;
    }


};