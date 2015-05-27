#include <string>
#include <iostream>
#include <vector>

using namespace std;

void Interpret(string code)
{
	vector<char> type(code.size(), 0);
	char current;
	int pos = 0, count;
	for (int i = 0; i < code.size(); i++)
	{
		current = code[i];
		switch (current)
		{
		case '>' :
			pos++;
			break;
		case '<':
			pos--;
			break;
		case '+':
			type[pos]++;
			break;
		case '-':
			type[pos]--;
			break;
		case '.':
			cout << type[pos];
			break;
		case ',':
			type[pos] = getchar();
			break;
		case '[':
			if (!type[pos])
			{
				count = 1;
				while (count)
				{
					current = code[++i];
					if (current == '[')
						count++;
					if (current == ']')
						count--;
				}
			}
			break;
		case ']':
			if (type[pos])
			{
				count = 1;
				while (count)
				{
					current = code[--i];
					if (current == ']')
						count++;
					if (current == '[')
						count--;
				}
			}
			break;
		}
	}
}
int main () {
	string cont = "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.";//read_file("m.txt");
	Interpret(cont);
	system("pause");
}

  