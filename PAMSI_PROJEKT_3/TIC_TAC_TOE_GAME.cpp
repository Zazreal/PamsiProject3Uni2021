#include "TIC_TAC_TOE_GAME.h"
#include<random>

int TIC_TAC_TOE_GAME::ScanBoard()
{
	int p_score = 0;
	int AI_score = 0;

	//Up to Down
	for (int i = 0; i < m_Board.GetSize(); i++)
	{
		for (int j = 0; j < m_Board.GetSize(); j++)
		{
			if (m_Board[i][j].data == m_player_choice) p_score++;
			if (m_Board[i][j].data == AI_Icon) AI_score++;
		}
		if (p_score == m_Board.GetSize())
		{
			std::cout << "YOU WIN!" << std::endl;
			return 1;
		}
		if (AI_score == m_Board.GetSize())
		{
			std::cout << "YOU LOSE!" << std::endl;
			return -1;
		}
		p_score = 0;
		AI_score = 0;
	}

	//Left To Right
	for (int i = 0; i < m_Board.GetSize(); i++)
	{
		for (int j = 0; j < m_Board.GetSize(); j++)
		{
			if (m_Board[j][i].data == m_player_choice) p_score++;
			if (m_Board[j][i].data == AI_Icon) AI_score++;
		}
		if (p_score == m_Board.GetSize())
		{
			std::cout << "YOU WIN!" << std::endl;
			return true;
		}
		if (AI_score == m_Board.GetSize())
		{
			std::cout << "YOU LOSE!" << std::endl;
			return true;
		}
		p_score = 0;
		AI_score = 0;
	}

	//Diagonal Left to Right
	for (int i = 0; i < m_Board.GetSize(); i++)
	{

		if (m_Board[i][i].data == m_player_choice) p_score++;
		if (m_Board[i][i].data == AI_Icon) AI_score++;
	}
	if (p_score == m_Board.GetSize())
	{
		std::cout << "YOU WIN!" << std::endl;
		return true;
	}
	if (AI_score == m_Board.GetSize())
	{
		std::cout << "YOU LOSE!" << std::endl;
		return true;
	}

	p_score = 0;
	AI_score = 0;
	//Diagonal Right to Left
	int j = 0;
	for (int i = m_Board.GetSize()-1; -1 < i ; i--)
	{
		if (m_Board[i][j].data == m_player_choice) p_score++;
		if (m_Board[i][j].data == AI_Icon) AI_score++;
		j++;
	}
	if (p_score == m_Board.GetSize())
	{
		std::cout << "YOU WIN!" << std::endl;
		return 1;
	}
	else if (AI_score == m_Board.GetSize())
	{
		std::cout << "YOU LOSE!" << std::endl;
		return -1;
	}

	//Tie
	int takenscore = 0;
	for (int i = 0; i < m_Board.GetSize(); i++)
	{
		for (int j = 0; j < m_Board.GetSize(); j++)
		{
			if (m_Board[j][i].taken == true) takenscore++;
		}
	}
	if (takenscore == m_Board.GetSize() * m_Board.GetSize())
	{
		std::cout << "You Tied!" << std::endl;
		return 0;
	}

	return -10;
}


TIC_TAC_TOE_GAME::TIC_TAC_TOE_GAME(Board& Board, TTT_AI AI, char P_C) : m_AI(AI), m_Board(Board), m_player_choice(P_C)
{
	if (m_player_choice == 'x') AI_Icon = 'o';
	else if (m_player_choice == 'o') AI_Icon = 'x';
	else AI_Icon = ' ';
}

void TIC_TAC_TOE_GAME::Play()
{
	int coord_x = 0;
	int coord_y = 0;
	bool First = false;
	std::cout << "\nYou start with: " << m_player_choice << std::endl;
	std::cout << m_Board << std::endl;
	if ('o' == m_player_choice)
	{
		std::random_device rd; // obtain a random number from hardware
		std::mt19937 gen(rd()); // seed the generator
		std::uniform_int_distribution<> distr(0, m_Board.GetSize() - 1); // define the range

		First = true;
		std::cout << "AI's Turn!\n";
		m_Board[distr(gen) % m_Board.GetSize()][distr(gen) % m_Board.GetSize()].Set('x');
		std::cout << m_Board << std::endl;
	}
	while (true)
	{

		std::cout << "Your Turn!\n";
		std::cout << "Enter the X and Y coordinates\n";
		std::cin >> coord_x >> coord_y;
		//Zabezpieczenia przeciwko idiotom
		if (coord_x > m_Board.GetSize() || coord_x < 0)
		{
			std::cout << "Please Enter different coordinates, those are incorrect\n";
			std::cin >> coord_x >> coord_y;
		}
		if (coord_y > m_Board.GetSize() || coord_y < 0)
		{
			std::cout << "Please Enter different coordinates, those are incorrect\n";
			std::cin >> coord_x >> coord_y;
		}
		while (m_Board[coord_y - 1][coord_x - 1].taken == true)
		{
			std::cout << "Please Enter different coordinates, those are taken\n";
			std::cin >> coord_x >> coord_y;
			if (coord_x > m_Board.GetSize() || coord_x < 0) continue;
			if (coord_y > m_Board.GetSize() || coord_y < 0) continue;
		}

		m_Board[(coord_y-1)][(coord_x-1)].Set(m_player_choice);

		std::cout << m_Board << std::endl;

		if (-10 != ScanBoard())
		{
			break;
		}
		
		std::cout << "AI's Turn!\n";
		m_AI.Turn(First);

		std::cout << m_Board << std::endl;
		if (-10 != ScanBoard())
		{
			break;
		}
		
	}

}

Board& TIC_TAC_TOE_GAME::GetBoard()
{
	return this->m_Board;
}
