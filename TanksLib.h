//=================================================================================================================
//{ Info
//=================================================================================================================
//!
//! @file    TanksLib.h
//! @brief   Библиотека функций танка
//!
//!          $Version: 0.5.9$
//!          $Date: 2018-03-22 20:42:74 +0500 $
//!
//!          Библиотека TanksLibrary есть набор функций, необходимых для работы программы
//!          В основе работы стоит библиотека TXLibrary, созданная Ильёй Дединским
//!
//! @warning <b>Это бета-версия. Для использования требуется согласование с автором библиотеки.</b> @nn
//!
//!
//-----------------------------------------------------------------------------------------------------------------
//!
//! @defgroup Drawing   Рисование
//! @defgroup Interface Интерфейс
//! @defgroup Logic     Логика
//}
//=================================================================================================================

//-----------------------------------------------------------------------------------------------------------------
//{     The Includes
//-----------------------------------------------------------------------------------------------------------------

    #include "TXLib.h"
    #include <fstream>
    #include <string>
    #include <sstream>
    #include <cmath>

//}
//-----------------------------------------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------------------------------------
//{     The Namespaces
//-----------------------------------------------------------------------------

    using namespace std;
//}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//{     TanksLib INTERFACE
//      Интерфейс библиотеки
//-----------------------------------------------------------------------------------------------------------------
//=================================================================================================================
//{          Drawing
//! @name    Рисование фигур
//=================================================================================================================
//! @{

//{----------------------------------------------------------------------------------------------------------------
/*!
    @ingroup Drawing

    @brief   Отрисовка карты
             Рисует карту, основываясь на структуре mapMas[][]

    @param   xOfCenter X-координата центра карты
    @param   yOfCenter Y-координата центра карты
    @param   mapSize   Размер карты
    @param   mapDat1   Количество строк
    @param   mapDat2   количество столбцо

    @see     mapMas[][]

    @usage @code
            drawMap(500, 300, 10, 6, 6);
    @endcode
*/
//}----------------------------------------------------------------------------------------------------------------
    void drawMap(int xOfCenter, int yOfCenter, double mapSize, int mapDat1, int mapDat2);
    void drawWelcome(int xWindowSize, int yWindowSize);
    void drawGTHOH(int xWindowSize,int yWindowSize);
    void drawMapInit(int xWindowSize, int yWindowSize);
    void drawMapSaveFound(int xWindowSize, int yWindowSize);
    void drawMapGlowTank(tank t, int xOfCenter, int yOfCenter, double mapSize, int mapDat1, int mapDat2);
    void drawMapLoad(int xWindowSize, int yWindowSize);
    void drawTank(tank t, int xOfCenter, int yOfCenter, double mapSize, int mapDat1, int mapDat2);
    void drawKekovuyTank(int x, int y, double k, int pozition, COLORREF tankColour);
    void drawDefinitionChoose(int* xWindowSize, int* yWindowSize);
    void drawTankStat(tank t[], int tankAmount, int xWindowSize, int yWindowSize, int turn);
    void drawTankMovementGlow(bool a, int x, int y, int xOfCenter, int yOfCenter, double mapSize, int mapDat1, int mapDat2);
    void drawTankAttackGlow(int x, int y, int xOfCenter, int yOfCenter, double mapSize, int mapDat1, int mapDat2);
    void drawNewTurn(int number, int timeTurnChange, int xWindowSize, int yWindowSize);
    void drawButtonAddPerk(int xCenter, int yCenter, int radius, COLORREF fillColor, COLORREF crossColor, int thickness);
    void drawMenu(int XWINDOWSIZE, int YWINDOWSIZE);
    void drawButtonForMenuExit(int XCENTER, int YCENTER, int RADIUS, COLORREF FILLCOLOR, COLORREF CROSSCOLOR);
    void drawButtonForMenuStartGame(int XCENTER, int YCENTER, COLORREF COLOR, bool notStartButContinue);
    void drawButtonForMenuMapRedactor(int XCENTER, int YCENTER, COLORREF COLOR, bool comingSoon=false);
    void drawHP(int x,int y, double k);
    void drawAvailablePlaceToStart(int distanceOfStart, int xOfCenter, int yOfCenter, double mapSize, int mapDat1, int mapDat2);
    void drawMapGlowAvailable(int x, int y, int xOfCenter, int yOfCenter, double mapSize, int mapDat1, int mapDat2);
    void drawBoom(tank t, int xOfCenter, int yOfCenter, double mapSize, int mapDat1, int mapDat2, int* boomCd);
//! @}
//}
//=================================================================================================================
//}
//=================================================================================================================

    int mapMas[1000][1000];

    struct tank{
        int x,
            y,
            statHealth,
            statHealthMax,
            statAttack,
            statSpeed,
            statSpeedMax,
            statAim,
            distributionPoints,
            position,
            deathTime;

        COLORREF color;

        bool clicked,
             attacked;
    };



    template<typename T>
    string toString(T value)
    {
        std:ostringstream oss;
        oss<<value;
        return oss.str();
    }

    //logic



    void mapInitializer(bool sav, int* mapDat1, int* mapDat2);
    bool correctMapChecker(bool onlyCheck, int mapDat1, int mapDat2);
    bool checkThisPoint(int n);
    bool mapSavedChecker();
    void mapBoundController(int* xOfCenter, int* yOfCenter, int mapDat1, int mapDat2, double mapSize, int xWindowSize, int yWindowSize);
    void tankMovementAvailability(int n, int spd, bool turn, int xOfCenter, int yOfCenter, int mapDat1, int mapDat2, double mapSize, tank* t, bool a, int tankAmount);
    void toMasOfChar(string s, char* c);

    //interface
    void interfaceOfMap(double* mapSize, int* xOfCenter, int* yOfCenter);
    void interfaceTankMoveCheck(tank t[], int xOfCenter, int yOfCenter, double mapSize, int mapDat1, int mapDat2, int tankAmount, int* timeMouseTankIgnore, int* timeMouseTankAttackIgnore, int turn, int* boomed);
    void donotshootitisme(tank t[],int tankAmount,int xOfCenter, int yOfCenter, double mapSize, int mapDat1, int mapDat2, int tankNumber, int* boomCd, int* boomed);
    bool secretFunction(int* ss);
    bool windowSizeChooseAndConfirmation(int* xWindowSize, int* yWindowSize);
    void changeResolution(int* xWindowSize, int* yWindowSize);
    void mouseklikswhatcansupportustomovetank(tank* t, int xOfCenter, int yOfCenter, double mapSize, int mapDat1, int mapDat2, int* timeMouseTankMoveIgnore, int* timeMouseTankIgnore);
    void buttonEndTurn(int xWindowSize, int yWindowSize, int* timeMouseNewTurnIgnore, bool* turnChange);
    void buttonEndGame(int xWindowSize, int yWindowSize, bool* menuIn);
    void buttonsAddPerk(int xWindowSize, int yWindowSize, tank* t, int tankAmount, int tankNumber, bool* mainButtonClicked, int* timeMouseButtonAddPerkIgnore);
    bool ultimateCircleButtonInterface(int xCenter, int yCenter, int radius);
    bool interfaceMenuButtons(int xWindowSize, int yWindowSize, bool* menuIn);
    bool chooseStart(int distanceOfStart, tank* t, int xOfCenter, int yOfCenter, double mapSize, int mapDat1, int mapDat2);

    //drawing
