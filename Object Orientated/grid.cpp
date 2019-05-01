/*
 Name: Gregory Moncayo
 Course: COP 3330
 Assignment: Assignment # 4
 section: 03
 Due Date: 03/02/2018
 About this Project: Upon completion of this program, you should gain experience with the use of managing arrays inside of a class.
 */

#include "grid.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Default constructor that creates a 1x1 grid with the cursor facing east.

Grid:: Grid()
{
    winner = 0;
    position = 0;
    row = 1;
    column = 1;
    direction = EAST;
    mover = '>';
    button = 'O';
    exit = ' ';
}

// Constructor that creates grid with r amount of rows & c amount of columns. Cursor faces random direction.
// Border is fenced off with blocks & one exit.

Grid:: Grid(int r, int c)
{
    if (r < 3)
    {
        r = 3;
    }
    
    if (c < 3)
    {
        c = 3;
    }
    
    if (r > limit)
    {
        r = limit;
    }
    
    if (c > boundary)
    {
        c = boundary;
    }
    
    positiony = rand() % r;
    positionx = rand() % c;
    
    exit = rand() % r;
    
    if (positiony % r != 0)
    {
        exit = ' ';
    }
    
    for (int i = 0; i <= r; i++)
    {
        for (int j = 0; j <= c; j++)
        {
            if (r == r - i)
            {
                grid[i][j] = '#';
            }
            
            else if (c == c - j)
            {
                grid[i][j] = '#';
            }
            
            else if (i == r-1 && grid[i][j] != ' ')
            {
                grid[i][j] = '#';
                
            }
            
            else if (j == c-1 && grid[i][j] != ' ')
            {
                grid[i][j] = '#';
            }
            
            else if (grid[i][j] == mover && grid[i][j] == ' ')
            {
                winner = 1;
            }
            
        }
    }
    
    direction = rand() % 4;
    mover = '>';
    row = r;
    column = c;
    
    if (direction == NORTH)
    {
        mover = '^';
    }
    
    else if (direction == WEST)
    {
        mover = '<';
    }
    
    else if (direction == SOUTH)
    {
        mover = 'V';
    }
    
    else if (direction == EAST)
    {
        mover = '>';
    }
  
}

// Constructor that create grids with r amount of rows, c amount of columns, row/column position of cursor, & direction.

Grid:: Grid(int r, int c, int mr, int mc, int d)
{
    if (row > limit)
    {
        row = 1;
    }
    
    if (column > boundary)
    {
        column = 1;
    }
    
    if (mr > boundary)
    {
        mr = boundary;
    }
    
    else if (mr < 1)
    {
        mr = 1;
    }
    
    if (mc > limit)
    {
        mc = limit;
    }
    
    else if (mc < 1)
    {
        mc = 1;
    }
    
    mover = '>';
    row = r;
    column = c;
    positionx = mr;
    positiony = mc;
    direction = d;
    
    if (direction == NORTH)
    {
        mover = '^';
    }
    
    else if (direction == WEST)
    {
        mover = '<';
    }
    
    else if (direction == SOUTH)
    {
        mover = 'V';
    }
    
}

// Function that moves the cursor.

bool Grid:: Move(int s)
{
    if (s > 0)
    {
        if (direction == NORTH)
        {
            positionx = positionx - s;
            grid[positionx+s][positiony] = '.';
            
            for (int i = 0; i < s; i++)
            {
                if (grid[positionx-i][positiony] != '#')
                {
                    grid[positionx-s][positiony] = mover;
                    return true;
                }
            }
        }
        
        if (direction == SOUTH)
        {
            positionx = positionx + s;
            grid[positionx-s][positiony] = '.';
            
            for (int i = 0; i < s; i++)
            {
                if (grid[positionx+i][positiony] != '#')
                {
                    grid[positionx+s][positiony] = mover;
                    return true;
                }
            }
        }
        
        if (direction == EAST)
        {
            positiony = positiony + s;
            grid[positionx][positiony-s] = '.';
            
            for (int i = 0; i < s; i++)
            {
                if (grid[positionx][positiony+i] != '#')
                {
                    grid[positionx][positiony+s] = mover;
                    
                    return true;
                }
            }
        }
        
        if (direction == WEST)
        {
            positiony = positiony - s;
            grid[positionx][positiony+s] = '.';
            
            for (int i = 0; i < s; i++)
            {
                if (grid[positionx][positiony-i] != '#')
                {
                    grid[positionx][positiony-s] = mover;
                    return true;
                }
            }
        }
    }
    
    return false;
}

// Function that shows the "path" of the cursor.

void Grid:: TogglePath()
{
    if (button == 'O')
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (i == positionx & j == positiony)
                {
                    grid[i][j] = ' ';
                }
            }
        }
        
        button = 'F';
    }
    
    else if (button == 'F')
    {
        grid[row][column] = '.';
        button = 'O';
    }
}

