// main.cpp : Defines the entry point for the application.
#include <iostream>
#include <raylib.h>
#include <imgui.h>
#include <rlImGui.h>
#include "../../include/imGuiTheme.h"
#include <gameMain.h>

using namespace std;

int main()
{
#if PRODUCTION_BUILD == 1
	SetTraceLogLevel(LOG_NONE); // no log output from raylib to console
#endif
	
	SetConfigFlags(FLAG_WINDOW_RESIZABLE); // Game window can be resized
	InitWindow(800, 450, "TerrariaGameCpp"); // Size and name of window
	SetExitKey(NULL); // prevents exit by pressing "esc"
	SetTargetFPS(120);

	#pragma region imguiSetup
	rlImGuiSetup(true); // Setup imgui rendering for raylib
	ImGuiIO& io = ImGui::GetIO();
	io.FontGlobalScale = 1.5; // Increase font size
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable; // Enable docking
	#pragma endregion

	if (!initGame()) {
		return 0;
	}
	while (!WindowShouldClose()) {
		BeginDrawing(); // All graphics drawn in the window go between these two commands
		ClearBackground(BLACK); // Sets bg colour
		
#pragma region setupImgui
		rlImGuiBegin();

		//docking stuff
		ImGui::PushStyleColor(ImGuiCol_WindowBg, {});
		ImGui::PushStyleColor(ImGuiCol_DockingEmptyBg, {});
		ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
		ImGui::PopStyleColor(2);
#pragma endregion

		if(!updateGame()) {
			CloseWindow();
		}

#pragma region imGuiEnd
		rlImGuiEnd();
#pragma endregion
		
		EndDrawing();
	}
	CloseWindow();

	closeGame();
}
