//**************************************************************************
//**************************************************************************
// C++ program to print the grid of Game of Life and play the game!!.
// Author:  Miguel Medina Cantos
// Grade: Computer engineering - 3th year
// Date:    2023/04/30
// Version: 1.0
// Purpose: Game of Life
//**************************************************************************
//**************************************************************************
// Revision history
// 2023/04/30 Version 1.0

// ***************************************************************************************************************************************************************************************
// This is a simple implementation of Conway's Game of Life!!!!.
// Story of the Game of Life
// The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970.
// The game is a zero-player game, meaning that its evolution is determined by its initial state, requiring no further input.
// One interacts with the Game of Life by creating an initial configuration and observing how it evolves.
// It is Turing complete and can simulate a universal constructor or any other Turing machine.
// The universe of the Game of Life is an infinite, two-dimensional orthogonal grid of square cells, each of which is in one of two possible states, alive or dead,
// (or populated and unpopulated, respectively). Every cell interacts with its eight neighbours, which are the cells that are horizontally, vertically, or diagonally adjacent.
// At each step in time, the following transitions occur:
// 1. Any live cell with fewer than two live neighbours dies, as if by underpopulation.
// 2. Any live cell with two or three live neighbours lives on to the next generation.
// 3. Any live cell with more than three live neighbours dies, as if by overpopulation.
// 4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
// The initial pattern constitutes the seed of the system. The first generation is created by applying the above rules simultaneously to every cell in the seed;
// births and deaths occur simultaneously, and the discrete moment at which this happens is sometimes called a tick.
// Each generation is a pure function of the preceding one. The rules continue to be applied repeatedly to create further generations.
// The Game of Life can also be played on other topologies, such as toroidal ones (i.e. on a torus), finite plane, and spherical.
// **************************************************************************************************************************************************************************************


//These are the libraries used in the program
#include <iostream>
#include <vector>
#include <unistd.h>
#include <map>

//These are the namespaces used in the program
using namespace std;



// Grid dimensions. You can change these values to play with bigger grids.
const int HEIGHT = 20;
const int WIDTH = 40;

// Prints the grid to the console.
// in the function is use std::vector to create a vector of vectors of bools
// because the grid is a 2D array of bools.

void printGrid(const std::vector<std::vector<bool>> &grid)
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            std::cout << (grid[i][j] ? '*' : ' ');
        }
        std::cout << '\n';
    }
}

// Counts the number of live neighbors of a cell.
int countLiveNeighbors(const std::vector<std::vector<bool>> &grid, int x, int y)
{
    // The eight possible directions.
    // (dx[i], dy[i]) is the i-th direction.
    // For example, (dx[0], dy[0]) = (-1, -1) is the top-left direction.
    // (dx[1], dy[1]) = (-1, 0) is the top direction.
    // (dx[2], dy[2]) = (-1, 1) is the top-right direction.
    // ...
    // (dx[7], dy[7]) = (1, 1) is the bottom-right direction.
    // -1 means moving left or up.
    // 0 means not moving left/right or up/down.
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int count = 0;

    for (int i = 0; i < 8; i++)
    {
        //newX and newY are the coordinates of the neighbor.
        int newX = x + dx[i], newY = y + dy[i];

        // Check if the neighbor is within the grid.
        if (newX >= 0 && newX < HEIGHT && newY >= 0 && newY < WIDTH && grid[newX][newY])
        {
            count++;
        }
    }

    return count;
}

// Returns the next state of the grid.
std::vector<std::vector<bool>> getNextState(const std::vector<std::vector<bool>> &currentGrid)
{
    // Initialize the new grid with all cells dead.
    std::vector<std::vector<bool>> newGrid(HEIGHT, std::vector<bool>(WIDTH, false));

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            int liveNeighbors = countLiveNeighbors(currentGrid, i, j);

            if (currentGrid[i][j] && (liveNeighbors == 2 || liveNeighbors == 3))
            {
                newGrid[i][j] = true;
            }
            else if (!currentGrid[i][j] && liveNeighbors == 3)
            {
                newGrid[i][j] = true;
            }
        }
    }

    return newGrid;
}



void initializeGlider(std::vector<std::vector<bool>> &grid)
{
    grid[1][2] = true;
    grid[2][3] = true;
    grid[3][1] = true;
    grid[3][2] = true;
    grid[3][3] = true;
}

void initializeSmallExploder(std::vector<std::vector<bool>> &grid)
{
    grid[8][15] = true;
    grid[9][14] = true;
    grid[9][15] = true;
    grid[9][16] = true;
    grid[10][14] = true;
    grid[10][16] = true;
    grid[11][15] = true;
}

void initializeTenCellRow(std::vector<std::vector<bool>> &grid)
{
    for (int i = 10; i < 20; i++)
    {
        grid[10][i] = true;
    }
}

int main()
{
    std::vector<std::vector<bool>> grid(HEIGHT, std::vector<bool>(WIDTH, false));

    std::map<int, std::pair<std::string, std::string>> configurations = {
        {1, {"Glider", "El deslizador es un patrón que se mueve diagonalmente a través del tablero. Consiste en una configuración de cinco celdas que parece 'deslizarse' hacia abajo y hacia la derecha en el tablero con cada iteración."}},
        {2, {"Small Exploder", "El Pequeño Explosivo es un patrón que 'explota' después de unas pocas iteraciones, creando un conjunto de celdas vivas a su alrededor. Aunque finalmente se estabiliza y deja de cambiar, sus 'explosiones' pueden interactuar con otros patrones cercanos y causar comportamientos interesantes."}},
        {3, {"Ten Cell Row", "Este es un patrón simple que consiste en una fila de diez celdas vivas. Después de varias iteraciones, este patrón se transforma en una combinación de 'barcos', 'parpadeadores' y 'bloques'."}}
    
    };

    printf("Bienvenido al juego de la vida de Conway\n");
    printf("Seleccione una configuración inicial:\n");
    printf("\n");

    for (const auto &config : configurations)
    {
        std::cout << config.first << ". " << config.second.first << ": " << config.second.second << '\n';
        printf("\n");
    }

    printf("\n");
    int choice;
    std::cin >> choice;

    while (configurations.find(choice) == configurations.end())
    {
        std::cout << "Invalid choice. Please try again.\n";
        std::cin >> choice;
    }

    switch (choice)
    {
    case 1:
        initializeGlider(grid);
        break;
    case 2:
        initializeSmallExploder(grid);
        break;
    case 3:
        initializeTenCellRow(grid);
        break;
    default:
        std::cout << "Invalid configuration.\n";
        return 1;
    }

    while (true)
    {
        printGrid(grid);
        grid = getNextState(grid);
        usleep(100000); // Sleep for 100 ms.
    }

    return 0;
}
