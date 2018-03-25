//=================================================================================================================
//{ Info
//=================================================================================================================
//!
//! @file    TanksLib.h
//! @brief   ���������� ������� ������� "Tanks Offline"
//!
//!          $Version: 0.5.9$
//!          $Date: 2018-03-22 20:42:74 +0500 $
//!
//!          ���������� TanksLibrary �������� � ���� �������, ����������� ��� ������ �������.
//!          � ������� ������������ ���������� TXLibrary, ��������� ����� ���������
//!
//! @warning <b>��� ����-������. ��� ������������� ��������� ������������ � ������� ����������.</b> @nn
//!
//!
//-----------------------------------------------------------------------------------------------------------------
//!
//! @defgroup Drawing   ���������
//! @defgroup Interface ���������
//! @defgroup Logic     ������
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
//      ��������� ����������
//-----------------------------------------------------------------------------------------------------------------
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
//=================================================================================================================
//{          Drawing
//! @name    ���������
//=================================================================================================================
//! @{

//{----------------------------------------------------------------------------------------------------------------
/*!
    @ingroup Drawing
    @brief   ��������� �����
             ������ �����, ����������� �� ��������� mapMas[][]
    @param   xOfCenter X-���������� ������ �����
    @param   yOfCenter Y-���������� ������ �����
    @param   mapSize   ������ �����
    @param   mapDat1   ���������� �����
    @param   mapDat2   ���������� ��������
    @see     mapMas[][]
    @usage @code
            drawMap(500, 300, 10, 6, 6);
    @endcode
*/
//}----------------------------------------------------------------------------------------------------------------
    void drawMap(int xOfCenter, int yOfCenter, double mapSize, int mapDat1, int mapDat2);

//{----------------------------------------------------------------------------------------------------------------
/*!
    @ingroup Drawing
    @brief   ��������� ������ �����������
    @param   xWindowSize ������ ���� �� X
    @param   yWindowSize ������ ���� �� Y
    @usage @code
             drawWelcome(800, 600);
    @endcode
*/
//}----------------------------------------------------------------------------------------------------------------
    void drawWelcome(int xWindowSize, int yWindowSize);

//{----------------------------------------------------------------------------------------------------------------
/*!
    @ingroup Drawing
    @brief   ��������� ������ ��������
             Get the hell outta here!
    @param   xWindowSize ������ ���� �� X
    @param   yWindowSize ������ ���� �� Y
    @usage @code
             drawGTHOH(800, 600);
    @endcode
*/
//}----------------------------------------------------------------------------------------------------------------
    void drawGTHOH(int xWindowSize,int yWindowSize);

//{----------------------------------------------------------------------------------------------------------------
/*!
    @ingroup Drawing
    @brief   ��������� ������ ������������� �����
    @param   xWindowSize ������ ���� �� X
    @param   yWindowSize ������ ���� �� Y
    @usage @code
             drawMapInit(800, 600);
    @endcode
*/
//}----------------------------------------------------------------------------------------------------------------
    void drawMapInit(int xWindowSize, int yWindowSize);

//{----------------------------------------------------------------------------------------------------------------
/*!
    @ingroup Drawing
    @brief   ������ ��������������, ������������ ��� ���������� ����� ���������� �����
    @param   xWindowSize ������ ���� �� X
    @param   yWindowSize ������ ���� �� Y
    @warning ���� � �������� ���� ��������� ������ �����, ������, � ��� ���� ���� ���������� � ����� ����;
             ����� ��������� ���, ���������� ������ Y; ����� ��������������� ���, ���������� ������ N
    @see     mapInitializer(), mapSavedChecker()
    @usage @code
             drawMapSaveFound(800, 600);
    @endcode
*/
//}----------------------------------------------------------------------------------------------------------------
    void drawMapSaveFound(int xWindowSize, int yWindowSize);

//{----------------------------------------------------------------------------------------------------------------
/*!
    @ingroup Drawing
    @brief   ��������� �������� ��������������� �����

    @param   t         ������ ��������� tank
    @param   xOfCenter X-���������� ������ �����
    @param   yOfCenter Y-���������� ������ �����
    @param   mapSize   ������ �����
    @param   mapDat1   ���������� �����
    @param   mapDat2   ���������� ��������

    @see     tank, interfaceTankMoveCheck()
    @usage @code
             tank t;
             t.x=1;
             t.y=2;
             drawMapGlowTank(t, 300, 400, 10, 6, 6);
    @endcode
*/
//}----------------------------------------------------------------------------------------------------------------
    void drawMapGlowTank(tank t, int xOfCenter, int yOfCenter, double mapSize, int mapDat1, int mapDat2);

//{----------------------------------------------------------------------------------------------------------------
/*!
    @ingroup Drawing
    @brief   ��������� ������ �������� �����
    @param   xWindowSize ������ ���� �� X
    @param   yWindowSize ������ ���� �� Y
    @usage @code
             drawMapLoad(800, 600);
    @endcode
*/
//}----------------------------------------------------------------------------------------------------------------
    void drawMapLoad(int xWindowSize, int yWindowSize);

//{----------------------------------------------------------------------------------------------------------------
/*!
    @ingroup Drawing
    @brief   ������ ���� �� �����-������
    @param   t         ������ ��������� tank
    @param   xOfCenter X-���������� ������ �����
    @param   yOfCenter Y-���������� ������ �����
    @param   mapSize   ������ �����
    @param   mapDat1   ���������� �����
    @param   mapDat2   ���������� ��������
    @warning <b>��������!</b> ���� ���� ����� ���������� ������������ ��� �������������� �� �����. ������ ������� ������������ <b>�������������</b> � ��������������� ��������� � <b>�������������</b> � ���������� ������ ����������
    @usage @code
             tank t;
             t.x=1;
             t.y=2;
             drawTank(t, 300, 400, 10, 6, 6);
    @endcode
*/
//}----------------------------------------------------------------------------------------------------------------
    void drawTank(tank t, int xOfCenter, int yOfCenter, double mapSize, int mapDat1, int mapDat2);

//{----------------------------------------------------------------------------------------------------------------
/*!
    @ingroup Drawing

    @brief   ������ ����

    @param   x          X-���������� ������ �����
    @param   y          Y-���������� ������ �����
    @param   k          ������ �����
    @param   pozition   ������� ����� (� ����� ������� �� �������)
    @param   tankColour ���� �����

    @warning <b>��������!</b>  k= <i>������</i> �����, <b>��</b> <i>�������</i> (<big>�</big> <ins>������<ins> <del>��������</del> <sub>�</sub> <code>������</code> <dfn>������<dfn> <b>HTML<b>)

    @usage @code
             drawKekovuyTank(600, 600, 100, 1, TX_PINK);
    @endcode
*/
//}----------------------------------------------------------------------------------------------------------------
    void drawKekovuyTank(int x, int y, double k, int pozition, COLORREF tankColour);

//{----------------------------------------------------------------------------------------------------------------
/*!
    @ingroup Drawing
    @brief   ������ ���� ������ ���������� ������
    @param   *xWindowSize ��������� �� ������ ���� �� X
    @param   *yWindowSize ��������� �� ������ ���� �� Y
    @see     changeResolution()
    @usage @code
             int xWindowSize,
                 yWindowSize;
             drawDefinitionChoose(&xWindowSize, &yWindowSize);
    @endcode
*/
//}----------------------------------------------------------------------------------------------------------------
    void drawDefinitionChoose(int* xWindowSize, int* yWindowSize);

//{----------------------------------------------------------------------------------------------------------------
/*!
    @ingroup Drawing
    @brief   ��������� ������ ���������� ���� ������
             �������� ������� ����������, ����� ��� drawHP(), drawAttack(), etc.
    @param   t[]         ������ ��������� tank
    @param   tankAmount  ���������� ������
    @param   xWindowSize ������ ���� �� X
    @param   yWindowSize ������ ���� �� Y
    @param   turn        ���������� ���� (��� ������ ���)
    @see     tank, drawHP(), drawAttack()
    @usage @code
             int tankAmount = 2;
             tank t[tankAmount];
             for (i=0;i<tankAmount;i++) //���������� ���� ���������� ������, �������� ��������� tank
             {
                ...
             }
             for (i=0;i<tankAmount;i++)
             {
                drawTankStat(t, tankAmount, 800, 600, i);
                txSleep(1000);
             }
    @endcode
*/
//}----------------------------------------------------------------------------------------------------------------
    void drawTankStat(tank t[], int tankAmount, int xWindowSize, int yWindowSize, int turn);

//{----------------------------------------------------------------------------------------------------------------
/*!
    @ingroup Drawing
    @brief   ������������ ������ � ������� ���� � ������� ��������� ����� ������� � ������ ���
    @param   a           ��� a=1 ������������ �������, ����� �����
    @param   x           ���������� X ������
    @param   y           ���������� Y ������
    @param   xOfCenter   X-���������� ������ �����
    @param   yOfCenter   Y-���������� ������ �����
    @param   mapSize     ������ �����
    @param   mapDat1     ���������� �����
    @param   mapDat2     ���������� ��������
    @usage @code
             tank t;
             t.x=0;
             t.y=0;
             drawTankMovementGlow(1, t.x, t.y, 300, 400, 10, 10, 10);
    @endcode
*/
//}----------------------------------------------------------------------------------------------------------------
    void drawTankMovementGlow(bool a, int x, int y, int xOfCenter, int yOfCenter, double mapSize, int mapDat1, int mapDat2);

//{----------------------------------------------------------------------------------------------------------------
/*!
    @ingroup Drawing
    @brief   ������������ ����� � ������� ���� � ������� ���������� ����� ����� ������� � ������ ���
    @param   x           ���������� X ������
    @param   y           ���������� Y ������
    @param   xOfCenter   X-���������� ������ �����
    @param   yOfCenter   Y-���������� ������ �����
    @param   mapSize     ������ �����
    @param   mapDat1     ���������� �����
    @param   mapDat2     ���������� ��������
    @usage @code
             tank t;
             t.x=0;
             t.y=0;
             drawTankAttackGlow(1, t.x, t.y, 300, 400, 10, 10, 10);
    @endcode
*/
//}----------------------------------------------------------------------------------------------------------------
    void drawTankAttackGlow(int x, int y, int xOfCenter, int yOfCenter, double mapSize, int mapDat1, int mapDat2);

//{----------------------------------------------------------------------------------------------------------------
/*!
    @ingroup Drawing
    @brief   ������������ ����� � ������� ���� � ������� ���������� ����� ����� ������� � ������ ���
    @param   number             �����, ������������, ��� ������ ���
    @param   timeTurnChange     ��������� ����� (�������, �� ������ ������), ����� ������, ���������� �� ����� ����, ��������������(����� �������� ��������� ��������� ����)
    @param   xWindowSize        ������ ���� �� X
    @param   yWindowSize        ������ ���� �� Y
    @usage @code
             int ttc=40;
             while (ttc>0)
             {
                drawNewTurn(0, ttc--, 800, 600);
             }
    @endcode
*/
//}----------------------------------------------------------------------------------------------------------------
    void drawNewTurn(int number, int timeTurnChange, int xWindowSize, int yWindowSize);

//{----------------------------------------------------------------------------------------------------------------
/*!
    @ingroup Drawing
    @brief   ������ ������ ���������� �� ���������� ������ � ������
    @param   xCenter            ���������� �� x �������� ������
    @param   yCenter            ���������� �� y �������� ������
    @param   radius             ������ ������
    @param   fillColor          ���� ���������� ������� ����� ������
    @param   crossColor         ���� ���������� �������� (�� �����, �������) ������
    @param   thickness          ������� ������� ������
    @usage @code
             drawButtonAddPerk(400, 300, 50, TX_GREY, TW_WHITE, 5);
    @endcode
*/
//}----------------------------------------------------------------------------------------------------------------
    void drawButtonAddPerk(int xCenter, int yCenter, int radius, COLORREF fillColor, COLORREF crossColor, int thickness);

//{----------------------------------------------------------------------------------------------------------------
/*!
    @ingroup Drawing
    @brief   ������ ������ ����
    @param   XWINDOWSIZE    ������ ���� �� x
    @param   YWINDOWSIZE    ������ ���� �� y
    @usage @code
             drawMenu(800, 600);
    @endcode
*/
//}----------------------------------------------------------------------------------------------------------------
    void drawMenu(int XWINDOWSIZE, int YWINDOWSIZE);

//{----------------------------------------------------------------------------------------------------------------
/*!
    @ingroup Drawing
    @brief   ������ ������ ���������� �� ����� �� ����
    @param   xCenter            ���������� �� x �������� ������
    @param   yCenter            ���������� �� y �������� ������
    @param   radius             ������ ������
    @param   fillColor          ���� ���������� ������� ����� ������
    @param   crossColor         ���� ���������� ���������� ����� ������
    @usage @code
             drawButtonForMenuExit(400, 300, 40, TX_GREY, TX_WHITE);
    @endcode
*/
//}----------------------------------------------------------------------------------------------------------------
    void drawButtonForMenuExit(int XCENTER, int YCENTER, int RADIUS, COLORREF FILLCOLOR, COLORREF CROSSCOLOR);

//{----------------------------------------------------------------------------------------------------------------
/*!
    @ingroup Drawing
    @brief   ������ ������ "������ ����"
             �������� �� ���������������� ������� "���������� ����", ���� ��� ��������� ����� � ����
    @param   xCenter             ���������� �� x �������� ������
    @param   yCenter             ���������� �� y �������� ������
    @param   Color               ���� ���������� ������
    @param   notStartButContinue ��� �������� 1 ������ ������ "���������� ����", � ��������� ������ ������ "������ ����"
    @usage @code
             drawButtonForMenuStartGame(400, 300, TX_BLUE, true);
   @endcode
*/
//}----------------------------------------------------------------------------------------------------------------
    void drawButtonForMenuStartGame(int XCENTER, int YCENTER, COLORREF COLOR, bool notStartButContinue);

