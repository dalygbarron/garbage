#include <stdlib.h>
#include <string.h>
#include <menu.h>
#include "Map.h"

void coolStuff() {
	Map map(Vector(40, 20));
	for (int y = 0; y < map.size.y; y++) {
		move(y, 0);
		for (int x = 0; x < map.size.x; x++) {
			addch(map.getTile(Vector(x, y), 0));
		}
	}
	getch();
}

int main() {
	initscr();
	start_color();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	coolStuff();
	endwin();
}

