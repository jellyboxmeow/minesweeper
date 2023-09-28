#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

struct user_input{
    char letter;
    int num;
    bool hitBomb = 0;
};

struct board{
    char letterPos = 'A';
    int numPos = 0;
    string dispLetter = "X";
    bool isBomb = 0; 
    int bAround;
    bool checkedAlready = 0;
};

board initalBoardE[5][5];
board initalBoardN[10][10];
board initalBoardH[20][20];
int howManyBombs = 0;

int bombsAround(int y, int x, int identity);

void setBoardE(){
    for(int i = 0; i < 5; i++){
        board temp;
        temp.numPos = 1 + i;
        for(int j = 0; j < 5; j++){
            temp.letterPos = 'A' + j;
            double randomValue = (rand()%25)+1;
            if(randomValue/25 <= .24){
                temp.isBomb = true;
                howManyBombs++;
            }
            initalBoardE[i][j] = temp;
            temp.isBomb = 0;
        }
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            initalBoardE[i][j].bAround = bombsAround(i,j,1);
        }
    }
}

void setBoardN(){
    for(int i = 0; i < 10; i++){
        board temp;
        temp.numPos = 1 + i;
        for(int j = 0; j < 10; j++){
            temp.letterPos = 'A' + j;
            double randomValue = (rand()%25)+1;
            if(randomValue/25 <= .4){
                temp.isBomb = true;
                howManyBombs++;
            }
            initalBoardN[i][j] = temp;
            temp.isBomb = 0;
        }
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            initalBoardN[i][j].bAround = bombsAround(i,j,2);
        }
    }
}

/* void setBoardH(){
    for(int i = 0; i < 26; i++){
        board temp;
        temp.numPos = 1 + i;
        for(int j = 0; j < 26; j++){
            temp.letterPos = 'A' + j;
            double randomValue = (rand()%25)+1;
            if(randomValue/25 <= .5){
                temp.isBomb = true;
            }
            initalBoardH[i][j] = temp;
            temp.isBomb = 0;
        }
    }
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 26; j++){
            initalBoardH[i][j].bAround = bombsAround(i,j,3);
        }
    }
}  */

void dispBoardE(){
    cout << "   ";
    for(int num = 0; num < 5; num++){
        char tempChar = 'A' + num;
        cout << tempChar << " ";
    }
    cout << endl;
    for(int i = 0; i < 5; i++){
        int tempNum = i+1;
        cout << tempNum << "  ";

        for(int j = 0; j < 5; j++){
            cout << /*initalBoardE[i][j].bAround << */initalBoardE[i][j].dispLetter /*<< initalBoardE[i][j].isBomb*/ << " ";
        }
        cout << endl;
    }
}

void dispBoardN(){
    cout << "    ";
    for(int num = 0; num < 10; num++){
        char tempChar = 'A' + num;
        cout << tempChar << " ";
    }
    cout << endl << endl;
    for(int i = 0; i < 10; i++){
        int tempNum = i+1;
        if(tempNum < 10) cout << tempNum << "   ";
        else cout << tempNum << "  ";
        for(int j = 0; j < 10; j++){
            cout << /*initalBoardN[i][j].bAround <<*/ initalBoardN[i][j].dispLetter << /*initalBoardN[i][j].isBomb <<*/ " ";
        }
        cout << endl;
    }
}


/* void dispBoardH(){
    cout << "    ";
    for(int num = 0; num < 26; num++){
        char tempChar = 'A' + num;
        cout << tempChar << " ";
    }
    cout << endl << endl;
    for(int i = 0; i < 26; i++){
        int tempNum = i+1;
        if(tempNum < 26) cout << tempNum << "   ";
        else cout << tempNum << "  ";
        for(int j = 0; j < 26; j++){
            cout << initalBoardH[i][j].dispLetter << " ";
        }
        cout << endl;
    }
}

 */

