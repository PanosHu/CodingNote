/************************************
 *@file: initialsInCapitals.cpp
 *@author: Hu Pan
 *@date: 2015/9/12
 *@version: 0.1
 *@describe: 字符串中单词首字母大写
 ************************************/
#include <cctype>
#include "tools.cpp"

void initialsInCapitals(string &src)
{
    if(0 == src.size())
    {
        return;
    }
    //display(src.begin(),src.end());
    //转换成大写字母的条件：当前字符是字母且前一个字符是空格
    bool preIsSpace = true;
    for(size_t i = 0; i != src.size(); ++i)
    {
        if(preIsSpace && isalpha(src[i]))
        {
            src[i] = isupper(src[i])?src[i]:toupper(src[i]);
            preIsSpace = false;
        }
        else
        {
            preIsSpace = isspace(src[i])?true:false;
        }
    }
    //display(src.begin(),src.end());
}

int main()
{
    string str;
    getline(cin,str);
    initialsInCapitals(str);
    return 0;
}
