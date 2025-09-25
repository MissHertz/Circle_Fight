#include "Players.h"

//		Constructors	//
void Players::DrawRock_Slinger(Color inPlayerColor)
{
	float rock_SlingerSize = 20.f;
	rock_SlingerColor = inPlayerColor;
	DrawCircle(rock_SlingerXposition, rock_SlingerYposition, rock_SlingerSize, rock_SlingerColor);
}

void Players::DrawSwordsman(Color inPlayer2Color)
{
	float swordsmanSize = 30.f;
	swordsmanColor = inPlayer2Color;
	DrawCircle(swordsmanXposition, swordsmanYposition, swordsmanSize, swordsmanColor);
}

//		Functions		//

//	Rock Slinger //
void Players::rock_SlingerController()
{
	float playerSpeed = 280.f;
	float increasedplayerSpeed = 1.4f;
	float reducedplayerSpeed = 0.5f;

	if (IsKeyDown(KEY_A))
	{
		if (IsKeyDown(KEY_LEFT_SHIFT))
		{
			rock_SlingerXposition -= playerSpeed * increasedplayerSpeed * GetFrameTime();
		}

		if (IsKeyDown(KEY_LEFT_CONTROL))
		{
			rock_SlingerXposition -= playerSpeed * reducedplayerSpeed * GetFrameTime();
		}

		else
		{
			rock_SlingerXposition -= playerSpeed * GetFrameTime();
		}
	}

	if (IsKeyDown(KEY_D))
	{
		if (IsKeyDown(KEY_LEFT_SHIFT))
		{
			rock_SlingerXposition += playerSpeed * increasedplayerSpeed * GetFrameTime();
		}
		if (IsKeyDown(KEY_LEFT_CONTROL))
		{
			rock_SlingerXposition += playerSpeed * reducedplayerSpeed * GetFrameTime();
		}
		else
		{
			rock_SlingerXposition += playerSpeed * GetFrameTime();
		}
	}

	if (IsKeyDown(KEY_W))
	{
		if (IsKeyDown(KEY_LEFT_SHIFT))
		{
			rock_SlingerYposition -= playerSpeed * increasedplayerSpeed * GetFrameTime();
		}

		if (IsKeyDown(KEY_LEFT_CONTROL))
		{
			rock_SlingerYposition -= playerSpeed * reducedplayerSpeed * GetFrameTime();
		}

		else
		{
			rock_SlingerYposition -= playerSpeed * GetFrameTime();
		}
	}

	if (IsKeyDown(KEY_S))
	{
		if (IsKeyDown(KEY_LEFT_SHIFT))
		{
			rock_SlingerYposition += playerSpeed * increasedplayerSpeed * GetFrameTime();
		}
		if (IsKeyDown(KEY_LEFT_CONTROL))
		{
			rock_SlingerYposition += playerSpeed * reducedplayerSpeed * GetFrameTime();
		}
		else
		{
			rock_SlingerYposition += playerSpeed * GetFrameTime();
		}
	}
}

//	Swordsman	//
void Players::swordsmanController()
{
	float player2Speed = 200.f;
	float increasedplayer2Speed = 1.6f;
	float reducedplayer2Speed = 0.7f;

	if (IsKeyDown(KEY_LEFT))
	{
		if (IsKeyDown(KEY_RIGHT_SHIFT))
		{
			swordsmanXposition -= player2Speed * increasedplayer2Speed * GetFrameTime();
		}

		if (IsKeyDown(KEY_RIGHT_ALT))
		{
			swordsmanXposition -= player2Speed * reducedplayer2Speed * GetFrameTime();
		}

		else
		{
			swordsmanXposition -= player2Speed * GetFrameTime();
		}
	}

	if (IsKeyDown(KEY_RIGHT))
	{
		if (IsKeyDown(KEY_RIGHT_SHIFT))
		{
			swordsmanXposition += player2Speed * increasedplayer2Speed * GetFrameTime();
		}
		if (IsKeyDown(KEY_RIGHT_ALT))
		{
			swordsmanXposition += player2Speed * reducedplayer2Speed * GetFrameTime();
		}
		else
		{
			swordsmanXposition += player2Speed * GetFrameTime();
		}
	}

	if (IsKeyDown(KEY_UP))
	{
		if (IsKeyDown(KEY_RIGHT_SHIFT))
		{
			swordsmanYposition -= player2Speed * increasedplayer2Speed * GetFrameTime();
		}

		if (IsKeyDown(KEY_RIGHT_ALT))
		{
			swordsmanYposition -= player2Speed * reducedplayer2Speed * GetFrameTime();
		}

		else
		{
			swordsmanYposition -= player2Speed * GetFrameTime();
		}
	}

	if (IsKeyDown(KEY_DOWN))
	{
		if (IsKeyDown(KEY_RIGHT_SHIFT))
		{
			swordsmanYposition += player2Speed * increasedplayer2Speed * GetFrameTime();
		}
		if (IsKeyDown(KEY_RIGHT_ALT))
		{
			swordsmanYposition += player2Speed * reducedplayer2Speed * GetFrameTime();
		}
		else
		{
			swordsmanYposition += player2Speed * GetFrameTime();
		}
	}
}