int bombsAround(int y, int x, int identity){
    int bombs = 0;
    if(identity == 1){
        if(y == 0){ //checks the first row 
            if(initalBoardE[y+1][x].isBomb){ //checks the position to the Bottom
                bombs++;
            }
            if(x == 0){
                if(initalBoardE[y][x+1].isBomb){ //checks the position to the right
                    bombs++;
                }
                if(initalBoardE[y+1][x+1].isBomb){ //checks the position to the Bottom-right
                    bombs++;
                }
            }
            else if(x == 4){
                if(initalBoardE[y][x-1].isBomb){ //checks the position to the left
                    bombs++;
                }
                if(initalBoardE[y+1][x-1].isBomb){ //checks the position to the Bottom-left
                    bombs++;
                }
            }
            else{
                if(initalBoardE[y][x+1].isBomb){ //checks the position to the right
                    bombs++;
                }
                if(initalBoardE[y+1][x+1].isBomb){ //checks the position to the Bottom-right
                    bombs++;
                }
                if(initalBoardE[y][x-1].isBomb){ //checks the position to the left
                    bombs++;
                }
                if(initalBoardE[y+1][x-1].isBomb){ //checks the position to the Bottom-left
                    bombs++;
                }
            }
        }
        
        if(y == 4){ //checks the last row 
            if(initalBoardE[y-1][x].isBomb){ //checks the position to the Up
                bombs++;
            }
            if(x == 0){
                if(initalBoardE[y][x+1].isBomb){ //checks the position to the right
                    bombs++;
                }
                if(initalBoardE[y-1][x+1].isBomb){ //checks the position to the Up-right
                    bombs++;
                }
            }
            else if(x == 4){
                if(initalBoardE[y][x-1].isBomb){ //checks the position to the left
                    bombs++;
                }
                if(initalBoardE[y-1][x-1].isBomb){ //checks the position to the Up-left
                    bombs++;
                }
            }
            else{
                if(initalBoardE[y][x+1].isBomb){ //checks the position to the right
                    bombs++;
                }
                if(initalBoardE[y-1][x+1].isBomb){ //checks the position to the Up-right
                    bombs++;
                }
                if(initalBoardE[y][x-1].isBomb){ //checks the position to the left
                    bombs++;
                }
                if(initalBoardE[y-1][x-1].isBomb){ //checks the position to the Up-left
                    bombs++;
                }
            }
        }

        if(x == 0){ //checks the first column excluding first row and last row
            if(y != 0 && y != 4){
                /* Checks the 5 to the right
                X X
                S X
                X X
                */
                for(int k = -1; k <= 1; k++){
                    for(int l = 0; l <= 1; l++){
                        if(k == 0 && l == 0){
                            continue;
                        }
                        else{
                            if(initalBoardE[y+k][x+l].isBomb) bombs++;
                            else continue;
                        }
                    }
                }
            }
        }

        if(x == 4){ //checks the first column excluding first row and last row
            if(y != 0 && y != 4){
                /* Checks the 5 to the left
                X X
                X S
                X X 
                */
                for(int k = -1; k <= 1; k++){
                    for(int l = -1; l <= 0; l++){
                        if(k == 0 && l == 0){
                            continue;
                        }
                        else{
                            if(initalBoardE[y+k][x+l].isBomb) bombs++;
                            else continue;
                        }
                    }
                }
            }
            
        }

        if(y != 0 && y != 4 && x != 0 && x != 4){ // checks the 8 squares around
            for(int k = -1; k <= 1; k++){
                for(int l = -1; l <= 1; l++){
                    if(k == 0 && l == 0){
                        continue;
                    }
                    else{
                        if(initalBoardE[y+k][x+l].isBomb) bombs++;
                        else continue;
                    }
                }
            }
        }

    }
    if(identity == 2){
        if(y == 0){ //checks the first row 
            if(initalBoardN[y+1][x].isBomb){ //checks the position to the Bottom
                bombs++;
            }
            if(x == 0){
                if(initalBoardN[y][x+1].isBomb){ //checks the position to the right
                    bombs++;
                }
                if(initalBoardN[y+1][x+1].isBomb){ //checks the position to the Bottom-right
                    bombs++;
                }
            }
            else if(x == 9){
                if(initalBoardN[y][x-1].isBomb){ //checks the position to the left
                    bombs++;
                }
                if(initalBoardN[y+1][x-1].isBomb){ //checks the position to the Bottom-left
                    bombs++;
                }
            }
            else{
                if(initalBoardN[y][x+1].isBomb){ //checks the position to the right
                    bombs++;
                }
                if(initalBoardN[y+1][x+1].isBomb){ //checks the position to the Bottom-right
                    bombs++;
                }
                if(initalBoardN[y][x-1].isBomb){ //checks the position to the left
                    bombs++;
                }
                if(initalBoardN[y+1][x-1].isBomb){ //checks the position to the Bottom-left
                    bombs++;
                }
            }
        }
        
        if(y == 9){ //checks the last row 
            if(initalBoardN[y-1][x].isBomb){ //checks the position to the Up
                bombs++;
            }
            if(x == 0){
                if(initalBoardN[y][x+1].isBomb){ //checks the position to the right
                    bombs++;
                }
                if(initalBoardN[y-1][x+1].isBomb){ //checks the position to the Up-right
                    bombs++;
                }
            }
            else if(x == 9){
                if(initalBoardN[y][x-1].isBomb){ //checks the position to the left
                    bombs++;
                }
                if(initalBoardN[y-1][x-1].isBomb){ //checks the position to the Up-left
                    bombs++;
                }
            }
            else{
                if(initalBoardN[y][x+1].isBomb){ //checks the position to the right
                    bombs++;
                }
                if(initalBoardN[y-1][x+1].isBomb){ //checks the position to the Up-right
                    bombs++;
                }
                if(initalBoardN[y][x-1].isBomb){ //checks the position to the left
                    bombs++;
                }
                if(initalBoardN[y-1][x-1].isBomb){ //checks the position to the Up-left
                    bombs++;
                }
            }
        }

        if(x == 0){ //checks the first column excluding first row and last row
            if(y != 0 && y != 9){
                /* Checks the 5 to the right
                X X
                S X
                X X
                */
                for(int k = -1; k <= 1; k++){
                    for(int l = 0; l <= 1; l++){
                        if(k == 0 && l == 0){
                            continue;
                        }
                        else{
                            if(initalBoardN[y+k][x+l].isBomb) bombs++;
                            else continue;
                        }
                    }
                }
            }
        }

        if(x == 9){ //checks the first column excluding first row and last row
            if(y != 0 && y != 9){
                /* Checks the 5 to the left
                X X
                X S
                X X 
                */
                for(int k = -1; k <= 1; k++){
                    for(int l = -1; l <= 0; l++){
                        if(k == 0 && l == 0){
                            continue;
                        }
                        else{
                            if(initalBoardN[y+k][x+l].isBomb) bombs++;
                            else continue;
                        }
                    }
                }
            }
            
        }

        if(y != 0 && y != 9 && x != 0 && x != 9){ // checks the 8 squares around
            for(int k = -1; k <= 1; k++){
                for(int l = -1; l <= 1; l++){
                    if(k == 0 && l == 0){
                        continue;
                    }
                    else{
                        if(initalBoardN[y+k][x+l].isBomb) bombs++;
                        else continue;
                    }
                }
            }
        }

    }
    if(identity == 3){ // checks the hard board
        if(y == 0){ //checks the first row 
            if(initalBoardH[y+1][x].isBomb){ //checks the position to the Bottom
                bombs++;
            }
            if(x == 0){
                if(initalBoardH[y][x+1].isBomb){ //checks the position to the right
                    bombs++;
                }
                if(initalBoardH[y+1][x+1].isBomb){ //checks the position to the Bottom-right
                    bombs++;
                }
            }
            else if(x == 25){
                if(initalBoardH[y][x-1].isBomb){ //checks the position to the left
                    bombs++;
                }
                if(initalBoardH[y+1][x-1].isBomb){ //checks the position to the Bottom-left
                    bombs++;
                }
            }
            else{
                if(initalBoardH[y][x+1].isBomb){ //checks the position to the right
                    bombs++;
                }
                if(initalBoardH[y+1][x+1].isBomb){ //checks the position to the Bottom-right
                    bombs++;
                }
                if(initalBoardH[y][x-1].isBomb){ //checks the position to the left
                    bombs++;
                }
                if(initalBoardH[y+1][x-1].isBomb){ //checks the position to the Bottom-left
                    bombs++;
                }
            }
        }
        
        if(y == 25){ //checks the last row 
            if(initalBoardH[y-1][x].isBomb){ //checks the position to the Up
                bombs++;
            }
            if(x == 0){
                if(initalBoardH[y][x+1].isBomb){ //checks the position to the right
                    bombs++;
                }
                if(initalBoardH[y-1][x+1].isBomb){ //checks the position to the Up-right
                    bombs++;
                }
            }
            else if(x == 25){
                if(initalBoardH[y][x-1].isBomb){ //checks the position to the left
                    bombs++;
                }
                if(initalBoardH[y-1][x-1].isBomb){ //checks the position to the Up-left
                    bombs++;
                }
            }
            else{
                if(initalBoardH[y][x+1].isBomb){ //checks the position to the right
                    bombs++;
                }
                if(initalBoardH[y-1][x+1].isBomb){ //checks the position to the Up-right
                    bombs++;
                }
                if(initalBoardH[y][x-1].isBomb){ //checks the position to the left
                    bombs++;
                }
                if(initalBoardH[y-1][x-1].isBomb){ //checks the position to the Up-left
                    bombs++;
                }
            }
        }

        if(x == 0){ //checks the first column excluding first row and last row
            if(y != 0 && y != 25){
                /* Checks the 5 to the right
                X X
                S X
                X X
                */
                for(int k = -1; k <= 1; k++){
                    for(int l = 0; l <= 1; l++){
                        if(k == 0 && l == 0){
                            continue;
                        }
                        else{
                            if(initalBoardN[y+k][x+l].isBomb) bombs++;
                            else continue;
                        }
                    }
                }
            }
        }

        if(x == 25){ //checks the first column excluding first row and last row
            if(y != 0 && y != 25){
                /* Checks the 5 to the left
                X X
                X S
                X X 
                */
                for(int k = -1; k <= 1; k++){
                    for(int l = -1; l <= 0; l++){
                        if(k == 0 && l == 0){
                            continue;
                        }
                        else{
                            if(initalBoardH[y+k][x+l].isBomb) bombs++;
                            else continue;
                        }
                    }
                }
            }
            
        }

        if(y != 0 && y != 25 && x != 0 && x != 25){ // checks the 8 squares around
            for(int k = -1; k <= 1; k++){
                for(int l = -1; l <= 1; l++){
                    if(k == 0 && l == 0){
                        continue;
                    }
                    else{
                        if(initalBoardH[y+k][x+l].isBomb) bombs++;
                        else continue;
                    }
                }
            }
        }

    }

    return bombs;
}

