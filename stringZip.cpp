/**********************************************************
 *@file: stringZip.cpp
 *@author: Hu Pan
 *@date: 2015/09/12
 *@version: 0.1
 *@describe: 压缩字符串中连续出现的同一字符为“次数+字符”
 **********************************************************/
 #inlcude <tools.h>
 
void stringZip(const char *pInputStr, long lInputLen, char *pOutputStr)
{
    int num = 1;
    int index = 0;
    char charPre = pInputStr[0];

    for (long i = 1; i != lInputLen; ++i)
    {
        if (pInputStr[i] == charPre)
        {
            ++num;
        }
        else
        {
            if (num > 10)
            {
                numToChar(pOutputStr, num, index);
                pOutputStr[index++] = charPre;
            }
            else
            {
                pOutputStr[index++] = num + '0';
                pOutputStr[index++] = charPre;
            }
            num = 1;
            charPre = pInputStr[i];
        }
    }
    pOutputStr[index] = '\0';
    //display(pOutputStr, pOutputStr + lInputLen);
}
