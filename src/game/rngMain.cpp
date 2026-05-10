#include "rngMain.h"
#include "map.h"
#include <raylib.h>
#include <imgui.h>
#include <rlImGui.h>
#include "../../include/imGuiTheme.h"
#include <iostream>
#include <fstream>
#include <asserts.h>

using namespace std;

struct rngData {
	Map map;
	Camera2D camera;
} rngData;

bool initMap() {
	rngData.map.init(128, 128);

	// setup camera
	rngData.camera.target = { 64, 64 };
	rngData.camera.rotation = 0.0f;
	rngData.camera.zoom = 5.0f;

	return true;
}

bool drawMap() {
	// Screen dimensions
	rngData.camera.offset = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };

	BeginMode2D(rngData.camera); // use camera
	
	for (int y = 0; y < rngData.map.w; y++) {
		for (int x = 0; x < rngData.map.h; x++) {
			int index = y * rngData.map.w + x;
			
			if (rngData.map.mapData[x + y * rngData.map.w]) {
				DrawRectangle(x, y, 1, 1, WHITE);
			}
			else {
				DrawRectangle(x, y, 1, 1, BLACK);
			}			
		}
	}

	//ImGui::ShowDemoWindow();
	//SetupImGuiStyle();

	return true;
};