void checkBombE(char userLetter, int userPos, bool* userBomb){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(userLetter == initalBoardE[i][j].letterPos && userPos == initalBoardE[i][j].numPos && !initalBoardE[i][j].checkedAlready){
                if(initalBoardE[i][j].isBomb){
                    *userBomb = 1;
                    cout << "You hit a bomb! :(\n";
                }
                else{
                    initalBoardE[i][j].dispLetter = bombsAround(i, j, 1) + 48;
                    if(initalBoardE[i][j].bAround == 0 || initalBoardE[i][j].bAround == 1){
                        if(i != 0 && i != 4 && j != 0 && j != 4){ // makes sure the userinput isn't on the edge
                            for(int k = -1; k <= 1; k++){
                                for(int l = -1; l <= 1; l++){
                                    if(k == 0 && l == 0){
                                        continue;
                                    }
                                    else{
                                        if(initalBoardE[i+k][j+l].isBomb) {continue;}
                                        else {
                                                initalBoardE[i+k][j+l].dispLetter = bombsAround(i+k, j+l, 1) + 48;
                                                initalBoardE[i+k][j+l].checkedAlready = 1;
                                            }
                                    }
                                }
                            }
                        }
                        if(i == 0){ 
                            //shows the position to the Bottom
                            if(!initalBoardE[i+1][j].isBomb){initalBoardE[i+1][j].dispLetter = bombsAround(i+1, j, 1) + 48; initalBoardE[i+1][j].checkedAlready = 1;}
                            //shows the right and bottom-right
                            if(j == 0){
                                
                                if(!initalBoardE[i][j+1].isBomb){initalBoardE[i][j+1].dispLetter = bombsAround(i, j+1, 1) + 48; initalBoardE[i][j+1].checkedAlready = 1;} 
                                if(!initalBoardE[i+1][j+1].isBomb){initalBoardE[i+1][j+1].dispLetter = bombsAround(i+1, j+1, 1) + 48; initalBoardE[i+1][j+1].checkedAlready = 1;}
                            }
                            //shows the left and bottom-left
                            else if(j == 4){
                                if(!initalBoardE[i][j-1].isBomb){initalBoardE[i][j-1].dispLetter = bombsAround(i, j-1, 1) + 48; initalBoardE[i][j-1].checkedAlready = 1;} 
                                if(!initalBoardE[i+1][j-1].isBomb){initalBoardE[i+1][j-1].dispLetter = bombsAround(i+1, j-1, 1) + 48; initalBoardE[i+1][j-1].checkedAlready = 1;}
                            }
                            //shows the right, bottom-right, left and bottom-left
                            else{
                                if(!initalBoardE[i][j+1].isBomb){initalBoardE[i][j+1].dispLetter = bombsAround(i, j+1, 1) + 48; initalBoardE[i][j+1].checkedAlready = 1;} 
                                if(!initalBoardE[i+1][j+1].isBomb){initalBoardE[i+1][j+1].dispLetter = bombsAround(i+1, j+1, 1) + 48; initalBoardE[i+1][j+1].checkedAlready = 1;}
                                if(!initalBoardE[i][j-1].isBomb){initalBoardE[i][j-1].dispLetter = bombsAround(i, j-1, 1) + 48; initalBoardE[i][j-1].checkedAlready = 1;} 
                                if(!initalBoardE[i+1][j-1].isBomb){initalBoardE[i+1][j-1].dispLetter = bombsAround(i+1, j-1, 1) + 48; initalBoardE[i+1][j-1].checkedAlready = 1;}
                            }
                        } 

                        if(i == 4){ 
                            //shows the position to the Top
                            if(!initalBoardE[i-1][j].isBomb){initalBoardE[i-1][j].dispLetter = bombsAround(i-1, j, 1) + 48; initalBoardE[i-1][j].checkedAlready = 1;}
                            //shows the right and top-right
                            if(j == 0){
                                if(!initalBoardE[i][j+1].isBomb){initalBoardE[i][j+1].dispLetter = bombsAround(i, j+1, 1) + 48; initalBoardE[i][j+1].checkedAlready = 1;} 
                                if(!initalBoardE[i-1][j+1].isBomb){initalBoardE[i-1][j+1].dispLetter = bombsAround(i-1, j+1, 1) + 48; initalBoardE[i-1][j+1].checkedAlready = 1;}
                            }
                            //shows the left and top-left
                            else if(j == 4){
                                if(!initalBoardE[i][j-1].isBomb){initalBoardE[i][j-1].dispLetter = bombsAround(i, j-1, 1) + 48; initalBoardE[i][j-1].checkedAlready = 1;} 
                                if(!initalBoardE[i-1][j-1].isBomb){initalBoardE[i-1][j-1].dispLetter = bombsAround(i-1, j-1, 1) + 48; initalBoardE[i-1][j-1].checkedAlready = 1;}
                            }
                            //shows the right, top-right, left and top-left
                            else{
                                if(!initalBoardE[i][j+1].isBomb){initalBoardE[i][j+1].dispLetter = bombsAround(i, j+1, 1) + 48; initalBoardE[i][j+1].checkedAlready = 1;} 
                                if(!initalBoardE[i-1][j+1].isBomb){initalBoardE[i-1][j+1].dispLetter = bombsAround(i-1, j+1, 1) + 48; initalBoardE[i-1][j+1].checkedAlready = 1;}
                                if(!initalBoardE[i][j-1].isBomb){initalBoardE[i][j-1].dispLetter = bombsAround(i, j-1, 1) + 48; initalBoardE[i][j-1].checkedAlready = 1;} 
                                if(!initalBoardE[i-1][j-1].isBomb){initalBoardE[i-1][j-1].dispLetter = bombsAround(i-1, j-1, 1) + 48; initalBoardE[i-1][j-1].checkedAlready = 1;}
                            }
                        } 

                        if(j == 0){
                            if(i != 0 && i != 4){
                                /* Checks the 5 to the right
                                X X
                                S X
                                X X
                                */
                                for(int k = -1; k <= 1; k++){
                                    for(int l = 0; l <= 1; l++){
                                        if(k == 0 && l == 0){
                                            continue;
                                        }
                                        else{
                                            if(!initalBoardE[i+k][j+l].isBomb) {initalBoardE[i+k][j+l].dispLetter = bombsAround(i+k, j+l, 1) + 48; initalBoardE[i+k][j+l].checkedAlready = 1;}
                                            else {continue;}
                                        }
                                    }
                                }
                            }
                        }

                        if(j == 4){
                            if(i != 0 && i != 4){
                                /* Checks the 5 to the left
                                X X 
                                X S 
                                X X
                                */
                                for(int k = -1; k <= 1; k++){
                                    for(int l = -1; l <= 0; l++){
                                        if(k == 0 && l == 0){
                                            continue;
                                        }
                                        else{
                                            if(!initalBoardE[i+k][j+l].isBomb) {initalBoardE[i+k][j+l].dispLetter = bombsAround(i+k, j+l, 1) + 48; initalBoardE[i+k][j+l].checkedAlready = 1;}
                                            else {continue;}
                                        }
                                    }
                                }
                            }
                        }

                    }
                }
            }
        }
    }
}

