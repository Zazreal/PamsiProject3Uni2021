#include "TTT_AI.h"
#include <stdlib.h>
#include <ctime>

//#include <thread>
//#include <chrono>
//#include "Timer.h"

//Normalna wersja Minimax
int minimax(Board board, int depth, bool Maxing);

//Wersja Minimax z alpha-beta cieciami
int minimaxAB(Board board, int depth, int alpha, int beta, bool Maxing);

//Nazwa
int CheckWinner(Board& board);

//Nie chcialem przekazywac tych rzeczy, byly do debugowania
//static int iterations = 0;
//static int AIiterations = 0;
//static char SOC;

TTT_AI::TTT_AI(Board& Board, char player_choice) : m_Board{ Board }
{
	if ('x' == player_choice)
	{
		m_KLK = 'o';
	}
	else
	{
		m_KLK = 'x';
	}
}

void TTT_AI::Turn(bool First)
{
	int score = 0;

	int BestMoveX = 0;
	int BestMoveY = 0;
	int BestScore;
	//Timer timer;
	//Tutaj sprawdza czy gracz wykonuje pierwszy ruch czy SI
	if (!First)
	{
		BestScore = INT_MAX;
		for (int i = 0; i < m_Board.GetSize(); i++)
		{
			for (int j = 0; j < m_Board.GetSize(); j++)
			{
				if (' ' == m_Board[i][j].data)
				{
					//AIiterations++;
					//std::cout << "AI Iterations: " << AIiterations << std::endl;
	
					m_Board[i][j].data = 'o';
					//score = minimax(m_Board,m_Board.GetSize(), false);
					score = minimaxAB(m_Board, m_Board.GetSize() ^ 2, -INT_MAX, INT_MAX, false);
					m_Board[i][j].data = ' ';
					if (score < BestScore)
					{
						//std::cout << score << std::endl;
						BestScore = score;
						BestMoveX = i;
						BestMoveY = j;
					}
				}
			}
		}
	}
	else
	{	//tutaj sie wykonuje jesli SI ma pierwszy ruch
		BestScore = -INT_MAX;
		for (int i = 0; i < m_Board.GetSize(); i++)
		{
			for (int j = 0; j < m_Board.GetSize(); j++)
			{
				if (' ' == m_Board[i][j].data)
				{
					//AIiterations++;
					//std::cout << "AI Iterations: " << AIiterations << std::endl;
	
					m_Board[i][j].data = 'x';
					//score = minimax(m_Board,m_Board.GetSize(), false);
					score = minimaxAB(m_Board, m_Board.GetSize() ^ 2, -INT_MAX, INT_MAX, true);
					m_Board[i][j].data = ' ';
					if (score > BestScore)
					{
						//std::cout << score << std::endl;
						BestScore = score;
						BestMoveX = i;
						BestMoveY = j;
					}
				}
			}
		}
	}

	//AIiterations = 0;
	//iterations = 0;
	m_Board[BestMoveX][BestMoveY].Set(m_KLK);
}

enum Scores
{
	X = 10, O = -10, Tie = 0
};

