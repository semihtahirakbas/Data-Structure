#include "stack.h"
#include "stack.cpp"

int prec(char operand) {

	if (operand == '^') return 3;

	else if (operand == '*' || operand == '/') return 2;

	else if (operand == '+' || operand == '-') return 1;

	//Otherwise there is no operation that is defined!
	return -1;

}

void InfixToPostfix(std::string s) {
	char ex;
	Array::Stack<char> st(s.length() + 1);

	std::string result;

	for (int i = 0; i < s.length(); i++) {
		char c = s[i]; //Divide it to pieces to check.
		//std::cout << c << std::endl;

		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
			result += c;

		}

		else if (c == '(') {
			ex = '(';
			st.push(ex);
		}

		else if (c == ')') {
			
			while (st.topValue() != '(') {
				result += st.topValue(); //Adding elements in parantheses to result.
				st.pop(); // Then popping elements to stack
			}

			//std::cout << st.topValue() << std::endl;
			st.pop(); //removing '(' in stack.
		}

		else {
			
			while (!st.isEmpty() && prec(s[i]) <= prec(st.topValue())) { //Checks precedence. if current precedence lower than current string character, it'll keep executing until matching '^' operand.
				if (c == '^' && st.topValue() == '^')
					break;

				else {
					result += st.topValue();
					st.pop();
				}
			}
			st.push(c);
		}

	}
	char temp;

	while (!st.isEmpty()) {
		result += st.topValue();
		st.pop();
	}

	std::cout << result << std::endl;

}

	

int main() {

	std::string exp = "a+b*(c^d-e)^(f+g*h)-i";
	std::cout << "Input: " << exp << std::endl;
	InfixToPostfix(exp);
	return 0;
}