void checkBombN(char userLetter, int userPos, bool* userBomb){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(userLetter == initalBoardN[i][j].letterPos && userPos == initalBoardN[i][j].numPos && !initalBoardN[i][j].checkedAlready){
                if(initalBoardN[i][j].isBomb){
                    *userBomb = 1;
                    cout << "You hit a bomb! :(\n";
                }
                else{
                    initalBoardN[i][j].dispLetter = bombsAround(i, j, 2) + 48;
                    if(initalBoardN[i][j].bAround == 0 || initalBoardN[i][j].bAround == 1){
                        if(i != 0 && i != 9 && j != 0 && j != 9){ // makes sure the userinput isn't on the edge
                            for(int k = -1; k <= 1; k++){
                                for(int l = -1; l <= 1; l++){
                                    if(k == 0 && l == 0){
                                        continue;
                                    }
                                    else{
                                        if(initalBoardN[i+k][j+l].isBomb) {continue;}
                                        else {
                                                initalBoardN[i+k][j+l].dispLetter = bombsAround(i+k, j+l, 2) + 48;
                                                initalBoardN[i+k][j+l].checkedAlready = 1;
                                            }
                                    }
                                }
                            }
                        }
                        if(i == 0){ 
                            //shows the position to the Bottom
                            if(!initalBoardN[i+1][j].isBomb){initalBoardN[i+1][j].dispLetter = bombsAround(i+1, j, 2) + 48; initalBoardN[i+1][j].checkedAlready = 1;}
                            //shows the right and bottom-right
                            if(j == 0){
                                
                                if(!initalBoardN[i][j+1].isBomb){initalBoardN[i][j+1].dispLetter = bombsAround(i, j+1, 2) + 48; initalBoardN[i][j+1].checkedAlready = 1;} 
                                if(!initalBoardN[i+1][j+1].isBomb){initalBoardN[i+1][j+1].dispLetter = bombsAround(i+1, j+1, 2) + 48; initalBoardN[i+1][j+1].checkedAlready = 1;}
                            }
                            //shows the left and bottom-left
                            else if(j == 9){
                                if(!initalBoardN[i][j-1].isBomb){initalBoardN[i][j-1].dispLetter = bombsAround(i, j-1, 2) + 48; initalBoardN[i][j-1].checkedAlready = 1;} 
                                if(!initalBoardN[i+1][j-1].isBomb){initalBoardN[i+1][j-1].dispLetter = bombsAround(i+1, j-1, 2) + 48; initalBoardN[i+1][j-1].checkedAlready = 1;}
                            }
                            //shows the right, bottom-right, left and bottom-left
                            else{
                                if(!initalBoardN[i][j+1].isBomb){initalBoardN[i][j+1].dispLetter = bombsAround(i, j+1, 2) + 48; initalBoardN[i][j+1].checkedAlready = 1;} 
                                if(!initalBoardN[i+1][j+1].isBomb){initalBoardN[i+1][j+1].dispLetter = bombsAround(i+1, j+1, 2) + 48; initalBoardN[i+1][j+1].checkedAlready = 1;}
                                if(!initalBoardN[i][j-1].isBomb){initalBoardN[i][j-1].dispLetter = bombsAround(i, j-1, 2) + 48; initalBoardN[i][j-1].checkedAlready = 1;} 
                                if(!initalBoardN[i+1][j-1].isBomb){initalBoardN[i+1][j-1].dispLetter = bombsAround(i+1, j-1, 2) + 48; initalBoardN[i+1][j-1].checkedAlready = 1;}
                            }
                        } 

                        if(i == 9){ 
                            //shows the position to the Top
                            if(!initalBoardN[i-1][j].isBomb){initalBoardN[i+1][j].dispLetter = bombsAround(i-1, j, 2) + 48; initalBoardN[i-1][j].checkedAlready = 1;}
                            //shows the right and top-right
                            if(j == 0){
                                if(!initalBoardN[i][j+1].isBomb){initalBoardN[i][j+1].dispLetter = bombsAround(i, j+1, 2) + 48; initalBoardN[i][j+1].checkedAlready = 1;} 
                                if(!initalBoardN[i-1][j+1].isBomb){initalBoardN[i-1][j+1].dispLetter = bombsAround(i-1, j+1, 2) + 48; initalBoardN[i-1][j+1].checkedAlready = 1;}
                            }
                            //shows the left and top-left
                            else if(j == 9){
                                if(!initalBoardN[i][j-1].isBomb){initalBoardN[i][j-1].dispLetter = bombsAround(i, j-1, 2) + 48; initalBoardN[i][j-1].checkedAlready = 1;} 
                                if(!initalBoardN[i-1][j-1].isBomb){initalBoardN[i-1][j-1].dispLetter = bombsAround(i-1, j-1, 2) + 48; initalBoardN[i-1][j-1].checkedAlready = 1;}
                            }
                            //shows the right, top-right, left and top-left
                            else{
                                if(!initalBoardN[i][j+1].isBomb){initalBoardN[i][j+1].dispLetter = bombsAround(i, j+1, 2) + 48; initalBoardN[i][j+1].checkedAlready = 1;} 
                                if(!initalBoardN[i-1][j+1].isBomb){initalBoardN[i-1][j+1].dispLetter = bombsAround(i-1, j+1, 2) + 48; initalBoardN[i-1][j+1].checkedAlready = 1;}
                                if(!initalBoardN[i][j-1].isBomb){initalBoardN[i][j-1].dispLetter = bombsAround(i, j-1, 2) + 48; initalBoardN[i][j-1].checkedAlready = 1;} 
                                if(!initalBoardN[i-1][j-1].isBomb){initalBoardN[i-1][j-1].dispLetter = bombsAround(i-1, j-1, 2) + 48; initalBoardN[i-1][j-1].checkedAlready = 1;}
                            }
                        } 

                        if(j == 0){
                            if(i != 0 && i != 9){
                                /* Checks the 5 to the right
                                X X
                                S X
                                X X
                                */
                                for(int k = -1; k <= 1; k++){
                                    for(int l = 0; l <= 1; l++){
                                        if(k == 0 && l == 0){
                                            continue;
                                        }
                                        else{
                                            if(!initalBoardN[i+k][j+l].isBomb) {initalBoardN[i+k][j+l].dispLetter = bombsAround(i+k, j+l, 2) + 48; initalBoardN[i+k][j+l].checkedAlready = 1;}
                                            else {continue;}
                                        }
                                    }
                                }
                            }
                        }

                        if(j == 9){
                            if(i != 0 && i != 9){
                                /* Checks the 5 to the left
                                X X 
                                X S 
                                X X
                                */
                                for(int k = -1; k <= 1; k++){
                                    for(int l = -1; l <= 0; l++){
                                        if(k == 0 && l == 0){
                                            continue;
                                        }
                                        else{
                                            if(!initalBoardN[i+k][j+l].isBomb) {initalBoardN[i+k][j+l].dispLetter = bombsAround(i+k, j+l, 2) + 48; initalBoardN[i+k][j+l].checkedAlready = 1;}
                                            else {continue;}
                                        }
                                    }
                                }
                            }
                        }

                    }
                }
            }
        }
    }
}

