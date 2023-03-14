#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

const int z = 3; /// Z - constant weigth-value for new lines started by algo
const int x = 2; /// X - constant weigth-value for continued lines by algo
const int y = 1; /// Y - constant weigth-value for blocked lines for opponent




int GetDecisionPoints(vector<int> board, int position);

vector<int> InitializeVector()
{
    vector<int> emptyVector = vector<int>();
    for(int i = 0; i < 30; i++){
        emptyVector.push_back(0);
    }
    emptyVector[0] = -2;
    emptyVector[10] = -2;
    emptyVector[20] = -2;
    return emptyVector;
}


vector<int> GetDecisionVector(vector<int> board){
    vector<int> decisionVector = InitializeVector();
    for(int i = 1; i < board.size(); i++)
    {
        if(board[i] != 0)
            decisionVector[i] = -1;
        else
            decisionVector[i] = GetDecisionPoints(board,i);
    }
return decisionVector;
}


int GetDecisionPoints(vector<int> board, int position){
    int userLinesToBeStarted = 0;
    int userLinesToBeContinued = 0;
    int opponentLinesToBeBlocked = 0;
    switch(position){

    /// Upper plane

    case 1:
    /// Check win or block condition (100/50 points)
        if((board[2] == -1 && board[3] == -1) || (board[5] == -1 && board[9] == -1) || (board[4] == -1 && board[7] == -1)
           || (board[11] == -1 && board[21] == -1) || (board[15] == -1 && board[29] == -1)
           || (board[14] == -1 && board[27] == -1)|| (board[12] == -1 && board[23] == -1))
            return 100;
        if((board[2] == 1 && board[3] == 1) || (board[5] == 1 && board[9] == 1) || (board[4] == 1 && board[7] == 1)
           || (board[11] == 1 && board[21] == 1) || (board[15] == 1 && board[29] == 1)
           || (board[14] == 1 && board[27] == 1)|| (board[12] == 1 && board[23] == 1))
            return 50;
    /// First line 1-2-3
        if(board[2] + board[3] == 1)
            opponentLinesToBeBlocked++;
        else if(board[2] == 0 && board[3] == 0)
            userLinesToBeStarted++;
        else if(board[2] + board[3] == -1)
            userLinesToBeContinued++;
    /// Second line 1-5-9
        if(board[5] + board[9] == 1)
            opponentLinesToBeBlocked++;
        else if(board[5] == 0 && board[9] == 0)
            userLinesToBeStarted++;
        else if(board[5] + board[9] == -1)
            userLinesToBeContinued++;
    /// Third line 1-4-7
        if(board[4] + board[7] == 1)
            opponentLinesToBeBlocked++;
        else if(board[4] == 0 && board[7] == 0)
            userLinesToBeStarted++;
        else if(board[4] + board[7] == -1)
            userLinesToBeContinued++;
    /// Fourth line, 1-11-21
        if(board[11] + board[21] == 1)
            opponentLinesToBeBlocked++;
        else if(board[11] == 0 && board[21] == 0)
            userLinesToBeStarted++;
        else if(board[11] + board[21] == -1)
            userLinesToBeContinued++;
    /// Fifth line, 1-15-29
        if(board[15] + board[29] == 1)
            opponentLinesToBeBlocked++;
        else if(board[15] == 0 && board[29] == 0)
            userLinesToBeStarted++;
        else if(board[15] + board[29] == -1)
            userLinesToBeContinued++;
    /// Sixth line, 1-14-27
        if(board[14] + board[27] == 1)
            opponentLinesToBeBlocked++;
        else if(board[14] == 0 && board[27] == 0)
            userLinesToBeStarted++;
        else if(board[14] + board[27] == -1)
            userLinesToBeContinued++;
    /// Seventh line, 1-12-23
        if(board[12] + board[23] == 1)
            opponentLinesToBeBlocked++;
        else if(board[12] == 0 && board[23] == 0)
            userLinesToBeStarted++;
        else if(board[12] + board[23] == -1)
            userLinesToBeContinued++;
    return (userLinesToBeContinued * x) + (userLinesToBeStarted * z) + (opponentLinesToBeBlocked * y);
    case 2:
        /// Check win or block condition (100/50 points)
        if((board[1] == -1 && board[3] == -1) || (board[5] == -1 && board[8] == -1)
            || (board[12] == -1 && board[22] == -1) || (board[15] == -1 && board[28] == -1))
            return 100;
        if((board[1] == 1 && board[3] == 1) || (board[5] == 1 && board[8] == 1)
            || (board[12] == 1 && board[22] == 1) || (board[15] == 1 && board[28] == 1))
            return 50;
        /// First lane, 1-2-3
        if(board[1] + board[3] == 1)
            opponentLinesToBeBlocked++;
        else if(board[1] == 0 && board[3] == 0)
            userLinesToBeStarted++;
        else if(board[1] + board[3] == -1)
            userLinesToBeContinued++;
        /// Second lane, 2-5-8
        if(board[5] + board[8] == 1)
            opponentLinesToBeBlocked++;
        else if(board[5] == 0 && board[8] == 0)
            userLinesToBeStarted++;
        else if(board[5] + board[8] == -1)
            userLinesToBeContinued++;
        /// Third line, 2-12-22
        if(board[12] + board[22] == 1)
            opponentLinesToBeBlocked++;
        else if(board[12] == 0 && board[22] == 0)
            userLinesToBeStarted++;
        else if(board[12] + board[22] == -1)
            userLinesToBeContinued++;
        /// Fourth line, 2-15-28
        if(board[15] + board[28] == 1)
            opponentLinesToBeBlocked++;
        else if(board[15] == 0 && board[28] == 0)
            userLinesToBeStarted++;
        else if(board[15] + board[28] == -1)
            userLinesToBeContinued++;
    return (userLinesToBeContinued * x) + (userLinesToBeStarted * z) + (opponentLinesToBeBlocked * y);
    case 3:
        /// Check win or block condition (100/50 points)
        if((board[1] == -1 && board[2] == -1) || (board[6] == -1 && board[9] == -1) || (board[5] == -1 && board[7] == -1) ||
           (board[13] == -1 && board[23] == -1) || (board[15] == -1 && board[27] == -1) || (board[16] == -1 && board[29] == -1) ||
           (board[12] == -1 && board[21] == -1))
           return 100;
        if((board[1] == 1 && board[2] == 1) || (board[6] == 1 && board[9] == 1) || (board[5] == 1 && board[7] == 1) ||
           (board[13] == 1 && board[23] == 1) || (board[15] == 1 && board[27] == 1) || (board[16] == 1 && board[29] == 1) ||
           (board[12] == 1 && board[21] == 1))
           return 50;
        /// First line, 1-2-3
        if(board[1] + board[2] == 1)
            opponentLinesToBeBlocked++;
        else if(board[1] == 0 && board[2] == 0)
            userLinesToBeStarted++;
        else if(board[1] + board[2] == -1)
            userLinesToBeContinued++;
        /// Second line, 3-6-9
        if(board[6] + board[9] == 1)
            opponentLinesToBeBlocked++;
        else if(board[6] == 0 && board[9] == 0)
            userLinesToBeStarted++;
        else if(board[6] + board[9] == -1)
            userLinesToBeContinued++;
        /// Third line, 3-5-7
        if(board[5] + board[7] == 1)
            opponentLinesToBeBlocked++;
        else if(board[5] == 0 && board[7] == 0)
            userLinesToBeStarted++;
        else if(board[5] + board[7] == -1)
            userLinesToBeContinued++;
        /// Fourth line, 3-13-23
        if(board[13] + board[23] == 1)
            opponentLinesToBeBlocked++;
        else if(board[13] == 0 && board[23] == 0)
            userLinesToBeStarted++;
        else if(board[13] + board[23] == -1)
            userLinesToBeContinued++;
        /// Fifth line, 3-15-27
        if(board[15] + board[27] == 1)
            opponentLinesToBeBlocked++;
        else if(board[15] == 0 && board[27] == 0)
            userLinesToBeStarted++;
        else if(board[15] + board[27] == -1)
            userLinesToBeContinued++;
        /// Sixth line, 3-16-29
        if(board[16] + board[29] == 1)
            opponentLinesToBeBlocked++;
        else if(board[16] == 0 && board[29] == 0)
            userLinesToBeStarted++;
        else if(board[16] + board[29] == -1)
            userLinesToBeContinued++;
        /// Seventh line, 3-12-21
        if(board[12] + board[21] == 1)
            opponentLinesToBeBlocked++;
        else if(board[12] == 0 && board[21] == 0)
            userLinesToBeStarted++;
        else if(board[12] + board[21] == -1)
            userLinesToBeContinued++;
    return (userLinesToBeContinued * x) + (userLinesToBeStarted * z) + (opponentLinesToBeBlocked * y);
    case 4:
    if((board[1] == -1 && board[7] == -1) || (board[5] == -1 && board[6] == -1) || (board[14] == -1 && board[24] == -1) || (board[15] == -1 && board[26] == -1))
        return 100;
    if((board[1] == 1 && board[7] == 1) || (board[5] == 1 && board[6] == 1) || (board[14] == 1 && board[24] == 1) || (board[15] == 1 && board[26] == 1))
        return 50;
    /// First line, 1-4-7
    if(board[1] + board[7] == 1)
        opponentLinesToBeBlocked++;
    else if(board[1] == 0 && board[7] == 0)
        userLinesToBeStarted++;
    else if(board[1] + board[7] == -1)
        userLinesToBeContinued++;
    /// Second line, 4-5-6
    if(board[5] + board[6] == 1)
        opponentLinesToBeBlocked++;
    else if(board[5] == 0 && board[6] == 0)
        userLinesToBeStarted++;
    else if(board[5] + board[6] == -1)
        userLinesToBeContinued++;
    /// Third line, 4-14-24
    if(board[14] + board[24] == 1)
        opponentLinesToBeBlocked++;
    else if(board[14] == 0 && board[24] == 0)
        userLinesToBeStarted++;
    else if(board[14] + board[24] == -1)
        userLinesToBeContinued++;
    /// Fourth line, 4-15-26
    if(board[15] + board[26] == 1)
        opponentLinesToBeBlocked++;
    else if(board[15] == 0 && board[26] == 0)
        userLinesToBeStarted++;
    else if(board[15] + board[26] == -1)
        userLinesToBeContinued++;
    return (userLinesToBeContinued * x) + (userLinesToBeStarted * z) + (opponentLinesToBeBlocked * y);
    case 5:
    if((board[1] == -1 && board[9] == -1) ||(board[3] == -1 && board[7] == -1) || (board[2] == -1 && board[8] == -1)
       || (board[4] == -1 && board[6] == -1) || (board[15] == -1 && board[25] == -1))
       return 100;
    if((board[1] == 1 && board[9] == 1) ||(board[3] == 1 && board[7] == 1) || (board[2] == 1 && board[8] == 1)
       || (board[4] == 1 && board[6] == 1) || (board[15] == 1 && board[25] == 1))
       return 50;
    /// First lane, 1-5-9
    if(board[1] + board[9] == 1)
        opponentLinesToBeBlocked++;
    else if(board[1] == 0 && board[9] == 0)
        userLinesToBeStarted++;
    else if(board[1] + board[9] == -1)
        userLinesToBeContinued++;
    /// Second lane, 3-5-7
    if(board[3] + board[7] == 1)
        opponentLinesToBeBlocked++;
    else if(board[3] == 0 && board[7] == 0)
        userLinesToBeStarted++;
    else if(board[3] + board[7] == -1)
        userLinesToBeContinued++;
    /// Third lane, 2-5-8
    if(board[2] + board[8] == 1)
        opponentLinesToBeBlocked++;
    else if(board[2] == 0 && board[8] == 0)
        userLinesToBeStarted++;
    else if(board[2] + board[8] == -1)
        userLinesToBeContinued++;
    /// Fourth line, 4-5-6
    if(board[4] + board[6] == 1)
        opponentLinesToBeBlocked++;
    else if(board[4] == 0 && board[6] == 0)
        userLinesToBeStarted++;
    else if(board[4] + board[6] == -1)
        userLinesToBeContinued++;
    /// Fifth line, 5-15-25
    if(board[15] + board[25] == 1)
        opponentLinesToBeBlocked++;
    else if(board[15] == 0 && board[25] == 0)
        userLinesToBeStarted++;
    else if(board[15] + board[25] == -1)
        userLinesToBeContinued++;
    return (userLinesToBeContinued * x) + (userLinesToBeStarted * z) + (opponentLinesToBeBlocked * y);
    case 6:
    if((board[3] == -1 && board[9] == -1) || (board[4] == -1 && board[5] == -1) || (board[16] == -1 && board[26] == -1) || (board[15] == -1 && board[24] == -1))
        return 100;
    if((board[3] == 1 && board[9] == 1) || (board[4] == 1 && board[5] == 1) || (board[16] == 1 && board[26] == 1) || (board[15] == 1 && board[24] == 1))
        return 50;
    /// First lane, 3-6-9
    if(board[3] + board[9] == 1)
        opponentLinesToBeBlocked++;
    else if(board[3] == 0 && board[9] == 0)
        userLinesToBeStarted++;
    else if(board[3] + board[9] == -1)
        userLinesToBeContinued++;
    /// Second line, 4-5-6
    if(board[4] + board[5] == 1)
        opponentLinesToBeBlocked++;
    else if(board[4] == 0 && board[5] == 0)
        userLinesToBeStarted++;
    else if(board[4] + board[5] == -1)
        userLinesToBeContinued++;
    /// Third line, 6-16-26
    if(board[16] + board[26] == 1)
        opponentLinesToBeBlocked++;
    else if(board[16] == 0 && board[26] == 0)
        userLinesToBeStarted++;
    else if(board[16] + board[26] == -1)
        userLinesToBeContinued++;
    /// Fourth line, 6-15-24
    if(board[15] + board[24] == 1)
        opponentLinesToBeBlocked++;
    else if(board[15] == 0 && board[24] == 0)
        userLinesToBeStarted++;
    else if(board[15] + board[24] == -1)
        userLinesToBeContinued++;
    return (userLinesToBeContinued * x) + (userLinesToBeStarted * z) + (opponentLinesToBeBlocked * y);
    case 7:
    if((board[1] == -1 && board[4] == -1) || (board[3] == -1 && board[5] == -1) || (board[8] == -1 && board[9] == -1)
        || (board[17] == -1 && board[27] == -1) || (board[15] == -1 && board[23] == -1) || (board[14] == -1 && board[21] == -1)
        || (board[18] == -1 && board[29] == -1))
            return 100;
    if((board[1] == 1 && board[4] == 1) || (board[3] == 1 && board[5] == 1) || (board[8] == 1 && board[9] == 1)
        || (board[17] == 1 && board[27] == 1) || (board[15] == 1 && board[23] == 1) || (board[14] == 1 && board[21] == 1)
        || (board[18] == 1 && board[29] == 1))
            return 50;
    /// First line, 1-4-7
    if(board[1] + board[4] == 1)
        opponentLinesToBeBlocked++;
    else if(board[1] == 0 && board[4] == 0)
        userLinesToBeStarted++;
    else if(board[1] + board[4] == -1)
        userLinesToBeContinued++;
    /// Second line, 3-5-7
    if(board[3] + board[5] == 1)
        opponentLinesToBeBlocked++;
    else if(board[3] == 0 && board[5] == 0)
        userLinesToBeStarted++;
    else if(board[3] + board[5] == -1)
        userLinesToBeContinued++;
    /// Third line, 7-8-9
    if(board[8] + board[9] == 1)
        opponentLinesToBeBlocked++;
    else if(board[8] == 0 && board[9] == 0)
        userLinesToBeStarted++;
    else if(board[8] + board[9] == -1)
        userLinesToBeContinued++;
    /// Fourth line, 7-17-27
    if(board[17] + board[27] == 1)
        opponentLinesToBeBlocked++;
    else if(board[17] == 0 && board[27] == 0)
        userLinesToBeStarted++;
    else if(board[17] + board[27] == -1)
        userLinesToBeContinued++;
    /// Fifth line, 7-15-23
    if(board[15] + board[23] == 1)
        opponentLinesToBeBlocked++;
    else if(board[15] == 0 && board[23] == 0)
        userLinesToBeStarted++;
    else if(board[15] + board[23] == -1)
        userLinesToBeContinued++;
    /// Sixth line, 7-14-21
    if(board[14] + board[21] == 1)
        opponentLinesToBeBlocked++;
    else if(board[14] == 0 && board[21] == 0)
        userLinesToBeStarted++;
    else if(board[14] + board[21] == -1)
        userLinesToBeContinued++;
    /// Seventh line, 7-18-29
    if(board[18] + board[29] == 1)
        opponentLinesToBeBlocked++;
    else if(board[18] == 0 && board[29] == 0)
        userLinesToBeStarted++;
    else if(board[18] + board[29] == -1)
        userLinesToBeContinued++;
    return (userLinesToBeContinued * x) + (userLinesToBeStarted * z) + (opponentLinesToBeBlocked * y);
    case 8:
    if((board[2] == -1 && board[5] == -1) || (board[7] == -1 && board[9] == -1) || (board[15] == -1 && board[22] == -1) || (board[18] == -1 && board[28] == -1))
        return 100;
    if((board[2] == 1 && board[5] == 1) || (board[7] == 1 && board[9] == 1) || (board[15] == 1 && board[22] == 1) || (board[18] == 1 && board[28] == 1))
        return 50;
    /// First line 2-5-8
    if(board[2] + board[5] == 1)
        opponentLinesToBeBlocked++;
    else if(board[2] == 0 && board[5] == 0)
        userLinesToBeStarted++;
    else if(board[2] + board[5] == -1)
        userLinesToBeContinued++;
    /// Second line, 7-8-9
    if(board[7] + board[9] == 1)
        opponentLinesToBeBlocked++;
    else if(board[7] == 0 && board[9] == 0)
        userLinesToBeStarted++;
    else if(board[7] + board[9] == -1)
        userLinesToBeContinued++;
    /// Third line, 8-15-22
    if(board[15] + board[22] == 1)
        opponentLinesToBeBlocked++;
    else if(board[15] == 0 && board[22] == 0)
        userLinesToBeStarted++;
    else if(board[15] + board[22] == -1)
        userLinesToBeContinued++;
    /// Fourth line, 8-18-28
    if(board[18] + board[28] == 1)
        opponentLinesToBeBlocked++;
    else if(board[18] == 0 && board[28] == 0)
        userLinesToBeStarted++;
    else if(board[18] + board[28] == -1)
        userLinesToBeContinued++;
    return (userLinesToBeContinued * x) + (userLinesToBeStarted * z) + (opponentLinesToBeBlocked * y);
    case 9:
    if((board[1] == -1 && board[5] == -1) || (board[3] == -1 && board[6] == -1) || (board[7] == -1 && board[8] == -1)
        || (board[19] == -1 && board[29] == -1) || (board[15] == -1 && board[21] == -1) || (board[18] == -1 && board[27] == -1)
        || (board[16] == -1 && board[23] == -1))
        return 100;
    if((board[1] == 1 && board[5] == 1) || (board[3] == 1 && board[6] == 1) || (board[7] == 1 && board[8] == 1)
        || (board[19] == 1 && board[29] == 1) || (board[15] == 1 && board[21] == 1) || (board[18] == 1 && board[27] == 1)
        || (board[16] == 1 && board[23] == 1))
        return 50;
    /// First lane, 1-5-9
    if(board[1] + board[5] == 1)
        opponentLinesToBeBlocked++;
    else if(board[1] == 0 && board[5] == 0)
        userLinesToBeStarted++;
    else if(board[1] + board[5] == -1)
        userLinesToBeContinued++;
    /// Second line, 3-6-9
    if(board[3] + board[6] == 1)
        opponentLinesToBeBlocked++;
    else if(board[3] == 0 && board[6] == 0)
        userLinesToBeStarted++;
    else if(board[3] + board[6] == -1)
        userLinesToBeContinued++;
    /// Third line, 7-8-9
    if(board[7] + board[8] == 1)
        opponentLinesToBeBlocked++;
    else if(board[7] == 0 && board[8] == 0)
        userLinesToBeStarted++;
    else if(board[7] + board[8] == -1)
        userLinesToBeContinued++;
    /// Fourth line, 9-19-29
    if(board[19] + board[29] == 1)
        opponentLinesToBeBlocked++;
    else if(board[19] == 0 && board[29] == 0)
        userLinesToBeStarted++;
    else if(board[19] + board[29] == -1)
        userLinesToBeContinued++;
    /// Fifth line, 9-15-21
    if(board[15] + board[21] == 1)
        opponentLinesToBeBlocked++;
    else if(board[15] == 0 && board[21] == 0)
        userLinesToBeStarted++;
    else if(board[15] + board[21] == -1)
        userLinesToBeContinued++;
    /// Sixth line, 9-18-27
    if(board[18] + board[27] == 1)
        opponentLinesToBeBlocked++;
    else if(board[18] == 0 && board[27] == 0)
        userLinesToBeStarted++;
    else if(board[18] + board[27] == -1)
        userLinesToBeContinued++;
    /// Seventh line, 9-16-23
    if(board[16] + board[23] == 1)
        opponentLinesToBeBlocked++;
    else if(board[16] == 0 && board[23] == 0)
        userLinesToBeStarted++;
    else if(board[16] + board[23] == -1)
        userLinesToBeContinued++;
    return (userLinesToBeContinued * x) + (userLinesToBeStarted * z) + (opponentLinesToBeBlocked * y);

    /// Middle plane

    case 11:
    if((board[1] == -1 && board[21] == -1) || (board[12] == -1 && board[13] == -1) || (board[15] == -1 && board[19] == -1) || (board[14] == -1 && board[17] == -1))
            return 100;
    if((board[1] == 1 && board[21] == 1) || (board[12] == 1 && board[13] == 1) || (board[15] == 1 && board[19] == 1) || (board[14] == 1 && board[17] == 1))
            return 50;
    /// First line, 1-11-21
    if(board[1] + board[21] == 1)
        opponentLinesToBeBlocked++;
    else if(board[1] == 0 && board[21] == 0)
        userLinesToBeStarted++;
    else if(board[1] + board[21] == -1)
        userLinesToBeContinued++;
    /// Second line, 11-12-13
    if(board[12] + board[13] == 1)
        opponentLinesToBeBlocked++;
    else if(board[12] == 0 && board[13] == 0)
        userLinesToBeStarted++;
    else if(board[12] + board[13] == -1)
        userLinesToBeContinued++;
    /// Third line, 11-15-19
    if(board[15] + board[19] == 1)
        opponentLinesToBeBlocked++;
    else if(board[15] == 0 && board[19] == 0)
        userLinesToBeStarted++;
    else if(board[15] + board[19] == -1)
        userLinesToBeContinued++;
    /// Fourth line, 11-14-17
    if(board[14] + board[17] == 1)
        opponentLinesToBeBlocked++;
    else if(board[14] == 0 && board[17] == 0)
        userLinesToBeStarted++;
    else if(board[14] + board[17] == -1)
        userLinesToBeContinued++;
    return (userLinesToBeContinued * x) + (userLinesToBeStarted * z) + (opponentLinesToBeBlocked * y);
    case 12:
    if((board[11] == -1 && board[13] == -1) || (board[15] == -1 && board[18] == -1) || (board[2] == -1 && board[22] == -1)
        || (board[3] == -1 && board[21] == -1) || (board[12] == -1 && board[23] == -1))
        return 100;
    if((board[11] == 1 && board[13] == 1) || (board[15] == 1 && board[18] == 1) || (board[2] == 1 && board[22] == 1)
        || (board[3] == 1 && board[21] == 1) || (board[12] == 1 && board[23] == 1))
        return 50;
    /// First line, 11-12-13
    if(board[11] + board[13] == 1)
        opponentLinesToBeBlocked++;
    else if(board[11] == 0 && board[13] == 0)
        userLinesToBeStarted++;
    else if(board[11] + board[13] == -1)
        userLinesToBeContinued++;
    /// Second line, 12-15-18
    if(board[15] + board[18] == 1)
        opponentLinesToBeBlocked++;
    else if(board[15] == 0 && board[18] == 0)
        userLinesToBeStarted++;
    else if(board[15] + board[18] == -1)
        userLinesToBeContinued++;
    /// Third line, 2-12-22
    if(board[2] + board[22] == 1)
        opponentLinesToBeBlocked++;
    else if(board[2] == 0 && board[22] == 0)
        userLinesToBeStarted++;
    else if(board[2] + board[22] == -1)
        userLinesToBeContinued++;
    /// Fourth line, 3-12-21
    if(board[3] + board[21] == 1)
        opponentLinesToBeBlocked++;
    else if(board[3] == 0 && board[21] == 0)
        userLinesToBeStarted++;
    else if(board[3] + board[21] == -1)
        userLinesToBeContinued++;
    /// Fifth line, 1-12-23
    if(board[12] + board[23] == 1)
        opponentLinesToBeBlocked++;
    else if(board[12] == 0 && board[23] == 0)
        userLinesToBeStarted++;
    else if(board[12] + board[23] == -1)
        userLinesToBeContinued++;
    return (userLinesToBeContinued * x) + (userLinesToBeStarted * z) + (opponentLinesToBeBlocked * y);
    case 13:
    if((board[11] == -1 && board[12] == -1) || (board[16] == -1 && board[19] == -1) || (board[15] == -1 && board[17] == -1) || (board[3] == -1 && board[23] == -1))
        return 100;
    if((board[11] == 1 && board[12] == 1) || (board[16] == 1 && board[19] == 1) || (board[15] == 1 && board[17] == 1) || (board[3] == 1 && board[23] == 1))
        return 50;
    /// First lane, 11-12-13
    if(board[11] + board[12] == 1)
        opponentLinesToBeBlocked++;
    else if(board[11] == 0 && board[12] == 0)
        userLinesToBeStarted++;
    else if(board[11] + board[12] == -1)
        userLinesToBeContinued++;
    /// Second line, 13-16-19
    if(board[16] + board[19] == 1)
        opponentLinesToBeBlocked++;
    else if(board[16] == 0 && board[19] == 0)
        userLinesToBeStarted++;
    else if(board[16] + board[19] == -1)
        userLinesToBeContinued++;
   /// Third line, 13-15-17
   if(board[15] + board[17] == 1)
        opponentLinesToBeBlocked++;
    else if(board[15] == 0 && board[17] == 0)
        userLinesToBeStarted++;
    else if(board[15] + board[17] == -1)
        userLinesToBeContinued++;
    /// Fourth line, 3-13-23
    if(board[3] + board[23] == 1)
        opponentLinesToBeBlocked++;
    else if(board[3] == 0 && board[23] == 0)
        userLinesToBeStarted++;
    else if(board[3] + board[23] == -1)
        userLinesToBeContinued++;
    return (userLinesToBeContinued * x) + (userLinesToBeStarted * z) + (opponentLinesToBeBlocked * y);
    case 14:
    if((board[11] == -1 && board[17] == -1) || (board[15] == -1 && board[16] == -1)
      || (board[4] == -1 && board[24] == -1) || (board[1] == -1 && board[27] == -1) || (board[7] == -1 && board[21] == -1))
        return 100;
    if((board[11] == 1 && board[17] == 1) || (board[15] == 1 && board[16] == 1)
      || (board[4] == 1 && board[24] == 1) || (board[1] == 1 && board[27] == 1) || (board[7] == 1 && board[21] == 1))
      return 50;
    /// First line, 11-14-17
    if(board[11] + board[17] == 1)
        opponentLinesToBeBlocked++;
    else if(board[11] == 0 && board[17] == 0)
        userLinesToBeStarted++;
    else if(board[11] + board[17] == -1)
        userLinesToBeContinued++;
    /// Second line, 14-15-16
    if(board[15] + board[16] == 1)
        opponentLinesToBeBlocked++;
    else if(board[15] == 0 && board[16] == 0)
        userLinesToBeStarted++;
    else if(board[15] + board[16] == -1)
        userLinesToBeContinued++;
    /// Third line, 4-14-24
    if(board[4] + board[24] == 1)
        opponentLinesToBeBlocked++;
    else if(board[4] == 0 && board[24] == 0)
        userLinesToBeStarted++;
    else if(board[4] + board[24] == -1)
        userLinesToBeContinued++;
    ///  Fourth line, 1-14-27
    if(board[1] + board[27] == 1)
        opponentLinesToBeBlocked++;
    else if(board[1] == 0 && board[27] == 0)
        userLinesToBeStarted++;
    else if(board[1] + board[27] == -1)
        userLinesToBeContinued++;
    /// Fifth line, 7-14-21
    if(board[7] + board[21] == 1)
        opponentLinesToBeBlocked++;
    else if(board[7] == 0 && board[21] == 0)
        userLinesToBeStarted++;
    else if(board[7] + board[21] == -1)
        userLinesToBeContinued++;
    return (userLinesToBeContinued * x) + (userLinesToBeStarted * z) + (opponentLinesToBeBlocked * y);
    case 15:
    if((board[5] == -1 && board[25] == -1) || (board[14] == -1 && board[16] == -1) || (board[12] == -1 && board[18] == -1)
        || (board[1] == -1 && board[29] == -1) || (board[3] == -1 && board[27] == -1) || (board[7] == -1 && board[23] == -1)
        || (board[9] == -1 && board[21] == -1) || (board[11] == -1 && board[19] == -1) || (board[13] == -1 && board[17] == -1))
            return 100;
    if((board[5] == 1 && board[25] == 1) || (board[14] == 1 && board[16] == 1) || (board[12] == 1 && board[18] == 1)
        || (board[1] == 1 && board[29] == 1) || (board[3] == 1 && board[27] == 1) || (board[7] == 1 && board[23] == 1)
        || (board[9] == 1 && board[21] == 1) || (board[11] == 1 && board[19] == 1) || (board[13] == 1 && board[17] == 1))
        return 50;
    /// First line, 5-15-25
    if(board[5] + board[25] == 1)
        opponentLinesToBeBlocked++;
    else if(board[5] == 0 && board[25] == 0)
        userLinesToBeStarted++;
    else if(board[5] + board[25] == -1)
        userLinesToBeContinued++;
    /// Second line, 14-15-16
    if(board[14] + board[16] == 1)
        opponentLinesToBeBlocked++;
    else if(board[14] == 0 && board[16] == 0)
        userLinesToBeStarted++;
    else if(board[14] + board[16] == -1)
        userLinesToBeContinued++;
    /// Third line, 12-15-18
    if(board[12] + board[18] == 1)
        opponentLinesToBeBlocked++;
    else if(board[12] == 0 && board[18] == 0)
        userLinesToBeStarted++;
    else if(board[12] + board[18] == -1)
        userLinesToBeContinued++;
    /// Fourth line, 1-15-29
    if(board[1] + board[29] == 1)
        opponentLinesToBeBlocked++;
    else if(board[1] == 0 && board[29] == 0)
        userLinesToBeStarted++;
    else if(board[1] + board[29] == -1)
        userLinesToBeContinued++;
    /// Fifth line, 3-15-27
    if(board[3] + board[27] == 1)
        opponentLinesToBeBlocked++;
    else if(board[3] == 0 && board[27] == 0)
        userLinesToBeStarted++;
    else if(board[3] + board[27] == -1)
        userLinesToBeContinued++;
    /// Sixth line, 23-15-7
    if(board[7] + board[23] == 1)
        opponentLinesToBeBlocked++;
    else if(board[7] == 0 && board[23] == 0)
        userLinesToBeStarted++;
    else if(board[7] + board[23] == -1)
        userLinesToBeContinued++;
    /// Seventh line, 21-15-9
    if(board[9] + board[21] == 1)
        opponentLinesToBeBlocked++;
    else if(board[9] == 0 && board[21] == 0)
        userLinesToBeStarted++;
    else if(board[9] + board[21] == -1)
        userLinesToBeContinued++;
    /// Eights line, 11-15-19
    if(board[11] + board[19] == 1)
        opponentLinesToBeBlocked++;
    else if(board[11] == 0 && board[19] == 0)
        userLinesToBeStarted++;
    else if(board[11] + board[19] == -1)
        userLinesToBeContinued++;
    /// Ninth line, 13-15-17
    if(board[13] + board[17] == 1)
        opponentLinesToBeBlocked++;
    else if(board[13] == 0 && board[17] == 0)
        userLinesToBeStarted++;
    else if(board[13] + board[17] == -1)
        userLinesToBeContinued++;
    return (userLinesToBeContinued * x) + (userLinesToBeStarted * z) + (opponentLinesToBeBlocked * y);
    case 16:
    if((board[13] == -1 && board[19] == -1) || (board[14] == -1 && board[15] == -1) || (board[6] == -1 && board[26] == -1)
        || (board[3] == -1 && board[29] == -1) || (board[9] == -1 && board[23] == -1))
            return 100;
    if((board[13] == 1 && board[19] == 1) || (board[14] == 1 && board[15] == 1) || (board[6] == 1 && board[26] == 1)
        || (board[3] == 1 && board[29] == 1) || (board[9] == 1 && board[23] == 1))
        return 50;
    /// First line 13-16-19
    if(board[13] + board[19] == 1)
        opponentLinesToBeBlocked++;
    else if(board[13] == 0 && board[19] == 0)
        userLinesToBeStarted++;
    else if(board[13] + board[19] == -1)
        userLinesToBeContinued++;
    /// Second line 14-15-16
    if(board[14] + board[15] == 1)
        opponentLinesToBeBlocked++;
    else if(board[14] == 0 && board[15] == 0)
        userLinesToBeStarted++;
    else if(board[14] + board[15] == -1)
        userLinesToBeContinued++;
    /// Third line, 6-16-26
    if(board[6] + board[26] == 1)
        opponentLinesToBeBlocked++;
    else if(board[6] == 0 && board[26] == 0)
        userLinesToBeStarted++;
    else if(board[6] + board[26] == -1)
        userLinesToBeContinued++;
    /// Fourth line, 3-16-29
    if(board[3] + board[29] == 1)
        opponentLinesToBeBlocked++;
    else if(board[3] == 0 && board[29] == 0)
        userLinesToBeStarted++;
    else if(board[3] + board[29] == -1)
        userLinesToBeContinued++;
    /// Fifth line, 9-16-23
    if(board[9] + board[23] == 1)
        opponentLinesToBeBlocked++;
    else if(board[9] == 0 && board[23] == 0)
        userLinesToBeStarted++;
    else if(board[9] + board[23] == -1)
        userLinesToBeContinued++;
    return (userLinesToBeContinued * x) + (userLinesToBeStarted * z) + (opponentLinesToBeBlocked * y);
    case 17:
    if((board[11] == -1 && board[14] == -1) || (board[18] == -1 && board[19] == -1)
        || (board[13] == -1 && board[15] == -1) || (board[7] == -1 && board[27] == -1))
            return 100;
    if((board[11] == 1 && board[14] == 1) || (board[18] == 1 && board[19] == 1)
        || (board[13] == 1 && board[15] == 1) || (board[7] == 1 && board[27] == 1))
            return 50;
    /// First line, 11-14-17
    if(board[11] + board[14] == 1)
        opponentLinesToBeBlocked++;
    else if(board[11] == 0 && board[14] == 0)
        userLinesToBeStarted++;
    else if(board[11] + board[14] == -1)
        userLinesToBeContinued++;
    /// Second line, 17-18-19
    if(board[18] + board[19] == 1)
        opponentLinesToBeBlocked++;
    else if(board[18] == 0 && board[19] == 0)
        userLinesToBeStarted++;
    else if(board[18] + board[19] == -1)
        userLinesToBeContinued++;
    /// Third line, 13-15-17
    if(board[13] + board[15] == 1)
        opponentLinesToBeBlocked++;
    else if(board[13] == 0 && board[15] == 0)
        userLinesToBeStarted++;
    else if(board[13] + board[15] == -1)
        userLinesToBeContinued++;
    /// Fourth line, 7-17-27
    if(board[7] + board[27] == 1)
        opponentLinesToBeBlocked++;
    else if(board[7] == 0 && board[27] == 0)
        userLinesToBeStarted++;
    else if(board[7] + board[27] == -1)
        userLinesToBeContinued++;
    return (userLinesToBeContinued * x) + (userLinesToBeStarted * z) + (opponentLinesToBeBlocked * y);
    case 18:
    if((board[17] == -1 && board[19] == -1) || (board[8] == -1 && board[28] == -1) || (board[9] == -1 && board[27] == -1)
        || (board[12] == -1 && board[15] == -1) || (board[7] == -1 && board[29] == -1))
            return 100;
    if((board[17] == 1 && board[19] == 1) || (board[8] == 1 && board[28] == 1) || (board[9] == 1 && board[27] == 1)
        || (board[12] == 1 && board[15] == 1) || (board[7] == 1 && board[29] == 1))
            return 50;
    /// First line, 17-18-19
    if(board[17] + board[19] == 1)
        opponentLinesToBeBlocked++;
    else if(board[17] == 0 && board[19] == 0)
        userLinesToBeStarted++;
    else if(board[17] + board[19] == -1)
        userLinesToBeContinued++;
    /// Second line, 8-18-28
    if(board[8] + board[28] == 1)
        opponentLinesToBeBlocked++;
    else if(board[8] == 0 && board[28] == 0)
        userLinesToBeStarted++;
    else if(board[8] + board[28] == -1)
        userLinesToBeContinued++;
    /// Third line, 12-15-18
    if(board[12] + board[15] == 1)
        opponentLinesToBeBlocked++;
    else if(board[12] == 0 && board[15] == 0)
        userLinesToBeStarted++;
    else if(board[12] + board[15] == -1)
        userLinesToBeContinued++;
    /// Fourth line, 9-18-27
    if(board[9] + board[27] == 1)
        opponentLinesToBeBlocked++;
    else if(board[9] == 0 && board[27] == 0)
        userLinesToBeStarted++;
    else if(board[9] + board[27] == -1)
        userLinesToBeContinued++;
    /// Fifth line, 7-18-29
    if(board[7] + board[29] == 1)
        opponentLinesToBeBlocked++;
    else if(board[7] == 0 && board[29] == 0)
        userLinesToBeStarted++;
    else if(board[7] + board[29] == -1)
        userLinesToBeContinued++;
    return (userLinesToBeContinued * x) + (userLinesToBeStarted * z) + (opponentLinesToBeBlocked * y);
    case 19:
    if((board[17] == -1 && board[18] == -1) || (board[13] == -1 && board[16] == -1)
        || (board[11] == -1 && board[15] == -1) || (board[9] == -1 && board[29] == -1))
        return 100;
    if((board[17] == 1 && board[18] == 1) || (board[13] == 1 && board[16] == 1)
        || (board[11] == 1 && board[15] == 1) || (board[9] == 1 && board[29] == 1))
        return 50;
    /// First line, 17-18-19
    if(board[17] + board[18] == 1)
        opponentLinesToBeBlocked++;
    else if(board[17] == 0 && board[18] == 0)
        userLinesToBeStarted++;
    else if(board[17] + board[18] == -1)
        userLinesToBeContinued++;
    /// Second line, 13-16-19
    if(board[13] + board[16] == 1)
        opponentLinesToBeBlocked++;
    else if(board[13] == 0 && board[16] == 0)
        userLinesToBeStarted++;
    else if(board[13] + board[16] == -1)
        userLinesToBeContinued++;
    /// Third line, 11-15-19
    if(board[11] + board[15] == 1)
        opponentLinesToBeBlocked++;
    else if(board[11] == 0 && board[15] == 0)
        userLinesToBeStarted++;
    else if(board[11] + board[15] == -1)
        userLinesToBeContinued++;
    /// Fourth line, 9-19-29
    if(board[9] + board[29] == 1)
        opponentLinesToBeBlocked++;
    else if(board[9] == 0 && board[29] == 0)
        userLinesToBeStarted++;
    else if(board[9] + board[29] == -1)
        userLinesToBeContinued++;
    return (userLinesToBeContinued * x) + (userLinesToBeStarted * z) + (opponentLinesToBeBlocked * y);

    /// Bottom plane

    case 21:
    if((board[22] == -1 && board[23] == -1) || (board[24] == -1 && board[27] == -1) || (board[25] == -1 && board[29] == -1)
        || (board[1] == -1 && board[11] == -1) || (board[9] == -1 && board[15] == -1) || (board[7] == -1 && board[14] == -1)
        || (board[3] == -1 && board[12] == -1))
        return 100;
    if((board[22] == 1 && board[23] == 1) || (board[24] == 1 && board[27] == 1) || (board[25] == 1 && board[29] == 1)
        || (board[1] == 1 && board[11] == 1) || (board[9] == 1 && board[15] == 1) || (board[7] == 1 && board[14] == 1)
        || (board[3] == 1 && board[12] == 1))
        return 50;
    /// First line 21-22-23
    if(board[22] + board[23] == 1)
        opponentLinesToBeBlocked++;
    else if(board[22] == 0 && board[23] == 0)
        userLinesToBeStarted++;
    else if(board[22] + board[23] == -1)
        userLinesToBeContinued++;
    /// Second line, 21-24-27
    if(board[24] + board[27] == 1)
        opponentLinesToBeBlocked++;
    else if(board[24] == 0 && board[19] == 0)
        userLinesToBeStarted++;
    else if(board[24] + board[27] == -1)
        userLinesToBeContinued++;
    /// Third line, 21-25-29
    if(board[25] + board[29] == 1)
        opponentLinesToBeBlocked++;
    else if(board[25] == 0 && board[29] == 0)
        userLinesToBeStarted++;
    else if(board[25] + board[29] == -1)
        userLinesToBeContinued++;
    /// Fourth line, 1-11-21
    if(board[1] + board[11] == 1)
        opponentLinesToBeBlocked++;
    else if(board[1] == 0 && board[11] == 0)
        userLinesToBeStarted++;
    else if(board[1] + board[11] == -1)
        userLinesToBeContinued++;
    /// Fifth line, 21-15-9
    if(board[9] + board[15] == 1)
        opponentLinesToBeBlocked++;
    else if(board[9] == 0 && board[15] == 0)
        userLinesToBeStarted++;
    else if(board[9] + board[15] == -1)
        userLinesToBeContinued++;
    /// Sixth line, 21-14-7
    if(board[7] + board[14] == 1)
        opponentLinesToBeBlocked++;
    else if(board[7] == 0 && board[14] == 0)
        userLinesToBeStarted++;
    else if(board[7] + board[14] == -1)
        userLinesToBeContinued++;
    /// Seventh line, 21-12-3
    if(board[3] + board[12] == 1)
        opponentLinesToBeBlocked++;
    else if(board[3] == 0 && board[12] == 0)
        userLinesToBeStarted++;
    else if(board[3] + board[12] == -1)
        userLinesToBeContinued++;
    return (userLinesToBeContinued * x) + (userLinesToBeStarted * z) + (opponentLinesToBeBlocked * y);
    case 22:
    if((board[21] == -1 && board[23] == -1) || (board[25] == -1 && board[28] == -1)
        || (board[2] == -1 && board[12] == -1) || (board[15] == -1 && board[8] == -1))
        return 100;
    if((board[21] == 1 && board[23] == 1) || (board[25] == 1 && board[28] == 1)
        || (board[2] == 1 && board[12] == 1) || (board[15] == 1 && board[8] == 1))
        return 50;
    /// First line, 21-22-23
    if(board[21] + board[23] == 1)
        opponentLinesToBeBlocked++;
    else if(board[21] == 0 && board[23] == 0)
        userLinesToBeStarted++;
    else if(board[21] + board[23] == -1)
        userLinesToBeContinued++;
    /// Second line, 22-25-28
    if(board[25] + board[28] == 1)
        opponentLinesToBeBlocked++;
    else if(board[25] == 0 && board[28] == 0)
        userLinesToBeStarted++;
    else if(board[25] + board[28] == -1)
        userLinesToBeContinued++;
    /// Third line, 2-12-22
    if(board[2] + board[12] == 1)
        opponentLinesToBeBlocked++;
    else if(board[2] == 0 && board[12] == 0)
        userLinesToBeStarted++;
    else if(board[2] + board[12] == -1)
        userLinesToBeContinued++;
    /// Fourth lane, 22-15-8
    if(board[15] + board[8] == 1)
        opponentLinesToBeBlocked++;
    else if(board[15] == 0 && board[8] == 0)
        userLinesToBeStarted++;
    else if(board[15] + board[8] == -1)
        userLinesToBeContinued++;
    return (userLinesToBeContinued * x) + (userLinesToBeStarted * z) + (opponentLinesToBeBlocked * y);
    case 23:
    if((board[21] == -1 && board[22] == -1) || (board[26] == -1 && board[29] == -1) || (board[25] == -1 && board[27] == -1)
        || (board[3] == -1 && board[13] == -1) || (board[1] == -1 && board[12] == -1) || (board[9] == -1 && board[16] == -1)
        || (board[7] == -1 && board[15] == -1))
        return 100;
    if((board[21] == 1 && board[22] == 1) || (board[26] == 1 && board[29] == 1) || (board[25] == 1 && board[27] == 1)
        || (board[3] == 1 && board[13] == 1) || (board[1] == 1 && board[12] == 1) || (board[9] == 1 && board[16] == 1)
        || (board[7] == 1 && board[15] == 1))
        return 50;
    /// First line, 21-22-23
    if(board[21] + board[22] == 1)
        opponentLinesToBeBlocked++;
    else if(board[21] == 0 && board[22] == 0)
        userLinesToBeStarted++;
    else if(board[21] + board[22] == -1)
        userLinesToBeContinued++;
    /// Second line, 23-26-29
    if(board[26] + board[29] == 1)
        opponentLinesToBeBlocked++;
    else if(board[26] == 0 && board[29] == 0)
        userLinesToBeStarted++;
    else if(board[26] + board[29] == -1)
        userLinesToBeContinued++;
    /// Third line, 23-25-27
    if(board[25] + board[27] == 1)
        opponentLinesToBeBlocked++;
    else if(board[25] == 0 && board[27] == 0)
        userLinesToBeStarted++;
    else if(board[25] + board[27] == -1)
        userLinesToBeContinued++;
    /// Fourth line, 23-13-3
    if(board[3] + board[13] == 1)
        opponentLinesToBeBlocked++;
    else if(board[3] == 0 && board[13] == 0)
        userLinesToBeStarted++;
    else if(board[3] + board[13] == -1)
        userLinesToBeContinued++;
    /// Fifth lane, 1-12-23
    if(board[1] + board[12] == 1)
        opponentLinesToBeBlocked++;
    else if(board[1] == 0 && board[12] == 0)
        userLinesToBeStarted++;
    else if(board[1] + board[12] == -1)
        userLinesToBeContinued++;
    /// Sixth line, 9-16-23
    if(board[9] + board[16] == 1)
        opponentLinesToBeBlocked++;
    else if(board[9] == 0 && board[16] == 0)
        userLinesToBeStarted++;
    else if(board[9] + board[16] == -1)
        userLinesToBeContinued++;
    /// Seventh line, 23-15-7
    if(board[7] + board[15] == 1)
        opponentLinesToBeBlocked++;
    else if(board[7] == 0 && board[15] == 0)
        userLinesToBeStarted++;
    else if(board[7] + board[15] == -1)
        userLinesToBeContinued++;
    return (userLinesToBeContinued * x) + (userLinesToBeStarted * z) + (opponentLinesToBeBlocked * y);
    case 24:
    if((board[21] == -1 && board[27] == -1) || (board[25] == -1 && board[26] == -1)
        || (board[4] == -1 && board[14] == -1) || (board[6] == -1 && board[15] == -1))
        return 100;
    if((board[21] == 1 && board[27] == 1) || (board[25] == 1 && board[26] == 1)
        || (board[4] == 1 && board[14] == 1) || (board[6] == 1 && board[15] == 1))
        return 50;
    /// First line, 21-24-27
    if(board[21] + board[27] == 1)
        opponentLinesToBeBlocked++;
    else if(board[21] == 0 && board[27] == 0)
        userLinesToBeStarted++;
    else if(board[21] + board[27] == -1)
        userLinesToBeContinued++;
    /// Second line, 24-25-26
    if(board[25] + board[26] == 1)
        opponentLinesToBeBlocked++;
    else if(board[25] == 0 && board[26] == 0)
        userLinesToBeStarted++;
    else if(board[25] + board[26] == -1)
        userLinesToBeContinued++;
    /// Third line, 24-14-4
    if(board[4] + board[14] == 1)
        opponentLinesToBeBlocked++;
    else if(board[4] == 0 && board[14] == 0)
        userLinesToBeStarted++;
    else if(board[4] + board[14] == -1)
        userLinesToBeContinued++;
    /// Fourth line, 24-15-6
    if(board[6] + board[15] == 1)
        opponentLinesToBeBlocked++;
    else if(board[15] == 0 && board[6] == 0)
        userLinesToBeStarted++;
    else if(board[15] + board[6] == -1)
        userLinesToBeContinued++;
    return (userLinesToBeContinued * x) + (userLinesToBeStarted * z) + (opponentLinesToBeBlocked * y);
    case 25:
    if((board[22] == -1 && board[28] == -1) || (board[24] == -1 && board[26] == -1) || (board[21] == -1 && board[29] == -1)
        || (board[23] == -1 && board[27] == -1) || (board[5] == -1 && board[15] == -1))
            return 100;
    if((board[22] == 1 && board[28] == 1) || (board[24] == 1 && board[26] == 1) || (board[21] == 1 && board[29] == 1)
        || (board[23] == 1 && board[27] == 1) || (board[5] == 1 && board[15] == 1))
            return 50;
    /// First lane, 22-25-28
    if(board[22] + board[28] == 1)
        opponentLinesToBeBlocked++;
    else if(board[22] == 0 && board[28] == 0)
        userLinesToBeStarted++;
    else if(board[22] + board[28] == -1)
        userLinesToBeContinued++;
    /// Second line, 24-25-26
    if(board[24] + board[26] == 1)
        opponentLinesToBeBlocked++;
    else if(board[24] == 0 && board[26] == 0)
        userLinesToBeStarted++;
    else if(board[24] + board[26] == -1)
        userLinesToBeContinued++;
    /// Third lane, 21-25-29
    if(board[21] + board[29] == 1)
        opponentLinesToBeBlocked++;
    else if(board[21] == 0 && board[29] == 0)
        userLinesToBeStarted++;
    else if(board[21] + board[29] == -1)
        userLinesToBeContinued++;
    /// Fourth line, 23-25-27
    if(board[23] + board[27] == 1)
        opponentLinesToBeBlocked++;
    else if(board[23] == 0 && board[27] == 0)
        userLinesToBeStarted++;
    else if(board[23] + board[27] == -1)
        userLinesToBeContinued++;
    /// Fifth line, 25-15-5
    if(board[5] + board[15] == 1)
        opponentLinesToBeBlocked++;
    else if(board[5] == 0 && board[15] == 0)
        userLinesToBeStarted++;
    else if(board[5] + board[15] == -1)
        userLinesToBeContinued++;
    return (userLinesToBeContinued * x) + (userLinesToBeStarted * z) + (opponentLinesToBeBlocked * y);
    case 26:
    if((board[24] == -1 && board[25] == -1) || (board[23] == -1 && board[29] == -1)
        || (board[6] == -1 && board[16] == -1) || (board[4] == -1 && board[15] == -1))
        return 100;
    if((board[24] == 1 && board[25] == 1) || (board[23] == 1 && board[29] == 1)
        || (board[6] == 1 && board[16] == 1) || (board[4] == 1 && board[15] == 1))
        return 50;
    /// First line, 24-25-26
    if(board[24] + board[25] == 1)
        opponentLinesToBeBlocked++;
    else if(board[24] == 0 && board[25] == 0)
        userLinesToBeStarted++;
    else if(board[24] + board[25] == -1)
        userLinesToBeContinued++;
    /// Second lane, 23-26-29
    if(board[23] + board[29] == 1)
        opponentLinesToBeBlocked++;
    else if(board[23] == 0 && board[29] == 0)
        userLinesToBeStarted++;
    else if(board[23] + board[29] == -1)
        userLinesToBeContinued++;
    /// Third lane, 6-16-26
    if(board[6] + board[16] == 1)
        opponentLinesToBeBlocked++;
    else if(board[6] == 0 && board[16] == 0)
        userLinesToBeStarted++;
    else if(board[6] + board[16] == -1)
        userLinesToBeContinued++;
    /// Fourth line, 26-15-4
    if(board[4] + board[15] == 1)
        opponentLinesToBeBlocked++;
    else if(board[4] == 0 && board[15] == 0)
        userLinesToBeStarted++;
    else if(board[4] + board[15] == -1)
        userLinesToBeContinued++;
    return (userLinesToBeContinued * x) + (userLinesToBeStarted * z) + (opponentLinesToBeBlocked * y);
    case 27:
    if((board[21] == -1 && board[24] == -1) || (board[28] == -1 && board[29] == -1) || (board[23] == -1 && board[25] == -1)
        || (board[7] == -1 && board[17] == -1) || (board[3] == -1 && board[15] == -1)
        || (board[1] == -1 && board[14] == -1) || (board[9] == -1 && board[18] == -1))
        return 100;
    if((board[21] == 1 && board[24] == 1) || (board[28] == 1 && board[29] == 1) || (board[23] == 1 && board[25] == 1)
        || (board[7] == 1 && board[17] == 1) || (board[3] == 1 && board[15] == 1)
        || (board[1] == 1 && board[14] == 1) || (board[9] == 1 && board[18] == 1))
        return 50;
    /// First line, 21-24-27
    if(board[21] + board[24] == 1)
        opponentLinesToBeBlocked++;
    else if(board[21] == 0 && board[24] == 0)
        userLinesToBeStarted++;
    else if(board[21] + board[24] == -1)
        userLinesToBeContinued++;
    /// Second line, 27-28-29
    if(board[28] + board[29] == 1)
        opponentLinesToBeBlocked++;
    else if(board[28] == 0 && board[29] == 0)
        userLinesToBeStarted++;
    else if(board[28] + board[29] == -1)
        userLinesToBeContinued++;
    /// Third line, 23-25-27
    if(board[23] + board[25] == 1)
        opponentLinesToBeBlocked++;
    else if(board[23] == 0 && board[25] == 0)
        userLinesToBeStarted++;
    else if(board[23] + board[25] == -1)
        userLinesToBeContinued++;
    /// Fourth lane, 27-17-7
    if(board[7] + board[17] == 1)
        opponentLinesToBeBlocked++;
    else if(board[7] == 0 && board[17] == 0)
        userLinesToBeStarted++;
    else if(board[7] + board[17] == -1)
       userLinesToBeContinued++;
   /// Fifth line, 27-15-3
    if(board[3] + board[15] == 1)
        opponentLinesToBeBlocked++;
    else if(board[3] == 0 && board[15] == 0)
        userLinesToBeStarted++;
    else if(board[3] + board[15] == -1)
        userLinesToBeContinued++;
    /// Sixth line, 27-14-1
    if(board[1] + board[14] == 1)
        opponentLinesToBeBlocked++;
    else if(board[1] == 0 && board[14] == 0)
        userLinesToBeStarted++;
    else if(board[1] + board[14] == -1)
        userLinesToBeContinued++;
    /// Seventh line, 27-18-9
    if(board[9] + board[18] == 1)
        opponentLinesToBeBlocked++;
    else if(board[9] == 0 && board[18] == 0)
        userLinesToBeStarted++;
    else if(board[9] + board[18] == -1)
        userLinesToBeContinued++;
    return (userLinesToBeContinued * x) + (userLinesToBeStarted * z) + (opponentLinesToBeBlocked * y);
    case 28:
    if((board[27] == -1 && board[29] == -1) || (board[22] == -1 && board[25] == -1)
        || (board[8] == -1 && board[18] == -1) || (board[2] == -1 && board[15] == -1))
        return 100;
    if((board[27] == 1 && board[29] == 1) || (board[22] == 1 && board[25] == 1)
        || (board[8] == 1 && board[18] == 1) || (board[2] == 1 && board[15] == 1))
        return 50;
    /// First line, 27-28-29
    if(board[27] + board[29] == 1)
        opponentLinesToBeBlocked++;
    else if(board[27] == 0 && board[29] == 0)
        userLinesToBeStarted++;
    else if(board[27] + board[29] == -1)
        userLinesToBeContinued++;
    /// Second line, 22-25-28
    if(board[22] + board[25] == 1)
        opponentLinesToBeBlocked++;
    else if(board[22] == 0 && board[25] == 0)
        userLinesToBeStarted++;
    else if(board[22] + board[25] == -1)
        userLinesToBeContinued++;
    /// Third line, 28-18-8
    if(board[8] + board[18] == 1)
        opponentLinesToBeBlocked++;
    else if(board[8] == 0 && board[18] == 0)
        userLinesToBeStarted++;
    else if(board[8] + board[18] == -1)
        userLinesToBeContinued++;
    /// Fourth line, 28-15-2
    if(board[2] + board[15] == 1)
        opponentLinesToBeBlocked++;
    else if(board[2] == 0 && board[15] == 0)
        userLinesToBeStarted++;
    else if(board[2] + board[15] == -1)
        userLinesToBeContinued++;
    return (userLinesToBeContinued * x) + (userLinesToBeStarted * z) + (opponentLinesToBeBlocked * y);
    case 29:
    if((board[27] == -1 && board[28] == -1) || (board[23] == -1 && board[26] == -1) || (board[21] == -1 && board[25] == -1)
        || (board[9] == -1 && board[19] == -1) || (board[3] == -1 && board[16] == -1)
        || (board[7] == -1 && board[18] == -1) || (board[1] == -1 && board[15] == -1))
        return 100;
    if((board[27] == 1 && board[28] == 1) || (board[23] == 1 && board[26] == 1) || (board[21] == 1 && board[25] == 1)
        || (board[9] == 1 && board[19] == 1) || (board[3] == 1 && board[16] == 1)
        || (board[7] == 1 && board[18] == 1) || (board[1] == 1 && board[15] == 1))
        return 50;
    /// First line, 27-28-29
    if(board[27] + board[28] == 1)
        opponentLinesToBeBlocked++;
    else if(board[27] == 0 && board[28] == 0)
        userLinesToBeStarted++;
    else if(board[27] + board[28] == -1)
        userLinesToBeContinued++;
    /// Second line, 23-26-29
    if(board[23] + board[26] == 1)
        opponentLinesToBeBlocked++;
    else if(board[23] == 0 && board[26] == 0)
        userLinesToBeStarted++;
    else if(board[23] + board[26] == -1)
        userLinesToBeContinued++;
    /// Third line, 21-25-29
    if(board[21] + board[25] == 1)
        opponentLinesToBeBlocked++;
    else if(board[21] == 0 && board[25] == 0)
        userLinesToBeStarted++;
    else if(board[21] + board[25] == -1)
        userLinesToBeContinued++;
    /// Fourth line, 29-19-9
    if(board[9] + board[19] == 1)
        opponentLinesToBeBlocked++;
    else if(board[9] == 0 && board[19] == 0)
        userLinesToBeStarted++;
    else if(board[9] + board[19] == -1)
        userLinesToBeContinued++;
   /// Fifth line, 29-16-3
   if(board[3] + board[16] == 1)
        opponentLinesToBeBlocked++;
    else if(board[3] == 0 && board[16] == 0)
        userLinesToBeStarted++;
    else if(board[3] + board[16] == -1)
        userLinesToBeContinued++;
    /// Sixth line, 29-18-7
    if(board[7] + board[18] == 1)
        opponentLinesToBeBlocked++;
    else if(board[7] == 0 && board[18] == 0)
        userLinesToBeStarted++;
    else if(board[7] + board[18] == -1)
        userLinesToBeContinued++;
    /// Seventh line, 29-15-1
    if(board[1] + board[15] == 1)
        opponentLinesToBeBlocked++;
    else if(board[1] == 0 && board[15] == 0)
        userLinesToBeStarted++;
    else if(board[1] + board[15] == -1)
        userLinesToBeContinued++;
    return (userLinesToBeContinued * x) + (userLinesToBeStarted * z) + (opponentLinesToBeBlocked * y);
    }
}

