#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef char gameBoard[10][10];

void get_board_data(ifstream&, gameBoard player1, gameBoard player2);
void fire(gameBoard, int&, bool&);
void print_board(gameBoard);
bool winner_test(int, int);

// im retarded on main too
int main()
{
	ifstream mydata;
	bool end_game = false;
	gameBoard player1, player2;
	get_board_data(mydata, player1, player2);
	for (int i = 0; i < 23; i++)
	{
		for (int k = 0; k < 23; k++)
		{

			do {
				cout << "Player1 hits: " << i << " Player 2 hits: " << k << endl;
				cout << "Player1 - Enter your move (ie. 0 4):";
				fire(player2, i, end_game);
				cout << "Player1 hits: " << i << " Player 2 hits: " << k << endl;
				cout << "Player2 - Enter your move (ie. 0 4):";
				fire(player1, k, end_game);
			} while (winner_test(i, k) != end_game);
		}
	}
	cout << "Thanks for playing Battleship" << endl;
	cout << "Player 1's Board" << endl;
	print_board(player1);
	cout << endl;
	cout << "Player 2's Board" << endl;
	print_board(player2);
	system("pause");
	return 0;
}

// i dont really understand the logic for this 
void fire(gameBoard player, int& no_hits, bool& end_game)
{
	{
		int move1, move2;
		cin >> move1 >> move2;
		player[move1][move2];
		if (move1 && move2 == 10)
		{
			cout << "Thanks for playing Batlleship" << endl;
			end_game = false;
		}
		else if (player[move1][move2] == '#')
		{
			cout << "hit" << endl;
			cout << player[move1][move2];
			player[move1][move2] = 'H';
			no_hits++;
		}
		else
		{
			cout << "miss" << endl;
			no_hits++;
		}
	}
}

bool winner_test(int no_hits_player_1, int no_hits_player_2)
{
	if (no_hits_player_1 == 23 || no_hits_player_2 == 23)
	{
		cout << "game has ended" << endl;
		cout << "Thanks for playing Batlleship" << endl;
		return false;
	}
	return true;
}

void get_board_data(ifstream& thedata, gameBoard player1, gameBoard player2)
{
	string player, playernum, game, board;
	string _player, _playernum, _game, _board;
	thedata.open("infile.txt");
	int NumCols = 10, NumRows = 10;
	thedata >> player >> playernum >> game >> board;
	cout << player << playernum << game << board << endl;
	for (int i = 0; i < NumCols; i++)
	{
		for (int j = 0; j < NumRows; j++)
		{
			thedata >> player1[i][j];
			cout << player1[i][j];
		}
		cout << endl;
	}
	thedata >> _player >> _playernum >> _game >> _board;
	cout << _player << _playernum << _game << _board << endl;
	for (int k = 0; k < NumCols; k++)
	{
		for (int l = 0; l < NumRows; l++)
		{
			thedata >> player2[k][l];
			cout << player2[k][l];
		}
		cout << endl;
	}
	thedata.close();
}

void print_board(gameBoard playerboard)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << playerboard[i][j];
		}
		cout << endl;
	}
}