// void checkBombH(char userLetter, int userPos, bool* userBomb){
//     for(int i = 0; i < 26; i++){
//         for(int j = 0; j < 26; j++){
//             if(userLetter == initalBoardH[i][j].letterPos && userPos == initalBoardH[i][j].numPos && !initalBoardH[i][j].checkedAlready){
//                 if(initalBoardH[i][j].isBomb){
//                     *userBomb = 1;
//                     cout << "You hit a bomb! :(\n";
//                 }
//                 else{
//                     initalBoardH[i][j].dispLetter = bombsAround(i, j, 3) + 48;
//                     if(initalBoardH[i][j].bAround == 0 || initalBoardH[i][j].bAround == 1){
//                         if(i != 0 && i != 25 && j != 0 && j != 25){ // makes sure the userinput isn't on the edge
//                             for(int k = -1; k <= 1; k++){
//                                 for(int l = -1; l <= 1; l++){
//                                     if(k == 0 && l == 0){
//                                         continue;
//                                     }
//                                     else{
//                                         if(initalBoardH[i+k][j+l].isBomb) {continue;}
//                                         else {
//                                                 initalBoardH[i+k][j+l].dispLetter = bombsAround(i+k, j+l, 3) + 48;
//                                                 initalBoardH[i+k][j+l].checkedAlready = 1;
//                                             }
//                                     }
//                                 }
//                             }
//                         }
//                         if(i == 0){ 
//                             //shows the position to the Bottom
//                             if(!initalBoardH[i+1][j].isBomb){initalBoardH[i+1][j].dispLetter = bombsAround(i+1, j, 3) + 48; initalBoardH[i+1][j].checkedAlready = 1;}
//                             //shows the right and bottom-right
//                             if(j == 0){
                                
