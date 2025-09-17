#include "bsq.h"

typedef struct s_map {
    int y, x;
    char empty, obst, full;
    char **grid;
} t_map;

void free_map(t_map *map) {
    if (map->grid) {
        for (int i = 0; i < map->y; i++)
            free(map->grid[i]);
        free(map->grid);
    }
}

int map_error(FILE *file, t_map *map) {
    fprintf(stderr, "map error\n");
    if (file)
        fclose(file);
    if (map)
        free_map(map);
    return 0;
}

int init_map(t_map *map, FILE *file) {
    if (!file || !map)
        return 0;

    map->y = 0;
    size_t len = 0;
    ssize_t read;
    char *line = NULL;

    read = getline(&line, &len, file);
    if (read == -1) {
        free(line);
        return 0;
    }
    int i = 0;
    while (line[i] >= '0' && line[i] <= '9') {
        map->y = map->y * 10 + (line[i] - '0');
        i++;
    }
    if (i == 0 || map->y <= 0) {
        free(line);
        return 0;
    }
    if (read < i + 3) {
        free(line);
        return 0;
    }
    map->empty = line[i++];
    map->obst = line[i++];
    map->full = line[i++];
    if (!map->empty || !map->obst || !map->full ||
        map->empty == map->obst || map->empty == map->full || map->obst == map->full) {
        free(line);
        return 0;
    }
    free(line);
    return 1;
}

int read_grid(t_map *map, FILE *file) {
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
    int max_i = 0, max_j = 0, max_size = 0;

    int **dp = calloc(map->y, sizeof(int *));
    if (!dp) return;

    for (int i = 0; i < map->y; i++) {
        dp[i] = calloc(map->x, sizeof(int));
        if (!dp[i]) return;
    }

    for (int i = 0; i < map->y; i++) {
        for (int j = 0; j < map->x; j++) {
            if (map->grid[i][j] == map->empty) {
                if (i == 0 || j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = 1 + min3(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
                if (dp[i][j] > max_size) {
                    max_size = dp[i][j];
                    max_i = i;
                    max_j = j;
                }
            }
        }
    }

    for (int i = max_i - max_size + 1; i <= max_i; i++) {
        for (int j = max_j - max_size + 1; j <= max_j; j++) {
            map->grid[i][j] = map->full;
        }
    }

    for (int i = 0; i < map->y; i++)
        free(dp[i]);
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
        if (!init_map(&map, stdin) || !read_grid(&map, stdin))
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
            } else if (!init_map(&map, file) || !read_grid(&map, file)) {
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
