#include "../Stack/stack.h"
#include "../Stack/stack.cpp"


double evaluatePosfix(char* exp) {
	Linked::Stack<double> stack;
	double result;
	int i;

	for (i = 0; exp[i]; ++i) {

		if (exp[i] == ' ') continue;


		else if (isdigit(exp[i])) {
			int num = 0;

			while (isdigit(exp[i])) {
				num = num * 10 + (int)(exp[i] - '0');
				i++;
			}
			i--;

			stack.push(num);
		}

		else {
			double val1, val2;
			stack.getTop(val2);
			stack.pop();
			stack.getTop(val1);
			stack.pop();

			std::cout << val1 << " " << exp[i] << " " << val2 << std::endl;

			switch (exp[i]) {
			case '+': stack.push(val1 + val2); break;
			case '-': stack.push(val1 - val2); break;
			case '*': stack.push(val1 * val2); break;
			case '/': stack.push(val1 / val2); break;

			}
		}

	}

	stack.getTop(result);

	return result;

}

/*
int main() {

	std::string input;
	char exp[32];

	std::cout << "Enter a calculation: ";
	std::cin.getline(exp, 32);
	std::cout << exp << std::endl;



	std::cout << evaluatePosfix(exp);

}

*/



