#include <agb_lib.h>
int score, feel_brave, doornum, gdoor, blah, x, i;
int sram, doorrand;
u16 door;
u16 offset = 0;
char* buf[256];

int main()
{
	Initialize();
	SetMode(MODE_3|BG2_ENABLE);
	feel_brave=1;
	FadeIn(0);
	doorrand=LoadInt(offset);
	srand(doorrand);
	if(doorrand==0)
	{
		doorrand==03;
		SaveInt(offset, 03);
	}
	while(feel_brave==1)
	{
		fillscreen3(0x0000);
		Print(-1, 0, "PREPARING...", RED, BLACK);
		for(i=0;i<doorrand;i++)
		{
			gdoor = rand()%4+1;
		}
		fillscreen3(0x0000);
		WaitForVblank();
		Sleep(3);
		Print(-1, 0, "GHOST GAME", RED, BLACK);
		WaitForVblank();
		Sleep(3);
		Print(-1, 9, "3 DOORS AHEAD", RED, BLACK);
		WaitForVblank();
		Sleep(3);
		Print(-1, 18, "A GHOST BEHIND ONE", RED, BLACK);
		WaitForVblank();
		Sleep(3);
		Print(-1, 27, "WHICH DOOR DO YOU CHOOSE?", RED, BLACK);
		WaitForVblank();
		Sleep(3);
		Print(-1, 36, "UP, LEFT, OR RIGHT?", RED, BLACK);
		WaitForVblank();
		Sleep(3);
		while(NOT((keyDown(KEY_UP))OR(keyDown(KEY_LEFT))OR(keyDown(KEY_RIGHT))))
		{
			gdoor = rand() % 4+1;
		}
		if(keyDown(KEY_UP))
		{
			doornum=1;
		}
		if(keyDown(KEY_LEFT))
		{
			doornum=2;
		}
		if(keyDown(KEY_RIGHT))
		{
			doornum=3;
		}
		if(doornum==gdoor)
		{
			SetMode(MODE_3|BG2_ENABLE|OBJ_ENABLE|OBJ_MAP_1D);
			fillscreen3(0x0000);	
			WaitForVblank();
			Sleep(25);
			Print(0, 0, "GHOST! RUN AWAY!", RED, BLACK);
			WaitForVblank();
			Sleep(3);
			sprintf(buf, "GAME OVER! YOU SCORED: %d.", score);
			Print(0, 9, (char*)buf, RED, BLACK);
			WaitForVblank();
			Sleep(3);
			Print(0, 18, "PRESS ANY BUTTON TO RESET.", RED, BLACK);
			Print(0, 152, "GET REKT M80.", 0x0C63, BLACK);
			Sleep(127.5);
			vsync
			//load numbers zero to nine
			SaveInt(offset, doorrand+(score*5));
			while(1)
			{
				CopyOAM();
				if(KEY_ANY_PRESSED)
				{
					asm("swi 0x26");
				}
			}
		} else {
			fillscreen3(0x0000);
			WaitForVblank();
			Sleep(8);
			Print(-1, 0, "NO GHOST!", RED, BLACK);
			score++;	
			while(NOT(keyDown(KEY_A)));	
		}
	}
	
	return 0;
}
