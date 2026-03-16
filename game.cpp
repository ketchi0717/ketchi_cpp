#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <vector>
#include <string>

using namespace std;

struct bulletinfo {
	int x;
	int y;
	int speed;
	int direction; // 0 = right, 1 = down, 2 = left, 3 = up
	bool active;
};

int userX = 30, userY = 15;  // Initial position of the user
const int map_x = 60;
const int map_y = 30;
const int BULLET_COUNT = 20;

bulletinfo bullets[BULLET_COUNT];

void respawn_bullet(int i) {
	int edge = rand() % 4;
	bullets[i].speed = 1 + rand() % 2; // speed 1..2
	bullets[i].active = true;
	switch (edge) {
	case 0: // left -> move right
		bullets[i].x = 1;
		bullets[i].y = 1 + rand() % (map_y - 2);
		bullets[i].direction = 0;
		break;
	case 1: // top -> move down
		bullets[i].x = 1 + rand() % (map_x - 2);
		bullets[i].y = 1;
		bullets[i].direction = 1;
		break;
	case 2: // right -> move left
		bullets[i].x = map_x;
		bullets[i].y = 1 + rand() % (map_y - 2);
		bullets[i].direction = 2;
		break;
	case 3: // bottom -> move up
		bullets[i].x = 1 + rand() % (map_x - 2);
		bullets[i].y = map_y;
		bullets[i].direction = 3;
		break;
	}
}

void init_bullets() {
	for (int i = 0; i < BULLET_COUNT; ++i) {
		respawn_bullet(i);
	}
}

void update_bullets() {
	for (int i = 0; i < BULLET_COUNT; ++i) {
		if (!bullets[i].active) {
			respawn_bullet(i);
			continue;
		}
		switch (bullets[i].direction) {
		case 0: // right
			bullets[i].x += bullets[i].speed;
			break;
		case 1: // down
			bullets[i].y += bullets[i].speed;
			break;
		case 2: // left
			bullets[i].x -= bullets[i].speed;
			break;
		case 3: // up
			bullets[i].y -= bullets[i].speed;
			break;
		}
		// if out of bounds, deactivate (will respawn next frame)
		if (bullets[i].x < 1 || bullets[i].x > map_x || bullets[i].y < 1 || bullets[i].y > map_y) {
			bullets[i].active = false;
		}
	}
}

bool check_collision() {
	for (int i = 0; i < BULLET_COUNT; ++i) {
		if (!bullets[i].active) continue;
		if (bullets[i].x == userX && bullets[i].y == userY) return true;
	}
	return false;
}

void usermove() {
	if (_kbhit()) {
		int ch = _getch();
		// arrow keys come as 0 or 224 then code
		if (ch == 0 || ch == 224) {
			int ext = _getch();
			switch (ext) {
			case 72: // up
				if (userY > 2) userY--;
				break;
			case 80: // down
				if (userY < map_y - 1) userY++;
				break;
			case 75: // left
				if (userX > 2) userX--;
				break;
			case 77: // right
				if (userX < map_x - 1) userX++;
				break;
			}
		}
		else {
			switch (ch) {
			case 'w': case 'W':
				if (userY > 2) userY--;
				break;
			case 's': case 'S':
				if (userY < map_y - 1) userY++;
				break;
			case 'a': case 'A':
				if (userX > 2) userX--;
				break;
			case 'd': case 'D':
				if (userX < map_x - 1) userX++;
				break;
			case 27: // ESC
				exit(0);
			}
		}
	}
}

void print_screen() {
	// buffer: indices 1..map_y, 1..map_x
	static vector<string> screen;
	screen.assign(map_y + 1, string(map_x + 1, ' '));

	// draw border
	for (int x = 1; x <= map_x; ++x) {
		screen[1][x] = '*';
		screen[map_y][x] = '*';
	}
	for (int y = 1; y <= map_y; ++y) {
		screen[y][1] = '*';
		screen[y][map_x] = '*';
	}

	// draw bullets
	for (int i = 0; i < BULLET_COUNT; ++i) {
		if (!bullets[i].active) continue;
		int bx = bullets[i].x;
		int by = bullets[i].y;
		if (bx >= 1 && bx <= map_x && by >= 1 && by <= map_y) {
			screen[by][bx] = '*';
		}
	}

	// draw player (overwrites bullets for visibility)
	if (userX >= 1 && userX <= map_x && userY >= 1 && userY <= map_y) {
		screen[userY][userX] = '@';
	}

	// output
	system("cls");
	for (int y = 1; y <= map_y; ++y) {
		for (int x = 1; x <= map_x; ++x) {
			cout << screen[y][x];
		}
		cout << endl;
	}
}

int main() {
	// Seed RNG once
	srand(static_cast<unsigned>(time(NULL)));
	init_bullets();

	// center player initially (inside border)
	if (userX < 2) userX = map_x / 2;
	if (userY < 2) userY = map_y / 2;

	int frames = 0;
	DWORD start = GetTickCount();

	while (true) {
		usermove();
		update_bullets();
		if (check_collision()) {
			system("cls");
			DWORD elapsed = GetTickCount() - start;
			cout << "Game Over! You survived " << (elapsed / 1000.0) << " seconds (" << frames << " frames)." << endl;
			cout << "Press any key to exit..." << endl;
			_getch();
			break;
		}
		print_screen();
		frames++;
		Sleep(10);
	}

	return 0;
}