// Function that turns the cursor to the left side.

void Grid:: TurnLeft()
{
    if (direction == NORTH)
    {
        direction = WEST;
        mover = '<';
    }
    
    else if (direction == WEST)
    {
        direction = SOUTH;
        mover = 'V';
    }
    
    else if (direction == SOUTH)
    {
        direction = EAST;
        mover = '>';
    }
    
    else if (direction == EAST)
    {
        direction = NORTH;
        mover = '^';
    }
}

// Function that places an item on the grid.

void Grid:: PutDown()
{
        if (grid[positionx][positiony] != '0')
        {
            grid[positionx][positiony] = '0';
        }
}

// Function that places an item on the grid at certain row location & column location

bool Grid:: PutDown(int r, int c)
{
    if (r >= 0 && r < row && c >= 0 && c < column)
    {
        grid[r][c] = '0';
        return true;
    }
    
    return false;
}

// Function that picks up the item when the cursor goes past it.

bool Grid:: PickUp()
{
    
    if (grid[positionx][positiony] == '0')
    {
        grid[positionx][positiony] = ' ';
        return true;
    }
    
    return false;
}

// Function that places blocks at a certain row location & column location.

bool Grid:: PlaceBlock(int r, int c)
{
    if (r >= 0 && r < row && c >= 0 && c < column)
    {
            grid[r][c] = '#';
            return true;
    }
    
    return false;
}

// Grows the row & column by a certain amount of numbers.

void Grid:: Grow(int gr, int gc)
{
    if (gr >= limit)
    {
        gr = limit;
    }
    
    if (gc >= boundary)
    {
        gr = boundary;
    }
    
    else
    {
        row = row+gr;
        column = column+gc;
    }
    
}

// Displays the grid.

void Grid:: Display() const
{
    cout << "The Grid: " << endl;
    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (i == positionx && j == positiony)
            {
                if (grid[i][j] == '0')
                {
                    cout << '@' << " ";
                }
                
                else
                {
                    cout << mover << " ";
                }
            }
            
            else if (grid[i][j] == '#')
            {
               cout << "#" << " ";
            }
            
            else if (grid[i][j] == '0')
            {
                cout << "0" << " ";
            }
            
            else if (grid[i][j] == '.')
            {
                 cout << '.' << " ";
            }
            
            else if (grid[i][j] == ' ')
            {
                if (button == 'O')
                {
                    cout << ' ' << " ";
                }
            }
            
            else
            {
               cout << "." << " ";
            }
            
        }
        
        cout << endl;
    }
}

// Accessors

// Checks if the front is not blocked off.

bool Grid:: FrontIsClear() const
{
    if (grid[positionx][positiony] == NORTH)
    {
        
        if (grid[positionx-1][positiony] == '#')
        {
            return true;
        }
    }
    
    if (direction == SOUTH)
    {
        if (grid[positionx+1][positiony] != '#')
        {
            return true;
        }
    }
    
    if (grid[positionx][positiony] == WEST)
    {
        if (grid[positionx][positiony-1] != '#')
        {
            return true;
        }
    }
    
    if (grid[positionx][positiony] == EAST)
    {
        if (grid[positionx][positiony+1] != '#')
        {
            return true;
        }
    }
    
    return false;
}

// checks to see if the right of the cursor is not blocked off.

bool Grid:: RightIsClear() const
{
    if (direction == NORTH)
    {
        if (grid[positionx][positiony+1] != '#')
        {
            return true;
        }
    }
    
    if (direction == SOUTH)
    {
        if (grid[positionx][positiony+1] != '#')
        {
            return true;
        }
    }
    
    if (direction == WEST)
    {
        if (grid[positionx-1][positiony] != '#')
        {
            return true;
        }
    }
    
    if (direction == EAST)
    {
        if (grid[positionx+1][positiony] != '#')
        {
            return true;
        }
    }
    
    return false;
}

// Returns the number of rows.

int Grid:: GetRow() const
{
    return row;
}

// Returns the number of columns.

int Grid:: GetCol() const
{
    return column;
}

// Returns the position of the cursor.

int Grid:: GetPosition() const
{
    return position;
}

// Returns the direction of the cursor.

int Grid:: GetDirection() const
{
    return direction;
}

// Returns the cursor.

char Grid:: ReturnMover() const
{
    return mover;
}

// Returns the row position of the cursor.

int Grid:: ReturnPositionX() const
{
    return positionx;
}

// Returns the column position of the cursor.

int Grid:: ReturnPositionY() const
{
    return positiony;
}

// Returns the grid.

char Grid:: ReturnGrid() const
{
    return grid[positionx][positiony];
}

// Returns the toggle button for ON/OFF.

char Grid:: ReturnButton() const
{
    return button;
}

// Returns the exit.

char Grid:: ReturnExit() const
{
    return exit;
}

// Returns the winner.

int Grid:: ReturnWinner() const
{
    return winner;
}