//                                 if(!initalBoardH[i][j+1].isBomb){initalBoardH[i][j+1].dispLetter = bombsAround(i, j+1, 3) + 48; initalBoardH[i][j+1].checkedAlready = 1;} 
//                                 if(!initalBoardH[i+1][j+1].isBomb){initalBoardH[i+1][j+1].dispLetter = bombsAround(i+1, j+1, 3) + 48; initalBoardH[i+1][j+1].checkedAlready = 1;}
//                             }
//                             //shows the left and bottom-left
//                             else if(j == 25){
//                                 if(!initalBoardH[i][j-1].isBomb){initalBoardH[i][j-1].dispLetter = bombsAround(i, j-1, 3) + 48; initalBoardH[i][j-1].checkedAlready = 1;} 
//                                 if(!initalBoardH[i+1][j-1].isBomb){initalBoardH[i+1][j-1].dispLetter = bombsAround(i+1, j-1, 3) + 48; initalBoardH[i+1][j-1].checkedAlready = 1;}
//                             }
//                             //shows the right, bottom-right, left and bottom-left
//                             else{
//                                 if(!initalBoardH[i][j+1].isBomb){initalBoardH[i][j+1].dispLetter = bombsAround(i, j+1, 3) + 48; initalBoardH[i][j+1].checkedAlready = 1;} 
//                                 if(!initalBoardH[i+1][j+1].isBomb){initalBoardH[i+1][j+1].dispLetter = bombsAround(i+1, j+1, 3) + 48; initalBoardH[i+1][j+1].checkedAlready = 1;}
//                                 if(!initalBoardH[i][j-1].isBomb){initalBoardH[i][j-1].dispLetter = bombsAround(i, j-1, 3) + 48; initalBoardH[i][j-1].checkedAlready = 1;} 
//                                 if(!initalBoardH[i+1][j-1].isBomb){initalBoardH[i+1][j-1].dispLetter = bombsAround(i+1, j-1, 3) + 48; initalBoardH[i+1][j-1].checkedAlready = 1;}
//                             }
//                         } 

