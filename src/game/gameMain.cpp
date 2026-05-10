#include "gameMain.h"
#include <raylib.h>
#include <imgui.h>
#include <rlImGui.h>
#include "../../include/imGuiTheme.h"
#include <iostream>
#include <fstream>
#include <asserts.h>

using namespace std;

struct GameData {
	float playerX = 100;
	float playerY = 100;
} gameData;

bool initGame() {
	return true;
};

bool updateGame() {
	static float velocity = 200;
	float deltatime = GetFrameTime();
	if (deltatime > 1.0 / 5) { deltatime = 1.0f / 5; } // Never allow delta time to be bigger than 1/5 (5 frames per second)

	if (IsKeyDown(KEY_A)) { gameData.playerX -= velocity * deltatime; }
	if (IsKeyDown(KEY_D)) { gameData.playerX += velocity * deltatime; }
	if (IsKeyDown(KEY_S)) { gameData.playerY += velocity * deltatime; }
	if (IsKeyDown(KEY_W)) { gameData.playerY -= velocity * deltatime; }

	DrawRectangle(gameData.playerX, gameData.playerY, 100, 100, RED);

	ImGui::ShowDemoWindow();
	SetupImGuiStyle();

	return true;
};

void closeGame() {
	ofstream f(RESOURCES_PATH "log.txt");
	f << "Close game";
	f.close();
}