/// Returns -1 if algo win || 1 if user win || 0 if draw || 2 if still possibility of turn
int checkIfGameEnded(vector<int> board)
{
    /// Iterate each line for 3 symbols in row.
    /// Check if there is no empty cells
    if(board[1] + board[2] + board[3] == -3)
        return -1;
    else if(board[1] + board[2] + board[3] == 3)
        return 1;
    if(board[4] + board[5] + board[6] == -3)
        return -1;
    else if(board[4] + board[5] + board[6] == 3)
        return 1;
    if(board[7] + board[8] + board[9] == -3)
        return -1;
    else if(board[7] + board[8] + board[9] == 3)
        return 1;
    if(board[1] + board[4] + board[7] == -3)
        return -1;
    else if(board[1] + board[4] + board[7] == 3)
        return 1;
    if(board[2] + board[5] + board[8] == -3)
        return -1;
    else if(board[2] + board[5] + board[8] == 3)
        return 1;
    if(board[3] + board[6] + board[9] == -3)
        return -1;
    else if(board[3] + board[6] + board[9] == 3)
        return 1;
    if(board[1] + board[5] + board[9] == -3)
        return -1;
    else if(board[1] + board[5] + board[9] == 3)
        return 1;
    if(board[3] + board[5] + board[7] == -3)
        return -1;
    else if(board[3] + board[5] + board[7] == 3)
        return 1;
    if(board[1] + board[15] + board[29] == -3)
        return -1;
    else if(board[1] + board[15] + board[29] == 3)
        return 1;
    if(board[1] + board[11] + board[21] == -3)
        return -1;
    else if(board[1] + board[11] + board[21] == 3)
        return 1;
    if(board[1] + board[12] + board[23] == -3)
        return -1;
    else if(board[1] + board[12] + board[23] == 3)
        return 1;
    if(board[1] + board[14] + board[27] == -3)
        return -1;
    else if(board[1] + board[14] + board[27] == 3)
        return 1;
    if(board[2] + board[12] + board[22] == -3)
        return -1;
    else if(board[2] + board[12] + board[22] == 3)
        return 1;
    if(board[2] + board[15] + board[28] == -3)
        return -1;
    else if(board[2] + board[15] + board[28] == 3)
        return 1;
    if(board[3] + board[13] + board[23] == -3)
        return -1;
    else if(board[3] + board[13] + board[23] == 3)
        return 1;
    if(board[3] + board[15] + board[27] == -3)
        return -1;
    else if(board[3] + board[15] + board[27] == 3)
        return 1;
    if(board[3] + board[16] + board[29] == -3)
        return -1;
    else if(board[3] + board[16] + board[29] == 3)
        return 1;
    if(board[3] + board[12] + board[21] == -3)
        return -1;
    else if(board[3] + board[12] + board[21] == 3)
        return 1;
    if(board[4] + board[14] + board[24] == -3)
        return -1;
    else if(board[4] + board[14] + board[24] == 3)
        return 1;
    if(board[4] + board[15] + board[26] == -3)
        return -1;
    else if(board[4] + board[15] + board[26] == 3)
        return 1;
    if(board[5] + board[15] + board[25] == -3)
        return -1;
    else if(board[5] + board[15] + board[25] == 3)
        return 1;
    if(board[6] + board[16] + board[26] == -3)
        return -1;
    else if(board[6] + board[16] + board[26] == 3)
        return 1;
    if(board[6] + board[15] + board[24] == -3)
        return -1;
    else if(board[6] + board[15] + board[24] == 3)
        return 1;
    if(board[7] + board[17] + board[27] == -3)
        return -1;
    else if(board[7] + board[17] + board[27] == 3)
        return 1;
    if(board[7] + board[15] + board[23] == -3)
        return -1;
    else if(board[7] + board[15] + board[23] == 3)
        return 1;
    if(board[7] + board[14] + board[21] == -3)
        return -1;
    else if(board[7] + board[14] + board[21] == 3)
        return 1;
    if(board[7] + board[18] + board[29] == -3)
        return -1;
    else if(board[7] + board[18] + board[29] == 3)
        return 1;
    if(board[8] + board[15] + board[22] == -3)
        return -1;
    else if(board[8] + board[15] + board[22] == 3)
        return 1;
    if(board[8] + board[18] + board[28] == -3)
        return -1;
    else if(board[8] + board[18] + board[28] == 3)
        return 1;
    if(board[9] + board[19] + board[29] == -3)
        return -1;
    else if(board[9] + board[19] + board[29] == 3)
        return 1;
    if(board[9] + board[15] + board[21] == -3)
        return -1;
    else if(board[9] + board[15] + board[21] == 3)
        return 1;
    if(board[9] + board[18] + board[27] == -3)
        return -1;
    else if(board[9] + board[18] + board[27] == 3)
        return 1;
    if(board[9] + board[16] + board[23] == -3)
        return -1;
    else if(board[9] + board[16] + board[23] == 3)
        return 1;
    if(board[11] + board[12] + board[13] == -3)
        return -1;
    else if(board[11] + board[12] + board[13] == 3)
        return 1;
    if(board[11] + board[15] + board[19] == -3)
        return -1;
    else if(board[11] + board[15] + board[19] == 3)
        return 1;
    if(board[11] + board[14] + board[17] == -3)
        return -1;
    else if(board[11] + board[14] + board[17] == 3)
        return 1;
    if(board[12] + board[15] + board[18] == -3)
        return -1;
    else if(board[12] + board[15] + board[18] == 3)
        return 1;
    if(board[13] + board[16] + board[19] == -3)
        return -1;
    else if(board[13] + board[16] + board[19] == 3)
        return 1;
    if(board[13] + board[15] + board[17] == -3)
        return -1;
    else if(board[13] + board[15] + board[17] == 3)
        return 1;
    if(board[14] + board[15] + board[16] == -3)
        return -1;
    else if(board[14] + board[15] + board[16] == 3)
        return 1;
    if(board[17] + board[18] + board[19] == -3)
        return -1;
    else if(board[17] + board[18] + board[19] == 3)
        return 1;
    if(board[21] + board[22] + board[23] == -3)
        return -1;
    else if(board[21] + board[22] + board[23] == 3)
        return 1;
    if(board[21] + board[24] + board[27] == -3)
        return -1;
    else if(board[21] + board[24] + board[27] == 3)
        return 1;
    if(board[21] + board[25] + board[29] == -3)
        return -1;
    else if(board[21] + board[25] + board[29] == 3)
        return 1;
    if(board[22] + board[25] + board[28] == -3)
        return -1;
    else if(board[22] + board[25] + board[28] == 3)
        return 1;
    if(board[23] + board[26] + board[29] == -3)
        return -1;
    else if(board[23] + board[26] + board[29] == 3)
        return 1;
    if(board[23] + board[25] + board[27] == -3)
        return -1;
    else if(board[23] + board[25] + board[27] == 3)
        return 1;
    if(board[24] + board[25] + board[26] == -3)
        return -1;
    else if(board[24] + board[25] + board[26] == 3)
        return 1;
    if(board[27] + board[28] + board[29] == -3)
        return -1;
    else if(board[27] + board[28] + board[29] == 3)
        return 1;
    for(int i = 1; i < board.size(); i++)
        if(board[i] == 0)
        return 2;
return 0;
}