//                         if(i == 25){ 
//                             //shows the position to the Top
//                             if(!initalBoardH[i-1][j].isBomb){initalBoardH[i+1][j].dispLetter = bombsAround(i-1, j, 3) + 48; initalBoardH[i-1][j].checkedAlready = 1;}
//                             //shows the right and top-right
//                             if(j == 0){
//                                 if(!initalBoardH[i][j+1].isBomb){initalBoardH[i][j+1].dispLetter = bombsAround(i, j+1, 3) + 48; initalBoardH[i][j+1].checkedAlready = 1;} 
//                                 if(!initalBoardH[i-1][j+1].isBomb){initalBoardH[i-1][j+1].dispLetter = bombsAround(i-1, j+1, 3) + 48; initalBoardH[i-1][j+1].checkedAlready = 1;}
//                             }
//                             //shows the left and top-left
//                             else if(j == 25){
//                                 if(!initalBoardH[i][j-1].isBomb){initalBoardH[i][j-1].dispLetter = bombsAround(i, j-1, 3) + 48; initalBoardH[i][j-1].checkedAlready = 1;} 
//                                 if(!initalBoardH[i-1][j-1].isBomb){initalBoardH[i-1][j-1].dispLetter = bombsAround(i-1, j-1, 3) + 48; initalBoardH[i-1][j-1].checkedAlready = 1;}
//                             }
//                             //shows the right, top-right, left and top-left
//                             else{
//                                 if(!initalBoardH[i][j+1].isBomb){initalBoardH[i][j+1].dispLetter = bombsAround(i, j+1, 3) + 48; initalBoardH[i][j+1].checkedAlready = 1;} 
//                                 if(!initalBoardH[i-1][j+1].isBomb){initalBoardH[i-1][j+1].dispLetter = bombsAround(i-1, j+1, 3) + 48; initalBoardH[i-1][j+1].checkedAlready = 1;}
//                                 if(!initalBoardH[i][j-1].isBomb){initalBoardH[i][j-1].dispLetter = bombsAround(i, j-1, 3) + 48; initalBoardH[i][j-1].checkedAlready = 1;} 
//                                 if(!initalBoardH[i-1][j-1].isBomb){initalBoardH[i-1][j-1].dispLetter = bombsAround(i-1, j-1, 3) + 48; initalBoardH[i-1][j-1].checkedAlready = 1;}
//                             }
//                         } 

