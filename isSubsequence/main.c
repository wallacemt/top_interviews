
bool isSubsequence(char *s, char *t)
{
    int i = 0, j = 0;
    while (s[i] != '\0')
    {
        while (t[j] != '\0' && t[j] != s[i])
            j++;
        if (t[j] == '\0')
            return false;
        i++;
        j++;
    }
    return true;
}