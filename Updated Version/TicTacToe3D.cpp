#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <list>
#include <unistd.h>

using namespace std;

void initializeBoard();
int GetDecisionPoints(int pos);
void game();
int checkIfGameEnded();
void printBoardNormal();

const int z = 3; /// Z - constant weigth-value for new lines started by algo
const int x = 2; /// X - constant weigth-value for continued lines by algo
const int y = 1; /// Y - constant weigth-value for blocked lines for opponent

vector<vector<pair<int, int>>> lines = vector<vector<pair<int, int>>>();


vector<int> InitializeVector()
{
    vector<int> emptyVector = vector<int>();
    for (int i = 0; i < 30; i++) {
        emptyVector.push_back(0);
    }
    emptyVector[0] = -2;
    emptyVector[10] = -2;
    emptyVector[20] = -2;
    return emptyVector;
}

bool checkIfPositionIsEmpty(int position) {
    for (vector<pair<int, int>> line : lines) {
        for (pair<int, int> para : line) {
            if (para.first == position)
                return para.second == 0;
        }
    }
    return 0;
}


vector<int> GetDecisionVector() {
    vector<int> decisionVector = InitializeVector();
    for (vector<pair<int, int>> line : lines) {
        for (pair<int, int> para : line) {
            if (checkIfPositionIsEmpty(para.first))
            {
                decisionVector[para.first] = GetDecisionPoints(para.first);
            }
            else
            {
                decisionVector[para.first] = -1;
            }
        }
    }
    return decisionVector;
}

int getNextPositionToMove(){
    vector<int> decisionVector = GetDecisionVector();
    int theBestMove = 0;
    for(int i = 0; i < decisionVector.size(); i++){
        if(decisionVector[i] > decisionVector[theBestMove])
            theBestMove = i;
    }
cout << theBestMove;
return theBestMove;
}


int GetDecisionPoints(int pos) {
    int userLinesToBeStarted = 0;
    int userLinesToBeContinued = 0;
    int opponentLinesToBeBlocked = 0;

    vector<vector<pair<int, int>>> conductedLines = vector<vector<pair<int, int>>>();
    int index = 0;
    for (vector<pair<int, int>> line : lines) {
        for (pair<int, int> para : line) {
            if (para.first == pos) {
                conductedLines.push_back(line);
                break;
            }
        }
    }

    vector<vector<pair<int, int>>> conductedLinesModified = vector<vector<pair<int, int>>>();
     for (vector<pair<int, int>> line : conductedLines) {
        for (vector<pair<int, int>>::iterator iter = line.begin(); iter != line.end(); iter++) {
            if ((*iter).first == pos) {
                line.erase(iter);
                conductedLinesModified.push_back(line);
                break;
            }
        }
    }

    for (vector<pair<int, int>> line : conductedLinesModified)
    {
        if (line[0].second == -1 && line[1].second == -1)
            return 100;
        if (line[0].second == 1 && line[1].second == 1)
            return 50;
        if (line[0].second + line[1].second == 1)
            opponentLinesToBeBlocked++;
        else if (line[0].second == 0 && line[1].second == 0)
            userLinesToBeStarted++;
        else if (line[0].second + line[1].second == -1) {
            userLinesToBeContinued++;
        }
    }
    return (userLinesToBeContinued * x) + (userLinesToBeStarted * z) + (opponentLinesToBeBlocked * y);
}