//                         if(j == 0){
//                             if(i != 0 && i != 25){
//                                 /* Checks the 5 to the right
//                                 X X
//                                 S X
//                                 X X
//                                 */
//                                 for(int k = -1; k <= 1; k++){
//                                     for(int l = 0; l <= 1; l++){
//                                         if(k == 0 && l == 0){
//                                             continue;
//                                         }
//                                         else{
//                                             if(!initalBoardH[i+k][j+l].isBomb) {initalBoardH[i+k][j+l].dispLetter = bombsAround(i+k, j+l, 3) + 48; initalBoardH[i+k][j+l].checkedAlready = 1;}
//                                             else {continue;}
//                                         }
//                                     }
//                                 }
//                             }
//                         }

//                         if(j == 25){
//                             if(i != 0 && i != 25){
//                                 /* Checks the 5 to the left
//                                 X X 
//                                 X S 
//                                 X X
//                                 */
//                                 for(int k = -1; k <= 1; k++){
//                                     for(int l = -1; l <= 0; l++){
//                                         if(k == 0 && l == 0){
//                                             continue;
//                                         }
//                                         else{
//                                             if(!initalBoardH[i+k][j+l].isBomb) {initalBoardH[i+k][j+l].dispLetter = bombsAround(i+k, j+l, 3) + 48; initalBoardH[i+k][j+l].checkedAlready = 1;}
//                                             else {continue;}
//                                         }
//                                     }
//                                 }
//                             }
//                         }

//                     }
//                 }
//             }
//         }
//     }
// }


int howManyBombsE(){
    int totalLeft = 0;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(initalBoardE[i][j].dispLetter == "X"){
                totalLeft++;
            }
        }
    }
    return totalLeft;
}

int howManyBombsN(){
    int totalLeft = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(initalBoardN[i][j].dispLetter == "X"){
                totalLeft++;
            }
        }
    }
    return totalLeft;
}

/*int howManyBombsH(){
    int totalLeft = 0;
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 26; j++){
            if(initalBoardN[i][j].dispLetter == "X"){
                totalLeft++;
            }
        }
    }
    return totalLeft;
}*/

int main() {
    srand(time(0)); //To affect rand() so that it is random
    string choice;
    cout << "Hello, Welcome to Minesweeper on C++\n"
    << "   What size board do you want?\n"
    << "       1. Easy   2. Normal\n"
    << "          Or exit with 0?\n";
    cin >> choice;
    if(choice.size() > 1 || stoi(choice) < 0 || stoi(choice) > 3){
        cout << "Please put a valid input\n";
        main();
    }
    if(stoi(choice) == 0){
        return 0;
    }
    int choiceNum = stoi(choice);
    if(choiceNum == 1){
        setBoardE();
        dispBoardE();
    }
    if(choiceNum == 2){
        setBoardN();
        dispBoardN();
    }
    /*if(choiceNum == 3){
        setBoardH();
        dispBoardH();
    }*/
    
    
    
    user_input user;
    cin.ignore();
    while(user.hitBomb != 1){

        //Displays the inital Board
        int once = 0;


        if(howManyBombsE() == howManyBombs || howManyBombsN() == howManyBombs)
        {
            break;
        }
        //User input
        cout << "Which letter do you want to check?\n" << "(There are: " << howManyBombs << " bombs)\n";
        cin >> user.letter;
        cin.ignore();
        user.letter = toupper(user.letter);
        if(choiceNum == 1  && !(user.letter >= 'A' && user.letter <= 'A' + 4)) {cout << "Please enter a valid input\n"; continue;}
        if(choiceNum == 2  && !(user.letter >= 'A' && user.letter <= 'A' + 9)) {cout << "Please enter a valid input\n"; continue;}
        //if(choiceNum == 3  && !(user.letter >= 'A' && user.letter <= 'A' + 25)) {cout << "Please enter a valid input\n"; continue;}


        cout << "What number do you want?\n";
        cin >> user.num;
        cin.ignore();
        if(choiceNum == 1  && !(user.num >= 1 && user.num <= 5)) {cout << "Please enter a valid input\n"; continue;}
        if(choiceNum == 2  && !(user.num >= 1 && user.num <= 10)) {cout << "Please enter a valid input\n"; continue;}
        //if(choiceNum == 3  && !(user.num >= 1 && user.num <= 26)) {cout << "Please enter a valid input\n"; continue;}

        //write code for invalid inputs
        
        if(choiceNum == 1) {checkBombE(user.letter, user.num, &user.hitBomb);}
        if(choiceNum == 2) {checkBombN(user.letter, user.num, &user.hitBomb);}
        //if(choiceNum == 3) {checkBombH(user.letter, user.num, &user.hitBomb);}

        once++;
        if(choiceNum == 1 && once != 0 && user.hitBomb != 1){
            dispBoardE();
        }
        if(choiceNum == 2 && once != 0 && user.hitBomb != 1){
            dispBoardN();
        }
        /*if(choiceNum == 3 && once != 0 && user.hitBomb != 1){
            dispBoardH();
        }*/
    }

    //vector<vector<board>> initialBoard = makeBoard(stoi(choice));
    
    if(howManyBombsE() == howManyBombs || howManyBombsN() == howManyBombs)
    {
        cout << "You win!!\n";
    }
    


    cout << "\ncat";
    return 0;
}