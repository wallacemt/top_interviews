char* intToRoman(int num) {
    char* result = malloc(sizeof(char) * 20); 
    int index = 0;
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            for (char* p = symbols[i]; *p != '\0'; p++) {
                result[index++] = *p;
            }
            num -= values[i];
        }
    }
    result[index] = '\0';
    return result;
}

