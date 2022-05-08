#include "../Stack/stack.h"
#include "../Stack/stack.cpp"

enum OPERATIONS{
	NOTHING,
	DELETE,
	UNDO,
	REDO
};

OPERATIONS operation = NOTHING;

template <typename T>
void Undo(Array::Stack<T>& source, Array::Stack<T>& dest) {
	
	operation = UNDO;

	T temp;

	if (dest.isEmpty()) {
		std::cout << "Buffer is empty!!" << std::endl;
		return;
	}

	dest.getTop(temp);//We get last operation from stack then we push the element what we get back to stack.
	dest.pop();
	
	std::cout << temp << " element got pushed back to stack!!" << std::endl;

	source.push(temp);
}

template <typename T>
void Redo(Array::Stack<T>& m_stack, Array::Stack<T>& buffer) {

	T temp;

	//Undo site
	if (operation == UNDO) {

		m_stack.getTop(temp);
		m_stack.pop();

		buffer.push(temp);
	}

	operation = REDO;

}

void Menu() {
	std::cout << "************* OPERATIONS **************" << std::endl;
	std::cout << "** 1.) ADD		  2.)UNDO    **" << std::endl;
	std::cout << "** 3.) DELETE		  4.)REDO    **" << std::endl;
	std::cout << "**             0.)EXIT               **" << std::endl;
	std::cout << "***************************************" << std::endl;

}

/*
* int main() {

	//Undo can be used for 3 times
	//But Redo can be used for 1 time.


	bool run = true;


	int selection = 0;
	std::string temp;

	Array::Stack<std::string> stack(5);
	Array::Stack<std::string> buffer(3);//Using for undo and redo
	

	while (run) {
		Menu();
		std::cout << "Stack elements: ";
		stack.Show();
		std::cout << "\nEnter a operation:" << std::endl;
		std::cout << "----> ";
		std::cin >> selection;


		switch (selection) {

		//Adding element to stack
		case 1:
			system("cls");
			std::cout << "Your Input: ";
			std::cin >> temp;

			stack.push(temp);

			system("cls");
			break;

		//UNDO
		case 2:
			system("cls");
			operation = UNDO;
			Undo(stack, buffer);
			break;

		//DELETING
		case 3:
			system("cls");
			stack.getTop(temp);
			stack.pop();

			std::cout << temp << " element was removed from stack!!" << std::endl;

			buffer.push(temp);

			operation = DELETE;
			break;
		
		//REDO
		case 4:
			system("cls");
			Redo(stack, buffer);
			break;
		
		//ERROR
		default:
			std::cout << "There is no operation that you chose !!" << std::endl;
			break;

		}
		
	}


	return 0;
}
*/


