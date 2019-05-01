/*
 Name: Gregory Moncayo
 Course: COP 3330
 Assignment: Assignment # 4
 section: 03
 Due Date: 03/02/2018
 About this Project: To gain experience with the use of managing arrays inside of a class.
 */

// Grid class

const int limit = 40;
const int boundary = 40;

class Grid
{
public:
    // public static class constants, for direction indicators
    static const int NORTH = 0;
    static const int WEST = 1;
    static const int SOUTH = 2;
    static const int EAST = 3;
    
    // public member funcitons
    
    Grid();                 // build 1 x 1 grid with mover in only
                            //  square, facing east
    Grid(int r, int c);		// build grid with r rows, c cols,
                            //  blocks around edge with random exit
                            //  and random mover position and direction
    
    Grid(int r, int c, int mr, int mc, int d);
    // build empty grid with r rows, c cols, and mover
    //  at row mr, col mc, and facing direction d
    
    bool Move(int s);               // move forward s spaces, if possible
    void TogglePath();              // toggle whether or not moved path is shown
    void TurnLeft();                // turn the mover to the left
    void PutDown();                 // put down an item at the mover's position
    bool PutDown(int r, int c);     // put down an item at (r,c), if possible
    bool PickUp();                  // pick up item at current position
    bool PlaceBlock(int r, int c);	// put a block at (r,c), if possible
    void Grow(int gr, int gc);      // grow the grid by gr rows, gc columns
    
    
    void Display() const;           // display the grid on screen
    
    // Accessors
    bool FrontIsClear() const;      // check to see if space in front of
                                    //  mover is clear
    bool RightIsClear() const;      // check to see if space to right of
                                    //  mover is clear
    int GetRow() const;             // return row of the grid
    int GetCol() const;             // return column of the grid
    int GetPosition() const;        // Get the random position of the cursor
    int GetDirection() const;       // Get direction of the cursor
    char ReturnMover() const;       // Get the cursor.
    int ReturnPositionX() const;    // Get the row position of the cursor
    int ReturnPositionY() const;    // Get the column position of the cursor
    char ReturnGrid() const;        // Returns the grid.
    char ReturnButton() const;      // Returns the toggle Button for ON/OFF
    char ReturnExit() const;        // Returns random exit to escape the maze.
    int ReturnWinner() const;       // to return whether the user won.
    
private:
    int row;                    // stores the number of rows within the grid.
    int column;                // stores the number of columns within the grid.
    int position;            // stores the random position of the cursor.
    int positionx;          // stores the row position of the cursor.
    int positiony;         // stores the column position of the cursor.
    int direction;        // stores the direction of the cursor.
    char mover;          // stores the cursor.
    char grid[40][40];  // stores the grid.
    char button;       // stores the toggle ON/OFF button.
    char exit;        // stores the exit of the raandom position.
    int winner;      // determines whether one won or not.
};