//{----------------------------------------------------------------------------------------------------------------
/*!
    @ingroup Drawing
    @brief   ������ ������ ���������� �� ���� � ����� ��������� ����
    @param   xCenter             ���������� �� x �������� ������
    @param   yCenter             ���������� �� y �������� ������
    @param   Color               ���� ���������� ������
    @param   comingSoon          ��� �������� 1 ����� ����������� ������, ��� ��� �� �������� ������ ������ ������ �� �������Ĩ�
    @usage @code
             drawButtonForMenuMapRedactor(400, 300, TX_RED, true);
    @endcode
*/
//}----------------------------------------------------------------------------------------------------------------
    void drawButtonForMenuMapRedactor(int XCENTER, int YCENTER, COLORREF COLOR, bool comingSoon=false);

//{----------------------------------------------------------------------------------------------------------------
/*!
    @ingroup Drawing
    @brief   ������ ������ - �������� ��� ����������� HP �����
             �������-"�����������"
    @param   x             ���������� �� x �������� ������
    @param   y             ���������� �� y �������� ������
    @param   k             ������ ������

    @usage @code
             drawHP(200, 200, 80);
    @endcode
*/
//}----------------------------------------------------------------------------------------------------------------
    void drawHP(int x,int y, double k);

//{----------------------------------------------------------------------------------------------------------------
/*!
    @ingroup Drawing
    @brief   ������ ���������� ���� - �������� ��� ����������� ����� ��������� �����
             �������-"�����������"
    @param   x             ���������� �� x �������� ������
    @param   y             ���������� �� y �������� ������
    @param   k             ������ ������

    @warning ��, �� �����, ��� ������ �� ����� ���
             �� ������ ������ ����� <sup>���� ���� ���� ����� ��������</sup>

    @usage @code
             drawAttack(200, 200, 80);
    @endcode
*/
//}----------------------------------------------------------------------------------------------------------------
    void drawAttack(int x,int y, double k);

//{----------------------------------------------------------------------------------------------------------------
/*!
    @ingroup Drawing
    @brief   ������������ ������, � ������� ����� ��������� ����
    @param   distanceOfStart  ����������� ����������, �� ������� ����� ���� ����������� �����
    @param   xOfCenter        X-���������� ������ �����
    @param   yOfCenter        Y-���������� ������ �����
    @param   mapSize          ������ �����
    @param   mapDat1          ���������� �����
    @param   mapDat2          ���������� ��������
    @usage @code
             drawAvailablePlaceToStart(2, 800, 600, 10, 10, 10);
    @endcode
*/
//}----------------------------------------------------------------------------------------------------------------
    void drawAvailablePlaceToStart(int distanceOfStart, int xOfCenter, int yOfCenter, double mapSize, int mapDat1, int mapDat2);

//{----------------------------------------------------------------------------------------------------------------
/*!
    @ingroup Drawing
    @brief   ������������ ������, ���� � �� ����� ��������� ����

    @param   x                x-���������� ������
    @param   y                y-���������� ������
    @param   xOfCenter        X-���������� ������ �����
    @param   yOfCenter        Y-���������� ������ �����
    @param   mapSize          ������ �����
    @param   mapDat1          ���������� �����
    @param   mapDat2          ���������� ��������

    @usage @code
             drawMapGlowAvailable(0, 0, 800, 600, 10, 10, 10);
    @endcode
*/
//}----------------------------------------------------------------------------------------------------------------
    void drawMapGlowAvailable(int x, int y, int xOfCenter, int yOfCenter, double mapSize, int mapDat1, int mapDat2);

//{----------------------------------------------------------------------------------------------------------------
/*!
    @ingroup Drawing
    @brief   ������ �������� ��������� � ����
    @param   t                ��������� tank (��������� - ����, � ������� ��������)
    @param   xOfCenter        X-���������� ������ �����
    @param   yOfCenter        Y-���������� ������ �����
    @param   mapSize          ������ �����
    @param   mapDat1          ���������� �����
    @param   mapDat2          ���������� ��������
    @param   boomCd           ������ ��������

    @usage @code
             tank t;
             t.x=3;
             t.y=3;
             int boomCd;
             for (boomCd=40; boomCd>=0; boomCd--)
                drawBoom(t, 800, 600, 10, 10, 10, boomCd);
    @endcode
*/
//}----------------------------------------------------------------------------------------------------------------
    void drawBoom(tank t, int xOfCenter, int yOfCenter, double mapSize, int mapDat1, int mapDat2, int boomCd);
//! @}
//}
//=================================================================================================================

//=================================================================================================================
//{          Logic
//! @name    ������
//=================================================================================================================


//{----------------------------------------------------------------------------------------------------------------
/*!
    @ingroup Logic
    @brief   ������������� �����
             ��� ������� ����������� ����� ��������� � �� �����, ����� ���������� ��������� ����� (���������)
    @param   sav       ��� sav=1 ��������� �� �����, ����� ���������� ���������
    @param   *mapDat1   ��������� �� ���������� �����
    @param   *mapDat2   ��������� �� ���������� ��������
    @see     mapMas[][]
    @usage @code
            drawMap(500, 300, 10, 6, 6);
    @endcode
*/
//}----------------------------------------------------------------------------------------------------------------
    void mapInitializer(bool sav, int* mapDat1, int* mapDat2);

//{----------------------------------------------------------------------------------------------------------------
/*!
    @ingroup Logic
    @brief   �������� ����� �� ������ ����� �� ��������� mapMas[][] � �������� ��� �� ��������� (� ��������� ����������� ������������)
    @param   onlycheck  ��� �������� 1 ������ ��������� �� ���������, ����� ����������
    @param   mapDat1   ���������� �����
    @param   mapDat2   ���������� ��������
    @return  1, ���� ����� �������� ������, � 0 � ��������� ������
    @see     mapMas[][], graph[][5], checkThisPoint()
    @usage @code
             correctMapChecker(0, 10, 10);
    @endcode
*/
//}----------------------------------------------------------------------------------------------------------------
    bool correctMapChecker(bool onlyCheck, int mapDat1, int mapDat2);

//{----------------------------------------------------------------------------------------------------------------
/*!
    @ingroup Logic
    @brief   ��������� ������ ����� ����� �� ��������� graph[][5] �� ��������� � ������ (0, 0)
             ����������� ��������, ����������� ��� ������ ������� <b>correctMapChecker()</b>
    @param   n  �����
    @return  1, ���� ����� �������� �������, � 0 � ��������� ������
    @see     mapMas[][], graph[][5], correctMapChecker()
    @usage @code
             checkThisPoint(25);
    @endcode
*/
//}----------------------------------------------------------------------------------------------------------------
    bool checkThisPoint(int n);

//{----------------------------------------------------------------------------------------------------------------
/*!
    @ingroup Logic
    @brief   ��������� ������ ����� ����� �� ��������� graph[][5] �� ��������� � ������ (0, 0)
             ����������� ��������, ����������� ��� ������ ������� <b>correctMapChecker()</b>
    @return  1, ���� ����� �������� �������, � 0 � ��������� ������
    @see     mapMas[][], graph[][5], correctMapChecker()
    @usage @code
             mapSavedChecker(); //�� ��, �� ��� ������
    @endcode
*/
//}----------------------------------------------------------------------------------------------------------------
    bool mapSavedChecker();

//{----------------------------------------------------------------------------------------------------------------
/*!
    @ingroup Logic
    @brief   ������������ �������� ��� �������
             ��������� ����������� ������ ������� ������-������ �� ����� � ����� �� ����� �
             ���������� �������������� �� ��������� ���������� � ������������� �������. ������� �� ���������!
    @param   *xOfCenter ��������� �� X-���������� ������ �����
    @param   *yOfCenter ��������� �� Y-���������� ������ �����
    @param   mapDat1    ���������� �����
    @param   mapDat2    ���������� ��������
    @param   mapSize    ������ �����
    @param   xWindowSize ������ ���� �� X
    @param   yWindowSize ������ ���� �� Y

    @see     drawMap()

    @usage @code
             xOfCenter=400;
             yOfCenter=300;
             xWindowSize=800;
             yWindowSize=600;
             while (1)
             {
                 yOfCenter++;
                 mapBoundController(&xOfCenter, &yOfCenter, 6, 6, 10, xWindowSize, yWindowSize); //������ ������ ����������� �������, � �� ����� ������ � ������
             }
    @endcode
*/
//}----------------------------------------------------------------------------------------------------------------
    void mapBoundController(int* xOfCenter, int* yOfCenter, int mapDat1, int mapDat2, double mapSize, int xWindowSize, int yWindowSize);

//{----------------------------------------------------------------------------------------------------------------
/*!
    @ingroup Logic
    @brief   ��������� ����������� ����������� ����� �� ��������� ������ � ������� ���������
             ����������� ��������, �������� ������� drawTankMovementGlow(), ���������� �������� interfaceTankMoveCheck()
    @param   n ��������� �� X-���������� ������ �����
    @param   spd ��������� �� Y-���������� ������ �����

    @param   n         ����� ������ � ��������� graph[][5]
    @param   spd       ������� �������� �����
    @param   turn      1, ���� �� ��������� ����, ������� ����� ������; 0 � ��������� ������
    @param   xOfCenter X-���������� ������ �����
    @param   yOfCenter Y-���������� ������ �����
    @param   mapDat1   ���������� �����
    @param   mapDat2   ���������� ��������
    @param   mapSize   ������ �����
    @param   a         �� ��������� 1 - ������������� ����� � ��������� ������; �������� �� 0 <i> �� �������������</i>

    @see     interfaceTankMoveCheck(), drawTankMovementGlow()
    @usage @code
             tank t;
             t.statSpeed=5;
             t.x=1;
             t.y=2;
             mapDat1=6;
             mapDat2=6;
             tankMovementAvailability(mapDat2*t.y+t.x, t.statspeed, 0, 300, 300, mapDat1, mapDat2, 10);
    @endcode
*/
//}----------------------------------------------------------------------------------------------------------------
    void tankMovementAvailability(int n, int spd, bool turn, int xOfCenter, int yOfCenter, int mapDat1, int mapDat2, double mapSize, bool a = 1);

//{----------------------------------------------------------------------------------------------------------------
/*!
    @ingroup Logic
    @brief   ������� �������� ������ ���� string � ������ �������� ���� char*

    @param   s      ����������� ������
    @param   spd    ������, � ������� ���������� ��������� ������

    @see     toString()

    @usage @code
             string s="Michugan-san";
             char c[s.length()];
             toMasOfChar(s, c);
    @endcode
*/
//}----------------------------------------------------------------------------------------------------------------
    void toMasOfChar(string s, char* c);

//{----------------------------------------------------------------------------------------------------------------
/*!
    @ingroup Logic
    @brief   ������� �������� �������� ������ ��������� ���� � ������ string

    @return  ������, � ������� �������� �������� ��������

    @param   value  ��������, ������� ���������� ���������

    @see     toMasOfChar()

    @usage @code
             string s=toString(456);
    @endcode
*/
//}----------------------------------------------------------------------------------------------------------------
    template<typename T>
    string toString(T value)
    {
        std:ostringstream oss;
        oss<<value;
        return oss.str();
    }

//{----------------------------------------------------------------------------------------------------------------
/*!
    @ingroup Logic
    @brief   ������� ������ ����� chooseStart()
             ������������� ���������� � ����� chooseStart()

    @param   mapDat1    ���������� �����
    @param   mapDat2    ���������� ��������

    @see     chooseStart(), chooseStartInitialise()

    @usage @code
            mapDat1=7;
            mapDat2=7;
            chooseStartInitialise(2, mapDat1, mapDat2); //���������� �����... ����������� ��� ������!
            chooseStartClear(mapDat1, mapDat2);         //��� � �� ��������� � �������, ������ ���. ���� ������ �����
    @endcode
*/
//}----------------------------------------------------------------------------------------------------------------
    void chooseStartClear(int mapDat1, int mapDat2);

//{----------------------------------------------------------------------------------------------------------------
/*!
    @ingroup Logic
    @brief   ���������� ������ � ������� mapMas[][] ��� ������ chooseStart()
             ������������� ���������� � ����� chooseStart()

    @param   distanceOfStart    ��������� ����� �������, ������� ���������� ������� ��� ��������� ����� �� �����
    @param   mapDat1            ���������� �����
    @param   mapDat2            ���������� ��������

    @see     mapMas[][], chooseStart(), chooseStartClear()

    @usage @code
            mapDat1=7;
            mapDat2=7;
            chooseStartInitialise(2, mapDat1, mapDat2); //���������� �����... ����������� ��� ������!
            chooseStartClear(mapDat1, mapDat2);         //��� � �� ��������� � �������, ������ ���. ���� ������ �����
    @endcode
*/
//}----------------------------------------------------------------------------------------------------------------
    void chooseStartInitialise(int distanceOfStart, int mapDat1, int mapDat2);

//{----------------------------------------------------------------------------------------------------------------
/*!
    @ingroup Logic
    @brief   �������� �� ���� pcPref.txt, � ������� ������������ ���������� ����
             �������� ������� DrawDefinitionChoose()

    @param   xWindowSize    ������ ���� �� x
    @param   yWindowSize    ������ ���� �� y

    @see     drawDefinitionChoose(), changeResolution()

    @usage @code
            mapDat1=7;
            mapDat2=7;
            chooseStartInitialise(2, mapDat1, mapDat2); //���������� �����... ����������� ��� ������!
            chooseStartClear(mapDat1, mapDat2);         //��� � �� ��������� � �������, ������ ���. ���� ������ �����
    @endcode
*/
//}----------------------------------------------------------------------------------------------------------------
    bool windowSizeChooseAndConfirmation(int* xWindowSize, int* yWindowSize);
