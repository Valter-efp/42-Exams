#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

typedef struct s_map{
	int y, x;
	char empty, obst, full;
	char **grid;
} t_map;

void clean_map(t_map *map){
	if(map && map->grid){
		for(int y = 0; y < map->y; y++)
			free(map->grid[y]);
		free(map->grid);
		map->grid = NULL;
	}
}

int map_error(FILE*file, t_map *map){
	fprintf(stderr, "map error\n");
	if(map)
		clean_map(map);
	if(file)
		fclose(file);
	return 0;
}

char *read_line(FILE *file){
	char *line = NULL;
	size_t len = 0;
	if(getline(&line, &len, file) == -1){
		free(line);
		return NULL;
	}
	return line;
}

int init_header(FILE *file, t_map *map){
	if(!file || !map)
		return 0;
	
	char *line = read_line(file);
	if(!line)
		return 0;
	
	map->y = 0;
	int i = 0;

	while(line[i] >= '0' && line[i] <= '9'){
		map->y = map->y * 10 + (line[i] - '0');
		i++;
	}

	if(i == 0 || map->y <= 0 || !line[i] || !line[i+1] || !line[i+2]){
		free(line);
		//printf("ola\n");
		return 0;
	}

	map->empty = line[i++];
	map->obst = line[i++];
	map->full = line[i++];

	if(map->empty == map->obst || map->empty == map->full || map->obst == map->full){
		free(line);
		return 0;
	}

	free(line);
	return 1;
}

int load_grid(FILE *file, t_map *map){
	if(!map || !file)
		return 0;
	
	map->grid = calloc(map->y, sizeof(char *));
	if(!map->grid)
		return 0;
	
	int y = 0;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while((read = getline(&line, &len, file)) != -1 && y < map->y){
		if(y == 0)
			map->x = read -1;
		else if(map->x != read -1){
			free(line);
			return 0;
		}

		map->grid[y] = malloc(map->x + 1);
		if(!map->grid[y]){
			free(line);
			return 0;
		}

		for(int x = 0; x < map->x; x++){
			if(line[x] != map->empty && line[x] != map->obst){
				free(line);
				return 0;
			}
			map->grid[y][x] = line[x];
		}
		map->grid[y][map->x] = '\0';
		y++;
	}
	free(line);
	return (y == map->y);
}

int min3(int a, int b, int c) {
	int result = a;
	if (b < result) result = b;
	if (c < result) result = c;
	return result;
}

void mark_square(t_map *map, int i, int j, int size) {
	for (int y = i - size + 1; y <= i; y++)
		for (int x = j - size + 1; x <= j; x++)
			map->grid[y][x] = map->full;
}

void find_biggest_square(t_map *map) {
	int max_i = 0, max_j = 0, max_size = 0;

	int **square_size = calloc(map->y, sizeof(int *));
	if (!square_size) return;

	for (int i = 0; i < map->y; i++) {
		square_size[i] = calloc(map->x, sizeof(int));
		if (!square_size[i]) return;
	}

	for (int i = 0; i < map->y; i++) {
		for (int j = 0; j < map->x; j++) {
			if (map->grid[i][j] == map->empty) {
				if (i == 0 || j == 0)
					square_size[i][j] = 1;
				else
					square_size[i][j] = 1 + min3(
						square_size[i - 1][j],
						square_size[i][j - 1],
						square_size[i - 1][j - 1]
					);
				if (square_size[i][j] > max_size) {
					max_size = square_size[i][j];
					max_i = i;
					max_j = j;
				}
			}
		}
	}

	mark_square(map, max_i, max_j, max_size);

	for (int i = 0; i < map->y; i++)
		free(square_size[i]);
	free(square_size);
}

void print_grid(t_map *map) {
	if (!map || !map->grid)
		return;
	for (int i = 0; i < map->y; i++)
		printf("%s\n", map->grid[i]);
}

void process_file(const char *filename) {
	FILE *file = (filename ? fopen(filename, "r") : stdin);
	if (!file) {
		fprintf(stderr, "map error\n");
		return;
	}

	t_map map = {0};
	if (!init_header(file, &map) || !load_grid(file, &map)) {
		map_error(file, &map);
		return;
	}

	find_biggest_square(&map);
	print_grid(&map);
	clean_map(&map);

	if (file != stdin)
		fclose(file);
}

int main(int ac, char **av) {
	if (ac == 1)
		process_file(NULL);
	else {
		for (int i = 1; i < ac; i++) {
			process_file(av[i]);
			if (i < ac - 1)
				putchar('\n');
		}
	}
	return EXIT_SUCCESS;
}
