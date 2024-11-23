//#include <iostream>
//#include <string>
//#include <stack>
//#include <cmath>
//#include <iomanip>
//using namespace std;
//struct Boolean_operations {
//    int operand_count;
//    char operands[20];
//} obj;
//
//void count_operand(string exp);
//void print_truthTable(string exp);
//bool balanced_brackets(string exp);
//bool is_operand(char c);
//bool is_operator(char c);
//int precedence(char op);
//int evaluate_operand(int a, int b, char op);
//int apply_negation(int a, char op);
//string generate_postfix(string exp);
//int search(char c, char* arr, int num);
//int calculate_postfix(string exp, int* val, char* ar, int num);
//bool is_exp_equivalent(string exp1, string exp2);
//string decimal_to_binary(int deci, int bits);
//void display_menu();
//void display_signs();
//
//
//int main() {
//    while (true) {
//        display_menu();
//
//        int ch;
//        cin >> ch;
//
//        switch (ch) {
//        case 1: {
//            system("CLS");
//            display_signs();
//            cin.ignore();
//
//            string exp, exp2;
//            cout << "Enter the first Boolean expression:\n";
//            getline(cin, exp);
//            cout << "Enter the second Boolean expression:\n";
//            getline(cin, exp2);
//
//            if (!balanced_brackets(exp) || !balanced_brackets(exp2)) {
//                cout << "One or both expressions have improper brackets.\n";
//                break;
//            }
//
//            cout << "\nTruth Table for Expression 1:\n";
//            count_operand(exp);
//            print_truthTable(exp);
//
//            cout << "\nTruth Table for Expression 2:\n";
//            count_operand(exp2);
//            print_truthTable(exp2);
//
//           
//            if (is_exp_equivalent(exp, exp2)) {
//                cout << "\nThe expressions are logically equivalent.\n";
//            }
//            else {
//                cout << "\nThe expressions are NOT logically equivalent.\n";
//            }
//            
//            break;
//        }
//        case 2:
//
//            cout << "\n\n\t\t     Credits:"<<endl;
//           
//            cout << " \n\t\tCreated by Usman Dilbar and Ajmal Razzaq Bhatti" << endl;
//            cout << "\t\tBoolean Expression Evaluator" << endl;
//            cout << "\t\tThis program evaluates logical expressions, generates truth tables, " << endl;
//            cout << " \t\tand checks if two Boolean expressions are logically equivalent\n\n" << endl;
//            break;
//        case 0:
//            return 0;
//        default:
//            cout << "Invalid choice. Please try again.\n";
//        }
//        system("pause");
//        system("CLS");
//    }
//    return 0;
//}
//
//void count_operand(string exp) {
//    obj.operand_count = 0;
//    for (int i = 0; i < exp.length(); i++) {
//        char c = exp[i];
//        if (is_operand(c)) {
//            bool flag = false;
//            for (int j = 0; j < obj.operand_count; j++) {
//                if (c == obj.operands[j]) {
//                    flag = true;
//                    break;
//                }
//            }
//            if (!flag) {
//                obj.operands[obj.operand_count++] = c;
//            }
//        }
//    }
//
//
//}
//
//
//static int search (string c, string* arr, int num) {
//    for (int i = 0; i < num; i++) {
//        if (arr[i] == c) return i;
//    }
//    return -1;
//}
//
//
//void print_truthTable(string exp) {
//    int len = exp.length();
//    // Extract unique operands from the expression
//    if (obj.operand_count == 0) {
//        for (int i = 0;i < len;i++) {
//            if (is_operand(exp[i]) && search(exp[i], obj.operands, obj.operand_count) == -1) {
//                obj.operands[obj.operand_count++] = exp[i];
//            }
//        }
//    }
//
//   
//    string postfix = generate_postfix(exp);
//    int pfxlen = postfix.length();
//    int sub_expr_count = 0;
//    string* sub_expressions = new string[100]; // Assume a max size of 100 for sub-expressions
//    // Extract and track sub-expressions for evaluation
//    stack<string> stk;
//    for (int i = 0;i < pfxlen;i++) {
//        if (is_operand(postfix[i])) {
//            stk.push(string(1, postfix[i]));
//        }
//        else if (is_operator(postfix[i])) {
//            if (postfix[i] == '!') {
//                string a = stk.top();
//                stk.pop();
//                string new_expr = postfix[i] + a;
//                if (search(new_expr, sub_expressions, sub_expr_count) == -1) {
//                   
//                    sub_expressions[sub_expr_count++] = new_expr;
//                }
//                stk.push(new_expr);
//            }
//            else {
//                string b = stk.top(); stk.pop();
//                string a = stk.top(); stk.pop();
//                string new_expr = "(" + a + postfix[i] + b + ")";
//                if (search(new_expr, sub_expressions, sub_expr_count) == -1) {
//                    sub_expressions[sub_expr_count++] = new_expr;
//                }
//                stk.push(new_expr);
//            }
//        }
//    }
//
//    // Final expression in the stack
//    string final_expression = stk.top();
//    if (search(final_expression, sub_expressions, sub_expr_count) == -1) {
//        sub_expressions[sub_expr_count++] = final_expression;
//    }
//
//    // Header row
//    const int col_width = 20; // Fixed column width for better alignment
//    for (int i = 0; i < obj.operand_count; ++i) {
//        cout << "| " << setw(col_width) << obj.operands[i] << " ";
//    }
//    for (int i = 0; i < sub_expr_count; ++i) {
//        cout << "| " << setw(col_width) << sub_expressions[i] << " ";
//    }
//    cout << "|\n";
//
//    // Separator
//    for (int i = 0; i < obj.operand_count + sub_expr_count; ++i) {
//        cout << string(col_width + 3, '-') << "-";
//    }
//    cout << "\n";
//
//    // Truth table rows
//    int* operand_values = new int[obj.operand_count];
//    for (int i = 0; i < pow(2, obj.operand_count); ++i) {
//        string binary = decimal_to_binary(i, obj.operand_count);
//
//        // Assign binary values to operands
//        for (int j = 0; j < obj.operand_count; ++j) {
//            operand_values[j] = binary[j] - '0';
//            cout << "| " << setw(col_width) << operand_values[j] << " ";
//        }
//
//        // Evaluate sub-expressions
//        for (int j = 0; j < sub_expr_count; ++j) {
//            string sub_postfix = generate_postfix(sub_expressions[j]);
//            int result = calculate_postfix(sub_postfix, operand_values, obj.operands, obj.operand_count);
//            cout << "| " << setw(col_width) << result << " ";
//        }
//        cout << "|\n";
//    }
//
//    // Clean up dynamic memory
//    delete[] operand_values;
//    delete[] sub_expressions;
//}
//
//
//
//
//
//
//
//
//
//bool balanced_brackets(string exp) {
//    stack<char> s;
//    for (int i = 0; i < exp.length(); i++) {
//        char c = exp[i];
//        if (c == '(') {
//            s.push(c);
//        }
//        else if (c == ')') {
//            if (s.empty() || s.top() != '(') {
//                return false;
//            }
//            s.pop();
//        }
//    }
//    return s.empty();
//}
//
//bool is_operand(char c) {
//    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
//}
//
//bool is_operator(char c) {
//    return c == '!' || c == '&' || c == '|' || c == '>' || c == '^';
//}
//
//int precedence(char op) {
//    if (op == '!') return 4;
//    if (op == '&') return 3;
//    if (op == '|') return 2;
//    if (op == '>' || op == '^') return 1;
//    return 0;
//}
//
//int evaluate_operand(int a, int b, char op) {
//    switch (op) {
//    case '&': return a & b;
//    case '|': return a | b;
//    case '>': return (!a | b);
//    case '^': return (a == b);
//    default: return 0;
//    }
//}
//
//int apply_negation(int a, char op) {
//    if (op == '!') return !a;
//    return -1;
//}
//
//string generate_postfix(string exp) {
//    stack<char> stk;
//    string result;
//    for (int i = 0; i < exp.length(); i++) {
//        char ch = exp[i];
//        if (is_operand(ch)) {
//            result += ch;
//        }
//        else if (ch == '(') {
//            stk.push(ch);
//        }
//        else if (ch == ')') {
//            while (!stk.empty() && stk.top() != '(') {
//                result += stk.top();
//                stk.pop();
//            }
//            if (!stk.empty()) stk.pop();
//        }
//        else {
//            while (!stk.empty() && precedence(ch) <= precedence(stk.top())) {
//                result += stk.top();
//                stk.pop();
//            }
//            stk.push(ch);
//        }
//    }
//    while (!stk.empty()) {
//        result += stk.top();
//        stk.pop();
//    }
//    return result;
//}
//
//int search(char c, char* arr, int num) {
//    for (int i = 0; i < num; i++) {
//        if (arr[i] == c) return i;
//    }
//    return -1;
//}
//
//int calculate_postfix(string exp, int* val, char* ar, int num) {
//    stack<int> stk;
//    for (int i = 0; i < exp.length(); i++) {
//        char c = exp[i];
//        if (is_operand(c)) {
//            int idx = search(c, ar, num);
//            stk.push(val[idx]);
//        }
//        else {
//            if (stk.empty()) return -1;
//            int a = stk.top(); stk.pop();
//            if (c == '!') stk.push(apply_negation(a, c));
//            else {
//                if (stk.empty()) return -1;
//                int b = stk.top(); stk.pop();
//                stk.push(evaluate_operand(b, a, c));
//            }
//        }
//    }
//    return stk.top();
//}
//
//bool is_exp_equivalent(string exp1, string exp2) {
//    string postfix1 = generate_postfix(exp1);
//    string postfix2 = generate_postfix(exp2);
//
//    count_operand(exp1);
//    int operand_count = obj.operand_count;
//
//    int* operand_values = new int[operand_count];
//
//    for (int i = 0; i < pow(2, operand_count); i++) {
//        string binary = decimal_to_binary(i, operand_count);
//
//        for (int j = 0; j < operand_count; j++) {
//            operand_values[j] = binary[j] - '0';
//        }
//
//        int result1 = calculate_postfix(postfix1, operand_values, obj.operands, operand_count);
//        int result2 = calculate_postfix(postfix2, operand_values, obj.operands, operand_count);
//
//        if (result1 != result2) {
//            delete[] operand_values;
//            return false;
//        }
//    }
//
//    delete[] operand_values;
//    return true;
//}
//string decimal_to_binary(int deci, int bits) {
//    string bin;
//    while (bits--) {
//        bin = char('0' + (deci % 2)) + bin;
//        deci /= 2;
//    }
//    return bin;
//}
//
//void display_menu() {
//   
//    cout << "\n\n\t\tWelcome to Boolean Expression Evaluator\n\n";
//    cout << "\tPress 1 to Evaluate Expressions\n";
//    cout << "\tPress 2 to show Credits\n";
//    cout << "\tPress 0 to Exit\n";
//}
//
//void display_signs() {
//    cout << "\nInstruction:\n";
//  
//    cout << "use ! for NOT operations\n";
//    cout << "use & for AND operations\n";
//    cout << "use | for OR operations\n";
//    cout << "use > for Implies operation\n";
//    cout << "use ^ for Bi-Directional\n";
//    cout << "use only () parenthesis :\n";
//}