//}
//=================================================================================================================

//=================================================================================================================
//{ Interface
//! @name ���������
//=================================================================================================================


//{--------------------------------------------------------------------------------------------------------------�
/*!
    @ingroup Interface
    @brief  �������� �� ������������ ����� � � ������
    @param  *xOfCenter   ��������� �� X-���������� ������ �����
    @param  *yOfCenter   ��������� �� Y-���������� ������ �����
    @param  *mapSize     ��������� �� ������ �����
    @usage @code
            double m;
            int x,y;
            interfaceOfMap(&m, &x, &y);
@endcode
*/
//}--------------------------------------------------------------------------------------------------------------�
    void interfaceOfMap(double* mapSize, int* xOfCenter, int* yOfCenter);

//{--------------------------------------------------------------------------------------------------------------�
/*!
    @ingroup Interface
    @brief   �������, ���������� �� ������������� ��������� ����� � ����� ��� ������� �� ����
             �������� ������� tankMovementAvailability(), donotshootitisme() � drawMapGlowTank()

    @param   t[]                            ������ �������� tank
    @param   xOfCenter                      X-���������� ������ �����
    @param   yOfCenter                      Y-���������� ������ �����
    @param   mapSize                        ������ �����
    @param   mapDat1                        ���������� �����
    @param   mapDat2                        ���������� ��������
    @param   boomCd                         ��������� �� ������ ��������
    @param   tankAmount                     ���������� ������
    @param   *timeMouseTankIgnore           ��������� �� �����, ����� ������� ���� ������������ ���� �������� �������������
    @param   *timeMouseTankAttackIgnore     ��������� �� ����� ���� ��� �������� �����
    @param   turn                           ��� ����� ���
    @param   *boomed                        ��������� �� ����� ������������ �����

    @see     tankMovementAvailability(), donotshootitisme(), drawMapGlowTank(), mouseklikswhatcansupportustomovetank()

    @usage @code
                        //���� �� ��� ��� �����������, ��� ���...
                        //� ������ ������ ����� ������ ���� � ������� ����
             ...        //����� ������ ���� ������������� ������� t[] � ���������� xOfCenter, yOfCenter, mapSize, mapDat1, mapDat2, tankAmount, timeMouseTankIgnore, timeMouseTankAttackIgnore, turn, boomed
             interfaceTankMoveCheck(t, xOfCenter, yOfCenter, mapSize, mapDat1, mapDat2, tankAmount, &timeMouseTankIgnore, &timeMouseTankAttackIgnore, nowIsTurnOf, &boomed);

    @endcode
*/
//}--------------------------------------------------------------------------------------------------------------�
    void interfaceTankMoveCheck(tank t[], int xOfCenter, int yOfCenter, double mapSize, int mapDat1, int mapDat2, int tankAmount, int* timeMouseTankIgnore, int* timeMouseTankAttackIgnore, int turn, int* boomed);

//{--------------------------------------------------------------------------------------------------------------�
/*!
    @ingroup Interface
    @brief   ������������ ������ � ������� ������ ���� ������ ����� ����������
    @param   t[]        ������ �������� tank
    @param   tankAmount ���������� ������
    @param   xOfCenter  X-���������� ������ �����
    @param   yOfCenter  Y-���������� ������ �����
    @param   mapSize    ������ �����
    @param   mapDat1    ���������� �����
    @param   mapDat2    ���������� ��������
    @param   tankNumber ����� �����
    @param   *boomCd    ��������� �� ����� ������� �����
    @param   *boomed    ��������� �� ����� ������������ �����

    @usage @code
             ...        //����� ������ ���� ������������� ������� t[] � ���������� tankAmount, xOfCenter, yOfCenter, mapSize, mapDat1, mapDat2, tankNumber, timeMouseTankAttackIgnore, boomed
             donotshootitisme(t, tankAmount, xOfCenter, yOfCenter, mapSize, mapDat1, mapDat2, tankNumber, &timeMouseTankAttackIgnore, &boomed);
    @endcode
*/
//}--------------------------------------------------------------------------------------------------------------�
    void donotshootitisme(tank t[], int tankAmount,int xOfCenter, int yOfCenter, double mapSize, int mapDat1, int mapDat2, int tankNumber, int* boomCd, int* boomed);

//{--------------------------------------------------------------------------------------------------------------�
/*!
    @ingroup Interface
    @brief   �����������

    @param   ss     ������������ ����������
    @usage @code
             //?????
    @endcode
*/
//}--------------------------------------------------------------------------------------------------------------�
    bool secretFunction(int* ss);

//{--------------------------------------------------------------------------------------------------------------�
/*!
    @ingroup Interface
    @brief   ������ �������� ���������� �������� ����
             ���������� � �������� ����, ��������� �������� drawDefinitionChoose()

    @param   *xWindowSize ��������� �� ������ ���� �� x
    @param   *yWindowSize ��������� �� ������ ���� �� y

    @see     drawDefinitionChoose(), windowSizeChooseAndConfirmation()

    @usage @code
             int xWindowSize,
                 yWindowSize;
             changeResolution(&xWindowSize, &yWindowSize);
    @endcode
*/
//}--------------------------------------------------------------------------------------------------------------�
    void changeResolution(int* xWindowSize, int* yWindowSize);

//{--------------------------------------------------------------------------------------------------------------�
/*!
    @ingroup Interface
    @brief   �������� �� ������������ �����
    @param   *t                         ��������� �� ��������� tank
    @param   xOfCenter                  X-���������� ������ �����
    @param   yOfCenter                  Y-���������� ������ �����
    @param   mapSize                    ������ �����
    @param   mapDat1                    ���������� �����
    @param   mapDat2                    ���������� ��������
    @param   *timeMouseTankMoveIgnore   ��������� �� ����� ����, ����� �������� ����
    @param   *timeMouseTankAttackIgnore ��������� �� ����� ���� ��� �������� �����

    @warning �� ������ ������ ���������� ���� ��� �� ���� ������. ����� ������� ��������� ������������ �� ��������� ������ � ������. ����� ������������!

    @see     interfaceTankMoveCheck()

    @usage @code
             mouseklikswhatcansupportustomovetank(&t, xOfCenter, yOfCenter, mapSize, mapDat1, mapDat2, &timeMouseTankMoveIgnore, &timeMouseTankIgnore);
    @endcode
*/
//}--------------------------------------------------------------------------------------------------------------�
    void mouseklikswhatcansupportustomovetank(tank* t, int xOfCenter, int yOfCenter, double mapSize, int mapDat1, int mapDat2, int* timeMouseTankMoveIgnore, int* timeMouseTankIgnore);

//{--------------------------------------------------------------------------------------------------------------�
/*!
    @ingroup Interface
    @brief   �������� �� ������ ������ ����� ����

    @param   xWindowSize                ������ ���� �� x
    @param   yWindowSize                ������ ���� �� y
    @param   *timeMouseNewTurnIgnore    ��������� �� ����� ���������� ������� ������: ������������� �������� ���������� ��������� ������ ������ - �������� ������ ��� �������� 0
    @param   *turnChange                ������� ����� ����

    @usage @code
             bool turnChange=0;
             int  timeMouseNewTurnIgnore=0;
             buttonEndTurn(800, 600, &timeMouseNewTurnIgnore, &turnChange);
    @endcode
*/
//}--------------------------------------------------------------------------------------------------------------�
    void buttonEndTurn(int xWindowSize, int yWindowSize, int* timeMouseNewTurnIgnore, bool* turnChange);

//{--------------------------------------------------------------------------------------------------------------�
/*!
    @ingroup Interface
    @brief   �������, ���������� �� ������ ������ � ����
    @param   xWindowSize    ������ ���� �� x
    @param   yWindowSize    ������ ���� �� y
    @param   *menuIn        ������� ������ � ����
    @usage @code
             bool menuIn=1;
             buttonEndGame(800, 600, &menuIn);
    @endcode
*/
//}--------------------------------------------------------------------------------------------------------------�
    void buttonEndGame(int xWindowSize, int yWindowSize, bool* menuIn);

//{--------------------------------------------------------------------------------------------------------------�
/*!
    @ingroup Interface
    @brief   ��������� ������ �������� �������������
             � ����������� �� ��������� �� ������ � ������� �������� ������� drawButtonAddPerk()

    @param   xWindowSize                    ������ ���� �� x
    @param   yWindowSize                    ������ ���� �� y
    @param   *t                             ��������� �� ��������� tank
    @param   tankAmount                     ���������� ������
    @param   tankNumber                     ����� �����
    @param   *mainButtonClicked             ������� ������� ������� ������ (������ ������������� ������)
    @param   *timeMouseButtonAddPerkIgnore  ��������� �� ����� ������� ������ ������

    @see drawButtonAddPerk()

    @usage @code
             tank t;
             t.stat...=...;//������������� �����
             bool mainButtonClicked=0;
             int  timeMouseButtonAddPerkIgnore=0;
             buttonsAddPerk(800, 600, &t, 1, 0, &mainButtonClicked, &timeMouseButtonAddPerkIgnore);
    @endcode
*/
//}--------------------------------------------------------------------------------------------------------------�
    void buttonsAddPerk(int xWindowSize, int yWindowSize, tank* t, int tankAmount, int tankNumber, bool* mainButtonClicked, int* timeMouseButtonAddPerkIgnore);

//{--------------------------------------------------------------------------------------------------------------�
/*!
    @ingroup Interface
    @brief   ������������� �������� �������� ��������� �� ������� ������

    @return  1, ���� �� ������� ������ ������ ������, � 0 � ��������� ������

    @param   xCenter        ���������� �� x ������ ������� ������
    @param   yWindowSize    ���������� �� y ������ ������� ������
    @param   radius         ������ ������� ������

    @usage @code
             if (ultimateCircleButtonInterface(80, 80, 50))
                txCircle(80, 80, 100);
             else
                txCircle(80, 80, 50);
    @endcode
*/
//}--------------------------------------------------------------------------------------------------------------�
    bool ultimateCircleButtonInterface(int xCenter, int yCenter, int radius);

//{--------------------------------------------------------------------------------------------------------------�
/*!
    @ingroup Interface
    @brief   ��������� ������ � ������� ����

    @param   xWindowSize    ������ ���� �� x
    @param   yWindowSize    ������ ���� �� y
    @param   *menuIn        ������� ������ � ����

    @return  0, ���� ������ ������ "�����", 1 � ��������� ������

    @usage @code
    double a=12.4;
    int b=13,c=43;
    interfaceOfMap(*a,*b,*c);
    @endcode
*/
//}--------------------------------------------------------------------------------------------------------------�
    bool interfaceMenuButtons(int xWindowSize, int yWindowSize, bool* menuIn);

//{----------------------------------------------------------------------------------------------------------------
/*!
    @ingroup Interface
    @brief   �������, ���������� �� ����������� ������ �� ������� ���� (� ������ ���� � ����� �����������)
             �������� chooseStartInitialise() � chooseStartClear()

    @param   distanceOfStart    ��������� ����� �������, ������� ���������� ������� ��� ��������� ����� �� �����
    @param   *tank              ��������� �� ��������� ��������� tank
    @param   xOfCenter          X-���������� ������ �����
    @param   yOfCenter          Y-���������� ������ �����
    @param   mapSize            ������ �����
    @param   mapDat1            ���������� �����
    @param   mapDat2            ���������� ��������

    @see     chooseStartInitialise(), chooseStartClear()

    @usage @code
            mapDat1=7;
            mapDat2=7;
            chooseStartInitialise(2, mapDat1, mapDat2); //���������� �����... ����������� ��� ������!
            chooseStartClear(mapDat1, mapDat2);         //��� � �� ��������� � �������, ������ ���. ���� ������ �����
    @endcode
*/
//}----------------------------------------------------------------------------------------------------------------
    bool chooseStart(int distanceOfStart, tank* t, int xOfCenter, int yOfCenter, double mapSize, int mapDat1, int mapDat2);
