#include "Dot.h"
#include "Common.h"



Dot::Dot()
{
}

Dot::~Dot()
{
}

void Dot::kirby(short posX, short posY)
{
    _kirby = {
        {0,0,12,12,12,0,0},
        {0,12,0,12,0,12,0},
        {0,12,0,12,0,12,0},
        {0,12,12,12,12,12,0},
        {6,4,4,6,4,4,6},
        {6,6,6,6,6,6,6},
        {0,6,6,0,6,6,0}
    };

    for (unsigned int i = 0; i < _kirby.size(); i++)
    {
        COORD Position = { SHORT(posX - 1), SHORT(posY - 1 + i) };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Position);

        for (unsigned int j = 0; j < _kirby[i].size(); j++)
        {
            int colorNum = _kirby[i][j];

            if (colorNum > 16 || colorNum < 0)
            {
                TextColor(7, 0);
            }
            else
            {
                TextColor(colorNum, colorNum);
            }
            cout << "け";
        }
        TextColor(7, 0);
    }
}

void Dot::kirbyHit(short posX, short posY)
{
    _kirbyHit = {
        {0,0,7,7,7,0,0},
        {0,7,7,7,7,7,0},
        {0,7,7,7,7,7,0},
        {0,7,7,7,7,7,0},
        {7,7,7,7,7,7,7},
        {7,7,7,7,7,7,7},
        {0,7,7,0,7,7,0}
    };

    for (unsigned int i = 0; i < _kirbyHit.size(); i++)
    {
        COORD Position = { SHORT(posX - 1), SHORT(posY - 1 + i) };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Position);

        for (unsigned int j = 0; j < _kirbyHit[i].size(); j++)
        {
            int colorNum = _kirbyHit[i][j];

            if (colorNum > 16 || colorNum < 0)
            {
                TextColor(7, 0);
            }
            else
            {
                TextColor(colorNum, colorNum);
            }
            cout << "け";
        }
        TextColor(7, 0);
    }
}

void Dot::KirbyStageSelect(short posX, short posY)
{
    _kirbyStageSelect = {
        {12,12,12,12,12},
        {12,0,12,0,12},
        {12,0,12,0,12},
        {12,12,12,12,12},
        {12,12,12,12,12}
    };

    for (unsigned int i = 0; i < _kirbyStageSelect.size(); i++)
    {
        cursorXY(posX, posY + i);
        for (unsigned int j = 0; j < _kirbyStageSelect[i].size(); j++)
        {
            int colorNum = _kirbyStageSelect[i][j];

            if (colorNum > 16 || colorNum < 0)
            {
                TextColor(7, 0);
            }
            else
            {
                TextColor(colorNum, colorNum);
            }
            cout << "け";
        }
        TextColor(7, 0);
    }
}


void Dot::WaddleDee(short posX, short posY)
{
    _waddleDee = {
        {0,4,4,4,0},
        {4,0,14,0,4},
        {4,0,14,0,4},
        {12,14,14,14,12},
        {0,4,4,4,0},
        {6,6,0,6,6}
    };

    for (unsigned int i = 0; i < _waddleDee.size(); i++)
    {
        cursorXY(posX, posY + i);
        for (unsigned int j = 0; j < _waddleDee[i].size(); j++)
        {
            int colorNum = _waddleDee[i][j];

            if (colorNum > 16 || colorNum < 0)
            {
                TextColor(7, 0);
            }
            else
            {
                TextColor(colorNum, colorNum);
            }
            cout << "け";
        }
        TextColor(7, 0);
    }
}
void Dot::WaddleDeeHit(short posX, short posY)
{
    _waddleDeeHit = {
        {0,7,7,7,0},
        {7,7,7,7,7},
        {7,7,7,7,7},
        {7,7,7,7,7},
        {0,7,7,7,0},
        {7,7,0,7,7}
    };

    for (unsigned int i = 0; i < _waddleDeeHit.size(); i++)
    {
        cursorXY(posX, posY + i);
        for (unsigned int j = 0; j < _waddleDeeHit[i].size(); j++)
        {
            int colorNum = _waddleDeeHit[i][j];

            if (colorNum > 16 || colorNum < 0)
            {
                TextColor(7, 0);
            }
            else
            {
                TextColor(colorNum, colorNum);
            }
            cout << "け";
        }
        TextColor(7, 0);
    }
}