void setValueForPositionAfterMove(int pos, int value)
{
    vector<vector<pair<int, int>>> LinesToBeModified = vector<vector<pair<int, int>>>();
    for (vector<pair<int, int>> line : lines) {
        for (pair<int, int> para : line) {
            if (para.first == pos) {
                LinesToBeModified.push_back(line);
                break;
            }
        }
    }


    vector<vector<pair<int, int>>> LinesModified = vector<vector<pair<int, int>>>();
    for (vector<pair<int, int>> linee : LinesToBeModified) {
        for (vector<pair<int, int>>::iterator iter = linee.begin(); iter != linee.end(); iter++) {
            if ((*iter).first == pos) {
                (*iter).second = value;
            }
            else
                continue;
            LinesModified.push_back(linee);
            break;
        }
    }

    vector<vector<pair<int, int>>> LinesTemp = vector<vector<pair<int, int>>>();
    list<int> lineFromOrigin = list<int>();
    list<list<int>> linesFromMod = list<list<int>>();

    for (vector<pair<int, int>> lineMod : LinesModified) {
        linesFromMod.push_back(list<int> {lineMod[0].first, lineMod[1].first, lineMod[2].first});
    }

    bool check = false;
    for (vector<pair<int, int>> linee : lines) {
        lineFromOrigin.push_back(linee[0].first);
        lineFromOrigin.push_back(linee[1].first);
        lineFromOrigin.push_back(linee[2].first);
        for (auto t : linesFromMod) {
            if (t == lineFromOrigin)
            {
                check = true;
                break;
            }
        }
        lineFromOrigin.clear();
        if (!check) {
            LinesModified.push_back(linee);
            check = false;
        }
        check = false;
    }
    lines = LinesModified;
}

int main() {
    initializeBoard();
    game();
    return 0;
}


void game()
{
    bool whosTurnToMove = false; /// false => algoritms turn to move && true => user time to move
    while(checkIfGameEnded() == 2){
        if(!whosTurnToMove){
            /// AI logic of move
            vector<int> decisionVector = GetDecisionVector();
            int theBestMove = 0;
            for(int i = 0; i < decisionVector.size(); i++){
                if(decisionVector[i] > decisionVector[theBestMove])
                    theBestMove = i;
            }
            setValueForPositionAfterMove(theBestMove, -1);
            whosTurnToMove = true;
        }
        else{
            /// User logic of move
            /// Get int pos, check if possible and move
            int number;
            while(true)
            {
                cout << endl << "Where you want to move?";
                cin >> number;
                if(number >= 1 && number < 30 && number%10 != 0 && checkIfPositionIsEmpty(number))
                {
                  setValueForPositionAfterMove(number,1);
                  whosTurnToMove = false;
                  break;
                }
                else{
                    cout << endl << "Incorrect position, please, try again!";
                    usleep(990000);
                    system("cls");
                    printBoardNormal();
                }
            }
        }
        system("cls");
        printBoardNormal();
        switch(checkIfGameEnded()){
        case -1:
            cout << "Algo win";
            return;
        case 1:
            cout << "User win";
            return;
        case 0:
            cout << "There is a draw";
            return;
        }
    }
}

/// Returns -1 if algo win || 1 if user win || 0 if draw || 2 if still possibility of turn
int checkIfGameEnded()
{
    int sum = 0;
    for(vector<pair<int,int>> line : lines){
        for(pair<int,int> para : line){
            sum += para.second;
        }
        if(sum == -3)
            return -1;
        else if(sum == 3)
            return 1;
        sum = 0;
    }
    for(vector<pair<int,int>> line : lines){
        for(pair<int,int> para : line){
            if(para.second == 0)
                return 2;
        }
    }
return 0;
}


