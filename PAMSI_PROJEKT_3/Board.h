#pragma once
#include "Slot.h"
#include <vector>
#include <iostream>

class Board
{
private:
	int m_Board_Size;
	std::vector<std::vector<Slot>> m_Board;
public:
	Board();
	Board(int Board_size);
	~Board();
	std::vector<std::vector<Slot>>& GetBoard();
	int GetSize() const;
	void Clean();
	std::vector<Slot> operator[](const int index) const;
	std::vector<Slot>& operator[](const int index);
	friend std::ostream& operator<<(std::ostream& stream, const Board& GBoard);
};