//}
//=================================================================================================================
//}
//=================================================================================================================
    int mapMas[1000][1000];





    //logic

    bool windowSizeChooseAndConfirmation(int* xWindowSize, int* yWindowSize)
    {
        ifstream in;
        ofstream out;
        string str;
        in.open("pcPref.txt");
        getline(in, str);
        if (str=="//This file is for saving your PC's preferences like screen resolution, etc.")
        {
            while (str.length()!=0)
            {
                getline(in, str);
                if (str.substr(0, 20)=="screenDefinitionX = ")
                {
                    str.erase(0, 20);
                    *xWindowSize = atoi(str.c_str());
                }
                else if (str.substr(0, 20)=="screenDefinitionY = ")
                {
                    str.erase(0, 20);
                    *yWindowSize = atoi(str.c_str());
                }
            }
            in.close();
            return 1;
        }
        else
        {
            in.close();
            out.open("pcPref.txt");
            out << "//This file is for saving your PC's preferences like screen resolution, etc.\n";
            drawDefinitionChoose(xWindowSize, yWindowSize);
            out << "screenDefinitionX = " << *xWindowSize <<endl << "screenDefinitionY = " << *yWindowSize << endl;
            return 0;
        }
    }

    //interface

    void mapInitializer(bool sav, int* mapDat1, int* mapDat2)
    {
        ifstream in;
        ofstream out;
        string saveController;
        in.open("ss.txt");
        getline(in, saveController);
        if (sav)
        {
            in>>*mapDat1;
            in>>*mapDat2;
            for (int i=0; i<*mapDat1; i++)
            {
                for (int j=0; j<*mapDat2; j++)
                {
                    in>>mapMas[i][j];
                }
            }
        }
        else
        for (int i=0; i<*mapDat1; i++)
        {
            for (int j=0; j<*mapDat2; j++)
            {
                mapMas[i][j]=rand()%20/4;
                if (mapMas[i][j]>0) mapMas[i][j]=1;
            }
        }
        in.close();
    }


    bool mapSavedChecker()
    {
        ifstream in;
        ofstream out;
        string saveController;
        in.open("ss.txt");
        getline(in, saveController);
        in.close();
        if (saveController=="SAVE_DATA_RIGHT_FILE=true") return 1;
        else return 0;
    }




    int graph[1000000][5];             //^0 >1 v2 <3 checked - 4




    bool correctMapChecker(bool onlyCheck, int mapDat1, int mapDat2)
    {
        int i, j;
        for (i=0; i<mapDat1; i++)
        {
            for (j=0; j<mapDat2; j++)
            {
                if (mapMas[i][j]==0)
                {
                    graph[mapDat2*i+j][0]=-1;
                    graph[mapDat2*i+j][1]=-1;
                    graph[mapDat2*i+j][2]=-1;
                    graph[mapDat2*i+j][3]=-1;
                    graph[mapDat2*i+j][4]=-1;
                }
            }
        }
        if (mapMas[0][0]>0)graph[0][4]=0;
        if (mapMas[0][mapDat2-1]>0)graph[mapDat2-1][4]=0;
        if (mapMas[mapDat1-1][0]>0)graph[mapDat2*(mapDat1-1)][4]=0;
        if (mapMas[mapDat1-1][mapDat2-1]>0)graph[mapDat1*mapDat2-1][4]=0;
        graph[0][0]=-1;
        graph[0][3]=-1;
        if (mapMas[1][0]==0) graph[0][2]=-1;
        else graph[0][2]=mapDat2;
        if (mapMas[0][1]==0) graph[0][1]=-1;
        else graph[0][1]=1;                                   //initializing key points (corners)
        graph[mapDat2-1][0]=-1;
        graph[mapDat2-1][1]=-1;
        if (mapMas[1][mapDat2-1]==0) graph[mapDat2-1][2]=-1;
        else graph[mapDat2-1][2]=mapDat2*2-1;
        if (mapMas[0][mapDat2-2]==0) graph[mapDat2-1][3]=-1;
        else graph[mapDat2-1][3]=mapDat2-2;
        graph[mapDat2*(mapDat1-1)][2]=-1;
        graph[mapDat2*(mapDat1-1)][3]=-1;
        if (mapMas[mapDat1-2][0]==0) graph[mapDat2*(mapDat1-1)][0]=-1;
        else graph[mapDat2*(mapDat1-1)][0]=mapDat2*(mapDat1-2);
        if (mapMas[mapDat1-1][1]==0) graph[mapDat2*(mapDat1-1)][1]=-1;
        else graph[mapDat2*(mapDat1-1)][1]=mapDat2*(mapDat1-1)+1;
        graph[mapDat1*mapDat2-1][1]=-1;
        graph[mapDat1*mapDat2-1][2]=-1;
        if (mapMas[mapDat1-1][mapDat2-2]==0) graph[mapDat1*mapDat2-1][0]=-1;
        else graph[mapDat1*mapDat2-1][0]=(mapDat1-1)*mapDat2-1;
        if (mapMas[mapDat1-2][mapDat2-1]==0) graph[mapDat1*mapDat2-1][3]=-1;
        else graph[mapDat1*mapDat2-1][3]=mapDat1*mapDat2-2;



        for (i=1; i<mapDat1-1; i++)
        {
            if (mapMas[i][0]>0) graph[mapDat2*i][4]=0;
            if (mapMas[i][mapDat2-1]>0) graph[mapDat2*(i+1)-1][4]=0;
            graph[mapDat2*i][3]=-1;
            graph[mapDat2*(i+1)-1][1]=-1;
            if (mapMas[i-1][0]==0) graph[mapDat2*i][0]=-1;
            else graph[mapDat2*i][0]=mapDat2*(i-1);
            if (mapMas[i][1]==0) graph[mapDat2*i][1]=-1;
            else graph[mapDat2*i][1]=mapDat2*i+1;
            if (mapMas[i+1][0]==0) graph[mapDat2*i][2]=-1;
            else graph[mapDat2*i][2]=mapDat2*(i+1);
            if (mapMas[i-1][mapDat2-1]==0) graph[mapDat2*(i+1)-1][0]=-1;          //OMG i did it
            else graph[mapDat2*(i+1)-1][0]=mapDat2*i-1;
            if (mapMas[i+1][mapDat2-1]==0) graph[mapDat2*(i+1)-1][2]=-1;
            else graph[mapDat2*(i+1)-1][2]=mapDat2*(i+2)-1;
            if (mapMas[i][mapDat2-2]==0) graph[mapDat2*(i+1)-1][3]=-1;
            else graph[mapDat2*(i+1)-1][3]=mapDat2*(i+1)-2;
        }
        for (j=1; j<mapDat2-1; j++)
        {
            if (mapMas[0][j]>0) graph[j][4]=0;
            if (mapMas[mapDat1-1][j]>0)graph[mapDat2*(mapDat1-1)+j][4]=0;
            graph[j][0]=-1;
            graph[mapDat2*(mapDat1-1)+j][2]=-1;
            if (mapMas[0][j+1]==0) graph[j][1]=-1;
            else graph[j][1]=j+1;
            if (mapMas[1][j]==0) graph[j][2]=-1;
            else graph[j][2]=mapDat2+j;
            if (mapMas[0][j-1]==0) graph[j][3]=-1;
            else graph[j][3]=j-1;
            if (mapMas[mapDat1-2][j]==0) graph[(mapDat1-1)*mapDat2+j][0]=-1;
            else graph[(mapDat1-1)*mapDat2+j][0]=(mapDat1-2)*mapDat2+j;
            if (mapMas[mapDat1-1][j-1]==0) graph[(mapDat1-1)*mapDat2+j][1]=-1;
            else graph[(mapDat1-1)*mapDat2+j][1]=(mapDat1-1)*mapDat2+j+1;
            if (mapMas[mapDat1-1][j]==0) graph[(mapDat1-1)*mapDat2+j][3]=-1;
            else graph[(mapDat1-1)*mapDat2+j][3]=(mapDat1-1)*mapDat2+j-1;

        }
        for (i=1; i<mapDat1-1; i++)
        {
            for (j=1; j<mapDat2-1; j++)
            {
                if (mapMas[i][j]>0)graph[mapDat2*i+j][4]=0;
                if (mapMas[i-1][j]==0) graph[mapDat2*i+j][0]=-1;
                else graph[mapDat2*i+j][0]=mapDat2*(i-1)+j;
                if (mapMas[i][j+1]==0) graph[mapDat2*i+j][1]=-1;
                else graph[mapDat2*i+j][1]=mapDat2*i+j+1;
                if (mapMas[i+1][j]==0) graph[mapDat2*i+j][2]=-1;
                else graph[mapDat2*i+j][2]=mapDat2*(i+1)+j;
                if (mapMas[i][j-1]==0) graph[mapDat2*i+j][3]=-1;
                else graph[mapDat2*i+j][3]=mapDat2*i+j-1;
            }
        }
        for (i=0; i<mapDat1; i++)
        {
        for (j=0; j<mapDat2; j++)
        {
            for (int i1=0; i1<mapDat1; i1++)  for (int j1=0; j1<mapDat2; j1++) graph[mapDat2*i1+j1][4]=0;
            for (int i1=0; i1<mapDat1; i1++)  for (int j1=0; j1<mapDat2; j1++)
            {
                if (mapMas[i1][j1]==0) graph[mapDat2*i1+j1][4]=-1;
            }
            if (graph[mapDat2*i+j][4]!=-1)
            {
            if(!checkThisPoint(mapDat2*i+j))
            {
                if (onlyCheck)
                return 0;
                int i1=i, j1=j;

                while (mapMas[i1][j1]!=0&&(i1>0||j1>0))
                {
                    if ((rand()%2==0 && i1>0) || j1==0) i1--;
                    else j1--;
                }
                mapMas[i1][j1]=1;
                graph[mapDat2*i1+j1][4]=0;
                if (i1>0&&mapMas[i1-1][j1]!=0)
                {
                    graph[mapDat2*i1+j1][0]=mapDat2*(i1-1)+j1;
                    graph[mapDat2*(i1-1)+j1][2]=mapDat2*i1+j1;
                }
                if (j1<mapDat2-1&&mapMas[i1][j1+1]!=0)
                {
                    graph[mapDat2*i1+j1][1]=mapDat2*i1+j1+1;
                    graph[mapDat2*i1+j1+1][3]=mapDat2*i1+j1;

                }
                if (i1<mapDat1-1&&mapMas[i1+1][j1]!=0)
                {
                   graph[mapDat2*i1+j][2]=mapDat2*(i1+1)+j1;
                   graph[mapDat2*(i1+1)+j1][0]=mapDat2*i1+j1;
                }
                if (j1>0&&mapMas[i1][j1-1]!=0)
                {
                    graph[mapDat2*i1+j1][3]=mapDat2*i1+j1-1;
                    graph[mapDat2*i1+j1-1][1]=mapDat2*i1+j1;
                }
                j--;
            }
            }

      //  cout<<graph[(mapDat1-1)*mapDat2][0]<<" "<<graph[(mapDat1-1)*mapDat2][1]<<" "<<graph[(mapDat1-1)*mapDat2][2]<<" "<<graph[(mapDat1-1)*mapDat2][3]<<" "<<graph[(mapDat1-1)*mapDat2][4]<<endl;

      //  cout<<graph[(mapDat1-2)*mapDat2][0]<<" "<<graph[(mapDat1-2)*mapDat2][1]<<" "<<graph[(mapDat1-2)*mapDat2][2]<<" "<<graph[(mapDat1-2)*mapDat2][3]<<" "<<graph[(mapDat1-2)*mapDat2][4]<<endl<<i<<" "<<j<<" "<<endl;
        //txSleep(30);
        }
        }
        return 1;
    }

    bool checkThisPoint(int n)
    {
        if (graph[n][4]==1||graph[n][4]==-1) return 0;
        else if (n==0) return 1;
        else
        {
            graph[n][4]=1;
            for (int i=0; i<4; i++)
            {
                if (graph[n][i]!=-1) if (checkThisPoint(graph[n][i])) return 1;
            }
            return 0;
        }
    }

    void mapBoundController(int* xOfCenter, int* yOfCenter, int mapDat1, int mapDat2, double mapSize, int xWindowSize, int yWindowSize)
    {
        if (mapDat1*2*mapSize>xWindowSize-xWindowSize/4-60)
        {
            if (*xOfCenter>(mapDat2+1)*mapSize+xWindowSize/4+40)
                *xOfCenter=(int)((mapDat2+1)*mapSize)+xWindowSize/4+40;
            if (*xOfCenter<xWindowSize-(mapDat2-1)*mapSize-20)
                *xOfCenter=xWindowSize-(int)((mapDat2-1)*mapSize)-20;
        }
        else
        {
            if (*xOfCenter<(mapDat2+1)*mapSize+xWindowSize/4+40)
                *xOfCenter=(int)((mapDat2+1)*mapSize)+xWindowSize/4+40;
            if (*xOfCenter+(mapDat2-1)*mapSize>xWindowSize-20)
                *xOfCenter=xWindowSize-(int)((mapDat2-1)*mapSize)-20;
        }
        if (mapDat2*2*mapSize>yWindowSize-40)
        {
            if (*yOfCenter>(mapDat1+1)*mapSize+20)
                *yOfCenter=(int)((mapDat1+1)*mapSize)+20;
            if (*yOfCenter<yWindowSize-(mapDat1-1)*mapSize-20)
                *yOfCenter=yWindowSize-(int)((mapDat1-1)*mapSize)-20;
        }
        else
        {
            if (*yOfCenter<(mapDat1+1)*mapSize+20)
                *yOfCenter=(int)((mapDat1+1)*mapSize)+20;
            if (*yOfCenter+(mapDat1-1)*mapSize>yWindowSize-20)
                *yOfCenter=yWindowSize-(int)((mapDat1-1)*mapSize)-20;
        }
    }

    void tankMovementAvailability(int n, int spd, bool turn, int xOfCenter, int yOfCenter, int mapDat1, int mapDat2, double mapSize, bool a)
    {
         if (spd<0) return;
         if (n<0)return;
         if (a==0&&(mapMas[n/mapDat2][n%mapDat2]<=0||mapMas[n/mapDat2][n%mapDat2]==2)) return;
         if (a==0) drawTankMovementGlow(turn, n%mapDat2, n/mapDat2, xOfCenter, yOfCenter, mapSize, mapDat1, mapDat2);
         for (int i = 0; i < 4; i ++)
         {
            tankMovementAvailability(graph[n][i], spd-1, turn, xOfCenter, yOfCenter, mapDat1, mapDat2, mapSize, 0);
         }

    }

    void toMasOfChar(string s, char* c)
    {
        unsigned int i;
        for (i = 0; i < s.length()+5; i ++)
        {
            c[i]=s[i];
        }
    }

    void chooseStartInitialise(int distanceOfStart, int mapDat1, int mapDat2)
    {
        for (int i = 0; i < mapDat1; i ++)
        {
            for (int j = 0; j < mapDat2; j ++)
            {
                if (mapMas[i][j] >= 2 && mapMas[i][j] != 322)
                {
                    for (int i1 = max(0, i-distanceOfStart); i1 <= min(mapDat1-1, i + distanceOfStart); i1++)
                        for (int j1 = max(0, j - distanceOfStart); j1 <= min(mapDat2-1, j + distanceOfStart); j1++)
                            if (
                                abs(i1-i)+abs(j1-j)<=distanceOfStart
                                &&
                                mapMas[i1][j1]==1
                                )
                                mapMas[i1][j1]=322;
                }
            }
        }
    }

    void chooseStartClear(int mapDat1, int mapDat2)
    {
        for (int i = 0; i < mapDat1; i ++)
        {
            for (int j = 0; j < mapDat2; j ++)
            {
                if (mapMas[i][j]==322)
                    mapMas[i][j]=1;
            }
        }
    }

    //interface
    void interfaceOfMap(double* mapSize, int* xOfCenter, int* yOfCenter)
    {
        if (GetAsyncKeyState('V'))
        {
            *mapSize+=0.19;
        }
        if (GetAsyncKeyState('B'))
        {
            *mapSize-=0.19;
        }
        if (GetAsyncKeyState(VK_RIGHT))     *xOfCenter-=(int)(*mapSize/10);
        if (GetAsyncKeyState(VK_LEFT))      *xOfCenter+=(int)(*mapSize/10);
        if (GetAsyncKeyState(VK_DOWN))      *yOfCenter-=(int)(*mapSize/10);
        if (GetAsyncKeyState(VK_UP))        *yOfCenter+=(int)(*mapSize/10);
        if (*mapSize<5) *mapSize=5;
        if (*mapSize>45) *mapSize=45;
    }

    void interfaceTankMoveCheck(tank t[], int xOfCenter, int yOfCenter, double mapSize, int mapDat1, int mapDat2, int tankAmount, int* timeMouseTankIgnore, int* timeMouseTankAttackIgnore, int turn, int* boomed)
    {
        for (int i=0; i < tankAmount; i++)
        {
            if (t[i].x>=0)
            {
                if (t[i].clicked==1)
                {
                    tankMovementAvailability(t[i].y*mapDat2+t[i].x, t[i].statSpeed, (turn==i), xOfCenter, yOfCenter, mapDat1, mapDat2, mapSize, 1);
                    donotshootitisme(t, tankAmount, xOfCenter, yOfCenter, mapSize, mapDat1, mapDat2, turn, timeMouseTankAttackIgnore, boomed);
                }
                if (In( txMouseX(),
                        (int)(xOfCenter-(mapDat2-t[i].x*2+1)*mapSize),
                        (int)(xOfCenter-(mapDat2-t[i].x*2-1)*mapSize)
                      )
                    &&
                    In( txMouseY(),
                        (int)(yOfCenter-(mapDat1-t[i].y*2+1)*mapSize),
                        (int)(yOfCenter-(mapDat1-t[i].y*2-1)*mapSize)
                      )
                   )
                {
                    if (txMouseButtons() & 1 && *timeMouseTankIgnore==0)
                    {
                        *timeMouseTankIgnore=10;
                        int c=t[i].clicked;
                        if (c>0) c=1;
                        c=(c+1)%2;
                        t[i].clicked=c;
                    }
                    drawMapGlowTank(t[i], xOfCenter, yOfCenter, mapSize, mapDat1, mapDat2);
                }
            }
        }
    }

    void donotshootitisme(tank t[],int tankAmount,int xOfCenter, int yOfCenter, double mapSize, int mapDat1, int mapDat2, int tankNumber, int* boomCd, int* boomed)
    {
        int range=1;
        bool x1=1,x2=1,x3=1,x4=1;
        while(range<=t[tankNumber].statAim)
        {
            if(mapMas[t[tankNumber].y+range][t[tankNumber].x]==0 and x1)
                x1=0;
            if(mapMas[t[tankNumber].y-range][t[tankNumber].x]==0 and x2)
                x2=0;
            if(mapMas[t[tankNumber].y][t[tankNumber].x+range]==0 and x3)
                x3=0;
            if(mapMas[t[tankNumber].y][t[tankNumber].x-range]==0 and x4)
                x4=0;
            if(mapMas[t[tankNumber].y+range][t[tankNumber].x]==2 and x1)
            {
                drawTankAttackGlow(t[tankNumber].x,t[tankNumber].y+range, xOfCenter, yOfCenter, mapSize, mapDat1, mapDat2);
                if
                (In ( txMouseX(),
                (int)(xOfCenter-(mapDat2-t[tankNumber].x*2+1)*mapSize+2),
                (int)(xOfCenter-(mapDat2-t[tankNumber].x*2-1)*mapSize-2)
                )
                &&
                In ( txMouseY(),
                (int)(yOfCenter-(mapDat1-(t[tankNumber].y+range)*2+1)*mapSize+2),
                (int)(yOfCenter-(mapDat1-(t[tankNumber].y+range)*2-1)*mapSize-2)
                )
                &&
                txMouseButtons() & 1
                &&
                t[tankNumber].attacked==0
                )
                {
                    for(int i=0;i<tankAmount;i++)
                    {
                        if(t[i].x==t[tankNumber].x and t[i].y==t[tankNumber].y+range )
                        {
                            t[i].statHealth=t[i].statHealth-t[tankNumber].statAttack;
                            t[tankNumber].attacked=1;
                            t[tankNumber].position=3;
                            *boomed=i;
                            *boomCd=30;
                            drawBoom(t[i], xOfCenter, yOfCenter, mapSize, mapDat1, mapDat2, *boomCd);
                        }
                    }
                }
            }
            if(mapMas[t[tankNumber].y-range][t[tankNumber].x]==2 and x2)
            {
                drawTankAttackGlow(t[tankNumber].x,t[tankNumber].y-range, xOfCenter, yOfCenter, mapSize, mapDat1, mapDat2);
                if  (In ( txMouseX(),
                        (int)(xOfCenter-(mapDat2-t[tankNumber].x*2+1)*mapSize+2),
                        (int)(xOfCenter-(mapDat2-t[tankNumber].x*2-1)*mapSize-2)
                        )
                        &&
                        In ( txMouseY(),
                        (int)(yOfCenter-(mapDat1-(t[tankNumber].y-range)*2+1)*mapSize+2),
                        (int)(yOfCenter-(mapDat1-(t[tankNumber].y-range)*2-1)*mapSize-2)
                        )
                        &&
                        txMouseButtons() & 1
                        &&
                        t[tankNumber].attacked==0
                    )
                {
                    for(int i=0;i<tankAmount;i++)
                    {
                        if(t[i].x==t[tankNumber].x and t[i].y==t[tankNumber].y-range )
                        {
                            t[i].statHealth=t[i].statHealth-t[tankNumber].statAttack;
                            t[tankNumber].attacked=1;
                            t[tankNumber].position=1;
                            *boomed=i;
                            *boomCd=30;
                            drawBoom(t[i], xOfCenter, yOfCenter, mapSize, mapDat1, mapDat2, *boomCd);
                        }
                    }
                }
            }
            if(mapMas[t[tankNumber].y][t[tankNumber].x+range]==2 and x3==1)
            {
                drawTankAttackGlow(t[tankNumber].x+range,t[tankNumber].y, xOfCenter, yOfCenter, mapSize, mapDat1, mapDat2);
                if  (   In( txMouseX(),
                            (int)(xOfCenter-(mapDat2-(t[tankNumber].x+range)*2+1)*mapSize+2),
                            (int)(xOfCenter-(mapDat2-(t[tankNumber].x+range)*2-1)*mapSize-2)
                          )
                        &&
                        In( txMouseY(),
                            (int)(yOfCenter-(mapDat1-(t[tankNumber].y)*2+1)*mapSize+2),
                            (int)(yOfCenter-(mapDat1-(t[tankNumber].y)*2-1)*mapSize-2)
                          )
                        &&
                        txMouseButtons() & 1
                        &&
                        t[tankNumber].attacked == 0
                    )
                {
                    for(int i=0;i<tankAmount;i++)
                    {
                        if(t[i].x==t[tankNumber].x+range and t[i].y==t[tankNumber].y)
                        {
                            t[i].statHealth=t[i].statHealth-t[tankNumber].statAttack;
                            t[tankNumber].attacked=1;
                            t[tankNumber].position=2;
                            *boomed=i;
                            *boomCd=30;
                            drawBoom(t[i], xOfCenter, yOfCenter, mapSize, mapDat1, mapDat2, *boomCd);
                        }
                    }
                }
            }
            if(mapMas[t[tankNumber].y][t[tankNumber].x-range]==2 and x4==1)
            {
                drawTankAttackGlow(t[tankNumber].x-range,t[tankNumber].y, xOfCenter, yOfCenter, mapSize, mapDat1, mapDat2);
                if( In( txMouseX(),
                        (int)(xOfCenter-(mapDat2-(t[tankNumber].x-range)*2+1)*mapSize+2),
                        (int)(xOfCenter-(mapDat2-(t[tankNumber].x-range)*2-1)*mapSize-2)
                      )
                    &&
                    In( txMouseY(),
                        (int)(yOfCenter-(mapDat1-(t[tankNumber].y)*2+1)*mapSize+2),
                        (int)(yOfCenter-(mapDat1-(t[tankNumber].y)*2-1)*mapSize-2)
                        )
                    &&
                    txMouseButtons() & 1
                    &&
                    t[tankNumber].attacked==0
                )
                {
                    for(int i=0;i<tankAmount;i++)
                    {
                        if(t[i].x==t[tankNumber].x-range and t[i].y==t[tankNumber].y )
                        {
                            t[i].statHealth=t[i].statHealth-t[tankNumber].statAttack;
                            t[tankNumber].attacked=1;
                            t[tankNumber].position=4;
                            *boomed=i;
                            *boomCd=30;
                            drawBoom(t[i], xOfCenter, yOfCenter, mapSize, mapDat1, mapDat2, *boomCd);
                        }
                    }
                }
            }
            range++;
        }
    }


    void changeResolution(int* xWindowSize, int* yWindowSize)
    {
        if (GetAsyncKeyState(VK_LEFT))
        {
            *xWindowSize=*xWindowSize-2;
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            *xWindowSize=*xWindowSize+2;
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            *yWindowSize=*yWindowSize-1;
        }
        if (GetAsyncKeyState(VK_UP))
        {
            *yWindowSize=*yWindowSize+1;
        }
        if (*xWindowSize<0) *xWindowSize=0;
        if (*xWindowSize>2715) *xWindowSize=2715;
        if (*yWindowSize<0) *yWindowSize=0;
        if (*yWindowSize>1527) *yWindowSize=1527;
    }

    void mouseklikswhatcansupportustomovetank(tank* t, int xOfCenter, int yOfCenter, double mapSize, int mapDat1, int mapDat2, int* timeMouseTankMoveIgnore, int* timeMouseTankIgnore)
    {
        if
        (In  (   txMouseX(),
                    (int)(xOfCenter-(mapDat2-(*t).x*2+1)*mapSize+2),
                    (int)(xOfCenter-(mapDat2-(*t).x*2-1)*mapSize-2)
                )
            &&
            In  (   txMouseY(),
                    (int)(yOfCenter-(mapDat1-((*t).y-1)*2+1)*mapSize+2),
                    (int)(yOfCenter-(mapDat1-((*t).y-1)*2-1)*mapSize-2)
                )
            &&
            txMouseButtons() & 1
            &&
            (*t).y>0
            &&
            mapMas[(*t).y-1][(*t).x]>0
            &&
            mapMas[(*t).y-1][(*t).x]!=2
        )
        {
        mapMas[(*t).y][(*t).x]=1;
        (*t).y--;
        mapMas[(*t).y][(*t).x]=2;
        (*t).statSpeed--;
        (*t).position=1;
        (*timeMouseTankMoveIgnore)=5;
        (*timeMouseTankIgnore)+=3;
        }

        if
        (In  (   txMouseX(),
                    (int)(xOfCenter-(mapDat2-(*t).x*2+1)*mapSize+2),
                    (int)(xOfCenter-(mapDat2-(*t).x*2-1)*mapSize-2)
                )
            &&
            In  (   txMouseY(),
                    (int)(yOfCenter-(mapDat1-((*t).y+1)*2+1)*mapSize+2),
                    (int)(yOfCenter-(mapDat1-((*t).y+1)*2-1)*mapSize-2)
                )
            &&
            txMouseButtons() & 1
            &&
            (*t).y<mapDat1
            &&
            mapMas[(*t).y+1][(*t).x]>0
            &&
            mapMas[(*t).y+1][(*t).x]!=2
        )
        {
        mapMas[(*t).y][(*t).x]=1;
        (*t).y++;
        mapMas[(*t).y][(*t).x]=2;
        (*t).statSpeed--;
        (*t).position=3;
        (*timeMouseTankMoveIgnore)=5;
        (*timeMouseTankIgnore)+=3;
        }
        if
        (In  (   txMouseX(),
                    (int)(xOfCenter-(mapDat2-((*t).x-1)*2+1)*mapSize+2),
                    (int)(xOfCenter-(mapDat2-((*t).x-1)*2-1)*mapSize-2)
                )
            &&
            In  (   txMouseY(),
                    (int)(yOfCenter-(mapDat1-((*t).y)*2+1)*mapSize+2),
                    (int)(yOfCenter-(mapDat1-((*t).y)*2-1)*mapSize-2)
                )
            &&
            txMouseButtons() & 1
             &&
            (*t).x>0
            &&
            mapMas[(*t).y][(*t).x-1]>0
            &&
            mapMas[(*t).y][(*t).x-1]!=2
        )
        {
        mapMas[(*t).y][(*t).x]=1;
        (*t).x--;
        mapMas[(*t).y][(*t).x]=2;
        (*t).statSpeed--;
        (*t).position=4;
        (*timeMouseTankMoveIgnore)=5;
        (*timeMouseTankIgnore)+=3;
        }
        if
        (In  (   txMouseX(),
                    (int)(xOfCenter-(mapDat2-((*t).x+1)*2+1)*mapSize+2),
                    (int)(xOfCenter-(mapDat2-((*t).x+1)*2-1)*mapSize-2)
                )
            &&
            In  (   txMouseY(),
                    (int)(yOfCenter-(mapDat1-((*t).y)*2+1)*mapSize+2),
                    (int)(yOfCenter-(mapDat1-((*t).y)*2-1)*mapSize-2)
                )
            &&
            txMouseButtons() & 1
            &&
            (*t).x<mapDat2
            &&
            mapMas[(*t).y][(*t).x+1]>0
            &&
            mapMas[(*t).y][(*t).x+1]!=2
        )
        {
        mapMas[(*t).y][(*t).x]=1;
        (*t).x++;
        mapMas[(*t).y][(*t).x]=2;
        (*t).statSpeed--;
        (*t).position=2;
        (*timeMouseTankMoveIgnore)=5;
        (*timeMouseTankIgnore)+=3;
        }

    }

    void buttonEndGame(int XCENTER, int YCENTER, bool* menuIn)
    {
        if (
            txMouseButtons() & 1
            &&
            In  (
                    txMouseX(),
                    XCENTER-75,
                    XCENTER+75
                )
            &&
            In  (
                    txMouseY(),
                    YCENTER-50,
                    YCENTER+10
                )
            )
        {
            *menuIn=0;
        }
    }

    void buttonEndTurn(int XCENTER, int YCENTER, int* timeMouseNewTurnIgnore, bool* turnChange)
    {
        if (
            txMouseButtons() & 1
            &&
            In  (
                    txMouseX(),
                    XCENTER-75,
                    XCENTER+70
                )
            &&
            In  (
                    txMouseY(),
                    YCENTER-30,
                    YCENTER+30
                )
            &&
            *timeMouseNewTurnIgnore==0
            )
        {
            *timeMouseNewTurnIgnore=30;
            *turnChange=1;
        }
    }

    void buttonsAddPerk(int xWindowSize, int yWindowSize, tank* t, int tankAmount, int tankNumber, bool* mainButtonClicked, int* timeMouseButtonAddPerkIgnore)
    {
        CONST COLORREF  BU_DARKGREEN = RGB(23, 121, 53),
                        BU_GREEN = RGB(46, 207, 37),
                        BU_LIGHTGREEN = RGB(96, 225, 89),
                        BU_BROWN = RGB(186, 210, 111),
                        BU_LIGHTBROWN = RGB(250, 239, 112),
                        BU_GREY = RGB(100, 100, 100),
                        BU_LIGHTGREY = RGB(150, 150, 150);
        if (*mainButtonClicked)
        {
            drawButtonAddPerk(xWindowSize*14/60, (yWindowSize-50)/tankAmount*(tankNumber+1)-xWindowSize/60-20, xWindowSize/60, BU_DARKGREEN, BU_GREEN, xWindowSize/350);
            txSetTextAlign(TA_CENTER);
            txSelectFont("Aharoni", 20);
            //health
            if ((*t).distributionPoints>0)
            {
                if (ultimateCircleButtonInterface(xWindowSize/10-40-xWindowSize/75, (int)((yWindowSize-50)/tankAmount*(tankNumber+0.25))+15, xWindowSize/75))
                {
                    if (txMouseButtons() & 1)
                    {
                        drawButtonAddPerk(xWindowSize/10-40-xWindowSize/75, (int)((yWindowSize-50)/tankAmount*(tankNumber+0.25))+15, xWindowSize/75, BU_DARKGREEN, BU_GREEN, xWindowSize/450);
                        if (*timeMouseButtonAddPerkIgnore==0)
                        {
                            (*t).statHealthMax++;
                            (*t).statHealth++;
                            (*t).distributionPoints--;
                            *timeMouseButtonAddPerkIgnore=3;
                        }
                    }
                    else
                        drawButtonAddPerk(xWindowSize/10-40-xWindowSize/75, (int)((yWindowSize-50)/tankAmount*(tankNumber+0.25))+15, xWindowSize/75, BU_GREEN, BU_LIGHTGREEN, xWindowSize/450);
                }
                else
                    drawButtonAddPerk(xWindowSize/10-40-xWindowSize/75, (int)((yWindowSize-50)/tankAmount*(tankNumber+0.25))+15, xWindowSize/75, BU_BROWN, BU_LIGHTBROWN, xWindowSize/450);
            }
            else
                drawButtonAddPerk(xWindowSize/10-40-xWindowSize/75, (int)((yWindowSize-50)/tankAmount*(tankNumber+0.25))+15, xWindowSize/75, BU_GREY, BU_LIGHTGREY, xWindowSize/450);
            txTextOut(xWindowSize/10-40-xWindowSize/75, (int)((yWindowSize-50)/tankAmount*(tankNumber+0.25))+15+xWindowSize/75, "1 p");

            //attackdamage
            if ((*t).distributionPoints>1)
            {
                if (ultimateCircleButtonInterface(xWindowSize/12-40-xWindowSize/75, (int)((yWindowSize-50)/tankAmount*(tankNumber+0.5))+15, xWindowSize/75))
                {
                    if (txMouseButtons() & 1)
                    {
                        drawButtonAddPerk(xWindowSize/12-40-xWindowSize/75, (int)((yWindowSize-50)/tankAmount*(tankNumber+0.5))+15, xWindowSize/75, BU_DARKGREEN, BU_GREEN, xWindowSize/450);
                        if (*timeMouseButtonAddPerkIgnore==0)
                        {
                            (*t).statAttack++;
                            (*t).distributionPoints-=2;
                            *timeMouseButtonAddPerkIgnore=3;
                        }
                    }
                    else
                        drawButtonAddPerk(xWindowSize/12-40-xWindowSize/75, (int)((yWindowSize-50)/tankAmount*(tankNumber+0.5))+15, xWindowSize/75, BU_GREEN, BU_LIGHTGREEN, xWindowSize/450);
                }
                else
                    drawButtonAddPerk(xWindowSize/12-40-xWindowSize/75, (int)((yWindowSize-50)/tankAmount*(tankNumber+0.5))+15, xWindowSize/75, BU_BROWN, BU_LIGHTBROWN, xWindowSize/450);
            }
            else
                drawButtonAddPerk(xWindowSize/12-40-xWindowSize/75, (int)((yWindowSize-50)/tankAmount*(tankNumber+0.5))+15, xWindowSize/75, BU_GREY, BU_LIGHTGREY, xWindowSize/450);
            txTextOut(xWindowSize/12-40-xWindowSize/75, (int)((yWindowSize-50)/tankAmount*(tankNumber+0.5))+15+xWindowSize/75, "2 p");

            //speed
            if ((*t).distributionPoints>49)
            {
                if (ultimateCircleButtonInterface(xWindowSize/12-40-xWindowSize/75, (int)((yWindowSize-50)/tankAmount*(tankNumber+0.75))+15, xWindowSize/75))
                {
                    if (txMouseButtons() & 1)
                    {
                        drawButtonAddPerk(xWindowSize/12-40-xWindowSize/75, (int)((yWindowSize-50)/tankAmount*(tankNumber+0.75))+15, xWindowSize/75, BU_DARKGREEN, BU_GREEN, xWindowSize/450);
                        if (*timeMouseButtonAddPerkIgnore==0)
                        {
                            (*t).statSpeed++;
                            (*t).statSpeedMax++;
                            (*t).distributionPoints-=50;
                            *timeMouseButtonAddPerkIgnore=3;
                        }
                    }
                    else
                        drawButtonAddPerk(xWindowSize/12-40-xWindowSize/75, (int)((yWindowSize-50)/tankAmount*(tankNumber+0.75))+15, xWindowSize/75, BU_GREEN, BU_LIGHTGREEN, xWindowSize/450);
                }
                else
                    drawButtonAddPerk(xWindowSize/12-40-xWindowSize/75, (int)((yWindowSize-50)/tankAmount*(tankNumber+0.75))+15, xWindowSize/75, BU_BROWN, BU_LIGHTBROWN, xWindowSize/450);
            }
            else
                drawButtonAddPerk(xWindowSize/12-40-xWindowSize/75, (int)((yWindowSize-50)/tankAmount*(tankNumber+0.75))+15, xWindowSize/75, BU_GREY, BU_LIGHTGREY, xWindowSize/450);
            txTextOut(xWindowSize/12-40-xWindowSize/75, (int)((yWindowSize-50)/tankAmount*(tankNumber+0.75))+15+xWindowSize/75, "50 p");

            //aim
            if ((*t).distributionPoints>74)
            {
                if (ultimateCircleButtonInterface(xWindowSize/4-60-xWindowSize/75, (int)((yWindowSize-50)/tankAmount*(tankNumber+0.75))+15, xWindowSize/75))
                {
                    if (txMouseButtons() & 1)
                    {
                        drawButtonAddPerk(xWindowSize/4-60-xWindowSize/75, (int)((yWindowSize-50)/tankAmount*(tankNumber+0.75))+15, xWindowSize/75, BU_DARKGREEN, BU_GREEN, xWindowSize/450);
                        if (*timeMouseButtonAddPerkIgnore==0)
                        {
                            (*t).statAim++;
                            (*t).distributionPoints-=75;
                            *timeMouseButtonAddPerkIgnore=3;
                        }
                    }
                    else
                        drawButtonAddPerk(xWindowSize/4-60-xWindowSize/75, (int)((yWindowSize-50)/tankAmount*(tankNumber+0.75))+15, xWindowSize/75, BU_GREEN, BU_LIGHTGREEN, xWindowSize/450);
                }
                else
                    drawButtonAddPerk(xWindowSize/4-60-xWindowSize/75, (int)((yWindowSize-50)/tankAmount*(tankNumber+0.75))+15, xWindowSize/75, BU_BROWN, BU_LIGHTBROWN, xWindowSize/450);
            }
            else
                drawButtonAddPerk(xWindowSize/4-60-xWindowSize/75, (int)((yWindowSize-50)/tankAmount*(tankNumber+0.75))+15, xWindowSize/75, BU_GREY, BU_LIGHTGREY, xWindowSize/450);
            txTextOut(xWindowSize/4-60-xWindowSize/75, (int)((yWindowSize-50)/tankAmount*(tankNumber+0.75))+15+xWindowSize/75, "75 p");

            if (ultimateCircleButtonInterface(xWindowSize*14/60, (yWindowSize-50)/tankAmount*(tankNumber+1)-xWindowSize/60-20, xWindowSize/60) && txMouseButtons() & 1 && *timeMouseButtonAddPerkIgnore==0)
            {
                *mainButtonClicked=0;
                *timeMouseButtonAddPerkIgnore=3;
            }
        }
        else if (ultimateCircleButtonInterface(xWindowSize*14/60, (yWindowSize-50)/tankAmount*(tankNumber+1)-xWindowSize/60-20, xWindowSize/60))
        {
            if (txMouseButtons() & 1)
            {
                drawButtonAddPerk(xWindowSize*14/60, (yWindowSize-50)/tankAmount*(tankNumber+1)-xWindowSize/60-20, xWindowSize/60, BU_DARKGREEN, BU_GREEN, xWindowSize/350);
                if(*timeMouseButtonAddPerkIgnore==0)
                    {
                        *mainButtonClicked=1;
                        *timeMouseButtonAddPerkIgnore=3;
                    }
            }
            else
            drawButtonAddPerk(xWindowSize*14/60, (yWindowSize-50)/tankAmount*(tankNumber+1)-xWindowSize/60-20, xWindowSize/60, BU_GREEN, BU_LIGHTGREEN, xWindowSize/350);
        }
        else
            drawButtonAddPerk(xWindowSize*14/60, (yWindowSize-50)/tankAmount*(tankNumber+1)-xWindowSize/60-20, xWindowSize/60, BU_BROWN, BU_LIGHTBROWN, xWindowSize/350);
    }

    bool ultimateCircleButtonInterface(int xCenter, int yCenter, int radius)
    {
        if ((txMouseX()-xCenter)*(txMouseX()-xCenter)+(txMouseY()-yCenter)*(txMouseY()-yCenter)<radius*radius)
            return 1;
        else return 0;
    }

    bool interfaceMenuButtons(int xWindowSize, int yWindowSize, bool* menuIn)
    {
        if  (txMouseButtons()&1
            &&
            In  (txMouseX(),
                xWindowSize/4-60,
                xWindowSize/4+60
                )
            &&
            In  (txMouseY(),
                yWindowSize/2-20,
                yWindowSize/2+20
                )
            )
            *menuIn=true;
        if (ultimateCircleButtonInterface(xWindowSize-50, 50, 40)&&txMouseButtons()&1)
            return 0;
        return 1;
    }

    bool secretFunction(int* ss)
    {
        switch(*ss)
        {
            case 0:
                if (GetAsyncKeyState('U')) *ss++;
                break;
            case 1:
                if (GetAsyncKeyState('M')) return 1;
                break;
            default:
                break;
                //{
                //   �� ����������� ��������, ��� �������� ����?
                //   �� � ��� �� ������? ���� ������ ��� �� ������ �� ��������
                //}
        }
        return 0;
    }

    bool chooseStart(int distanceOfStart, tank* t, int xOfCenter, int yOfCenter, double mapSize, int mapDat1, int mapDat2)
    {
        chooseStartInitialise(distanceOfStart, mapDat1, mapDat2);
        drawAvailablePlaceToStart(distanceOfStart, xOfCenter, yOfCenter, mapSize, mapDat1, mapDat2);
        int x=((txMouseX()-xOfCenter)/mapSize+mapDat2+1)/2,
            y=((txMouseY()-yOfCenter)/mapSize+mapDat1+1)/2;
        bool R;
        if (x>=0&&x<mapDat2&&y>=0&&y<mapDat1&&mapMas[y][x]==1)
        {
            drawMapGlowAvailable(x, y, xOfCenter, yOfCenter, mapSize, mapDat1, mapDat2);
            if (txMouseButtons()&1)
            {
                (*t).x=x;
                (*t).y=y;
                R=1;
            }
            else
                R=0;
        }
        chooseStartClear(mapDat1, mapDat2);
        return R;
    }

    //drawing
    void drawMap(int xOfCenter, int yOfCenter, double mapSize, int mapDat1, int mapDat2)
    {
        txSetColor(TX_BLACK, mapSize);
        txSetFillColor(TX_YELLOW);
        txRectangle(xOfCenter-(1+mapDat2)*mapSize, yOfCenter-(1+mapDat1)*mapSize, xOfCenter+(mapDat2-1)*mapSize, yOfCenter+(mapDat1-1)*mapSize);
        txSetColor(TX_BLACK);
        for (int i=0; i<mapDat1; i++)
        {
            for (int j=0; j<mapDat2; j++)
            {
                if (mapMas[i][j]==0)
                {
                    txSetColor(RGB(25, 25, 25));
                    txSetFillColor(RGB(25, 25, 25));
                }
                else
                {
                    txSetColor(TX_BLACK);
                    txSetFillColor(TX_WHITE);
                }
                txRectangle(xOfCenter-(mapDat2-j*2-1)*mapSize, yOfCenter-(mapDat1-i*2-1)*mapSize, xOfCenter-(mapDat2-j*2+1)*mapSize, yOfCenter-(mapDat1-i*2+1)*mapSize);
            }
        }
    }

    void drawWelcome(int xWindowSize, int yWindowSize)
    {
        txSetFillColor(TX_BLACK);
        txClear();
        txSetColor(TX_WHITE);
        txSetTextAlign(TA_CENTER);
        txSelectFont("Aharoni", 160);
        txTextOut(xWindowSize/2, yWindowSize/2-60, "TANKS OFFLINE");
        txSelectFont("Aharoni", 60);
        txTextOut(xWindowSize/2+170, yWindowSize/2+45, "beta");
        txSelectFont("Aharoni", 30);
        txTextOut(xWindowSize/2+260, yWindowSize/2+85, "v.0.59");

    }

    void drawMapInit(int xWindowSize, int yWindowSize)
    {
        txSetFillColor(TX_BLACK);
        txClear();
        txSetColor(TX_WHITE);
        txSelectFont("Aharoni", 30);
        txSetTextAlign(TA_CENTER);
        txTextOut(xWindowSize/2, yWindowSize/2, "creating map");
    }

    void drawMapLoad(int xWindowSize, int yWindowSize)
    {
        txSetFillColor(TX_BLACK);
        txClear();
        txSetColor(TX_WHITE);
        txSelectFont("Aharoni", 30);
        txSetTextAlign(TA_CENTER);
        txTextOut(xWindowSize/2, yWindowSize/2, "loading map");
    }

    void drawMapSaveFound(int xWindowSize, int yWindowSize)
    {
        txSetFillColor(TX_BLACK);
        txClear();
        txSetColor(TX_WHITE);
        txSelectFont("Aharoni", 30);
        txSetTextAlign(TA_CENTER);
        txTextOut(xWindowSize/2-25, yWindowSize/2-25, "saved map found. Load?\n");
        txTextOut(xWindowSize/2+15, yWindowSize/2+15, "Y - yes  N - no");
    }

    void drawMapGlowTank(tank t, int xOfCenter, int yOfCenter, double mapSize, int mapDat1, int mapDat2)
    {
        txSetFillColor(TX_YELLOW);
        txRectangle (   xOfCenter-(mapDat2-t.x*2-1)*mapSize,
                        yOfCenter-(mapDat1-t.y*2+1)*mapSize,
                        xOfCenter-(mapDat2-t.x*2+1)*mapSize,
                        yOfCenter-(mapDat1-t.y*2-1)*mapSize
                    );
    }

    void drawTank(tank t, int xOfCenter, int yOfCenter, double mapSize, int mapDat1, int mapDat2)
    {
        txSetColor(TX_BLACK);
        txSetFillColor(t.color);
        txCircle(xOfCenter-(mapDat2-t.x*2)*mapSize, yOfCenter-(mapDat1-t.y*2)*mapSize, mapSize/3);
    }

    void drawDefinitionChoose(int* xWindowSize, int* yWindowSize)
    {
        txCreateWindow(1920, 1080, true);
        while (!GetAsyncKeyState(VK_ESCAPE))
        {
            txSetColor(TX_RED, 2);
            txSetFillColor(TX_BLACK);
            txClear();
            txSetFillColor(TX_NULL);
            txRectangle(1920/2-*xWindowSize/2,
                        1080/2-*yWindowSize/2,
                        1920/2+*xWindowSize/2,
                        1080/2+*yWindowSize/2
                        );
            txSetTextAlign(TA_CENTER);
            txSetColor(TX_WHITE);
            txTextOut(1920/2-10, 1080/2-10, "CHOOSE RESOLUTION");
            txTextOut(1920/2, 1080/2, "ALIGN RED FRAMES TO WINDOW'S BOARDS");
            txTextOut(1920/2+10, 1080/2+10, "LEFT/RIGHT - HORIZONTAL  UP/DOWN - VERTICAL");
            txTextOut(1920/2+30, 1080/2+30, "ESC - CONFIRM");
            changeResolution(xWindowSize, yWindowSize);
            txSleep(1);
        }
    }

    void drawKekovuyTank(int x, int y, double k, int pozition,COLORREF tankColour)
    {
        if(pozition==1)
        {
            //wheels
            txSetFillColour(TX_BLACK);
            txSetColour(TX_BLACK, 0.04*k);
            txRectangle(x-0.6*k,y-0.8*k,x-0.4*k,y+0.8*k);
            txRectangle(x+0.6*k,y-0.8*k,x+0.4*k,y+0.8*k);
            //The main part
            txSetFillColour(tankColour);
            txRectangle(x-0.4*k,y-0.8*k,x+0.4*k,y+0.8*k);
            //The Top of tank
            txPie(x-0.4*k,y-0.2*k,x+0.4*k,y+0.6*k,180,180);
            POINT kuk[4]=
            {
                {x-0.4*k,y+0.2*k},
                {x-0.2*k,y-0.2*k},
                {x+0.2*k,y-0.2*k},
                {x+0.4*k,y+0.2*k}
            };
            txPolygon(kuk,4);
            txRectangle(x-0.1*k,y-0.9*k,x+0.1*k,y-0.2*k);
            txSetFillColour(tankColour);
            txSetColour(tankColour);
            txRectangle(x-0.38*k,y+0.23*k,x+0.38*k,y+0.17*k);
        }
        if(pozition==2)
        {
            //wheels
            txSetFillColour(TX_BLACK);
            txSetColour(TX_BLACK, 0.04*k);
            txRectangle(x-0.8*k,y-0.6*k,x+0.8*k,y-0.4*k);
            txRectangle(x-0.8*k,y+0.6*k,x+0.8*k,y+0.4*k);
            //The main part
            txSetFillColour(tankColour);
            txRectangle(x-0.8*k,y+0.4*k,x+0.8*k,y-0.4*k);
            //The Top of tank
            txPie(x-0.6*k,y-0.4*k,x+0.2*k,y+0.4*k,90,180);
            POINT kuk[4]=
            {
                {x-0.2*k,y-0.4*k},
                {x+0.2*k,y-0.2*k},
                {x+0.2*k,y+0.2*k},
                {x-0.2*k,y+0.4*k}
            };
            txPolygon(kuk,4);
            txRectangle(x+0.9*k,y+0.1*k,x+0.2*k,y-0.1*k);
            txSetFillColour(tankColour);
            txSetColour(tankColour);
            txRectangle(x-0.23*k,y+0.38*k,x-0.17*k,y-0.38*k);
        }
        if(pozition==3)
        {
            //wheels
            txSetFillColour(TX_BLACK);
            txSetColour(TX_BLACK, 0.04*k);
            txRectangle(x-0.6*k,y-0.8*k,x-0.4*k,y+0.8*k);
            txRectangle(x+0.6*k,y-0.8*k,x+0.4*k,y+0.8*k);
            //The main part
            txSetFillColour(tankColour);
            txRectangle(x-0.4*k,y-0.8*k,x+0.4*k,y+0.8*k);
            //The Top of tank
            txPie(x-0.4*k,y+0.2*k,x+0.4*k,y-0.6*k,0,180);
            POINT kuk[4]=
            {
                {x-0.4*k,y-0.2*k},
                {x-0.2*k,y+0.2*k},
                {x+0.2*k,y+0.2*k},
                {x+0.4*k,y-0.2*k}
            };
            txPolygon(kuk,4);
            txRectangle(x-0.1*k,y+0.9*k,x+0.1*k,y+0.2*k);
            txSetFillColour(tankColour);
            txSetColour(tankColour);
            txRectangle(x-0.38*k,y-0.17*k,x+0.38*k,y-0.23*k);
        }
        if(pozition==4)
        {
            //wheels
            txSetFillColour(TX_BLACK);
            txSetColour(TX_BLACK, 0.04*k);
            txRectangle(x-0.8*k,y-0.6*k,x+0.8*k,y-0.4*k);
            txRectangle(x-0.8*k,y+0.6*k,x+0.8*k,y+0.4*k);
            //The main part
            txSetFillColour(tankColour);
            txRectangle(x-0.8*k,y+0.4*k,x+0.8*k,y-0.4*k);
            //The Top of tank
            txPie(x-0.2*k,y-0.4*k,x+0.6*k,y+0.4*k,270,180);
            POINT kuk[4]=
            {
                {x+0.2*k,y-0.4*k},
                {x-0.2*k,y-0.2*k},
                {x-0.2*k,y+0.2*k},
                {x+0.2*k,y+0.4*k}
            };
            txPolygon(kuk,4);
            txRectangle(x-0.9*k,y+0.1*k,x-0.2*k,y-0.1*k);
            txSetFillColour(tankColour);
            txSetColour(tankColour);
            txRectangle(x+0.23*k,y+0.38*k,x+0.17*k,y-0.38*k);
        }
    }

    void drawTankStat(tank t[], int tankAmount, int xWindowSize, int yWindowSize, int turn)
    {
        txSetColor(TX_BLACK, 3);
        txSetFillColor(RGB(142, 159, 145));
        POINT statWindow[5]=
        {
            {-10, 0},
            {xWindowSize/4, 0},
            {xWindowSize/4+20, 20},
            {xWindowSize/4+20, yWindowSize-50},
            {-10, yWindowSize-50}
        };
        txPolygon(statWindow, 5);
        txSetFillColor(RGB(0 ,179, 0));
        POINT buttons[4]=
        {
            {-10, yWindowSize-50},
            {xWindowSize/4+20, yWindowSize-50},
            {xWindowSize/4+20, yWindowSize+10},
            {-10, yWindowSize+10}
        };
        txPolygon(buttons, 4);
        txSetFillColor(t[turn].color);
        if (turn==0)
        {
            POINT thisTankTurn[5]=
            {
                {-10, 0},
                {xWindowSize/4, 0},
                {xWindowSize/4+20, 20},
                {xWindowSize/4+20, (yWindowSize-50)/tankAmount},
                {-10, (yWindowSize-50)/tankAmount}
            };
            txPolygon(thisTankTurn, 5);

        }
        else
        {
            POINT thisTankTurn[4]=
            {
                {-10, (yWindowSize-50)/tankAmount*turn},
                {xWindowSize/4+20, (yWindowSize-50)/tankAmount*turn},
                {xWindowSize/4+20, (yWindowSize-50)/tankAmount*(turn+1)},
                {-10, (yWindowSize-50)/tankAmount*(turn+1)}
            };
            txPolygon(thisTankTurn, 4);
        }

        if (t[turn].statSpeed==0&&t[turn].attacked==1)
            txSetFillColor(RGB(54, 194, 41));
        else if (t[turn].statSpeed==t[turn].statSpeedMax&&t[turn].attacked==0)
            txSetFillColor(RGB(187, 43, 43));
        else
            txSetFillColor(RGB(194, 194, 41));
        txLine(80, yWindowSize-50, 80, yWindowSize);
        txRectangle(xWindowSize/4-125, yWindowSize-50, xWindowSize/4+20, yWindowSize+10);
        txSelectFont("Aharoni", 40);
        txSetTextAlign(TA_CENTER);
        txDrawText(0, yWindowSize-40, xWindowSize/4-125, yWindowSize, "Menu", TA_LEFT);
        txTextOut(xWindowSize/4-50, yWindowSize-40, "End turn");

        for (int i = 1; i < tankAmount; i ++)
        {
            txLine(0, (yWindowSize-50)/tankAmount*i, xWindowSize/4+20, (yWindowSize-50)/tankAmount*i);
        }
        txSelectFont("Aharoni", 40);
        txSetTextAlign(TA_LEFT);
        for (int i = 0; i < tankAmount; i ++)
        {
            string s;
            if (t[i].deathTime>0)
            {
                txSetTextAlign(TA_LEFT);
                s="DEAD";
                char c5[s.length()];
                toMasOfChar(s, c5);
                txTextOut(20, (yWindowSize-50)/tankAmount*(i+0.1), c5);
                s="Respawn: "+toString(t[i].deathTime)+" turns";
                char c6[s.length()];
                toMasOfChar(s, c6);
                txTextOut(10, (yWindowSize-50)/tankAmount-50, c5);
            }
            txSetTextAlign(TA_RIGHT);
            s=toString(t[i].distributionPoints)+" points";
            char c0[s.length()];
            toMasOfChar(s, c0);
            txTextOut(xWindowSize/4-20, (yWindowSize-50)/tankAmount*(i+0.05), c0);
            txSetTextAlign(TA_LEFT);
            s=toString(t[i].statHealth)+'/'+toString(t[i].statHealthMax);
            char c1[s.length()];
            toMasOfChar(s, c1);
            txTextOut(xWindowSize/10, (yWindowSize-50)/tankAmount*(i+0.25), c1);
            drawHP(xWindowSize/10-15, (yWindowSize-50)/tankAmount*(i+0.25)+11, 11);
            s=toString (t[i].statAttack);
            char c2[s.length()];
            toMasOfChar(s, c2);
            txTextOut(xWindowSize/12, (yWindowSize-50)/tankAmount*(i+0.5), c2);
            drawAttack(xWindowSize/12-15, (yWindowSize-50)/tankAmount*(i+0.5)+11, 12);
            s=toString(t[i].statSpeed)+'/'+toString(t[i].statSpeedMax);
            char c3[s.length()];
            toMasOfChar(s, c3);
            txTextOut(xWindowSize/12, (yWindowSize-50)/tankAmount*(i+0.75), c3);
            s=toString(t[i].statAim);
            char c4[s.length()];
            toMasOfChar(s, c4);
            txTextOut(xWindowSize/4-20, (yWindowSize-50)/tankAmount*(i+0.75), c4);
        }
    }

    void drawTankMovementGlow(bool a, int x, int y, int xOfCenter, int yOfCenter, double mapSize, int mapDat1, int mapDat2)
    {
        if (a==1)
            txSetFillColor(RGB(0, 162, 232));
            else
            txSetFillColor(RGB(192, 200, 200));
        txRectangle (   xOfCenter-(mapDat2-x*2+1)*mapSize,
                        yOfCenter-(mapDat1-y*2+1)*mapSize,
                        xOfCenter-(mapDat2-x*2-1)*mapSize,
                        yOfCenter-(mapDat1-y*2-1)*mapSize
                    );
    }

    void drawTankAttackGlow(int x, int y, int xOfCenter, int yOfCenter, double mapSize, int mapDat1, int mapDat2)
    {
        txSetFillColor(TX_RED);
        txRectangle (   xOfCenter-(mapDat2-x*2+1)*mapSize,
                        yOfCenter-(mapDat1-y*2+1)*mapSize,
                        xOfCenter-(mapDat2-x*2-1)*mapSize,
                        yOfCenter-(mapDat1-y*2-1)*mapSize
                    );
    }

    void drawNewTurn(int number, int timeTurnChange, int xWindowSize, int yWindowSize)
    {
        txSetFillColor(TX_WHITE);
        txSetColor(TX_BLACK);
        if (timeTurnChange>10) timeTurnChange=10;
        if (timeTurnChange==-1)
            txRectangle(    xWindowSize/2-300,
                            -1,
                            xWindowSize/2+300,
                            60
                        );

        else
            txRectangle(    xWindowSize/2-200,
                            -60+timeTurnChange*yWindowSize/20,
                            xWindowSize/2+200,
                            60+timeTurnChange*yWindowSize/20
                        );
        string s;
        if (timeTurnChange==-1)
            s="Player"+toString (number)+", choose a cell to spawn";
        else
            s="Player"+toString (number)+", Your turn!";
        char c[s.length()];
        toMasOfChar(s, c);
        txSetTextAlign(TA_CENTER);
        txSelectFont("Aharoni", 40);
        if (timeTurnChange==-1)
            txTextOut(xWindowSize/2, 10, c);
        else
            txTextOut(xWindowSize/2, timeTurnChange * yWindowSize / 20-20, c);
    }

    void drawButtonAddPerk(int xCenter, int yCenter, int radius, COLORREF fillColor, COLORREF crossColor, int thickness)
    {
        if (thickness<1) thickness=1;
        if (thickness>5) thickness=5;
        txSetColor(TX_BLACK, 3);
        txSetFillColor(fillColor);
        txCircle(xCenter, yCenter, radius);
        txSetFillColor(crossColor);
        POINT cross[12]=
        {
            {xCenter+radius/4, yCenter-radius*13/20},
            {xCenter+radius/4, yCenter-radius/4},
            {xCenter+radius*13/20, yCenter-radius/4},
            {xCenter+radius*13/20, yCenter+radius/4},
            {xCenter+radius/4, yCenter+radius/4},
            {xCenter+radius/4, yCenter+radius*13/20},
            {xCenter-radius/4, yCenter+radius*13/20},
            {xCenter-radius/4, yCenter+radius/4},
            {xCenter-radius*13/20, yCenter+radius/4},
            {xCenter-radius*13/20, yCenter-radius/4},
            {xCenter-radius/4, yCenter-radius/4},
            {xCenter-radius/4, yCenter-radius*13/20}
        };
        txPolygon(cross, 12);
    }

    void drawMenu(int XWINDOWSIZE, int YWINDOWSIZE)
    {
        txSetFillColor(TX_WHITE);
        txClear();
        txSetColor(TX_BLACK);
        txSetTextAlign(TA_CENTER);
        txSelectFont("Aharoni", 80);
        txTextOut(XWINDOWSIZE/2, 60, "TANKS OFFLINE");
        txSelectFont("Aharoni", 30);
        txTextOut(XWINDOWSIZE/2+170, 105, "beta");
        txSelectFont("Aharoni", 15);
        txTextOut(XWINDOWSIZE/2+220, 117, "v.0.59");
        txSetTextAlign(TA_RIGHT);
        txSetColor(RGB(150, 150, 150));
        txTextOut(XWINDOWSIZE, YWINDOWSIZE-45, "v. 0.59");
        txTextOut(XWINDOWSIZE, YWINDOWSIZE-25, "ProfiTROLLI_Studios(C) All rights reserved");
    }

    void drawButtonForMenuExit(int XCENTER, int YCENTER, int RADIUS, COLORREF FILLCOLOR, COLORREF CROSSCOLOR)
    {
        txSetColor(TX_BLACK, 3);
        txSetFillColor(FILLCOLOR);
        txCircle(XCENTER, YCENTER, RADIUS);
        txSetFillColor(CROSSCOLOR);
        POINT cross[12]
        {
            {XCENTER, YCENTER-RADIUS/4},
            {XCENTER+RADIUS*9/20, YCENTER-RADIUS*7/10},
            {XCENTER+RADIUS*7/10, YCENTER-RADIUS*9/20},
            {XCENTER+RADIUS/4, YCENTER},
            {XCENTER+RADIUS*7/10, YCENTER+RADIUS*9/20},
            {XCENTER+RADIUS*9/20, YCENTER+RADIUS*7/10},
            {XCENTER, YCENTER+RADIUS/4},
            {XCENTER-RADIUS*9/20, YCENTER+RADIUS*7/10},
            {XCENTER-RADIUS*7/10, YCENTER+RADIUS*9/20},
            {XCENTER-RADIUS/4, YCENTER},
            {XCENTER-RADIUS*7/10, YCENTER-RADIUS*9/20},
            {XCENTER-RADIUS*9/20, YCENTER-RADIUS*7/10}
        };
        txPolygon(cross, 12);
    }

    void drawButtonForMenuStartGame(int XCENTER, int YCENTER, COLORREF COLOR, bool notStartButContinue)
    {
        txSetColor(TX_BLACK, 3);
        txSetFillColor(COLOR);
        txSelectFont("Aharoni", 50);
        txRectangle(XCENTER-120,
                    YCENTER-60,
                    XCENTER+120,
                    YCENTER+60
                    );
        txSetTextAlign(TA_CENTER);
        if (notStartButContinue)
            txDrawText( XCENTER-120,
                        YCENTER-60,
                        XCENTER+120,
                        YCENTER+60,
                        "Continue"
                        );
        else
            txDrawText( XCENTER-120,
                        YCENTER-60,
                        XCENTER+120,
                        YCENTER+60,
                        "Start Game"
                        );

    }

    void drawButtonForMenuMapRedactor(int XCENTER, int YCENTER, COLORREF COLOR, bool comingSoon)
    {
        txSetColor(TX_BLACK, 3);
        txSetFillColor(COLOR);
        if (comingSoon)
            txSetFillColor(RGB(50, 50, 50));
        txSelectFont("Aharoni", 50);
            txSetTextAlign(TA_CENTER);
        txRectangle(XCENTER-120,
                    YCENTER-60,
                    XCENTER+120,
                    YCENTER+60
                    );
        txDrawText( XCENTER-120,
                    YCENTER-60,
                    XCENTER+120,
                    YCENTER+60,
                    "Map Redactor"
                    );
        if (comingSoon)
        {
            txSelectFont("Aharoni", 40);
            txDrawText( XCENTER-100,
                        YCENTER+60,
                        XCENTER+100,
                        YCENTER+110,
                        "Coming soon"
                        );
        }
    }

    void drawHP(int x,int y, double k)
    {
        txSetFillColour(TX_RED);
        txSetColour(TX_BLACK);
        POINT kuk[10]=
        {
            {x,y+k},
            {x-k,y},
            {x-k,y-0.25*k},
            {x-0.75*k,y-0.5*k},
            {x-0.25*k,y-0.5*k},
            {x,y-0.25*k},
            {x+0.25*k,y-0.5*k},
            {x+0.75*k,y-0.5*k},
            {x+k,y-0.25*k},
            {x+k,y}

        };
        txPolygon(kuk,10);
    }

    void drawAvailablePlaceToStart(int distanceOfStart, int xOfCenter, int yOfCenter, double mapSize, int mapDat1, int mapDat2)
    {
        txSetColor(TX_BLACK);
        txSetFillColor(RGB(255, 255, 170));
        for (int i = 0; i < mapDat1; i ++)
            for (int j = 0; j < mapDat2; j ++)
                if (mapMas[i][j]==1)
                    txRectangle(xOfCenter-(mapDat2-j*2+1)*mapSize,
                                yOfCenter-(mapDat1-i*2+1)*mapSize,
                                xOfCenter-(mapDat2-j*2-1)*mapSize,
                                yOfCenter-(mapDat1-i*2-1)*mapSize
                               );
    }

    void drawMapGlowAvailable(int x, int y, int xOfCenter, int yOfCenter, double mapSize, int mapDat1, int mapDat2)
    {
        txSetFillColor(TX_YELLOW);
        txRectangle (   xOfCenter-(mapDat2-x*2-1)*mapSize,
                        yOfCenter-(mapDat1-y*2+1)*mapSize,
                        xOfCenter-(mapDat2-x*2+1)*mapSize,
                        yOfCenter-(mapDat1-y*2-1)*mapSize
                    );
    }

    void drawBoom(tank t, int xOfCenter, int yOfCenter, double mapSize, int mapDat1, int mapDat2, int boomCd)
    {
        txSetColor(TX_BLACK);
        txSetFillColor(TX_WHITE);
        txRectangle (   xOfCenter-(mapDat2-t.x*2-1)*mapSize-boomCd,
                        yOfCenter-(mapDat1-t.y*2+1)*mapSize+boomCd/2-15,
                        xOfCenter-(mapDat2-t.x*2-1)*mapSize-boomCd+60,
                        yOfCenter-(mapDat1-t.y*2+1)*mapSize+25+boomCd/2
                    );
        txSetTextAlign(TA_CENTER);
        txSelectFont("Aharoni", 20);
        txDrawText(     xOfCenter-(mapDat2-t.x*2-1)*mapSize-(boomCd),
                        yOfCenter-(mapDat1-t.y*2+1)*mapSize+(boomCd/2)-15,
                        xOfCenter-(mapDat2-t.x*2-1)*mapSize-(boomCd)+60,
                        yOfCenter-(mapDat1-t.y*2+1)*mapSize+25+(boomCd/2),
                        "BOOM");
    }

    void drawAttack(int x,int y, double k)
    {
        COLORREF cvet=RGB(220,220,220);
        txSetFillColour(cvet);
        txSetColour(TX_BLACK,0.05*k);

        POINT kuk1[13]=
        {
            {x,y+k},
            {x-0.3*k,y+0.7*k},
            {x-0.6*k,y+k},
            {x-k,y+0.6*k},
            {x-0.7*k,y+0.3*k},
            {x-k,y},
            {x-0.8*k,y-0.2*k},
            {x-0.5*k,y+0.1*k},
            {x+0.6*k,y-k},
            {x+k,y-k},
            {x+k,y-0.6*k},
            {x-0.1*k,y+0.5*k},
            {x+0.2*k,y+0.8*k}
        };

        POINT kuk2[5]=
        {
            {x-0.4*k,y},
            {x-k,y-0.6*k},
            {x-k,y-k},
            {x-0.6*k,y-k},
            {x,y-0.4*k}
        };
        POINT kuk3[12]=
        {
            {x+0.4*k,y},
            {x+0.5*k,y+0.1*k},
            {x+0.8*k,y-0.2*k},
            {x+k,y},
            {x+0.7*k,y+0.3*k},
            {x+k,y+0.6*k},
            {x+0.6*k,y+k},
            {x+0.3*k,y+0.7*k},
            {x+0.2*k,y+0.8*k},
            {x,y+0.6*k},
            {x+0.1*k,y+0.5*k},
            {x,y+0.4*k}
        };
        txPolygon(kuk1,13);
        txPolygon(kuk2,5);
        txPolygon(kuk3,12);
        txLine(x-0.8*k,y-0.8*k,x-0.2*k,y-0.2*k);
        txLine(x+0.2*k,y+0.2*k,x+0.3*k,y+0.3*k);
        txLine(x-0.3*k,y+0.3*k,x+0.8*k,y-0.8*k);
    }
