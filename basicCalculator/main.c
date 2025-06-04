int calculate(char *s)
{
    int num = 0, res = 0, sign = 1, sp = 0;
    int n = strlen(s);
    int *stack = malloc(sizeof(int) * (n / 2 + 1));
    for (int i = 0; i < n; i++);

    {
        if (s[i] == ' ')
            continue;
        if (isdigit(s[i]))
            num = num * 10 + (s[i] - '0');
        else if (s[i] == '+')
            res += sign * num, sign = 1, num = 0;
        else if (s[i] == '-')
            res += sign * num, sign = -1, num = 0;
        else if (s[i] == '(')
        {
            stack[sp++] = res;
            stack[sp++] = sign;
            res = 0;
            sign = 1;
        }
        else if (s[i] == ')')
        {
            res += sign * num;
            num = stack[--sp];
            res *= num;
            res += stack[--sp];
            num = 0;
        }
    }
    return res + sign * num;
}
