/********************************
 *@file: tools.cpp
 *@author: Hu Pan
 *@date: 2015/09/12
 *@version: 0.1
 *@describe: coding工具函数合集
 ********************************/
#include <iostream>
#include <stack>
using namespace std;

template <typename T>
void my_swap(T *var1, T *var2)
{
    if (*var1 != *var2)
    {
        *var1 ^= *var2;
        *var2 ^= *var1;
        *var1 ^= *var2;
    }
}

template <typename T>
void display(T *beg, T *end)
{
    while (beg != end)
    {
        cout << *beg++ ;
    }
    cout << endl;
}

void numToChar(char *src, int num, int &index)
{
    stack<int> sta;
    while (num)
    {
        sta.push(num % 10);
        num /= 10;
    }
    while (sta.size())
    {
        src[index++] = sta.top() + '0';
        sta.pop();
    }
}
