#include <stdio.h>
#include <stdlib.h>

typedef struct s_map{
    int y, x;
    char empty, obst, full;
    char **grid;
} t_map;

void free_map(t_map *map){
    if(map->grid){
        for(int y = 0; y < map->y; y++)
            free(map->grid[y]);
        free(map->grid);
    }
}

int map_error(FILE *file, t_map *map){
    fprintf(stderr, "map error\n");
    if(file)
        fclose(file);
    if(map)
        free_map(map);
    return 0;
}

int init_header(FILE *file, t_map *map){
    if(!file || !map)
        return 0;
    
    map->y = 0;
    size_t len = 0;
    ssize_t read;
    char *line = NULL;

    read = getline(&line, &len, file);
    if(read == -1){
        free(line);
        return 0;
    }
    int i = 0;
    while(line[i] >= '0' && line[i] <= '9'){
        map->y = map->y * 10 + (line[i] - '0');
        i++;
    }
    if(i == 0 || map->y <= 0 || (read < i + 3)){
        free(line);
        return 0;
    }

    map->empty = line[i++];
    map->obst = line[i++];
    map->full = line[i++];
    if(!map->empty || !map->obst || !map->full ||
        map->empty == map->obst || map->empty == map->full || map->obst == map->full){
            free(line);
            return 0;
    }
    free(line);
    return 1;
    
}

int init_grid(FILE *file, t_map *map) {
    if (!map || !file)
        return 0;

    size_t len = 0;
    ssize_t read;
    char *line = NULL;
    int y = 0;

    map->grid = calloc(map->y, sizeof(char *));
    if (!map->grid)
        return 0;

    while ((read = getline(&line, &len, file)) != -1 && y < map->y) {
        if (y == 0)
            map->x = read - 1;
        else if (read - 1 != map->x) {
            free(line);
            return 0;
        }
        map->grid[y] = malloc(sizeof(char) * (map->x + 1));
        if (!map->grid[y]) {
            free(line);
            return 0;
        }
        for (int x = 0; x < map->x; x++) {
            if (line[x] != map->empty && line[x] != map->obst) {
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

void find_biggest_square(t_map *map) {
    int max_y = 0, max_x = 0, max_size = 0;

    int **dp = calloc(map->y, sizeof(int *));
    if (!dp) return;

    for (int y = 0; y < map->y; y++) {
        dp[y] = calloc(map->x, sizeof(int));
        if (!dp[y]) return;
    }

    for (int y = 0; y < map->y; y++) {
        for (int x = 0; x < map->x; x++) {
            if (map->grid[y][x] == map->empty) {
                if (y == 0 || x == 0)
                    dp[y][x] = 1;
                else
                    dp[y][x] = 1 + min3(dp[y - 1][x], dp[y][x - 1], dp[y - 1][x - 1]);
                if (dp[y][x] > max_size) {
                    max_size = dp[y][x];
                    max_y = y;
                    max_x = x;
                }
            }
        }
    }

    for (int y = max_y - max_size + 1; y <= max_y; y++) {
        for (int x = max_x - max_size + 1; x <= max_x; x++) {
            map->grid[y][x] = map->full;
        }
    }

    for (int y = 0; y < map->y; y++)
        free(dp[y]);
    free(dp);
}

void print_grid(t_map *map) {
    if (!map || !map->grid)
        return;

    for (int i = 0; i < map->y; i++)
        fprintf(stdout, "%s\n", map->grid[i]);
}

int main(int ac, char **av) {
    if (ac == 1) {
        t_map map = {0};
        if (!init_header(stdin, &map) || !init_grid(stdin, &map))
            return map_error(NULL, &map);
        find_biggest_square(&map);
        print_grid(&map);
        free_map(&map);
        return 0;
    } else {
        for (int i = 1; i < ac; i++) {
            t_map map = {0};
            FILE *file = fopen(av[i], "r");
            if (!file) {
                fprintf(stderr, "map error\n");
            } else if (!init_header(file, &map) || !init_grid(file, &map)) {
                map_error(file, &map);
            } else {
                find_biggest_square(&map);
                print_grid(&map);
                free_map(&map);
                fclose(file);
            }
            if (i < ac - 1)
                fprintf(stdout, "\n");
        }
        return 0;
    }
}
