#include "Board.h"

Board::Board() : m_Board_Size(3)
{
	//m_Board = std::make_shared< std::vector<std::vector<Slot>> >(3, std::vector<Slot>(3, ' '));
	m_Board = std::vector<std::vector<Slot>>(3, std::vector<Slot>(3, ' '));
}

Board::Board(int Board_size): m_Board_Size(Board_size)
{
	//m_Board = std::make_shared< std::vector<std::vector<Slot>> >(Board_size, std::vector<Slot>(Board_size,' '));
	m_Board = std::vector<std::vector<Slot>>(Board_size, std::vector<Slot>(Board_size, ' '));
}

Board::~Board()
{

}

std::vector<std::vector<Slot>>& Board::GetBoard()
{
	return m_Board;
}

int Board::GetSize() const
{
	return m_Board_Size;
}

void Board::Clean()
{
	for (int i = 0; i < m_Board_Size; i++)
	{
		for (int j = 0; j < m_Board_Size; j++)
		{
			this->m_Board[i][j].Free();
		}
	}
}

std::vector<Slot> Board::operator[](const int index) const
{
	if (index > m_Board_Size - 1 || index < 0)
	{
		std::cerr << "index ouf of range! index: " << index << std::endl;
		return m_Board[index % this->m_Board_Size];
	}
	else
	{
		return m_Board[index];
	}
}

std::vector<Slot>& Board::operator[](const int index)
{
	if (index > m_Board_Size - 1 || index < 0)
	{
		std::cerr << "index ouf of range! index: " << index << std::endl;
		return m_Board[index % this->m_Board_Size];
	}
	else
	{
		return m_Board[index];
	}
}

std::ostream& operator<<(std::ostream& stream, const Board& GBoard)
{
	//linia na gorze
	/*
	for (int i = 0; i < GBoard.GetSize(); i++)
	{
		stream << "  " << i;
	}
	stream << std::endl;
	for (int i = 0; i < GBoard.GetSize()*4; i++)
	{
		stream << "-";
	}
	stream << std::endl;
	*/
	//wszystko pomiedzy
	stream << "\n  ";
	for (int j = 0; j < GBoard.GetSize()+1; j++)
	{
		stream << j << " | ";
	}
	stream << std::endl;

	stream << "  ";
	for (int k = 0; k < GBoard.GetSize() * 4.5; k++)
	{
		stream << "-";
	}
	stream << std::endl;

	for (int i = 0; i < GBoard.GetSize(); i++)
	{
		stream << "  " << i+1;
		for (int j = 0; j < GBoard.GetSize(); j++)
		{
			stream << " | " << GBoard[i][j];
		}
		stream << " |"<< std::endl;

		stream << "  ";
		for (int k = 0; k < GBoard.GetSize() * 4.5; k++)
		{
			stream << "-";
		}
		stream << std::endl;
	}

	//linia na dole
	/*
	stream << "  ";
	for (int i = 0; i < GBoard.GetSize()*4; i++)
	{
		stream << "-";
	}
	stream << std::endl;
	*/
	return stream;
}
