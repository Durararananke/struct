#include<Stack.h>
bool BracketsCheck(char *str)
{
    Stack S;
    InitStack(S);
    int i = 0;
    char e;
    while (str[i] != '\0')
    {
        switch (str[i])
        {
        case '(':
        case '[':
        case '{':
            Push(S, str[i]);
            break;
        case ')':
        case ']':
        case '}':
            Pop(S, e);
            if ((str[i] == ')' && e != '(') ||
                (str[i] == ']' && e != '[') ||
                (str[i] == '}' && e != '{'))
            {
                return false;
            }
            break;
        default:
            break;
        }
        i++;
    }
    if (!IsEmpty(S))
    {
        return false;
    }
    return true;
}