void initializeBoard()
{
    vector<pair<int, int>> line1 = vector<pair<int, int>>();
    vector<pair<int, int>> line2 = vector<pair<int, int>>();
    vector<pair<int, int>> line3 = vector<pair<int, int>>();
    vector<pair<int, int>> line4 = vector<pair<int, int>>();
    vector<pair<int, int>> line5 = vector<pair<int, int>>();
    vector<pair<int, int>> line6 = vector<pair<int, int>>();
    vector<pair<int, int>> line7 = vector<pair<int, int>>();
    vector<pair<int, int>> line8 = vector<pair<int, int>>();

    vector<pair<int, int>> line9 = vector<pair<int, int>>();
    vector<pair<int, int>> line10 = vector<pair<int, int>>();
    vector<pair<int, int>> line11 = vector<pair<int, int>>();
    vector<pair<int, int>> line12 = vector<pair<int, int>>();
    vector<pair<int, int>> line13 = vector<pair<int, int>>();
    vector<pair<int, int>> line14 = vector<pair<int, int>>();
    vector<pair<int, int>> line15 = vector<pair<int, int>>();
    vector<pair<int, int>> line16 = vector<pair<int, int>>();

    vector<pair<int, int>> line17 = vector<pair<int, int>>();
    vector<pair<int, int>> line18 = vector<pair<int, int>>();
    vector<pair<int, int>> line19 = vector<pair<int, int>>();
    vector<pair<int, int>> line20 = vector<pair<int, int>>();
    vector<pair<int, int>> line21 = vector<pair<int, int>>();
    vector<pair<int, int>> line22 = vector<pair<int, int>>();
    vector<pair<int, int>> line23 = vector<pair<int, int>>();
    vector<pair<int, int>> line24 = vector<pair<int, int>>();

    vector<pair<int, int>> line25 = vector<pair<int, int>>();
    vector<pair<int, int>> line26 = vector<pair<int, int>>();
    vector<pair<int, int>> line27 = vector<pair<int, int>>();
    vector<pair<int, int>> line28 = vector<pair<int, int>>();
    vector<pair<int, int>> line29 = vector<pair<int, int>>();

    vector<pair<int, int>> line30 = vector<pair<int, int>>();
    vector<pair<int, int>> line31 = vector<pair<int, int>>();
    vector<pair<int, int>> line32 = vector<pair<int, int>>();
    vector<pair<int, int>> line33 = vector<pair<int, int>>();
    vector<pair<int, int>> line34 = vector<pair<int, int>>();

    vector<pair<int, int>> line35 = vector<pair<int, int>>();
    vector<pair<int, int>> line36 = vector<pair<int, int>>();
    vector<pair<int, int>> line37 = vector<pair<int, int>>();
    vector<pair<int, int>> line38 = vector<pair<int, int>>();
    vector<pair<int, int>> line39 = vector<pair<int, int>>();

    vector<pair<int, int>> line40 = vector<pair<int, int>>();
    vector<pair<int, int>> line41 = vector<pair<int, int>>();
    vector<pair<int, int>> line42 = vector<pair<int, int>>();
    vector<pair<int, int>> line43 = vector<pair<int, int>>();
    vector<pair<int, int>> line44 = vector<pair<int, int>>();

    vector<pair<int, int>> line45 = vector<pair<int, int>>();
    vector<pair<int, int>> line46 = vector<pair<int, int>>();
    vector<pair<int, int>> line47 = vector<pair<int, int>>();
    vector<pair<int, int>> line48 = vector<pair<int, int>>();
    vector<pair<int, int>> line49 = vector<pair<int, int>>();

    vector<pair<int, int>> line50 = vector<pair<int, int>>();


    ///################# Upper Plane ##########################

    line1.push_back(pair<int, int>(1, 0));
    line1.push_back(pair<int, int>(2, 0));
    line1.push_back(pair<int, int>(3, 0));

    line2.push_back(pair<int, int>(4, 0));
    line2.push_back(pair<int, int>(5, 0));
    line2.push_back(pair<int, int>(6, 0));

    line3.push_back(pair<int, int>(7, 0));
    line3.push_back(pair<int, int>(8, 0));
    line3.push_back(pair<int, int>(9, 0));

    line4.push_back(pair<int, int>(1, 0));
    line4.push_back(pair<int, int>(4, 0));
    line4.push_back(pair<int, int>(7, 0));

    line5.push_back(pair<int, int>(2, 0));
    line5.push_back(pair<int, int>(5, 0));
    line5.push_back(pair<int, int>(8, 0));

    line6.push_back(pair<int, int>(3, 0));
    line6.push_back(pair<int, int>(6, 0));
    line6.push_back(pair<int, int>(9, 0));

    line7.push_back(pair<int, int>(1, 0));
    line7.push_back(pair<int, int>(5, 0));
    line7.push_back(pair<int, int>(9, 0));

    line8.push_back(pair<int, int>(3, 0));
    line8.push_back(pair<int, int>(5, 0));
    line8.push_back(pair<int, int>(7, 0));

    ///########################################################

    ///################# Middle Plane #########################

    line9.push_back(pair<int, int>(11, 0));
    line9.push_back(pair<int, int>(12, 0));
    line9.push_back(pair<int, int>(13, 0));

    line10.push_back(pair<int, int>(14, 0));
    line10.push_back(pair<int, int>(15, 0));
    line10.push_back(pair<int, int>(16, 0));

    line11.push_back(pair<int, int>(17, 0));
    line11.push_back(pair<int, int>(18, 0));
    line11.push_back(pair<int, int>(19, 0));

    line12.push_back(pair<int, int>(11, 0));
    line12.push_back(pair<int, int>(14, 0));
    line12.push_back(pair<int, int>(17, 0));

    line13.push_back(pair<int, int>(12, 0));
    line13.push_back(pair<int, int>(15, 0));
    line13.push_back(pair<int, int>(18, 0));

    line14.push_back(pair<int, int>(13, 0));
    line14.push_back(pair<int, int>(16, 0));
    line14.push_back(pair<int, int>(19, 0));

    line15.push_back(pair<int, int>(11, 0));
    line15.push_back(pair<int, int>(15, 0));
    line15.push_back(pair<int, int>(19, 0));

    line16.push_back(pair<int, int>(13, 0));
    line16.push_back(pair<int, int>(15, 0));
    line16.push_back(pair<int, int>(17, 0));

    ///########################################################

    ///################# Bottom Plane #########################

    line17.push_back(pair<int, int>(21, 0));
    line17.push_back(pair<int, int>(22, 0));
    line17.push_back(pair<int, int>(23, 0));

    line18.push_back(pair<int, int>(24, 0));
    line18.push_back(pair<int, int>(25, 0));
    line18.push_back(pair<int, int>(26, 0));

    line19.push_back(pair<int, int>(27, 0));
    line19.push_back(pair<int, int>(28, 0));
    line19.push_back(pair<int, int>(29, 0));

    line20.push_back(pair<int, int>(21, 0));
    line20.push_back(pair<int, int>(24, 0));
    line20.push_back(pair<int, int>(27, 0));

    line21.push_back(pair<int, int>(22, 0));
    line21.push_back(pair<int, int>(25, 0));
    line21.push_back(pair<int, int>(28, 0));

    line22.push_back(pair<int, int>(23, 0));
    line22.push_back(pair<int, int>(26, 0));
    line22.push_back(pair<int, int>(29, 0));

    line23.push_back(pair<int, int>(21, 0));
    line23.push_back(pair<int, int>(25, 0));
    line23.push_back(pair<int, int>(29, 0));

    line24.push_back(pair<int, int>(23, 0));
    line24.push_back(pair<int, int>(25, 0));
    line24.push_back(pair<int, int>(27, 0));

    ///########################################################

    ///################# Left Plane ###########################

    line25.push_back(pair<int, int>(1, 0));
    line25.push_back(pair<int, int>(11, 0));
    line25.push_back(pair<int, int>(21, 0));

    line26.push_back(pair<int, int>(4, 0));
    line26.push_back(pair<int, int>(14, 0));
    line26.push_back(pair<int, int>(24, 0));

    line27.push_back(pair<int, int>(7, 0));
    line27.push_back(pair<int, int>(17, 0));
    line27.push_back(pair<int, int>(27, 0));

    line28.push_back(pair<int, int>(1, 0));
    line28.push_back(pair<int, int>(14, 0));
    line28.push_back(pair<int, int>(27, 0));

    line29.push_back(pair<int, int>(7, 0));
    line29.push_back(pair<int, int>(14, 0));
    line29.push_back(pair<int, int>(21, 0));

    ///########################################################

    ///################# Front Plane ###########################

    line30.push_back(pair<int, int>(8, 0));
    line30.push_back(pair<int, int>(18, 0));
    line30.push_back(pair<int, int>(28, 0));

    line31.push_back(pair<int, int>(9, 0));
    line31.push_back(pair<int, int>(19, 0));
    line31.push_back(pair<int, int>(29, 0));

    line32.push_back(pair<int, int>(7, 0));
    line32.push_back(pair<int, int>(18, 0));
    line32.push_back(pair<int, int>(29, 0));

    line33.push_back(pair<int, int>(9, 0));
    line33.push_back(pair<int, int>(18, 0));
    line33.push_back(pair<int, int>(27, 0));

    ///########################################################

    ///################# Right Plane ##########################

    line34.push_back(pair<int, int>(6, 0));
    line34.push_back(pair<int, int>(16, 0));
    line34.push_back(pair<int, int>(26, 0));

    line35.push_back(pair<int, int>(3, 0));
    line35.push_back(pair<int, int>(13, 0));
    line35.push_back(pair<int, int>(23, 0));

    line36.push_back(pair<int, int>(9, 0));
    line36.push_back(pair<int, int>(16, 0));
    line36.push_back(pair<int, int>(23, 0));

    line37.push_back(pair<int, int>(3, 0));
    line37.push_back(pair<int, int>(16, 0));
    line37.push_back(pair<int, int>(29, 0));


    ///########################################################

    ///################# Back Plane ###########################

    line38.push_back(pair<int, int>(2, 0));
    line38.push_back(pair<int, int>(12, 0));
    line38.push_back(pair<int, int>(22, 0));

    line39.push_back(pair<int, int>(1, 0));
    line39.push_back(pair<int, int>(12, 0));
    line39.push_back(pair<int, int>(23, 0));

    line40.push_back(pair<int, int>(3, 0));
    line40.push_back(pair<int, int>(12, 0));
    line40.push_back(pair<int, int>(21, 0));

    ///########################################################

    ///################# Inside Lines #########################


    line41.push_back(pair<int, int>(1, 0));
    line41.push_back(pair<int, int>(15, 0));
    line41.push_back(pair<int, int>(29, 0));

    line42.push_back(pair<int, int>(9, 0));
    line42.push_back(pair<int, int>(15, 0));
    line42.push_back(pair<int, int>(21, 0));

    line43.push_back(pair<int, int>(3, 0));
    line43.push_back(pair<int, int>(15, 0));
    line43.push_back(pair<int, int>(27, 0));

    line44.push_back(pair<int, int>(7, 0));
    line44.push_back(pair<int, int>(15, 0));
    line44.push_back(pair<int, int>(23, 0));

    line45.push_back(pair<int, int>(5, 0));
    line45.push_back(pair<int, int>(15, 0));
    line45.push_back(pair<int, int>(25, 0));

    line46.push_back(pair<int, int>(2, 0));
    line46.push_back(pair<int, int>(15, 0));
    line46.push_back(pair<int, int>(27, 0));

    line47.push_back(pair<int, int>(7, 0));
    line47.push_back(pair<int, int>(15, 0));
    line47.push_back(pair<int, int>(22, 0));

    line48.push_back(pair<int, int>(4, 0));
    line48.push_back(pair<int, int>(15, 0));
    line48.push_back(pair<int, int>(26, 0));

    line49.push_back(pair<int, int>(6, 0));
    line49.push_back(pair<int, int>(15, 0));
    line49.push_back(pair<int, int>(24, 0));

    line50.push_back(pair<int, int>(3, 0));
    line50.push_back(pair<int, int>(12, 0));
    line50.push_back(pair<int, int>(21, 0));

    ///########################################################
    ///########################################################

    lines.push_back(line1);
    lines.push_back(line2);
    lines.push_back(line3);
    lines.push_back(line4);
    lines.push_back(line5);
    lines.push_back(line6);
    lines.push_back(line7);
    lines.push_back(line8);
    lines.push_back(line9);
    lines.push_back(line10);
    lines.push_back(line11);
    lines.push_back(line12);
    lines.push_back(line13);
    lines.push_back(line14);
    lines.push_back(line15);
    lines.push_back(line16);
    lines.push_back(line17);
    lines.push_back(line18);
    lines.push_back(line19);
    lines.push_back(line20);
    lines.push_back(line21);
    lines.push_back(line22);
    lines.push_back(line23);
    lines.push_back(line24);
    lines.push_back(line25);
    lines.push_back(line26);
    lines.push_back(line27);
    lines.push_back(line28);
    lines.push_back(line29);
    lines.push_back(line30);
    lines.push_back(line31);
    lines.push_back(line32);
    lines.push_back(line33);
    lines.push_back(line34);
    lines.push_back(line35);
    lines.push_back(line36);
    lines.push_back(line37);
    lines.push_back(line38);
    lines.push_back(line39);
    lines.push_back(line40);
    lines.push_back(line41);
    lines.push_back(line42);
    lines.push_back(line43);
    lines.push_back(line44);
    lines.push_back(line45);
    lines.push_back(line46);
    lines.push_back(line47);
    lines.push_back(line48);
    lines.push_back(line49);
    lines.push_back(line50);
}

