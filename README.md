# Game of Life

This is a simple implementation of Conway's Game of Life.

## Story of the Game of Life

The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970. The game is a zero-player game, meaning that its evolution is determined by its initial state, requiring no further input. One interacts with the Game of Life by creating an initial configuration and observing how it evolves. It is Turing complete and can simulate a universal constructor or any other Turing machine.

The universe of the Game of Life is an infinite, two-dimensional orthogonal grid of square cells, each of which is in one of two possible states, alive or dead, (or populated and unpopulated, respectively). Every cell interacts with its eight neighbors, which are the cells that are horizontally, vertically, or diagonally adjacent.

At each step in time, the following transitions occur:

1. Any live cell with fewer than two live neighbors dies, as if by underpopulation.
2. Any live cell with two or three live neighbors lives on to the next generation.
3. Any live cell with more than three live neighbors dies, as if by overpopulation.
4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

The initial pattern constitutes the seed of the system. The first generation is created by applying the above rules simultaneously to every cell in the seed; births and deaths occur simultaneously, and the discrete moment at which this happens is sometimes called a tick. Each generation is a pure function of the preceding one. The rules continue to be applied repeatedly to create further generations.

The Game of Life can also be played on other topologies, such as toroidal ones (i.e. on a torus), finite plane, and spherical.

## Usage

These are the libraries used in the program:

- iostream
- vector
- unistd.h
- map

The program allows the user to select one of the following initial configurations:

1. **Glider**
El deslizador es un patrón que se mueve diagonalmente a través del tablero. Consiste en una configuración de cinco celdas que parece 'deslizarse' hacia abajo y hacia la derecha en el tablero con cada iteración.

2. **Small Exploder**
El Pequeño Explosivo es un patrón que 'explota' después de unas pocas iteraciones, creando un conjunto de celdas vivas a su alrededor. Aunque finalmente se estabiliza y deja de cambiar, sus 'explosiones' pueden interactuar con otros patrones cercanos y causar comportamientos interesantes.

3. **Ten Cell Row**
Este es un patrón simple que consiste en una fila de diez celdas vivas. Después de varias iteraciones, este patrón se transforma en una combinación de 'barcos', 'parpadeadores' y 'bloques'.


To run the program, simply compile and run the source code:

```bash
g++ game_of_life.cpp -o game_of_life
./game_of_life
```

## Author

- Name: Miguel Medina Cantos
- Grade: Computer engineering - 3th year
- Date: 2023/04/30
- Version: 1.0

## Revision history

- 2023/04/30 Version 1.0




