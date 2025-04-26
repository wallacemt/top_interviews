int romanToInt(char* s) {
    int sum = 0;
    int prev = 0;

    for (int i = strlen(s) - 1; i >= 0; i--) {
        int curr = 0;

        switch (s[i]) {
            case 'I':
                curr = 1;
                break;
            case 'V':
                curr = 5;
                break;
            case 'X':
                curr = 10;
                break;
            case 'L':
                curr = 50;
                break;
            case 'C':
                curr = 100;
                break;
            case 'D':
                curr = 500;
                break;
            case 'M':
                curr = 1000;
                break;
            default:
                break;
        }

        if (curr < prev) {
            sum -= curr;
        } else {
            sum += curr;
        }

        prev = curr;
    }   

    return sum;
}