void Dot::Daroach(short posX, short posY)
{
    _daroach = {
        {0,0,7,7,0,0,0,7,7,7,7,0},
        {0,7,7,12,12,12,7,7,8,8,7,0},
        {12,7,7,12,12,7,7,8,8,8,8,7},
        {12,12,7,12,12,7,7,12,8,8,8,7},
        {12,12,4,12,12,12,12,12,8,8,7,0},
        {6,12,12,4,4,4,6,7,7,7,0,0},
        {6,12,6,12,12,0,6,7,7,0,0,0},
        {7,7,6,12,12,6,7,7,4,4,0,0},
        {7,7,4,7,7,7,7,4,4,4,0,0},
        {7,7,4,0,6,6,4,4,4,0,0,0},
        {0,4,4,12,12,12,12,12,12,0,0,0},
        {0,4,4,12,12,12,12,12,12,12,12,0},
        {0,0,7,12,12,12,4,12,12,12,12,12},
        {0,7,7,12,0,12,12,4,7,7,12,12},
        {0,0,0,0,0,0,12,12,7,7,7,0},
    };
    for (unsigned int i = 0; i < _daroach.size(); i++)
    {
        cursorXY(posX, posY + i);
        for (unsigned int j = 0; j < _daroach[i].size(); j++)
        {
            int colorNum = _daroach[i][j];

            if (colorNum > 16 || colorNum < 0)
            {
                TextColor(7, 0);
            }
            else
            {
                TextColor(colorNum, colorNum);
            }
            cout << "け";
        }
        TextColor(7, 0);
    }
}
void Dot::DaroachHit(short posX, short posY)
{
    _daroachHit = {
        {0,0,7,7,0,0,0,7,7,7,7,0},
        {0,7,7,7,7,7,7,7,7,7,7,0},
        {7,7,7,7,7,7,7,7,7,7,7,7},
        {7,7,7,7,7,7,7,7,7,7,7,7},
        {7,7,7,7,7,7,7,7,7,7,7,0},
        {7,7,7,7,7,7,7,7,7,7,0,0},
        {7,7,7,7,7,7,7,7,7,0,0,0},
        {7,7,7,7,7,7,7,7,7,7,0,0},
        {7,7,7,7,7,7,7,7,7,7,0,0},
        {7,7,7,7,7,7,7,7,7,0,0,0},
        {0,7,7,7,7,7,7,7,7,0,0,0},
        {0,7,7,7,7,7,7,7,7,7,7,0},
        {0,0,7,7,7,7,7,7,7,7,7,7},
        {0,7,7,7,0,7,7,7,7,7,7,7},
        {0,0,0,0,0,0,7,7,7,7,7,0}
    };
    for (unsigned int i = 0; i < _daroachHit.size(); i++)
    {
        cursorXY(posX, posY + i);
        for (unsigned int j = 0; j < _daroachHit[i].size(); j++)
        {
            int colorNum = _daroachHit[i][j];

            if (colorNum > 16 || colorNum < 0)
            {
                TextColor(7, 0);
            }
            else
            {
                TextColor(colorNum, colorNum);
            }
            cout << "け";
        }
        TextColor(7, 0);
    }
}


