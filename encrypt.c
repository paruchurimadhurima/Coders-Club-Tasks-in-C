int is_alphabet(char c, char k)
{
    if(c>='a'&&c<='z'&&(c+(k-'0'))<='z')
        return 1;
    else
        return 0;
}
int IS_ALPHABET(char c, char k)
{
    if(c>='A'&&c<='Z'&&(c+(k-'0'))<='Z')
        return 1;
    else
        return 0;
}
char into_string( char c, char k)
{
    return c+(k-'0');
}
char not_is_alphabet(char c, char k)
{
    int num='{'-c;
    return ('a'+(k-'0'-num)) ;
}
char NOT_IS_ALPHABET(char c, char k)
{
    int num='['-c;
    return 'A'+(k-'0'-num) ;
}
char * encrypt( char *str, char *key)
{
    int len1,len2;
    len1=strlen(str);
    len2=strlen(key);
    char *str1;
    str1=(char *)malloc(sizeof(char)*len1+1);
    if(len1!=len2)
        return NULL;
    int i=0;
    for(i=0; i<len1; i++)
    {
        if(IS_ALPHABET(str[i], key[i]))
        {
            str1[i]=into_string(str[i],key[i]);
        }
        else if(IS_ALPHABET(str[i],'0'))
        {
            str1[i]=NOT_IS_ALPHABET(str[i],key[i]);
        }
        else if(is_alphabet(str[i], key[i]))
        {
            str1[i]=into_string(str[i],key[i]);
        }
        else if(is_alphabet(str[i],'0'))
        {
            str1[i]= not_is_alphabet(str[i],key[i]);
        }
        else
        {
            str1[i]=str[i];
        }
    }
    str1[i]='\0';
    return str1;
}
void test_encrypt(char *expected, char *actual, int num)
{
    if(!strcmp(expected,actual))
    {
        printf("%d Testcase passes , your output is %s \n",num,expected);
    }
    else
        printf("%d Testcase failed , your output is %s  expected is %s\n",num,actual,expected);
}