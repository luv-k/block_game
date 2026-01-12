// game.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <raylib.h>
#include "game.h"
#include <iostream>

double lastUpdateTime = 0;
bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    
    InitWindow(500, 620, "Tetris");
    SetTargetFPS(60);

	Font font = LoadFontEx("monogram.ttf", 64,0,0);

    Game game = Game();

    while (WindowShouldClose() == false)
    {
        game.HandelInput();
        if (EventTriggered(0.5))
        {
            game.MoveBlockDown();
        }
        BeginDrawing();
        ClearBackground(darkBlue);
        DrawTextEx(font, "Score", { 365,15 }, 38, 2, WHITE);
		DrawTextEx(font,"Next",{370,175},38,2,WHITE);

        if (game.gameOver)
        {
            DrawTextEx(font, "GAME OVER", { 320, 450 }, 38, 2, WHITE);
		}

        DrawRectangleRounded({320,55,170,60},0.3f,6, lightBlue);

		char scoreText[10];
        sprintf_s(scoreText, sizeof(scoreText), "%d", game.score);
		Vector2 scoreTextSize = MeasureTextEx(font, scoreText, 38, 2);


        DrawTextEx(font, scoreText, { 365,(170 - scoreTextSize.x) / 2}, 38, 2, WHITE);
        DrawRectangleRounded({320,215,170,180},0.3f,6, lightBlue);
        game.Draw();
        EndDrawing();
    }
    CloseWindow();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file