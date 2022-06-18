#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

void MainMenu(int c, int& ClickFix);
void GameMap(char x[][138], int level);
void StaticObjects(char x[][138], int cO1, int rO1, int cO2, int rO2, int cO3, int rO3, int cO4, int rO4, int cO5, int rO5, int cO6, int rO6, int cO7, int rO7, int cO8, int rO8, int cO9, int rO9);
void DynamicObjects(char x[][138], int& cO1, int& rO1, int& cO2, int& rO2, int& cO3, int& rO3, int& cO4, int& rO4, int& cO5, int& rO5, int& cO6, int& rO6, int&cO7, int& rO7, int& cO8, int& rO8, int& cO9, int& rO9, int CounterUntilStop, int level, char keyB, int AutoWalk);
void StaticFloor(char x[][2000], int& cF, int CounterFloor, int level, int value);
void StaticHero(char x[][2000], int &rH, int &cH, int countRLHL1, int& CountStart, int& LeftLook, int rEv, int Reload, int& ActionReload, int level, int rB, int cB, int GunsTook, int laserstat, int lasersecs, int eyecount);
void StaticHero5(char x[][2000], int &rH, int &cH, int countRLHL1, int& CountStart, int& LeftLook, int Reload, int ActionReload, int level, int rB, int cB);
void LandCheck(char x[][2000], int& rH, int& cH, int& flag1, int GetOut, int level, int SkateIn, int& rSkate, int& cSkate, int RopeIn, int cR, int tap4);
void AutoForward(char x[][2000], int& rH, int& cH, int& countRLHL1, int& flag1, int& CounterUntilStop, int& pass1, int& pass2, int& lose1, int& ScrollCounter, int& GetOut, int& LeftLook, int& rEv, int& level, int& DeathT, int& shoot1, int& SkateIn, int& rSkate, int& cSkate, int& RopeIn, int& rR, int & cR, int& rMS1, int& cMS1, int& rMS2, int& cMS2, int& ClickShot, int& WhichShot, int& rB, int &cB, int &ct, int win, int& rEvR, int& cT6, int& cFC, int& TelephRide, int& ladder, int Reload, int ActionReload, int& AutoWalk, int&realwalk, int&letme, int& value, int& GunsTook, int& AutoWalkCounter, int& ElevON, int& AirTubeStat, int& yeswalk);
void Constructor(char x[][2000], int rH, int cH, int &ConstructorCount, int timer, int CounterUntilStop, int rGuide, int cGuide, int& cC, int level, int GetOut, int timer2, int timer3, int BSc, int flagScore1, int flagScore, int flagScore3, int timer4, int flagTime1, int flagTime2, int flagTime3, int TSc, int mins, int flagScore4, int flagTime4, int timer5, int win, int timerBSC, int rFC, int cFC, int TelephRide, int tryagain, int value, int& lasersecs, int laserstat, int ElevON, int AirTubeStat);
void AutoBackward(char x[][138], int& rH, int& cH, int& lose1, int& pass1, int& pass2, int& cF, int& LeftLook, int CounterUntilStop, int& cO1, int& cC, int& rO1, int& DeathT, int& countRLHL1, int level);
void ToLand(char x[][2000], int rH, int cH, int& flag1, int GetOut, int LeftLook, int level, int rEv, int SkateIn, int& rSkate, int& cSkate, int RopeIn, int cR, int tap4);
void JumpReaction(char x[][2000], int& rH, int& cH, int& flag1, int GetOut, int& LeftLook, int level, int SkateIn, int& rSkate, int& cSkate, int RopeIn, int cR, int tap4);
void LeftHandMoveH1(char x[][2000], int rH, int cH, int countRLHL1, int Reload, int& ReloadAction, int level, int& rB, int cB, int GunsTook);
void RightHandMoveH1(char x[][2000], int rH, int cH, int countRLHL1, int GunsTook);
void RightLegMoveH1(char x[][2000], int& rH, int& cH, int countRLH1);
void LeftLegMoveH1(char x[][2000], int& rH, int& cH, int countRLHL1);
void LevelCounter(char x[][2000], int Stage);
void TimeCounter(char x[][2000], int &mins, int &secs, int CounterUntilStop, int& lose1, int& DeathT, int level, int shoot1, int value);
void HealthBar(char x[][2000], int rH, int cH, int& shoot1, int& lose1, int& DeathT, int level, int& countHearts, int& countHearts2, int mins, int value);
void HighScore(char x[][2000], int rH, int cH, int& Scounter, int CounterUntilStop, int& HScounter, int level, int shoot1, int flagScore1, int flagScore2, int flagScore3, int AutoWalk, int value);
void StaticGunShot(char x[][138], int rE1, int cE1, int& rEG1, int& cEG1, int& countG1, int CounterUntilStop, int GetOut);
void DynamicGunShot(char x[][138], int& rE1, int& cE1, int& rEG1, int& cEG1, int& countG1, int CounterUntilStop, int rH, int cH, int& shoot1, int GetOut, int& DelayShot, int& lose1, int& DeathT);
void StaticEnemy(char x[][2000], int cE1, int rE1, int CounterUntilStop, int countRLEL1, int Reload, int ActionReload, int level, int rB, int cB);
void DynamicEnemy(char x[][138], int& cE1, int& rE1, int CounterUntilStop, int& countRLEL1, int rEG1, int cEG1, int countG1, int GetOut);
void StaticGunShot2(char x[][138], int rE2, int cE2, int& rEG2, int& cEG2, int& countG2, int CounterUntilStop, int GetOut);
void DynamicGunShot2(char x[][138], int& rE2, int& cE2, int& rEG2, int& cEG2, int& countG2, int CounterUntilStop, int rH, int cH, int& shoot1, int GetOut, int& DelayShot, int& DeathT);
void StaticEnemy2(char x[][2000], int cE2, int rE2, int CounterUntilStop, int countRLEL2, int Reload, int ActionReload, int level, int rB, int cB);
void DynamicEnemy2(char x[][138], int& cE2, int& rE2, int CounterUntilStop, int& countRLEL2, int rEG2, int cEG2, int countG2, int GetOut);
void StaticCar2(char x[][138], int c, int r, int cH, int rH, int level, int sarena, int& ratio1, int& flagC);
void DynamicCar2(char x[][138], int& c, int& r, int& cH, int& rH, int& level, int& sarena, int& lose1, int& DeathT, int& Shoot1, int& ratio1, int& flagC);
void StaticPlane2(char x[][138], int r, int c, int rH, int cH, int level, int ratio, int flagP2);
void DynamicPlane2(char x[][138], int& r, int& c, int& rH, int& cH, int level, int& ratio, int& flagP22);
void StaticPlane3(char x[][138], int r, int c, int rH, int cH, int level, int ratio, int flagP2);
void DynamicPlane3(char x[][138], int& r, int& c, int& rH, int& cH, int level, int& ratio, int& flagP22);
void StaticSkate(char x[][138], int r, int c, int rH, int cH, int& SkateIn);
void Output(char x[][2000], int& ScrollCounter, int& cH, int& value);

struct PlayerInfo
{
	int PlayerScore;
	int TemprScore;
	int PlayerDiedLevel;
	char PlayerName[100];
};

void InsideMenu(char keyB, PlayerInfo P[], int& startgame, int H1, int H2, int H3, int HS, int k, int ks, int ClickFix, int& Reply)
{


	if (keyB == 'h' || keyB == 'H')
	{
		if (ClickFix == 1)
		{
			if (k > 1)
			{
				system("cls");
				cout << "\n\t\t\t\t\b\b Top three\n\n";
				if (k > 1)
				{
					cout << "1-" << P[H1].PlayerName << "\t\t\t\t\t\t" << P[H1].PlayerScore;
				}

				if (k > 2)
				{
					cout << "\n\n2-" << P[H2].PlayerName << "\t\t\t\t\t\t" << P[H2].PlayerScore;

				}

				if (k > 3)
				{
					cout << "\n\n3-" << P[H3].PlayerName << "\t\t\t\t\t\t" << P[H3].PlayerScore;

				}
				cout << "\n\n__________________________________________________________________________________________________________________________________________\n\n";
				cout << "\t\t\t\tOthers\n\n";
				if (k > 4)
				{
					for (int i = 1; i < k; i++)
					{
						if (i != H1 && i != H2 && i != H3)
						{
							cout << "- " << P[i].PlayerName << " (" << P[i].PlayerScore << ")\n\n";

						}
					}
				}
				if (k == 1)
				{
					cout << "\n\n\nX - back\t\tH - Analytics\t\tS - Start the game\n\n";
				}

				if (k > 1)
				{
					cout << "\n\n\nX - back\t\tH - Analytics\t\tS - Start the game\n\n";

				}
			}
			else
			{
				system("cls");
				cout << "\nThere is no analytics yet to show.\n\n";
				if (k == 1)
				{
					cout << "\n\n\nX - back\t\tH - Analytics\t\tS - Start the game\n\n";
				}

				if (k > 1)
				{
					cout << "\n\n\nX - back\t\tH - Analytics\t\tS - Start the game\n\n";

				}
			}
		}
	}

	else if (keyB == 'x' || keyB == 'X')
	{
		system("cls");
		MainMenu(k, ClickFix);
	}

	else if (keyB == 's' || keyB == 'S')
	{
		if (ClickFix == 1)
		{
			startgame = 1;
		}
	}


	else
	{
		system("cls");
		MainMenu(k, ClickFix);
	}

}

void MainMenu(int c, int& ClickFix)
{

	cout << "\nH - Who played and scores\n\n";
	cout << "S - Start Game!\n\n";
}

void GameMap(char x[][138], int level)
{

	for (int r = 0; r < 48; r++)
	{
		for (int c = 0; c < 138; c++)
		{
			x[r][c] = ' ';
		}
	}



	if (level == 1)
	{
		x[46][42] = '|';
		x[45][42] = '|';
		for (int c = 43; c < 49; c++)					//ROCKS
		{
			x[45][c] = 45;
		}

		x[46][48] = '|';
		x[45][48] = '|';

		////////////////////////////////////////////////////////////////////////////////////

		x[46][61] = '|';
		x[45][61] = '|';
		x[43][61] = '|';
		x[41][61] = '|';
		x[42][61] = '|';
		x[44][61] = '|';

		for (int c = 62; c < 68; c++)					//ROCKS
		{
			x[45][c] = 45;
		}
		for (int c = 62; c < 68; c++)					//ROCKS
		{
			x[43][c] = 45;
		}
		for (int c = 62; c < 68; c++)					//ROCKS
		{
			x[41][c] = 45;
		}

		x[46][67] = '|';
		x[45][67] = '|';
		x[43][67] = '|';
		x[41][67] = '|';
		x[42][67] = '|';
		x[44][67] = '|';

		////////////////////////////////////////////////////////////////////////////////////

		x[43][75] = '|';
		x[44][75] = '|';
		x[46][75] = '|';
		x[45][75] = '|';
		for (int c = 76; c < 82; c++)					//ROCKS
		{
			x[45][c] = 45;
		}
		for (int c = 76; c < 82; c++)					//ROCKS
		{
			x[43][c] = 45;
		}

		x[46][81] = '|';
		x[45][81] = '|';
		x[43][81] = '|';
		x[44][81] = '|';

		/////////////////////////////////////////////////////////////////////////////////////

		x[46][97] = '|';
		x[45][97] = '|';
		for (int c = 98; c < 104; c++)					//ROCKS
		{
			x[45][c] = 45;
		}

		x[46][103] = '|';
		x[45][103] = '|';

	}

	if (level == 2)
	{
		x[35][22] = '|';
		x[34][22] = '|';
		for (int c = 23; c < 27; c++)					//ROCKS
		{
			x[34][c] = 45;
		}

		x[34][26] = '|';
		x[35][26] = '|';




		x[35][52] = '|';
		x[34][52] = '|';
		for (int c = 53; c < 57; c++)					//ROCKS
		{
			x[34][c] = 45;
		}

		x[34][56] = '|';
		x[35][56] = '|';



		x[35][82] = '|';
		x[34][82] = '|';
		for (int c = 83; c < 87; c++)					//ROCKS
		{
			x[34][c] = 45;
		}

		x[34][86] = '|';
		x[35][86] = '|';



		x[35][122] = '|';
		x[34][122] = '|';
		for (int c = 123; c < 138; c++)					//ROCKS
		{
			x[34][c] = 45;
		}



	}
}

void GameMap6(char x[][2000], int level, int TelephRide, int ladder, int rH, int cH, int value, int GunsTook, int& AttachRope)
{

	for (int r = 0; r < 48; r++)
	{
		for (int c = value; c < 138 + value; c++)
		{
			x[r][c] = ' ';
		}
	}


	if (level == 6 && TelephRide == 0)
	{
		for (int r = 32; r <= 47; r++)
		{
			x[r][19] = 179;
		}
		for (int r = 32; r <= 47; r++)
		{
			x[r][30] = 179;
		}

		for (int r = 33; r <= 46; r += 3)
		{
			for (int c = 20; c < 30; c++)
			{
				x[r][c] = '_';
			}
		}
	}

	if (level == 6)//up
	{
		x[46][51] = '/';
		x[45][52] = '/';
		x[44][53] = '/';
		x[43][54] = '/';
		for (int c = 55; c < 96; c++)
		{
			x[42][c] = '_';
		}
		x[46][99] = '\\';
		x[45][98] = '\\';
		x[44][97] = '\\';
		x[43][96] = '\\';



		x[46][126] = '/';
		x[45][127] = '/';
		x[44][128] = '/';
		x[43][129] = '/';
		for (int c = 130; c < 170; c++)
		{
			x[42][c] = '_';
		}
		x[46][173] = '\\';
		x[45][172] = '\\';
		x[44][171] = '\\';
		x[43][170] = '\\';



		x[42][141] = '/';
		x[41][142] = '/';
		x[40][143] = '/';
		x[39][144] = '/';
		for (int c = 145; c < 185; c++)
		{
			x[38][c] = '_';
		}
		x[46][192] = '\\';
		x[45][191] = '\\';
		x[44][190] = '\\';
		x[43][189] = '\\';
		x[42][188] = '\\';
		x[41][187] = '\\';
		x[40][186] = '\\';
		x[39][185] = '\\';


		x[46][206] = '/';
		x[45][207] = '/';
		x[44][208] = '/';
		x[43][209] = '/';
		for (int c = 210; c < 250; c++)
		{
			x[42][c] = '_';
		}
		x[46][253] = '\\';
		x[45][252] = '\\';
		x[44][251] = '\\';
		x[43][250] = '\\';

		x[46][259] = '|';
		x[45][259] = '|';
		x[44][259] = '|';
		x[43][259] = '|';
		for (int c = 260; c < 340; c++)
		{
			x[42][c] = '_';
		}
		x[46][340] = '|';
		x[45][340] = '|';
		x[44][340] = '|';
		x[43][340] = '|';


		x[42][289] = '|';
		x[41][289] = '|';
		for (int c = 290; c < 370; c++)
		{
			x[40][c] = '_';
		}
		x[41][370] = '|';
		x[42][370] = '|';
		x[43][370] = '|';
		x[44][370] = '|';
		x[45][370] = '|';
		x[46][370] = '|';


		x[46][378] = '/';
		x[45][379] = '/';

		for (int c = 380; c < 450; c++)
		{
			x[44][c] = '_';
		}
		x[46][451] = '\\';
		x[45][450] = '\\';


		x[46][463] = '/';
		x[45][464] = '/';

		for (int c = 465; c < 490; c++)
		{
			x[44][c] = '_';
		}
		x[46][491] = '\\';
		x[45][490] = '\\';


		x[46][508] = '/';
		x[45][509] = '/';

		for (int c = 510; c < 560; c++)
		{
			x[44][c] = '_';
		}
		x[46][561] = '\\';
		x[45][560] = '\\';



		x[46][698] = '/';
		x[45][699] = '/';

		for (int c = 700; c < 750; c++)
		{
			x[44][c] = '_';
		}
		x[46][751] = '\\';
		x[45][750] = '\\';



		x[46][773] = '/';
		x[45][774] = '/';

		for (int c = 775; c < 820; c++)
		{
			x[44][c] = '_';
		}
		x[46][821] = '\\';
		x[45][820] = '\\';


		x[46][848] = '/';
		x[45][849] = '/';

		for (int c = 850; c < 950; c++)
		{
			x[44][c] = '_';
		}
		x[46][951] = '\\';
		x[45][950] = '\\';


		//GUN ATTACH
		if (GunsTook == 0)
		{
			for (int r = 20; r < 37; r++)
			{
				x[r][115] = 179;
			}

		}
		if (GunsTook == 1)
		{
			for (int r = 20; r < 29; r++)
			{
				x[r][115] = 179;
			}

		}

		if (GunsTook == 0)
		{
			int rG = 32;
			int cG = 109;
			x[rG + 4][cG + 7] = '_';	//GUN
			x[rG + 4][cG + 8] = '_';
			x[rG + 4][cG + 9] = '_';
			x[rG + 4][cG + 10] = '_';
			x[rG + 4][cG + 11] = '_';
			x[rG + 4][cG + 12] = '_';
			x[rG + 5][cG + 13] = '|';
			x[rG + 5][cG + 12] = '_';
			x[rG + 5][cG + 11] = '_';
			x[rG + 5][cG + 10] = '_';
			x[rG + 6][cG + 9] = '/';
			x[rG + 6][cG + 8] = '_';
			x[rG + 6][cG + 7] = '|';
			x[rG + 5][cG + 6] = '_';
			cG = 121;
			x[rG + 4][cG - 7] = '_';	//GUN
			x[rG + 4][cG - 8] = '_';
			x[rG + 4][cG - 9] = '_';
			x[rG + 4][cG - 10] = '_';
			x[rG + 4][cG - 11] = '_';
			x[rG + 4][cG - 12] = '_';
			x[rG + 5][cG - 13] = '|';
			x[rG + 5][cG - 12] = '_';
			x[rG + 5][cG - 11] = '_';
			x[rG + 5][cG - 10] = '_';
			x[rG + 6][cG - 9] = '\\';
			x[rG + 6][cG - 8] = '_';
			x[rG + 6][cG - 7] = '|';
			x[rG + 5][cG - 6] = '_';
		}
	}


	if (level == 6 && x[rH][cH + 9] != ' ' && ladder == 0)
	{
		x[rH - 1][cH + 6] = 'T';
		x[rH - 1][cH + 7] = 'A';
		x[rH - 1][cH + 8] = 'P';
		x[rH - 1][cH + 9] = ' ';
		x[rH - 1][cH + 10] = 'E';
		x[rH - 1][cH + 11] = ' ';
		x[rH - 1][cH + 12] = 'T';
		x[rH - 1][cH + 13] = 'O';
		x[rH - 1][cH + 14] = ' ';
		x[rH - 1][cH + 15] = 'C';
		x[rH - 1][cH + 16] = 'L';
		x[rH - 1][cH + 17] = 'I';
		x[rH - 1][cH + 18] = 'M';
		x[rH - 1][cH + 19] = 'B';
	}

	if (level == 6 && ladder == 2 && rH == 30)
	{
		x[rH - 1][cH + 6] = 'T';
		x[rH - 1][cH + 7] = 'A';
		x[rH - 1][cH + 8] = 'P';
		x[rH - 1][cH + 9] = ' ';
		x[rH - 1][cH + 10] = 'E';
		x[rH - 1][cH + 11] = ' ';
		x[rH - 1][cH + 12] = 'T';
		x[rH - 1][cH + 13] = 'O';
		x[rH - 1][cH + 14] = ' ';
		x[rH - 1][cH + 15] = 'R';
		x[rH - 1][cH + 16] = 'I';
		x[rH - 1][cH + 17] = 'D';
		x[rH - 1][cH + 18] = 'E';
	}

	if (level == 6 && ladder == 0 && TelephRide == 2)
	{
		for (int c = 21; c <= 49; c++)
		{
			x[46][c] = '_';
		}
		for (int c = 21; c <= 49; c++)
		{
			x[41][c] = '_';
		}
		for (int c = 22; c <= 48; c += 5)
		{
			for (int r = 42; r < 47; r++)
			{
				x[r][c] = 179;
			}
		}
	}


}

void StaticObjects(char x[][138], int cO1, int rO1, int cO2, int rO2, int cO3, int rO3, int cO4, int rO4, int cO5, int rO5, int cO6, int rO6, int cO7, int rO7, int cO8, int rO8, int cO9, int rO9)
{
	{

		x[rO1 + 23][cO1] = 179;
		x[rO1 + 22][cO1] = 179;
		x[rO1 + 21][cO1] = 179;
		x[rO1 + 20][cO1] = 179;
		x[rO1 + 19][cO1] = 179;
		x[rO1 + 18][cO1] = 179;
		x[rO1 + 17][cO1] = 179;
		x[rO1 + 16][cO1] = 179;
		x[rO1 + 15][cO1] = 179;
		x[rO1 + 14][cO1] = 179;
		x[rO1 + 13][cO1] = 179;
		x[rO1 + 12][cO1] = 179;
		x[rO1 + 11][cO1] = 179;
		x[rO1 + 10][cO1] = 179;
		x[rO1 + 9][cO1] = 179;
		x[rO1 + 8][cO1] = 179;
		x[rO1 + 7][cO1] = 179;
		x[rO1 + 6][cO1] = 179;
		x[rO1 + 5][cO1] = 179;

		x[rO1 + 5][cO1 - 1] = 22;
	}

	{
		x[rO2 + 23][cO2] = 186;
		x[rO2 + 22][cO2] = 186;
		x[rO2 + 21][cO2] = 186;
		x[rO2 + 20][cO2] = 186;
		x[rO2 + 19][cO2] = 186;
		x[rO2 + 18][cO2] = 186;
		x[rO2 + 17][cO2] = 186;
		x[rO2 + 16][cO2] = 186;
		x[rO2 + 15][cO2] = 186;
		x[rO2 + 14][cO2] = 186;
		x[rO2 + 13][cO2] = 186;

		x[rO2 + 13][cO2 - 8] = 176;
		x[rO2 + 13][cO2 - 7] = 176;
		x[rO2 + 13][cO2 - 6] = 176;
		x[rO2 + 13][cO2 - 5] = 176;
		x[rO2 + 13][cO2 - 4] = 176;
		x[rO2 + 13][cO2 - 3] = 176;
		x[rO2 + 13][cO2 - 2] = 176;
		x[rO2 + 13][cO2 - 1] = 176;
		x[rO2 + 13][cO2] = 176;
		x[rO2 + 13][cO2 + 1] = 176;
		x[rO2 + 13][cO2 + 2] = 176;
		x[rO2 + 13][cO2 + 3] = 176;
		x[rO2 + 13][cO2 + 4] = 176;
		x[rO2 + 13][cO2 + 5] = 176;
		x[rO2 + 13][cO2 + 6] = 176;
		x[rO2 + 13][cO2 + 7] = 176;
		x[rO2 + 13][cO2 + 8] = 176;

		x[rO2 + 12][cO2 - 7] = 176;
		x[rO2 + 12][cO2 - 6] = 176;
		x[rO2 + 12][cO2 - 5] = 176;
		x[rO2 + 12][cO2 - 4] = 176;
		x[rO2 + 12][cO2 - 3] = 176;
		x[rO2 + 12][cO2 - 2] = 176;
		x[rO2 + 12][cO2 - 1] = 176;
		x[rO2 + 12][cO2] = 176;
		x[rO2 + 12][cO2 + 1] = 176;
		x[rO2 + 12][cO2 + 2] = 176;
		x[rO2 + 12][cO2 + 3] = 176;
		x[rO2 + 12][cO2 + 4] = 176;
		x[rO2 + 12][cO2 + 5] = 176;
		x[rO2 + 12][cO2 + 6] = 176;
		x[rO2 + 12][cO2 + 7] = 176;

		x[rO2 + 11][cO2 - 6] = 176;
		x[rO2 + 11][cO2 - 5] = 176;
		x[rO2 + 11][cO2 - 4] = 176;
		x[rO2 + 11][cO2 - 3] = 176;
		x[rO2 + 11][cO2 - 2] = 176;
		x[rO2 + 11][cO2 - 1] = 176;
		x[rO2 + 11][cO2] = 176;
		x[rO2 + 11][cO2 + 1] = 176;
		x[rO2 + 11][cO2 + 2] = 176;
		x[rO2 + 11][cO2 + 3] = 176;
		x[rO2 + 11][cO2 + 4] = 176;
		x[rO2 + 11][cO2 + 5] = 176;
		x[rO2 + 11][cO2 + 6] = 176;

		x[rO2 + 10][cO2 - 5] = 176;
		x[rO2 + 10][cO2 - 4] = 176;
		x[rO2 + 10][cO2 - 3] = 176;
		x[rO2 + 10][cO2 - 2] = 176;
		x[rO2 + 10][cO2 - 1] = 176;
		x[rO2 + 10][cO2] = 176;
		x[rO2 + 10][cO2 + 1] = 176;
		x[rO2 + 10][cO2 + 2] = 176;
		x[rO2 + 10][cO2 + 3] = 176;
		x[rO2 + 10][cO2 + 4] = 176;
		x[rO2 + 10][cO2 + 5] = 176;

		x[rO2 + 9][cO2 - 4] = 176;
		x[rO2 + 9][cO2 - 3] = 176;
		x[rO2 + 9][cO2 - 2] = 176;
		x[rO2 + 9][cO2 - 1] = 176;
		x[rO2 + 9][cO2] = 176;
		x[rO2 + 9][cO2 + 1] = 176;
		x[rO2 + 9][cO2 + 2] = 176;
		x[rO2 + 9][cO2 + 3] = 176;
		x[rO2 + 9][cO2 + 4] = 176;

		x[rO2 + 8][cO2 - 3] = 176;
		x[rO2 + 8][cO2 - 2] = 176;
		x[rO2 + 8][cO2 - 1] = 176;
		x[rO2 + 8][cO2] = 176;
		x[rO2 + 8][cO2 + 1] = 176;
		x[rO2 + 8][cO2 + 2] = 176;
		x[rO2 + 8][cO2 + 3] = 176;

		x[rO2 + 7][cO2 - 2] = 176;
		x[rO2 + 7][cO2 - 1] = 176;
		x[rO2 + 7][cO2] = 176;
		x[rO2 + 7][cO2 + 1] = 176;
		x[rO2 + 7][cO2 + 2] = 176;

		x[rO2 + 6][cO2 - 1] = 176;
		x[rO2 + 6][cO2] = 176;
		x[rO2 + 6][cO2 + 1] = 176;

		x[rO2 + 5][cO2] = 176;


	}


	{
		x[rO3 + 23][cO3] = 179;
		x[rO3 + 22][cO3] = 179;
		x[rO3 + 21][cO3] = 179;
		x[rO3 + 20][cO3] = 179;
		x[rO3 + 19][cO3] = 179;
		x[rO3 + 18][cO3] = 179;
		x[rO3 + 17][cO3] = 179;
		x[rO3 + 16][cO3] = 179;
		x[rO3 + 15][cO3] = 179;
		x[rO3 + 14][cO3] = 179;
		x[rO3 + 13][cO3] = 179;
		x[rO3 + 12][cO3] = 179;
		x[rO3 + 11][cO3] = 179;
		x[rO3 + 10][cO3] = 179;
		x[rO3 + 9][cO3] = 179;
		x[rO3 + 8][cO3] = 179;
		x[rO3 + 7][cO3] = 179;
		x[rO3 + 6][cO3] = 179;
		x[rO3 + 5][cO3] = 179;

		x[rO3 + 5][cO3 - 1] = 22;
	}

	{
		x[rO4 + 23][cO4] = 179;
		x[rO4 + 22][cO4] = 179;
		x[rO4 + 21][cO4] = 179;
		x[rO4 + 20][cO4] = 179;
		x[rO4 + 19][cO4] = 179;
		x[rO4 + 18][cO4] = 179;
		x[rO4 + 17][cO4] = 179;
		x[rO4 + 16][cO4] = 179;
		x[rO4 + 15][cO4] = 179;
		x[rO4 + 14][cO4] = 179;
		x[rO4 + 13][cO4] = 179;
		x[rO4 + 12][cO4] = 179;
		x[rO4 + 11][cO4] = 179;
		x[rO4 + 10][cO4] = 179;
		x[rO4 + 9][cO4] = 179;
		x[rO4 + 8][cO4] = 179;
		x[rO4 + 7][cO4] = 179;
		x[rO4 + 6][cO4] = 179;
		x[rO4 + 5][cO4] = 179;


		x[rO4 + 5][cO4 - 1] = 22;
	}


	{
		x[rO5 + 23][cO5] = 186;
		x[rO5 + 22][cO5] = 186;
		x[rO5 + 21][cO5] = 186;
		x[rO5 + 20][cO5] = 186;
		x[rO5 + 19][cO5] = 186;
		x[rO5 + 18][cO5] = 186;
		x[rO5 + 17][cO5] = 186;
		x[rO5 + 16][cO5] = 186;
		x[rO5 + 15][cO5] = 186;
		x[rO5 + 14][cO5] = 186;
		x[rO5 + 13][cO5] = 186;

		x[rO5 + 13][cO5 - 8] = 176;
		x[rO5 + 13][cO5 - 7] = 176;
		x[rO5 + 13][cO5 - 6] = 176;
		x[rO5 + 13][cO5 - 5] = 176;
		x[rO5 + 13][cO5 - 4] = 176;
		x[rO5 + 13][cO5 - 3] = 176;
		x[rO5 + 13][cO5 - 2] = 176;
		x[rO5 + 13][cO5 - 1] = 176;
		x[rO5 + 13][cO5] = 176;
		x[rO5 + 13][cO5 + 1] = 176;
		x[rO5 + 13][cO5 + 2] = 176;
		x[rO5 + 13][cO5 + 3] = 176;
		x[rO5 + 13][cO5 + 4] = 176;
		x[rO5 + 13][cO5 + 5] = 176;
		x[rO5 + 13][cO5 + 6] = 176;
		x[rO5 + 13][cO5 + 7] = 176;
		x[rO5 + 13][cO5 + 8] = 176;

		x[rO5 + 12][cO5 - 7] = 176;
		x[rO5 + 12][cO5 - 6] = 176;
		x[rO5 + 12][cO5 - 5] = 176;
		x[rO5 + 12][cO5 - 4] = 176;
		x[rO5 + 12][cO5 - 3] = 176;
		x[rO5 + 12][cO5 - 2] = 176;
		x[rO5 + 12][cO5 - 1] = 176;
		x[rO5 + 12][cO5] = 176;
		x[rO5 + 12][cO5 + 1] = 176;
		x[rO5 + 12][cO5 + 2] = 176;
		x[rO5 + 12][cO5 + 3] = 176;
		x[rO5 + 12][cO5 + 4] = 176;
		x[rO5 + 12][cO5 + 5] = 176;
		x[rO5 + 12][cO5 + 6] = 176;
		x[rO5 + 12][cO5 + 7] = 176;

		x[rO5 + 11][cO5 - 6] = 176;
		x[rO5 + 11][cO5 - 5] = 176;
		x[rO5 + 11][cO5 - 4] = 176;
		x[rO5 + 11][cO5 - 3] = 176;
		x[rO5 + 11][cO5 - 2] = 176;
		x[rO5 + 11][cO5 - 1] = 176;
		x[rO5 + 11][cO5] = 176;
		x[rO5 + 11][cO5 + 1] = 176;
		x[rO5 + 11][cO5 + 2] = 176;
		x[rO5 + 11][cO5 + 3] = 176;
		x[rO5 + 11][cO5 + 4] = 176;
		x[rO5 + 11][cO5 + 5] = 176;
		x[rO5 + 11][cO5 + 6] = 176;

		x[rO5 + 10][cO5 - 5] = 176;
		x[rO5 + 10][cO5 - 4] = 176;
		x[rO5 + 10][cO5 - 3] = 176;
		x[rO5 + 10][cO5 - 2] = 176;
		x[rO5 + 10][cO5 - 1] = 176;
		x[rO5 + 10][cO5] = 176;
		x[rO5 + 10][cO5 + 1] = 176;
		x[rO5 + 10][cO5 + 2] = 176;
		x[rO5 + 10][cO5 + 3] = 176;
		x[rO5 + 10][cO5 + 4] = 176;
		x[rO5 + 10][cO5 + 5] = 176;

		x[rO5 + 9][cO5 - 4] = 176;
		x[rO5 + 9][cO5 - 3] = 176;
		x[rO5 + 9][cO5 - 2] = 176;
		x[rO5 + 9][cO5 - 1] = 176;
		x[rO5 + 9][cO5] = 176;
		x[rO5 + 9][cO5 + 1] = 176;
		x[rO5 + 9][cO5 + 2] = 176;
		x[rO5 + 9][cO5 + 3] = 176;
		x[rO5 + 9][cO5 + 4] = 176;

		x[rO5 + 8][cO5 - 3] = 176;
		x[rO5 + 8][cO5 - 2] = 176;
		x[rO5 + 8][cO5 - 1] = 176;
		x[rO5 + 8][cO5] = 176;
		x[rO5 + 8][cO5 + 1] = 176;
		x[rO5 + 8][cO5 + 2] = 176;
		x[rO5 + 8][cO5 + 3] = 176;

		x[rO5 + 7][cO5 - 2] = 176;
		x[rO5 + 7][cO5 - 1] = 176;
		x[rO5 + 7][cO5] = 176;
		x[rO5 + 7][cO5 + 1] = 176;
		x[rO5 + 7][cO5 + 2] = 176;

		x[rO5 + 6][cO5 - 1] = 176;
		x[rO5 + 6][cO5] = 176;
		x[rO5 + 6][cO5 + 1] = 176;

		x[rO5 + 5][cO5] = 176;


	}

	{
		x[rO6 + 23][cO6] = 179;
		x[rO6 + 22][cO6] = 179;
		x[rO6 + 21][cO6] = 179;
		x[rO6 + 20][cO6] = 179;
		x[rO6 + 19][cO6] = 179;
		x[rO6 + 18][cO6] = 179;
		x[rO6 + 17][cO6] = 179;
		x[rO6 + 16][cO6] = 179;
		x[rO6 + 15][cO6] = 179;
		x[rO6 + 14][cO6] = 179;
		x[rO6 + 13][cO6] = 179;
		x[rO6 + 12][cO6] = 179;
		x[rO6 + 11][cO6] = 179;
		x[rO6 + 10][cO6] = 179;
		x[rO6 + 9][cO6] = 179;
		x[rO6 + 8][cO6] = 179;
		x[rO6 + 7][cO6] = 179;
		x[rO6 + 6][cO6] = 179;
		x[rO6 + 5][cO6] = 179;

		x[rO6 + 5][cO6 - 1] = 22;
	}

	{
		x[rO7 + 23][cO7] = 186;
		x[rO7 + 22][cO7] = 186;
		x[rO7 + 21][cO7] = 186;
		x[rO7 + 20][cO7] = 186;
		x[rO7 + 19][cO7] = 186;
		x[rO7 + 18][cO7] = 186;
		x[rO7 + 17][cO7] = 186;
		x[rO7 + 16][cO7] = 186;
		x[rO7 + 15][cO7] = 186;
		x[rO7 + 14][cO7] = 186;
		x[rO7 + 13][cO7] = 186;

		x[rO7 + 13][cO7 - 8] = 176;
		x[rO7 + 13][cO7 - 7] = 176;
		x[rO7 + 13][cO7 - 6] = 176;
		x[rO7 + 13][cO7 - 5] = 176;
		x[rO7 + 13][cO7 - 4] = 176;
		x[rO7 + 13][cO7 - 3] = 176;
		x[rO7 + 13][cO7 - 2] = 176;
		x[rO7 + 13][cO7 - 1] = 176;
		x[rO7 + 13][cO7] = 176;
		x[rO7 + 13][cO7 + 1] = 176;
		x[rO7 + 13][cO7 + 2] = 176;
		x[rO7 + 13][cO7 + 3] = 176;
		x[rO7 + 13][cO7 + 4] = 176;
		x[rO7 + 13][cO7 + 5] = 176;
		x[rO7 + 13][cO7 + 6] = 176;
		x[rO7 + 13][cO7 + 7] = 176;
		x[rO7 + 13][cO7 + 8] = 176;

		x[rO7 + 12][cO7 - 7] = 176;
		x[rO7 + 12][cO7 - 6] = 176;
		x[rO7 + 12][cO7 - 5] = 176;
		x[rO7 + 12][cO7 - 4] = 176;
		x[rO7 + 12][cO7 - 3] = 176;
		x[rO7 + 12][cO7 - 2] = 176;
		x[rO7 + 12][cO7 - 1] = 176;
		x[rO7 + 12][cO7] = 176;
		x[rO7 + 12][cO7 + 1] = 176;
		x[rO7 + 12][cO7 + 2] = 176;
		x[rO7 + 12][cO7 + 3] = 176;
		x[rO7 + 12][cO7 + 4] = 176;
		x[rO7 + 12][cO7 + 5] = 176;
		x[rO7 + 12][cO7 + 6] = 176;
		x[rO7 + 12][cO7 + 7] = 176;

		x[rO7 + 11][cO7 - 6] = 176;
		x[rO7 + 11][cO7 - 5] = 176;
		x[rO7 + 11][cO7 - 4] = 176;
		x[rO7 + 11][cO7 - 3] = 176;
		x[rO7 + 11][cO7 - 2] = 176;
		x[rO7 + 11][cO7 - 1] = 176;
		x[rO7 + 11][cO7] = 176;
		x[rO7 + 11][cO7 + 1] = 176;
		x[rO7 + 11][cO7 + 2] = 176;
		x[rO7 + 11][cO7 + 3] = 176;
		x[rO7 + 11][cO7 + 4] = 176;
		x[rO7 + 11][cO7 + 5] = 176;
		x[rO7 + 11][cO7 + 6] = 176;

		x[rO7 + 10][cO7 - 5] = 176;
		x[rO7 + 10][cO7 - 4] = 176;
		x[rO7 + 10][cO7 - 3] = 176;
		x[rO7 + 10][cO7 - 2] = 176;
		x[rO7 + 10][cO7 - 1] = 176;
		x[rO7 + 10][cO7] = 176;
		x[rO7 + 10][cO7 + 1] = 176;
		x[rO7 + 10][cO7 + 2] = 176;
		x[rO7 + 10][cO7 + 3] = 176;
		x[rO7 + 10][cO7 + 4] = 176;
		x[rO7 + 10][cO7 + 5] = 176;

		x[rO7 + 9][cO7 - 4] = 176;
		x[rO7 + 9][cO7 - 3] = 176;
		x[rO7 + 9][cO7 - 2] = 176;
		x[rO7 + 9][cO7 - 1] = 176;
		x[rO7 + 9][cO7] = 176;
		x[rO7 + 9][cO7 + 1] = 176;
		x[rO7 + 9][cO7 + 2] = 176;
		x[rO7 + 9][cO7 + 3] = 176;
		x[rO7 + 9][cO7 + 4] = 176;

		x[rO7 + 8][cO7 - 3] = 176;
		x[rO7 + 8][cO7 - 2] = 176;
		x[rO7 + 8][cO7 - 1] = 176;
		x[rO7 + 8][cO7] = 176;
		x[rO7 + 8][cO7 + 1] = 176;
		x[rO7 + 8][cO7 + 2] = 176;
		x[rO7 + 8][cO7 + 3] = 176;

		x[rO7 + 7][cO7 - 2] = 176;
		x[rO7 + 7][cO7 - 1] = 176;
		x[rO7 + 7][cO7] = 176;
		x[rO7 + 7][cO7 + 1] = 176;
		x[rO7 + 7][cO7 + 2] = 176;

		x[rO7 + 6][cO7 - 1] = 176;
		x[rO7 + 6][cO7] = 176;
		x[rO7 + 6][cO7 + 1] = 176;

		x[rO7 + 5][cO7] = 176;


	}

	/*{
	x[rO8 + 23][cO8] = 179;
	x[rO8 + 22][cO8] = 179;
	x[rO8 + 21][cO8] = 179;
	x[rO8 + 20][cO8] = 179;
	x[rO8 + 19][cO8] = 179;
	x[rO8 + 18][cO8] = 179;
	x[rO8 + 17][cO8] = 179;
	x[rO8 + 16][cO8] = 179;
	x[rO8 + 15][cO8] = 179;
	x[rO8 + 14][cO8] = 179;
	x[rO8 + 13][cO8] = 179;
	x[rO8 + 12][cO8] = 179;
	x[rO8 + 11][cO8] = 179;
	x[rO8 + 10][cO8] = 179;
	x[rO8 + 9][cO8] = 179;
	x[rO8 + 8][cO8] = 179;
	x[rO8 + 7][cO8] = 179;
	x[rO8 + 6][cO8] = 179;
	x[rO8 + 5][cO8] = 179;

	x[rO8 + 5][cO8 - 1] = 22;
	}*/


	{
		x[rO9 + 23][cO9] = 186;
		x[rO9 + 22][cO9] = 186;
		x[rO9 + 21][cO9] = 186;
		x[rO9 + 20][cO9] = 186;
		x[rO9 + 19][cO9] = 186;
		x[rO9 + 18][cO9] = 186;
		x[rO9 + 17][cO9] = 186;
		x[rO9 + 16][cO9] = 186;
		x[rO9 + 15][cO9] = 186;
		x[rO9 + 14][cO9] = 186;
		x[rO9 + 13][cO9] = 186;

		x[rO9 + 13][cO9 - 8] = 176;
		x[rO9 + 13][cO9 - 7] = 176;
		x[rO9 + 13][cO9 - 6] = 176;
		x[rO9 + 13][cO9 - 5] = 176;
		x[rO9 + 13][cO9 - 4] = 176;
		x[rO9 + 13][cO9 - 3] = 176;
		x[rO9 + 13][cO9 - 2] = 176;
		x[rO9 + 13][cO9 - 1] = 176;
		x[rO9 + 13][cO9] = 176;
		x[rO9 + 13][cO9 + 1] = 176;
		x[rO9 + 13][cO9 + 2] = 176;
		x[rO9 + 13][cO9 + 3] = 176;
		x[rO9 + 13][cO9 + 4] = 176;
		x[rO9 + 13][cO9 + 5] = 176;
		x[rO9 + 13][cO9 + 6] = 176;
		x[rO9 + 13][cO9 + 7] = 176;
		x[rO9 + 13][cO9 + 8] = 176;

		x[rO9 + 12][cO9 - 7] = 176;
		x[rO9 + 12][cO9 - 6] = 176;
		x[rO9 + 12][cO9 - 5] = 176;
		x[rO9 + 12][cO9 - 4] = 176;
		x[rO9 + 12][cO9 - 3] = 176;
		x[rO9 + 12][cO9 - 2] = 176;
		x[rO9 + 12][cO9 - 1] = 176;
		x[rO9 + 12][cO9] = 176;
		x[rO9 + 12][cO9 + 1] = 176;
		x[rO9 + 12][cO9 + 2] = 176;
		x[rO9 + 12][cO9 + 3] = 176;
		x[rO9 + 12][cO9 + 4] = 176;
		x[rO9 + 12][cO9 + 5] = 176;
		x[rO9 + 12][cO9 + 6] = 176;
		x[rO9 + 12][cO9 + 7] = 176;

		x[rO9 + 11][cO9 - 6] = 176;
		x[rO9 + 11][cO9 - 5] = 176;
		x[rO9 + 11][cO9 - 4] = 176;
		x[rO9 + 11][cO9 - 3] = 176;
		x[rO9 + 11][cO9 - 2] = 176;
		x[rO9 + 11][cO9 - 1] = 176;
		x[rO9 + 11][cO9] = 176;
		x[rO9 + 11][cO9 + 1] = 176;
		x[rO9 + 11][cO9 + 2] = 176;
		x[rO9 + 11][cO9 + 3] = 176;
		x[rO9 + 11][cO9 + 4] = 176;
		x[rO9 + 11][cO9 + 5] = 176;
		x[rO9 + 11][cO9 + 6] = 176;

		x[rO9 + 10][cO9 - 5] = 176;
		x[rO9 + 10][cO9 - 4] = 176;
		x[rO9 + 10][cO9 - 3] = 176;
		x[rO9 + 10][cO9 - 2] = 176;
		x[rO9 + 10][cO9 - 1] = 176;
		x[rO9 + 10][cO9] = 176;
		x[rO9 + 10][cO9 + 1] = 176;
		x[rO9 + 10][cO9 + 2] = 176;
		x[rO9 + 10][cO9 + 3] = 176;
		x[rO9 + 10][cO9 + 4] = 176;
		x[rO9 + 10][cO9 + 5] = 176;

		x[rO9 + 9][cO9 - 4] = 176;
		x[rO9 + 9][cO9 - 3] = 176;
		x[rO9 + 9][cO9 - 2] = 176;
		x[rO9 + 9][cO9 - 1] = 176;
		x[rO9 + 9][cO9] = 176;
		x[rO9 + 9][cO9 + 1] = 176;
		x[rO9 + 9][cO9 + 2] = 176;
		x[rO9 + 9][cO9 + 3] = 176;
		x[rO9 + 9][cO9 + 4] = 176;

		x[rO9 + 8][cO9 - 3] = 176;
		x[rO9 + 8][cO9 - 2] = 176;
		x[rO9 + 8][cO9 - 1] = 176;
		x[rO9 + 8][cO9] = 176;
		x[rO9 + 8][cO9 + 1] = 176;
		x[rO9 + 8][cO9 + 2] = 176;
		x[rO9 + 8][cO9 + 3] = 176;

		x[rO9 + 7][cO9 - 2] = 176;
		x[rO9 + 7][cO9 - 1] = 176;
		x[rO9 + 7][cO9] = 176;
		x[rO9 + 7][cO9 + 1] = 176;
		x[rO9 + 7][cO9 + 2] = 176;

		x[rO9 + 6][cO9 - 1] = 176;
		x[rO9 + 6][cO9] = 176;
		x[rO9 + 6][cO9 + 1] = 176;

		x[rO9 + 5][cO9] = 176;

		//	SetConsoleTextAttribute(hConsole, 15);
	}
}

void DynamicObjects(char x[][138], int& cO1, int& rO1, int& cO2, int& rO2, int& cO3, int& rO3, int& cO4, int& rO4, int& cO5, int& rO5, int& cO6, int& rO6, int&cO7, int& rO7, int& cO8, int& rO8, int& cO9, int& rO9, int CounterUntilStop, int level, char keyB, int AutoWalk)
{
	if (CounterUntilStop >= 16 && level == 1 && (keyB == 'd' || keyB == 'D'))
	{
		cO1 -= 3;
		cO2 -= 3;
		cO3 -= 3;
		cO4 -= 3;
		cO5 -= 3;
		cO6 -= 3;
		cO7 -= 3;
		cO8 -= 3;
		cO9 -= 3;
		if (cO1 <= 0)
		{
			rO1 = 3;
			cO1 = 137;
		}

		if (cO2 <= 0)
		{
			rO2 = 3;
			cO2 = 137;
		}
		if (cO3 <= 0)
		{
			rO3 = 3;
			cO3 = 137;
		}
		if (cO4 <= 0)
		{
			rO4 = 3;
			cO4 = 137;
		}
		if (cO5 <= 0)
		{
			rO5 = 3;
			cO5 = 137;
		}
		if (cO6 <= 0)
		{
			rO6 = 3;
			cO6 = 137;
		}
		if (cO7 <= 0)
		{
			rO7 = 3;
			cO7 = 137;
		}

		if (cO9 <= 0)
		{
			rO9 = 3;
			cO9 = 137;
		}
	}
	else
	{
		if (cO1 <= 0)
		{
			rO1 = 3;
			cO1 = 137;
		}

		if (cO2 <= 0)
		{
			rO2 = 3;
			cO2 = 137;
		}
		if (cO3 <= 0)
		{
			rO3 = 3;
			cO3 = 137;
		}
		if (cO4 <= 0)
		{
			rO4 = 3;
			cO4 = 137;
		}
		if (cO5 <= 0)
		{
			rO5 = 3;
			cO5 = 137;
		}
		if (cO6 <= 0)
		{
			rO6 = 3;
			cO6 = 137;
		}
		if (cO7 <= 0)
		{
			rO7 = 3;
			cO7 = 137;
		}

		if (cO9 <= 0)
		{
			rO9 = 3;
			cO9 = 137;
		}
	}



}

void DynamicObjects_2(char x[][138], int& cO1, int& rO1, int& cO2, int& rO2, int& cO3, int& rO3, int& cO4, int& rO4, int& cO5, int& rO5, int& cO6, int& rO6, int&cO7, int& rO7, int& cO8, int& rO8, int& cO9, int& rO9, int CounterUntilStop, int level, int AutoWalk)
{
	if (AutoWalk == 1)
	{
		cO1 -= 3;
		cO2 -= 3;
		cO3 -= 3;
		cO4 -= 3;
		cO5 -= 3;
		cO6 -= 3;
		cO7 -= 3;
		cO8 -= 3;
		cO9 -= 3;
		if (cO1 <= 0)
		{
			rO1 = 3;
			cO1 = 137;
		}

		if (cO2 <= 0)
		{
			rO2 = 3;
			cO2 = 137;
		}
		if (cO3 <= 0)
		{
			rO3 = 3;
			cO3 = 137;
		}
		if (cO4 <= 0)
		{
			rO4 = 3;
			cO4 = 137;
		}
		if (cO5 <= 0)
		{
			rO5 = 3;
			cO5 = 137;
		}
		if (cO6 <= 0)
		{
			rO6 = 3;
			cO6 = 137;
		}
		if (cO7 <= 0)
		{
			rO7 = 3;
			cO7 = 137;
		}

		if (cO9 <= 0)
		{
			rO9 = 3;
			cO9 = 137;
		}
	}
	else
	{
		if (cO1 <= 0)
		{
			rO1 = 3;
			cO1 = 137;
		}

		if (cO2 <= 0)
		{
			rO2 = 3;
			cO2 = 137;
		}
		if (cO3 <= 0)
		{
			rO3 = 3;
			cO3 = 137;
		}
		if (cO4 <= 0)
		{
			rO4 = 3;
			cO4 = 137;
		}
		if (cO5 <= 0)
		{
			rO5 = 3;
			cO5 = 137;
		}
		if (cO6 <= 0)
		{
			rO6 = 3;
			cO6 = 137;
		}
		if (cO7 <= 0)
		{
			rO7 = 3;
			cO7 = 137;
		}

		if (cO9 <= 0)
		{
			rO9 = 3;
			cO9 = 137;
		}
	}



}

void StaticObjects2(char x[][2000], int cO1, int rO1, int cO2, int rO2, int cO3, int rO3, int cO4, int rO4, int cO5, int rO5, int cO6, int rO6, int cO7, int rO7, int cO8, int rO8, int cO9, int rO9)
{
	{


		x[rO1 + 21][cO1] = 179;
		x[rO1 + 20][cO1] = 179;
		x[rO1 + 19][cO1] = 179;
		x[rO1 + 18][cO1] = 179;
		x[rO1 + 17][cO1] = 179;
		x[rO1 + 16][cO1] = 179;
		x[rO1 + 15][cO1] = 179;
		x[rO1 + 14][cO1] = 179;
		x[rO1 + 13][cO1] = 179;
		x[rO1 + 12][cO1] = 179;
		x[rO1 + 11][cO1] = 179;
		x[rO1 + 10][cO1] = 179;
		x[rO1 + 9][cO1] = 179;
		x[rO1 + 8][cO1] = 179;
		x[rO1 + 7][cO1] = 179;
		x[rO1 + 6][cO1] = 179;
		x[rO1 + 5][cO1] = 179;

		x[rO1 + 5][cO1 - 1] = 22;
	}

	{

		x[rO2 + 21][cO2] = 186;
		x[rO2 + 20][cO2] = 186;
		x[rO2 + 19][cO2] = 186;
		x[rO2 + 18][cO2] = 186;
		x[rO2 + 17][cO2] = 186;
		x[rO2 + 16][cO2] = 186;
		x[rO2 + 15][cO2] = 186;
		x[rO2 + 14][cO2] = 186;
		x[rO2 + 13][cO2] = 186;

		x[rO2 + 13][cO2 - 8] = 176;
		x[rO2 + 13][cO2 - 7] = 176;
		x[rO2 + 13][cO2 - 6] = 176;
		x[rO2 + 13][cO2 - 5] = 176;
		x[rO2 + 13][cO2 - 4] = 176;
		x[rO2 + 13][cO2 - 3] = 176;
		x[rO2 + 13][cO2 - 2] = 176;
		x[rO2 + 13][cO2 - 1] = 176;
		x[rO2 + 13][cO2] = 176;
		x[rO2 + 13][cO2 + 1] = 176;
		x[rO2 + 13][cO2 + 2] = 176;
		x[rO2 + 13][cO2 + 3] = 176;
		x[rO2 + 13][cO2 + 4] = 176;
		x[rO2 + 13][cO2 + 5] = 176;
		x[rO2 + 13][cO2 + 6] = 176;
		x[rO2 + 13][cO2 + 7] = 176;
		x[rO2 + 13][cO2 + 8] = 176;

		x[rO2 + 12][cO2 - 7] = 176;
		x[rO2 + 12][cO2 - 6] = 176;
		x[rO2 + 12][cO2 - 5] = 176;
		x[rO2 + 12][cO2 - 4] = 176;
		x[rO2 + 12][cO2 - 3] = 176;
		x[rO2 + 12][cO2 - 2] = 176;
		x[rO2 + 12][cO2 - 1] = 176;
		x[rO2 + 12][cO2] = 176;
		x[rO2 + 12][cO2 + 1] = 176;
		x[rO2 + 12][cO2 + 2] = 176;
		x[rO2 + 12][cO2 + 3] = 176;
		x[rO2 + 12][cO2 + 4] = 176;
		x[rO2 + 12][cO2 + 5] = 176;
		x[rO2 + 12][cO2 + 6] = 176;
		x[rO2 + 12][cO2 + 7] = 176;

		x[rO2 + 11][cO2 - 6] = 176;
		x[rO2 + 11][cO2 - 5] = 176;
		x[rO2 + 11][cO2 - 4] = 176;
		x[rO2 + 11][cO2 - 3] = 176;
		x[rO2 + 11][cO2 - 2] = 176;
		x[rO2 + 11][cO2 - 1] = 176;
		x[rO2 + 11][cO2] = 176;
		x[rO2 + 11][cO2 + 1] = 176;
		x[rO2 + 11][cO2 + 2] = 176;
		x[rO2 + 11][cO2 + 3] = 176;
		x[rO2 + 11][cO2 + 4] = 176;
		x[rO2 + 11][cO2 + 5] = 176;
		x[rO2 + 11][cO2 + 6] = 176;

		x[rO2 + 10][cO2 - 5] = 176;
		x[rO2 + 10][cO2 - 4] = 176;
		x[rO2 + 10][cO2 - 3] = 176;
		x[rO2 + 10][cO2 - 2] = 176;
		x[rO2 + 10][cO2 - 1] = 176;
		x[rO2 + 10][cO2] = 176;
		x[rO2 + 10][cO2 + 1] = 176;
		x[rO2 + 10][cO2 + 2] = 176;
		x[rO2 + 10][cO2 + 3] = 176;
		x[rO2 + 10][cO2 + 4] = 176;
		x[rO2 + 10][cO2 + 5] = 176;

		x[rO2 + 9][cO2 - 4] = 176;
		x[rO2 + 9][cO2 - 3] = 176;
		x[rO2 + 9][cO2 - 2] = 176;
		x[rO2 + 9][cO2 - 1] = 176;
		x[rO2 + 9][cO2] = 176;
		x[rO2 + 9][cO2 + 1] = 176;
		x[rO2 + 9][cO2 + 2] = 176;
		x[rO2 + 9][cO2 + 3] = 176;
		x[rO2 + 9][cO2 + 4] = 176;

		x[rO2 + 8][cO2 - 3] = 176;
		x[rO2 + 8][cO2 - 2] = 176;
		x[rO2 + 8][cO2 - 1] = 176;
		x[rO2 + 8][cO2] = 176;
		x[rO2 + 8][cO2 + 1] = 176;
		x[rO2 + 8][cO2 + 2] = 176;
		x[rO2 + 8][cO2 + 3] = 176;

		x[rO2 + 7][cO2 - 2] = 176;
		x[rO2 + 7][cO2 - 1] = 176;
		x[rO2 + 7][cO2] = 176;
		x[rO2 + 7][cO2 + 1] = 176;
		x[rO2 + 7][cO2 + 2] = 176;

		x[rO2 + 6][cO2 - 1] = 176;
		x[rO2 + 6][cO2] = 176;
		x[rO2 + 6][cO2 + 1] = 176;

		x[rO2 + 5][cO2] = 176;


	}


	{

		x[rO3 + 21][cO3] = 179;
		x[rO3 + 20][cO3] = 179;
		x[rO3 + 19][cO3] = 179;
		x[rO3 + 18][cO3] = 179;
		x[rO3 + 17][cO3] = 179;
		x[rO3 + 16][cO3] = 179;
		x[rO3 + 15][cO3] = 179;
		x[rO3 + 14][cO3] = 179;
		x[rO3 + 13][cO3] = 179;
		x[rO3 + 12][cO3] = 179;
		x[rO3 + 11][cO3] = 179;
		x[rO3 + 10][cO3] = 179;
		x[rO3 + 9][cO3] = 179;
		x[rO3 + 8][cO3] = 179;
		x[rO3 + 7][cO3] = 179;
		x[rO3 + 6][cO3] = 179;
		x[rO3 + 5][cO3] = 179;

		x[rO3 + 5][cO3 - 1] = 22;
	}

	{

		x[rO4 + 21][cO4] = 179;
		x[rO4 + 20][cO4] = 179;
		x[rO4 + 19][cO4] = 179;
		x[rO4 + 18][cO4] = 179;
		x[rO4 + 17][cO4] = 179;
		x[rO4 + 16][cO4] = 179;
		x[rO4 + 15][cO4] = 179;
		x[rO4 + 14][cO4] = 179;
		x[rO4 + 13][cO4] = 179;
		x[rO4 + 12][cO4] = 179;
		x[rO4 + 11][cO4] = 179;
		x[rO4 + 10][cO4] = 179;
		x[rO4 + 9][cO4] = 179;
		x[rO4 + 8][cO4] = 179;
		x[rO4 + 7][cO4] = 179;
		x[rO4 + 6][cO4] = 179;
		x[rO4 + 5][cO4] = 179;


		x[rO4 + 5][cO4 - 1] = 22;
	}


	{

		x[rO5 + 21][cO5] = 186;
		x[rO5 + 20][cO5] = 186;
		x[rO5 + 19][cO5] = 186;
		x[rO5 + 18][cO5] = 186;
		x[rO5 + 17][cO5] = 186;
		x[rO5 + 16][cO5] = 186;
		x[rO5 + 15][cO5] = 186;
		x[rO5 + 14][cO5] = 186;
		x[rO5 + 13][cO5] = 186;

		x[rO5 + 13][cO5 - 8] = 176;
		x[rO5 + 13][cO5 - 7] = 176;
		x[rO5 + 13][cO5 - 6] = 176;
		x[rO5 + 13][cO5 - 5] = 176;
		x[rO5 + 13][cO5 - 4] = 176;
		x[rO5 + 13][cO5 - 3] = 176;
		x[rO5 + 13][cO5 - 2] = 176;
		x[rO5 + 13][cO5 - 1] = 176;
		x[rO5 + 13][cO5] = 176;
		x[rO5 + 13][cO5 + 1] = 176;
		x[rO5 + 13][cO5 + 2] = 176;
		x[rO5 + 13][cO5 + 3] = 176;
		x[rO5 + 13][cO5 + 4] = 176;
		x[rO5 + 13][cO5 + 5] = 176;
		x[rO5 + 13][cO5 + 6] = 176;
		x[rO5 + 13][cO5 + 7] = 176;
		x[rO5 + 13][cO5 + 8] = 176;

		x[rO5 + 12][cO5 - 7] = 176;
		x[rO5 + 12][cO5 - 6] = 176;
		x[rO5 + 12][cO5 - 5] = 176;
		x[rO5 + 12][cO5 - 4] = 176;
		x[rO5 + 12][cO5 - 3] = 176;
		x[rO5 + 12][cO5 - 2] = 176;
		x[rO5 + 12][cO5 - 1] = 176;
		x[rO5 + 12][cO5] = 176;
		x[rO5 + 12][cO5 + 1] = 176;
		x[rO5 + 12][cO5 + 2] = 176;
		x[rO5 + 12][cO5 + 3] = 176;
		x[rO5 + 12][cO5 + 4] = 176;
		x[rO5 + 12][cO5 + 5] = 176;
		x[rO5 + 12][cO5 + 6] = 176;
		x[rO5 + 12][cO5 + 7] = 176;

		x[rO5 + 11][cO5 - 6] = 176;
		x[rO5 + 11][cO5 - 5] = 176;
		x[rO5 + 11][cO5 - 4] = 176;
		x[rO5 + 11][cO5 - 3] = 176;
		x[rO5 + 11][cO5 - 2] = 176;
		x[rO5 + 11][cO5 - 1] = 176;
		x[rO5 + 11][cO5] = 176;
		x[rO5 + 11][cO5 + 1] = 176;
		x[rO5 + 11][cO5 + 2] = 176;
		x[rO5 + 11][cO5 + 3] = 176;
		x[rO5 + 11][cO5 + 4] = 176;
		x[rO5 + 11][cO5 + 5] = 176;
		x[rO5 + 11][cO5 + 6] = 176;

		x[rO5 + 10][cO5 - 5] = 176;
		x[rO5 + 10][cO5 - 4] = 176;
		x[rO5 + 10][cO5 - 3] = 176;
		x[rO5 + 10][cO5 - 2] = 176;
		x[rO5 + 10][cO5 - 1] = 176;
		x[rO5 + 10][cO5] = 176;
		x[rO5 + 10][cO5 + 1] = 176;
		x[rO5 + 10][cO5 + 2] = 176;
		x[rO5 + 10][cO5 + 3] = 176;
		x[rO5 + 10][cO5 + 4] = 176;
		x[rO5 + 10][cO5 + 5] = 176;

		x[rO5 + 9][cO5 - 4] = 176;
		x[rO5 + 9][cO5 - 3] = 176;
		x[rO5 + 9][cO5 - 2] = 176;
		x[rO5 + 9][cO5 - 1] = 176;
		x[rO5 + 9][cO5] = 176;
		x[rO5 + 9][cO5 + 1] = 176;
		x[rO5 + 9][cO5 + 2] = 176;
		x[rO5 + 9][cO5 + 3] = 176;
		x[rO5 + 9][cO5 + 4] = 176;

		x[rO5 + 8][cO5 - 3] = 176;
		x[rO5 + 8][cO5 - 2] = 176;
		x[rO5 + 8][cO5 - 1] = 176;
		x[rO5 + 8][cO5] = 176;
		x[rO5 + 8][cO5 + 1] = 176;
		x[rO5 + 8][cO5 + 2] = 176;
		x[rO5 + 8][cO5 + 3] = 176;

		x[rO5 + 7][cO5 - 2] = 176;
		x[rO5 + 7][cO5 - 1] = 176;
		x[rO5 + 7][cO5] = 176;
		x[rO5 + 7][cO5 + 1] = 176;
		x[rO5 + 7][cO5 + 2] = 176;

		x[rO5 + 6][cO5 - 1] = 176;
		x[rO5 + 6][cO5] = 176;
		x[rO5 + 6][cO5 + 1] = 176;

		x[rO5 + 5][cO5] = 176;


	}

	{

		x[rO6 + 21][cO6] = 179;
		x[rO6 + 20][cO6] = 179;
		x[rO6 + 19][cO6] = 179;
		x[rO6 + 18][cO6] = 179;
		x[rO6 + 17][cO6] = 179;
		x[rO6 + 16][cO6] = 179;
		x[rO6 + 15][cO6] = 179;
		x[rO6 + 14][cO6] = 179;
		x[rO6 + 13][cO6] = 179;
		x[rO6 + 12][cO6] = 179;
		x[rO6 + 11][cO6] = 179;
		x[rO6 + 10][cO6] = 179;
		x[rO6 + 9][cO6] = 179;
		x[rO6 + 8][cO6] = 179;
		x[rO6 + 7][cO6] = 179;
		x[rO6 + 6][cO6] = 179;
		x[rO6 + 5][cO6] = 179;

		x[rO6 + 5][cO6 - 1] = 22;
	}

	{

		x[rO7 + 21][cO7] = 186;
		x[rO7 + 20][cO7] = 186;
		x[rO7 + 19][cO7] = 186;
		x[rO7 + 18][cO7] = 186;
		x[rO7 + 17][cO7] = 186;
		x[rO7 + 16][cO7] = 186;
		x[rO7 + 15][cO7] = 186;
		x[rO7 + 14][cO7] = 186;
		x[rO7 + 13][cO7] = 186;

		x[rO7 + 13][cO7 - 8] = 176;
		x[rO7 + 13][cO7 - 7] = 176;
		x[rO7 + 13][cO7 - 6] = 176;
		x[rO7 + 13][cO7 - 5] = 176;
		x[rO7 + 13][cO7 - 4] = 176;
		x[rO7 + 13][cO7 - 3] = 176;
		x[rO7 + 13][cO7 - 2] = 176;
		x[rO7 + 13][cO7 - 1] = 176;
		x[rO7 + 13][cO7] = 176;
		x[rO7 + 13][cO7 + 1] = 176;
		x[rO7 + 13][cO7 + 2] = 176;
		x[rO7 + 13][cO7 + 3] = 176;
		x[rO7 + 13][cO7 + 4] = 176;
		x[rO7 + 13][cO7 + 5] = 176;
		x[rO7 + 13][cO7 + 6] = 176;
		x[rO7 + 13][cO7 + 7] = 176;
		x[rO7 + 13][cO7 + 8] = 176;

		x[rO7 + 12][cO7 - 7] = 176;
		x[rO7 + 12][cO7 - 6] = 176;
		x[rO7 + 12][cO7 - 5] = 176;
		x[rO7 + 12][cO7 - 4] = 176;
		x[rO7 + 12][cO7 - 3] = 176;
		x[rO7 + 12][cO7 - 2] = 176;
		x[rO7 + 12][cO7 - 1] = 176;
		x[rO7 + 12][cO7] = 176;
		x[rO7 + 12][cO7 + 1] = 176;
		x[rO7 + 12][cO7 + 2] = 176;
		x[rO7 + 12][cO7 + 3] = 176;
		x[rO7 + 12][cO7 + 4] = 176;
		x[rO7 + 12][cO7 + 5] = 176;
		x[rO7 + 12][cO7 + 6] = 176;
		x[rO7 + 12][cO7 + 7] = 176;

		x[rO7 + 11][cO7 - 6] = 176;
		x[rO7 + 11][cO7 - 5] = 176;
		x[rO7 + 11][cO7 - 4] = 176;
		x[rO7 + 11][cO7 - 3] = 176;
		x[rO7 + 11][cO7 - 2] = 176;
		x[rO7 + 11][cO7 - 1] = 176;
		x[rO7 + 11][cO7] = 176;
		x[rO7 + 11][cO7 + 1] = 176;
		x[rO7 + 11][cO7 + 2] = 176;
		x[rO7 + 11][cO7 + 3] = 176;
		x[rO7 + 11][cO7 + 4] = 176;
		x[rO7 + 11][cO7 + 5] = 176;
		x[rO7 + 11][cO7 + 6] = 176;

		x[rO7 + 10][cO7 - 5] = 176;
		x[rO7 + 10][cO7 - 4] = 176;
		x[rO7 + 10][cO7 - 3] = 176;
		x[rO7 + 10][cO7 - 2] = 176;
		x[rO7 + 10][cO7 - 1] = 176;
		x[rO7 + 10][cO7] = 176;
		x[rO7 + 10][cO7 + 1] = 176;
		x[rO7 + 10][cO7 + 2] = 176;
		x[rO7 + 10][cO7 + 3] = 176;
		x[rO7 + 10][cO7 + 4] = 176;
		x[rO7 + 10][cO7 + 5] = 176;

		x[rO7 + 9][cO7 - 4] = 176;
		x[rO7 + 9][cO7 - 3] = 176;
		x[rO7 + 9][cO7 - 2] = 176;
		x[rO7 + 9][cO7 - 1] = 176;
		x[rO7 + 9][cO7] = 176;
		x[rO7 + 9][cO7 + 1] = 176;
		x[rO7 + 9][cO7 + 2] = 176;
		x[rO7 + 9][cO7 + 3] = 176;
		x[rO7 + 9][cO7 + 4] = 176;

		x[rO7 + 8][cO7 - 3] = 176;
		x[rO7 + 8][cO7 - 2] = 176;
		x[rO7 + 8][cO7 - 1] = 176;
		x[rO7 + 8][cO7] = 176;
		x[rO7 + 8][cO7 + 1] = 176;
		x[rO7 + 8][cO7 + 2] = 176;
		x[rO7 + 8][cO7 + 3] = 176;

		x[rO7 + 7][cO7 - 2] = 176;
		x[rO7 + 7][cO7 - 1] = 176;
		x[rO7 + 7][cO7] = 176;
		x[rO7 + 7][cO7 + 1] = 176;
		x[rO7 + 7][cO7 + 2] = 176;

		x[rO7 + 6][cO7 - 1] = 176;
		x[rO7 + 6][cO7] = 176;
		x[rO7 + 6][cO7 + 1] = 176;

		x[rO7 + 5][cO7] = 176;


	}

	/*{
	x[rO8 + 23][cO8] = 179;
	x[rO8 + 22][cO8] = 179;
	x[rO8 + 21][cO8] = 179;
	x[rO8 + 20][cO8] = 179;
	x[rO8 + 19][cO8] = 179;
	x[rO8 + 18][cO8] = 179;
	x[rO8 + 17][cO8] = 179;
	x[rO8 + 16][cO8] = 179;
	x[rO8 + 15][cO8] = 179;
	x[rO8 + 14][cO8] = 179;
	x[rO8 + 13][cO8] = 179;
	x[rO8 + 12][cO8] = 179;
	x[rO8 + 11][cO8] = 179;
	x[rO8 + 10][cO8] = 179;
	x[rO8 + 9][cO8] = 179;
	x[rO8 + 8][cO8] = 179;
	x[rO8 + 7][cO8] = 179;
	x[rO8 + 6][cO8] = 179;
	x[rO8 + 5][cO8] = 179;

	x[rO8 + 5][cO8 - 1] = 22;
	}*/


	{

		x[rO9 + 21][cO9] = 186;
		x[rO9 + 20][cO9] = 186;
		x[rO9 + 19][cO9] = 186;
		x[rO9 + 18][cO9] = 186;
		x[rO9 + 17][cO9] = 186;
		x[rO9 + 16][cO9] = 186;
		x[rO9 + 15][cO9] = 186;
		x[rO9 + 14][cO9] = 186;
		x[rO9 + 13][cO9] = 186;

		x[rO9 + 13][cO9 - 8] = 176;
		x[rO9 + 13][cO9 - 7] = 176;
		x[rO9 + 13][cO9 - 6] = 176;
		x[rO9 + 13][cO9 - 5] = 176;
		x[rO9 + 13][cO9 - 4] = 176;
		x[rO9 + 13][cO9 - 3] = 176;
		x[rO9 + 13][cO9 - 2] = 176;
		x[rO9 + 13][cO9 - 1] = 176;
		x[rO9 + 13][cO9] = 176;
		x[rO9 + 13][cO9 + 1] = 176;
		x[rO9 + 13][cO9 + 2] = 176;
		x[rO9 + 13][cO9 + 3] = 176;
		x[rO9 + 13][cO9 + 4] = 176;
		x[rO9 + 13][cO9 + 5] = 176;
		x[rO9 + 13][cO9 + 6] = 176;
		x[rO9 + 13][cO9 + 7] = 176;
		x[rO9 + 13][cO9 + 8] = 176;

		x[rO9 + 12][cO9 - 7] = 176;
		x[rO9 + 12][cO9 - 6] = 176;
		x[rO9 + 12][cO9 - 5] = 176;
		x[rO9 + 12][cO9 - 4] = 176;
		x[rO9 + 12][cO9 - 3] = 176;
		x[rO9 + 12][cO9 - 2] = 176;
		x[rO9 + 12][cO9 - 1] = 176;
		x[rO9 + 12][cO9] = 176;
		x[rO9 + 12][cO9 + 1] = 176;
		x[rO9 + 12][cO9 + 2] = 176;
		x[rO9 + 12][cO9 + 3] = 176;
		x[rO9 + 12][cO9 + 4] = 176;
		x[rO9 + 12][cO9 + 5] = 176;
		x[rO9 + 12][cO9 + 6] = 176;
		x[rO9 + 12][cO9 + 7] = 176;

		x[rO9 + 11][cO9 - 6] = 176;
		x[rO9 + 11][cO9 - 5] = 176;
		x[rO9 + 11][cO9 - 4] = 176;
		x[rO9 + 11][cO9 - 3] = 176;
		x[rO9 + 11][cO9 - 2] = 176;
		x[rO9 + 11][cO9 - 1] = 176;
		x[rO9 + 11][cO9] = 176;
		x[rO9 + 11][cO9 + 1] = 176;
		x[rO9 + 11][cO9 + 2] = 176;
		x[rO9 + 11][cO9 + 3] = 176;
		x[rO9 + 11][cO9 + 4] = 176;
		x[rO9 + 11][cO9 + 5] = 176;
		x[rO9 + 11][cO9 + 6] = 176;

		x[rO9 + 10][cO9 - 5] = 176;
		x[rO9 + 10][cO9 - 4] = 176;
		x[rO9 + 10][cO9 - 3] = 176;
		x[rO9 + 10][cO9 - 2] = 176;
		x[rO9 + 10][cO9 - 1] = 176;
		x[rO9 + 10][cO9] = 176;
		x[rO9 + 10][cO9 + 1] = 176;
		x[rO9 + 10][cO9 + 2] = 176;
		x[rO9 + 10][cO9 + 3] = 176;
		x[rO9 + 10][cO9 + 4] = 176;
		x[rO9 + 10][cO9 + 5] = 176;

		x[rO9 + 9][cO9 - 4] = 176;
		x[rO9 + 9][cO9 - 3] = 176;
		x[rO9 + 9][cO9 - 2] = 176;
		x[rO9 + 9][cO9 - 1] = 176;
		x[rO9 + 9][cO9] = 176;
		x[rO9 + 9][cO9 + 1] = 176;
		x[rO9 + 9][cO9 + 2] = 176;
		x[rO9 + 9][cO9 + 3] = 176;
		x[rO9 + 9][cO9 + 4] = 176;

		x[rO9 + 8][cO9 - 3] = 176;
		x[rO9 + 8][cO9 - 2] = 176;
		x[rO9 + 8][cO9 - 1] = 176;
		x[rO9 + 8][cO9] = 176;
		x[rO9 + 8][cO9 + 1] = 176;
		x[rO9 + 8][cO9 + 2] = 176;
		x[rO9 + 8][cO9 + 3] = 176;

		x[rO9 + 7][cO9 - 2] = 176;
		x[rO9 + 7][cO9 - 1] = 176;
		x[rO9 + 7][cO9] = 176;
		x[rO9 + 7][cO9 + 1] = 176;
		x[rO9 + 7][cO9 + 2] = 176;

		x[rO9 + 6][cO9 - 1] = 176;
		x[rO9 + 6][cO9] = 176;
		x[rO9 + 6][cO9 + 1] = 176;

		x[rO9 + 5][cO9] = 176;

		//	SetConsoleTextAttribute(hConsole, 15);
	}
}

void DynamicObjects2(char x[][2000], int& cO1, int& rO1, int& cO2, int& rO2, int& cO3, int& rO3, int& cO4, int& rO4, int& cO5, int& rO5, int& cO6, int& rO6, int&cO7, int& rO7, int& cO8, int& rO8, int& cO9, int& rO9, int CounterUntilStop, int level, char keyB, int AutoWalk, int value, int cH, int yeswalk)
{
	if ((level == 6) && (keyB == 'd' || keyB == 'D') && yeswalk == 1)
	{


		cO1 -= 3;
		cO2 -= 3;
		cO3 -= 3;
		cO4 -= 3;
		cO5 -= 3;
		cO6 -= 3;
		cO7 -= 3;
		cO8 -= 3;
		cO9 -= 3;
		if (cO1 <= value)
		{
			rO1 = -2;
			cO1 = 137 + value;
		}

		if (cO2 <= value)
		{
			rO2 = -2;
			cO2 = 137 + value;
		}
		if (cO3 <= value)
		{
			rO3 = -2;
			cO3 = 137 + value;
		}
		if (cO4 <= value)
		{
			rO4 = -2;
			cO4 = 137 + value;
		}
		if (cO5 <= value)
		{
			rO5 = -2;
			cO5 = 137 + value;
		}
		if (cO6 <= value)
		{
			rO6 = -2;
			cO6 = 137 + value;
		}
		if (cO7 <= value)
		{
			rO7 = -2;
			cO7 = 137 + value;
		}

		if (cO9 <= value)
		{
			rO9 = -2;
			cO9 = 137 + value;
		}

	}

	if ((level == 6) && (keyB == 'a' || keyB == 'A') && yeswalk == 1)
	{
		if (cH - 4 > 0)
		{

			cO1 += 3;
			cO2 += 3;
			cO3 += 3;
			cO4 += 3;
			cO5 += 3;
			cO6 += 3;
			cO7 += 3;
			cO8 += 3;
			cO9 += 3;
			if (cO1 >= value + 137)
			{
				rO1 = -2;
				cO1 = value;
			}

			if (cO2 >= value + 137)
			{
				rO2 = -2;
				cO2 = value;
			}
			if (cO3 >= value + 137)
			{
				rO3 = -2;
				cO3 = value;
			}
			if (cO4 >= value + 137)
			{
				rO4 = -2;
				cO4 = value;
			}
			if (cO5 >= value + 137)
			{
				rO5 = -2;
				cO5 = value;
			}
			if (cO6 >= value + 137)
			{
				rO6 = -2;
				cO6 = value;
			}
			if (cO7 >= value + 137)
			{
				rO7 = -2;
				cO7 = value;
			}

			if (cO9 >= value + 137)
			{
				rO9 = -2;
				cO9 = value;
			}
		}
	}
}

void DynamicObjects2_2(char x[][2000], int& cO1, int& rO1, int& cO2, int& rO2, int& cO3, int& rO3, int& cO4, int& rO4, int& cO5, int& rO5, int& cO6, int& rO6, int&cO7, int& rO7, int& cO8, int& rO8, int& cO9, int& rO9, int CounterUntilStop, int level, int AutoWalk, int value, int AirTubeStat, int AttachRobe)
{
	if (AutoWalk == 1 || AirTubeStat == 1 || AttachRobe == 1)
	{


		cO1 -= 3;
		cO2 -= 3;
		cO3 -= 3;
		cO4 -= 3;
		cO5 -= 3;
		cO6 -= 3;
		cO7 -= 3;
		cO8 -= 3;
		cO9 -= 3;
		if (cO1 <= value)
		{
			rO1 = -2;
			cO1 = 137 + value;
		}

		if (cO2 <= value)
		{
			rO2 = -2;
			cO2 = 137 + value;
		}
		if (cO3 <= value)
		{
			rO3 = -2;
			cO3 = 137 + value;
		}
		if (cO4 <= value)
		{
			rO4 = -2;
			cO4 = 137 + value;
		}
		if (cO5 <= value)
		{
			rO5 = -2;
			cO5 = 137 + value;
		}
		if (cO6 <= value)
		{
			rO6 = -2;
			cO6 = 137 + value;
		}
		if (cO7 <= value)
		{
			rO7 = -2;
			cO7 = 137 + value;
		}

		if (cO9 <= value)
		{
			rO9 = -2;
			cO9 = 137 + value;
		}

	}


}

void DynamicObjects3(char x[][138], int& cO1, int& rO1, int& cO2, int& rO2, int& cO3, int& rO3, int& cO4, int& rO4, int& cO5, int& rO5, int& cO6, int& rO6, int&cO7, int& rO7, int& cO8, int& rO8, int& cO9, int& rO9, int CounterUntilStop, int level, char keyB, int& cFC, int AutoWalk)
{
	if ((level == 6 && (keyB == 'd' || keyB == 'D')))
	{
		cO1 -= 3;
		cO2 -= 3;
		cO3 -= 3;
		cO4 -= 3;
		cO5 -= 3;
		cO6 -= 3;
		cO7 -= 3;
		cO8 -= 3;
		cO9 -= 3;
		if (cO1 <= 0)
		{
			rO1 = 3;
			cO1 = 137;
		}

		if (cO2 <= 0)
		{
			rO2 = 3;
			cO2 = 137;
		}
		if (cO3 <= 0)
		{
			rO3 = 3;
			cO3 = 137;
		}
		if (cO4 <= 0)
		{
			rO4 = 3;
			cO4 = 137;
		}
		if (cO5 <= 0)
		{
			rO5 = 3;
			cO5 = 137;
		}
		if (cO6 <= 0)
		{
			rO6 = 3;
			cO6 = 137;
		}
		if (cO7 <= 0)
		{
			rO7 = 3;
			cO7 = 137;
		}

		if (cO9 <= 0)
		{
			rO9 = 3;
			cO9 = 137;
		}
	}
	else
	{
		if (cO1 <= 0)
		{
			rO1 = 3;
			cO1 = 137;
		}

		if (cO2 <= 0)
		{
			rO2 = 3;
			cO2 = 137;
		}
		if (cO3 <= 0)
		{
			rO3 = 3;
			cO3 = 137;
		}
		if (cO4 <= 0)
		{
			rO4 = 3;
			cO4 = 137;
		}
		if (cO5 <= 0)
		{
			rO5 = 3;
			cO5 = 137;
		}
		if (cO6 <= 0)
		{
			rO6 = 3;
			cO6 = 137;
		}
		if (cO7 <= 0)
		{
			rO7 = 3;
			cO7 = 137;
		}

		if (cO9 <= 0)
		{
			rO9 = 3;
			cO9 = 137;
		}



	}


}

void StaticFloor(char x[][2000], int& cF, int CounterFloor, int level, int value)
{
	if (CounterFloor == 0)
	{

		for (cF = value; cF < 138 + value; cF += 2)			//FLOOR
		{
			x[47][cF] = 205;
		}



		if (level == 6)
		{
			for (cF = value; cF < 138 + value; cF++)			//SIDEWALK
			{

				x[19][cF] = 177;
			}
		}




	}




	if (CounterFloor % 2 == 0)
	{

		for (cF = value; cF < 138 + value; cF += 2)
		{
			x[47][cF] = 205;
		}



		if (level == 6)
		{
			for (cF = value; cF < 138 + value; cF++)			//SIDEWALK
			{

				x[19][cF] = 177;
			}
		}




	}

	else
	{

		for (cF = 1 + value; cF < 138 + value; cF += 2)
		{
			x[47][cF] = 205;
		}


		if (level == 6)
		{
			for (cF = value; cF < 138 + value; cF++)			//SIDEWALK
			{

				x[19][cF] = 177;
			}
		}



	}



}

void StaticFloor4(char x[][138], int& cF, int CounterFloor, int level, int& rT, int& cT, int rR, int cR)
{
	if (CounterFloor == 0)
	{
		for (cF = 0; cF < 138; cF += 2)			//FLOOR
		{
			x[47][cF] = 205;
		}
		for (cF = 0; cF < 138; cF++)			//SIDEWALK
		{

			x[19][cF] = 177;
		}
	}

	if (CounterFloor % 2 == 0)
	{
		for (cF = 0; cF < 138; cF += 2)			//FLOOR
		{
			x[47][cF] = 205;
		}
		for (cF = 0; cF < 138; cF++)			//SIDEWALK
		{

			x[19][cF] = 177;
		}
	}
	else
	{
		for (cF = 1; cF < 138; cF += 2)
		{
			x[47][cF] = 205;
		}
		for (cF = 1; cF < 138; cF++)			//SIDEWALK
		{

			x[19][cF] = 177;
		}
	}

	x[rT][cT] = '/';
	x[rT][cT + 1] = '\\';
	x[rT][cT + 2] = '/';
	x[rT][cT + 3] = '\\';
	x[rT][cT + 4] = '/';
	x[rT][cT + 5] = '\\';
	x[rT][cT + 6] = '/';
	x[rT][cT + 7] = '\\';
	x[rT][cT + 8] = '/';
	x[rT][cT + 9] = '\\';
	x[rT][cT + 10] = '/';
	x[rT][cT + 11] = '\\';
	x[rT][cT + 12] = '/';
	x[rT][cT + 13] = '\\';
	x[rT][cT + 14] = '/';
	x[rT][cT + 15] = '\\';
	x[rT][cT + 16] = '/';
	x[rT][cT + 17] = '\\';
	x[rT][cT + 18] = '/';
	x[rT][cT + 19] = '\\';
	x[rT][cT + 20] = '/';
	x[rT][cT + 21] = '\\';
	x[rT][cT + 22] = '/';
	x[rT][cT + 23] = '\\';
	x[rT][cT + 24] = '/';
	x[rT][cT + 25] = '\\';
	x[rT][cT + 26] = '/';
	x[rT][cT + 27] = '\\';
	x[rT][cT + 28] = '/';
	x[rT][cT + 29] = '\\';
	x[rT][cT + 30] = '/';
	x[rT][cT + 31] = '\\';
	x[rT][cT + 32] = '/';
	x[rT][cT + 33] = '\\';
	x[rT][cT + 34] = '/';
	x[rT][cT + 35] = '\\';
	x[rT][cT + 36] = '/';
	x[rT][cT + 37] = '\\';
	x[rT][cT + 38] = '/';
	x[rT][cT + 39] = '\\';
	x[rT][cT + 40] = '/';
	x[rT][cT + 41] = '\\';
	x[rT][cT + 42] = '/';
	x[rT][cT + 43] = '\\';
	x[rT][cT + 44] = '/';
	x[rT][cT + 45] = '\\';
	x[rT][cT + 46] = '/';
	x[rT][cT + 47] = '\\';
	x[rT][cT + 48] = '/';
	x[rT][cT + 49] = '\\';
	x[rT][cT + 50] = '/';
	x[rT][cT + 51] = '\\';
	x[rT][cT + 52] = '/';
	x[rT][cT + 53] = '\\';
	x[rT][cT + 54] = '/';
	x[rT][cT + 55] = '\\';
	x[rT][cT + 56] = '/';
	x[rT][cT + 57] = '\\';
	x[rT][cT + 58] = '/';
	x[rT][cT + 59] = '\\';
	x[rT][cT + 60] = '/';
	x[rT][cT + 61] = '\\';
	x[rT][cT + 62] = '/';
	x[rT][cT + 63] = '\\';
	x[rT][cT + 64] = '/';
	x[rT][cT + 65] = '\\';

	x[rR + 1][cR] = 179;
	x[rR + 2][cR] = 179;
	x[rR + 3][cR] = 179;
	x[rR + 4][cR] = 179;
	x[rR + 5][cR] = 179;
	x[rR + 6][cR] = 179;
	x[rR + 7][cR] = 179;
	x[rR + 8][cR] = 179;
	x[rR + 9][cR] = 179;
	x[rR + 10][cR] = 179;
	x[rR + 11][cR] = 179;
	x[rR + 12][cR] = 179;
	x[rR + 13][cR] = 179;
	x[rR + 14][cR] = 179;
	x[rR + 15][cR] = 179;
	x[rR + 16][cR] = 179;
	x[rR + 17][cR] = 179;
	x[rR + 18][cR] = 179;
	x[rR + 19][cR] = 179;
	x[rR + 20][cR] = 179;
	x[rR + 21][cR] = 179;
	x[rR + 22][cR] = 179;
	x[rR + 23][cR] = 179;
	x[rR + 24][cR] = 179;
	x[rR + 25][cR] = 179;
	x[rR + 26][cR] = 179;
	x[rR + 27][cR] = 179;
	x[rR + 28][cR] = 179;
	x[rR + 29][cR] = 179;
	x[rR + 30][cR] = 179;
	x[rR + 31][cR] = 179;
	x[rR + 32][cR] = 179;
	x[rR + 33][cR] = 179;
	x[rR + 34][cR] = 179;


	cT -= 16;

	if (cT + 30 <= 0)
	{
		cT = 95;
	}

}

void StaticHero(char x[][2000], int &rH, int &cH, int countRLHL1, int& CountStart, int& LeftLook, int rEv, int Reload, int& ActionReload, int level, int rB, int cB, int GunsTook, int laserstat, int lasersecs, int eyecount)
{

	if (rH < 0)
	{
		rH = rEv + 1;
	}
	x[rH][cH - 1] = '_';
	x[rH][cH] = '_';
	x[rH][cH + 1] = '_';
	x[rH][cH + 2] = '_';

	if (laserstat == 0 && lasersecs == 0)
	{
		if (eyecount % 3 == 0)
		{
			if (LeftLook == 1)
			{

				x[rH + 2][cH] = ' ';
				x[rH + 2][cH + 2] = ' ';

				x[rH + 2][cH + 1] = '-';
				x[rH + 2][cH - 1] = '-';

			}
			else
			{
				x[rH + 2][cH] = '-';
				x[rH + 2][cH + 2] = '-';

				x[rH + 2][cH + 1] = ' ';
				x[rH + 2][cH - 1] = ' ';
			}
		}
	}
	else
	{
		if (LeftLook == 1)
		{

			x[rH + 2][cH] = ' ';
			x[rH + 2][cH + 2] = ' ';

			x[rH + 2][cH + 1] = '-';
			x[rH + 2][cH - 1] = '-';

		}
		else
		{
			x[rH + 2][cH] = '-';
			x[rH + 2][cH + 2] = '-';

			x[rH + 2][cH + 1] = ' ';
			x[rH + 2][cH - 1] = ' ';
		}
	}
	x[rH + 1][cH - 2] = '/';
	x[rH + 1][cH + 3] = '\\';

	x[rH + 2][cH - 2] = '|';
	x[rH + 2][cH + 3] = '|';

	x[rH + 3][cH - 2] = '\\';
	x[rH + 3][cH + 3] = '/';

	x[rH + 3][cH - 1] = '_';
	x[rH + 3][cH] = '_';
	x[rH + 3][cH + 1] = 251;
	x[rH + 3][cH + 2] = '_';

	x[rH + 4][cH - 2] = '_';
	x[rH + 4][cH - 1] = '/';
	x[rH + 4][cH + 2] = '/';
	x[rH + 4][cH + 3] = '_';




	//x[rH + 5][cH + 3] = ' ';	   
	//x[rH + 6][cH + 3] = '|';	   
	x[rH + 7][cH + 3] = '|';

	//x[rH + 5][cH - 2] = ' ';
	//x[rH + 6][cH - 2] = ' ';
	x[rH + 7][cH - 2] = '|';

	x[rH + 7][cH - 1] = ' ';
	x[rH + 7][cH + 1] = ' ';
	x[rH + 7][cH + 2] = ' ';
	x[rH + 7][cH] = ' ';

	LeftLegMoveH1(x, rH, cH, countRLHL1);
	RightLegMoveH1(x, rH, cH, countRLHL1);

	RightHandMoveH1(x, rH, cH, countRLHL1, GunsTook);
	LeftHandMoveH1(x, rH, cH, countRLHL1, Reload, ActionReload, level, rB, cB, GunsTook);
	//if (CountStart == 1)
	//{
	//	rH = 26;
	//	CountStart++;
	//}
	//x[rH + 11][cH] = 'F';
	//x[rH + 10][cH + 5] = 'K';

}

void StaticHero6(char x[][2000], int &rH, int cH, int countRLHL1, int& CountStart, int& LeftLook, int rEv, int Reload, int& ActionReload, int level, int rB, int cB, int& DeathT, int& lose1)
{

	x[rH][cH - 1] = '_';
	x[rH][cH] = '_';
	x[rH][cH + 1] = '_';
	x[rH][cH + 2] = '_';

	if (LeftLook == 1)
	{

		x[rH + 2][cH] = ' ';
		x[rH + 2][cH + 2] = ' ';

		x[rH + 2][cH + 1] = 248;
		x[rH + 2][cH - 1] = 248;

	}
	else
	{
		x[rH + 2][cH] = 248;
		x[rH + 2][cH + 2] = 248;

		x[rH + 2][cH + 1] = ' ';
		x[rH + 2][cH - 1] = ' ';
	}

	x[rH + 1][cH - 2] = '/';
	x[rH + 1][cH + 3] = '\\';

	x[rH + 2][cH - 2] = '|';
	x[rH + 2][cH + 3] = '|';

	x[rH + 3][cH - 2] = '\\';
	x[rH + 3][cH + 3] = '/';

	x[rH + 3][cH - 1] = '_';
	x[rH + 3][cH] = '_';
	x[rH + 3][cH + 1] = 251;
	x[rH + 3][cH + 2] = '_';

	x[rH + 4][cH - 2] = '_';
	x[rH + 4][cH - 1] = '/';
	x[rH + 4][cH + 2] = '/';
	x[rH + 4][cH + 3] = '_';



	//x[rH + 5][cH + 3] = ' ';	   
	//x[rH + 6][cH + 3] = '|';	   
	x[rH + 7][cH + 3] = '_';

	//x[rH + 5][cH - 2] = ' ';
	//x[rH + 6][cH - 2] = ' ';
	x[rH + 7][cH - 2] = '|';

	x[rH + 7][cH - 1] = ' ';
	x[rH + 7][cH + 1] = ' ';
	x[rH + 7][cH + 2] = ' ';
	x[rH + 7][cH] = ' ';


	//x[rH + 7][cH - 1] = '_';
	//x[rH + 7][cH] = '_';
//	x[rH + 7][cH + 1] = '_';
	//x[rH + 7][cH + 2] = '_';

	x[rH + 4][cH + 4] = '_';
	x[rH + 4][cH + 5] = '|';
	x[rH + 3][cH + 5] = '|';
	x[rH + 2][cH + 5] = '|';
	x[rH + 1][cH + 5] = '|';
	x[rH][cH + 6] = '_';
	x[rH + 1][cH + 7] = '|';
	x[rH + 2][cH + 7] = '|';
	x[rH + 3][cH + 7] = '|';
	x[rH + 4][cH + 7] = '|';
	x[rH + 5][cH + 7] = '|';
	x[rH + 5][cH + 6] = '_';
	x[rH + 5][cH + 5] = '_';


	x[rH + 4][cH - 3] = '_';
	x[rH + 4][cH - 4] = '|';
	x[rH + 3][cH - 4] = '|';
	x[rH + 2][cH - 4] = '|';
	x[rH + 1][cH - 4] = '|';
	x[rH][cH - 5] = '_';
	x[rH + 1][cH - 6] = '|';
	x[rH + 2][cH - 6] = '|';
	x[rH + 3][cH - 6] = '|';
	x[rH + 4][cH - 6] = '|';
	x[rH + 5][cH - 6] = '|';
	x[rH + 5][cH - 5] = '_';
	x[rH + 5][cH - 4] = '_';



	x[rH + 7][cH + 4] = '_';
	x[rH + 7][cH + 5] = '_';
	x[rH + 7][cH + 6] = '_';
	x[rH + 7][cH + 7] = '_';
	x[rH + 7][cH + 8] = '_';
	x[rH + 7][cH + 9] = 179;
	x[rH + 6][cH + 8] = '_';
	x[rH + 6][cH + 7] = '_';
	x[rH + 6][cH + 6] = '_';
	x[rH + 6][cH + 5] = '_';
	x[rH + 6][cH + 4] = '_';

	x[rH + 8][cH - 2] = '|';

	//x[rH + 8][cH - 1] = '_';
	x[rH + 8][cH] = '_';
	x[rH + 8][cH + 1] = '_';
	x[rH + 8][cH + 2] = '_';
	x[rH + 8][cH + 3] = '_';
	x[rH + 8][cH + 4] = '_';
	x[rH + 8][cH + 5] = '_';
	x[rH + 8][cH + 6] = '_';
	x[rH + 8][cH + 7] = '_';
	x[rH + 8][cH + 8] = 179;






}

void StaticHero6_2(char x[][2000], int rH, int cH, int counter)
{
	x[rH][cH - 1] = '_';
	x[rH][cH] = '_';
	x[rH][cH + 1] = '_';
	x[rH][cH + 2] = '_';

	x[rH + 1][cH - 1] = ' ';
	x[rH + 1][cH] = ' ';
	x[rH + 1][cH + 1] = ' ';
	x[rH + 1][cH + 2] = ' ';

	x[rH + 2][cH - 1] = ' ';
	x[rH + 2][cH] = ' ';
	x[rH + 2][cH + 1] = ' ';
	x[rH + 2][cH + 2] = ' ';


	x[rH + 1][cH - 2] = '/';
	x[rH + 1][cH + 3] = '\\';

	x[rH + 2][cH - 2] = '|';
	x[rH + 2][cH + 3] = '|';

	x[rH + 3][cH - 2] = '\\';
	x[rH + 3][cH + 3] = '/';

	x[rH + 3][cH - 1] = '_';
	x[rH + 3][cH] = '_';
	x[rH + 3][cH + 1] = '_';
	x[rH + 3][cH + 2] = '_';

	x[rH + 4][cH - 2] = '_';
	x[rH + 4][cH - 1] = 179;
	x[rH + 4][cH + 2] = 179;
	x[rH + 4][cH + 3] = '_';

	x[rH + 4][cH] = ' ';
	x[rH + 4][cH + 1] = ' ';

	if (counter % 2 == 0)
	{

		x[rH + 4][cH + 4] = '_';
		x[rH + 4][cH + 5] = '|';
		x[rH + 3][cH + 5] = '|';
		x[rH + 2][cH + 5] = '|';
		x[rH + 1][cH + 5] = '|';
		x[rH][cH + 6] = '_';
		x[rH + 1][cH + 7] = '|';
		x[rH + 2][cH + 7] = '|';
		x[rH + 3][cH + 7] = '|';
		x[rH + 4][cH + 7] = '|';
		x[rH + 5][cH + 7] = '|';
		x[rH + 5][cH + 6] = '_';
		x[rH + 5][cH + 5] = '_';


		x[rH + 1][cH + 6] = ' ';
		x[rH + 2][cH + 6] = ' ';
		x[rH + 3][cH + 6] = ' ';
		x[rH + 4][cH + 6] = ' ';

		x[rH + 4][cH - 3] = '_';
		x[rH + 4][cH - 4] = '|';
		x[rH + 3][cH - 4] = '|';
		x[rH + 2][cH - 4] = '|';
		x[rH + 1][cH - 4] = '|';
		x[rH][cH - 5] = '_';
		x[rH + 1][cH - 6] = '|';
		x[rH + 2][cH - 6] = '|';
		x[rH + 3][cH - 6] = '|';
		x[rH + 4][cH - 6] = '|';
		x[rH + 5][cH - 6] = '|';
		x[rH + 5][cH - 5] = '_';
		x[rH + 5][cH - 4] = '_';

		x[rH + 1][cH - 5] = ' ';
		x[rH + 2][cH - 5] = ' ';
		x[rH + 3][cH - 5] = ' ';
		x[rH + 4][cH - 5] = ' ';

		x[rH + 9][cH - 2] = '|';
		x[rH + 10][cH - 2] = '|';
		x[rH + 11][cH - 2] = '|';
		x[rH + 9][cH - 1] = ' ';
		x[rH + 10][cH - 1] = ' ';
		x[rH + 11][cH - 1] = ' ';
		x[rH + 12][cH - 2] = '|';
		x[rH + 12][cH - 1] = '_';
		x[rH + 12][cH] = '|';
		x[rH + 11][cH] = '|';
		x[rH + 10][cH] = '|';
		x[rH + 9][cH] = '|';

		x[rH + 9][cH + 3] = '|';
		x[rH + 10][cH + 3] = '|';
		x[rH + 10][cH + 2] = '_';
		x[rH + 10][cH + 1] = '|';
		x[rH + 9][cH + 1] = '|';


	}
	else
	{

		x[rH + 4][cH + 4] = '_';
		x[rH + 4][cH + 5] = '|';
		x[rH + 3][cH + 5] = '|';
		x[rH + 2][cH + 5] = '|';
		x[rH + 1][cH + 5] = '|';
		x[rH][cH + 6] = '_';
		x[rH + 1][cH + 7] = '|';
		x[rH + 2][cH + 7] = '|';
		x[rH + 3][cH + 7] = '|';
		x[rH + 4][cH + 7] = '|';
		x[rH + 5][cH + 7] = '|';
		x[rH + 5][cH + 6] = '_';
		x[rH + 5][cH + 5] = '_';

		x[rH + 1][cH + 6] = ' ';
		x[rH + 2][cH + 6] = ' ';
		x[rH + 3][cH + 6] = ' ';
		x[rH + 4][cH + 6] = ' ';

		x[rH + 4][cH - 3] = '_';
		x[rH + 4][cH - 4] = '|';
		x[rH + 3][cH - 4] = '|';
		x[rH + 2][cH - 4] = '|';
		x[rH + 1][cH - 4] = '|';
		x[rH][cH - 5] = '_';
		x[rH + 1][cH - 6] = '|';
		x[rH + 2][cH - 6] = '|';
		x[rH + 3][cH - 6] = '|';
		x[rH + 4][cH - 6] = '|';
		x[rH + 5][cH - 6] = '|';
		x[rH + 5][cH - 5] = '_';
		x[rH + 5][cH - 4] = '_';

		x[rH + 1][cH - 5] = ' ';
		x[rH + 2][cH - 5] = ' ';
		x[rH + 3][cH - 5] = ' ';
		x[rH + 4][cH - 5] = ' ';


		x[rH + 9][cH + 3] = '|';
		x[rH + 10][cH + 3] = '|';
		x[rH + 11][cH + 3] = '|';
		x[rH + 9][cH + 2] = ' ';
		x[rH + 10][cH + 2] = ' ';
		x[rH + 11][cH + 2] = ' ';
		x[rH + 12][cH + 3] = '|';
		x[rH + 12][cH + 2] = '_';
		x[rH + 12][cH + 1] = '|';
		x[rH + 11][cH + 1] = '|';
		x[rH + 10][cH + 1] = '|';
		x[rH + 9][cH + 1] = '|';

		x[rH + 9][cH - 2] = '|';
		x[rH + 10][cH - 2] = '|';
		x[rH + 10][cH - 1] = '_';
		x[rH + 10][cH] = '|';
		x[rH + 9][cH] = '|';


	}

	x[rH + 5][cH - 2] = ' ';
	x[rH + 5][cH - 1] = ' ';
	x[rH + 5][cH] = ' ';
	x[rH + 5][cH + 1] = ' ';
	x[rH + 5][cH + 2] = ' ';
	x[rH + 5][cH + 3] = ' ';
	x[rH + 5][cH + 4] = ' ';
	x[rH + 5][cH + 5] = ' ';

	x[rH + 6][cH - 2] = ' ';
	x[rH + 6][cH - 1] = ' ';
	x[rH + 6][cH] = ' ';
	x[rH + 6][cH + 1] = ' ';
	x[rH + 6][cH + 2] = ' ';
	x[rH + 6][cH + 3] = ' ';
	x[rH + 6][cH + 4] = ' ';
	x[rH + 6][cH + 5] = ' ';

	x[rH + 7][cH - 2] = ' ';
	x[rH + 7][cH - 1] = ' ';
	x[rH + 7][cH] = ' ';
	x[rH + 7][cH + 1] = ' ';
	x[rH + 7][cH + 2] = ' ';
	x[rH + 7][cH + 3] = ' ';
	x[rH + 7][cH + 4] = ' ';
	x[rH + 7][cH + 5] = ' ';

	x[rH + 8][cH - 2] = ' ';
	x[rH + 8][cH - 1] = ' ';
	x[rH + 8][cH] = ' ';
	x[rH + 8][cH + 1] = ' ';
	x[rH + 8][cH + 2] = ' ';
	x[rH + 8][cH + 3] = ' ';
	x[rH + 8][cH + 4] = ' ';
	x[rH + 8][cH + 5] = ' ';

	x[rH + 9][cH - 1] = ' ';
	//x[rH + 10][cH - 1] = ' ';

	x[rH + 9][cH + 2] = ' ';
	//x[rH + 10][cH + 2] = ' ';
	//x[rH + 11][cH + 2] = ' ';

	//x[rH + 5][cH - 3] = '_';
	//x[rH + 5][cH - 2] = '_';
	//x[rH + 6][cH - 2] = 179;
	x[rH + 7][cH - 2] = 179;
	x[rH + 8][cH - 2] = 179;

	x[rH + 5][cH + 5] = '_';
	x[rH + 5][cH + 4] = '_';
	//x[rH + 5][cH + 3] = '_';
	//x[rH + 6][cH + 3] = 179;
	x[rH + 7][cH + 3] = 179;
	x[rH + 8][cH + 3] = 179;

	x[rH + 5][cH + 4] = ' ';

}

void StaticHero5(char x[][2000], int &rH, int &cH, int countRLHL1, int& CountStart, int& LeftLook, int Reload, int ActionReload, int level, int rB, int cB)
{

	x[rH][cH - 1] = '_';
	x[rH][cH] = '_';
	x[rH][cH + 1] = '_';
	x[rH][cH + 2] = '_';

	if (LeftLook == 1)
	{

		x[rH + 2][cH] = ' ';
		x[rH + 2][cH + 2] = ' ';

		x[rH + 2][cH + 1] = '-';
		x[rH + 2][cH - 1] = '-';

	}
	else
	{
		x[rH + 2][cH] = '-';
		x[rH + 2][cH + 2] = '-';

		x[rH + 2][cH + 1] = ' ';
		x[rH + 2][cH - 1] = ' ';
	}

	x[rH + 1][cH - 2] = '/';
	x[rH + 1][cH + 3] = '\\';

	x[rH + 2][cH - 2] = '|';
	x[rH + 2][cH + 3] = '|';

	x[rH + 3][cH - 2] = '\\';
	x[rH + 3][cH + 3] = '/';

	x[rH + 3][cH - 1] = '_';
	x[rH + 3][cH] = '_';
	x[rH + 3][cH + 1] = 251;
	x[rH + 3][cH + 2] = '_';

	x[rH + 4][cH - 2] = '_';
	x[rH + 4][cH - 1] = '/';
	x[rH + 4][cH + 2] = '/';
	x[rH + 4][cH + 3] = '_';

	if (countRLHL1 == 0)
	{


		x[rH + 6][cH + 4] = '\\';	//RIGHT HAND
		x[rH + 6][cH + 5] = '_';
		x[rH + 6][cH + 6] = '_';
		x[rH + 6][cH + 7] = '/';
		x[rH + 5][cH + 8] = '_';
		x[rH + 4][cH + 7] = '_';
		x[rH + 5][cH + 5] = '\\';
		x[rH + 5][cH + 6] = '/';
		x[rH + 4][cH + 4] = '_';

		x[rH + 4][cH + 7] = '_';	//GUN
		x[rH + 4][cH + 8] = '_';
		x[rH + 4][cH + 9] = '_';
		x[rH + 4][cH + 10] = '_';
		x[rH + 4][cH + 11] = '_';
		x[rH + 4][cH + 12] = '_';
		x[rH + 5][cH + 13] = '|';
		x[rH + 5][cH + 12] = '_';
		x[rH + 5][cH + 11] = '_';
		x[rH + 5][cH + 10] = '_';
		x[rH + 6][cH + 9] = '/';
		x[rH + 6][cH + 8] = '_';

		x[rH + 6][cH + 12] = '2';



	}
	if (countRLHL1 % 2 != 0)
	{
		x[rH + 6][cH + 4] = '_';	//RIGHT HAND
		x[rH + 6][cH + 3] = ' ';
		x[rH + 5][cH + 3] = '/';
		x[rH + 6][cH + 5] = '_';
		x[rH + 6][cH + 7] = ' ';
		x[rH + 6][cH + 6] = ' ';//
		x[rH + 6][cH + 8] = ' ';
		x[rH + 4][cH + 7] = '_';
		x[rH + 5][cH + 5] = '_';
		x[rH + 5][cH + 6] = ' ';
		x[rH + 5][cH + 7] = ' ';
		x[rH + 4][cH + 4] = ' ';
		x[rH + 5][cH + 4] = '_';
		x[rH + 4][cH + 7] = ' ';

		x[rH + 5][cH + 6] = ' ';	//GUN
		x[rH + 6][cH + 6] = '/';
		x[rH + 5][cH + 7] = '_';
		x[rH + 5][cH + 8] = '_';
		x[rH + 5][cH + 9] = '_';
		x[rH + 5][cH + 10] = '_';
		x[rH + 5][cH + 11] = '_';
		x[rH + 6][cH + 12] = '|';
		x[rH + 6][cH + 11] = '_';
		x[rH + 6][cH + 10] = '_';
		x[rH + 6][cH + 9] = '_';
		x[rH + 7][cH + 8] = '/';
		x[rH + 7][cH + 7] = '_';
		x[rH + 6][cH + 7] = ' ';
		x[rH + 7][cH + 6] = '|';


		x[rH + 7][cH + 11] = '2';



	}
	else
	{
		x[rH + 6][cH + 4] = '\\';	//RIGHT HAND
		x[rH + 6][cH + 5] = '_';
		x[rH + 6][cH + 6] = '_';
		x[rH + 6][cH + 7] = '/';
		x[rH + 5][cH + 8] = '_';
		x[rH + 4][cH + 7] = '_';
		x[rH + 5][cH + 5] = '\\';
		x[rH + 5][cH + 6] = '/';
		x[rH + 4][cH + 4] = '_';

		x[rH + 4][cH + 7] = '_';	//GUN
		x[rH + 4][cH + 8] = '_';
		x[rH + 4][cH + 9] = '_';
		x[rH + 4][cH + 10] = '_';
		x[rH + 4][cH + 11] = '_';
		x[rH + 4][cH + 12] = '_';
		x[rH + 5][cH + 13] = '|';
		x[rH + 5][cH + 12] = '_';
		x[rH + 5][cH + 11] = '_';
		x[rH + 5][cH + 10] = '_';
		x[rH + 6][cH + 9] = '/';
		x[rH + 6][cH + 8] = '_';

		x[rH + 6][cH + 12] = '2';


	}

	//LeftHandMoveH1(x, rH, cH, countRLHL1, Reload, ActionReload, level, rB, cB,GunsTook);

	//x[rH + 5][cH + 3] = ' ';	   
	//x[rH + 6][cH + 3] = '|';	   
	x[rH + 7][cH + 3] = '|';

	//x[rH + 5][cH - 2] = ' ';
	//x[rH + 6][cH - 2] = ' ';
	x[rH + 7][cH - 2] = '|';

	x[rH + 7][cH - 1] = ' ';
	x[rH + 7][cH + 1] = ' ';
	x[rH + 7][cH + 2] = ' ';
	x[rH + 7][cH] = ' ';

	LeftLegMoveH1(x, rH, cH, countRLHL1);
	RightLegMoveH1(x, rH, cH, countRLHL1);
}

void StaticHeroFS(char x[][138], int &rH, int &cH, int counter, int timerFS)
{


	x[rH][cH - 1] = '_';
	x[rH][cH] = '_';
	x[rH][cH + 1] = '_';
	x[rH][cH + 2] = '_';



	//x[rH + 2][cH] = ' ';
	//x[rH + 2][cH + 2] = ' ';

	//x[rH + 2][cH + 1] = '-';
	//x[rH + 2][cH - 1] = '-';


	//x[rH + 2][cH] = '-';
	//x[rH + 2][cH + 2] = '-';

	//x[rH + 2][cH + 1] = ' ';
	//x[rH + 2][cH - 1] = ' ';


	x[rH + 1][cH - 2] = '/';
	x[rH + 1][cH + 3] = '\\';

	x[rH + 2][cH - 2] = '|';
	x[rH + 2][cH + 3] = '|';

	x[rH + 3][cH - 2] = '\\';
	x[rH + 3][cH + 3] = '/';

	x[rH + 3][cH - 1] = '_';
	x[rH + 3][cH] = '_';
	x[rH + 3][cH + 1] = '_';
	x[rH + 3][cH + 2] = '_';

	x[rH + 4][cH - 2] = '_';
	x[rH + 4][cH - 1] = 179;
	x[rH + 4][cH + 2] = 179;
	x[rH + 4][cH + 3] = '_';



	//x[rH + 5][cH + 3] = ' ';	   
	//x[rH + 6][cH + 3] = '|';	   
	x[rH + 7][cH + 3] = '|';
	x[rH + 8][cH + 3] = '|';


	//x[rH + 5][cH - 2] = ' ';
	//x[rH + 6][cH - 2] = ' ';
	x[rH + 7][cH - 2] = '|';
	x[rH + 8][cH - 2] = '|';


	x[rH + 8][cH - 1] = '_';
	x[rH + 8][cH + 1] = '_';
	x[rH + 8][cH + 2] = '_';
	x[rH + 8][cH] = '_';



	if (timerFS >= 0 && timerFS <= 15)
	{
		if (counter % 2 == 0)
		{

			x[rH + 4][cH + 4] = '_';
			x[rH + 5][cH + 5] = '|';
			x[rH + 6][cH + 5] = '|';
			x[rH + 7][cH + 5] = '|';
			x[rH + 8][cH + 5] = '|';
			x[rH + 8][cH + 4] = '_';

			x[rH + 3][cH - 3] = '|';
			x[rH + 2][cH - 4] = '_';
			x[rH + 3][cH - 5] = '|';
			x[rH + 4][cH - 5] = '|';
			x[rH + 5][cH - 5] = '|';
			x[rH + 6][cH - 4] = '\\';
			x[rH + 6][cH - 3] = '_';

			x[rH + 9][cH - 2] = '|';
			x[rH + 10][cH - 2] = '|';
			x[rH + 11][cH - 2] = '|';
			x[rH + 12][cH - 2] = '|';
			x[rH + 12][cH - 1] = '_';
			x[rH + 12][cH] = '|';
			x[rH + 11][cH] = '|';
			x[rH + 10][cH] = '|';
			x[rH + 9][cH] = '|';

			x[rH + 9][cH + 3] = '|';
			x[rH + 10][cH + 3] = '|';
			x[rH + 10][cH + 2] = ' ';
			x[rH + 10][cH + 1] = '|';
			x[rH + 9][cH + 1] = '|';
			rH--;

		}
		else
		{

			x[rH + 3][cH + 4] = '|';
			x[rH + 2][cH + 5] = '_';
			x[rH + 3][cH + 6] = '|';
			x[rH + 4][cH + 6] = '|';
			x[rH + 5][cH + 6] = '|';
			x[rH + 6][cH + 5] = '/';
			x[rH + 6][cH + 4] = '_';

			x[rH + 4][cH - 3] = '_';
			x[rH + 5][cH - 4] = '|';
			x[rH + 6][cH - 4] = '|';
			x[rH + 7][cH - 4] = '|';
			x[rH + 8][cH - 4] = '|';
			x[rH + 8][cH - 3] = '_';

			x[rH + 9][cH + 3] = '|';
			x[rH + 10][cH + 3] = '|';
			x[rH + 11][cH + 3] = '|';
			x[rH + 12][cH + 3] = '|';
			x[rH + 12][cH + 2] = '_';
			x[rH + 12][cH + 1] = '|';
			x[rH + 11][cH + 1] = '|';
			x[rH + 10][cH + 1] = '|';
			x[rH + 9][cH + 1] = '|';

			x[rH + 9][cH - 2] = '|';
			x[rH + 10][cH - 2] = '|';
			x[rH + 10][cH - 1] = ' ';
			x[rH + 10][cH] = '|';
			x[rH + 9][cH] = '|';
			rH--;

		}
	}
	else
	{
		x[rH + 4][cH + 4] = '_';
		x[rH + 5][cH + 5] = '|';
		x[rH + 6][cH + 5] = '|';
		x[rH + 7][cH + 5] = '|';
		x[rH + 8][cH + 5] = '|';
		x[rH + 8][cH + 4] = '_';

		x[rH + 4][cH - 3] = '_';
		x[rH + 5][cH - 4] = '|';
		x[rH + 6][cH - 4] = '|';
		x[rH + 7][cH - 4] = '|';
		x[rH + 8][cH - 4] = '|';
		x[rH + 8][cH - 3] = '_';

		x[rH + 9][cH + 3] = '|';
		x[rH + 10][cH + 3] = '|';
		x[rH + 11][cH + 3] = '|';
		x[rH + 12][cH + 3] = '|';
		x[rH + 12][cH + 2] = '_';
		x[rH + 12][cH + 1] = '|';
		x[rH + 11][cH + 1] = '|';
		x[rH + 10][cH + 1] = '|';
		x[rH + 9][cH + 1] = '|';

		x[rH + 9][cH - 2] = '|';
		x[rH + 10][cH - 2] = '|';
		x[rH + 11][cH - 2] = '|';
		x[rH + 12][cH - 2] = '|';
		x[rH + 12][cH - 1] = '_';
		x[rH + 12][cH] = '|';
		x[rH + 11][cH] = '|';
		x[rH + 10][cH] = '|';
		x[rH + 9][cH] = '|';

		x[rH + 2][cH + 1] = '-';
		x[rH + 2][cH - 1] = '-';
	}
}

void DynamicHero(char x[][2000], int& rH, int& cH, char keyB, int& countRLHL1, int& flag1, int& CounterUntilStop, int& pass1, int& pass2, int& lose1, int& ScrollCounter, int& GetOut, int& LeftLook, int& rEv, int& level, int& DeathT, int& shoot1, int& SkateIn, int& rSkate, int& cSkate, int& RopeIn, int& rR, int & cR, int& rMS1, int& cMS1, int& rMS2, int& cMS2, int& ClickShot, int& WhichShot, int& rB, int &cB, int &ct, int win, int& rEvR, int& cT6, int& cFC, int& TelephRide, int& ladder, int& AutoWalk, int& AutoWalkCounter, int& realwalk, int&letme, int& value, int& yeswalk, int& flagjumpchange, int& GunsTook, int rGS1[], int cGS1[], int rGS2[], int cGS2[], int& ordered, int& counterSH, int& f, int&laserstat, int&lasersecs, int& ElevON, int& AirTubeStat, int& AttachRope,int& laserdelay,int& orderedDiag,int& fDiag, int rGS1Diag[], int cGS1Diag[], int rGS2Diag[], int cGS2Diag[],int& counterSHDiag)
{
	if (keyB == 32)
	{

		if (level == 6 && TelephRide != 2 && TelephRide != 1 && (x[rH + 11][cH] != ' ' || rH == 36) && ElevON == 0 && AirTubeStat == 0 && AttachRope == 0)
		{
			for (int i = 0; i < 20; i++)
			{
				if (x[rH - 3][cH] == ' ' && x[rH - 3][cH - 1] == ' ' && x[rH - 3][cH - 2] == ' ' && x[rH - 3][cH + 1] == ' ' && x[rH - 3][cH + 2] == ' ' && x[rH - 3][cH + 3] == ' ')
				{
					rH--;
					countRLHL1 = 2;
					if (value <= 570 && value >= 530)
					{
						AttachRope = 1;
						flag1 = 0;
					}
				}

				else
				{
					break;
				}
			}

			flag1 = 1;

		}


	}


	if (keyB == 's' || keyB == 'S')
	{
		if ((GetOut == 0 || GetOut == 3) && rH < 36 && TelephRide == 0 || TelephRide == 3 && ElevON == 0 && AirTubeStat == 0)
		{
			countRLHL1 = 2;
			//cH -= 2;

			for (;;)
			{
				if (x[rH + 11][cH - 4] == ' ' && x[rH + 11][cH - 3] == ' ' && x[rH + 11][cH - 2] == ' ' && x[rH + 11][cH - 1] == ' ' && x[rH + 11][cH] == ' ' && x[rH + 11][cH + 1] == ' ' && x[rH + 11][cH + 2] == ' ' && x[rH + 11][cH + 3] == ' ' && x[rH + 11][cH + 4] == ' ')
				{
					rH++;
				}
				else
				{
					break;
				}
			}
			//rH--;

			flag1 = 0;
			RopeIn = 0;
		}

		if (level == 6 && rH <= 34 && ladder == 2 && TelephRide == 0)
		{
			rH++;
			countRLHL1++;
		}

	}


	if (keyB == 'a' || keyB == 'A')
	{
		AutoWalk = 0;
		AutoWalkCounter = 1;

		if (cH - 4 > value)
		{
			if (level == 6 && cT6 + value > 14 && TelephRide == 2)
			{
				cH -= 2;
				cT6 -= 2;
				LeftLook = 1;
				yeswalk = 1;
				if (cH - 4 >= 0)
				{
					value -= 2;
				}
			}

			else if (level == 6 && TelephRide == 0 && ladder == 0 && ElevON == 0 && AirTubeStat == 0)
			{
				cH -= 3;
				LeftLook = 1;
				countRLHL1 = 2;
				yeswalk = 1;
				if (cH - 4 >= 0)
				{
					value -= 2;
				}
			}

			else if (level == 6 && TelephRide == 3 && ElevON == 0 && AirTubeStat == 0)
			{
				for (int a = 0; a < 2; a++)
				{
					cH--;
					if (x[rH + 10][cH - 5] == '\\' || x[rH + 10][cH - 6] == '\\' || x[rH + 10][cH - 7] == '\\' || x[rH + 10][cH - 4] == '\\' || x[rH + 11][cH - 3] == '\\')
					{
						rH -= 2;
					}
				}

				LeftLook = 1;
				countRLHL1 = 2;
				yeswalk = 1;
				if (cH - 4 > 0)
				{
					value -= 2;
				}

			}
			else
			{
				yeswalk = 0;
			}

		}
		if ((cH - 1) < value)
		{
			lose1 = 1;
			DeathT = 0;
		}

	}


	if (keyB == 'd' || keyB == 'D')
	{
		AutoWalk = 0;
		AutoWalkCounter = 1;

		if (level == 6 && TelephRide == 2 && ladder == 0)
		{
			LeftLook = 0;
			cH += 2;
			cT6 += 2;
			value += 2;
			yeswalk = 1;
			if (value >= 82)
			{
				TelephRide = 3;
				cH = 4 + value;
				rH = 30;
				countRLHL1 = 2;

			}
		}

		else if (level == 6 && TelephRide == 0 && ladder == 0 && x[rH][cH + 9] == ' '&& ElevON == 0 && AirTubeStat == 0)
		{

			countRLHL1++;
			LeftLook = 0;
			value += 2;
			cH += 2;
			yeswalk = 1;
			if (letme == 0 && cH <= value + 9)
			{
				cH++;
			}

			if (realwalk % 24 == 0)
			{
				letme = 1;
			}

			if (letme == 1)
			{
				cH--;
				if (cH <= value + 4)
				{

					letme = 0;
				}
			}
		}

		else if (level == 6 && x[rH][cH + 9] == ' ' && TelephRide == 3 && ElevON == 0 && AirTubeStat == 0)
		{
			countRLHL1++;
			LeftLook = 0;
			value += 2;
			for (int a = 0; a < 2; a++)
			{

				if (x[rH + 10][cH + 5] == '/' || x[rH + 10][cH + 3] == '/' || x[rH + 11][cH + 5] == '/' || x[rH + 11][cH + 3] == '/')
				{
					rH -= 2;
				}

				cH++;
			}
			yeswalk = 1;
			if (letme == 0 && cH <= value + 9)
			{

				if (x[rH + 10][cH + 5] == '/' || x[rH + 10][cH + 3] == '/' || x[rH + 11][cH + 5] == '/' || x[rH + 11][cH + 3] == '/')
				{
					rH -= 2;
				}
				if (cH + 6 >= 100)
				{
					GunsTook = 1;
				}
				cH++;

			}

			if (realwalk % 24 == 0)
			{
				letme = 1;
			}

			if (letme == 1)
			{

				cH--;
				if (x[rH + 10][cH + 5] == '/' || x[rH + 10][cH + 3] == '/' || x[rH + 11][cH + 5] == '/' || x[rH + 11][cH + 3] == '/')
				{
					rH -= 2;
				}

				if (cH <= value + 4)
				{

					letme = 0;
				}
			}


		}

		else
		{
			yeswalk = 0;
		}


	}


	if ((keyB == 'e' || keyB == 'E') && level == 6)
	{
		if (x[rH][cH + 9] != ' ' && ladder == 0)
		{
			ladder = 1;
		}
		if (rH == 30)
		{
			ladder = 0;
			TelephRide = 1;
		}
	}


	if (keyB == 43 && level == 5 && ClickShot <= 2)
	{
		ClickShot++;
		WhichShot = 1;

		if (ClickShot == 1)
		{
			rMS1 = rH;
			cMS1 = cH;
		}

		if (ClickShot == 2)
		{
			rMS2 = rH;
			cMS2 = cH;
			rB = rH + 6;
			cB = cH + 7;
			ct = 0;
		}

		if (ClickShot > 2)
		{
			ClickShot = 2;
		}


	}


	if (keyB == 43 && GunsTook == 1 && ladder == 0 && (TelephRide == 0 || TelephRide == 3) && ElevON == 0 && AirTubeStat == 0)
	{

		rGS1[f] = rH + 5;
		cGS1[f] = cH + 14;

		rGS2[f] = rH + 6;
		cGS2[f] = cH + 6;

		ordered = 1;
		//orderedDiag = 0;
		counterSH++;
		f++;
	}

	if (keyB == '-' && GunsTook == 1 && ladder == 0 && (TelephRide == 0 || TelephRide == 3) && ElevON == 0 && AirTubeStat == 0)
	{

		rGS1Diag[fDiag] = rH + 5;
		cGS1Diag[fDiag] = cH + 14;

		rGS2Diag[fDiag] = rH + 6;
		cGS2Diag[fDiag] = cH + 6;

		orderedDiag = 1;
		//ordered = 0;
		counterSHDiag++;
		fDiag++;
		//fDiagR--;
	}

	if ((keyB == 'w' || keyB == 'W') && level == 6 && ladder == 2 && TelephRide == 0 && rH > 30)
	{
		countRLHL1++;
		rH--;
	}


	if ((keyB == 8) && CounterUntilStop > 14)
	{
		AutoWalkCounter++;
		LeftLook = 0;
		if (AutoWalkCounter % 2 == 0)
		{
			AutoWalk = 1;
		}
		else
		{
			AutoWalk = 0;
		}

	}


	if (keyB == 'l' || keyB == 'L')
	{
		if (laserstat == 0 && lasersecs == 0 && ladder == 0 && (TelephRide == 0 || TelephRide == 3) && LeftLook == 0 && ElevON == 0 && AirTubeStat == 0 && AttachRope == 0 && value <= 700)
		{
			laserstat = 1;
			laserdelay = 0;
		}
		if (value >= 700)
		{
			laserstat = 2;
			laserdelay = 0;
		}
	}
}

void LandCheck(char x[][2000], int& rH, int& cH, int& flag1, int GetOut, int level, int SkateIn, int& rSkate, int& cSkate, int RopeIn, int cR, int tap4)
{
	if (x[rH + 11][cH - 4] == ' ' && x[rH + 11][cH - 3] == ' ' && x[rH + 11][cH - 2] == ' ' && x[rH + 11][cH - 1] == ' ' && x[rH + 11][cH] == ' ' && x[rH + 11][cH + 1] == ' ' && x[rH + 11][cH + 2] == ' ' && x[rH + 11][cH + 3] == ' ' && x[rH + 11][cH + 4] == ' ' && x[rH + 8][cH + 4] == ' ' && x[rH + 8][cH + 5] == ' ' && x[rH + 8][cH + 6] == ' ' && x[rH + 8][cH + 7] == ' ' && (x[rH + 11][cH] == ' ' || x[rH + 11][cH] == '='))
	{
		rH++;
		if (rH < 32)
		{
			x[rH - 3][cH + 4] = 'T';
			x[rH - 3][cH + 5] = 'a';
			x[rH - 3][cH + 6] = 'p';
			x[rH - 3][cH + 7] = ' ';
			x[rH - 3][cH + 8] = 39;
			x[rH - 3][cH + 9] = 's';
			x[rH - 3][cH + 10] = 39;
			x[rH - 3][cH + 11] = ' ';
			x[rH - 3][cH + 12] = 't';
			x[rH - 3][cH + 13] = 'o';
			x[rH - 3][cH + 14] = ' ';
			x[rH - 3][cH + 15] = 'f';
			x[rH - 3][cH + 16] = 'a';
			x[rH - 3][cH + 17] = 's';
			x[rH - 3][cH + 18] = 't';
			x[rH - 3][cH + 19] = ' ';
			x[rH - 3][cH + 20] = 'l';
			x[rH - 3][cH + 21] = 'a';
			x[rH - 3][cH + 22] = 'n';
			x[rH - 3][cH + 23] = 'd';

		}



		else
		{

			//flag1 = 0;
		}

	}
}

void AutoForward(char x[][2000], int& rH, int& cH, int& countRLHL1, int& flag1, int& CounterUntilStop, int& pass1, int& pass2, int& lose1, int& ScrollCounter, int& GetOut, int& LeftLook, int& rEv, int& level, int& DeathT, int& shoot1, int& SkateIn, int& rSkate, int& cSkate, int& RopeIn, int& rR, int & cR, int& rMS1, int& cMS1, int& rMS2, int& cMS2, int& ClickShot, int& WhichShot, int& rB, int &cB, int &ct, int win, int& rEvR, int& cT6, int& cFC, int& TelephRide, int& ladder, int Reload, int ActionReload, int& AutoWalk, int&realwalk, int&letme, int& value, int& GunsTook, int& AutoWalkCounter, int& ElevON, int& AirTubeStat, int& yeswalk)
{
	if (AutoWalk == 1)
	{
		LeftHandMoveH1(x, rH, cH, countRLHL1, Reload, ActionReload, level, rB, cB, GunsTook);
		RightHandMoveH1(x, rH, cH, countRLHL1, GunsTook);
		RightLegMoveH1(x, rH, cH, countRLHL1);
		LeftLegMoveH1(x, rH, cH, countRLHL1);


		AutoWalk = 0;
		AutoWalkCounter = 1;

		if (level == 6 && TelephRide == 2 && ladder == 0)
		{
			LeftLook = 0;
			cH += 2;
			cT6 += 2;
			value += 2;
			yeswalk = 1;
			if (value >= 82)
			{
				TelephRide = 3;
				cH = 4 + value;
				rH = 30;
				countRLHL1 = 2;

			}
		}

		else if (level == 6 && TelephRide == 0 && ladder == 0 && x[rH][cH + 9] == ' '&& ElevON == 0 && AirTubeStat == 0)
		{

			countRLHL1++;
			LeftLook = 0;
			value += 2;
			cH += 2;
			yeswalk = 1;
			if (letme == 0 && cH <= value + 9)
			{
				cH++;
			}

			if (realwalk % 24 == 0)
			{
				letme = 1;
			}

			if (letme == 1)
			{
				cH--;
				if (cH <= value + 4)
				{

					letme = 0;
				}
			}
		}

		else if (level == 6 && x[rH][cH + 9] == ' ' && TelephRide == 3 && ElevON == 0 && AirTubeStat == 0)
		{
			countRLHL1++;
			LeftLook = 0;
			value += 2;
			for (int a = 0; a < 2; a++)
			{

				if (x[rH + 10][cH + 5] == '/' || x[rH + 10][cH + 3] == '/' || x[rH + 11][cH + 5] == '/' || x[rH + 11][cH + 3] == '/')
				{
					rH -= 2;
				}

				cH++;
			}
			yeswalk = 1;
			if (letme == 0 && cH <= value + 9)
			{

				if (x[rH + 10][cH + 5] == '/' || x[rH + 10][cH + 3] == '/' || x[rH + 11][cH + 5] == '/' || x[rH + 11][cH + 3] == '/')
				{
					rH -= 2;
				}
				if (cH + 6 >= 100)
				{
					GunsTook = 1;
				}
				cH++;

			}

			if (realwalk % 24 == 0)
			{
				letme = 1;
			}

			if (letme == 1)
			{

				cH--;
				if (x[rH + 10][cH + 5] == '/' || x[rH + 10][cH + 3] == '/' || x[rH + 11][cH + 5] == '/' || x[rH + 11][cH + 3] == '/')
				{
					rH -= 2;
				}

				if (cH <= value + 4)
				{

					letme = 0;
				}
			}


		}

		else
		{
			yeswalk = 0;
		}
	}
}

void Constructor(char x[][2000], int rH, int cH, int &ConstructorCount, int timer, int CounterUntilStop, int rGuide, int cGuide, int& cC, int level, int GetOut, int timer2, int timer3, int BSc, int flagScore1, int flagScore2, int flagScore3, int timer4, int flagTime1, int flagTime2, int flagTime3, int TSc, int mins, int flagScore4, int flagTime4, int timer5, int win, int timerBSC, int rFC, int cFC, int TelephRide, int tryagain, int value, int& lasersecs, int laserstat, int ElevON, int AirTubeStat)
{


	char TA[2];
	_itoa_s(tryagain, TA, 10);

	char LAS[3];
	_itoa_s(lasersecs, LAS, 10);


	if (level == 6)
	{
		x[0][36 + value] = 'C';
		x[0][37 + value] = 'h';
		x[0][38 + value] = 'a';
		x[0][39 + value] = 'n';
		x[0][40 + value] = 'c';
		x[0][41 + value] = 'e';
		x[0][42 + value] = 's';
		x[0][43 + value] = ' ';
		x[0][44 + value] = 'l';
		x[0][45 + value] = 'e';
		x[0][46 + value] = 'f';
		x[0][47 + value] = 't';
		x[0][48 + value] = ' ';
		x[0][49 + value] = TA[0];
		x[0][50 + value] = ' ';
		x[0][51 + value] = '|';
		x[0][52 + value] = ' ';

		if (lasersecs > 9)
		{
			x[20][115 + value] = 'A';
			x[20][116 + value] = 'c';
			x[20][117 + value] = 't';
			x[20][118 + value] = 'i';
			x[20][119 + value] = 'v';
			x[20][120 + value] = 'a';
			x[20][121 + value] = 't';
			x[20][122 + value] = 'e';
			x[20][123 + value] = ' ';
			x[20][124 + value] = 'L';
			x[20][125 + value] = 'a';
			x[20][126 + value] = 's';
			x[20][127 + value] = 'e';
			x[20][128 + value] = 'r';
			x[20][129 + value] = ' ';
			x[20][130 + value] = 'i';
			x[20][131 + value] = 'n';
			x[20][132 + value] = ' ';
			x[20][133 + value] = LAS[0];
			x[20][134 + value] = LAS[1];
			x[20][135 + value] = 's';
		}
		if (lasersecs <= 9)
		{
			x[20][115 + value] = 'A';
			x[20][116 + value] = 'c';
			x[20][117 + value] = 't';
			x[20][118 + value] = 'i';
			x[20][119 + value] = 'v';
			x[20][120 + value] = 'a';
			x[20][121 + value] = 't';
			x[20][122 + value] = 'e';
			x[20][123 + value] = ' ';
			x[20][124 + value] = 'L';
			x[20][125 + value] = 'a';
			x[20][126 + value] = 's';
			x[20][127 + value] = 'e';
			x[20][128 + value] = 'r';
			x[20][129 + value] = ' ';
			x[20][130 + value] = 'i';
			x[20][131 + value] = 'n';
			x[20][132 + value] = ' ';
			x[20][133 + value] = LAS[0];
			x[20][134 + value] = 's';
		}
	}
	if (laserstat == 0 && lasersecs >= 1 && ElevON == 0 && AirTubeStat == 0)
	{
		lasersecs--;
	}
	if ((laserstat == 1 || laserstat == 2) && lasersecs == 0)
	{
		lasersecs = 99;
		laserstat = 0;
	}


	char COL[6];
	_itoa_s(value, COL, 10);
	x[20][0 + value] = COL[0];
	x[20][1 + value] = COL[1];
	x[20][2 + value] = COL[2];
	x[20][3 + value] = COL[3];

}

void AutoBackward(char x[][138], int& rH, int& cH, int& lose1, int& pass1, int& pass2, int& cF, int& LeftLook, int CounterUntilStop, int& cO1, int& cC, int& rO1, int& DeathT, int& countRLHL1, int level)
{
	if (cH - 4 < -4)
	{
		DeathT = 0;
		lose1 = 1;
	}
	else
		if (CounterUntilStop >= 14 && level == 1)
		{
			if (rH == 36)
			{

				if (x[rH + 10][cH - 5] == ' ' || cH - 4 <= 0)
				{
					cH--;
					LeftLook = 1;
				}

			}

		}

	if (level == 2)
	{
		if (rH == 36)
		{


			cH--;
			LeftLook = 1;


		}

	}

	cF++;

}

void ToLand(char x[][2000], int rH, int cH, int& flag1, int GetOut, int LeftLook, int level, int rEv, int SkateIn, int& rSkate, int& cSkate, int RopeIn, int cR, int tap4)
{

	if (x[rH + 11][cH - 4] == ' ' && x[rH + 11][cH - 3] == ' ' && x[rH + 11][cH - 2] == ' ' && x[rH + 11][cH - 1] == ' ' && x[rH + 11][cH] == ' ' && x[rH + 11][cH + 1] == ' ' && x[rH + 11][cH + 2] == ' ' && x[rH + 11][cH + 3] == ' ' && x[rH + 11][cH + 4] == ' ')
	{

		JumpReaction(x, rH, cH, flag1, GetOut, LeftLook, level, SkateIn, rSkate, cSkate, RopeIn, cR, tap4);
		//LandCheck(x, rH, cH, flag1, GetOut);
	}

	else
	{

		flag1 = 0;
	}


}

void JumpReaction(char x[][2000], int& rH, int& cH, int& flag1, int GetOut, int& LeftLook, int level, int SkateIn, int& rSkate, int& cSkate, int RopeIn, int cR, int tap4)
{



	if (rH < 36)
	{
		//sleep_for(nanoseconds(9900000));
		//dsleep_until(system_clock::now() + seconds(1));
		//cH += 1;
		LandCheck(x, rH, cH, flag1, GetOut, level, SkateIn, rSkate, cSkate, RopeIn, cR, tap4);



	}



}

void LeftHandMoveH1(char x[][2000], int rH, int cH, int countRLHL1, int Reload, int& ReloadAction, int level, int& rB, int cB, int GunsTook)
{
	if (GunsTook == 0)
	{
		if (countRLHL1 == 0)
		{
			x[rH + 5][cH - 3] = '/';			//LEFT HAND 
			x[rH + 6][cH - 4] = '\\';
			x[rH + 5][cH - 4] = '_';
			x[rH + 5][cH - 2] = '_';
			x[rH + 6][cH - 3] = '_';
			x[rH + 6][cH - 1] = '_';
			x[rH + 6][cH - 2] = '_';
			x[rH + 6][cH] = '|';
			x[rH + 5][cH - 1] = '_';

			if (Reload == 1 && ReloadAction == 2 && level == 5)
			{
				x[rH + 5][cH - 3] = ' ';			//LEFT HAND 
				x[rH + 6][cH - 2] = ' ';
				x[rH + 5][cH - 7] = ' ';
				x[rH + 6][cH - 5] = ' ';
				x[rH + 7][cH - 6] = ' ';
				x[rH + 7][cH - 5] = ' ';
				//x[rH + 6][cH - 3] = '/';
				x[rH + 7][cH - 4] = ' ';
				x[rH + 6][cH - 3] = ' ';
				x[rH + 5][cH - 4] = ' ';
				x[rH + 4][cH - 3] = ' ';

				x[rH + 6][cH] = ' ';
				x[rH + 6][cH - 1] = ' ';
				x[rH + 6][cH - 2] = ' ';
				x[rH + 5][cH - 1] = ' ';
				x[rH + 6][cH - 4] = ' ';
				x[rH + 6][cH - 3] = ' ';
				x[rH + 5][cH - 3] = ' ';

				x[rH + 8][cH - 6] = ' ';
				x[rH + 8][cH - 5] = ' ';
				x[rH + 8][cH - 4] = ' ';
				x[rH + 9][cH - 6] = ' ';
				x[rH + 9][cH - 4] = ' ';
				x[rH + 9][cH - 5] = ' ';


				x[rH + 5][cH - 3] = ' ';			//LEFT HAND 
				x[rH + 6][cH - 4] = ' ';
				x[rH + 5][cH - 4] = ' ';
				x[rH + 5][cH - 2] = ' ';
				x[rH + 6][cH - 3] = ' ';
				x[rH + 6][cH - 1] = ' ';
				x[rH + 6][cH - 2] = ' ';
				x[rH + 6][cH] = ' ';
				x[rH + 5][cH - 1] = ' ';


				x[rH + 5][cH] = '_';			//LEFT HAND 
				x[rH + 6][cH] = '_';
				x[rH + 6][cH - 1] = '_';
				x[rH + 6][cH + 1] = '_';
				x[rH + 6][cH - 2] = ' ';
				x[rH + 6][cH - 3] = ' ';
				x[rH + 7][cH + 1] = '_';
				x[rH + 6][cH + 2] = '|';
				x[rH + 5][cH - 1] = '_';
				x[rH + 5][cH - 2] = '\\';
				x[rH + 5][cH - 3] = ' ';
				x[rH + 5][cH + 1] = '_';

				x[rH + 5][cH + 2] = ' ';
				x[rH + 5][cH + 3] = '_';
				x[rH + 5][cH + 4] = '_';
				x[rH + 5][cH + 5] = '_';
				x[rH + 6][cH + 6] = '|';
				x[rH + 6][cH + 5] = '2';
				x[rH + 6][cH + 4] = '_';
				x[rH + 6][cH + 3] = '_';



			}

			if (Reload == 1 && ReloadAction == 1 && level == 5)
			{
				x[rH + 5][cH - 3] = '/';			//LEFT HAND 
				x[rH + 6][cH - 2] = '|';
				x[rH + 5][cH - 7] = ' ';
				x[rH + 6][cH - 5] = '/';
				x[rH + 7][cH - 6] = '/';
				x[rH + 7][cH - 5] = '_';
				//x[rH + 6][cH - 3] = '/';
				x[rH + 7][cH - 4] = '/';
				x[rH + 6][cH - 3] = '/';
				x[rH + 5][cH - 4] = '/';
				x[rH + 4][cH - 3] = '_';

				x[rH + 6][cH] = ' ';
				x[rH + 6][cH - 1] = ' ';
				x[rH + 6][cH - 2] = ' ';
				x[rH + 5][cH - 1] = ' ';
				x[rH + 6][cH - 4] = ' ';
				x[rH + 6][cH - 3] = '/';
				x[rH + 5][cH - 3] = ' ';

				x[rH + 8][cH - 6] = '|';
				x[rH + 8][cH - 5] = '2';
				x[rH + 8][cH - 4] = '|';
				x[rH + 9][cH - 6] = '|';
				x[rH + 9][cH - 4] = '|';
				x[rH + 9][cH - 5] = '_';




				x[rB + 1][cB] = '_';
				x[rB + 2][cB] = '0';
				x[rB + 2][cB - 1] = '|';
				x[rB + 2][cB + 1] = '|';
				x[rB + 3][cB - 1] = '|';
				x[rB + 3][cB + 1] = '|';
				x[rB + 3][cB] = '_';


			}
		}
		if (countRLHL1 % 2 != 0)
		{

			x[rH + 5][cH - 3] = ' ';			//LEFT HAND 
			x[rH + 6][cH - 4] = ' ';
			x[rH + 5][cH - 4] = ' ';
			x[rH + 5][cH - 2] = ' ';
			x[rH + 6][cH - 3] = ' ';
			x[rH + 6][cH - 1] = ' ';
			x[rH + 6][cH - 2] = ' ';
			x[rH + 6][cH] = ' ';
			x[rH + 5][cH - 1] = ' ';


			x[rH + 5][cH] = '_';			//LEFT HAND 
			x[rH + 6][cH] = '_';
			x[rH + 6][cH - 1] = '_';
			x[rH + 6][cH + 1] = '_';
			x[rH + 6][cH - 2] = '_';
			x[rH + 6][cH - 3] = '\\';
			//x[rH + 7][cH + 1] = '_';
			x[rH + 6][cH + 2] = '|';
			x[rH + 5][cH - 1] = '_';
			x[rH + 5][cH - 2] = '\\';
			x[rH + 5][cH - 3] = ' ';
			x[rH + 5][cH + 1] = '_';

			if (Reload == 1 && ReloadAction == 2 && level == 5)
			{
				x[rH + 5][cH - 3] = ' ';			//LEFT HAND 
				x[rH + 6][cH - 2] = ' ';
				x[rH + 5][cH - 7] = ' ';
				x[rH + 6][cH - 5] = ' ';
				x[rH + 7][cH - 6] = ' ';
				x[rH + 7][cH - 5] = ' ';
				//x[rH + 6][cH - 3] = '/';
				x[rH + 7][cH - 4] = ' ';
				x[rH + 6][cH - 3] = ' ';
				x[rH + 5][cH - 4] = ' ';
				x[rH + 4][cH - 3] = ' ';

				x[rH + 6][cH] = ' ';
				x[rH + 6][cH - 1] = ' ';
				x[rH + 6][cH - 2] = ' ';
				x[rH + 5][cH - 1] = ' ';
				x[rH + 6][cH - 4] = ' ';
				x[rH + 6][cH - 3] = ' ';
				x[rH + 5][cH - 3] = ' ';

				x[rH + 8][cH - 6] = ' ';
				x[rH + 8][cH - 5] = ' ';
				x[rH + 8][cH - 4] = ' ';
				x[rH + 9][cH - 6] = ' ';
				x[rH + 9][cH - 4] = ' ';
				x[rH + 9][cH - 5] = ' ';


				x[rH + 5][cH - 3] = ' ';			//LEFT HAND 
				x[rH + 6][cH - 4] = ' ';
				x[rH + 5][cH - 4] = ' ';
				x[rH + 5][cH - 2] = ' ';
				x[rH + 6][cH - 3] = ' ';
				x[rH + 6][cH - 1] = ' ';
				x[rH + 6][cH - 2] = ' ';
				x[rH + 6][cH] = ' ';
				x[rH + 5][cH - 1] = ' ';


				x[rH + 5][cH] = '_';			//LEFT HAND 
				x[rH + 6][cH] = '_';
				x[rH + 6][cH - 1] = '_';
				x[rH + 6][cH + 1] = '_';
				x[rH + 6][cH - 2] = ' ';
				x[rH + 6][cH - 3] = ' ';
				x[rH + 7][cH + 1] = '_';
				x[rH + 6][cH + 2] = '|';
				x[rH + 5][cH - 1] = '_';
				x[rH + 5][cH - 2] = '\\';
				x[rH + 5][cH - 3] = ' ';
				x[rH + 5][cH + 1] = '_';

				x[rH + 5][cH + 2] = ' ';
				x[rH + 5][cH + 3] = '_';
				x[rH + 5][cH + 4] = '_';
				x[rH + 5][cH + 5] = '_';
				x[rH + 6][cH + 6] = '|';
				x[rH + 6][cH + 5] = '2';
				x[rH + 6][cH + 4] = '_';
				x[rH + 6][cH + 3] = '_';

			}

			if (Reload == 1 && ReloadAction == 1 && level == 5)
			{
				x[rH + 5][cH - 3] = '/';			//LEFT HAND 
				x[rH + 6][cH - 2] = '|';
				x[rH + 5][cH - 7] = ' ';
				x[rH + 6][cH - 5] = '/';
				x[rH + 7][cH - 6] = '/';
				x[rH + 7][cH - 5] = '_';
				//x[rH + 6][cH - 3] = '/';
				x[rH + 7][cH - 4] = '/';
				x[rH + 6][cH - 3] = '/';
				x[rH + 5][cH - 4] = '/';
				x[rH + 4][cH - 3] = '_';

				x[rH + 6][cH] = ' ';
				x[rH + 6][cH - 1] = ' ';
				x[rH + 6][cH - 2] = ' ';
				x[rH + 5][cH - 1] = ' ';
				x[rH + 6][cH - 4] = ' ';
				x[rH + 6][cH - 3] = '/';
				x[rH + 5][cH - 3] = ' ';

				x[rH + 8][cH - 6] = '|';
				x[rH + 8][cH - 5] = '2';
				x[rH + 8][cH - 4] = '|';
				x[rH + 9][cH - 6] = '|';
				x[rH + 9][cH - 4] = '|';
				x[rH + 9][cH - 5] = '_';




				x[rB + 1][cB] = '_';
				x[rB + 2][cB] = '0';
				x[rB + 2][cB - 1] = '|';
				x[rB + 2][cB + 1] = '|';
				x[rB + 3][cB - 1] = '|';
				x[rB + 3][cB + 1] = '|';
				x[rB + 3][cB] = '_';


			}


		}
		else
		{
			x[rH + 5][cH - 3] = '/';			//LEFT HAND 
			x[rH + 6][cH - 4] = '\\';
			x[rH + 5][cH - 4] = '_';
			x[rH + 5][cH - 2] = '_';
			x[rH + 6][cH - 3] = '_';
			x[rH + 6][cH - 1] = '_';
			x[rH + 6][cH - 2] = '_';
			x[rH + 6][cH] = '|';
			x[rH + 5][cH - 1] = '_';


			if (Reload == 1 && ReloadAction == 2 && level == 5)
			{
				x[rH + 5][cH - 3] = ' ';			//LEFT HAND 
				x[rH + 6][cH - 2] = ' ';
				x[rH + 5][cH - 7] = ' ';
				x[rH + 6][cH - 5] = ' ';
				x[rH + 7][cH - 6] = ' ';
				x[rH + 7][cH - 5] = ' ';
				//x[rH + 6][cH - 3] = '/';
				x[rH + 7][cH - 4] = ' ';
				x[rH + 6][cH - 3] = ' ';
				x[rH + 5][cH - 4] = ' ';
				x[rH + 4][cH - 3] = ' ';

				x[rH + 6][cH] = ' ';
				x[rH + 6][cH - 1] = ' ';
				x[rH + 6][cH - 2] = ' ';
				x[rH + 5][cH - 1] = ' ';
				x[rH + 6][cH - 4] = ' ';
				x[rH + 6][cH - 3] = ' ';
				x[rH + 5][cH - 3] = ' ';

				x[rH + 8][cH - 6] = ' ';
				x[rH + 8][cH - 5] = ' ';
				x[rH + 8][cH - 4] = ' ';
				x[rH + 9][cH - 6] = ' ';
				x[rH + 9][cH - 4] = ' ';
				x[rH + 9][cH - 5] = ' ';


				x[rH + 5][cH - 3] = ' ';			//LEFT HAND 
				x[rH + 6][cH - 4] = ' ';
				x[rH + 5][cH - 4] = ' ';
				x[rH + 5][cH - 2] = ' ';
				x[rH + 6][cH - 3] = ' ';
				x[rH + 6][cH - 1] = ' ';
				x[rH + 6][cH - 2] = ' ';
				x[rH + 6][cH] = ' ';
				x[rH + 5][cH - 1] = ' ';


				x[rH + 5][cH] = '_';			//LEFT HAND 
				x[rH + 6][cH] = '_';
				x[rH + 6][cH - 1] = '_';
				x[rH + 6][cH + 1] = '_';
				x[rH + 6][cH - 2] = ' ';
				x[rH + 6][cH - 3] = ' ';
				x[rH + 7][cH + 1] = '_';
				x[rH + 6][cH + 2] = '|';
				x[rH + 5][cH - 1] = '_';
				x[rH + 5][cH - 2] = '\\';
				x[rH + 5][cH - 3] = ' ';
				x[rH + 5][cH + 1] = '_';

				x[rH + 5][cH + 2] = ' ';
				x[rH + 5][cH + 3] = '_';
				x[rH + 5][cH + 4] = '_';
				x[rH + 5][cH + 5] = '_';
				x[rH + 6][cH + 6] = '|';
				x[rH + 6][cH + 5] = '2';
				x[rH + 6][cH + 4] = '_';
				x[rH + 6][cH + 3] = '_';


			}

			if (Reload == 1 && ReloadAction == 1 && level == 5)
			{
				x[rH + 5][cH - 3] = '/';			//LEFT HAND 
				x[rH + 6][cH - 2] = '|';
				x[rH + 5][cH - 7] = ' ';
				x[rH + 6][cH - 5] = '/';
				x[rH + 7][cH - 6] = '/';
				x[rH + 7][cH - 5] = '_';
				//x[rH + 6][cH - 3] = '/';
				x[rH + 7][cH - 4] = '/';
				x[rH + 6][cH - 3] = '/';
				x[rH + 5][cH - 4] = '/';
				x[rH + 5][cH - 2] = ' ';
				x[rH + 6][cH - 2] = '|';
				x[rH + 4][cH - 3] = '_';

				x[rH + 6][cH] = ' ';
				x[rH + 6][cH - 1] = ' ';
				x[rH + 6][cH - 2] = ' ';
				x[rH + 5][cH - 1] = ' ';
				x[rH + 6][cH - 4] = ' ';
				x[rH + 6][cH - 3] = '/';
				x[rH + 5][cH - 3] = ' ';

				x[rH + 8][cH - 6] = '|';
				x[rH + 8][cH - 5] = '2';
				x[rH + 8][cH - 4] = '|';
				x[rH + 9][cH - 6] = '|';
				x[rH + 9][cH - 4] = '|';
				x[rH + 9][cH - 5] = '_';




				x[rB + 1][cB] = '_';
				x[rB + 2][cB] = '0';
				x[rB + 2][cB - 1] = '|';
				x[rB + 2][cB + 1] = '|';
				x[rB + 3][cB - 1] = '|';
				x[rB + 3][cB + 1] = '|';

				x[rB + 3][cB] = '_';


			}


		}
	}

	if (GunsTook == 1)
	{
		x[rH + 5][cH - 3] = '/';			//LEFT HAND 
		x[rH + 6][cH - 4] = '\\';
		x[rH + 5][cH - 4] = '_';
		x[rH + 5][cH - 2] = '_';
		x[rH + 6][cH - 3] = '_';
		x[rH + 6][cH - 1] = '_';
		x[rH + 6][cH - 2] = '_';
		x[rH + 6][cH] = '|';
		x[rH + 5][cH - 1] = '_';

		x[rH + 4 + 1][cH - 7 + 7] = ' ';	//GUN
		x[rH + 4 + 1][cH - 7 + 8] = '_';
		x[rH + 4 + 1][cH - 7 + 9] = '_';
		x[rH + 4 + 1][cH - 7 + 10] = '_';
		x[rH + 4 + 1][cH - 7 + 11] = '_';
		x[rH + 4 + 1][cH - 7 + 12] = '_';
		x[rH + 5 + 1][cH - 7 + 13] = '|';
		x[rH + 5 + 1][cH - 7 + 12] = '_';
		x[rH + 5 + 1][cH - 7 + 11] = '_';
		x[rH + 5 + 1][cH - 7 + 10] = '_';
		x[rH + 6 + 1][cH - 7 + 9] = '/';
		x[rH + 6 + 1][cH - 7 + 8] = '_';
		x[rH + 7][cH + 3] = ' ';

	}
}

void RightHandMoveH1(char x[][2000], int rH, int cH, int countRLHL1, int GunsTook)
{

	if (countRLHL1 == 0 && GunsTook == 0)
	{


		x[rH + 6][cH + 4] = '\\';	//RIGHT HAND
		x[rH + 6][cH + 5] = '_';
		x[rH + 6][cH + 6] = '_';
		x[rH + 6][cH + 7] = '/';
		x[rH + 5][cH + 8] = '/';
		x[rH + 4][cH + 7] = '_';
		x[rH + 5][cH + 5] = '\\';
		x[rH + 5][cH + 6] = '/';
		x[rH + 4][cH + 4] = '_';

	}
	if (countRLHL1 % 2 != 0 && GunsTook == 0)
	{
		x[rH + 6][cH + 4] = '_';	//RIGHT HAND
		x[rH + 6][cH + 3] = ' ';
		x[rH + 5][cH + 3] = '/';
		x[rH + 6][cH + 5] = '_';
		x[rH + 6][cH + 7] = ' ';
		x[rH + 6][cH + 6] = '|';
		x[rH + 6][cH + 8] = ' ';
		x[rH + 4][cH + 7] = '_';
		x[rH + 5][cH + 5] = '_';
		x[rH + 5][cH + 6] = ' ';
		x[rH + 5][cH + 7] = ' ';
		x[rH + 4][cH + 4] = ' ';
		x[rH + 5][cH + 4] = '_';
		x[rH + 4][cH + 7] = ' ';

	}
	else if (countRLHL1 % 2 == 0 && GunsTook == 0)
	{
		x[rH + 6][cH + 4] = '\\';	//RIGHT HAND
		x[rH + 6][cH + 5] = '_';
		x[rH + 6][cH + 6] = '_';
		x[rH + 6][cH + 7] = '/';
		x[rH + 5][cH + 8] = '/';
		x[rH + 4][cH + 7] = '_';
		x[rH + 5][cH + 5] = '\\';
		x[rH + 5][cH + 6] = '/';
		x[rH + 4][cH + 4] = '_';


	}

	if (GunsTook == 1)
	{
		x[rH + 6][cH + 4] = '\\';	//RIGHT HAND
		x[rH + 6][cH + 5] = '_';
		x[rH + 6][cH + 6] = '_';
		x[rH + 6][cH + 7] = '/';
		x[rH + 5][cH + 8] = '_';
		x[rH + 4][cH + 7] = '_';
		x[rH + 5][cH + 5] = '\\';
		x[rH + 5][cH + 6] = '/';
		x[rH + 4][cH + 4] = '_';

		x[rH + 4][cH + 7] = '_';	//GUN
		x[rH + 4][cH + 8] = '_';
		x[rH + 4][cH + 9] = '_';
		x[rH + 4][cH + 10] = '_';
		x[rH + 4][cH + 11] = '_';
		x[rH + 4][cH + 12] = '_';
		x[rH + 5][cH + 13] = '|';
		x[rH + 5][cH + 12] = '_';
		x[rH + 5][cH + 11] = '_';
		x[rH + 5][cH + 10] = '_';
		x[rH + 6][cH + 9] = '/';
		x[rH + 6][cH + 8] = '_';

	}
}

void RightLegMoveH1(char x[][2000], int& rH, int& cH, int countRLH1)
{
	if (countRLH1 == 0)
	{

		x[rH + 8][cH + 1] = '\\';			//RIGHT LEG 3
		x[rH + 9][cH + 2] = '\\';
		x[rH + 10][cH + 2] = '|';

		x[rH + 8][cH + 3] = '\\';			//RIGHT LEG 4
		x[rH + 9][cH + 4] = '\\';
		x[rH + 10][cH + 4] = '|';
		x[rH + 10][cH + 3] = '_';
	}

	if (countRLH1 % 2 != 0)
	{
		x[rH + 8][cH + 1] = '/';			//RIGHT LEG 3
		x[rH + 9][cH + 2] = '/';
		//x[rH + 10][cH + 2] = ' ';//////

		x[rH + 8][cH + 3] = '/';			//RIGHT LEG 4
		x[rH + 9][cH + 4] = ' ';
		x[rH + 10][cH + 4] = ' ';
		x[rH + 10][cH + 3] = ' ';
		x[rH + 10][cH - 1] = '_';
		x[rH + 10][cH - 2] = '|';
	}

	else
	{
		x[rH + 8][cH + 1] = '\\';			//RIGHT LEG 3
		x[rH + 9][cH + 2] = '\\';
		x[rH + 10][cH + 2] = '|';

		x[rH + 8][cH + 3] = '\\';			//RIGHT LEG 4
		x[rH + 9][cH + 4] = '\\';
		x[rH + 10][cH + 4] = '|';
		x[rH + 10][cH + 3] = '_';
	}
}

void LeftLegMoveH1(char x[][2000], int& rH, int& cH, int countRLHL1)
{
	if (countRLHL1 == 0)
	{
		x[rH + 8][cH - 2] = '/';			//LEFT LEG 1
		x[rH + 9][cH - 3] = '/';
		x[rH + 10][cH - 4] = '/';

		x[rH + 8][cH] = '/'; 			//LEFT LEG 2
		x[rH + 9][cH - 1] = '/';
		x[rH + 10][cH - 2] = '/';
		x[rH + 10][cH - 3] = '_';
	}

	if (countRLHL1 % 2 != 0)
	{
		x[rH + 8][cH - 2] = '\\';			//LEFT LEG 1
		x[rH + 9][cH - 1] = '\\';
		x[rH + 10][cH] = '\\';

		x[rH + 8][cH] = '\\'; 			//LEFT LEG 2
		x[rH + 9][cH + 1] = '\\';
		x[rH + 10][cH + 1] = '_';		//FOOT
		x[rH + 10][cH + 2] = '\\';

		//x[rH + 10][cH - 3] = ' ';


	}
	else
	{
		x[rH + 8][cH - 2] = '/';			//LEFT LEG 1
		x[rH + 9][cH - 3] = '/';
		x[rH + 10][cH - 4] = '/';

		x[rH + 8][cH] = '/'; 			//LEFT LEG 2
		x[rH + 9][cH - 1] = '/';
		x[rH + 10][cH - 2] = '/';
		x[rH + 10][cH - 3] = '_';
	}
}

void SElev(char x[][138], int rEv, int cEv, int rH, int cH, int GetOut, int openG, int rEvR)
{
	/*if (rEv > 33 || rEv < 0 || rH < 0 || cH > 138 || rH > 100)
	{

		rH = rEv + 1;
		cH = 114;

	}*/




	x[rEv][cEv] = '_';
	x[rEv][cEv + 1] = '_';
	x[rEv][cEv + 2] = '_';
	x[rEv][cEv + 3] = '_';
	x[rEv][cEv + 4] = '_';
	x[rEv][cEv + 5] = '_';
	x[rEv][cEv + 6] = '_';
	x[rEv][cEv + 7] = '_';
	x[rEv][cEv + 8] = '_';
	x[rEv][cEv + 9] = '_';
	x[rEv][cEv + 10] = '_';
	x[rEv][cEv + 11] = '_';
	x[rEv][cEv + 12] = '_';
	x[rEv][cEv + 13] = '_';
	x[rEv][cEv + 14] = '_';
	x[rEv][cEv + 15] = '_';

	x[rEv + 12][cEv] = '_';
	x[rEv + 12][cEv + 1] = '_';
	x[rEv + 12][cEv + 2] = '_';
	x[rEv + 12][cEv + 3] = '_';
	x[rEv + 12][cEv + 4] = '_';
	x[rEv + 12][cEv + 5] = '_';
	x[rEv + 12][cEv + 6] = '_';
	x[rEv + 12][cEv + 7] = '_';
	x[rEv + 12][cEv + 8] = '_';
	x[rEv + 12][cEv + 9] = '_';
	x[rEv + 12][cEv + 10] = '_';
	x[rEv + 12][cEv + 11] = '_';
	x[rEv + 12][cEv + 12] = '_';
	x[rEv + 12][cEv + 13] = '_';
	x[rEv + 12][cEv + 14] = '_';
	x[rEv + 12][cEv + 15] = '_';



	for (int i = 0; (rEvR - 1) >= -1; i++, rEvR--)
	{
		x[rEvR][117] = 179;

	}

	if (GetOut != 1)
	{

		x[rEv - 1][118] = 'E';
		x[rEv - 1][119] = 'l';
		x[rEv - 1][120] = 'e';
		x[rEv - 1][121] = 'v';
		x[rEv - 1][122] = 'a';
		x[rEv - 1][123] = 't';
		x[rEv - 1][124] = 'o';
		x[rEv - 1][125] = 'r';

	}



	if (GetOut != 2 && openG == 0)
	{

		x[rEv + 1][125] = '|';
		x[rEv + 2][125] = '|';
		x[rEv + 3][125] = '|';
		x[rEv + 4][125] = '|';
		x[rEv + 5][125] = '|';
		x[rEv + 6][125] = '|';
		x[rEv + 7][125] = '|';
		x[rEv + 8][125] = '|';
		x[rEv + 9][125] = '|';
		x[rEv + 10][125] = '|';
		x[rEv + 11][125] = '|';
		x[rEv + 12][125] = '|';

	}

	if (GetOut != 3)
	{

		x[rEv + 1][108] = '|';
		x[rEv + 2][108] = '|';
		x[rEv + 3][108] = '|';
		x[rEv + 4][108] = '|';
		x[rEv + 5][108] = '|';
		x[rEv + 6][108] = '|';
		x[rEv + 7][108] = '|';
		x[rEv + 8][108] = '|';
		x[rEv + 9][108] = '|';
		x[rEv + 10][108] = '|';
		x[rEv + 11][108] = '|';
		x[rEv + 12][108] = '|';

	}

	for (int r = rEv + 1, i = 0; i < 11; r++, i++)
	{
		for (int c = cEv, j = 0; j < 16; c++, j++)
		{
			x[r][c] = ' ';
		}
	}

}

void DElev(char x[][138], int& rEv, int cEv, int& rH, int cH, int& GetOut, int& countRLHL1, int& openG, int &rEvR)
{
	if (cH >= 115 && rEv > 11)
	{
		rH = rEv + 1;
		rEv -= 2;
		GetOut = 1;
		countRLHL1 = 2;
		rEvR -= 2;
	}

	else if (rEv <= 11)
	{
		//rH = 12;
		GetOut = 2;
		openG = 1;
		rH = rEv + 1;
		//system("pause");
		x[9][120] = '-';
		x[9][121] = '-';
		x[9][122] = '-';
		x[9][123] = '-';
		x[9][124] = '-';
		x[9][125] = '-';
		x[9][126] = '-';
		x[9][127] = '-';
		x[9][128] = '-';
		x[9][129] = 16;
	}
}

void Floor_Elev(char x[][138], int& r, int& c, int& FloorNumber, int GetOut, int& FloorNumberCount)
{
	x[r][c] = 'F';
	x[r][c + 1] = 'l';
	x[r][c + 2] = 'o';
	x[r][c + 3] = 'o';
	x[r][c + 4] = 'r';
	x[r][c + 5] = ':';
	x[r][c + 6] = 'G';
	char FN[2];
	_itoa_s(FloorNumber, FN, 10);

	if (GetOut == 1)
	{
		if (FloorNumberCount % 3 == 0)
		{
			FloorNumber++;
		}
		x[r][c + 6] = FN[0];
		r -= 2;
	}
	if (GetOut == 2)
	{
		x[r][c + 6] = FN[0];
	}
	FloorNumberCount++;
}

void LevelCounter(char x[][2000], int Stage)
{


}

void TimeCounter(char x[][2000], int& mins, int& secs, int CounterUntilStop, int& lose1, int& DeathT, int level, int shoot1, int value)
{

	x[0][53 + value] = 'T';
	x[0][54 + value] = 'i';
	x[0][55 + value] = 'm';
	x[0][56 + value] = 'e';
	x[0][57 + value] = ' ';
	x[0][58 + value] = 'L';
	x[0][59 + value] = 'e';
	x[0][60 + value] = 'f';
	x[0][61 + value] = 't';
	x[0][62 + value] = ' ';
	//x[0][63] = '5';
	//x[0][64] = 'm';
	x[0][65 + value] = ' ';
	//x[0][66] = '9';
	//x[0][67] = '9';
	//x[0][68] = 's';
	x[0][69 + value] = ' ';
	x[0][70 + value] = '|';
	x[0][71 + value] = ' ';


	char TimeS[5];
	_itoa_s(secs, TimeS, 10);
	x[0][66 + value] = TimeS[0];
	x[0][67 + value] = TimeS[1];
	x[0][68 + value] = 's';

	if (secs < 10)
	{
		x[0][66 + value] = TimeS[0];
		x[0][67 + value] = 's';
		x[0][68 + value] = ' ';
	}


	secs--;

	char TimeM[5];
	_itoa_s(mins, TimeM, 10);
	x[0][63 + value] = TimeM[0];
	x[0][64 + value] = 'm';

	if (secs == 0)
	{
		mins--;
		if (mins < 0 && secs == 0)
		{
			lose1 = 1;
			DeathT = 1;
		}
		secs = 60;

	}





}

void HealthBar(char x[][2000], int rH, int cH, int& shoot1, int& lose1, int& DeathT, int level, int& countHearts, int& countHearts2, int mins, int value)
{

	if (level == 6)
	{
		if (shoot1 == 0)
		{
			char HB1[2];
			_itoa_s(6, HB1, 10);
			x[0][72 + value] = 'H';
			x[0][73 + value] = 'e';
			x[0][74 + value] = 'a';
			x[0][75 + value] = 'l';
			x[0][76 + value] = 't';
			x[0][77 + value] = 'h';
			x[0][78 + value] = ' ';
			x[0][79 + value] = 'B';
			x[0][80 + value] = 'a';
			x[0][81 + value] = 'r';
			x[0][82 + value] = ' ';
			x[0][83 + value] = 219;
			x[0][84 + value] = ' ';
			x[0][85 + value] = 219;
			x[0][86 + value] = ' ';
			x[0][87 + value] = 219;
			x[0][88 + value] = ' ';
			x[0][89 + value] = 219;
			x[0][90 + value] = ' ';
			x[0][91 + value] = 219;
			x[0][92 + value] = ' ';
			x[0][93 + value] = 219;
			x[0][94 + value] = ' ';
			x[0][95 + value] = HB1[0];

		}
		if (shoot1 == 1)
		{
			char HB2[2];
			_itoa_s(5, HB2, 10);
			x[0][72 + value] = 'H';
			x[0][73 + value] = 'e';
			x[0][74 + value] = 'a';
			x[0][75 + value] = 'l';
			x[0][76 + value] = 't';
			x[0][77 + value] = 'h';
			x[0][78 + value] = ' ';
			x[0][79 + value] = 'B';
			x[0][80 + value] = 'a';
			x[0][81 + value] = 'r';
			x[0][82 + value] = ' ';
			x[0][83 + value] = 219;
			x[0][84 + value] = ' ';
			x[0][85 + value] = 219;
			x[0][86 + value] = ' ';
			x[0][87 + value] = 219;
			x[0][88 + value] = ' ';
			x[0][89 + value] = 219;
			x[0][90 + value] = ' ';
			x[0][91 + value] = 219;
			x[0][92 + value] = ' ';
			x[0][93 + value] = HB2[0];


		}
		if (shoot1 == 2)
		{
			char HB3[2];
			_itoa_s(4, HB3, 10);
			x[0][72 + value] = 'H';
			x[0][73 + value] = 'e';
			x[0][74 + value] = 'a';
			x[0][75 + value] = 'l';
			x[0][76 + value] = 't';
			x[0][77 + value] = 'h';
			x[0][78 + value] = ' ';
			x[0][79 + value] = 'B';
			x[0][80 + value] = 'a';
			x[0][81 + value] = 'r';
			x[0][82 + value] = ' ';
			x[0][83 + value] = 219;
			x[0][84 + value] = ' ';
			x[0][85 + value] = 219;
			x[0][86 + value] = ' ';
			x[0][87 + value] = 219;
			x[0][88 + value] = ' ';
			x[0][89 + value] = 219;
			x[0][90 + value] = ' ';
			x[0][91 + value] = HB3[0];


		}
		if (shoot1 == 3)
		{
			char HB4[2];
			_itoa_s(3, HB4, 10);
			x[0][72 + value] = 'H';
			x[0][73 + value] = 'e';
			x[0][74 + value] = 'a';
			x[0][75 + value] = 'l';
			x[0][76 + value] = 't';
			x[0][77 + value] = 'h';
			x[0][78 + value] = ' ';
			x[0][79 + value] = 'B';
			x[0][80 + value] = 'a';
			x[0][81 + value] = 'r';
			x[0][82 + value] = ' ';
			x[0][83 + value] = 219;
			x[0][84 + value] = ' ';
			x[0][85 + value] = 219;
			x[0][86 + value] = ' ';
			x[0][87 + value] = 219;
			x[0][88 + value] = ' ';
			x[0][89 + value] = HB4[0];


		}
		if (shoot1 == 4)
		{
			char HB5[2];
			_itoa_s(2, HB5, 10);
			x[0][72 + value] = 'H';
			x[0][73 + value] = 'e';
			x[0][74 + value] = 'a';
			x[0][75 + value] = 'l';
			x[0][76 + value] = 't';
			x[0][77 + value] = 'h';
			x[0][78 + value] = ' ';
			x[0][79 + value] = 'B';
			x[0][80 + value] = 'a';
			x[0][81 + value] = 'r';
			x[0][82 + value] = ' ';
			x[0][83 + value] = 219;
			x[0][84 + value] = ' ';
			x[0][85 + value] = 219;
			x[0][86 + value] = ' ';
			x[0][87 + value] = HB5[0];

		}
		if (shoot1 == 5)
		{
			char HB6[2];
			_itoa_s(1, HB6, 10);
			x[0][72 + value] = 'H';
			x[0][73 + value] = 'e';
			x[0][74 + value] = 'a';
			x[0][75 + value] = 'l';
			x[0][76 + value] = 't';
			x[0][77 + value] = 'h';
			x[0][78 + value] = ' ';
			x[0][79 + value] = 'B';
			x[0][80 + value] = 'a';
			x[0][81 + value] = 'r';
			x[0][82 + value] = ' ';
			x[0][83 + value] = 219;
			x[0][84 + value] = ' ';
			x[0][85 + value] = HB6[0];

		}
		if (shoot1 >= 6)
		{
			char HB7[2];
			_itoa_s(0, HB7, 10);
			x[0][72 + value] = 'H';
			x[0][73 + value] = 'e';
			x[0][74 + value] = 'a';
			x[0][75 + value] = 'l';
			x[0][76 + value] = 't';
			x[0][77 + value] = 'h';
			x[0][78 + value] = ' ';
			x[0][79 + value] = 'B';
			x[0][80 + value] = 'a';
			x[0][81 + value] = 'r';
			x[0][82 + value] = ' ';
			x[0][83 + value] = HB7[0];

			lose1 = 1;

		}
	}

	if (level == 2 && countHearts == 0)
	{
		x[28][95] = 3;

	}
	if (level == 2 && countHearts2 == 0)
	{
		x[32][41] = 3;
	}

	if ((x[28][96] != ' ' || x[28][94] != ' ' || x[28][95] != 3 || x[27][94] != ' ' || x[27][95] != ' ' || x[27][96] != ' ' || x[29][94] != ' ' || x[29][95] != ' ' || x[29][96] != ' ') && level == 2 && shoot1 >= 1 && countHearts == 0)
	{

		if (shoot1 >= 1)
		{
			shoot1--;
		}

		x[28][95] = ' ';
		countHearts++;
	}

	if ((x[32][40] != ' ' || x[32][41] != 3 || x[32][42] != ' ' || x[31][41] != ' ' || x[31][42] != ' ' || x[31][43] != ' ' || x[33][41] != ' ' || x[33][42] != ' ' || x[33][43] != ' ') && level == 2 && shoot1 >= 1 && countHearts2 == 0)
	{
		if (shoot1 >= 1)
		{
			shoot1--;
		}

		x[32][41] = ' ';
		countHearts2++;
	}


	if (level == 5)
	{
		if (shoot1 == 0)
		{
			char HB1[2];
			_itoa_s(6, HB1, 10);

			x[rH - 2][cH - 4] = 219;
			x[rH - 2][cH - 3] = ' ';
			x[rH - 2][cH - 2] = 219;
			x[rH - 2][cH - 1] = ' ';
			x[rH - 2][cH] = 219;
			x[rH - 2][cH + 1] = ' ';
			x[rH - 2][cH + 2] = 219;
			x[rH - 2][cH + 3] = ' ';
			x[rH - 2][cH + 4] = 219;
			x[rH - 2][cH + 5] = ' ';
			x[rH - 2][cH + 6] = 219;
			x[rH - 2][cH + 7] = ' ';
			x[rH - 2][cH + 8] = HB1[0];

		}
		if (shoot1 == 1)
		{
			char HB2[2];
			_itoa_s(5, HB2, 10);

			x[rH - 2][cH - 4] = 219;
			x[rH - 2][cH - 3] = ' ';
			x[rH - 2][cH - 2] = 219;
			x[rH - 2][cH - 1] = ' ';
			x[rH - 2][cH] = 219;
			x[rH - 2][cH + 1] = ' ';
			x[rH - 2][cH + 2] = 219;
			x[rH - 2][cH + 3] = ' ';
			x[rH - 2][cH + 4] = 219;
			x[rH - 2][cH + 5] = ' ';
			x[rH - 2][cH + 6] = HB2[0];


		}
		if (shoot1 == 2)
		{
			char HB3[2];
			_itoa_s(4, HB3, 10);

			x[rH - 2][cH - 4] = 219;
			x[rH - 2][cH - 3] = ' ';
			x[rH - 2][cH - 2] = 219;
			x[rH - 2][cH - 1] = ' ';
			x[rH - 2][cH] = 219;
			x[rH - 2][cH + 1] = ' ';
			x[rH - 2][cH + 2] = 219;
			x[rH - 2][cH + 3] = ' ';
			x[rH - 2][cH + 4] = HB3[0];


		}
		if (shoot1 == 3)
		{
			char HB4[2];
			_itoa_s(3, HB4, 10);

			x[rH - 2][cH - 4] = 219;
			x[rH - 2][cH - 3] = ' ';
			x[rH - 2][cH - 2] = 219;
			x[rH - 2][cH - 1] = ' ';
			x[rH - 2][cH] = 219;
			x[rH - 2][cH + 1] = ' ';
			x[rH - 2][cH + 2] = HB4[0];


		}
		if (shoot1 == 4)
		{
			char HB5[2];
			_itoa_s(2, HB5, 10);

			x[rH - 2][cH - 4] = 219;
			x[rH - 2][cH - 3] = ' ';
			x[rH - 2][cH - 2] = 219;
			x[rH - 2][cH - 1] = ' ';
			x[rH - 2][cH] = HB5[0];


		}
		if (shoot1 == 5)
		{
			char HB6[2];
			_itoa_s(1, HB6, 10);

			x[rH - 2][cH - 4] = 219;
			x[rH - 2][cH - 3] = ' ';
			x[rH - 2][cH - 2] = HB6[0];


		}
		if (shoot1 >= 6)
		{
			char HB7[2];
			_itoa_s(0, HB7, 10);

			x[rH - 2][cH - 4] = HB7[0];

			lose1 = 1;

		}
	}
}

void BigBossHealthBar(char x[][138], int rH, int cH, int& gotshot, int& win, int mins, int rBB, int cBB)
{

	if (gotshot == 0)
	{
		char HB1[3];
		_itoa_s(10, HB1, 10);

		x[rBB - 3][cBB - 10] = 219;
		x[rBB - 3][cBB - 9] = ' ';
		x[rBB - 3][cBB - 8] = 219;
		x[rBB - 3][cBB - 7] = ' ';
		x[rBB - 3][cBB - 6] = 219;
		x[rBB - 3][cBB - 5] = ' ';
		x[rBB - 3][cBB - 4] = 219;
		x[rBB - 3][cBB - 3] = ' ';
		x[rBB - 3][cBB - 2] = 219;
		x[rBB - 3][cBB - 1] = ' ';
		x[rBB - 3][cBB] = 219;
		x[rBB - 3][cBB + 1] = ' ';
		x[rBB - 3][cBB + 2] = 219;
		x[rBB - 3][cBB + 3] = ' ';
		x[rBB - 3][cBB + 4] = 219;
		x[rBB - 3][cBB + 5] = ' ';
		x[rBB - 3][cBB + 6] = 219;
		x[rBB - 3][cBB + 7] = ' ';
		x[rBB - 3][cBB + 8] = 219;
		x[rBB - 3][cBB + 9] = ' ';
		x[rBB - 3][cBB + 10] = HB1[0];
		x[rBB - 3][cBB + 11] = HB1[1];


	}
	if (gotshot == 1)
	{
		char HB2[2];
		_itoa_s(9, HB2, 10);

		x[rBB - 3][cBB - 10] = 219;
		x[rBB - 3][cBB - 9] = ' ';
		x[rBB - 3][cBB - 8] = 219;
		x[rBB - 3][cBB - 7] = ' ';
		x[rBB - 3][cBB - 6] = 219;
		x[rBB - 3][cBB - 5] = ' ';
		x[rBB - 3][cBB - 4] = 219;
		x[rBB - 3][cBB - 3] = ' ';
		x[rBB - 3][cBB - 2] = 219;
		x[rBB - 3][cBB - 1] = ' ';
		x[rBB - 3][cBB] = 219;
		x[rBB - 3][cBB + 1] = ' ';
		x[rBB - 3][cBB + 2] = 219;
		x[rBB - 3][cBB + 3] = ' ';
		x[rBB - 3][cBB + 4] = 219;
		x[rBB - 3][cBB + 5] = ' ';
		x[rBB - 3][cBB + 6] = 219;
		x[rBB - 3][cBB + 7] = ' ';
		x[rBB - 3][cBB + 8] = HB2[0];



	}
	if (gotshot == 2)
	{
		char HB3[2];
		_itoa_s(8, HB3, 10);

		x[rBB - 3][cBB - 10] = 219;
		x[rBB - 3][cBB - 9] = ' ';
		x[rBB - 3][cBB - 8] = 219;
		x[rBB - 3][cBB - 7] = ' ';
		x[rBB - 3][cBB - 6] = 219;
		x[rBB - 3][cBB - 5] = ' ';
		x[rBB - 3][cBB - 4] = 219;
		x[rBB - 3][cBB - 3] = ' ';
		x[rBB - 3][cBB - 2] = 219;
		x[rBB - 3][cBB - 1] = ' ';
		x[rBB - 3][cBB] = 219;
		x[rBB - 3][cBB + 1] = ' ';
		x[rBB - 3][cBB + 2] = 219;
		x[rBB - 3][cBB + 3] = ' ';
		x[rBB - 3][cBB + 4] = 219;
		x[rBB - 3][cBB + 5] = ' ';
		x[rBB - 3][cBB + 6] = HB3[0];


	}
	if (gotshot == 3)
	{
		char HB4[2];
		_itoa_s(7, HB4, 10);

		x[rBB - 3][cBB - 10] = 219;
		x[rBB - 3][cBB - 9] = ' ';
		x[rBB - 3][cBB - 8] = 219;
		x[rBB - 3][cBB - 7] = ' ';
		x[rBB - 3][cBB - 6] = 219;
		x[rBB - 3][cBB - 5] = ' ';
		x[rBB - 3][cBB - 4] = 219;
		x[rBB - 3][cBB - 3] = ' ';
		x[rBB - 3][cBB - 2] = 219;
		x[rBB - 3][cBB - 1] = ' ';
		x[rBB - 3][cBB] = 219;
		x[rBB - 3][cBB + 1] = ' ';
		x[rBB - 3][cBB + 2] = 219;
		x[rBB - 3][cBB + 3] = ' ';
		x[rBB - 3][cBB + 4] = HB4[0];


	}
	if (gotshot == 4)
	{
		char HB5[2];
		_itoa_s(6, HB5, 10);

		x[rBB - 3][cBB - 10] = 219;
		x[rBB - 3][cBB - 9] = ' ';
		x[rBB - 3][cBB - 8] = 219;
		x[rBB - 3][cBB - 7] = ' ';
		x[rBB - 3][cBB - 6] = 219;
		x[rBB - 3][cBB - 5] = ' ';
		x[rBB - 3][cBB - 4] = 219;
		x[rBB - 3][cBB - 3] = ' ';
		x[rBB - 3][cBB - 2] = 219;
		x[rBB - 3][cBB - 1] = ' ';
		x[rBB - 3][cBB] = 219;
		x[rBB - 3][cBB + 1] = ' ';
		x[rBB - 3][cBB + 2] = HB5[0];


	}
	if (gotshot == 5)
	{
		char HB6[2];
		_itoa_s(5, HB6, 10);

		x[rBB - 3][cBB - 10] = 219;
		x[rBB - 3][cBB - 9] = ' ';
		x[rBB - 3][cBB - 8] = 219;
		x[rBB - 3][cBB - 7] = ' ';
		x[rBB - 3][cBB - 6] = 219;
		x[rBB - 3][cBB - 5] = ' ';
		x[rBB - 3][cBB - 4] = 219;
		x[rBB - 3][cBB - 3] = ' ';
		x[rBB - 3][cBB - 2] = 219;
		x[rBB - 3][cBB - 1] = ' ';
		x[rBB - 3][cBB] = HB6[0];


	}
	if (gotshot == 6)
	{
		char HB7[2];
		_itoa_s(4, HB7, 10);

		x[rBB - 3][cBB - 10] = 219;
		x[rBB - 3][cBB - 9] = ' ';
		x[rBB - 3][cBB - 8] = 219;
		x[rBB - 3][cBB - 7] = ' ';
		x[rBB - 3][cBB - 6] = 219;
		x[rBB - 3][cBB - 5] = ' ';
		x[rBB - 3][cBB - 4] = 219;
		x[rBB - 3][cBB - 3] = ' ';
		x[rBB - 3][cBB - 2] = HB7[0];



	}

	if (gotshot == 7)
	{
		char HB8[2];
		_itoa_s(3, HB8, 10);

		x[rBB - 3][cBB - 10] = 219;
		x[rBB - 3][cBB - 9] = ' ';
		x[rBB - 3][cBB - 8] = 219;
		x[rBB - 3][cBB - 7] = ' ';
		x[rBB - 3][cBB - 6] = 219;
		x[rBB - 3][cBB - 5] = ' ';
		x[rBB - 3][cBB - 4] = HB8[0];



	}

	if (gotshot == 8)
	{
		char HB9[2];
		_itoa_s(2, HB9, 10);


		x[rBB - 3][cBB - 10] = 219;
		x[rBB - 3][cBB - 9] = ' ';
		x[rBB - 3][cBB - 8] = 219;
		x[rBB - 3][cBB - 7] = ' ';
		x[rBB - 3][cBB - 6] = HB9[0];



	}

	if (gotshot == 9)
	{
		char HB10[2];
		_itoa_s(1, HB10, 10);

		x[rBB - 3][cBB - 10] = 219;
		x[rBB - 3][cBB - 9] = ' ';
		x[rBB - 3][cBB - 8] = HB10[0];



	}

	if (gotshot >= 10)
	{
		char HB11[2];
		_itoa_s(0, HB11, 10);

		x[rBB - 3][cBB - 9] = ' ';

		win = 1;

	}

}

void HighScore(char x[][2000], int rH, int cH, int& Scounter, int CounterUntilStop, int& HScounter, int level, int shoot1, int flagScore1, int flagScore2, int flagScore3, int AutoWalk, int value)
{
	x[0][124 + value] = 'S';
	x[0][125 + value] = 'c';
	x[0][126 + value] = 'o';
	x[0][127 + value] = 'r';
	x[0][128 + value] = 'e';
	x[0][129 + value] = ':';


	if (level == 6)
	{


		x[0][1 + value] = 'H';
		x[0][2 + value] = 'i';
		x[0][3 + value] = 'g';
		x[0][4 + value] = 'h';
		x[0][5 + value] = ' ';
		x[0][6 + value] = 'S';
		x[0][7 + value] = 'c';
		x[0][8 + value] = 'o';
		x[0][9 + value] = 'r';
		x[0][10 + value] = 'e';
		x[0][11 + value] = ':';
		if (AutoWalk == 0)
		{
			x[20][55 + value] = 'A';
			x[20][56 + value] = 'u';
			x[20][57 + value] = 't';
			x[20][58 + value] = 'o';
			x[20][59 + value] = ' ';
			x[20][60 + value] = 'W';
			x[20][61 + value] = 'a';
			x[20][62 + value] = 'l';
			x[20][63 + value] = 'k';
			x[20][64 + value] = ' ';
			x[20][65 + value] = ':';
			x[20][66 + value] = ' ';
			x[20][67 + value] = 'O';
			x[20][68 + value] = 'F';
			x[20][69 + value] = 'F';
			x[20][70 + value] = ' ';
			x[20][71 + value] = '(';
			x[20][72 + value] = 'B';
			x[20][73 + value] = 'S';
			x[20][74 + value] = 'P';
			x[20][75 + value] = ')';

		}
		if (AutoWalk == 1)
		{
			x[20][55 + value] = 'A';
			x[20][56 + value] = 'u';
			x[20][57 + value] = 't';
			x[20][58 + value] = 'o';
			x[20][59 + value] = ' ';
			x[20][60 + value] = 'W';
			x[20][61 + value] = 'a';
			x[20][62 + value] = 'l';
			x[20][63 + value] = 'k';
			x[20][64 + value] = ' ';
			x[20][65 + value] = ':';
			x[20][66 + value] = ' ';
			x[20][67 + value] = 'O';
			x[20][68 + value] = 'N';
			x[20][69 + value] = ' ';
			x[20][70 + value] = ' ';
			x[20][71 + value] = '(';
			x[20][72 + value] = 'B';
			x[20][73 + value] = 'S';
			x[20][74 + value] = 'P';
			x[20][75 + value] = ')';

		}

	}


	Scounter++;


	char SC[10];
	_itoa_s(Scounter, SC, 10);

	x[0][130 + value] = SC[0];

	if (Scounter > 9)
	{
		x[0][131 + value] = SC[1];
	}
	if (Scounter > 99)
	{
		x[0][132 + value] = SC[2];
	}
	if (Scounter > 999)
	{
		x[0][133 + value] = SC[3];
	}
	if (Scounter > 9999)
	{
		x[0][134 + value] = SC[4];
	}
	if (Scounter > 99999)
	{
		x[0][135 + value] = SC[5];
	}
	if (Scounter > 999999)
	{
		x[0][136 + value] = SC[6];
	}
	if (Scounter > 9999999)
	{
		x[0][137 + value] = SC[7];
	}





	if (level == 6)
	{


		char HSC[10];
		_itoa_s(HScounter, HSC, 10);

		if (HScounter >= 0)
		{
			x[0][12 + value] = HSC[0];
		}
		if (HScounter > 9)
		{
			x[0][13 + value] = HSC[1];
		}
		if (HScounter > 99)
		{
			x[0][14 + value] = HSC[2];
		}
		if (HScounter > 999)
		{
			x[0][15 + value] = HSC[3];
		}
		if (HScounter > 9999)
		{
			x[0][16 + value] = HSC[4];
		}
		if (HScounter > 99999)
		{
			x[0][17 + value] = HSC[5];
		}
		if (HScounter > 999999)
		{
			x[0][18 + value] = HSC[6];
		}
		if (HScounter > 9999999)
		{
			x[0][19 + value] = HSC[7];
		}


		if (Scounter > HScounter)
		{
			HScounter = Scounter;

			x[0][12 + value] = SC[0];

			if (HScounter > 9)
			{
				x[0][13 + value] = SC[1];
			}
			if (HScounter > 99)
			{
				x[0][14 + value] = SC[2];
			}
			if (HScounter > 999)
			{
				x[0][15 + value] = SC[3];
			}
			if (HScounter > 9999)
			{
				x[0][16 + value] = SC[4];
			}
			if (HScounter > 99999)
			{
				x[0][17 + value] = SC[5];
			}
			if (HScounter > 999999)
			{
				x[0][18 + value] = SC[6];
			}
			if (HScounter > 9999999)
			{
				x[0][19 + value] = SC[7];
			}
		}


	}
}

void StaticGunShot(char x[][138], int rE1, int cE1, int& rEG1, int& cEG1, int& countG1, int CounterUntilStop, int GetOut)
{
	/*if (countG1 % 2 != 0)
	{
		rEG1 = rE1;
		cEG1 = cE1;

	}*/

	if (CounterUntilStop >= 21 && (GetOut == 0 || GetOut == 3))
	{
		x[rEG1 + 5][cEG1 + 13] = 22;

	}

}

void DynamicGunShot(char x[][138], int& rE1, int& cE1, int& rEG1, int& cEG1, int& countG1, int CounterUntilStop, int rH, int cH, int& shoot1, int GetOut, int& DelayShot, int& lose1, int& DeathT)
{

	int breakable = 0;
	breakable = 0;
	if (CounterUntilStop >= 21 && (GetOut == 0 || GetOut == 3))
	{
		cEG1 += 4;
	}

	if (cEG1 > 95 && CounterUntilStop >= 21 && (GetOut == 0 || GetOut == 3))
	{
		cEG1 = cE1;
	}


	if (CounterUntilStop >= 21 && (GetOut == 0 || GetOut == 3))
	{
		for (int r = rH, i = 0; i < 12; i++, r++)
		{
			for (int c = cH - 4, j = 0; j < 8; j++, c++)
			{
				if (x[r][c] == 22)
				{
					DeathT = 3;
					shoot1++;
					cEG1 = cE1;
					breakable = 1;
					break;
				}
			}
			if (breakable == 1)
			{
				breakable = 0;
				break;
			}

		}

		for (int r = rH - 1, i = 0; i < 12; i++, r++)
		{
			for (int c = cH - 13, j = 0; j < 20; j++, c++)
			{
				if (x[r][c] == 21)
				{
					lose1 = 1;
					DeathT = 2;
					breakable = 1;
					break;
				}
			}
			if (breakable == 1)
			{
				break;
			}

		}

	}

	if (CounterUntilStop >= 21 && cH <= 26)
	{
		DeathT = 2;
		lose1 = 1;
	}


}

void StaticEnemy(char x[][2000], int cE1, int rE1, int CounterUntilStop, int countRLEL1, int Reload, int ActionReload, int level, int rB, int cB)
{

	if (CounterUntilStop >= 21)
	{


		x[rE1][cE1 - 2] = '_';
		x[rE1][cE1 - 3] = '/';
		x[rE1 + 1][cE1 - 3] = '\\';
		x[rE1 - 1][cE1 - 2] = '_';
		x[rE1 - 1][cE1 - 1] = '_';
		x[rE1 - 1][cE1] = '_';
		x[rE1 - 1][cE1 + 1] = '_';
		x[rE1 - 1][cE1 + 2] = '_';
		x[rE1 - 1][cE1 + 3] = '_';
		x[rE1][cE1 + 3] = '_';
		x[rE1][cE1 + 4] = '\\';
		x[rE1 + 1][cE1 + 4] = '/';



		x[rE1][cE1 - 1] = '_';
		x[rE1][cE1] = 21;
		x[rE1][cE1 + 1] = '_';
		x[rE1][cE1 + 2] = '_';


		{
			x[rE1 + 2][cE1] = 127;
			x[rE1 + 2][cE1 + 2] = 127;

			x[rE1 + 2][cE1 + 1] = ' ';
			x[rE1 + 2][cE1 - 1] = ' ';
		}

		x[rE1 + 1][cE1 - 2] = '/';
		x[rE1 + 1][cE1 + 3] = '\\';

		x[rE1 + 2][cE1 - 2] = '|';
		x[rE1 + 2][cE1 + 3] = '|';

		x[rE1 + 3][cE1 - 2] = '\\';
		x[rE1 + 3][cE1 + 3] = '/';

		x[rE1 + 3][cE1 - 1] = '_';
		x[rE1 + 3][cE1] = '_';
		x[rE1 + 3][cE1 + 1] = '^';
		x[rE1 + 3][cE1 + 2] = '_';

		x[rE1 + 4][cE1 - 2] = '_';
		x[rE1 + 4][cE1 - 1] = '/';
		x[rE1 + 4][cE1 + 2] = '/';
		x[rE1 + 4][cE1 + 3] = '_';

		if (countRLEL1 == 0)
		{


			x[rE1 + 6][cE1 + 4] = '\\';	//RIGHT HAND
			x[rE1 + 6][cE1 + 5] = '_';
			x[rE1 + 6][cE1 + 6] = '_';
			x[rE1 + 6][cE1 + 7] = '/';
			x[rE1 + 5][cE1 + 8] = '_';
			x[rE1 + 4][cE1 + 7] = '_';
			x[rE1 + 5][cE1 + 5] = '\\';
			x[rE1 + 5][cE1 + 6] = '/';
			x[rE1 + 4][cE1 + 4] = '_';

			x[rE1 + 4][cE1 + 7] = '_';	//GUN
			x[rE1 + 4][cE1 + 8] = '_';
			x[rE1 + 4][cE1 + 9] = '_';
			x[rE1 + 4][cE1 + 10] = '_';
			x[rE1 + 4][cE1 + 11] = '_';
			x[rE1 + 4][cE1 + 12] = '_';
			x[rE1 + 5][cE1 + 13] = '|';
			x[rE1 + 5][cE1 + 12] = '_';
			x[rE1 + 5][cE1 + 11] = '_';
			x[rE1 + 5][cE1 + 10] = '_';
			x[rE1 + 6][cE1 + 9] = '/';
			x[rE1 + 6][cE1 + 8] = '_';

		}
		if (countRLEL1 % 2 != 0)
		{
			x[rE1 + 6][cE1 + 4] = '_';	//RIGHT HAND
			x[rE1 + 6][cE1 + 3] = ' ';
			x[rE1 + 5][cE1 + 3] = '/';
			x[rE1 + 6][cE1 + 5] = '_';
			x[rE1 + 6][cE1 + 7] = ' ';
			x[rE1 + 6][cE1 + 6] = ' ';//
			x[rE1 + 6][cE1 + 8] = ' ';
			x[rE1 + 4][cE1 + 7] = '_';
			x[rE1 + 5][cE1 + 5] = '_';
			x[rE1 + 5][cE1 + 6] = ' ';
			x[rE1 + 5][cE1 + 7] = ' ';
			x[rE1 + 4][cE1 + 4] = ' ';
			x[rE1 + 5][cE1 + 4] = '_';
			x[rE1 + 4][cE1 + 7] = ' ';

			x[rE1 + 5][cE1 + 6] = ' ';	//GUN
			x[rE1 + 6][cE1 + 6] = '/';
			x[rE1 + 5][cE1 + 7] = '_';
			x[rE1 + 5][cE1 + 8] = '_';
			x[rE1 + 5][cE1 + 9] = '_';
			x[rE1 + 5][cE1 + 10] = '_';
			x[rE1 + 5][cE1 + 11] = '_';
			x[rE1 + 6][cE1 + 12] = '|';
			x[rE1 + 6][cE1 + 11] = '_';
			x[rE1 + 6][cE1 + 10] = '_';
			x[rE1 + 6][cE1 + 9] = '_';
			x[rE1 + 7][cE1 + 8] = '/';
			x[rE1 + 7][cE1 + 7] = '_';
			x[rE1 + 6][cE1 + 7] = ' ';
			x[rE1 + 7][cE1 + 6] = '|';



		}
		else
		{
			x[rE1 + 6][cE1 + 4] = '\\';	//RIGHT HAND
			x[rE1 + 6][cE1 + 5] = '_';
			x[rE1 + 6][cE1 + 6] = '_';
			x[rE1 + 6][cE1 + 7] = '/';
			x[rE1 + 5][cE1 + 8] = '_';
			x[rE1 + 4][cE1 + 7] = '_';
			x[rE1 + 5][cE1 + 5] = '\\';
			x[rE1 + 5][cE1 + 6] = '/';
			x[rE1 + 4][cE1 + 4] = '_';

			x[rE1 + 4][cE1 + 7] = '_';	//GUN
			x[rE1 + 4][cE1 + 8] = '_';
			x[rE1 + 4][cE1 + 9] = '_';
			x[rE1 + 4][cE1 + 10] = '_';
			x[rE1 + 4][cE1 + 11] = '_';
			x[rE1 + 4][cE1 + 12] = '_';
			x[rE1 + 5][cE1 + 13] = '|';
			x[rE1 + 5][cE1 + 12] = '_';
			x[rE1 + 5][cE1 + 11] = '_';
			x[rE1 + 5][cE1 + 10] = '_';
			x[rE1 + 6][cE1 + 9] = '/';
			x[rE1 + 6][cE1 + 8] = '_';



		}

		//LeftHandMoveH1(x, rE1, cE1, countRLEL1, Reload, ActionReload, level, rB, cB,GunsTook);

		//x[rH + 5][cH + 3] = ' ';	   
		//x[rH + 6][cH + 3] = '|';	   
		x[rE1 + 7][cE1 + 3] = '|';

		//x[rH + 5][cH - 2] = ' ';
		//x[rH + 6][cH - 2] = ' ';
		x[rE1 + 7][cE1 - 2] = '|';

		x[rE1 + 7][cE1 - 1] = '_';
		x[rE1 + 7][cE1 + 1] = '_';
		x[rE1 + 7][cE1 + 2] = '_';
		x[rE1 + 7][cE1] = '_';

		LeftLegMoveH1(x, rE1, cE1, countRLEL1);
		RightLegMoveH1(x, rE1, cE1, countRLEL1);

	}

}

void DynamicEnemy(char x[][138], int& cE1, int& rE1, int CounterUntilStop, int& countRLEL1, int rEG1, int cEG1, int countG1, int GetOut)
{
	if (CounterUntilStop >= 21 && CounterUntilStop < 48 && (GetOut == 0 || GetOut == 3))
	{
		cE1++;
		countRLEL1++;

	}
}

void StaticGunShot2(char x[][138], int rE2, int cE2, int& rEG2, int& cEG2, int& countG2, int CounterUntilStop, int GetOut)
{
	/*if (countG1 % 2 != 0)
	{
		rEG1 = rE1;
		cEG1 = cE1;

	}*/

	if (CounterUntilStop >= 44 && (GetOut == 0 || GetOut == 3))
	{
		x[rEG2 + 5][cEG2 + 13] = '=';
	}

}

void DynamicGunShot2(char x[][138], int& rE2, int& cE2, int& rEG2, int& cEG2, int& countG2, int CounterUntilStop, int rH, int cH, int& shoot1, int GetOut, int& DelayShot, int& DeathT)
{

	int breakable = 0;
	breakable = 0;

	if (CounterUntilStop >= 44 && (GetOut == 0 || GetOut == 3))
	{
		cEG2 += 3;
	}

	if (cEG2 > 95 && CounterUntilStop >= 44 && (GetOut == 0 || GetOut == 3))
	{
		cEG2 = cE2;
	}


	/*if (CounterUntilStop >= 44 && (GetOut == 0 || GetOut == 3))
	{
		for (int r = rH, i = 0; i < 6; i++, r++)
		{
			for (int c = cH - 3, j = 0; j < 8; j++, c++)
			{
				if (rEG2 == r && cEG2 == c)
				{
					shoot1++;
					cEG2 = cE2 + 13;
					breakable = 1;
					break;
				}
			}
			if (breakable == 1)
			{
				break;
			}

		}

	}*/

	if (CounterUntilStop >= 44 && (GetOut == 0 || GetOut == 3))
	{
		for (int r = rH, i = 0; i < 12; i++, r++)
		{
			for (int c = cH - 4, j = 0; j < 8; j++, c++)
			{
				if (x[r][c] == '=')
				{
					DeathT = 3;
					shoot1++;
					cEG2 = cE2;
					breakable = 1;
					break;
				}
				if (breakable == 1)
				{
					break;
				}
			}

		}

	}



}

void StaticEnemy2(char x[][2000], int cE2, int rE2, int CounterUntilStop, int countRLEL2, int Reload, int ActionReload, int level, int rB, int cB)
{

	if (CounterUntilStop >= 44)
	{


		x[rE2][cE2 - 2] = '_';
		x[rE2][cE2 - 3] = '/';
		x[rE2 + 1][cE2 - 3] = '\\';
		x[rE2 - 1][cE2 - 2] = '_';
		x[rE2 - 1][cE2 - 1] = '_';
		x[rE2 - 1][cE2] = '_';
		x[rE2 - 1][cE2 + 1] = '_';
		x[rE2 - 1][cE2 + 2] = '_';
		x[rE2 - 1][cE2 + 3] = '_';
		x[rE2][cE2 + 3] = '_';
		x[rE2][cE2 + 4] = '\\';
		x[rE2 + 1][cE2 + 4] = '/';



		x[rE2][cE2 - 1] = '_';
		x[rE2][cE2] = 21;
		x[rE2][cE2 + 1] = '_';
		x[rE2][cE2 + 2] = '_';


		{
			x[rE2 + 2][cE2] = 127;
			x[rE2 + 2][cE2 + 2] = 127;

			x[rE2 + 2][cE2 + 1] = ' ';
			x[rE2 + 2][cE2 - 1] = ' ';
		}

		x[rE2 + 1][cE2 - 2] = '/';
		x[rE2 + 1][cE2 + 3] = '\\';

		x[rE2 + 2][cE2 - 2] = '|';
		x[rE2 + 2][cE2 + 3] = '|';

		x[rE2 + 3][cE2 - 2] = '\\';
		x[rE2 + 3][cE2 + 3] = '/';

		x[rE2 + 3][cE2 - 1] = '_';
		x[rE2 + 3][cE2] = '_';
		x[rE2 + 3][cE2 + 1] = '^';
		x[rE2 + 3][cE2 + 2] = '_';

		x[rE2 + 4][cE2 - 2] = '_';
		x[rE2 + 4][cE2 - 1] = '/';
		x[rE2 + 4][cE2 + 2] = '/';
		x[rE2 + 4][cE2 + 3] = '_';

		if (countRLEL2 == 0)
		{


			x[rE2 + 6][cE2 + 4] = '\\';	//RIGHT HAND
			x[rE2 + 6][cE2 + 5] = '_';
			x[rE2 + 6][cE2 + 6] = '_';
			x[rE2 + 6][cE2 + 7] = '/';
			x[rE2 + 5][cE2 + 8] = '_';
			x[rE2 + 4][cE2 + 7] = '_';
			x[rE2 + 5][cE2 + 5] = '\\';
			x[rE2 + 5][cE2 + 6] = '/';
			x[rE2 + 4][cE2 + 4] = '_';

			x[rE2 + 4][cE2 + 7] = '_';	//GUN
			x[rE2 + 4][cE2 + 8] = '_';
			x[rE2 + 4][cE2 + 9] = '_';
			x[rE2 + 4][cE2 + 10] = '_';
			x[rE2 + 4][cE2 + 11] = '_';
			x[rE2 + 4][cE2 + 12] = '_';
			x[rE2 + 5][cE2 + 13] = '|';
			x[rE2 + 5][cE2 + 12] = '_';
			x[rE2 + 5][cE2 + 11] = '_';
			x[rE2 + 5][cE2 + 10] = '_';
			x[rE2 + 6][cE2 + 9] = '/';
			x[rE2 + 6][cE2 + 8] = '_';

		}
		if (countRLEL2 % 2 != 0)
		{
			x[rE2 + 6][cE2 + 4] = '_';	//RIGHT HAND
			x[rE2 + 6][cE2 + 3] = ' ';
			x[rE2 + 5][cE2 + 3] = '/';
			x[rE2 + 6][cE2 + 5] = '_';
			x[rE2 + 6][cE2 + 7] = ' ';
			x[rE2 + 6][cE2 + 6] = ' ';//
			x[rE2 + 6][cE2 + 8] = ' ';
			x[rE2 + 4][cE2 + 7] = '_';
			x[rE2 + 5][cE2 + 5] = '_';
			x[rE2 + 5][cE2 + 6] = ' ';
			x[rE2 + 5][cE2 + 7] = ' ';
			x[rE2 + 4][cE2 + 4] = ' ';
			x[rE2 + 5][cE2 + 4] = '_';
			x[rE2 + 4][cE2 + 7] = ' ';

			x[rE2 + 5][cE2 + 6] = ' ';	//GUN
			x[rE2 + 6][cE2 + 6] = '/';
			x[rE2 + 5][cE2 + 7] = '_';
			x[rE2 + 5][cE2 + 8] = '_';
			x[rE2 + 5][cE2 + 9] = '_';
			x[rE2 + 5][cE2 + 10] = '_';
			x[rE2 + 5][cE2 + 11] = '_';
			x[rE2 + 6][cE2 + 12] = '|';
			x[rE2 + 6][cE2 + 11] = '_';
			x[rE2 + 6][cE2 + 10] = '_';
			x[rE2 + 6][cE2 + 9] = '_';
			x[rE2 + 7][cE2 + 8] = '/';
			x[rE2 + 7][cE2 + 7] = '_';
			x[rE2 + 6][cE2 + 7] = ' ';
			x[rE2 + 7][cE2 + 6] = '|';



		}
		else
		{
			x[rE2 + 6][cE2 + 4] = '\\';	//RIGHT HAND
			x[rE2 + 6][cE2 + 5] = '_';
			x[rE2 + 6][cE2 + 6] = '_';
			x[rE2 + 6][cE2 + 7] = '/';
			x[rE2 + 5][cE2 + 8] = '_';
			x[rE2 + 4][cE2 + 7] = '_';
			x[rE2 + 5][cE2 + 5] = '\\';
			x[rE2 + 5][cE2 + 6] = '/';
			x[rE2 + 4][cE2 + 4] = '_';

			x[rE2 + 4][cE2 + 7] = '_';	//GUN
			x[rE2 + 4][cE2 + 8] = '_';
			x[rE2 + 4][cE2 + 9] = '_';
			x[rE2 + 4][cE2 + 10] = '_';
			x[rE2 + 4][cE2 + 11] = '_';
			x[rE2 + 4][cE2 + 12] = '_';
			x[rE2 + 5][cE2 + 13] = '|';
			x[rE2 + 5][cE2 + 12] = '_';
			x[rE2 + 5][cE2 + 11] = '_';
			x[rE2 + 5][cE2 + 10] = '_';
			x[rE2 + 6][cE2 + 9] = '/';
			x[rE2 + 6][cE2 + 8] = '_';



		}

		//LeftHandMoveH1(x, rE2, cE2, countRLEL2, Reload, ActionReload, level, rB, cB);

		//x[rH + 5][cH + 3] = ' ';	   
		//x[rH + 6][cH + 3] = '|';	   
		x[rE2 + 7][cE2 + 3] = '|';

		//x[rH + 5][cH - 2] = ' ';
		//x[rH + 6][cH - 2] = ' ';
		x[rE2 + 7][cE2 - 2] = '|';

		x[rE2 + 7][cE2 - 1] = '_';
		x[rE2 + 7][cE2 + 1] = '_';
		x[rE2 + 7][cE2 + 2] = '_';
		x[rE2 + 7][cE2] = '_';

		LeftLegMoveH1(x, rE2, cE2, countRLEL2);
		RightLegMoveH1(x, rE2, cE2, countRLEL2);

	}

}

void DynamicEnemy2(char x[][138], int& cE2, int& rE2, int CounterUntilStop, int& countRLEL2, int rEG2, int cEG2, int countG2, int GetOut)
{
	if (CounterUntilStop >= 44 && CounterUntilStop <= 51 && (GetOut == 0 || GetOut == 3))
	{
		cE2++;
		countRLEL2++;

	}
}

void StaticCar2(char x[][138], int c, int r, int cH, int rH, int level, int sarena, int& ratio1, int& flagC2)
{
	if (ratio1 == 2 && flagC2 == 1)
	{


		x[r][c - 1] = '_';
		x[r][c - 2] = '_';
		x[r][c] = '_';
		x[r][c + 1] = '_';
		x[r][c + 2] = '_';

		x[r + 1][c - 1] = '_';
		x[r + 1][c - 2] = '_';
		x[r + 1][c] = 179;
		x[r + 1][c + 1] = '_';
		x[r + 1][c + 2] = '_';

		x[r + 1][c + 3] = 179;
		x[r + 1][c - 3] = 179;

		x[r + 1][c + 4] = '_';
		x[r + 1][c - 4] = '_';


		x[r + 2][c + 6] = '\\';
		x[r + 3][c + 8] = '\\';
		x[r + 3][c + 9] = '_';
		x[r + 3][c + 10] = '_';
		x[r + 3][c + 11] = '_';
		x[r + 3][c + 12] = '_';
		x[r + 3][c + 13] = '_';
		x[r + 3][c + 14] = '_';
		x[r + 4][c + 15] = 179;

		x[r + 2][c - 6] = '/';
		x[r + 3][c - 8] = '/';
		x[r + 4][c - 10] = '/';
		x[r + 4][c - 11] = '_';
		x[r + 4][c - 12] = '_';
		x[r + 4][c - 13] = '_';
		x[r + 4][c - 14] = '_';
		x[r + 4][c - 15] = '_';
		x[r + 4][c - 16] = '_';
		x[r + 4][c - 17] = '_';
		x[r + 4][c - 18] = '_';
		x[r + 5][c - 19] = '/';

		x[r + 5][c - 18] = '_';
		x[r + 5][c - 17] = '_';
		x[r + 5][c - 16] = '/';
		x[r + 6][c - 19] = '\\';
		x[r + 7][c - 19] = 179;
		x[r + 8][c - 18] = '\\';
		x[r + 8][c - 17] = '_';
		x[r + 8][c - 16] = '_';
		x[r + 8][c - 15] = '_';
		x[r + 8][c - 14] = '_';


		x[r + 8][c - 13] = '|';						//el3agala LEFT
		x[r + 7][c - 13] = '/';
		x[r + 6][c - 12] = '_';
		x[r + 6][c - 11] = '_';
		x[r + 6][c - 10] = '_';
		x[r + 7][c - 9] = '\\';
		x[r + 8][c - 9] = '|';




		x[r + 8][c - 8] = '_';
		x[r + 8][c - 7] = '_';
		x[r + 8][c - 6] = '_';
		x[r + 8][c - 5] = '_';
		x[r + 8][c - 4] = '_';
		x[r + 8][c - 3] = '_';
		x[r + 8][c - 2] = '_';
		x[r + 8][c - 1] = '_';
		x[r + 8][c] = '_';
		x[r + 8][c + 1] = '_';
		x[r + 8][c + 2] = '_';
		x[r + 8][c + 3] = '_';
		x[r + 8][c + 4] = '_';
		x[r + 8][c + 5] = '_';
		x[r + 8][c + 6] = '_';
		x[r + 8][c + 7] = '_';


		x[r + 8][c + 8] = '|';						//el3agala RIGHT
		x[r + 7][c + 8] = '/';
		x[r + 6][c + 9] = '_';
		x[r + 6][c + 10] = '_';
		x[r + 6][c + 11] = '_';
		x[r + 7][c + 12] = '\\';
		x[r + 8][c + 12] = '|';





		x[r + 4][c + 14] = '_';
		x[r + 5][c + 13] = '|';
		x[r + 5][c + 14] = '_';


		x[r + 6][c + 14] = '_';
		x[r + 6][c + 13] = '|';


		x[r + 7][c + 15] = 179;
		x[r + 8][c + 16] = '\\';
		x[r + 8][c + 15] = '_';
		x[r + 8][c + 14] = '_';
		x[r + 8][c + 13] = '_';

		x[r + 6][c + 15] = '|';
		x[r + 5][c + 15] = '|';

		//////////////////////INSIDE//////


		x[r + 4][c - 9] = '_';
		x[r + 4][c - 8] = '_';
		x[r + 4][c - 7] = '_';
		x[r + 4][c - 6] = '_';
		x[r + 4][c - 5] = '_';
		x[r + 4][c - 4] = '^';
		x[r + 4][c - 3] = '_';
		x[r + 4][c - 2] = '_';
		x[r + 4][c - 1] = '_';
		x[r + 4][c] = '_';
		x[r + 4][c + 1] = '_';
		x[r + 4][c + 2] = '_';
		x[r + 4][c + 3] = '_';
		x[r + 4][c + 4] = '_';
		x[r + 4][c + 5] = '_';
		x[r + 4][c + 6] = '_';
		x[r + 4][c + 7] = '_';
		x[r + 4][c + 8] = '_';
		x[r + 4][c + 9] = '_';
		x[r + 4][c + 10] = '/';


		x[r + 2][c + 5] = '\\';
		x[r + 3][c + 7] = '\\';

		x[r + 2][c + 4] = '|';
		x[r + 3][c + 4] = '|';
		x[r + 4][c + 4] = '|';


		x[r + 3][c + 3] = '/';
		x[r + 4][c + 3] = '|';

		x[r + 5][c + 2] = 191;

		x[r + 5][c + 3] = '\\';
		x[r + 6][c + 4] = 179;
		x[r + 7][c + 4] = 179;

		///////////////FACE INSIDE///

		x[r + 2][c - 3] = '_';
		x[r + 2][c - 4] = '_';
		x[r + 2][c - 5] = '_';
		x[r + 3][c - 2] = 179;
		x[r + 4][c - 2] = 179;

		x[r + 3][c - 6] = 179;
		x[r + 4][c - 6] = 179;

		x[r + 3][c - 5] = '-';
		x[r + 3][c - 4] = '-';

		x[r + 6][c - 2] = 'F';
		x[r + 6][c - 1] = 'B';
		x[r + 6][c] = 'I';
	}

}

void DynamicCar2(char x[][138], int& c, int& r, int& cH, int& rH, int& level, int& sarena, int& lose1, int& DeathT, int& Shoot1, int& ratio1, int& flagC2)
{
	if (ratio1 == 2 && c - 16 >= 0)
	{
		if (x[r][c - 20] == ' ' && x[r + 1][c - 20] == ' ' && x[r + 2][c - 20] == ' ' && x[r + 3][c - 20] == ' ' && x[r + 4][c - 20] == ' ' && x[r + 5][c - 20] == ' ' && x[r + 6][c - 20] == ' ' && x[r + 7][c - 20] == ' ' && x[r + 8][c - 20] == ' ' && x[r + 3][c - 18] == ' ' && x[r + 3][c - 17] == ' ' && x[r + 3][c - 16] == ' ' && x[r + 3][c - 15] == ' ' && x[r + 3][c - 14] == ' ' && x[r + 3][c - 13] == ' ' && x[r + 3][c - 12] == ' ' && x[r + 3][c - 11] == ' ' && x[r + 3][c - 10] == ' ' && x[r + 2][c - 8] == ' ' && x[r + 1][c - 6] == ' ' && x[r][c - 4] == ' ' && x[r][c - 3] == ' ' && x[r - 1][c - 1] == ' ' && x[r - 1][c - 2] == ' ' && x[r - 1][c] == ' ' && x[r - 1][c + 1] == ' ' && x[r - 1][c + 2] == ' ' && x[r - 1][c + 3] == ' ' && x[r][c + 4] == ' ' && x[r + 1][c + 5] == ' ' && x[r + 1][c + 6] == ' ' && x[r + 2][c + 7] == ' ' && x[r + 2][c + 8] == ' ' && x[r + 2][c + 9] == ' ' && x[r + 2][c + 10] == ' ' && x[r + 2][c + 11] == ' ' && x[r + 2][c + 12] == ' ' && x[r + 2][c + 13] == ' ' && x[r + 2][c + 14] == ' ' && x[r + 2][c + 15] == ' ')
		{

			if (sarena % 2 == 0 && flagC2 == 1)
			{
				x[r + 1][c - 1] = 219;
				x[r + 1][c - 2] = 219;

				x[r + 1][c + 1] = '_';
				x[r + 1][c + 2] = '_';


				//elgwa el3agala  LEFT
				x[r + 7][c - 11] = 179;
				x[r + 8][c - 10] = '\\';
				x[r + 8][c - 12] = ' ';

				//elgwa el3agala  RIGHT
				x[r + 7][c + 10] = 179;
				x[r + 8][c + 11] = '\\';
				x[r + 8][c + 9] = ' ';


			}
			else if (sarena % 2 != 0 && flagC2 == 1)
			{
				x[r + 1][c + 1] = 219;
				x[r + 1][c + 2] = 219;

				x[r + 1][c - 1] = '_';
				x[r + 1][c - 2] = '_';


				//elgwa el3agala  LEFT
				x[r + 7][c - 11] = ' ';
				x[r + 8][c - 10] = '\\';
				x[r + 8][c - 12] = '/';

				//elgwa el3agala  RIGHT
				x[r + 7][c + 10] = ' ';
				x[r + 8][c + 11] = '\\';
				x[r + 8][c + 9] = '/';

			}

			flagC2 = 1;
			c -= 6;

		}

		else if ((x[r][c - 20] != ' ' || x[r + 1][c - 20] != ' ' || x[r + 2][c - 20] != ' ' || x[r + 3][c - 20] != ' ' || x[r + 4][c - 20] != ' ' || x[r + 5][c - 20] != ' ' || x[r + 6][c - 20] != ' ' || x[r + 7][c - 20] != ' ' || x[r + 8][c - 20] != ' ' || x[r + 3][c - 18] != ' ' || x[r + 3][c - 17] != ' ' || x[r + 3][c - 16] != ' ' || x[r + 3][c - 15] != ' ' || x[r + 3][c - 14] != ' ' || x[r + 3][c - 13] != ' ' || x[r + 3][c - 12] != ' ' || x[r + 3][c - 11] != ' ' || x[r + 3][c - 10] != ' ' || x[r + 2][c - 8] != ' ' || x[r + 1][c - 6] != ' ' || x[r][c - 4] != ' ' || x[r][c - 3] != ' ' || x[r - 1][c - 1] != ' ' || x[r - 1][c - 2] != ' ' || x[r - 1][c] != ' ' || x[r - 1][c + 1] != ' ' || x[r - 1][c + 2] != ' ' || x[r - 1][c + 3] != ' ' || x[r][c + 4] != ' ' || x[r + 1][c + 5] != ' ' || x[r + 1][c + 6] != ' ' || x[r + 2][c + 7] != ' ' || x[r + 2][c + 8] != ' ' || x[r + 2][c + 9] != ' ' || x[r + 2][c + 10] != ' ' || x[r + 2][c + 11] != ' ' || x[r + 2][c + 12] != ' ' || x[r + 2][c + 13] != ' ' || x[r + 2][c + 14] != ' ' || x[r + 2][c + 15] == ' ') && flagC2 == 1)
		{
			flagC2 = 0;
			ratio1 = 1;
			cH -= 10;
			c = 75;
			DeathT = 4;
			Shoot1 += 2;

		}
	}

	if (c - 16 <= 0 && ratio1 == 2)
	{
		flagC2 = 0;
	}
}

void StaticPlane2(char x[][138], int r, int c, int rH, int cH, int level, int ratio, int flagP2)
{
	if ((ratio == 2 || ratio == 3) && flagP2 == 1)
	{


		x[r][c] = '/';
		x[r - 1][c + 1] = '/';
		x[r - 2][c + 2] = '/';
		x[r - 3][c + 3] = '/';
		x[r - 4][c + 4] = '/';


		x[r - 2][c + 3] = '_';
		//x[r - 1][c + 2] = '_';
		x[r - 2][c + 4] = '/';
		x[r - 3][c + 5] = '/';
		x[r - 3][c + 4] = '_';
		x[r - 4][c + 5] = '_';


		x[r - 5][c + 4] = '_';
		x[r - 5][c + 3] = '_';
		x[r - 5][c + 2] = '_';
		x[r - 5][c + 1] = '_';
		x[r - 5][c] = '_';
		x[r - 5][c - 1] = '\\';
		x[r - 6][c - 1] = '_';
		x[r - 6][c] = '_';
		x[r - 6][c + 1] = '_';
		x[r - 6][c + 2] = '_';
		x[r - 6][c + 3] = '_';
		x[r - 6][c + 4] = '_';
		x[r - 6][c + 5] = '_';
		x[r - 6][c + 6] = '_';
		x[r - 6][c + 7] = '_';
		x[r - 6][c + 8] = '_';
		x[r - 6][c + 9] = '_';
		x[r - 6][c + 10] = '_';

		x[r - 5][c + 11] = '\\';
		x[r - 4][c + 12] = '\\';
		x[r - 3][c + 13] = '\\';
		x[r - 2][c + 14] = '\\';

		x[r - 5][c + 9] = '\\';
		x[r - 4][c + 10] = '\\';
		x[r - 3][c + 11] = '\\';
		x[r - 3][c + 12] = '_';
		x[r - 2][c + 12] = '\\';
		x[r - 1][c + 13] = '\\';

		x[r - 2][c + 15] = '/';
		x[r - 3][c + 16] = '/';
		x[r - 4][c + 17] = '/';
		x[r - 5][c + 18] = '_';
		x[r - 5][c + 19] = '_';
		x[r - 5][c + 20] = '_';

		x[r - 4][c + 21] = 179;
		x[r - 3][c + 21] = 179;
		x[r - 2][c + 21] = 179;
		x[r - 1][c + 21] = 179;
		x[r][c + 21] = 179;

		x[r][c + 20] = '_';
		x[r][c + 19] = '_';
		x[r][c + 18] = '_';
		x[r][c + 17] = '_';
		x[r][c + 16] = '_';
		x[r][c + 15] = '_';
		x[r][c + 14] = '_';
		x[r][c + 13] = '_';
		x[r][c + 12] = '_';
		x[r][c + 11] = '_';
		x[r][c + 10] = '_';
		x[r][c + 9] = '_';
		x[r][c + 8] = '_';
		x[r][c + 7] = '_';
		x[r][c + 6] = '_';
		x[r][c + 5] = '_';
		x[r][c + 4] = '_';
		x[r][c + 3] = '_';
		x[r][c + 2] = '_';
		x[r][c + 1] = '_';
		//x[r][c] = '_';
		//x[r][c - 1] = '_';
		x[r][c - 2] = '_';
		x[r][c - 3] = '_';
		x[r][c - 4] = '_';
		x[r][c - 5] = '_';
		x[r][c - 6] = '_';
		x[r][c - 7] = '_';
		x[r][c - 8] = '_';
		x[r][c - 9] = '_';
		x[r][c - 10] = '_';
		x[r][c - 11] = '_';
		x[r][c - 12] = '_';
		x[r][c - 13] = '_';
		x[r][c - 14] = '_';
		x[r][c - 15] = '_';
		x[r][c - 16] = '_';

		x[r][c - 1] = 179;
		x[r - 1][c - 1] = 179;
		x[r - 2][c - 1] = 179;

		x[r - 3][c - 2] = '_';
		x[r - 3][c - 2] = '_';
		x[r - 3][c - 3] = '_';

		x[r - 2][c - 4] = '/';
		x[r - 1][c - 5] = '/';
		x[r][c - 6] = '/';


		x[r - 1][c + 14] = '/';
		x[r][c + 13] = '/';


		x[r + 1][c - 17] = '/';
		x[r + 2][c - 18] = '/';

		x[r + 2][c - 17] = '_';
		x[r + 2][c - 16] = '_';
		x[r + 2][c - 15] = '_';
		x[r + 2][c - 14] = '_';
		x[r + 2][c - 13] = '_';
		x[r + 2][c - 12] = '_';
		x[r + 2][c - 11] = '_';
		x[r + 2][c - 10] = '_';
		x[r + 2][c - 9] = '_';
		x[r + 2][c - 8] = '_';
		x[r + 2][c - 7] = '_';
		x[r + 2][c - 6] = '_';
		x[r + 2][c - 5] = '_';
		x[r + 2][c - 4] = '_';
		x[r + 2][c - 3] = '_';
		x[r + 2][c - 2] = '_';
		x[r + 2][c - 1] = '_';
		x[r + 2][c] = '_';
		x[r + 2][c + 1] = '_';
		x[r + 2][c + 2] = '_';
		x[r + 2][c + 3] = '_';
		x[r + 2][c + 4] = '_';
		x[r + 2][c + 5] = '_';
		x[r + 2][c + 6] = '_';
		x[r + 2][c + 7] = '_';
		x[r + 2][c + 8] = '_';
		x[r + 2][c + 9] = '_';
		x[r + 2][c + 10] = '_';
		x[r + 2][c + 11] = '_';
		x[r + 2][c + 12] = '_';
		x[r + 2][c + 13] = '_';
		x[r + 2][c + 14] = '_';
		x[r + 2][c + 15] = '_';
		x[r + 2][c + 16] = '_';
		x[r + 2][c + 17] = '_';
		x[r + 2][c + 18] = '_';
		x[r + 2][c + 19] = '_';
		x[r + 2][c + 20] = '_';
		x[r + 2][c + 21] = '_';
		x[r + 2][c + 22] = '/';
		x[r + 1][c + 22] = '_';
		x[r + 1][c + 21] = 179;

		//Lower Wing
		x[r + 3][c - 6] = '\\';
		x[r + 4][c - 5] = '\\';
		x[r + 4][c - 6] = '_';
		//ROCKETING
		x[r + 5][c - 7] = 34;
		/////////////////////
		x[r + 4][c - 8] = '_';
		x[r + 4][c - 9] = '\\';
		x[r + 3][c - 9] = '_';
		x[r + 3][c - 8] = '_';
		x[r + 3][c - 7] = '_';

		x[r + 5][c - 4] = '\\';
		x[r + 5][c - 3] = '_';
		x[r + 5][c - 2] = '_';
		x[r + 5][c - 1] = 179;
		x[r + 4][c - 1] = 179;
		x[r + 3][c - 1] = 179;

		//INSIDE -->
		x[r + 1][c - 14] = '|';
		x[r + 1][c - 13] = '_';
		x[r + 1][c - 12] = '_';
		x[r + 1][c - 11] = '_';
		x[r + 1][c - 10] = '_';
		x[r + 1][c - 9] = '_';
		x[r + 1][c - 8] = '|';
		x[r + 1][c - 7] = '_';
		x[r + 1][c - 6] = '_';
		x[r + 1][c - 5] = '_';
		x[r + 1][c - 4] = '_';
		x[r + 1][c - 3] = '_';
		x[r + 1][c - 2] = '|';
		x[r + 1][c - 1] = '_';
		x[r + 1][c] = '_';
		x[r + 1][c + 1] = '/';

		//OUTSIDE --->
		x[r + 6][c] = '\\';
		x[r + 7][c + 1] = '\\';

		x[r + 6][c + 2] = '\\';
		x[r + 7][c + 3] = '\\';

		x[r + 5][c + 1] = '_';
		x[r + 7][c + 2] = '_';
		x[r + 6][c + 1] = '_';

		x[r + 7][c] = '_';
		x[r + 7][c - 1] = '_';
		x[r + 7][c - 2] = '_';
		x[r + 8][c - 2] = '\\';
		x[r + 8][c - 1] = '_';
		x[r + 8][c] = '_';
		x[r + 8][c + 1] = '_';
		x[r + 8][c + 2] = '_';
		x[r + 8][c + 3] = '_';
		x[r + 8][c + 4] = '_';
		x[r + 8][c + 5] = '_';
		x[r + 8][c + 6] = '_';
		x[r + 8][c + 7] = '_';
		x[r + 8][c + 8] = '_';

		x[r + 8][c + 9] = '/';
		x[r + 7][c + 10] = '/';
		x[r + 6][c + 11] = '/';
		x[r + 5][c + 12] = '/';
		x[r + 4][c + 13] = '/';
		x[r + 3][c + 14] = '/';

		x[r + 8][c + 7] = '/';
		x[r + 7][c + 8] = '/';
		x[r + 6][c + 9] = '/';
		x[r + 5][c + 10] = '/';
		x[r + 5][c + 11] = '_';
		x[r + 4][c + 11] = '/';
		x[r + 3][c + 12] = '/';

		x[r + 4][c + 1] = 196;
		x[r + 4][c + 2] = 196;
		x[r + 4][c + 3] = 196;
		x[r + 4][c + 4] = 196;
		x[r + 4][c + 5] = 196;
		x[r + 4][c + 6] = 196;
		x[r + 4][c + 7] = 196;
		x[r + 4][c + 8] = 196;
		x[r + 4][c + 9] = 196;

		x[r - 1][c + 5] = 196;
		x[r - 1][c + 6] = 196;
		x[r - 1][c + 7] = 196;
		x[r - 1][c + 8] = 196;
		x[r - 1][c + 9] = 196;
		x[r - 1][c + 10] = 196;

		x[r - 1][c + 7] = 'F';
		x[r - 1][c + 8] = 'B';
		x[r - 1][c + 9] = 'I';

		x[r + 4][c + 4] = 'F';
		x[r + 4][c + 5] = 'B';
		x[r + 4][c + 6] = 'I';

	}

}

void DynamicPlane2(char x[][138], int& r2, int& c2, int& rH, int& cH, int level, int& ratio, int& flagP2)
{
	if (ratio == 2)
	{
		if (c2 < 65)
		{
			r2++;
		}
		c2 -= 9;
		flagP2 = 1;
	}

	if (ratio == 3)
	{
		if (c2 < 45)
		{
			r2++;
		}
		c2 -= 9;
		flagP2 = 1;
	}

	if (c2 - 10 <= 0 && (ratio == 3 || ratio == 2))
	{
		flagP2 = 0;
	}

}

void StaticPlane3(char x[][138], int r, int c, int rH, int cH, int level, int ratio, int flagP22)
{
	if (ratio == 3 && flagP22 == 1)
	{


		x[r][c] = '/';
		x[r - 1][c + 1] = '/';
		x[r - 2][c + 2] = '/';
		x[r - 3][c + 3] = '/';
		x[r - 4][c + 4] = '/';


		x[r - 2][c + 3] = '_';
		//x[r - 1][c + 2] = '_';
		x[r - 2][c + 4] = '/';
		x[r - 3][c + 5] = '/';
		x[r - 3][c + 4] = '_';
		x[r - 4][c + 5] = '_';


		x[r - 5][c + 4] = '_';
		x[r - 5][c + 3] = '_';
		x[r - 5][c + 2] = '_';
		x[r - 5][c + 1] = '_';
		x[r - 5][c] = '_';
		x[r - 5][c - 1] = '\\';
		x[r - 6][c - 1] = '_';
		x[r - 6][c] = '_';
		x[r - 6][c + 1] = '_';
		x[r - 6][c + 2] = '_';
		x[r - 6][c + 3] = '_';
		x[r - 6][c + 4] = '_';
		x[r - 6][c + 5] = '_';
		x[r - 6][c + 6] = '_';
		x[r - 6][c + 7] = '_';
		x[r - 6][c + 8] = '_';
		x[r - 6][c + 9] = '_';
		x[r - 6][c + 10] = '_';

		x[r - 5][c + 11] = '\\';
		x[r - 4][c + 12] = '\\';
		x[r - 3][c + 13] = '\\';
		x[r - 2][c + 14] = '\\';

		x[r - 5][c + 9] = '\\';
		x[r - 4][c + 10] = '\\';
		x[r - 3][c + 11] = '\\';
		x[r - 3][c + 12] = '_';
		x[r - 2][c + 12] = '\\';
		x[r - 1][c + 13] = '\\';

		x[r - 2][c + 15] = '/';
		x[r - 3][c + 16] = '/';
		x[r - 4][c + 17] = '/';
		x[r - 5][c + 18] = '_';
		x[r - 5][c + 19] = '_';
		x[r - 5][c + 20] = '_';

		x[r - 4][c + 21] = 179;
		x[r - 3][c + 21] = 179;
		x[r - 2][c + 21] = 179;
		x[r - 1][c + 21] = 179;
		x[r][c + 21] = 179;

		x[r][c + 20] = '_';
		x[r][c + 19] = '_';
		x[r][c + 18] = '_';
		x[r][c + 17] = '_';
		x[r][c + 16] = '_';
		x[r][c + 15] = '_';
		x[r][c + 14] = '_';
		x[r][c + 13] = '_';
		x[r][c + 12] = '_';
		x[r][c + 11] = '_';
		x[r][c + 10] = '_';
		x[r][c + 9] = '_';
		x[r][c + 8] = '_';
		x[r][c + 7] = '_';
		x[r][c + 6] = '_';
		x[r][c + 5] = '_';
		x[r][c + 4] = '_';
		x[r][c + 3] = '_';
		x[r][c + 2] = '_';
		x[r][c + 1] = '_';
		//x[r][c] = '_';
		//x[r][c - 1] = '_';
		x[r][c - 2] = '_';
		x[r][c - 3] = '_';
		x[r][c - 4] = '_';
		x[r][c - 5] = '_';
		x[r][c - 6] = '_';
		x[r][c - 7] = '_';
		x[r][c - 8] = '_';
		x[r][c - 9] = '_';
		x[r][c - 10] = '_';
		x[r][c - 11] = '_';
		x[r][c - 12] = '_';
		x[r][c - 13] = '_';
		x[r][c - 14] = '_';
		x[r][c - 15] = '_';
		x[r][c - 16] = '_';

		x[r][c - 1] = 179;
		x[r - 1][c - 1] = 179;
		x[r - 2][c - 1] = 179;

		x[r - 3][c - 2] = '_';
		x[r - 3][c - 2] = '_';
		x[r - 3][c - 3] = '_';

		x[r - 2][c - 4] = '/';
		x[r - 1][c - 5] = '/';
		x[r][c - 6] = '/';


		x[r - 1][c + 14] = '/';
		x[r][c + 13] = '/';


		x[r + 1][c - 17] = '/';
		x[r + 2][c - 18] = '/';

		x[r + 2][c - 17] = '_';
		x[r + 2][c - 16] = '_';
		x[r + 2][c - 15] = '_';
		x[r + 2][c - 14] = '_';
		x[r + 2][c - 13] = '_';
		x[r + 2][c - 12] = '_';
		x[r + 2][c - 11] = '_';
		x[r + 2][c - 10] = '_';
		x[r + 2][c - 9] = '_';
		x[r + 2][c - 8] = '_';
		x[r + 2][c - 7] = '_';
		x[r + 2][c - 6] = '_';
		x[r + 2][c - 5] = '_';
		x[r + 2][c - 4] = '_';
		x[r + 2][c - 3] = '_';
		x[r + 2][c - 2] = '_';
		x[r + 2][c - 1] = '_';
		x[r + 2][c] = '_';
		x[r + 2][c + 1] = '_';
		x[r + 2][c + 2] = '_';
		x[r + 2][c + 3] = '_';
		x[r + 2][c + 4] = '_';
		x[r + 2][c + 5] = '_';
		x[r + 2][c + 6] = '_';
		x[r + 2][c + 7] = '_';
		x[r + 2][c + 8] = '_';
		x[r + 2][c + 9] = '_';
		x[r + 2][c + 10] = '_';
		x[r + 2][c + 11] = '_';
		x[r + 2][c + 12] = '_';
		x[r + 2][c + 13] = '_';
		x[r + 2][c + 14] = '_';
		x[r + 2][c + 15] = '_';
		x[r + 2][c + 16] = '_';
		x[r + 2][c + 17] = '_';
		x[r + 2][c + 18] = '_';
		x[r + 2][c + 19] = '_';
		x[r + 2][c + 20] = '_';
		x[r + 2][c + 21] = '_';
		x[r + 2][c + 22] = '/';
		x[r + 1][c + 22] = '_';
		x[r + 1][c + 21] = 179;

		//Lower Wing
		x[r + 3][c - 6] = '\\';
		x[r + 4][c - 5] = '\\';
		x[r + 4][c - 6] = '_';
		//ROCKETING
		x[r + 5][c - 7] = 34;
		/////////////////////
		x[r + 4][c - 8] = '_';
		x[r + 4][c - 9] = '\\';
		x[r + 3][c - 9] = '_';
		x[r + 3][c - 8] = '_';
		x[r + 3][c - 7] = '_';

		x[r + 5][c - 4] = '\\';
		x[r + 5][c - 3] = '_';
		x[r + 5][c - 2] = '_';
		x[r + 5][c - 1] = 179;
		x[r + 4][c - 1] = 179;
		x[r + 3][c - 1] = 179;

		//INSIDE -->
		x[r + 1][c - 14] = '|';
		x[r + 1][c - 13] = '_';
		x[r + 1][c - 12] = '_';
		x[r + 1][c - 11] = '_';
		x[r + 1][c - 10] = '_';
		x[r + 1][c - 9] = '_';
		x[r + 1][c - 8] = '|';
		x[r + 1][c - 7] = '_';
		x[r + 1][c - 6] = '_';
		x[r + 1][c - 5] = '_';
		x[r + 1][c - 4] = '_';
		x[r + 1][c - 3] = '_';
		x[r + 1][c - 2] = '|';
		x[r + 1][c - 1] = '_';
		x[r + 1][c] = '_';
		x[r + 1][c + 1] = '/';

		//OUTSIDE --->
		x[r + 6][c] = '\\';
		x[r + 7][c + 1] = '\\';

		x[r + 6][c + 2] = '\\';
		x[r + 7][c + 3] = '\\';

		x[r + 5][c + 1] = '_';
		x[r + 7][c + 2] = '_';
		x[r + 6][c + 1] = '_';

		x[r + 7][c] = '_';
		x[r + 7][c - 1] = '_';
		x[r + 7][c - 2] = '_';
		x[r + 8][c - 2] = '\\';
		x[r + 8][c - 1] = '_';
		x[r + 8][c] = '_';
		x[r + 8][c + 1] = '_';
		x[r + 8][c + 2] = '_';
		x[r + 8][c + 3] = '_';
		x[r + 8][c + 4] = '_';
		x[r + 8][c + 5] = '_';
		x[r + 8][c + 6] = '_';
		x[r + 8][c + 7] = '_';
		x[r + 8][c + 8] = '_';

		x[r + 8][c + 9] = '/';
		x[r + 7][c + 10] = '/';
		x[r + 6][c + 11] = '/';
		x[r + 5][c + 12] = '/';
		x[r + 4][c + 13] = '/';
		x[r + 3][c + 14] = '/';

		x[r + 8][c + 7] = '/';
		x[r + 7][c + 8] = '/';
		x[r + 6][c + 9] = '/';
		x[r + 5][c + 10] = '/';
		x[r + 5][c + 11] = '_';
		x[r + 4][c + 11] = '/';
		x[r + 3][c + 12] = '/';

		x[r + 4][c + 1] = 196;
		x[r + 4][c + 2] = 196;
		x[r + 4][c + 3] = 196;
		x[r + 4][c + 4] = 196;
		x[r + 4][c + 5] = 196;
		x[r + 4][c + 6] = 196;
		x[r + 4][c + 7] = 196;
		x[r + 4][c + 8] = 196;
		x[r + 4][c + 9] = 196;

		x[r - 1][c + 5] = 196;
		x[r - 1][c + 6] = 196;
		x[r - 1][c + 7] = 196;
		x[r - 1][c + 8] = 196;
		x[r - 1][c + 9] = 196;
		x[r - 1][c + 10] = 196;

		x[r - 1][c + 7] = 'F';
		x[r - 1][c + 8] = 'B';
		x[r - 1][c + 9] = 'I';

		x[r + 4][c + 4] = 'F';
		x[r + 4][c + 5] = 'B';
		x[r + 4][c + 6] = 'I';

	}

}

void DynamicPlane3(char x[][138], int& r3, int& c3, int& rH, int& cH, int level, int& ratio, int& flagP22)
{
	if (ratio == 3)
	{
		if (c3 < 45)
		{
			r3++;
		}
		c3 -= 9;
		flagP22 = 1;
	}
	if (c3 - 10 <= 0 && ratio == 3)
	{
		flagP22 = 0;
	}

}

void StaticSkate(char x[][138], int r, int c, int rH, int cH, int& SkateIn)
{


	if (cH < 35 && SkateIn == 0)
	{


		x[r][c - 8] = '_';
		x[r][c - 7] = '_';
		x[r][c - 6] = '_';
		x[r][c - 5] = '_';
		x[r][c - 4] = '_';
		x[r][c - 3] = '_';
		x[r][c - 2] = '_';
		x[r][c - 1] = '_';
		x[r][c] = '_';
		x[r][c + 1] = '_';
		x[r][c + 2] = '_';
		x[r][c + 3] = '_';
		x[r][c + 4] = '_';
		x[r][c + 5] = '_';
		x[r][c + 6] = '_';
		x[r][c + 7] = '_';
		x[r][c + 8] = '_';

		x[r][c - 9] = '\\';
		x[r - 1][c - 10] = '_';
		x[r][c - 11] = 179;
		x[r + 1][c - 10] = '\\';
		x[r + 1][c - 9] = '_';
		x[r + 1][c - 8] = '_';
		x[r + 1][c - 7] = '_';
		x[r + 2][c - 6] = '\\';
		x[r + 2][c - 5] = '_';
		x[r + 2][c - 4] = '/';
		x[r + 1][c - 3] = '_';
		x[r + 1][c - 2] = '|';
		x[r + 1][c - 1] = '_';
		x[r + 1][c] = '_';
		x[r + 1][c + 1] = '_';
		x[r + 1][c + 2] = '|';
		x[r + 1][c + 3] = '_';
		x[r + 2][c + 4] = '\\';
		x[r + 2][c + 5] = '_';
		x[r + 2][c + 6] = '/';
		x[r + 1][c + 7] = '_';
		x[r + 1][c + 8] = '_';
		x[r + 1][c + 9] = '_';
		x[r][c + 9] = '/';
		x[r - 1][c + 10] = '_';
		x[r][c + 11] = 179;
		x[r + 1][c + 10] = '/';

		if (cH < 24 && SkateIn == 0)
		{
			x[r - 1][c - 5] = 'S';
			x[r - 1][c - 4] = 'K';
			x[r - 1][c - 3] = 'A';
			x[r - 1][c - 2] = 'T';
			x[r - 1][c - 1] = 'E';
			x[r - 1][c] = ' ';
			x[r - 1][c + 1] = 'B';
			x[r - 1][c + 2] = 'O';
			x[r - 1][c + 3] = 'A';
			x[r - 1][c + 4] = 'R';
			x[r - 1][c + 5] = 'D';



		}

		if (cH >= 24 && rH == 36 && SkateIn == 0)
		{
			x[rH - 1][cH + 6] = 'T';
			x[rH - 1][cH + 7] = 'A';
			x[rH - 1][cH + 8] = 'P';
			x[rH - 1][cH + 9] = ' ';
			x[rH - 1][cH + 10] = 'E';
			x[rH - 1][cH + 11] = ' ';
			x[rH - 1][cH + 12] = 'T';
			x[rH - 1][cH + 13] = 'O';
			x[rH - 1][cH + 14] = ' ';
			x[rH - 1][cH + 15] = 'E';
			x[rH - 1][cH + 16] = 'Q';
			x[rH - 1][cH + 17] = 'U';
			x[rH - 1][cH + 18] = 'I';
			x[rH - 1][cH + 19] = 'P';
		}
	}

	if (SkateIn == 1)
	{


		x[r][c - 8] = '_';
		x[r][c - 7] = '_';
		x[r][c - 6] = '_';
		x[r][c - 5] = '_';
		x[r][c - 4] = '_';
		x[r][c - 3] = '_';
		x[r][c - 2] = '_';
		x[r][c - 1] = '_';
		x[r][c] = '_';
		x[r][c + 1] = '_';
		x[r][c + 2] = '_';
		x[r][c + 3] = '_';
		x[r][c + 4] = '_';
		x[r][c + 5] = '_';
		x[r][c + 6] = '_';
		x[r][c + 7] = '_';
		x[r][c + 8] = '_';

		x[r][c - 9] = '\\';
		x[r - 1][c - 10] = '_';
		x[r][c - 11] = 179;
		x[r + 1][c - 10] = '\\';
		x[r + 1][c - 9] = '_';
		x[r + 1][c - 8] = '_';
		x[r + 1][c - 7] = '_';
		x[r + 2][c - 6] = '\\';
		x[r + 2][c - 5] = '_';
		x[r + 2][c - 4] = '/';
		x[r + 1][c - 3] = '_';
		x[r + 1][c - 2] = '|';
		x[r + 1][c - 1] = '_';
		x[r + 1][c] = '_';
		x[r + 1][c + 1] = '_';
		x[r + 1][c + 2] = '|';
		x[r + 1][c + 3] = '_';
		x[r + 2][c + 4] = '\\';
		x[r + 2][c + 5] = '_';
		x[r + 2][c + 6] = '/';
		x[r + 1][c + 7] = '_';
		x[r + 1][c + 8] = '_';
		x[r + 1][c + 9] = '_';
		x[r][c + 9] = '/';
		x[r - 1][c + 10] = '_';
		x[r][c + 11] = 179;
		x[r + 1][c + 10] = '/';
	}

}

void CheckTrap(char x[][138], int& rH, int& cH, int& DeathT, int& shoot1, int& rR, int& cR, int& RopeIn, int& tap4)
{
	if (RopeIn == 0 && x[rH + 11][cH - 2] == '/' || x[rH + 11][cH - 2] == '\\' || x[rH + 11][cH - 1] == '/' || x[rH + 11][cH - 1] == '\\' || x[rH + 11][cH] == '/' || x[rH + 11][cH] == '\\' || x[rH + 11][cH + 1] == '/' || x[rH + 11][cH + 1] == '\\' || x[rH + 11][cH + 2] == '/' || x[rH + 11][cH + 2] == '\\' || x[rH + 11][cH + 3] == '/' || x[rH + 11][cH + 3] == '\\' || x[rH + 11][cH + 4] == '/' || x[rH + 11][cH + 4] == '\\')
	{

		shoot1 += 4;
		rH -= 14;
		DeathT = 6;
		cH -= 5;

	}

	if (cH > (cR - 16) && cH < (cR + 4) && RopeIn == 0)
	{
		x[rH - 1][cH + 6] = 'T';
		x[rH - 1][cH + 7] = 'A';
		x[rH - 1][cH + 8] = 'P';
		x[rH - 1][cH + 9] = ' ';
		x[rH - 1][cH + 10] = 'E';
		x[rH - 1][cH + 11] = ' ';
		x[rH - 1][cH + 12] = 'T';
		x[rH - 1][cH + 13] = 'O';
		x[rH - 1][cH + 14] = ' ';
		x[rH - 1][cH + 15] = 'R';
		x[rH - 1][cH + 16] = 'I';
		x[rH - 1][cH + 17] = 'D';
		x[rH - 1][cH + 18] = 'E';
		tap4 = 1;
	}
	else
	{
		tap4 = 0;
	}
}

void MyStaticShot(char x[][138], int rH, int cH, int& rMS1, int& cMS1, int& rMS2, int& cMS2, int countRLHL1, int& countMyShot, int& ClickShot, int& WhichShot, int &rB)
{

	if (countRLHL1 % 2 == 0 && ClickShot >= 1)
	{
		x[rMS1 + 5][cMS1 + 14] = 22;
		x[rH + 6][cH + 12] = '1';
	}
	else if (countRLHL1 % 2 != 0 && ClickShot >= 1)
	{
		x[rMS1 + 6][cMS1 + 13] = 22;
		x[rH + 7][cH + 11] = '1';
	}


	if (countRLHL1 % 2 == 0 && ClickShot == 2)
	{
		x[rMS2 + 5][cMS2 + 14] = 22;
		x[rH + 6][cH + 12] = '0';

	}
	else if (countRLHL1 % 2 != 0 && ClickShot == 2)
	{
		x[rMS2 + 6][cMS2 + 13] = 22;
		x[rH + 7][cH + 11] = '0';

	}


}

void MyDynamicShot(char x[][138], int rH, int cH, int& rMS1, int& cMS1, int& rMS2, int& cMS2, int countRLHL1, int& countMyShot, int& ClickShot, int& Reload, int& ReloadAction, int& rB, int& ct, int& gotshot, int cBB, int rBB, int& WhichShot)
{


	if (cMS1 + 20 <= 137 && ClickShot >= 1)
	{
		for (int a = 0; a < 16; a++)
		{
			cMS1++;

			if (x[rMS1 + 5][cMS1 + 15] != ' ' && rMS1 + 5 >= rBB + 1 && rMS1 + 5 < rBB + 6 && cMS1 >= 0 && cMS1 <= 137)
			{
				x[28][83] = 'H';
				x[28][84] = 'E';
				x[28][85] = 'A';
				x[28][86] = 'D';
				x[28][87] = 'S';
				x[28][88] = 'H';
				x[28][89] = 'O';
				x[28][90] = 'T';
				x[28][91] = '!';

				gotshot += 2;
				cMS1 = 138;
				rMS1 = 46;
			}

			if (x[rMS1 + 5][cMS1 + 15] != ' ' && rMS1 + 5 >= 34 && rMS1 + 5 <= 40 && cMS1 >= 0 && cMS1 <= 137)
			{
				gotshot += 1;
				cMS1 = 137;
				rMS1 = 46;
			}

		}


	}
	else if (cMS1 + 20 > 137 && ClickShot >= 1)
	{
		cMS1 = 137;
		rMS1 = 46;

	}


	if (ClickShot >= 1)
	{

		if (countRLHL1 % 2 == 0)
		{
			x[rH + 6][cH + 12] = '1';
		}
		else
		{
			x[rH + 7][cH + 11] = '1';
		}
	}

	if (cMS2 + 20 <= 137 && ClickShot == 2)
	{
		for (int a = 0; a < 16; a++)
		{
			cMS2++;

			if (x[rMS2 + 5][cMS2 + 15] != ' ' && rMS2 + 5 >= rBB + 1 && rMS2 + 5 < rBB + 6 && cMS2 >= 0 && cMS2 <= 137)
			{
				x[28][83] = 'H';
				x[28][84] = 'E';
				x[28][85] = 'A';
				x[28][86] = 'D';
				x[28][87] = 'S';
				x[28][88] = 'H';
				x[28][89] = 'O';
				x[28][90] = 'T';
				x[28][91] = '!';
				gotshot += 2;
				cMS2 = 138;
				rMS2 = 46;
			}

			if (x[rMS2 + 5][cMS2 + 15] != ' ' && rMS2 + 5 >= 34 && rMS2 + 5 <= 40 && cMS2 >= 0 && cMS2 <= 137)
			{
				gotshot += 1;
				cMS2 = 137;
				rMS2 = 46;
			}
		}

	}
	else if (cMS2 + 20 > 137 && ClickShot == 2)
	{
		cMS2 = 137;
		rMS2 = 46;

	}



	if (ClickShot == 2)
	{

		Reload = 1;

		if (countRLHL1 % 2 == 0)
		{
			x[rH + 6][cH + 12] = '0';
		}
		else
		{
			x[rH + 7][cH + 11] = '0';
		}
		//ReloadAction = 2;

		if (ct >= 2)
		{
			ReloadAction = 2;
		}


	}

	if (cMS2 + 20 > 137 && ClickShot == 2)
	{
		ClickShot = 0;
		Reload = 0;
		ReloadAction = 1;

		if (countRLHL1 % 2 == 0)
		{
			x[rH + 6][cH + 12] = '2';
		}
		else
		{
			x[rH + 7][cH + 11] = '2';
		}
		//Reload = 0;
	}











}

void StaticBigBoss(char x[][138], int rH, int cH, int r, int c, int win)
{
	if (win == 0)
	{
		x[r][c - 3] = '_';
		x[r][c - 5] = '/';
		x[r - 1][c - 4] = '_';
		x[r - 1][c - 3] = '_';
		x[r - 1][c - 2] = '_';
		x[r - 1][c - 1] = '_';
		x[r - 1][c] = '_';
		x[r - 1][c + 1] = '_';
		x[r - 1][c + 2] = '_';
		x[r - 1][c + 3] = '_';
		x[r - 1][c + 4] = '_';
		x[r][c + 5] = '\\';
		x[r + 1][c + 4] = '\\';
		x[r + 1][c + 5] = '/';


		x[r + 1][c - 4] = '/';
		x[r + 1][c - 5] = '\\';
		x[r][c - 4] = '_';
		x[r][c - 3] = '_';
		x[r][c - 2] = '_';
		x[r][c - 1] = '7';
		x[r][c] = '7';
		x[r][c + 1] = '7';
		x[r][c + 2] = '_';
		x[r][c + 3] = '_';
		x[r][c + 4] = '_';

		x[r + 2][c - 4] = '|';
		x[r + 3][c - 4] = '|';
		x[r + 4][c - 4] = '|';
		x[r + 2][c + 4] = '|';
		x[r + 3][c + 4] = '|';
		x[r + 4][c + 4] = '|';

		x[r + 5][c - 4] = '\\';
		x[r + 5][c - 3] = '_';
		x[r + 5][c - 2] = '_';
		x[r + 5][c - 1] = '_';
		x[r + 5][c] = '_';
		x[r + 5][c + 1] = '_';
		x[r + 5][c + 2] = '_';
		x[r + 5][c + 3] = '_';
		x[r + 5][c + 4] = '/';

		x[r + 2][c - 2] = '_';
		x[r + 2][c + 1] = '_';

		x[r + 3][c - 1] = '_';
		x[r + 4][c - 2] = 179;
		//x[r + 4][c - 1] = '/';
		x[r + 4][c] = 179;

		x[r + 6][c + 3] = '/';
		x[r + 6][c + 4] = '_';
		x[r + 6][c - 3] = '/';
		x[r + 6][c - 4] = '_';
		x[r + 6][c - 4] = '_';
		x[r + 6][c - 5] = '_';
		x[r + 10][c - 4] = '|';
		x[r + 9][c - 4] = '|';
		x[r + 9][c - 5] = '_';
		x[r + 9][c - 6] = '_';
		x[r + 9][c - 7] = '_';
		x[r + 9][c - 8] = '_';
		x[r + 9][c - 9] = '_';
		x[r + 9][c - 10] = '_';
		x[r + 9][c - 11] = '_';
		x[r + 11][c - 4] = '|';
		x[r + 12][c - 4] = '|';
		x[r + 10][c + 4] = '|';
		x[r + 9][c + 4] = '|';
		x[r + 11][c + 4] = '|';
		x[r + 12][c + 4] = '|';
		//x[r + 12][c - 3] = '_';		
		//x[r + 12][c - 2] = '_';		
		//x[r + 12][c - 1] = '_';		
		//x[r + 12][c] = '_';		
		//x[r + 12][c + 1] = '_';		
		//x[r + 12][c + 2] = '_';		
		//x[r + 12][c + 3] = '_';		

		x[r + 7][c - 6] = '/';
		x[r + 7][c - 7] = '_';
		x[r + 7][c - 8] = '_';
		x[r + 7][c - 9] = '_';
		x[r + 7][c - 10] = '_';
		x[r + 7][c - 11] = '/';
		x[r + 6][c - 10] = '/';
		x[r + 5][c - 9] = '_';
		x[r + 6][c - 8] = 179;
		x[r + 6][c - 7] = '_';
		x[r + 6][c - 6] = 179;
		x[r + 5][c - 6] = 179;
		x[r + 4][c - 7] = '_';
		x[r + 4][c - 8] = '_';
		x[r + 4][c - 9] = '_';
		x[r + 4][c - 10] = '_';
		x[r + 4][c - 11] = '_';
		x[r + 5][c - 12] = '/';
		x[r + 6][c - 13] = '/';
		x[r + 7][c - 14] = '/';
		x[r + 7][c - 15] = '_';
		x[r + 7][c - 16] = '_';
		x[r + 7][c - 17] = '_';
		x[r + 7][c - 18] = '_';
		x[r + 7][c - 19] = '_';
		x[r + 7][c - 20] = '_';
		x[r + 7][c - 21] = '_';
		x[r + 7][c - 22] = '_';
		x[r + 7][c - 23] = '\\';
		x[r + 7][c - 24] = '/';
		x[r + 7][c - 25] = '_';
		x[r + 7][c - 26] = '_';
		x[r + 7][c - 27] = '_';
		x[r + 8][c - 27] = 179;
		x[r + 9][c - 27] = 179;
		x[r + 7][c - 28] = '_';
		x[r + 7][c - 29] = '_';
		x[r + 7][c - 30] = '_';
		x[r + 8][c - 31] = '|';
		x[r + 9][c - 31] = '|';
		x[r + 9][c - 30] = '_';
		x[r + 9][c - 29] = '_';
		x[r + 9][c - 28] = '_';
		x[r + 9][c - 27] = 179;
		x[r + 9][c - 26] = '_';
		x[r + 9][c - 25] = '_';
		x[r + 9][c - 24] = '_';
		x[r + 9][c - 23] = '_';
		x[r + 9][c - 22] = '_';
		x[r + 9][c - 21] = '_';
		x[r + 9][c - 20] = '_';
		x[r + 9][c - 19] = '_';
		x[r + 9][c - 18] = '_';
		x[r + 9][c - 17] = '_';
		x[r + 9][c - 16] = '_';
		x[r + 9][c - 15] = '_';
		x[r + 9][c - 14] = '_';
		x[r + 9][c - 13] = '/';
		x[r + 8][c - 12] = '_';
		x[r + 9][c - 12] = ' ';
		x[r + 9][c - 11] = '\\';
		x[r + 10][c - 28] = '|';
		x[r + 10][c - 27] = '_';
		x[r + 10][c - 26] = '_';
		x[r + 10][c - 25] = '_';
		x[r + 10][c - 24] = 179;
		x[r + 10][c - 23] = '_';
		x[r + 10][c - 22] = '_';
		x[r + 10][c - 21] = '_';
		x[r + 10][c - 20] = '_';
		x[r + 10][c - 19] = '_';
		x[r + 10][c - 18] = '_';
		x[r + 10][c - 17] = '_';
		x[r + 10][c - 16] = '_';
		x[r + 10][c - 15] = '_';
		x[r + 10][c - 14] = '_';
		x[r + 10][c - 13] = '_';
		x[r + 10][c - 12] = '_';
		x[r + 10][c - 11] = '_';
		x[r + 10][c - 10] = '_';
		x[r + 10][c - 9] = '_';
		x[r + 10][c - 8] = '|';

		x[r + 12][c - 5] = '/';
		x[r + 12][c - 6] = '_';
		x[r + 12][c - 7] = '_';
		x[r + 12][c - 8] = '_';
		x[r + 12][c - 9] = '_';
		x[r + 12][c - 10] = '\\';
		x[r + 11][c - 11] = '\\';


		x[r + 10][c - 6] = '/';
		x[r + 11][c - 7] = '/';
		x[r + 11][c - 8] = '\\';

		x[r + 13][c - 4] = '/';
		x[r + 14][c - 5] = '/';
		x[r + 15][c - 6] = '/';
		x[r + 16][c - 7] = '/';
		x[r + 17][c - 7] = '|';
		x[r + 18][c - 7] = '|';
		x[r + 18][c - 6] = '_';
		x[r + 18][c - 5] = '_';
		x[r + 18][c - 4] = '|';
		x[r + 17][c - 4] = '|';
		x[r + 16][c - 4] = '/';
		x[r + 15][c - 3] = '/';
		x[r + 14][c - 2] = '/';
		x[r + 13][c - 1] = '/';

		x[r + 13][c] = '\\';
		x[r + 14][c + 1] = '\\';
		x[r + 15][c + 2] = '\\';
		x[r + 16][c + 3] = '\\';
		x[r + 17][c + 4] = '\\';
		x[r + 18][c + 5] = '\\';
		x[r + 18][c + 6] = '_';
		x[r + 18][c + 7] = '_';
		x[r + 18][c + 8] = '\\';
		x[r + 17][c + 7] = '\\';
		x[r + 16][c + 6] = '\\';
		x[r + 15][c + 5] = '\\';
		x[r + 14][c + 4] = '\\';
		x[r + 13][c + 4] = '|';



	}

}

void StaticBigBossShot(char x[][138], int rH, int cH, int r1, int c1, int r2, int c2, int when)
{
	if (when == 0)
	{
		x[r1][c1] = 219;
		x[r1 + 1][c1] = 219;
		x[r1][c1 - 1] = 219;
		x[r1 + 1][c1 - 1] = 219;

		x[r1][c1 - 3] = 219;
		x[r1 + 1][c1 - 3] = 219;
		x[r1][c1 - 4] = 219;
		x[r1 + 1][c1 - 4] = 219;
	}


	if (when == 1)
	{
		x[r2][c2] = 219;
		x[r2][c2 - 1] = 219;
	}
}

void DynamicBigBossShot(char x[][138], int rH, int& cH, int& r1, int& c1, int& r2, int& c2, int& DeathT, int& shoot1, int rBB, int& cBB, int& when)
{


	for (int z = 0; z < 14; z++)
	{
		if (when == 0)
		{
			c1--;

			if (x[r1][c1 - 5] != ' ' || x[r1 + 1][c1 - 5] != ' ')
			{
				cBB -= 4;
				shoot1 += 2;
				DeathT = 7;
				r1 = rBB + 8;
				c1 = cBB - 32;
				when = 1;
				cH -= 2;
			}
			if (c1 - 5 <= 0)
			{
				cBB++;
				r1 = rBB + 8;
				c1 = cBB - 32;
				when = 1;

			}
		}
	}

	for (int y = 0; y < 14; y++)
	{
		if (when == 1)
		{
			c2--;

			if (x[r2][c2 - 2] != ' ')
			{
				cBB -= 4;
				shoot1++;
				DeathT = 7;
				r2 = rBB + 10;
				c2 = cBB - 29;
				when = 0;
				cH -= 2;
			}
			if (c2 - 2 <= 0)
			{
				cBB++;
				r2 = rBB + 10;
				c2 = cBB - 29;
				when = 0;
			}

		}
	}

}

void Telepherique(char x[][2000], int rH, int cH, int r, int& c, int& cFC, int value, int& TelephRide)
{

	x[20][8] = 179;
	x[21][8] = 179;
	x[22][8] = 179;
	x[23][8] = 179;
	x[24][8] = 179;
	x[25][8] = 179;
	x[26][8] = 179;
	x[27][8] = 179;

	x[20][7] = '_';
	x[20][6] = '_';
	x[21][5] = 179;
	x[22][5] = 179;
	x[22][6] = '_';
	x[22][7] = '_';
	x[23][5] = 179;
	x[24][5] = 179;
	x[24][6] = '_';
	x[24][7] = '_';

	for (int a = 9; a <= 106; a++)
	{
		x[27][a] = '_';
	}
	for (int b = 27; b >= 20; b--)
	{
		x[b][107] = 179;
	}



	if (TelephRide == 2 || TelephRide == 3)
	{
		x[20][c + 1 - 3] = 179;
		x[21][c + 1 - 3] = 179;
		x[22][c + 1 - 3] = 179;
		x[23][c + 1 - 3] = 179;
		x[24][c + 1 - 3] = 179;
		x[25][c + 1 - 3] = 179;
		x[26][c + 1 - 3] = 179;
		x[27][c + 1 - 3] = 179;
		x[28][c + 1 - 3] = 179;
		x[29][c + 1 - 3] = 179;

		x[20][c - 3] = 179;
		x[21][c - 3] = 179;
		x[22][c - 3] = 179;
		x[23][c - 3] = 179;
		x[24][c - 3] = 179;
		x[25][c - 3] = 179;
		x[26][c - 3] = 179;
		x[27][c - 3] = 179;
		x[28][c - 3] = 179;
		x[29][c - 3] = 179;

		x[r + 2][c - 1 - 3] = '_';
		x[r + 2][c - 2 - 3] = '_';
		x[r + 2][c - 3 - 3] = '_';
		//x[29][13] = '_';
		x[r + 2][c + 2 - 3] = '_';
		x[r + 2][c + 3 - 3] = '_';
		x[r + 2][c + 4 - 3] = '_';
		x[r + 3][c + 5 - 3] = '\\';
		x[r + 3][c - 4 - 3] = '/';
		if (value >= 82 && c > 14)
		{
			c -= 4;
		}
	}
	else if ((TelephRide == 0 || TelephRide == 3) && value >= 82)
	{
		//c -= 4;
		TelephRide = 3;

	}
	else if (TelephRide == 0 && value < 25)
	{
		x[20][c + 1] = 179;
		x[21][c + 1] = 179;
		x[22][c + 1] = 179;
		x[23][c + 1] = 179;
		x[24][c + 1] = 179;
		x[25][c + 1] = 179;
		x[26][c + 1] = 179;
		x[27][c + 1] = 179;
		x[28][c + 1] = 179;
		x[29][c + 1] = 179;

		x[20][c] = 179;
		x[21][c] = 179;
		x[22][c] = 179;
		x[23][c] = 179;
		x[24][c] = 179;
		x[25][c] = 179;
		x[26][c] = 179;
		x[27][c] = 179;
		x[28][c] = 179;
		x[29][c] = 179;

		x[r + 2][c - 1] = '_';
		x[r + 2][c - 2] = '_';
		x[r + 2][c - 3] = '_';
		//x[29][13] = '_';
		x[r + 2][c + 2] = '_';
		x[r + 2][c + 3] = '_';
		x[r + 2][c + 4] = '_';
		x[r + 3][c + 5] = '\\';
		x[r + 3][c - 4] = '/';
	}
	x[21][11] = 'T';
	x[21][12] = 'e';
	x[21][13] = 'l';
	x[21][14] = 'e';
	x[21][15] = 'p';
	x[21][16] = 'h';
	x[21][17] = 'e';
	x[21][18] = 'r';
	x[21][19] = 'i';
	x[21][20] = 'q';
	x[21][21] = 'u';
	x[21][22] = 'e';



}

void StaticWallEnemy(char x[][2000], int rH, int cH, int r1, int c1, int r2, int c2, int k, int value, int wallexist, int wall1exist, int wall2exist, int& shoot1)
{

	if (wallexist == 1)
	{
		if (wall1exist == 1)
		{


			x[20][c1] = '/';
			x[21][c1] = '\\';
			x[22][c1] = '/';
			x[23][c1] = '\\';
			x[24][c1] = '/';
			x[25][c1] = '\\';
			x[26][c1] = '/';
			x[27][c1] = '\\';
			x[28][c1] = '/';
			x[29][c1] = '\\';
			x[30][c1] = '/';
			x[31][c1] = '\\';
			x[32][c1] = '/';
			x[33][c1] = '\\';
			x[34][c1] = '/';
			x[35][c1] = '\\';
			x[36][c1] = '/';
			x[37][c1] = '\\';
		}
		if (wall2exist == 1)
		{
			x[20][c2] = '/';
			x[21][c2] = '\\';
			x[22][c2] = '/';
			x[23][c2] = '\\';
			x[24][c2] = '/';
			x[25][c2] = '\\';
			x[26][c2] = '/';
			x[27][c2] = '\\';
			x[28][c2] = '/';
			x[29][c2] = '\\';
			x[30][c2] = '/';
			x[31][c2] = '\\';
			x[32][c2] = '/';
			x[33][c2] = '\\';
			x[34][c2] = '/';
			x[35][c2] = '\\';
			x[36][c2] = '/';
			x[37][c2] = '\\';
		}
	}


}

void DynamicWallEnemy(char x[][2000], int rH, int cH, int& r1, int& c1, int& r2, int& c2, int& k, int value, int& shoot1, int wall1exist, int wall2exist)
{

	if (value > 95 && value < 215 && c1 >= 116 && k == 0)
	{
		for (int i = 0; i < 5; i++)
		{
			if (c1 <= 116)
			{
				k = 1;
			}

			for (int j = 20; j < 34; j++)
			{
				if (x[j][c1 - 1] == '|' && wall1exist == 1)
				{
					shoot1++;
					c1 = 215;
					//	break;
				}
			}
			c1--;
		}


	}

	if (value > 95 && value < 215 && c2 >= 116 && k == 0)
	{
		for (int i = 0; i < 5; i++)
		{
			if (c2 <= 116)
			{
				k = 1;
			}

			for (int j = 20; j < 34; j++)
			{
				if (x[j][c2 - 1] == '|' && wall2exist == 1)
				{
					shoot1++;
					c2 = 225;
					///break;
				}
			}

			c2--;
		}


	}
	if (value > 95 && value < 215 && c1 <= 215 && k == 1)
	{

		for (int i = 0; i < 5; i++)
		{
			if (c1 >= 215)
			{
				k = 0;
			}



			c1++;
		}
	}
	if (value > 95 && value < 215 && c2 <= 215 && k == 1)
	{

		for (int i = 0; i < 5; i++)
		{
			if (c2 >= 215)
			{
				k = 0;
			}


			c2++;
		}
	}

}

void StaticHeroJumpChange(char x[][2000], int rH, int cH)
{

	x[rH + 10][cH - 1] = '_';
	x[rH + 10][cH] = '_';
	x[rH + 10][cH + 1] = ' ';
	x[rH + 10][cH + 2] = '_';
	x[rH + 10 + 1][cH + 1] = 251;
	x[rH + 10 + 2][cH] = ' ';
	x[rH + 10 + 2][cH + 2] = ' ';
	x[rH + 10 + 2][cH + 1] = '-';
	x[rH + 10 + 2][cH - 1] = '-';
	x[rH + 10 + 1][cH - 2] = '/';
	x[rH + 10 + 1][cH + 3] = '\\';
	x[rH + 10 + 2][cH - 2] = '|';
	x[rH + 10 + 2][cH + 3] = '|';
	x[rH + 10 + 3][cH - 2] = '\\';
	x[rH + 10 + 3][cH + 3] = '/';
	x[rH + 10 + 3][cH - 1] = '_';
	x[rH + 10 + 3][cH] = '_';
	x[rH + 10 + 3][cH + 1] = '_';
	x[rH + 10 + 3][cH + 2] = '_';
	x[rH + 9][cH - 1] = '_';
	x[rH + 10][cH - 1] = '/';
	x[rH + 10][cH + 3] = '/';
	x[rH + 9][cH + 4] = '_';

	x[rH + 9][cH - 2] = '|';
	x[rH + 8][cH - 2] = ' ';
	x[rH + 7][cH - 2] = '|';
	x[rH + 6][cH - 2] = '|';

	x[rH + 9][cH + 5] = '|';
	x[rH + 8][cH + 5] = ' ';
	x[rH + 7][cH + 5] = '|';
	x[rH + 6][cH + 5] = '|';

	x[rH + 8][cH + 4] = '_';
	x[rH + 8][cH + 3] = '_';
	x[rH + 8][cH + 2] = '_';
	x[rH + 8][cH] = '|';
	x[rH + 7][cH + 4] = '_';
	x[rH + 7][cH + 3] = '_';
	x[rH + 7][cH + 2] = '_';
	x[rH + 7][cH + 1] = '_';

	x[rH + 8][cH - 3] = '_';
	x[rH + 8][cH - 4] = '_';
	x[rH + 9][cH - 5] = 179;
	x[rH + 10][cH - 5] = 179;
	x[rH + 10][cH - 6] = '_';
	x[rH + 10][cH - 7] = 179;
	x[rH + 9][cH - 7] = 179;
	x[rH + 8][cH - 7] = '/';
	x[rH + 7][cH - 6] = '_';
	x[rH + 7][cH - 5] = '_';
	x[rH + 7][cH - 4] = '_';
	x[rH + 7][cH - 3] = '_';

	x[rH + 5][cH + 5] = '/';
	x[rH + 4][cH + 6] = '_';
	x[rH + 4][cH + 7] = '_';
	x[rH + 4][cH + 8] = '_';
	x[rH + 4][cH + 9] = '_';
	x[rH + 4][cH + 10] = '\\';
	x[rH + 3][cH + 9] = '_';
	x[rH + 3][cH + 8] = '_';
	x[rH + 3][cH + 7] = '_';
	x[rH + 3][cH + 6] = '_';
	x[rH + 3][cH + 5] = '_';
	x[rH + 3][cH + 4] = '_';
	x[rH + 3][cH + 3] = '_';
	x[rH + 4][cH + 2] = '|';


	x[rH + 5][cH - 2] = '\\';
	x[rH + 4][cH - 3] = '\\';
	x[rH + 3][cH - 4] = '\\';
	x[rH + 2][cH - 3] = '_';
	x[rH + 3][cH - 2] = '\\';
	x[rH + 4][cH - 1] = '\\';
	x[rH + 5][cH] = '\\';
	x[rH + 5][cH + 1] = '|';
	x[rH + 4][cH + 1] = '|';

}

void GunShots(char x[][2000], int rH, int cH, int r1[], int r2[], int c1[], int c2[], int& counterSH, int& ordered, int value, int& flagSH, int& wall1exist, int& wall2exist, int& enemy1exist, int cEnemy)
{
	if (ordered >= 1)
	{
		for (int f = 0; f < counterSH; f++)
		{
			if (c1[f] <= 133 + value )
			{
				x[r1[f]][c1[f]] = 22;
			}
			if (c2[f] <= 133 + value )
			{
				x[r2[f]][c2[f]] = 22;
			}
		}
		ordered = 2;
	}
	if (ordered == 2)
	{


		for (int f = 0; f < counterSH; f++)
		{
			for (int a = 0; a < 10; a++)
			{
				if ((x[r1[f]][c1[f] + 1] == '/' || x[r1[f]][c1[f] + 1] == '\\') && r1[f] < 38)
				{

					if (wall1exist == 1)
					{
						wall1exist = 0;
					}
					else
					{
						wall2exist = 0;
					}
				}

				if ((c1[f] + 1 == cEnemy || c1[f] + 2 == cEnemy + 1) && value >= 396)
				{
					enemy1exist = 0;
				}

				c1[f]++;
				
				
			}
			for (int a = 0; a < 9; a++)
			{
				if ((x[r1[f]][c2[f] + 1] == '/' || x[r1[f]][c2[f] + 1] == '\\') && r2[f] < 38)
				{

					if (wall2exist == 1)
					{
						wall2exist = 0;
					}
					else
					{
						wall1exist = 0;
					}

				}

				if ((c2[f] + 1 == cEnemy || c2[f] + 2 == cEnemy + 1) && value >= 396)
				{
					enemy1exist = 0;
				}

				c2[f]++;
				
			}

			if (c1[flagSH] >= 135 + value && c2[flagSH] >= 135 + value)
			{
				//counterSH--;
				counterSH = 0;
				ordered = 0;
				//flagSH = 0;

			}
		}




	}
}

void GunShotsDiag(char x[][2000], int rH, int cH, int r1[], int r2[], int c1[], int c2[], int& counterSH, int& ordered, int value, int& flagSH, int& wall1exist, int& wall2exist, int& enemy1exist, int cEnemy,int& planeexist,int& rEnemy)
{
	

	if (ordered >= 1)
	{
		for (int f = 0; f < counterSH; f++)
		{
			if (c1[f] <= 133 + value && r1[f] >=7)
			{
				x[r1[f]][c1[f]] = 22;
			}
			if (c2[f] <= 133 + value && r2[f] >= 7)
			{
				x[r2[f]][c2[f]] = 22;
			}
		}
		ordered = 2;
	}
	if (ordered == 2)
	{


		for (int f = 0; f < counterSH; f++)
		{
			for (int a = 0; a < 10; a++)
			{
				if ((x[r1[f]][c1[f] + 1] == '/' || x[r1[f]][c1[f] + 1] == '\\') && r1[f] < 38)
				{

					if (wall1exist == 1)
					{
						wall1exist = 0;
					}
					else
					{
						wall2exist = 0;
					}
				}

				if ((c1[f] + 1 == cEnemy || c1[f] + 2 == cEnemy + 1) && value >= 396)
				{
					enemy1exist = 0;
				}
				if (c1[f] % 5 == 0)
				{
					r1[f]--;
				}
				c1[f]++;


			}
			for (int a = 0; a < 9; a++)
			{
			if ((x[r1[f]][c2[f] + 1] == '/' || x[r1[f]][c2[f] + 1] == '\\') && r2[f] < 38)
				{

					if (wall2exist == 1)
					{
						wall2exist = 0;
					}
					else
					{
						wall1exist = 0;
					}

				}

				if ((c2[f] + 1 == cEnemy || c2[f] + 2 == cEnemy + 1) && value >= 396)
				{
					enemy1exist = 0;
				}
				if (c2[f] % 5 == 0)
				{
					r2[f]--;
				}
				c2[f]++;

			}

			if (c1[flagSH] >= 128 + value && c2[flagSH] >= 128 + value && r1[flagSH] <= 4 && r2[flagSH] <= 4)
			{
				//counterSH--;
				for (int f = 0; f < counterSH; f++)
				{
					r1[f] = rH + 5;
					c1[f] = cH + 14;

					r2[f] = rH + 6;
					c2[f] = cH + 6;
				}
				counterSH = 0;
				ordered = 0;
				//flagSH = 0;
				
			}
		}




	}
}

void Lasering(char x[][2000], int rH, int cH, int& laserstat, int lasersecs, int& laserdelay, int LeftLook, int ladder, int TelephRide, int& wall1exist, int& wall2exist, int& enemy1exist, int value, int cEnemy, int rEnemy, int& planeexist)
{
	if (laserstat == 1 && laserdelay >= 0 && laserdelay <= 20 && LeftLook == 0 && ladder == 0 && (TelephRide == 0 || TelephRide == 3) && value <= 700)
	{
		if (laserdelay % 2 == 0)
		{
			for (int i = cH + 1, k = 0; k < 70; k++, i += 2)
			{

				if (x[rH + 2][i + 1] == '/' || x[rH + 2][i + 1] == '\\' || x[rH + 2][i + 2] == '/' || x[rH + 2][i + 2] == '\\')
				{
					wall1exist = 0;

					wall2exist = 0;


				}
				for (int j = -4; j < 5; j++)
				{
					if (i + j == cEnemy && (rH + 2) >= rEnemy)
					{
						enemy1exist = 0;
					}
				}
				x[rH + 2][i] = '-';
			}

		}

		else
		{
			for (int i = cH + 2, k = 0; k < 70; k++, i += 2)
			{

				if (x[rH + 2][i + 1] == '/' || x[rH + 2][i + 1] == '\\' || x[rH + 2][i + 2] == '/' || x[rH + 2][i + 2] == '\\')
				{

					wall2exist = 0;

					wall1exist = 0;


				}

				for (int j = -4; j < 5; j++)
				{
					if (i + j == cEnemy && (rH + 2) >= rEnemy)
					{
						enemy1exist = 0;
					}
				}

				x[rH + 2][i] = '-';
			}

		}
		laserdelay++;
		if (laserdelay > 10)
		{
			laserdelay = 0;
			laserstat = 0;
		}
	}

	if (laserstat == 2)
	{
		if (laserdelay % 2 == 0)
		{
			for (int i = rH + 1, k = 0; k < 70; k++, i -= 2)
			{


				x[i][cH] = '|';
				x[i][cH + 2] = '|';
				planeexist = 0;
				x[rH + 2][cH] = ' ';
				x[rH + 2][cH + 2] = ' ';
			}



		}

		else
		{
			for (int i = rH, k = 0; k < 70; k++, i -= 2)
			{
				x[i][cH] = '|';
				x[i][cH + 2] = '|';
				planeexist = 0;
			//	x[rH + 2][cH + 2] = ' ';
				//x[rH + 2][cH] = ' ';


			}

		}
		laserdelay++;
		if (laserdelay > 10)
		{
			laserdelay = 0;
			laserstat = 0;
		}
	}

}

void StaticFutureElev(char x[][2000], int r, int c, int ElevON, int AirTubeStat, int rR)
{

	for (int i = 0; (rR) >= 20; i++, rR--)
	{
		x[rR][236] = 179;

	}


	x[r + 10][c - 1] = '_';
	x[r + 10][c - 2] = '_';
	x[r + 10][c - 3] = '_';
	x[r + 11][c - 4] = 179;
	x[r + 11][c - 4] = 179;

	x[r + 10][c + 1] = '_';
	x[r + 10][c + 2] = '_';
	x[r + 10][c + 3] = '_';
	x[r + 11][c + 4] = 179;
	x[r + 11][c + 4] = 179;
}

void DynamicFutureElev(char x[][2000], int& rH, int& cH, int& r, int& c, int& ElevON, int& AirTubeStat, int&countRLHL1, int& rR, int& Stat1)
{



	if (cH >= 226 && ElevON == 0 && AirTubeStat == 0 && Stat1 == 0)
	{
		ElevON = 1;
		countRLHL1 = 2;
		cH = 235;
		rH--;
	}

	if (ElevON == 1 && Stat1 == 0)
	{

		rH--;
		r--;
		rR--;
		if (rH <= 21)
		{
			ElevON = 0;
			AirTubeStat = 1;
			Stat1 = 99;
		}
	}
}

void StaticAirTube(char x[][2000], int rH, int cH, int ElevON, int AirTubeStat)
{
	x[20][228] = 179;
	x[21][228] = 179;
	x[21][229] = '_';
	x[22][230] = 179;
	x[23][230] = 179;
	x[24][230] = 179;
	x[25][230] = 179;
	x[26][230] = 179;
	x[27][230] = 179;
	x[28][230] = 179;

	x[28][242] = 179;

	for (int i = 243; i < 400; i++)
	{
		x[27][i] = '_';
	}

	x[28][400] = 179;
	x[29][400] = 179;
	x[30][400] = 179;

	x[20][412] = 179;
	x[21][412] = 179;
	x[22][412] = 179;
	x[23][412] = 179;
	x[24][412] = 179;
	x[25][412] = 179;
	x[26][412] = 179;
	x[27][412] = 179;
	x[28][412] = 179;
	x[29][412] = 179;
	x[30][412] = 179;
}

void DynamicAirTube(char x[][2000], int& rH, int& cH, int& ElevON, int& AirTubeStat, int& value, int& Stat2)
{
	if (AirTubeStat == 1 && Stat2 == 0)
	{
		cH += 2;

		if (value >= 395)
		{
			AirTubeStat = 0;
		}
	}
	if (value >= 395 && AirTubeStat == 0 && Stat2 == 0)
	{
		rH = 33;
		cH = 4 + value;
		AirTubeStat = 0;
		Stat2 = 99;
	}

}

void ShapeForTube(char x[][2000], int rH, int cH, int AirTubeStat)
{
	x[rH - 1][cH - 1] = '_';
	x[rH - 1][cH] = '_';
	x[rH - 1][cH + 1] = '_';
	x[rH - 1][cH + 2] = '_';
	x[rH - 1 + 2][cH] = '-';
	x[rH - 1 + 2][cH + 2] = '-';
	x[rH - 1 + 2][cH + 1] = ' ';
	x[rH - 1 + 2][cH - 1] = ' ';
	x[rH - 1 + 1][cH - 2] = '/';
	x[rH - 1 + 1][cH + 3] = '\\';
	x[rH - 1 + 2][cH - 2] = '|';
	x[rH - 1 + 2][cH + 3] = '|';
	x[rH - 1 + 3][cH - 2] = '\\';
	x[rH - 1 + 3][cH + 3] = '/';
	x[rH - 1 + 3][cH - 1] = '_';
	x[rH - 1 + 3][cH] = '_';
	x[rH - 1 + 3][cH + 1] = 'o';
	x[rH - 1 + 3][cH + 2] = '_';
	x[rH - 1 + 4][cH - 2] = '_';
	x[rH - 1 + 4][cH - 1] = '/';
	x[rH - 1 + 4][cH + 2] = '/';
	//	x[rH - 1 + 4][cH + 1] = '_';
	x[rH - 1 + 5][cH + 1] = '|';
	x[rH - 1 + 6][cH + 1] = '|';

	x[rH - 1 + 4][cH - 3] = '_';
	x[rH - 1 + 4][cH - 4] = ' ';
	x[rH - 1 + 4][cH - 5] = ' ';
	x[rH - 1 + 4][cH - 6] = '_';
	x[rH - 1 + 4][cH - 7] = '_';
	x[rH - 1 + 4][cH - 8] = '_';

	x[rH - 1 + 5][cH - 9] = '|';
	x[rH - 1 + 6][cH - 9] = '|';

	x[rH - 1 + 4][cH - 4] = '\\';
	x[rH - 1 + 3][cH - 5] = '\\';
	x[rH - 1 + 2][cH - 6] = '\\';
	x[rH - 1 + 1][cH - 7] = '_';
	x[rH - 1 + 2][cH - 8] = '\\';
	x[rH - 1 + 3][cH - 7] = '\\';
	x[rH - 1 + 4][cH - 6] = '\\';

	x[rH - 1 + 5][cH - 10] = '_';
	x[rH - 1 + 5][cH - 11] = '_';
	x[rH - 1 + 5][cH - 12] = '_';
	x[rH - 1 + 5][cH - 13] = '_';
	x[rH - 1 + 5][cH - 14] = '_';
	x[rH - 1 + 5][cH - 15] = '_';

	x[rH - 1 + 4][cH - 10] = '_';
	x[rH - 1 + 4][cH - 11] = '_';
	x[rH - 1 + 4][cH - 12] = '_';
	x[rH - 1 + 4][cH - 13] = '_';
	x[rH - 1 + 4][cH - 14] = '_';
	x[rH - 1 + 4][cH - 15] = '_';

	x[rH - 1 + 6][cH - 10] = '_';
	x[rH - 1 + 6][cH - 11] = '_';
	x[rH - 1 + 6][cH - 12] = '_';
	x[rH - 1 + 6][cH - 13] = '_';
	x[rH - 1 + 6][cH - 14] = '_';
	x[rH - 1 + 6][cH - 15] = '_';
}

void StaticEnemy61(char x[][2000], int rH, int cH, int r, int c, int countRLEL1, int enemy1exist)
{
	if (enemy1exist == 1)
	{
		x[r][c - 2] = '_';
		x[r][c - 3] = '/';
		x[r + 1][c - 3] = '\\';
		x[r - 1][c - 2] = '_';
		x[r - 1][c - 1] = '_';
		x[r - 1][c] = '_';
		x[r - 1][c + 1] = '_';
		x[r - 1][c + 2] = '_';
		x[r - 1][c + 3] = '_';
		x[r][c + 3] = '_';
		x[r][c + 4] = '\\';
		x[r + 1][c + 4] = '/';



		x[r][c - 1] = '_';
		x[r][c] = 21;
		x[r][c + 1] = '_';
		x[r][c + 2] = '_';



		x[r + 2][c - 1] = 127;
		x[r + 2][c + 1] = 127;




		x[r + 1][c - 2] = '/';
		x[r + 1][c + 3] = '\\';

		x[r + 2][c - 2] = '|';
		x[r + 2][c + 3] = '|';

		x[r + 3][c - 2] = '\\';
		x[r + 3][c + 3] = '/';

		x[r + 3][c - 1] = '_';
		x[r + 3][c] = '_';
		x[r + 3][c + 1] = '^';
		x[r + 3][c + 2] = '_';

		x[r + 4][c - 2] = '_';
		x[r + 4][c - 1] = '/';
		x[r + 4][c + 2] = '/';
		x[r + 4][c + 3] = '_';

		if (countRLEL1 == 0)
		{

			x[r + 6][c - 3] = '/';	//RIGHT HAND
			x[r + 6][c - 4] = '_';
			x[r + 6][c - 5] = '_';
			x[r + 6][c - 6] = '\\';
			x[r + 5][c - 7] = '_';
			x[r + 4][c - 6] = '_';
			x[r + 5][c - 4] = '/';
			x[r + 5][c - 5] = '\\';
			x[r + 4][c - 3] = '_';

			x[r + 4][c - 6] = '_';	//GUN
			x[r + 4][c - 7] = '_';
			x[r + 4][c - 8] = '_';
			x[r + 4][c - 9] = '_';
			x[r + 4][c - 10] = '_';
			x[r + 4][c - 11] = '_';
			x[r + 5][c - 12] = '|';
			x[r + 5][c - 11] = '_';
			x[r + 5][c - 10] = '_';
			x[r + 5][c - 9] = '_';
			x[r + 6][c - 8] = '\\';
			x[r + 6][c - 7] = '_';

		}
		if (countRLEL1 % 2 != 0)
		{
			x[r + 6][c - 3] = '_';	//RIGHT HAND
			x[r + 6][c - 2] = ' ';
			x[r + 5][c - 2] = '/';
			x[r + 6][c - 4] = '_';
			x[r + 6][c - 6] = ' ';
			x[r + 6][c - 5] = ' ';//
			x[r + 6][c - 7] = ' ';
			x[r + 4][c - 6] = '_';
			x[r + 5][c - 4] = '_';
			x[r + 5][c - 5] = ' ';
			x[r + 5][c - 6] = ' ';
			x[r + 4][c - 3] = ' ';
			x[r + 5][c - 3] = '_';
			x[r + 4][c - 6] = ' ';
			x[r + 4][c - 2] = ' ';

			x[r + 5][c - 5] = ' ';	//GUN
			x[r + 6][c - 5] = '\\';
			x[r + 5][c - 6] = '_';
			x[r + 5][c - 7] = '_';
			x[r + 5][c - 8] = '_';
			x[r + 5][c - 9] = '_';
			x[r + 5][c - 10] = '_';
			x[r + 6][c - 11] = '|';
			x[r + 6][c - 10] = '_';
			x[r + 6][c - 9] = '_';
			x[r + 6][c - 8] = '_';
			x[r + 7][c - 7] = '\\';
			x[r + 7][c - 6] = '_';
			x[r + 6][c - 6] = ' ';
			x[r + 7][c - 5] = '|';



		}
		else
		{
			x[r + 6][c - 3] = '/';	//RIGHT HAND
			x[r + 6][c - 4] = '_';
			x[r + 6][c - 5] = '_';
			x[r + 6][c - 6] = '\\';
			x[r + 5][c - 7] = '_';
			x[r + 4][c - 6] = '_';
			x[r + 5][c - 4] = '/';
			x[r + 5][c - 5] = '\\';
			x[r + 4][c - 3] = '_';

			x[r + 4][c - 6] = '_';	//GUN
			x[r + 4][c - 7] = '_';
			x[r + 4][c - 8] = '_';
			x[r + 4][c - 9] = '_';
			x[r + 4][c - 10] = '_';
			x[r + 4][c - 11] = '_';
			x[r + 5][c - 12] = '|';
			x[r + 5][c - 11] = '_';
			x[r + 5][c - 10] = '_';
			x[r + 5][c - 9] = '_';
			x[r + 6][c - 8] = '\\';
			x[r + 6][c - 7] = '_';



		}



		//x[r + 5][c + 3] = ' ';	   
		//x[r + 6][c + 3] = '|';	   
		x[r + 7][c + 3] = '|';

		//x[r + 5][c - 2] = ' ';
		//x[r + 6][c - 2] = ' ';
		x[r + 7][c - 2] = '|';

		x[r + 7][c - 1] = '_';
		x[r + 7][c + 1] = '_';
		x[r + 7][c + 2] = '_';
		x[r + 7][c] = '_';

		x[r + 5][c + 5] = '|';
		x[r + 6][c + 5] = '|';
		x[r + 7][c + 5] = '|';
		x[r + 7][c + 4] = '_';

		if (countRLEL1 == 0)
		{
			x[r + 8][c + 3] = '\\';			//LEFT LEG 1
			x[r + 9][c + 4] = '\\';
			x[r + 10][c + 5] = '\\';

			x[r + 8][c + 1] = '\\'; 			//LEFT LEG 2
			x[r + 9][c + 2] = '\\';
			x[r + 10][c + 3] = '\\';
			x[r + 10][c + 4] = '_';
		}

		if (countRLEL1 % 2 != 0)
		{
			x[r + 8][c + 3] = '/';			//LEFT LEG 1
			x[r + 9][c + 2] = '/';
			x[r + 10][c + 1] = '/';

			x[r + 8][c + 1] = '/'; 			//LEFT LEG 2
			x[r + 9][c] = '/';
			x[r + 10][c] = '_';		//FOOT
			x[r + 10][c + 1] = '/';

			//x[r + 10][c - 3] = ' ';


		}
		else
		{
			x[r + 8][c + 3] = '\\';			//LEFT LEG 1
			x[r + 9][c + 4] = '\\';
			x[r + 10][c + 5] = '\\';

			x[r + 8][c + 1] = '\\'; 			//LEFT LEG 2
			x[r + 9][c + 2] = '\\';
			x[r + 10][c + 3] = '\\';
			x[r + 10][c + 4] = '_';
		}


		if (countRLEL1 == 0)
		{

			x[r + 8][c] = '/';			//RIGHT LEG 3
			x[r + 9][c - 1] = '/';
			x[r + 10][c - 1] = '|';

			x[r + 8][c - 2] = '/';			//RIGHT LEG 4
			x[r + 9][c - 3] = '/';
			x[r + 10][c - 3] = '|';
			x[r + 10][c - 2] = '_';
		}

		if (countRLEL1 % 2 != 0)
		{
			x[r + 8][c] = '\\';			//RIGHT LEG 3
			x[r + 9][c - 1] = '\\';
			//x[r + 10][c + 2] = ' ';//////

			x[r + 8][c - 2] = '\\';			//RIGHT LEG 4
			x[r + 9][c - 3] = ' ';
			x[r + 10][c - 3] = ' ';
			x[r + 10][c - 2] = ' ';
			x[r + 10][c + 2] = '_';
			x[r + 10][c + 3] = '|';
		}

		else
		{
			x[r + 8][c] = '/';			//RIGHT LEG 3
			x[r + 9][c - 1] = '/';
			x[r + 10][c - 1] = '|';

			x[r + 8][c - 2] = '/';			//RIGHT LEG 4
			x[r + 9][c - 3] = '/';
			x[r + 10][c - 3] = '|';
			x[r + 10][c - 2] = '_';
		}
	}
}

void DynamicEnemy61(char x[][2000], int rH, int cH, int& r, int& c, int value)
{
	if (value >= 395 && value <= 525)
	{
		c -= 1;
	}
	if (x[r + 11][c] == ' ' && r != 36)
	{
		r++;
	}
	if ((x[r + 10][c - 4] == '\\' || x[r + 11][c - 4] == '\\' || x[r + 11][c - 3] == '\\' || x[r + 10][c - 3] == '\\'))
	{
		r -= 3;
	}
}

void StaticShot61(char x[][2000], int rH, int cH, int r, int c, int enemy1exist, int value)
{
	if (enemy1exist == 1 && value >= 396)
	{
		x[r][c] = 22;
	}
}

void DynamicShot61(char x[][2000], int rH, int cH, int& r, int& c, int& enemy1exist, int& shoot1, int rE, int cE, int value)
{
	if (value >= 396 && enemy1exist == 1)
	{
		c -= 5;
		for (int j = -5; j < 5; j++)
		{
			if (c + j == cH && r >= rH && r < rH + 11)
			{
				shoot1++;
				r = rE + 6;
				c = cE + -12;
			}
		}

		if (c <= 400)
		{
			r = rE + 6;
			c = cE + -12;
		}
	}
}

void StaticCar61(char x[][2000], int r, int c, int rH, int cH)
{

	x[r][c - 1] = '_';
	x[r][c - 2] = '_';
	x[r][c] = '_';
	x[r][c + 1] = '_';
	x[r][c + 2] = '_';

	x[r + 1][c - 1] = '_';
	x[r + 1][c - 2] = '_';
	x[r + 1][c] = 179;
	x[r + 1][c + 1] = '_';
	x[r + 1][c + 2] = '_';

	x[r + 1][c + 3] = 179;
	x[r + 1][c - 3] = 179;

	x[r + 1][c + 4] = '_';
	x[r + 1][c - 4] = '_';


	x[r + 2][c + 6] = '\\';
	x[r + 3][c + 8] = '\\';
	x[r + 3][c + 9] = '_';
	x[r + 3][c + 10] = '_';
	x[r + 3][c + 11] = '_';
	x[r + 3][c + 12] = '_';
	x[r + 3][c + 13] = '_';
	x[r + 3][c + 14] = '_';
	x[r + 4][c + 15] = 179;

	x[r + 2][c - 6] = '/';
	x[r + 3][c - 8] = '/';
	x[r + 4][c - 10] = '/';
	x[r + 4][c - 11] = '_';
	x[r + 4][c - 12] = '_';
	x[r + 4][c - 13] = '_';
	x[r + 4][c - 14] = '_';
	x[r + 4][c - 15] = '_';
	x[r + 4][c - 16] = '_';
	x[r + 4][c - 17] = '_';
	x[r + 4][c - 18] = '_';
	x[r + 5][c - 19] = '/';

	x[r + 5][c - 18] = '_';
	x[r + 5][c - 17] = '_';
	x[r + 5][c - 16] = '/';
	x[r + 6][c - 19] = '\\';
	x[r + 7][c - 19] = 179;
	x[r + 8][c - 18] = '\\';
	x[r + 8][c - 17] = '_';
	x[r + 8][c - 16] = '_';
	x[r + 8][c - 15] = '_';
	x[r + 8][c - 14] = '_';


	x[r + 8][c - 13] = '|';						//el3agala LEFT
	x[r + 7][c - 13] = '/';
	x[r + 6][c - 12] = '_';
	x[r + 6][c - 11] = '_';
	x[r + 6][c - 10] = '_';
	x[r + 7][c - 9] = '\\';
	x[r + 8][c - 9] = '|';




	x[r + 8][c - 8] = '_';
	x[r + 8][c - 7] = '_';
	x[r + 8][c - 6] = '_';
	x[r + 8][c - 5] = '_';
	x[r + 8][c - 4] = '_';
	x[r + 8][c - 3] = '_';
	x[r + 8][c - 2] = '_';
	x[r + 8][c - 1] = '_';
	x[r + 8][c] = '_';
	x[r + 8][c + 1] = '_';
	x[r + 8][c + 2] = '_';
	x[r + 8][c + 3] = '_';
	x[r + 8][c + 4] = '_';
	x[r + 8][c + 5] = '_';
	x[r + 8][c + 6] = '_';
	x[r + 8][c + 7] = '_';


	x[r + 8][c + 8] = '|';						//el3agala RIGHT
	x[r + 7][c + 8] = '/';
	x[r + 6][c + 9] = '_';
	x[r + 6][c + 10] = '_';
	x[r + 6][c + 11] = '_';
	x[r + 7][c + 12] = '\\';
	x[r + 8][c + 12] = '|';





	x[r + 4][c + 14] = '_';
	x[r + 5][c + 13] = '|';
	x[r + 5][c + 14] = '_';


	x[r + 6][c + 14] = '_';
	x[r + 6][c + 13] = '|';


	x[r + 7][c + 15] = 179;
	x[r + 8][c + 16] = '\\';
	x[r + 8][c + 15] = '_';
	x[r + 8][c + 14] = '_';
	x[r + 8][c + 13] = '_';

	x[r + 6][c + 15] = '|';
	x[r + 5][c + 15] = '|';

	//////////////////////INSIDE//////


	x[r + 4][c - 9] = '_';
	x[r + 4][c - 8] = '_';
	x[r + 4][c - 7] = '_';
	x[r + 4][c - 6] = '_';
	x[r + 4][c - 5] = '_';
	x[r + 4][c - 4] = '^';
	x[r + 4][c - 3] = '_';
	x[r + 4][c - 2] = '_';
	x[r + 4][c - 1] = '_';
	x[r + 4][c] = '_';
	x[r + 4][c + 1] = '_';
	x[r + 4][c + 2] = '_';
	x[r + 4][c + 3] = '_';
	x[r + 4][c + 4] = '_';
	x[r + 4][c + 5] = '_';
	x[r + 4][c + 6] = '_';
	x[r + 4][c + 7] = '_';
	x[r + 4][c + 8] = '_';
	x[r + 4][c + 9] = '_';
	x[r + 4][c + 10] = '/';


	x[r + 2][c + 5] = '\\';
	x[r + 3][c + 7] = '\\';

	x[r + 2][c + 4] = '|';
	x[r + 3][c + 4] = '|';
	x[r + 4][c + 4] = '|';


	x[r + 3][c + 3] = '/';
	x[r + 4][c + 3] = '|';

	x[r + 5][c + 2] = 191;

	x[r + 5][c + 3] = '\\';
	x[r + 6][c + 4] = 179;
	x[r + 7][c + 4] = 179;

	///////////////FACE INSIDE///

	x[r + 2][c - 3] = '_';
	x[r + 2][c - 4] = '_';
	x[r + 2][c - 5] = '_';
	x[r + 3][c - 2] = 179;
	x[r + 4][c - 2] = 179;

	x[r + 3][c - 6] = 179;
	x[r + 4][c - 6] = 179;

	x[r + 3][c - 5] = '-';
	x[r + 3][c - 4] = '-';

	x[r + 6][c - 2] = 'F';
	x[r + 6][c - 1] = 'B';
	x[r + 6][c] = 'I';


}

void DynamicCar61(char x[][2000], int& r, int& c, int& rH, int& cH, int& sarena, int& Shoot1, int value)
{
	if (value >= 544)
	{

		if (sarena % 2 == 0)
		{
			x[r + 1][c - 1] = 219;
			x[r + 1][c - 2] = 219;

			x[r + 1][c + 1] = '_';
			x[r + 1][c + 2] = '_';


			//elgwa el3agala  LEFT
			x[r + 7][c - 11] = 179;
			x[r + 8][c - 10] = '\\';
			x[r + 8][c - 12] = ' ';

			//elgwa el3agala  RIGHT
			x[r + 7][c + 10] = 179;
			x[r + 8][c + 11] = '\\';
			x[r + 8][c + 9] = ' ';


		}
		else
		{
			x[r + 1][c + 1] = 219;
			x[r + 1][c + 2] = 219;

			x[r + 1][c - 1] = '_';
			x[r + 1][c - 2] = '_';


			//elgwa el3agala  LEFT
			x[r + 7][c - 11] = ' ';
			x[r + 8][c - 10] = '\\';
			x[r + 8][c - 12] = '/';

			//elgwa el3agala  RIGHT
			x[r + 7][c + 10] = ' ';
			x[r + 8][c + 11] = '\\';
			x[r + 8][c + 9] = '/';

		}




		for (int j = -20; j < 10; j++)
		{
			if (c + j == cH && (rH) == 36)
			{
				c = 673;
				Shoot1++;
			}

		}
		c -= 6;
		if (c <= 580)
		{
			c = 673;
		}
	}



}

void StaticRope(char x[][2000], int rH, int cH, int AttachRope)
{
	if (AttachRope == 0)
	{
		for (int i = 0; i < 27; i++)
		{
			x[i][568] = 179;
		}

	}

}

void DynamicRope(char x[][2000], int& rH, int& cH, int& AttachRope, int value)
{
	if (AttachRope == 1 && value >= 530 && value < 690)
	{
		for (int i = 0; i < 27; i++)
		{
			x[i][value + 10] = 179;
		}
		rH = 22;

	}
}

void StaticPlane61(char x[][2000], int r, int c, int rH, int cH, int planeexist)
{
	if (planeexist == 1)
	{

		x[r][c] = '/';
		x[r - 1][c + 1] = '/';
		x[r - 2][c + 2] = '/';
		x[r - 3][c + 3] = '/';
		x[r - 4][c + 4] = '/';


		x[r - 2][c + 3] = '_';
		//x[r - 1][c + 2] = '_';
		x[r - 2][c + 4] = '/';
		x[r - 3][c + 5] = '/';
		x[r - 3][c + 4] = '_';
		x[r - 4][c + 5] = '_';


		x[r - 5][c + 4] = '_';
		x[r - 5][c + 3] = '_';
		x[r - 5][c + 2] = '_';
		x[r - 5][c + 1] = '_';
		x[r - 5][c] = '_';
		x[r - 5][c - 1] = '\\';
		x[r - 6][c - 1] = '_';
		x[r - 6][c] = '_';
		x[r - 6][c + 1] = '_';
		x[r - 6][c + 2] = '_';
		x[r - 6][c + 3] = '_';
		x[r - 6][c + 4] = '_';
		x[r - 6][c + 5] = '_';
		x[r - 6][c + 6] = '_';
		x[r - 6][c + 7] = '_';
		x[r - 6][c + 8] = '_';
		x[r - 6][c + 9] = '_';
		x[r - 6][c + 10] = '_';

		x[r - 5][c + 11] = '\\';
		x[r - 4][c + 12] = '\\';
		x[r - 3][c + 13] = '\\';
		x[r - 2][c + 14] = '\\';

		x[r - 5][c + 9] = '\\';
		x[r - 4][c + 10] = '\\';
		x[r - 3][c + 11] = '\\';
		x[r - 3][c + 12] = '_';
		x[r - 2][c + 12] = '\\';
		x[r - 1][c + 13] = '\\';

		x[r - 2][c + 15] = '/';
		x[r - 3][c + 16] = '/';
		x[r - 4][c + 17] = '/';
		x[r - 5][c + 18] = '_';
		x[r - 5][c + 19] = '_';
		x[r - 5][c + 20] = '_';

		x[r - 4][c + 21] = 179;
		x[r - 3][c + 21] = 179;
		x[r - 2][c + 21] = 179;
		x[r - 1][c + 21] = 179;
		x[r][c + 21] = 179;

		x[r][c + 20] = '_';
		x[r][c + 19] = '_';
		x[r][c + 18] = '_';
		x[r][c + 17] = '_';
		x[r][c + 16] = '_';
		x[r][c + 15] = '_';
		x[r][c + 14] = '_';
		x[r][c + 13] = '_';
		x[r][c + 12] = '_';
		x[r][c + 11] = '_';
		x[r][c + 10] = '_';
		x[r][c + 9] = '_';
		x[r][c + 8] = '_';
		x[r][c + 7] = '_';
		x[r][c + 6] = '_';
		x[r][c + 5] = '_';
		x[r][c + 4] = '_';
		x[r][c + 3] = '_';
		x[r][c + 2] = '_';
		x[r][c + 1] = '_';
		//x[r][c] = '_';
		//x[r][c - 1] = '_';
		x[r][c - 2] = '_';
		x[r][c - 3] = '_';
		x[r][c - 4] = '_';
		x[r][c - 5] = '_';
		x[r][c - 6] = '_';
		x[r][c - 7] = '_';
		x[r][c - 8] = '_';
		x[r][c - 9] = '_';
		x[r][c - 10] = '_';
		x[r][c - 11] = '_';
		x[r][c - 12] = '_';
		x[r][c - 13] = '_';
		x[r][c - 14] = '_';
		x[r][c - 15] = '_';
		x[r][c - 16] = '_';

		x[r][c - 1] = 179;
		x[r - 1][c - 1] = 179;
		x[r - 2][c - 1] = 179;

		x[r - 3][c - 2] = '_';
		x[r - 3][c - 2] = '_';
		x[r - 3][c - 3] = '_';

		x[r - 2][c - 4] = '/';
		x[r - 1][c - 5] = '/';
		x[r][c - 6] = '/';


		x[r - 1][c + 14] = '/';
		x[r][c + 13] = '/';


		x[r + 1][c - 17] = '/';
		x[r + 2][c - 18] = '/';

		x[r + 2][c - 17] = '_';
		x[r + 2][c - 16] = '_';
		x[r + 2][c - 15] = '_';
		x[r + 2][c - 14] = '_';
		x[r + 2][c - 13] = '_';
		x[r + 2][c - 12] = '_';
		x[r + 2][c - 11] = '_';
		x[r + 2][c - 10] = '_';
		x[r + 2][c - 9] = '_';
		x[r + 2][c - 8] = '_';
		x[r + 2][c - 7] = '_';
		x[r + 2][c - 6] = '_';
		x[r + 2][c - 5] = '_';
		x[r + 2][c - 4] = '_';
		x[r + 2][c - 3] = '_';
		x[r + 2][c - 2] = '_';
		x[r + 2][c - 1] = '_';
		x[r + 2][c] = '_';
		x[r + 2][c + 1] = '_';
		x[r + 2][c + 2] = '_';
		x[r + 2][c + 3] = '_';
		x[r + 2][c + 4] = '_';
		x[r + 2][c + 5] = '_';
		x[r + 2][c + 6] = '_';
		x[r + 2][c + 7] = '_';
		x[r + 2][c + 8] = '_';
		x[r + 2][c + 9] = '_';
		x[r + 2][c + 10] = '_';
		x[r + 2][c + 11] = '_';
		x[r + 2][c + 12] = '_';
		x[r + 2][c + 13] = '_';
		x[r + 2][c + 14] = '_';
		x[r + 2][c + 15] = '_';
		x[r + 2][c + 16] = '_';
		x[r + 2][c + 17] = '_';
		x[r + 2][c + 18] = '_';
		x[r + 2][c + 19] = '_';
		x[r + 2][c + 20] = '_';
		x[r + 2][c + 21] = '_';
		x[r + 2][c + 22] = '/';
		x[r + 1][c + 22] = '_';
		x[r + 1][c + 21] = 179;

		//Lower Wing
		x[r + 3][c - 6] = '\\';
		x[r + 4][c - 5] = '\\';
		x[r + 4][c - 6] = '_';
		//ROCKETING
		x[r + 5][c - 7] = 34;
		/////////////////////
		x[r + 4][c - 8] = '_';
		x[r + 4][c - 9] = '\\';
		x[r + 3][c - 9] = '_';
		x[r + 3][c - 8] = '_';
		x[r + 3][c - 7] = '_';

		x[r + 5][c - 4] = '\\';
		x[r + 5][c - 3] = '_';
		x[r + 5][c - 2] = '_';
		x[r + 5][c - 1] = 179;
		x[r + 4][c - 1] = 179;
		x[r + 3][c - 1] = 179;

		//INSIDE -->
		x[r + 1][c - 14] = '|';
		x[r + 1][c - 13] = '_';
		x[r + 1][c - 12] = '_';
		x[r + 1][c - 11] = '_';
		x[r + 1][c - 10] = '_';
		x[r + 1][c - 9] = '_';
		x[r + 1][c - 8] = '|';
		x[r + 1][c - 7] = '_';
		x[r + 1][c - 6] = '_';
		x[r + 1][c - 5] = '_';
		x[r + 1][c - 4] = '_';
		x[r + 1][c - 3] = '_';
		x[r + 1][c - 2] = '|';
		x[r + 1][c - 1] = '_';
		x[r + 1][c] = '_';
		x[r + 1][c + 1] = '/';

		//OUTSIDE --->
		x[r + 6][c] = '\\';
		x[r + 7][c + 1] = '\\';

		x[r + 6][c + 2] = '\\';
		x[r + 7][c + 3] = '\\';

		x[r + 5][c + 1] = '_';
		x[r + 7][c + 2] = '_';
		x[r + 6][c + 1] = '_';

		x[r + 7][c] = '_';
		x[r + 7][c - 1] = '_';
		x[r + 7][c - 2] = '_';
		x[r + 8][c - 2] = '\\';
		x[r + 8][c - 1] = '_';
		x[r + 8][c] = '_';
		x[r + 8][c + 1] = '_';
		x[r + 8][c + 2] = '_';
		x[r + 8][c + 3] = '_';
		x[r + 8][c + 4] = '_';
		x[r + 8][c + 5] = '_';
		x[r + 8][c + 6] = '_';
		x[r + 8][c + 7] = '_';
		x[r + 8][c + 8] = '_';

		x[r + 8][c + 9] = '/';
		x[r + 7][c + 10] = '/';
		x[r + 6][c + 11] = '/';
		x[r + 5][c + 12] = '/';
		x[r + 4][c + 13] = '/';
		x[r + 3][c + 14] = '/';

		x[r + 8][c + 7] = '/';
		x[r + 7][c + 8] = '/';
		x[r + 6][c + 9] = '/';
		x[r + 5][c + 10] = '/';
		x[r + 5][c + 11] = '_';
		x[r + 4][c + 11] = '/';
		x[r + 3][c + 12] = '/';

		x[r + 4][c + 1] = 196;
		x[r + 4][c + 2] = 196;
		x[r + 4][c + 3] = 196;
		x[r + 4][c + 4] = 196;
		x[r + 4][c + 5] = 196;
		x[r + 4][c + 6] = 196;
		x[r + 4][c + 7] = 196;
		x[r + 4][c + 8] = 196;
		x[r + 4][c + 9] = 196;

		x[r - 1][c + 5] = 196;
		x[r - 1][c + 6] = 196;
		x[r - 1][c + 7] = 196;
		x[r - 1][c + 8] = 196;
		x[r - 1][c + 9] = 196;
		x[r - 1][c + 10] = 196;

		x[r - 1][c + 7] = 'F';
		x[r - 1][c + 8] = 'B';
		x[r - 1][c + 9] = 'I';

		x[r + 4][c + 4] = 'F';
		x[r + 4][c + 5] = 'B';
		x[r + 4][c + 6] = 'I';
	}

}

void DynamicPlane61(char x[][2000], int& r1, int& c1, int& rH, int& cH, int value)
{
	if (value >= 700 && value <= 835)
	{
		c1 -= 7;
		if (c1 < 70)
		{
			r1++;
			if (r1 <= 0)
			{
				r1 = 7;
			}
		}


		if (c1 - 10 <= 700)
		{

			c1 = 835;
			r1 = 15;

		}
	}
}

void StaticPlaneShot61(char x[][2000], int& rPG1, int& cPG1,int planeexist)
{
	if (planeexist == 1)
	{
		x[rPG1][cPG1] = 219;
	}
}

void DynamicPlaneShot61(char x[][2000], int& rPG1, int& cPG1, int r1, int c1, int rH, int cH, int value, int& shoot1,int planeexist)
{
	if (planeexist == 1)
	{
		if (value >= 700 && value <= 835)
		{
			rPG1 += 8;
			for (int j = -3; j < 4; j++)
			{
				if (cPG1 == cH + j && rPG1 >= rH)
				{
					shoot1 += 3;
					rPG1 = r1 + 6;
					cPG1 = c1 - 2;
					break;
				}
			}
			if (rPG1 >= 46)
			{
				rPG1 = r1 + 6;
				cPG1 = c1 - 2;
			}
		}
	}
}

void Output(char x[][2000], int& ScrollCounter, int& cH, int& value)
{

	if (ScrollCounter == 0)
	{
		system("cls");

		for (int r = 0; r < 48; r++)
		{
			for (int c = value; c < 138 + value; c++)
			{

				cout << x[r][c];
			}
		}
	}

	if (ScrollCounter == 1)
	{
		for (int r = 0; r < 48; r++)
		{
			for (int c = value; c < 138 + value; c++)
			{
				cout << x[r][c];
			}
		}
		//cH = 5;
		ScrollCounter = 0;

	}

}


int main()
{
	char x[48][138];
	int countRLHL1 = 0;
	int rH = 36, cH = 8;
	int mins = 9, secs = 60;
	int level = 0;
	int flag1 = 0;
	int sand = 0;
	int lose1 = 0;
	int ConstructorCount = 0;
	char playerchoice[100];
	int CountStart = 0;
	int shoot1 = 0;
	int CounterUntilStop = 0;
	int pass1 = 0, pass2 = 0;
	int rF = 24, cF = 0;
	int CounterFloor = 0;
	int timer = 0;
	int ScrollCounter = 0, ScrollDelay = 0;
	int rEv = 33, cEv = 109;
	int rFEv = 46, cFEv = 118;
	int FloorNumber = 1;
	int OneTime = 0;
	int GetOut = 0;
	int rGuide = 0, cGuide = 0;
	int LeftLook = 0;
	int cO1 = 2, rO1 = 3;
	int cO2 = 20, rO2 = 3;
	int cO3 = 38, rO3 = 3;
	int cO4 = 43, rO4 = 3;
	int cO5 = 61, rO5 = 3;
	int cO6 = 79, rO6 = 3;
	int cO7 = 97, rO7 = 3;
	int cO8 = 0, rO8 = 0;
	int cO9 = 121, rO9 = 3;
	int cC = 85;
	int rE1 = 36, cE1 = 7;
	int rE2 = 36, cE2 = 7;
	int rEG1 = 36, cEG1 = 7;
	int rEG2 = 36, cEG2 = 7;
	int countRLEL1 = 1;
	int countRLEL2 = 1;
	int countG1 = 1;
	int countG2 = 1;
	int timer2 = 0;
	int timer3 = 0;
	int timer4 = 0;
	int timer5 = 0;
	int DelayShot = 2;
	int DeathT = 10;
	int Scounter = 0;
	int HScounter = 0;
	int GameOver = 0;
	int cCar1 = 120, rCar1 = 38;
	int cCar2 = 85, rCar2 = 38;
	int countCar1 = 0;
	int ratio1 = 1;
	int flagC = 0;
	int countHearts = 0;
	int countHearts2 = 0;
	int flagScore1 = 0, flagScore2 = 0, flagScore3 = 0, flagScore4 = 0;
	int flagTime1 = 0, flagTime2 = 0, flagTime3 = 0, flagTime4 = 0;
	int BSc = 128;
	int openG = 0;
	int TSc = 64;
	int rPlane1 = 7, cPlane1 = 120;
	int rPlane2 = 9, cPlane2 = 85;
	int rPlane3 = 11, cPlane3 = 50;
	int ratio2 = 1;
	int flagP2 = 0;
	int flagP22 = 0;
	int rPG1 = 13, rPG2 = 15, rPG3 = 17;
	int cPG1 = 113, cPG2 = 78, cPG3 = 43;
	int rSkate = 44, cSkate = 42;
	int SkateIn = 0;
	int rT = 47, cT = 95;
	int rR = 0, cR = 51;
	int RopeIn = 0;
	int tap4 = 0;
	int rMS1 = 36, cMS1 = 8;
	int rMS2 = 36, cMS2 = 8;
	int countMyShot = 0;
	int ShootON = 0;
	int countShots = 1;
	int Reload = 0, ActionReload = 1;
	int rB = 0;
	int cB = 0;
	int ct = 0;
	int rBB = 28;
	int cBB = 124;
	int win = 0;
	int gotshot = 0;
	int firsttime = 1;
	int timerBSC = 0;
	int rFC = 37, cFC = 121;
	int rEvR = 33;
	int flag6C = 1;
	int rBBS1 = rBB + 8, cBBS1 = cBB - 32;
	int rBBS2 = rBB + 10, cBBS2 = cBB - 29;
	int when = 0;
	int LevelSelection;
	int breakme = 0;
	int tryagain = 3;
	int ks = 0;
	int rT6 = 27, cT6 = 24;
	int shittybug = 0;
	int TelephRide = 0;
	int ladder = 0;
	int AutoWalk = 0;
	int AutoWalkCounter = 1;
	int FloorNumberCount = 0;
	int Reply = 0;
	int rEnemyFS = 14;
	int cEnemyFS = 68;
	char y[48][138];
	char z[48][138];
	char p[48][2000];
	int realwalk = 1;
	int letme = 0;
	int value = 0;////////////////////////////ssss
	int yeswalk = 0;
	int bufferhero = 0;
	int buffertimer = 0;
	int mark = 0;
	int rWall1 = 20, cWall1 = 210;
	int rWall2 = 20, cWall2 = 225;
	int WallLive = 0;
	int Fwall = 0;
	int flagjumpchange = 0;
	int GunsTook = 0;
	int rGS1[1000], cGS1[1000];
	int rGS2[1000], cGS2[1000];

	int rGS1Diag[1000], cGS1Diag[1000];
	int rGS2Diag[1000], cGS2Diag[1000];
	int ordered = 0;
	int orderedDiag = 0;
	int counterSH = 0;
	int counterSHDiag = 0;
	int flagSH = 0;
	int flagSHDiag = 0;
	int flagSHDiagR = 0;
	int lasersecs = 99;
	int laserstat = 0;
	int laserdelay = 0;
	int eyecount = 0;
	int wallexist = 1;
	int wall1exist = 1;
	int wall2exist = 1;
	int rFutureEv = 19, cFutureEv = 236;
	int rRF1 = 29;
	int rRF2 = 29;
	int AirTubeStat = 0, ElevON = 0;
	int Stat1 = 0;
	int Stat2 = 0;
	int rEnemy1 = 33, cEnemy1 = 525;
	int rEnemyShot = rEnemy1 + 6, cEnemyShot = cEnemy1 - 12;
	int enemy1exist = 1;
	int rCar61 = 38, cCar61 = 673;
	int sarena = 0;
	int AttachRope = 0;
	int cP61 = 835;
	int	rP61 = 15;
	int cPS61 = 835 - 2;
	int	rPS61 = 15 + 6;
	int planeexist = 1;

	PlayerInfo P[200];
	int IntroTimer = -1;
	int startgame = 0;
	int k = 1;
	int i;
	int H1 = 0;
	int H2 = 0;
	int H3 = 0;
	int max1 = -99999;
	int max2 = -99999;
	int max3 = -99999;
	int ClickFix = 0;



	for (;;)
	{

		if (level == 0)
		{

			//i = 1;

			if (k > 1)
			{
				for (i = 1; i < k; i++)
				{
					if (P[i].PlayerScore > max1)
					{
						max1 = P[i].PlayerScore;//10
						H1 = i;
						break;
					}
				}
			}

			if (k > 2)
			{
				for (i = 1; i < k; i++)
				{
					if (P[i].PlayerScore > max2 && P[i].PlayerScore <= max1 && i != H1)
					{
						max2 = P[i].PlayerScore;
						H2 = i;
						break;
					}
				}
			}

			if (k > 3)
			{
				for (i = 1; i < k; i++)
				{
					if (P[i].PlayerScore > max3 && P[i].PlayerScore <= max1 && P[i].PlayerScore <= max2 && i != H2 && i != H1)
					{
						max3 = P[i].PlayerScore;
						H3 = i;
						break;
					}
				}
			}




			system("cls");
			MainMenu(k, ClickFix);
			for (;;)
			{

				for (; !_kbhit();)
				{


					if (k == 1)
					{
						ClickFix = 1;
					}
					if (k > 1)
					{
						ClickFix = 1;

					}
					if (startgame == 1)
					{
						break;
					}

				}

				char kboard000 = _getch();
				InsideMenu(kboard000, P, startgame, H1, H2, H3, HScounter, k, ks, ClickFix, Reply);
				if (startgame == 1)
				{
					break;
				}
			}


			level = 6;


		}


		if (tryagain == 3)
		{
			system("cls");
			cout << "\nNick-name: ";
			for (;;)
			{
				gets_s(P[k].PlayerName);
				if (P[k].PlayerName[0] == 32 || P[k].PlayerName[0] == NULL || P[k].PlayerName[0] == '`')
				{
					system("cls");
					cout << "\nNick-name: ";
				}
				else
				{
					break;
				}
			}

		}


		ScrollCounter = 1;
		if (level == 6)
		{

			rH = 36;
			cH = 4;
			rO1 = -2;
			rO2 = -2;
			rO3 = -2;
			rO4 = -2;
			rO5 = -2;
			rO6 = -2;
			rO7 = -2;
			rO9 = -2;
			CounterUntilStop = 25;

			for (;;)
			{
				for (; !_kbhit(); )
				{
					if (value >= 216 && value < 395 && rH < 30 && AirTubeStat == 1)
					{
						value += 4;
						cH += 2;

					}
					if (AttachRope == 1 && value >= 530 && value <= 690)
					{
						value += 4;
						cH = value + 8;
						if (value >= 690)
						{
							rH = 36;
							cH = 3 + value;
							AttachRope = 0;
						}
					}
					GameMap6(p, level, TelephRide, ladder, rH, cH, value, GunsTook, AttachRope);
					StaticObjects2(p, cO1, rO1, cO2, rO2, cO3, rO3, cO4, rO4, cO5, rO5, cO6, rO6, cO7, rO7, cO8, rO8, cO9, rO9);
					StaticFloor(p, cF, CounterFloor, level, value);


					if (TelephRide == 1 && ladder == 0)
					{
						cH = 21;
						rH = 30;
						TelephRide = 2;
						StaticHero6(p, rH, cH, countRLHL1, CountStart, LeftLook, rEv, Reload, ActionReload, level, rB, cB, DeathT, lose1);
					}
					if (TelephRide == 2 && ladder == 0)
					{
						StaticHero6(p, rH, cH, countRLHL1, CountStart, LeftLook, rEv, Reload, ActionReload, level, rB, cB, DeathT, lose1);
					}
					if ((TelephRide == 0 || TelephRide == 3) && ladder == 0 && flag1 == 0 && AirTubeStat == 0)
					{
						if (bufferhero % 3 == 0 && mark == 1 && buffertimer < 6 && tryagain < 3)
						{
							StaticHero(p, rH, cH, countRLHL1, CountStart, LeftLook, rEv, Reload, ActionReload, level, rB, cB, GunsTook, laserstat, lasersecs, eyecount);
							buffertimer++;
							if (buffertimer >= 6)
							{
								buffertimer = 0;
								mark = 0;
							}
						}
						if (mark == 0)
						{
							StaticHero(p, rH, cH, countRLHL1, CountStart, LeftLook, rEv, Reload, ActionReload, level, rB, cB, GunsTook, laserstat, lasersecs, eyecount);
						}
					}
					if ((TelephRide == 0 || TelephRide == 3) && ladder == 0 && flag1 == 1 && AirTubeStat == 0)
					{
						if (bufferhero % 3 == 0 && mark == 1 && buffertimer < 6 && tryagain < 3)
						{
							StaticHeroJumpChange(p, rH, cH);
							buffertimer++;
							if (buffertimer >= 6)
							{
								buffertimer = 0;
								mark = 0;
							}
						}
						if (mark == 0)
						{
							StaticHeroJumpChange(p, rH, cH);
						}

					}

					if (TelephRide == 0 && ladder == 1)
					{
						cH = 20 + value;
						rH = 35;
						ladder = 2;
						StaticHero6_2(p, rH, cH, countRLHL1);
					}
					if (TelephRide == 0 && ladder == 2)
					{
						StaticHero6_2(p, rH, cH, countRLHL1);
					}
					if (AutoWalk == 1 || AirTubeStat == 1 || AttachRope == 1)
					{
						realwalk++;
						DynamicObjects2_2(p, cO1, rO1, cO2, rO2, cO3, rO3, cO4, rO4, cO5, rO5, cO6, rO6, cO7, rO7, cO8, rO8, cO9, rO9, CounterUntilStop, level, AutoWalk, value, AirTubeStat, AttachRope);
					}
					if (value >= 218 && value < 395 && rH < 30 && AirTubeStat == 1)
					{
						ShapeForTube(p, rH, cH, AirTubeStat);
					}

					Telepherique(p, rH, cH, rT6, cT6, cFC, value, TelephRide);
					CounterFloor++;
					if (ElevON != 1 && AirTubeStat != 1)
					{
						ToLand(p, rH, cH, flag1, GetOut, LeftLook, level, rEv, SkateIn, rSkate, cSkate, RopeIn, cR, tap4);
						JumpReaction(p, rH, cH, flag1, GetOut, LeftLook, level, SkateIn, rSkate, cSkate, RopeIn, cR, tap4);
					}
					TimeCounter(p, mins, secs, CounterUntilStop, lose1, DeathT, level, shoot1, value);
					HealthBar(p, rH, cH, shoot1, lose1, DeathT, level, countHearts, countHearts2, mins, value);
					LevelCounter(p, level);
					AutoForward(p, rH, cH, countRLHL1, flag1, CounterUntilStop, pass1, pass2, lose1, ScrollCounter, GetOut, LeftLook, rEv, level, DeathT, shoot1, SkateIn, rSkate, cSkate, RopeIn, rR, cR, rMS1, cMS1, rMS2, cMS2, ShootON, countShots, rB, cB, ct, win, rEvR, cT6, cFC, TelephRide, ladder, Reload, ActionReload, AutoWalk, realwalk, letme, value, GunsTook, AutoWalkCounter, ElevON, AirTubeStat, yeswalk);
					Constructor(p, rH, cH, ConstructorCount, timer, CounterUntilStop, rGuide, cGuide, cC, level, GetOut, timer2, timer3, BSc, flagScore1, flagScore2, flagScore3, timer4, flagTime1, flagTime2, flagTime3, TSc, mins, flagScore4, flagTime4, timer5, win, timerBSC, rFC, cFC, TelephRide, tryagain, value, lasersecs, laserstat, ElevON, AirTubeStat);
					HighScore(p, rH, cH, Scounter, CounterUntilStop, HScounter, level, shoot1, flagScore1, flagScore2, flagScore3, AutoWalk, value);
					StaticWallEnemy(p, rH, cH, rWall1, cWall1, rWall2, cWall2, Fwall, value, wallexist, wall1exist, wall2exist, shoot1);
					DynamicWallEnemy(p, rH, cH, rWall1, cWall1, rWall2, cWall2, Fwall, value, shoot1, wall1exist, wall2exist);
					GunShots(p, rH, cH, rGS1, rGS2, cGS1, cGS2, counterSH, ordered, value, flagSH, wall1exist, wall2exist, enemy1exist, cEnemy1);
					GunShotsDiag(p, rH, cH, rGS1Diag, rGS2Diag, cGS1Diag, cGS2Diag, counterSHDiag, orderedDiag, value, flagSHDiag, wall1exist, wall2exist, enemy1exist, cEnemy1,planeexist,rEnemy1);
					Lasering(p, rH, cH, laserstat, lasersecs, laserdelay, LeftLook, ladder, TelephRide, wall1exist, wall2exist, enemy1exist, level, cEnemy1, rEnemy1, planeexist);
					StaticFutureElev(p, rFutureEv, cFutureEv, ElevON, AirTubeStat, rRF1);
					DynamicFutureElev(p, rH, cH, rFutureEv, cFutureEv, ElevON, AirTubeStat, countRLHL1, rRF1, Stat1);
					StaticEnemy61(p, rH, cH, rEnemy1, cEnemy1, countRLEL1, enemy1exist);
					DynamicEnemy61(p, rH, cH, rEnemy1, cEnemy1, value);
					StaticShot61(p, rH, cH, rEnemyShot, cEnemyShot, enemy1exist, value);
					DynamicShot61(p, rH, cH, rEnemyShot, cEnemyShot, enemy1exist, shoot1, rEnemy1, cEnemy1, value);
					StaticCar61(p, rCar61, cCar61, rH, cH);
					DynamicCar61(p, rCar61, cCar61, rH, cH, sarena, shoot1, value);
					StaticRope(p, rH, cH, AttachRope);
					DynamicRope(p, rH, cH, AttachRope, value);
					StaticPlane61(p, rP61, cP61, rH, cH, planeexist);
					DynamicPlane61(p, rP61, cP61, rH, cH, value);
					StaticPlaneShot61(p, rPS61, cPS61,planeexist);
					DynamicPlaneShot61(p, rPS61, cPS61, rP61, cP61, rH, cH, value, shoot1,planeexist);

					StaticAirTube(p, rH, cH, ElevON, AirTubeStat);
					DynamicAirTube(p, rH, cH, ElevON, AirTubeStat, value, Stat2);


					bufferhero++;
					eyecount++;
					countRLEL1++;
					sarena++;
					if (lose1 == 1)
					{
						mark = 1;
						break;
					}

					Output(p, ScrollCounter, cH, value);


				}

				if (lose1 == 1)
				{
					mark = 1;
					break;
				}

				char kboard6 = _getch();
				DynamicHero(p, rH, cH, kboard6, countRLHL1, flag1, CounterUntilStop, pass1, pass2, lose1, ScrollCounter, GetOut, LeftLook, rEv, level, DeathT, shoot1, SkateIn, rSkate, cSkate, RopeIn, rR, cR, rMS1, cMS1, rMS2, cMS2, ShootON, countShots, rB, cB, ct, win, rEvR, cT6, cFC, TelephRide, ladder, AutoWalk, AutoWalkCounter, realwalk, letme, value, yeswalk, flagjumpchange, GunsTook, rGS1, cGS1, rGS2, cGS2, ordered, counterSH, flagSH, laserstat, lasersecs, ElevON, AirTubeStat, AttachRope,laserdelay,orderedDiag,flagSHDiag, rGS1Diag, cGS1Diag, rGS2Diag, cGS2Diag,counterSHDiag);
				DynamicObjects2(p, cO1, rO1, cO2, rO2, cO3, rO3, cO4, rO4, cO5, rO5, cO6, rO6, cO7, rO7, cO8, rO8, cO9, rO9, CounterUntilStop, level, kboard6, AutoWalk, value, cH, yeswalk);

				realwalk++;

			}


		}


		system("cls");


		P[ks].TemprScore = Scounter;
		ks++;


		cout << "\a";
		for (;;)
		{
			system("cls");
			if (DeathT == 0)
			{
				//cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  Game Over!, the road killed you\n\n";
				//cout << "\t\t\t\t\t\t         Play again? y/n : ";
			//	cin >> noskipws >> playerchoice;

			}

			//reset all
			{
				//system("cls");

				//RESET ALL
				rH = 36;
				cH = 4;
				realwalk = 1;
				letme = 0;
				value = 0;////////////////////////////ssss
				yeswalk = 0;
				bufferhero = 0;
				buffertimer = 0;
				mark = 0;
				rWall1 = 20, cWall1 = 210;
				rWall2 = 20, cWall2 = 225;
				WallLive = 0;
				Fwall = 0;
				flagjumpchange = 0;
				GunsTook = 0;
				rGS1[1000], cGS1[1000];
				rGS2[1000], cGS2[1000];
				ordered = 0;
				counterSH = 0;
				flagSH = 0;
				lasersecs = 99;
				laserstat = 0;
				laserdelay = 0;
				eyecount = 0;
				wallexist = 1;
				wall1exist = 1;
				wall2exist = 1;
				rFutureEv = 19, cFutureEv = 236;
				rRF1 = 29;
				rRF2 = 29;
				AirTubeStat = 0, ElevON = 0;
				Stat1 = 0;
				Stat2 = 0;
				rEnemy1 = 33, cEnemy1 = 525;
				rEnemyShot = rEnemy1 + 6, cEnemyShot = cEnemy1 - 12;
				enemy1exist = 1;
				rCar61 = 38, cCar61 = 673;
				sarena = 0;
				AttachRope = 0;
				cP61 = 835;
				rP61 = 15;
				cPS61 = 835 - 2;
				rPS61 = 15 + 6;
				planeexist = 1;
				countRLHL1 = 0;
				rH = 36, cH = 8;
				mins = 9, secs = 60;
				level = 0;
				flag1 = 0;
				sand = 0;
				lose1 = 0;
				ConstructorCount = 0;

				CountStart = 0;
				shoot1 = 0;
				CounterUntilStop = 0;
				pass1 = 0, pass2 = 0;
				rF = 24, cF = 0;
				CounterFloor = 0;
				timer = 0;
				ScrollCounter = 0, ScrollDelay = 0;
				rEv = 33, cEv = 109;
				rFEv = 46, cFEv = 118;
				FloorNumber = 1;
				OneTime = 0;
				GetOut = 0;
				rGuide = 0, cGuide = 0;
				LeftLook = 0;
				cO1 = 2, rO1 = 3;
				cO2 = 20, rO2 = 3;
				cO3 = 38, rO3 = 3;
				cO4 = 43, rO4 = 3;
				cO5 = 61, rO5 = 3;
				cO6 = 79, rO6 = 3;
				cO7 = 97, rO7 = 3;
				cO8 = 0, rO8 = 0;
				cO9 = 121, rO9 = 3;
				cC = 85;
				rE1 = 36, cE1 = 7;
				rE2 = 36, cE2 = 7;
				rEG1 = 36, cEG1 = 7;
				rEG2 = 36, cEG2 = 7;
				countRLEL1 = 1;
				countRLEL2 = 1;
				countG1 = 1;
				countG2 = 1;
				timer2 = 0;
				timer3 = 0;
				timer4 = 0;
				timer5 = 0;
				DelayShot = 2;
				DeathT = 10;
				Scounter = 0;
				//HScounter = 0;
				GameOver = 0;
				cCar1 = 120, rCar1 = 38;
				cCar2 = 85, rCar2 = 38;
				countCar1 = 0;
				ratio1 = 1;
				flagC = 0;
				countHearts = 0;
				countHearts2 = 0;
				flagScore1 = 0, flagScore2 = 0, flagScore3 = 0, flagScore4 = 0;
				flagTime1 = 0, flagTime2 = 0, flagTime3 = 0, flagTime4 = 0;
				BSc = 128;
				openG = 0;
				TSc = 64;
				rPlane1 = 7, cPlane1 = 120;
				rPlane2 = 9, cPlane2 = 85;
				rPlane3 = 11, cPlane3 = 50;
				ratio2 = 1;
				flagP2 = 0;
				flagP22 = 0;
				rPG1 = 13, rPG2 = 15, rPG3 = 17;
				cPG1 = 113, cPG2 = 78, cPG3 = 43;
				rSkate = 44, cSkate = 42;
				SkateIn = 0;
				rT = 47, cT = 95;
				rR = 0, cR = 51;
				RopeIn = 0;
				tap4 = 0;
				rMS1 = 36, cMS1 = 8;
				rMS2 = 36, cMS2 = 8;
				countMyShot = 0;
				ShootON = 0;
				countShots = 1;
				Reload = 0, ActionReload = 1;
				rB = 0;
				cB = 0;
				ct = 0;
				rBB = 28;
				cBB = 124;
				win = 0;
				gotshot = 0;
				firsttime = 1;
				timerBSC = 0;
				rFC = 37, cFC = 121;
				rEvR = 33;
				flag6C = 1;
				rBBS1 = rBB + 8, cBBS1 = cBB - 32;
				rBBS2 = rBB + 10, cBBS2 = cBB - 29;
				when = 0;
				LevelSelection;
				breakme = 0;
				tryagain = 3;
				ks = 0;
				rT6 = 27, cT6 = 24;
				shittybug = 0;
				TelephRide = 0;
				ladder = 0;
				AutoWalk = 0;
				AutoWalkCounter = 1;
				FloorNumberCount = 0;
				Reply = 0;
				rEnemyFS = 14;
				cEnemyFS = 68;

				for (;;)
				{
					system("cls");

					tryagain--;


					if (tryagain == 0)
					{
						tryagain = 3;

						level = 0;
						breakme = 1;
						int maxhere = -9999;
						for (int v = ks - 3, m = 0; m < 3; v++, m++)
						{
							if (P[v].TemprScore > maxhere)
							{
								maxhere = P[v].TemprScore;
								P[k].PlayerScore = P[v].TemprScore;
							}
						}
						k++;
						//ks = 0;

						break;
					}
					else
					{
						level = 6;
						breakme = 1;

						break;
					}

				}

				if (breakme == 1)
				{
					break;
				}

			}



		}

		if (GameOver == 1)
		{
			break;
		}

	}

	char SmileFace = 1;

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t        See you soon " << SmileFace << "\n\n";
	cout << "\n\t\t\t\t\t\t  Press ESC to close the game";
	for (;;)
	{
		char kboard00 = _getch();
		if (kboard00 == 27)
		{
			break;
		}

	}



	return(0);
}