/******************************************************************************
 * @file   tool.c
 * @brief  This file is a collection of function usually used * as basic
 *         tools.  Functions are generally simple.
 * @author zhuzi
 * ----------------------------------------------------------------------------
 * 2020/06/04       | 1.0          | zhuzi           | Create file
 * ----------------------------------------------------------------------------
 *
******************************************************************************/
#include "pcaptool.h"

/******************************************************************************
 * @brief          To find a specific substring from a longer string
 * @param   str1   main string
 * @param   str2   substring
 * @return  j      Return the first index where substring appears in main string
 *          -1     Fail
******************************************************************************/
char findSubstring(char *str1, char *str2)
{
    if (NULL == str1 || NULL == str2 || (strlen(str1) < strlen(str2)))
        return -1;
    char *mainStr = strToLowerCase(str1, sizeof(str1));
    size_t index = 0;
    char *cur = mainStr;
    while (cur)
    {
        char *strLoop = cur;
        char *subLoop = str2;
        while (subLoop && strLoop && *subLoop == *strLoop)
        {
            subLoop++;
            strLoop++;
        }
        if ('\0' == *subLoop)
            break;
        else if ('\0' == *strLoop)
            return -1;
        else
        {
            cur++;
            index++;
        }
    }
    return index;
}

/******************************************************************************
 * @brief          To find the request line from a http request header
 * @param   str1   http header
 * @return  j      length of the request line
 *          -1     Fail
******************************************************************************/
char getHttpHeaderFirstLine(char *pcapFile)
{
    if (NULL == pcapFile)
        return -1;
    unsigned int index = 0;
    index = findSubstring(pcapFile, "\n");
    if (index < 15)
        return -1;
    return index;
}

/******************************************************************************
 * @brief          Take out the first line from buf to a string
 * @param   offset the offset of the character of the first '\n' in buf
 * @return  j      string of the request line
 *          NULL   Fail
******************************************************************************/
char *copyBufToHttpFirstLine(unsigned int offset)
{
    if (0 >= offset)
        return NULL;
    char *reqLine;
    memset(reqLine, '\0', offset + 1);
    for (size_t i = 0; i < offset; i++)
    {
        reqLine[i] = buf[i];
    }
    return reqLine;
}

/******************************************************************************
 * @brief          Get field from a longer string
 * @param   str1   string to be searched in
 * @param   set    the collection of the specific field
 * @param   setLen the length of the collection
 * @return  field  the specific field found in the long string
 *          NULL   Fail
******************************************************************************/
char *findFieldInString(char *str, char **set, unsigned int setLen)
{
    if (NULL == str || NULL == set || NULL == *set || setLen <= 0)
        return NULL;
    int num = -1;
    unsigned int indexTmp = 0;
    for (size_t i = 0; i < setLen; i++)
    {
        num = findSubstring(str, *set);
        // printf("the method  is %s\n", *set);
        if (num >= 0)
            break;
        set++;
    }
    if (num >= 0)
        return *set;
    return NULL;
    // printf("the method  is %s\n", *set);
}

/******************************************************************************
 * @brief          Change the param1 to its lower case
 * @param   str1   string to be changed
 * @return  field  the specific field found in the long string
 *          EOF    Fail
******************************************************************************/
char *strToLowerCase(char *str, unsigned int strLen)
{
    if (NULL == str)
        return NULL;
    char *strRtn = str;
    // memset(strRtn, 0, strLen);
    for (size_t i = 0; i < strLen; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            strRtn[i] = str[i] + 32;
        }
        else
        {
            strRtn[i] = str[i];
        }
    }
    return strRtn;
}
