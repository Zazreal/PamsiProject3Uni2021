#include <iostream>
#include "Board.h"
#include "TTT_AI.h"
#include "TIC_TAC_TOE_GAME.h"

void Game();
void Driver();

int main()
{
    Game();
   // Driver();
    return 0;
}

void Game()
{
    int BoardSize = 0;
    char answer = 'x';
    while (true)
    {
        std::cout << "Do you want to play as 'x' or 'o'?\n";
        std::cout << "NOTICE: 'o' isnt working properly!\n";
        std::cin >> answer;
        if (answer == 'x' || 'o' == answer) break;
    }
    std::cout << "Please input the board size: ";
    std::cin >> BoardSize;
    Board GBoard(BoardSize);
    TTT_AI AI(GBoard, answer);
    TIC_TAC_TOE_GAME Game(GBoard, AI, answer);
    while (true)
    {
        Game.Play();
        std::cout << "\nPlay again?\n Y/N" << std::endl;
        std::cin >> answer;
        if ('N' == answer || 'n' == answer) break;
        std::cout << "Cleaning Board\n";
        Game.GetBoard().Clean();
    }
    std::cout << "\nTHANKS FOR PLAYING!" << std::endl;
}

void Driver()
{

    Slot slot;
    Board GBoard(2);
    TTT_AI AI(GBoard, 'x');
    TIC_TAC_TOE_GAME Game(GBoard, AI, 'x');
    std::cout << "Driver start\n\n";
    std::cout << "Slot slot;\n";
    std::cout << "Board GBoard(2);\n";
    std::cout << "TTT_AI AI(GBoard, 'x');\n";
    std::cout << "TIC_TAC_TOE_GAME Game(GBoard, AI, 'x');\n";

    std::cout << "Slot.operator<<\n";
    std::cout << slot << std::endl;
    std::cout << "Slot.set()\n";
    slot.Set('x');
    std::cout << slot << std::endl;
    std::cout << "Slot.free()\n";
    slot.Free();
    std::cout << slot << std::endl;
    std::cout << "Board.operator<<\n";
    std::cout << GBoard << std::endl;
    std::cout << "Board.GetSize()\n";
    std::cout << GBoard.GetSize() << std::endl;
    std::cout << "Board.operator[]\n";
    GBoard[0][0].Set('x');
    std::cout << GBoard[0][0] << std::endl;
    std::cout << "Board.Clean()\n";
    GBoard.Clean();
    std::cout << GBoard;
    std::cout << "Setting Board[0][0] to 'x'\n";
    GBoard[0][0].Set('x');
    GBoard[1][1].Set('o');
    std::cout << "Board.GetBoard()\n";
    auto a = GBoard.GetBoard();
    for (auto vec : a)
    {
        for (auto el : vec)
        {
            std::cout << el;
        }
        std::cout << std::endl;
    }
    
    std::cout << "TTT_AI.Turn()";
    AI.Turn(false);
    std::cout << GBoard;

    std::cout << "TIC_TAC_TOE_GAME.GetBoard()\n";
    std::cout << Game.GetBoard();
    std::cout << "Cleaning Board\n";
    Game.GetBoard().Clean();
    std::cout << "TIC_TAC_TOE_GAME.Play()\n";
    std::cout << "Please test your inputs\n";
    Game.Play();


    std::cout << "\nDriver End";
}