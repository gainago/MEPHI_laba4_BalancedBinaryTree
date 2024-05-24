int strlen(char* str)
{
    if(str == 0)
        return 0;
    int len = 0;
    while(str[len] != '\0')
        len++;
    
    return len;
}
char* strcat(char* str1, char* str2)
{   
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char* ans = new char[len1 + len2 + 1];
    for(int i = 0; i < len1; i++)
    {
        ans[i] = str1[i];
    }
    for(int i = len1; i < len1 + len2;i++)
        ans[i] = str2[i - len1];
    ans[len1 + len2 ] = '\0';
    return ans;
}