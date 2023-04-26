#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include "Game.h"
#include "Map.h"
#include "Dude.h"
#include "Rect.h"
#include "Util.h"

#define COLOURS 16
#define MENU_HEIGHT 5

int colours[COLOURS][COLOURS];
int floorColour;
int menuColour;

/**
 * Initialises the colours global so that it contains a colour pair for every
 * combination of allowed colours.
 */
void initColours() {
	for (int a = 0; a < COLOURS; a++) {
		for (int b = 0; b < COLOURS; b++) {
			int index = a * COLOURS + b;
			init_pair(index, a, b);
			colours[a][b] = index;
		}
	}
	floorColour = colours[COLOR_GREEN][COLOR_BLACK];
	menuColour = colours[COLOR_WHITE][COLOR_BLACK];
}

/**
 * Converts a render params colour enum value to a curses colour value.
 * @param colour is the colour to convert.
 * @return the int coloru code.
 */
int renderParamsColour(RenderParams::Colour colour) {
	switch (colour) {
		case RenderParams::Colour::WHITE: return COLOR_WHITE;
		case RenderParams::Colour::RED: return COLOR_RED;
		default: return COLOR_BLACK;
	}
}

/**
 * Converts a render params effect to a curses colour value.
 * @param effect is the effect to convert.
 * @return the colour code.
 */
int renderParamsEffect(RenderParams::Effect effect) {
	switch (effect) {
		case RenderParams::Effect::BURNING: return COLOR_RED;
		case RenderParams::Effect::FROZEN: return COLOR_CYAN;
		case RenderParams::Effect::GLOWING: return COLOR_YELLOW;
		default: return COLOR_BLACK;
	}
}

/**
 * Converts a render params to a colour pair code which can be used to render
 * whatever it is.
 * @param params the render params to convert.
 * @return a colour pair id.
 */
int renderParamsColourPair(RenderParams params) {
	int fg = renderParamsColour(params.colour);
	int bg = renderParamsEffect(params.effect);
	return colours[fg][bg];
}

/**
 * Moves somewhere then prints some text up to the given character count, and if
 * the string given doesn't hit the character count then it continues printing
 * spaces until it hits it.
 * @param row is the row to be on.
 * @param col is the column to be on.
 * @param n is the number of characters to write.
 * @param text is the text to write.
 */
void mvnprint(int row, int col, int n, char const *text) {
	move(row, col);
	bool reading = true;
	for (int i = 0; i < n; i++) {
		if (reading) {
			char c = text[i];
			if (c) {
				addch(c);
			} else {
				addch(' ');
				reading = false;
			}
		} else {
			addch(' ');
		}
	}
}

/**
 * Checks if the screen is big enough to allow play and loops until it is.
 * @return true if all is well, and false if the player asked to quit.
 */
bool checkScreen() {
	while (true) {
		if (COLS >= 80 && LINES >= 24) return true;
		clear();
		printw(
			"Terminal must be at least 80x25 to play, but is %dx%d\n",
			COLS,
			LINES
		);
		printw("Press q to quit");
		refresh();
		if (getch() == 'q') return false;
	}
}

void renderMap(Map const &map, Dude const &player, Vector camera) {
	attron(COLOR_PAIR(floorColour));
	for (int y = camera.y; y < camera.y + LINES - MENU_HEIGHT; y++) {
		move(y - camera.y + 1, 0);
		for (int x = camera.x; x < camera.x + COLS; x++) {
			int tile = map.getTile(Vector(x, y), 0);
			addch(tile ? tile : ' ');
		}
	}
	attroff(COLOR_PAIR(floorColour));
	for (Entity const *entity: map.getEntities()) {
		RenderParams params = entity->getRenderParams();
		int colour = renderParamsColourPair(params);
		attron(COLOR_PAIR(colour));
		mvaddch(entity->pos.y - camera.y + 1, entity->pos.x - camera.x, params.c);
		attroff(COLOR_PAIR(colour));
	}
	move(0, 0);
}

void renderMenu(Dude const &player, Game const &game) {
	attron(COLOR_PAIR(menuColour));
	// Top Bar.
	mvprintw(
		0,
		0,
		"%s (%d %d %d) Healthy",
		"Daly Barron",
		player.pos.x,
		player.pos.y,
		game.messageStore.getCursor()
	);
	// Message area.
	for (int y = LINES - MENU_HEIGHT; y < LINES; y++) {
		move(y, 0);
		for (int x = 0; x < COLS; x++) addch(' ');
	}
	for (int i = 0; i < MENU_HEIGHT; i++) {
		char const *message = game.messageStore[i];
		if (i == 0) attron(A_BOLD);
		mvnprint(LINES - 1 - i, 0, COLS - 1, message);
		if (i == 0) attroff(A_BOLD);
	}
	attroff(COLOR_PAIR(menuColour));
}

/**
 * Does the needful.
 */
void coolStuff() {
	Vector camera;
	Game game;
	game.playerInput = [&game, &camera](
		Dude const &player
	) mutable {
		if (!checkScreen()) return Action(Action::Type::QUIT);
		Vector screenSize(COLS, LINES - MENU_HEIGHT);
		Rect midScreen(camera + screenSize / 6, screenSize / 6 * 4);
		if (!midScreen.contains(player.pos)) {
			camera = player.pos - screenSize / 2;
		}
		Map const &map = game.getCurrentMap();
		renderMenu(player, game);
		renderMap(map, player, camera);
		refresh();
		Action a;
		a.type = Action::Type::MOVE;
		int ch = getch();
		if (ch == 'q') {
			a.type = Action::Type::QUIT;
		} else if (ch == 'k') {
			a.pos.y = -1;
		} else if (ch == 'j') {
			a.pos.y = 1;
		} else if (ch == 'h'){
			a.pos.x = -1;
		} else if (ch == 'l') {
			a.pos.x = 1;
		} else if (ch == 'y') {
			a.pos.x = -1;
			a.pos.y = -1;
		} else if (ch == 'u') {
			a.pos.x = 1;
			a.pos.y = -1;
		} else if (ch == 'b') {
			a.pos.x = -1;
			a.pos.y = 1;
		} else if (ch == 'n') {
			a.pos.x = 1;
			a.pos.y = 1;
		}
		return a;
	};
	game.start();
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
	curs_set(0);
	initColours();
	coolStuff();
	endwin();
}