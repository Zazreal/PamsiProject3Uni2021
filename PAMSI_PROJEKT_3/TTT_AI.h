#pragma once
#include "Board.h"


//Tic Tac Toe AI
class TTT_AI
{
private:
	char m_KLK;
	Board& m_Board;
public:
	TTT_AI(Board& Board, char player_choice);
	void Turn(bool First);
	~TTT_AI();
};

//Normalna wersja Minimax
int minimax(Board board, int depth, bool Maxing);

//Wersja Minimax z alpha-beta cieciami
//alpha i beta na poczatku to 
int minimaxAB(Board board, int depth, int alpha, int beta, bool Maxing);

//Sprawdza na planszy czy ktos wygral
int CheckWinner(Board& board);