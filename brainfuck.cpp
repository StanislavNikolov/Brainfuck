#include <iostream>
#include <set>
#include <stack>
#define MEM_MAX_SIZE 30000
#define CODE_MAX_SIZE 100000
using namespace std;

typedef unsigned int uint;
typedef unsigned char uchar;

string input;

uchar memory[MEM_MAX_SIZE];
uint bracketPairs[CODE_MAX_SIZE];
uint pointer = 0;

void preExecute(string code)
{
	stack<uint> lastOpen;
	uint codeLength = code.size();

	for(uint i = 0;i < codeLength;i ++)
	{
		if(code[i] == '[')
		{
			lastOpen.push(i);
		}
		else if(code[i] == ']')
		{
			bracketPairs[i] = lastOpen.top();
			bracketPairs[lastOpen.top()] = i;
			lastOpen.pop();
		}
	}
}

void execute(string code)
{
	uint codeLength = code.size();
	for(uint index  = 0;index < codeLength;++ index)
	{
		switch(code[index])
		{
			case '+':
				memory[pointer] ++;
				break;
			case '-':
				memory[pointer] --;
				break;
			case '>':
				pointer ++;
				break;
			case '<':
				pointer --;
				break;
			case '[':
				if(memory[pointer] == 0)
					index = bracketPairs[index];
				break;
			case ']':
				index = bracketPairs[index] - 1;
				break;
			case '.':
				cout << memory[pointer];
				break;
			case ',':
				memory[pointer] = cin.get();
				break;

		}
		//cout << code[index] << " " << index << '\n';
	}
}

int main()
{
	string input;
	cin >> input;
		
	preExecute(input);
	execute(input);
	
	cout << endl;
	return 0;
}
