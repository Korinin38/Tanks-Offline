    #include "TanksLib.h"
    using namespace std;

    int main()
    {
        double mapSize=15;

        int xWindowSize=1276,
            yWindowSize=800,
            xOfCenter=xWindowSize/2,
            yOfCenter=yWindowSize/2,
            mapDat1=10,
            mapDat2=10,
            po=0,
            pi=0,
            pe=0,
            tankAmount=2,
            timeMouseTankIgnore=0,
            timeMouseTankMoveIgnore=0,
            timeMouseTankAttackIgnore=0,
            timeTurnChange=0,
            timeMouseNewTurnIgnore=0,
            timeMouseButtonAddPerkIgnore=0,
            nowIsTurnOf,
            recurrectionTime=3,
            distanceOfStart=std::min(mapDat1, mapDat2)/4,
            boomed=-1;

        bool    menuIn=0,
                gameOver=0,
                turnChange=1,
                mainButtonAddPerkClicked=0,
                iSwearItIsLast=0;

        tank t[tankAmount];
            t[0].color=TX_BLUE;
            t[1].color=TX_RED;

        txBegin();
        if (!windowSizeChooseAndConfirmation(&xWindowSize, &yWindowSize)) return 0;
        srand(time(NULL));
        txCreateWindow (xWindowSize, yWindowSize);
        xOfCenter=xWindowSize/2;
        yOfCenter=yWindowSize/2;
        drawWelcome(xWindowSize, yWindowSize);
        txSleep(1000);
        do
        {
            txSleep(10);
            drawMenu(xWindowSize, yWindowSize);
            drawButtonForMenuStartGame(xWindowSize/4, yWindowSize/2, RGB(16, 127, 135), iSwearItIsLast);
            drawButtonForMenuMapRedactor(xWindowSize*3/4, yWindowSize/2, RGB(16, 127, 135), true);
            drawButtonForMenuExit(xWindowSize-50, 50, 40, RGB(237, 28, 36), RGB(215, 215, 215));
            if (GetAsyncKeyState('R'))
                iSwearItIsLast=0;
            if (menuIn)
            {
                if (iSwearItIsLast==0)
                {
                    for (int i = 0; i < tankAmount; i ++)
                    {
                        t[i].x=-1;
                        t[i].y=-1;
                        t[i].position=rand()%4+1;
                        t[i].statHealthMax=100;
                        t[i].statHealth=t[i].statHealthMax;
                        t[i].statAttack=10;
                        t[i].statSpeedMax=2;
                        t[i].statAim=2;
                        t[i].clicked=0;
                        t[i].attacked=0;
                        t[i].distributionPoints=50;
                        t[i].deathTime=1;
                    }
                    bool counter=0, counterWhile=0;
                    if (mapSavedChecker())
                    {
                        drawMapSaveFound(xWindowSize, yWindowSize);
                        while (counterWhile==0)
                        {
                            if (GetAsyncKeyState('Y'))
                            {
                                counter=1;
                                counterWhile=1;
                            }
                            if (GetAsyncKeyState('N'))
                            {
                                counter=0;
                                counterWhile=1;
                            }
                        }
                    }
                    mapInitializer(counter, &mapDat1, &mapDat2);
                    drawMapInit(xWindowSize, yWindowSize);
                    txSleep(500);
                    drawMapLoad(xWindowSize, yWindowSize);
                    correctMapChecker(0, mapDat1, mapDat2);
                    txSleep(1000);
                    nowIsTurnOf=rand()%tankAmount;
                    iSwearItIsLast=1;
                    turnChange=1;
                }
                while (iSwearItIsLast&&menuIn)
                {
                    txSetFillColor(TX_WHITE);
                    txClear();
                    interfaceOfMap(&mapSize, &xOfCenter, &yOfCenter);
                    drawMap(xOfCenter, yOfCenter, mapSize, mapDat1, mapDat2);
                    interfaceTankMoveCheck(t, xOfCenter, yOfCenter, mapSize, mapDat1, mapDat2, tankAmount, &timeMouseTankIgnore, &timeMouseTankAttackIgnore, nowIsTurnOf, &boomed);
                    if (t[nowIsTurnOf].clicked && timeMouseTankMoveIgnore==0&&t[nowIsTurnOf].statSpeed>0)
                        {
                            mouseklikswhatcansupportustomovetank(&t[nowIsTurnOf],  xOfCenter,  yOfCenter, mapSize,  mapDat1,  mapDat2, &timeMouseTankMoveIgnore, &timeMouseTankIgnore);
                        }
                    for(int i = 0; i < tankAmount; i ++)
                    {
                        if (t[i].statHealth<=0&&t[i].deathTime==0)
                        {
                            t[nowIsTurnOf].distributionPoints+=25;
                            t[i].statHealth=0;
                            t[i].deathTime=3;
                            mapMas[t[i].y][t[i].x]=1;
                            t[i].x=-1;
                            t[i].y=-1;
                        }
                        if (t[i].deathTime==0) drawKekovuyTank((int)(xOfCenter-(mapDat2-t[i].x*2)*mapSize), (int)(yOfCenter-(mapDat1-t[i].y*2)*mapSize), mapSize, t[i].position, t[i].color);
                    }
                    drawTankStat(t, tankAmount, xWindowSize, yWindowSize, nowIsTurnOf);
                    if (timeMouseTankAttackIgnore>0)
                        drawBoom(t[boomed], xOfCenter, yOfCenter, mapSize, mapDat1, mapDat2, timeMouseTankAttackIgnore);
                    buttonsAddPerk(xWindowSize, yWindowSize, &t[nowIsTurnOf], tankAmount, nowIsTurnOf, &mainButtonAddPerkClicked, &timeMouseButtonAddPerkIgnore);
                    if (turnChange)
                    {
                        if (timeTurnChange==0)
                        {
                            timeTurnChange=40;
                            nowIsTurnOf=(nowIsTurnOf+1)%tankAmount;
                            while (t[nowIsTurnOf].deathTime>1)
                            {
                                t[nowIsTurnOf].deathTime--;
                                nowIsTurnOf=(nowIsTurnOf+1)%tankAmount;
                            }
                            mainButtonAddPerkClicked=0;
                            for (int i = 0; i < tankAmount; i ++)
                            {
                                t[i].statSpeed=t[i].statSpeedMax;
                                t[i].clicked=0;
                                t[i].attacked=0;
                            }
                            t[nowIsTurnOf].distributionPoints+=5;
                            txSleep(50);
                        }
                        if (t[nowIsTurnOf].deathTime==1)
                        {
                            timeTurnChange=-1;
                            if (chooseStart(distanceOfStart, &t[nowIsTurnOf], xOfCenter, yOfCenter, mapSize, mapDat1, mapDat2))
                            {
                                t[nowIsTurnOf].statHealth=t[nowIsTurnOf].statHealthMax;
                                t[nowIsTurnOf].deathTime=0;
                                mapMas[t[nowIsTurnOf].y][t[nowIsTurnOf].x]=2;
                                timeTurnChange=0;
                                turnChange=1;
                            }
                        }
                        if (timeTurnChange==1) turnChange=0;
                        drawNewTurn(nowIsTurnOf+1, timeTurnChange, xWindowSize, yWindowSize);
                    }
                    if (t[nowIsTurnOf].statSpeed!=t[nowIsTurnOf].statSpeedMax||t[nowIsTurnOf].attacked==1)
                        buttonEndTurn(xWindowSize/4-50, yWindowSize-20, &timeMouseNewTurnIgnore, &turnChange);
                    if (GetAsyncKeyState(VK_ESCAPE)) menuIn=0;
                    if (pi==0)
                    {
                        if (secretFunction(&po)) pi=1;
                        mapBoundController(&xOfCenter, &yOfCenter, mapDat1, mapDat2, mapSize, xWindowSize, yWindowSize);
                    }
                    // if(secretFunction1(&pe)) t[nowIsTurnOf].attacked=0;
                    //time of ignore
                    if (timeMouseTankIgnore>0) timeMouseTankIgnore--;
                    if (timeMouseTankMoveIgnore>0)timeMouseTankMoveIgnore--;
                    if (timeMouseTankAttackIgnore>0)timeMouseTankAttackIgnore--;
                    if (timeTurnChange>0) timeTurnChange--;
                    if (timeMouseNewTurnIgnore>0) timeMouseNewTurnIgnore--;
                    if (timeMouseButtonAddPerkIgnore>0) timeMouseButtonAddPerkIgnore--;
                    txSleep(30);
                    buttonEndGame(5, yWindowSize-20, &menuIn);
                    if (GetAsyncKeyState('R'))
                    {
                        iSwearItIsLast=0;
                        menuIn=0;
                    }
                }
            }
        }
        while(interfaceMenuButtons(xWindowSize, yWindowSize, &menuIn)&&!GetAsyncKeyState(VK_ESCAPE));
        drawGTHOH(xWindowSize, yWindowSize);
        return 0;
    }
