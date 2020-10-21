// ConsoleApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

bool isPossible(int** table,int x, int y, int n) // returns if number is posssbile
{
   
    for (int i = 0; i < 9; i++)
    {
        if (table[y][i] == n)
        {
            return false;
        }
        if (table[i][x] == n)
        {
            return false;
        }
    }

    for (int i = (y / 3)*3; i < (y / 3)*3 + 3;i++)
    {
        for (int j = (x / 3)*3; j < (x / 3)*3 + 3; j++)
        {
            if (table[i][j] == n)
            {
                return false;
            }
        }
    }

    return true;
}

void displayTable(int** table) // displays the table
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            std::cout << table[i][j];
            std::cout << " ";
        }
        std::cout << "" << std::endl;
    }
}

void SudokuSolver(int** table) // solver function
{
    
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (table[i][j] == 0)
            {
                for (int n = 1; n < 10; n++)
                {
                    if (isPossible(table, j, i, n) == true)
                    {
                        table[i][j] = n;
                        SudokuSolver(table);
                        table[i][j] = 0;
                    }
                }
                return;
            }
        }
        
    }
    displayTable(table);
    std::cout << "More?" << std::endl;
    std::cin.get();
    return;       
}


int main()
{
    int** table;
    table = new int* [10];
    for (int i = 0; i < 10; i++)
    {
        table[i] = new int[10];
    }
    //test puzzle
    int puzzle[9][9] = { {5,3,0,0,7,0,0,0,0},{6,0,0,1,9,5,0,0,0},{0,9,8,0,0,0,0,6,0},{8,0,0,0,6,0,0,0,3},{4,0,0,8,0,3,0,0,1},{7,0,0,0,2,0,0,0,6},{0,6,0,0,0,0,2,8,0},{0,0,0,4,1,9,0,0,5},{0,0,0,0,8,0,0,7,9} };
    
    for (int i = 0; i < 9;i++)
    {
        for (int j = 0; j < 9;j++)
        {
            table[i][j] = puzzle[i][j];
        }
    }
    std::cout << "-----------------" << std::endl;
    displayTable(table);
    std::cout << "-----------------" << std::endl;
    SudokuSolver(table);
    
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
