#include<iostream>
#include<regex>
#include<string>
#include<stack>
using namespace std;
class Node {
public:
	char data;
	Node* next;
};
Node* head = NULL;
Node* tail = NULL;
class LINKSTACK {
public:
	//FOR LINKED LIST
	void Push(char element) {
		Node* temp = new Node();
		temp->data = element;
		temp->next = head;
		head = temp;
	}
	void display(Node* temphead) {
		Node* temp = new Node();
		temp = temphead;
		while (temp) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
	char pop() {
		Node* temp = new Node();
		Node* temp1 = head;
		char t = temp1->data;
		temp = head;
		head = head->next;
		delete temp;
		return t;
	}
	bool isEmpty() {
		if (head == NULL) {
			return true;
		}
		return false;
	}
	bool isFull() {
		return false;
	}
	void clear() {
		Node* temp = head;
		while (temp) {
			delete temp;
			temp = temp->next;
		}
	}
	char Peek() {
		Node* temp = new Node();
		temp = head;
		//cout << endl << "The top element of the stack is: " << temp->data;
		return temp->data;
	}
};
class ARRAYSTACK {
public:
	int arr[100];
	int max = 100;
	int index = 0;
	void push(int element) {
		if (index < max) {
			arr[index] = element;
			index++;
		}
	}
	int pop() {
		index = index - 1;
		return arr[index];
	}
	void display() {
		for (int i = index - 1; i >= 0; i--) {
			cout << arr[i] << " ";
		}
	}
	bool isEmpty() {
		if (index <= 0) {
			return true;
		}
		return false;
	}
	bool isFull() {
		if (index == max) {
			return true;
		}
		return false;
	}
	void clear() {
		for (int i = 0; i < index; i++) {
			arr[i] = 0;
		}
		delete arr;
	}
	void Peek() {
		cout << endl << arr[index - 1];
	}
	bool checking(string input) {
		int i;
		int temp;
		int ob = 0, cb = 0;
		ARRAYSTACK* as = new ARRAYSTACK();
		for (i = 0; i < input.length(); i++) {
			if (input[i] == '(' || input[i] == '{' || input[i] == '[')
			{
				ob++;
				as->push(i);
			}
			if (input[i] == ')' || input[i] == '}' || input[i] == ']') {
				cb++;
				as->pop();
			}
		}
		int temp1 = 0; 
		if (!as->isEmpty()) {
			temp1 = as->pop();
			cout << "The error is at index# " << error(input) << " ,\"" << input[error(input)] << "\" is not closed.";
		}
		if (as->isEmpty() && ob == cb) {
			return true;
		}
		else {
			return false;
		}
	}
	int error(string input) {
		int i;
		int j;
		int cond = 0;
		for (i = 0; i < input.length(); i++) {
			if (input[i] == '(') {
				cond = 0;
				for (j = i; j < input.length(); j++) {
					if (input[j] == ')') {
						cond = 1;
					}
				}
				if (cond == 0) {
					return i;
				}
			}
		}
		for (i = 0; i < input.length(); i++) {
			if (input[i] == '[') {
				cond = 0;
				for (j = i; j < input.length(); j++) {
					if (input[j] == ']') {
						cond = 1;
					}
				}
				if (cond == 0) {
					return i;
				}
			}
		}
		for (i = 0; i < input.length(); i++) {
			if (input[i] == '{') {
				cond = 0;
				for (j = i; j < input.length(); j++) {
					if (input[j] == '}') {
						cond = 1;
					}
				}
				if (cond == 0) {
					return i;
				}
			}
		}
	}
};

int main() {
	string input, answer;
	cout << "Enter the Infix notation: ";
	getline(cin, input);
	int i;
	input = regex_replace(input, regex(" "), ",");
	LINKSTACK* stack = new LINKSTACK();
	for (i = 0; i < input.length(); i++) {
		if (input[i] == '-' || input[i] == '+' || input[i] == '*' || input[i] == '/' || input[i] == '^' || input[i] == '(' || input[i] == ')' || input[i] == '{' || input[i] == '}' || input[i] == '[' || input[i] == ']') {
			if (input[i] == '+' || input[i] == '-') {
				if (head) {
					if (stack->Peek() == '-' || stack->Peek() == '+') {
						answer = answer + stack->pop();
						stack->Push(input[i]);
					}
					else {
						stack->Push(input[i]);
					}
				}
				else {
					stack->Push(input[i]);
				}
			}
			if (input[i] == '*' || input[i] == '/' || input[i] == '^') {
				if (head) {
					if (stack->Peek() == '*' || stack->Peek() == '/' || stack->Peek() == '^') {
						answer = answer + stack->pop();
						stack->Push(input[i]);
					}
					else {
						stack->Push(input[i]);
					}
				}
				else {
					stack->Push(input[i]);
				}
			}
			if (input[i] == '(') {
				if (head) {
					stack->Push(input[i]);
				}
				else {
					stack->Push(input[i]);
				}
			}
			if (input[i] == ')') {
				if (head) {
					while (stack->Peek() != '(') {
						answer = answer + stack->pop();
					}
					stack->pop();
				}
			}
			if (input[i] == '{') {
				if (head) {
					stack->Push(input[i]);
				}
				else {
					stack->Push(input[i]);
				}
			}
			if (input[i] == '}') {
				if (head) {
					while (stack->Peek() != '{') {
						answer = answer + stack->pop();
					}
					stack->pop();
				}
			}
			if (input[i] == '[') {
				if (head) {
					stack->Push(input[i]);
				}
				else {
					stack->Push(input[i]);
				}
			}
			if (input[i] == ']') {
				if (head) {
					while (stack->Peek() != '[') {
						answer = answer + stack->pop();
					}
					stack->pop();
				}
			}
		}
		else {
			answer = answer + input[i];
		}
	}
	while (!stack->isEmpty()) {
		answer = answer + stack->pop();
	}
	answer = regex_replace(answer, regex(","), " ");
	cout << endl << "ANSWER: " << answer;
    return 0;
}