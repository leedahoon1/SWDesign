#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "ItemDesign.h"
#pragma warning (disable:4996)

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
COORD MyGetCursor();
void MySetCursor(int x, int y);
void RemoveCursor();
void RunGame();
void StartGame();
void ShowHelp();
void ExitGame();
void DrawGameBoard();
void ShiftRight();
void ShiftLeft();
void ShiftDown();
void ShiftUp();
void KeyInput();
int curPosX, curPosY;

int main()
{
	RunGame();

	return 0;
}

void RemoveCursor()
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

void MySetCursor(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

COORD MyGetCursor()
{
	COORD curPoint;
	CONSOLE_SCREEN_BUFFER_INFO curInfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curPoint.X = curInfo.dwCursorPosition.X;
	curPoint.Y = curInfo.dwCursorPosition.Y;

	return curPoint;
}

void RunGame()
{
	system("mode con cols=150 lines=40");

	while (1)
	{
		MySetCursor(50, 5);
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 28; j++)
			{
				MySetCursor(50 + j * 2, 5 + i);
				if (title[i][j] == 1)
					printf("﹥");
			}
			printf("\n");
		}

		MySetCursor(70, 20);
		printf("1 : PLAY GAME");

		MySetCursor(70, 22);
		printf("2 : HELP");

		MySetCursor(70, 24);
		printf("3 : EXIT");

		char selectMenu = getch();

		if (selectMenu == '1')
		{
			StartGame();
			break;
		}
		else if (selectMenu == '2')
		{
			ShowHelp();
			break;
		}
		else if (selectMenu == '3')
		{
			ExitGame();
			break;
		}
		else
		{
			continue;
		}
	}
}

void StartGame()
{
	system("cls");
	DrawGameBoard();
	MySetCursor(0, 22);
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛 �香嚃蛾�   - Q 100埤萄             ⑷營 埤萄  - 300 弛\n");
	printf("弛 渠ん顫錶   - W 200埤萄             蝶纔檜雖   -  1  弛\n");
	printf("弛 蝸煎辦顫錶 - E 200 埤萄                             弛\n");
	printf("弛 嘐餌橾顫錶 - R 300 埤萄            ァ驕       -  A  弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
	MySetCursor(96, 27);
	printf("ⅥⅥⅥⅥⅥⅥⅥⅥⅥⅥⅥⅥ");

	while (1)
	{
		while (1)
		{
			KeyInput();
		}
	}
}

void ShowHelp()
{
	system("cls");
}

void ExitGame()
{
	system("cls");
	printf("模Щお錚橫 晦蟾撲啗 2奩 6褻\n");
	printf("夢鼻辦\n檜棻�躡n檜謙錳\n夢繹辦\n");
	printf("===================================\n");
	printf("contact us : psw7205@gmail.com\n");
	printf("https://github.com/psw7205/SWDesign\n");
}

void DrawGameBoard()
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 60; j++)
		{
			MySetCursor(j * 2, i);
			if (mapModel[i][j] == 1)
				printf("#");
		}
		printf("\n");
	}
}

void ShiftRight()
{
	curPosX += 2;
	MySetCursor(curPosX, curPosY);
	return;
}

void ShiftLeft()
{
	curPosX -= 2;
	MySetCursor(curPosX, curPosY);
	return;

}

void ShiftDown()
{
	curPosY++;
	MySetCursor(curPosX, curPosY);
	return;
}

void ShiftUp()
{
	curPosY--;
	MySetCursor(curPosX, curPosY);
	return;
}

void KeyInput()
{
	char key;

	for (int i = 0; i < 20; i++)
	{
		if (_kbhit() != 0)
		{

			key = _getch();

			switch (key)
			{
			case LEFT:
				ShiftLeft();
				break;
			case RIGHT:
				ShiftRight();
				break;
			case UP:
				ShiftUp();
				break;
			case DOWN:
				ShiftDown();
				break;

			case 'q':
				printf("≠");
				break;
			}
		}
		Sleep(10);
	}
}