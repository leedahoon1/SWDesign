#pragma once

typedef struct NPC {
	int hp;
	int curx;
	int cury;
	int move_flag;
	char shape; // ���� ���� �÷���.
}NPC;
char monsterModel[][2][2] = {
	{
		{ 1, 1 },
		{ 1, 1 }
	},
	{
		{ 1, 1 },
		{ 1, 1 }
	},
	{
		{ 1, 1 },
		{ 1, 1 }
	},
	{
		{ 1, 1 },
		{ 1, 1 }
	}
}; // ���� ���� �����.