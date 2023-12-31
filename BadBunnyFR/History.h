

#ifndef HISTORY_H
#define HISTORY_H

#include <stdio.h>
#include "globals.h"

class History
    {
      public:
        History(int nRows, int nCols);
        bool record(int r, int c);
        void display() const;
                
    private:
        int rowPMV;
        int colPMV;
        int Grid[MAXROWS][MAXCOLS];
    };


#endif