void Dot::MetaKnight(short posX, short posY)
{
    // 0, 1, 3, 4, 5, 6, 7, 8, 13
    _metaKnight = {
        {0,0,0,0,0,8,8,8,8,8,0,0,8,8,8,8,0,0},
        {0,0,0,8,8,1,4,1,8,0,0,0,0,8,1,4,8,0},
        {0,0,8,4,4,1,4,1,4,8,0,0,0,8,4,1,4,8},
        {0,8,4,4,1,4,4,1,4,8,0,0,8,6,4,1,4,8},
        {8,4,4,1,4,4,4,8,7,7,3,3,6,6,4,1,4,8},
        {8,4,0,0,6,7,8,8,8,7,7,3,6,6,7,8,0,0},
        {0,0,0,0,6,6,0,8,8,7,0,7,6,0,7,7,8,0},
        {0,0,0,0,0,1,0,6,0,6,0,7,1,0,0,7,8,0},
        {0,0,0,6,7,7,8,0,0,0,7,7,1,0,0,0,0,0},
        {0,0,6,4,7,7,8,8,7,7,7,1,8,0,0,0,0,0},
        {0,6,6,6,6,0,0,8,13,13,1,5,8,0,0,0,0,0},
        {6,6,6,0,0,0,0,0,13,13,5,5,8,0,0,0,0,0},
        {6,6,0,0,0,0,0,0,0,13,5,5,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0},
    };

    for (unsigned int i = 0; i < _metaKnight.size(); i++)
    {
        cursorXY(posX, posY + i);
        for (unsigned int j = 0; j < _metaKnight[i].size(); j++)
        {
            int colorNum = _metaKnight[i][j];

            if (colorNum > 16 || colorNum < 0)
            {
                TextColor(7, 0);
            }
            else
            {
                TextColor(colorNum, colorNum);
            }
            cout << "け";
        }
        TextColor(7, 0);
    }
}
void Dot::MetaKnightHit(short posX, short posY)
{
    _metaKnightHit = {
        {0,0,0,0,0,7,7,7,7,7,0,0,7,7,7,7,0,0},
        {0,0,0,7,7,7,7,7,7,0,0,0,0,7,7,7,7,0},
        {0,0,7,7,7,7,7,7,7,7,0,0,0,7,7,7,7,7},
        {0,7,7,7,7,7,7,7,7,7,0,0,7,7,7,7,7,7},
        {7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7},
        {7,7,0,0,7,7,7,7,7,7,7,7,7,7,7,7,0,0},
        {0,0,0,0,7,7,7,7,7,7,7,7,7,0,7,7,7,0},
        {0,0,0,0,0,7,7,7,7,7,7,7,7,0,0,7,7,0},
        {0,0,0,7,7,7,7,7,7,7,7,7,7,0,0,0,0,0},
        {0,0,7,7,7,7,7,7,7,7,7,7,7,0,0,0,0,0},
        {0,7,7,7,7,0,0,7,7,7,7,7,7,0,0,0,0,0},
        {7,7,7,0,0,0,0,0,7,7,7,7,7,0,0,0,0,0},
        {7,7,0,0,0,0,0,0,0,7,7,7,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0},
    };

    for (unsigned int i = 0; i < _metaKnightHit.size(); i++)
    {
        cursorXY(posX, posY + i);
        for (unsigned int j = 0; j < _metaKnightHit[i].size(); j++)
        {
            int colorNum = _metaKnightHit[i][j];

            if (colorNum > 16 || colorNum < 0)
            {
                TextColor(7, 0);
            }
            else
            {
                TextColor(colorNum, colorNum);
            }
            cout << "け";
        }
        TextColor(7, 0);
    }
}


void Dot::Life(short posX, short posY)
{
    _life = {
        {0,4,0,4,0},
        {4,7,4,4,4},
        {4,4,4,4,4},
        {0,4,4,4,0},
        {0,0,4,0,0}
    };

    for (unsigned int i = 0; i < _life.size(); i++)
    {
        cursorXY(posX, posY + i);
        for (unsigned int j = 0; j < _life[i].size(); j++)
        {
            int colorNum = _life[i][j];

            if (colorNum > 16 || colorNum < 0)
            {
                TextColor(7, 0);
            }
            else
            {
                TextColor(colorNum, colorNum);
            }
            cout << "け";
        }
        TextColor(7, 0);
    }
}

void Dot::LifeDec(short posX, short posY)
{
    _lifeDec = {
        {0,8,0,8,0},
        {8,7,8,8,8},
        {8,8,8,8,8},
        {0,8,8,8,0},
        {0,0,8,0,0}
    };

    for (unsigned int i = 0; i < _lifeDec.size(); i++)
    {
        cursorXY(posX, posY + i);
        for (unsigned int j = 0; j < _lifeDec[i].size(); j++)
        {
            int colorNum = _lifeDec[i][j];

            if (colorNum > 16 || colorNum < 0)
            {
                TextColor(7, 0);
            }
            else
            {
                TextColor(colorNum, colorNum);
            }
            cout << "け";
        }
        TextColor(7, 0);
    }
}

void Dot::HPUp(short posX, short posY)
{
}

void Dot::AtkSpeedUp(short posX, short posY)
{
}

void Dot::AtkPowerUp(short posX, short posY)
{
}