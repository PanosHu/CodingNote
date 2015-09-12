/******************************************
 *@file: sameStringFilter.cpp
 *@author: Hu Pan
 *@date:
 *@version: 0.1
 *@describe: 清除字符串中非第一次出现的字符
 ******************************************/
#include "tools.h"
#include <cctype>

void sameStringFilter(const char *pInputStr, long lInputLen, char *pOutputStr)
{
    int charNumCount[26];
    memset(charNumCount, 0, sizeof(int)* 26);

    long j = 0;
    for (long i = 0; i != lInputLen; ++i)
    {
        ++charNumCount[pInputStr[i] - 'a'];
        if (islower(pInputStr[i]) && 1 == charNumCount[pInputStr[i] - 'a'])
        {
            pOutputStr[j++] = pInputStr[i];
        }
    }
    pOutputStr[j] = '\0';
    //display(pInputStr, pInputStr + lInputLen);
    //display(charNumCount, charNumCount + 26);
    //display(pOutputStr, pOutputStr + lInputLen);
}