void printBoardNormal()
{
    vector<int> board = InitializeVector();
    for(vector<pair<int,int>> line : lines)
    {
        for(pair<int,int> pair : line)
        {
            board[pair.first] = pair.second;
        }
    }
        cout << "                  _____________________________________________" << endl;
    cout << "       	         /              /              /              /" << endl;
    cout << "	        /              /              /              /" << endl;


                cout << "               /      ";
                if(board[1] == -1)
                    cout << "X";
                else if(board[1] == 1)
                    cout << "O";
                else
                    cout << " ";

                 cout << "       /      ";
                if(board[2] == -1)
                    cout << "X";
                else if(board[2] == 1)
                    cout << "O";
                else
                    cout << " ";
                cout <<  "       /      ";
                if(board[3] == -1)
                    cout << "X";
                else if(board[3] == 1)
                    cout << "O";
                else
                    cout << " ";
                cout << " 	    /" << endl;


    cout << "              /              /		    /		   /" << endl;
    cout << "             /______________/______________/______________/" << endl;
    cout << "            /		   /	          /	         /" << endl;
    cout << "           /              /              /              /" << endl;


                cout << "          /      ";
                if(board[4] == -1)
                    cout << "X";
                else if(board[4] == 1)
                    cout << "O";
                else
                    cout << " ";

                cout << "       /      ";
                if(board[5] == -1)
                    cout << "X";
                else if(board[5] == 1)
                    cout << "O";
                else
                    cout << " ";

                cout << "       /      ";
                if(board[6] == -1)
                    cout << "X";
                else if(board[6] == 1)
                    cout << "O";
                else
                    cout << " ";

                cout <<"       /" << endl;


    cout << "         /              /	       /              /" << endl;
    cout << "        /______________/______________/______________/" << endl;
    cout << "       /	      /              /	            /" << endl;
    cout << "      /		     /		    /		   /" << endl;


                cout << "     /      ";
                if(board[7] == -1)
                    cout << "X";
                else if(board[7] == 1)
                    cout << "O";
                else
                    cout << " ";
                cout << "       /      ";
                if(board[8] == -1)
                    cout << "X";
                else if(board[8] == 1)
                    cout << "O";
                else
                    cout << " ";

                cout << "       /      ";
                if(board[9] == -1)
                    cout << "X";
                else if(board[9] == 1)
                    cout << "O";
                else
                    cout << " ";
                cout << "       /" << endl;


    cout << "    /              /              /              /" << endl;
    cout << "   /		  /		 /		/" << endl;
    cout << "  /______________/______________/______________/" << endl << endl << endl << endl;

       cout << "                  _____________________________________________" << endl;
    cout << "       	         /              /              /              /" << endl;
    cout << "	        /              /              /              /" << endl;


                cout << "               /      ";
                if(board[11] == -1)
                    cout << "X";
                else if(board[11] == 1)
                    cout << "O";
                else
                    cout << " ";

                 cout << "       /      ";
                if(board[12] == -1)
                    cout << "X";
                else if(board[12] == 1)
                    cout << "O";
                else
                    cout << " ";
                cout <<  "       /      ";
                if(board[13] == -1)
                    cout << "X";
                else if(board[13] == 1)
                    cout << "O";
                else
                    cout << " ";
                cout << " 	    /" << endl;


    cout << "              /              /		    /		   /" << endl;
    cout << "             /______________/______________/______________/" << endl;
    cout << "            /		   /	          /	         /" << endl;
    cout << "           /              /              /              /" << endl;


                cout << "          /      ";
                if(board[14] == -1)
                    cout << "X";
                else if(board[14] == 1)
                    cout << "O";
                else
                    cout << " ";

                cout << "       /      ";
                if(board[15] == -1)
                    cout << "X";
                else if(board[15] == 1)
                    cout << "O";
                else
                    cout << " ";

                cout << "       /      ";
                if(board[16] == -1)
                    cout << "X";
                else if(board[16] == 1)
                    cout << "O";
                else
                    cout << " ";

                cout <<"       /" << endl;


    cout << "         /              /	       /              /" << endl;
    cout << "        /______________/______________/______________/" << endl;
    cout << "       /	      /              /	            /" << endl;
    cout << "      /		     /		    /		   /" << endl;


                cout << "     /      ";
                if(board[17] == -1)
                    cout << "X";
                else if(board[17] == 1)
                    cout << "O";
                else
                    cout << " ";
                cout << "       /      ";
                if(board[18] == -1)
                    cout << "X";
                else if(board[18] == 1)
                    cout << "O";
                else
                    cout << " ";

                cout << "       /      ";
                if(board[19] == -1)
                    cout << "X";
                else if(board[19] == 1)
                    cout << "O";
                else
                    cout << " ";
                cout << "       /" << endl;


    cout << "    /              /              /              /" << endl;
    cout << "   /		  /		 /		/" << endl;
    cout << "  /______________/______________/______________/" << endl << endl << endl << endl;

       cout << "                  _____________________________________________" << endl;
    cout << "       	         /              /              /              /" << endl;
    cout << "	        /              /              /              /" << endl;


                cout << "               /      ";
                if(board[21] == -1)
                    cout << "X";
                else if(board[21] == 1)
                    cout << "O";
                else
                    cout << " ";

                 cout << "       /      ";
                if(board[22] == -1)
                    cout << "X";
                else if(board[22] == 1)
                    cout << "O";
                else
                    cout << " ";
                cout <<  "       /      ";
                if(board[23] == -1)
                    cout << "X";
                else if(board[23] == 1)
                    cout << "O";
                else
                    cout << " ";
                cout << " 	    /" << endl;


    cout << "              /              /		    /		   /" << endl;
    cout << "             /______________/______________/______________/" << endl;
    cout << "            /		   /	          /	         /" << endl;
    cout << "           /              /              /              /" << endl;


                cout << "          /      ";
                if(board[24] == -1)
                    cout << "X";
                else if(board[24] == 1)
                    cout << "O";
                else
                    cout << " ";

                cout << "       /      ";
                if(board[25] == -1)
                    cout << "X";
                else if(board[25] == 1)
                    cout << "O";
                else
                    cout << " ";

                cout << "       /      ";
                if(board[26] == -1)
                    cout << "X";
                else if(board[26] == 1)
                    cout << "O";
                else
                    cout << " ";

                cout <<"       /" << endl;


    cout << "         /              /	       /              /" << endl;
    cout << "        /______________/______________/______________/" << endl;
    cout << "       /	      /              /	            /" << endl;
    cout << "      /		     /		    /		   /" << endl;


                cout << "     /      ";
                if(board[27] == -1)
                    cout << "X";
                else if(board[27] == 1)
                    cout << "O";
                else
                    cout << " ";
                cout << "       /      ";
                if(board[28] == -1)
                    cout << "X";
                else if(board[28] == 1)
                    cout << "O";
                else
                    cout << " ";

                cout << "       /      ";
                if(board[29] == -1)
                    cout << "X";
                else if(board[29] == 1)
                    cout << "O";
                else
                    cout << " ";
                cout << "       /" << endl;


    cout << "    /              /              /              /" << endl;
    cout << "   /		  /		 /		/" << endl;
    cout << "  /______________/______________/______________/" << endl << endl;
}
