//#include <stdio.h>
#include <string.h>
#include <stdbool.h>

const char *ANotation[] = {
        "a8","b8","c8","d8","e8","f8","g8","h8",
        "a7","b7","c7","d7","e7","f7","g7","h7",
        "a6","b6","c6","d6","e6","f6","g6","h6",
        "a5","b5","c5","d5","e5","f5","g5","h5",
        "a4","b4","c4","d4","e4","f4","g4","h4",
        "a3","b3","c3","d3","e3","f3","g3","h3",
        "a2","b2","c2","d2","e2","f2","g2","h2",
        "a1","b1","c1","d1","e1","f1","g1","h1"
};

unsigned int Cboard[64];

int getCBPosition(const char *pieceAN);
int genericRule(const char *currentAN, const char *newAN);
int white_pawn(const char *currentAN, const char *newAN);
int black_pawn(const char *currentAN, const char *newAN);

int rules(const char *currentAN, const char *newAN) {
    if (!genericRule(currentAN, newAN))
        return 0;

    int currentChessBPosition = getCBPosition(currentAN);

    if (Cboard[currentChessBPosition] > 16 && Cboard[currentChessBPosition] < 25)
        if (!white_pawn(currentAN, newAN))
            return 0;

    if (Cboard[currentChessBPosition] > 8 && Cboard[currentChessBPosition] < 17)
        if (!black_pawn(currentAN, newAN))
            return 0;

    return 1;
}

int getCBPosition(const char *pieceAN) {
    for (int pos = 0; pos < 64; ++pos)
        if (strcmp(ANotation[pos], pieceAN) == 0)
            return pos;
    return 0;
}

int genericRule(const char *currentAN, const char *newAN) {
    if (strcmp(currentAN, newAN) == 0) {
        //printf("ERROR GENERIC RULE CODE 001");
        return 0;
    }
    return 1;
}

int white_pawn(const char *currentAN, const char *newAN) {
    bool walkTwoHouses = false;
    if (currentAN[1] == '2')
        walkTwoHouses = true;

    int currentPosInt = currentAN[1] - '0';
    int newPosInt = newAN[1] - '0';

    if (walkTwoHouses) {
        if (newAN[1] != '3' && newAN[1] != '4') {
            //printf("ERROR WHITE PAWN CODE 001");
            return 0;
        }
    }
    else {
        if (newPosInt > (currentPosInt + 1)) {
            //printf("ERROR WHITE PAWN CODE 002");
            return 0;
        }
    }

    int newANChessBPosition = getCBPosition(newAN);

    if (newAN[0] != currentAN[0]) {
        if (Cboard[newANChessBPosition] > 17) {
            //printf("ERROR WHITE PAWN CODE 003");
            return 0;
        }

        if (Cboard[newANChessBPosition] == 0) {
            //printf("ERROR WHITE PAWN CODE 004");
            return 0;
        }
    }

    if (newPosInt < currentPosInt) {
        //printf("ERROR WHITE PAWN CODE 005");
        return 0;
    }

    return 1;
}

int black_pawn(const char *currentAN, const char *newAN) {
    bool walkTwoHouses = false;
    if (currentAN[1] == '7')
        walkTwoHouses = true;

    int currentPosInt = currentAN[1] - '0';
    int newPosInt = newAN[1] - '0';

    if (walkTwoHouses) {
        if (newAN[1] != '6' && newAN[1] != '5') {
            //printf("ERROR BLACK PAWN CODE 001");
            return 1;
        }
    }
    else {
        if (newPosInt > (currentPosInt - 1)) {
            //printf("ERROR BLACK PAWN CODE 002");
            return 1;
        }
    }

    int newANChessBPosition = getCBPosition(newAN);

    if (newAN[0] != currentAN[0]) {
        if (Cboard[newANChessBPosition] < 17) {
            //printf("ERROR BLACK PAWN CODE 003");
            return 1;
        }
    }

    if (newPosInt > currentPosInt) {
        //printf("ERROR BLACK PAWN CODE 005");
        return 1;
    }

    return 0;
}