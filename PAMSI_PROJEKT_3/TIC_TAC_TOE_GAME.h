#pragma once

#include "Board.h"
#include "TTT_AI.h"

class TIC_TAC_TOE_GAME
{
private:
	Board& m_Board;
	TTT_AI m_AI;
	char m_player_choice;
	char AI_Icon;

	int ScanBoard();
public:
	TIC_TAC_TOE_GAME(Board& Board, TTT_AI AI, char P_C);
	void Play();
	Board& GetBoard();
	~TIC_TAC_TOE_GAME() {};
};

