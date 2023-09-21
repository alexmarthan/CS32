
#include <iostream>

bool pathExists(char maze[][10], int sr, int sc, int er, int ec){
        
    if (sr == er && sc == ec) { return true;}

    maze[sr][sc] = 'V'; // show that that position has been visited
        
    // SOUTH
    
    if (sr < 9 && sr > -1 && sc < 10 && sc > -1){ // check for out of bounds
        if (maze[sr + 1][sc] == '.'){ // if coord to south of current position is accessible
            if (pathExists(maze, sr+1, sc, er, ec)){
                return true;
            }
        }
    }
    
    // EAST
    if (sr < 10 && sr > -1 && sc < 9 && sc > -1){ // check for out of bounds
        if (maze[sr][sc + 1] == '.'){
            if (pathExists(maze, sr, sc+1, er, ec)){
                return true;
            }
        }
    }
    
//    // NORTH
    if (sr < 10 && sr > 0 && sc < 10 && sc > -1){ // check for out of bounds
        if (maze[sr - 1][sc] == '.'){
            if (pathExists(maze, sr-1, sc, er, ec)){
                return true;
            }
        }
    }
//    // WEST
    if (sr < 10 && sr > -1 && sc < 10 && sc > 0){ // check for out of bounds
        if (maze[sr][sc-1] == '.'){
            if (pathExists(maze, sr, sc-1, er, ec)){
                return true;
            }
        }
    }
    
    return false;
}

int main()
{
    char maze[10][10] = {
        { 'X','X','X','X','X','X','X','X','X','X' },
        { 'X','.','.','.','X','.','.','.','.','X' },
        { 'X','.','.','X','X','.','X','X','.','X' },
        { 'X','.','X','.','.','.','.','X','X','X' },
        { 'X','X','X','X','.','X','X','X','.','X' },
        { 'X','.','.','X','.','.','.','X','.','X' },
        { 'X','.','.','X','.','X','.','.','.','X' },
        { 'X','X','.','X','.','X','X','X','X','X' },
        { 'X','.','.','.','.','.','.','.','.','X' },
        { 'X','X','X','X','X','X','X','X','X','X' }
    };

    if (pathExists(maze, 3,4, 8,1))
        std::cout << "Solvable!" << std::endl;
    else
        std::cout << "Out of luck!" << std::endl;
    }


