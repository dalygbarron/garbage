#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include "Map.h"

#define COLOUR 1

/**
 * Does the needful.
 */
void coolStuff() {
	Map map(Vector(COLS, LINES));
	printw("size %d * %d = %d\n", map.size.x, map.size.y, map.size.x * map.size.y);
	getch();
	while (true) {
		for (int x = 0; x < map.size.x; x++) {
			for (int y = 0; y < map.size.y; y++) {
				map.setTile(Vector(x, y), 0, 32 + rand() % 94);
			}
		}
		for (int y = 0; y < map.size.y; y++) {
			move(y, 0);
			for (int x = 0; x < map.size.x; x++) {
				if (x % 2) attron(COLOR_PAIR(COLOUR));
				addch(map.getTile(Vector(x, y), 0));
				attroff(COLOR_PAIR(COLOUR));
			}
		}
		refresh();
		if (getch() == 'q') break;
	}
}

/**
 * Entrypoint of da program.
 * @param argc is the number of arguments.
 * @param argv is the value of the arguments.
 */
int main(int argc, char **args) {
	initscr();
	start_color();
	cbreak();
	noecho();
	raw();
	keypad(stdscr, TRUE);
	init_pair(COLOUR, COLOR_GREEN, COLOR_RED);
	coolStuff();
	endwin();
}