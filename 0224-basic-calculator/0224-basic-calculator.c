int calculate(char* s) {
    int len = strlen(s);
    int result = 0, sign = 1, currentNumber = 0;
    int stack[1000], stackIndex = 0;
    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (isdigit(c)){
            currentNumber = currentNumber*10 + (c-'0');
        } 
        else if (c == '+'){
            result += sign*currentNumber;
            sign = 1;
            currentNumber = 0;
        } 
        else if (c == '-'){
            result += sign*currentNumber;
            sign = -1;
            currentNumber = 0;
        } 
        else if (c == '('){
            stack[stackIndex++] = result;
            stack[stackIndex++] = sign;
            result = 0;
            sign = 1;
        } 
        else if (c == ')'){
            result += sign*currentNumber;
            currentNumber = 0;
            sign = stack[--stackIndex];
            result = stack[--stackIndex] + sign * result;
        }
    } 
    result += sign * currentNumber;
    return result;
}