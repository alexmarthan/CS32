#include <iostream>
#include <stack>


using namespace std;

class Coord
  {
    public:
      Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
      int r() const { return m_r; }
      int c() const { return m_c; }
    private:
      int m_r;
      int m_c;
  };

bool pathExists(char maze[][10], int sr, int sc, int er, int ec){
    stack<Coord> myFatStack;

    Coord begin(sr,sc);

    myFatStack.push(begin); // push the starting coord onto the stack
    maze[sr][sc] = 'E'; // show that that position has been visited

    while(!myFatStack.empty()){

        Coord current = myFatStack.top();

        myFatStack.pop();

        int r = current.r();
        int c = current.c();

        //std::cout << '(' << r << ','<< c << ')' << endl;

        if(r == er && c == ec ){ // if the top has same coords as the endcoords, a path exists
            return true;
        }

        if (r < 9 && r > -1 && c < 10 && c > -1){ // check for out of bounds
            if (maze[r + 1][c] == '.'){ // if coord to south of current position is accessible
                Coord south(r + 1,c); // create coord to the south of current position in the maze
                myFatStack.push(south); // push it onto the stack
                maze[r + 1][c] = 'F'; // mark coord as having already been visited
            }
        }

        if (r < 10 && r > -1 && c < 9 && c > -1){ // check for out of bounds
            if (maze[r][c + 1] == '.'){
                Coord east(r,c + 1);
                myFatStack.push(east); // push coord onto the stack
                maze[r][c + 1] = 'F'; // mark coord as having already been visited
            }
        }

        if (r < 10 && r > 0 && c < 10 && c > -1){ // check for out of bounds
            if (maze[r - 1][c] == '.'){
                Coord north(r - 1,c);
                myFatStack.push(north); // push coord onto the stack
                maze[r - 1][c] = 'F'; // mark coord as having already been visited
            }
        }

        if (r < 10 && r > -1 && c < 10 && c > 0){ // check for out of bounds
            if (maze[r][c - 1] == '.'){
                Coord west(r, c - 1);
                myFatStack.push(west); // push coord onto the stack
                maze[r][c - 1] = 'F'; // mark coord as having already been visited
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
                cout << "Solvable!" << endl;
            else
                cout << "Out of luck!" << endl;
        }