int minimax(Board board, int depth, bool Maxing)
{

	//std::this_thread::sleep_for(std::chrono::seconds(2));
	//std::cout << board;
	//char Human;
	//if (SOC == 'x') Human = 'o';
	//else if (SOC == 'o') Human = 'x';
	//else Human = ' ';

	int score = 0;
	int result = CheckWinner(board);

	//iterations++;
	//std::cout << "MINIMAX Iterations: " << iterations << std::endl;
	if (result != INT_MAX)
	{
		return result;
	}


	//std::cout << board;

	if (true == Maxing)
	{
		int MaxEval = -INT_MAX;
		for (int i = 0; i < board.GetSize(); i++)
		{
			for (int j = 0; j < board.GetSize(); j++)
			{
				if (' ' == board[i][j].data)
				{
					board[i][j].data = 'o';
					score = minimax(board, depth+1, false);
					board[i][j].data = ' ';
					MaxEval = std::max(score, MaxEval);
				}
			}
		}
		return MaxEval;
	}
	else
	{
		int MinEval = INT_MAX;
		for (int i = 0; i < board.GetSize(); i++)
		{
			for (int j = 0; j < board.GetSize(); j++)
			{
				if (' ' == board[i][j].data)
				{
					board[i][j].data = 'x';
					score = minimax(board, depth+1, true);
					board[i][j].data = ' ';
					MinEval = std::min(score, MinEval);
				}
			}
		}
		return MinEval;
	}
}
int minimaxAB(Board board, int depth,int alpha, int beta, bool Maxing)
{
	//char Human;
	//if (SOC == 'x') Human = 'o';
	//else if (SOC == 'o') Human = 'x';
	//else Human = ' ';

	int score = 0;
	int result = CheckWinner(board);


	//std::this_thread::sleep_for(std::chrono::seconds(2));
	//std::cout << board;

	if (result != INT_MAX)
	{
		//iterations++;
		//std::cout << "MINIMAX Iterations: " << iterations << "\n";
		return result;
	}


	//std::cout << board;

	if (true == Maxing)
	{
		int MaxEval = -INT_MAX;
		for (int i = 0; i < board.GetSize(); i++)
		{
			for (int j = 0; j < board.GetSize(); j++)
			{
				if (' ' == board[i][j].data)
				{
					board[i][j].data = 'o';
					score = minimaxAB(board, depth - 1, alpha, beta, false);
					board[i][j].data = ' ';
					MaxEval = std::max(score, MaxEval);
					alpha = std::max(score, alpha);
				}
				if (beta <= alpha) break;
			}
			if (beta <= alpha) break;
		}
		return MaxEval;
	}
	else
	{
		int MinEval = INT_MAX;
		for (int i = 0; i < board.GetSize(); i++)
		{
			for (int j = 0; j < board.GetSize(); j++)
			{
				if (' ' == board[i][j].data)
				{
					board[i][j].data = 'x';
					score = minimaxAB(board, depth - 1, alpha, beta, true);
					board[i][j].data = ' ';
					MinEval = std::min(score, MinEval);
					beta = std::min(score, beta);
				}
				if (beta <= alpha) break;
			}
			if (beta <= alpha) break;
		}
		return MinEval;
	}
}


int CheckWinner(Board& board)
{
	int Xscore = 0;
	int Oscore = 0;

	//Up to Down
	for (int i = 0; i < board.GetSize(); i++)
	{
		for (int j = 0; j < board.GetSize(); j++)
		{
			if (board[i][j].data == 'x') Xscore++;
			if (board[i][j].data == 'o') Oscore++;
		}
		if (Xscore == board.GetSize()) return X;
		if (Oscore == board.GetSize()) return O;
		Xscore = 0;
		Oscore = 0;
	}

	//Left To Right
	for (int i = 0; i < board.GetSize(); i++)
	{
		for (int j = 0; j < board.GetSize(); j++)
		{
			if (board[j][i].data == 'x') Xscore++;
			if (board[j][i].data == 'o') Oscore++;
		}
		if (Xscore == board.GetSize()) return X;
		if (Oscore == board.GetSize()) return O;
		Xscore = 0;
		Oscore = 0;
	}

	//Diagonal Left to Right
	for (int i = 0; i < board.GetSize(); i++)
	{

		if (board[i][i].data == 'x') Xscore++;
		if (board[i][i].data == 'o') Oscore++;
	}
	if (Xscore == board.GetSize()) return X;
	if (Oscore == board.GetSize()) return O;
	Xscore = 0;
	Oscore = 0;


	//Diagonal Right to Left
	int j = 0;
	for (int i = board.GetSize() - 1; -1 < i; i--)
	{
		if (board[i][j].data == 'x') Xscore++;
		if (board[i][j].data == 'o') Oscore++;
		j++;
	}
	if (Xscore == board.GetSize()) return X;
	if (Oscore == board.GetSize()) return O;


	int takenscore = 0;
	for (int i = 0; i < board.GetSize(); i++)
	{
		for (int j = 0; j < board.GetSize(); j++)
		{
			if (board[j][i].taken == true) takenscore++;
		}
	}
	if (takenscore == board.GetSize() * board.GetSize()) return Tie;


	return INT_MAX;
}

TTT_AI::~TTT_AI()
{
}