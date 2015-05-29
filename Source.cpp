#include <iostream>
#include <string>

using namespace std;

struct State
{
	State(int * state, string steps)
	{
		currentState = state;
		moves = steps;
		numMoves = steps.length() / 2;
		next = NULL;
	}
	void print()
	{
		cout << "Need " << numMoves << " move(s)" << endl;
		for (int i = 0; i < numMoves*2; i++)
		{
			
			if (i%2 == 1)
			{
				cout << " to peg number " << moves.at(i) << endl;
			}
			else
			{
				cout << "Disc number " << moves.at(i);
			}
		}
	}
	int numMoves;
	~State();
	string moves;
	int * currentState;
	State* next;
};

class BreadthFirst
{
public:
	BreadthFirst(string, string, string);
	~BreadthFirst();
private:
	int * finalState;
	int * initState;
	State * firstState;
	State * end;
	int numPeg;
	int numDisc;
	bool isMove(int*, int, int);
	void append();
	string getRidString(string baseString, string subString, string repString);
	State* search();
	bool isDone(State*);
};

BreadthFirst::BreadthFirst(string first, string second, string third)
{
	first = getRidString(first, " ", "");
	numDisc = first.at(0) - '0';
	numPeg = first.at(1) -'0'; 

	second = getRidString(second, " ", "");
	initState = new int[second.length()];
	for (int i = 0; i < second.length(); i++)
	{
		initState[i] = second.at(i) - '0';
	}
	firstState = new State(initState, "");

	third = getRidString(third, " ", "");
	finalState = new int[third.length()];
	for (int i = 0; i < third.length(); i++)
	{
		finalState[i] = third.at(i) - '0';
	}
	end = firstState;
	State* temp = search();
	temp->print();
}

bool BreadthFirst::isMove(int* grid, int from, int to)
{
	bool trueFalse = true;
	
	from--;
	//cout << to << " " << from << endl;
	for (int i = 0; i < from; i++)
	{
		
		if (grid[i] == grid[from] || grid[i] == to)
		{
			trueFalse = false;
			i = from;
		}
	}
	return trueFalse;
}

bool BreadthFirst::isDone(State*temp)
{
	bool trueFalse = true;
	for (int i = 0; i < numDisc; i++)
	{
		if (temp->currentState[i] != finalState[i])
		{
			trueFalse = false;
			i = numDisc;
		}
	}
	return trueFalse;
}

State* BreadthFirst::search()
{
	State * temp = firstState;
	//while (!isDone(temp))
	while (!isDone(temp))
	{
		for (int x = 1; x < numDisc + 1; x++)
		{
			for (int y = 1; y < numPeg + 1; y++)
			{
				if (y != temp->currentState[x - 1] && isMove(temp->currentState, x, y))
				{
					int* newInit = new int[numDisc];

					for (int i = 0; i < numDisc; i++)
					{
						newInit[i] = temp->currentState[i];
					}
					newInit[x-1] = y;
					string newMoves = temp->moves + to_string(x) + to_string(y);
					State* newState = new State(newInit, newMoves);
					end->next = newState;
					end = newState;
				}
			}
		}
		temp = temp->next;
	}

	return temp;
}

BreadthFirst::~BreadthFirst()
{
	State * temp = firstState;
	
	delete[] finalState;
}

string BreadthFirst::getRidString(string baseString, string subString, string repString)
{
	size_t index = 0;
	size_t preIndex = -1;
	while (preIndex != index)
	{
		preIndex = index;
		index = baseString.find(subString, index);

		if (index <= baseString.length())
		{
			baseString.replace(index, subString.length(), repString);
			//cout << index << endl;
		}
		if (index == 0)
		{
			preIndex = index;
		}
	}


	//cout << "yeah:	"<< baseString << endl;
	return baseString;
}

int main()
{
	string firstLi, secondLi, thirdLi;
	
	getline(cin, firstLi);
	getline(cin, secondLi);
	getline(cin, thirdLi);
	BreadthFirst tower(firstLi, secondLi, thirdLi);

	system("pause");
	return 0;
}