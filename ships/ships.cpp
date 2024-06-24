#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
using namespace std;

struct ships
{
	int number;
	string block;
	int x, y;
};


struct point
{
	int x, y;
};


void SetCursor(int x, int y)
{
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { x,y };
	SetConsoleCursorPosition(hstdout, coord);
}

/*
COORD GetCursorPisotion()
{
	HANDLE HSTDOUT = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(HSTDOUT, &consoleInfo);
	return consoleInfo.dwCursorPosition;
}*/


void printCursor(vector<point>& points)
{
	for (int i = 0; i < points.size();i++)
	{
		SetCursor(points[0].x, points[0].y);
		cout << "$";
	}
}



void clearCursor(int cursorMove[], vector<point>& points)
{
	for (int i = 0; i < points.size();i++)
	{
		SetCursor(points[i].x, points[i].y);
		cout << " ";
	}
	points[0].x += cursorMove[0];
	points[0].y += cursorMove[1];
	printCursor(points);
}



void printFields()
{
	// меню

	SetCursor(80, 5);
	cout << "1 block ship";
	SetCursor(80, 6);
	cout << "2 block ship";



	// 1 поле
	
	for (int x = 0;x < 21; x++)
	{
		SetCursor(x, 0);
		cout << "#";
	}
	for (int x = 0;x < 21; x++)
	{
		SetCursor(x, 9);
		cout << "#" << " ";
	}
	for (int y = 0;y < 9; y++)
	{
		SetCursor(0, y);
		cout << "#";
	}
	for (int y = 0;y < 9; y++)
	{
		SetCursor(20, y);
		cout << "#";
	}	

	// 2 поле


	for (int y = 0;y < 9; y++)
	{
		SetCursor(40, y);
		cout << '#';
	}
	for (int y = 0;y <9; y++)
	{
		SetCursor(60, y);
		cout << '#';
	}
	for (int x = 40;x < 61; x++)
	{
		SetCursor(x, 9);
		cout << '#';
	}
	for (int x = 40;x < 61; x++)
	{
		SetCursor(x, 0);
		cout << '#';
	}
}



ships shipsInit(int count, point positionShip)
{
	ships newShip;
	switch (count)
	{
	case 1: newShip.number = 1;
			newShip.block = "$";
			newShip.x = positionShip.x;
			newShip.y = positionShip.y;;
		; break;
	case 2: newShip.number = 2;
			newShip.block = "$$";
			newShip.x = positionShip.x;
			newShip.y = positionShip.y;;
		; break;
	case 3: newShip.number = 3;
			newShip.block = "$$$";
			newShip.x = positionShip.x;
			newShip.y = positionShip.y;;
		; break;
	case 4: newShip.number = 4;
			newShip.block = "$$$$";
			newShip.x = positionShip.x;
			newShip.y = positionShip.y;;
		; break;
	}	
	return newShip;
}


void printShips(ships ship)
{
	SetCursor(ship.x, ship.y);
	 cout << ship.block; 
}


void chooseShip()
{

}


int main()
{
	vector<point> points;
	vector<point> positionShip;
	vector<point> countCoordinateShips;
	int shipCountBlock[4] = { 0,0,0,0 };
	point first;
	first.x = 5;
	first.y = 5;
	points.push_back(first);
	int cursorInit[2] = { 5,5 };
	system("cls");
	printFields();
	ships mas[5];
	int cursorMove[2] = { 0,0 };
	while (1)
	{
		
		if (GetAsyncKeyState(VK_RIGHT)) {
			cursorMove[0] = 1;
			cursorMove[1] = 0;
			clearCursor(cursorMove, points);	
		}
		if (GetAsyncKeyState(VK_DOWN)) {
			cursorMove[0] = 0;
			cursorMove[1] = 1;
			clearCursor(cursorMove, points);			
		}
		if (GetAsyncKeyState(VK_LEFT)) {
			cursorMove[0] = -1;
			cursorMove[1] = 0;
			clearCursor(cursorMove, points);
		}
		if (GetAsyncKeyState(VK_UP)) {
			cursorMove[0] = 0;
			cursorMove[1] = -1;
			clearCursor(cursorMove, points);
		}
		if (GetAsyncKeyState(VK_SPACE)) {
			if (points[0].x > 0 && points[0].x < 20 && points[0].y > 0 && points[0].y < 10)
			{
				
				point CoordinateShips;
				CoordinateShips.x = points[0].x;
				CoordinateShips.y = points[0].y;
				countCoordinateShips.push_back(CoordinateShips);
				SetCursor(points[0].x, points[0].y);
				cout << " ";
				positionShip.push_back(first);
				points[0].x = 93;
				points[0].y = 5;
				clearCursor(cursorMove, points);
			}
			if (points[0].x == 93 && points[0].y == 5)
			{
					int oldx, oldy;
					point coordinate = countCoordinateShips.back();
					oldx = coordinate.x;
					oldy = coordinate.y;
					shipCountBlock[0] = 1;
					SetCursor(points[0].x, points[0].y);
					cout << " ";
					points[0].x = oldx+5;
					points[0].y = oldy;
					printShips(shipsInit(shipCountBlock[0], coordinate));
			}
			if (points[0].x == 93 && points[0].y == 6)
			{
				int oldx, oldy;
				point coordinate = countCoordinateShips.back();
				oldx = coordinate.x;
				oldy = coordinate.y;
				shipCountBlock[1] = 2;
				SetCursor(points[0].x, points[0].y);
				cout << " ";
				points[0].x = oldx + 5;
				points[0].y = oldy;
				printShips(shipsInit(shipCountBlock[1], coordinate));
			}

		//	}
		}
		
		Sleep(300);
	}

	
}