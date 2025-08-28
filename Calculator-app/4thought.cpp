#include <iostream>
#include <string>
#include <map>
using namespace std;

// Evaluate expression with correct precedence and truncating division
int eval(int a, char op1, int b, char op2, int c, char op3, int d) {
    int nums[4] = {a, b, c, d};
    char ops[3] = {op1, op2, op3};
    int temp[4], t = 0;
    char tempOps[3];
    int to = 0;
    temp[t++] = nums[0];
    // First handle * and /
    for (int i = 0; i < 3; i++) {
        if (ops[i] == '*') temp[t-1] *= nums[i+1];
        else if (ops[i] == '/') temp[t-1] /= nums[i+1];
        else { temp[t++] = nums[i+1]; tempOps[to++] = ops[i]; }
    }
    // Then handle + and -
    int res = temp[0];
    for (int i = 0; i < to; i++)
        res = (tempOps[i] == '+') ? res + temp[i+1] : res - temp[i+1];
    return res;
}

int main() {
    char ops[] = {'+', '-', '*', '/'};
    map<int, string> exprs;

    // Try all combinations of three operators
    for (char op1 : ops)
    for (char op2 : ops)
    for (char op3 : ops) {
        int result = eval(4, op1, 4, op2, 4, op3, 4);
        string expr = "4 ";
        expr += op1; expr += " 4 ";
        expr += op2; expr += " 4 ";
        expr += op3; expr += " 4 = ";
        expr += to_string(result);
        exprs[result] = expr;
    }

    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        if (exprs.count(n)) cout << exprs[n] << endl;
        else cout << "no solution" << endl;
    }
    return 0;
}
