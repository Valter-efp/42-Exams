#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct{
	int x;
	int y;
	int is_draw;
} Pen;

char **create_board(int width, int height){
	char **board = malloc(sizeof(char *) * height);
	for(int y = 0; y< height; y++){
		board[y] = malloc(width);
		for(int x = 0; x < width; x++)
			board[y][x] = ' ';
	}
	return board;
}

void free_board(char **board, int height){
	for(int y = 0; y < height; y++){
		free(board[y]);
	}
	free(board);
}

void print_board(char **board, int width, int height){
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            putchar(board[y][x]);
        }
        putchar('\n');
    }
}

int count_neighbours(char **board, int x, int y, int width, int height){
	int count = 0;
	for(int dy = -1; dy <= 1; dy ++){
		for(int dx = -1; dx <= 1; dx++){
			if(dx == 0 && dy == 0)
				continue;
			int ny = y + dy;
			int nx = x + dx;
			if(nx >= 0 && nx < width && ny >= 0 && ny < height){
				if(board[ny][nx] == 'O')
					count++;
			}
		}
	}
	return count;
}

void iter_game(char **board, int width, int height){
	char **new_board = create_board(width, height);
	for(int y = 0; y < height; y++){
		for (int x = 0; x < width; x++){
			int n = count_neighbours(board, x, y, width, height);
			if(board[y][x] == 'O'){
				if(n == 2 || n == 3)
					new_board[y][x] = 'O';
			} else {
				if(n == 3)
					new_board[y][x] = 'O';
			}
		}
	}
	for(int y = 0; y <height; y++){
		for(int x = 0; x < width; x++){
			board[y][x] = new_board[y][x];
		}
	}
	free_board(new_board, height);
}

void move_pen(Pen *pen, char cmd, char **board, int width, int height){
	if(cmd == 'w' && pen->y > 0)
		pen->y--;
	else if(cmd == 's' && pen->y < height-1)
		pen->y++;
	else if(cmd == 'a' && pen->x > 0)
		pen->x--;
	else if(cmd == 'd' && pen->x < width-1)
		pen->x++;
	if(pen->is_draw)
		board[pen->y][pen->x] = 'O';
}

int main(int ac, char **av){
	if(ac != 4)
		return 1;

	int width = atoi(av[1]);
	int height = atoi(av[2]);
	int iterations = atoi(av[3]);

	char **board = create_board(width, height);
	char c;
	Pen pen = {0,0,0,};

	while(read(0, &c, 1) > 0){
		if (c == 'x'){
			pen.is_draw = !pen.is_draw;
			if(pen.is_draw)
				board[pen.y][pen.x] = 'O';
		} else {
			move_pen(&pen, c, board, width, height);
		}
	}

	for(int i = 0; i < iterations; i++){
		iter_game(board, width, height);
	}
	print_board(board, width, height);
	free_board(board, height);
	return 0;
}