void printNumbersForTheBoard(vector<int> board){
    int counter = 1;
    for(int i = 1; i < 4; i++)
        cout << board[i] << " ";
    cout << endl;
    for(int i = 4; i < 7; i++)
        cout << board[i] << " ";
    cout << endl;
    for(int i = 7; i < 10; i++)
        cout << board[i] << " ";
    cout << endl << endl << endl;
    for(int i = 11; i < 14; i++)
        cout << board[i] << " ";
    cout << endl;
    for(int i = 14; i < 17; i++)
        cout << board[i] << " ";
    cout << endl;
    for(int i = 17; i < 20; i++)
        cout << board[i] << " ";
    cout << endl << endl << endl;
    for(int i = 21; i < 24; i++)
        cout << board[i] << " ";
    cout << endl;
    for(int i = 24; i < 27; i++)
        cout << board[i] << " ";
    cout << endl;
    for(int i = 27; i < 30; i++)
        cout << board[i] << " ";
    cout << endl;

}

void printBoardNormal(vector<int> board){
    //board[7] = 1;
    //board[8] = 1;
    //board[9] = -1;
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


void game(){
    vector<int> board = InitializeVector();
    bool whosTurnToMove = false; /// false => algoritms turn to move && true => user time to move
    while(checkIfGameEnded(board) == 2){
        if(!whosTurnToMove){
            vector<int> decisionVector = GetDecisionVector(board);
            int theBestMove = 0;
            for(int i = 1; i < decisionVector.size(); i++){
                if(decisionVector[i] > decisionVector[theBestMove]){
                    theBestMove = i;
                }
            }
            board[theBestMove] = -1;
            //if(theBestMove == 100)
              //  break;
            whosTurnToMove = true;
        }
        else{
            /// User logic of move
            /// Get int pos, check if possible and move
            int number;
            while(true){
                cout << endl << "Where you want to move?";
                cin >> number;
                if(number >= 1 && number < 30 && number%10 != 0 && board[number] == 0){
                    board[number] = 1;
                    whosTurnToMove = false;
                    break;
                }
                else{
                    cout << endl << "Incorect position, please, try again!";
                    Sleep(1500);
                    system("cls");
                    //printNumbersForTheBoard(board);
                    printBoardNormal(board);
                }
            }

        }
        system("cls");
        //printNumbersForTheBoard(board);
        printBoardNormal(board);
        switch(checkIfGameEnded(board)){
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



int main()
{
game();
return 0;
}
