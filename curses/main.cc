#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include "Game.h"
#include "Map.h"
#include "Dude.h"
#include "Rect.h"
#include "Util.h"

#define COLOUR 1
#define MENU_COLOUR 2
#define MENU_HEIGHT 7
#define MESSAGE_LENGTH 200

/**
 * Checks if the screen is big enough to allow play.
 * @return true if all is well, and false if the player asked to quit.
 */
bool checkScreen() {
	while (true) {
		Vector screenSize(COLS, LINES);
		if (screenSize.x >= 80 && screenSize.y >= 25) return true;
		clear();
		printw("Terminal must be at least 80x25 to play\n");
		printw("Press q to quit");
		refresh();
		if (getch() == 'q') return false;
	}
}

void renderMap(Map const &map, Dude const &player, Vector camera) {
	attron(COLOR_PAIR(COLOUR));
	for (int y = camera.y; y < camera.y + LINES - MENU_HEIGHT; y++) {
		move(y - camera.y, 0);
		for (int x = camera.x; x < camera.x + COLS; x++) {
			int tile = map.getTile(Vector(x, y), 0);
			addch(tile ? tile : ' ');
		}
	}
	attroff(COLOR_PAIR(COLOUR));
	mvaddch(player.pos.y - camera.y, player.pos.x - camera.x, '@');
	move(player.pos.y - camera.y, player.pos.x - camera.x);
}

void renderMenu(Dude const &player, char const *messages, int messageCursor) {
	attron(COLOR_PAIR(MENU_COLOUR));
	mvprintw(
		LINES - MENU_HEIGHT,
		0,
		"%s (%d %d %d)",
		"Daly Barron",
		player.pos.x,
		player.pos.y,
		0
	);
	for (int y = LINES - MENU_HEIGHT + 1; y < LINES; y++) {
		move(y, 0);
		for (int x = 0; x < COLS; x++) addch(' ');
	}
	for (int i = 0; i < MENU_HEIGHT - 1; i++) {
		char const *message = messages +
			Util::wrap(messageCursor - i - 1, MENU_HEIGHT - 1) * MESSAGE_LENGTH;
		// TODO: need to limit number of characters that can be written.
		if (i == 0) attron(A_BOLD);
		mvprintw(LINES - 1 - i, 10, "%s %d", message, i);
		if (i == 0) attroff(A_BOLD);
	}
	attroff(COLOR_PAIR(MENU_COLOUR));
}

/**
 * Does the needful.
 */
void coolStuff() {
	int messageCursor = 0;
	char messages[(MENU_HEIGHT - 1) * MESSAGE_LENGTH];
	for (int i = 0; i < sizeof(messages) * sizeof(char); i++) messages[i] = 0;
	Vector camera;
	Game game;
	game.playerInput = [game, camera, &messageCursor, &messages](
		Dude const &player
	) mutable {
		if (!checkScreen()) return Action(Action::Type::QUIT);
		Vector screenSize(COLS, LINES - MENU_HEIGHT);
		Rect midScreen(camera + screenSize / 6, screenSize / 6 * 4);
		if (!midScreen.contains(player.pos)) {
			camera = player.pos - screenSize / 2;
		}
		Map const &map = game.getCurrentMap();
		renderMenu(player, messages, messageCursor);
		renderMap(map, player, camera);
		refresh();
		Action a;
		a.type = Action::Type::MOVE;
		int ch = getch();
		if (ch == 'q') a.type = Action::Type::QUIT;
		else if (ch == 'w') a.pos.y = -1;
		else if (ch == 's') a.pos.y = 1;
		else if (ch == 'a') a.pos.x = -1;
		else if (ch == 'd') a.pos.x = 1;
		return a;
	};
	game.playerMessage = [&messages, &messageCursor](
		char const *message
	) mutable {
		strncpy(
			messages + messageCursor * MESSAGE_LENGTH,
			message,
			MESSAGE_LENGTH
		);
		messageCursor = (messageCursor + 1) % (MENU_HEIGHT - 1);
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
	init_pair(COLOUR, COLOR_GREEN, COLOR_BLACK);
	init_pair(MENU_COLOUR, COLOR_BLACK, COLOR_CYAN);
	coolStuff();
	endwin();
}