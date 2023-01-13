//
//  main.c
//  so_long
//
//  Created by Andre Almeida on 10/01/23.
//

#include <stdio.h>
#include <unistd.h>
#include <sys/fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int print_error(char *str)
{
    ft_putendl_fd("Error", 2);
    ft_putendl_fd(str, 2);
    exit(1);
}

int str_tab_len(char **tab)
{
    int len;
    
    len = 0;
    while (*tab++)
        len++;
    return (len);
}


int file_size(const char *path)
{
    char *buffer;
    int fd;
    int char_count;

    char_count = 0;
    fd = open(path, O_RDONLY);
    if (fd < 0)
        print_error("File can not be read.");
    buffer = malloc(sizeof(char));
    while (read(fd, buffer, 1))
        char_count++;
    free(buffer);
    close(fd);
    return (char_count);
}

int check_extention(const char *path, const char *extension)
{
    char *dot;
    
    if (!path && ft_strlen(path) <= ft_strlen(extension) + 1)
        return (0);
    dot = ft_strrchr(path, '.');
    if (!dot)
        return (0);
    return (ft_strncmp(dot + 1, extension, ft_strlen(dot + 1)) == 0);
}

char **parse_file(const char *path)
{
    char    **map;
    char    *buffer;
    int     len;
    int     fd;
    
    if (!check_extention(path, "ber"))
        print_error("Invalid file extension.");
    len = file_size(path);
    fd = open(path, O_RDONLY);
    if (fd < 0)
        print_error("File can not be read.");
    buffer = malloc(sizeof(char) * len);
    if (!read(fd, buffer, len))
        return (NULL);
    map = ft_split(buffer, '\n');
    if (!*map)
        print_error("Empty file.");
    free(buffer);
    close(fd);
    return map;
}

int is_rectangle(char **map)
{
    size_t len;
    
   
    if (!*map)
        return (0);
    len = strlen(*map);
    while (*++map)
    {
        if (strlen(*map) != len)
            return (0);
    }
    return (1);
}

int has_only_valid_chars(char **map)
{
    char valid[6] = "01CEP";
    int i;
    
    while (*map)
    {
        i = 0;
        while (*(*map + i))
            if (ft_strchr(valid, *(*map + i++)) == NULL)
                return (0);
        map++;
    }
    return (1);
}

int count_chars(char *str, char c)
{
    int number_of_chars;
    
    number_of_chars = 0;
    while (*str)
        if (*str++ == c)
            number_of_chars++;
    return (number_of_chars);
}

int count_number_of_chars(char **map, char c)
{
    int number_of_char;
    
    number_of_char = 0;
    while (*map)
        number_of_char += count_chars(*map++, c);
    return (number_of_char);
}


int has_valid_number_of_objects(char **map)
{
    if (count_number_of_chars(map, 'E') != 1)
        return (print_error("There should be one exit."));
    else if (count_number_of_chars(map, 'P') != 1)
        return (print_error("There should be one player."));
    else if (count_number_of_chars(map, 'C') < 1)
        return (print_error("There should be at least one collectible."));
    else if (count_number_of_chars(map, '0') < 1)
        return (print_error("There should be at least one empty space"));
    else
        return (1);
}

int is_surrounded_by_walls(char **map)
{
    int i;
    int line_count;
    
    line_count = str_tab_len(map);
    i = 0;
    while (i < line_count)
    {
        if (i == 0 || i == line_count)
        {
            if (count_chars(map[i], '1') != ft_strlen(map[i]))
                return (0);
        }
        else if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
            return (0);
        i++;
    }
    return (1);
}

char **cpy_tab(char **tab)
{
    char **cpy;
    size_t len;
    int i;
    
    len = str_tab_len(tab) * ft_strlen(*tab) * sizeof(char);
    cpy = malloc(len);
    if(!cpy)
        return (NULL);
    i = 0;
    while (tab[i])
    {
        cpy[i] = ft_strdup(tab[i]);
        i++;
    }
    return (cpy);
}

int    check_char(char *c)
{
    int is_object;
    is_object = (*c == 'C' || *c == 'E' || *c == 'P');
    *c = '_';
    return (is_object);
}

int   num_of_reachable_objects(char **map, int row, int col)
{
    if (row < 1 ||
        row > str_tab_len(map) - 2 ||
        col < 1 ||
        col > ft_strlen(*map) - 2 ||
        map[row][col] == '_' ||
        map[row][col] == '1')
        return (0);
    
    return (check_char(&map[row][col]) +
            num_of_reachable_objects(map, row, col + 1) +
            num_of_reachable_objects(map, row, col - 1) +
            num_of_reachable_objects(map, row + 1, col) +
            num_of_reachable_objects(map, row - 1, col));
}

int is_playable(char **map)
{
    char **cpy;
    int row;
    int col;
    int found_player;
    
    found_player = 0;
    cpy = cpy_tab(map);
    row = 0;
    col = 0;
    while (cpy[row] && !found_player)
    {
        col = 0;
        while (cpy[row][col] && !found_player)
        {
            if (cpy[row][col] == 'P' && found_player++)
                break;
            col++;
        }
        row++;
    }
    int num_of_obj = num_of_reachable_objects(cpy, row - 1, col - 1);
    return (num_of_obj == 2 + count_number_of_chars(map, 'C'));
}

int is_valid_map_check_map(char **map)
{
    if (!is_rectangle(map))
        return (print_error("The map must be rectangular."));
    else if (!has_only_valid_chars(map))
        return (print_error("The map has invalid characters"));
    else if (!has_valid_number_of_objects(map))
        return (print_error("The map has invalid number of objects."));
    else if (!is_surrounded_by_walls(map))
        return (print_error("The map must be closed/surrounded by walls."));
    else if (!is_playable(map))
        return (print_error("There’s no valid path in the map."));
    else
        return (1);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
    char **map  = parse_file(argv[1]);
    if (!*map)
        return (1);
    
    printf("check: %d\n", is_valid_map_check_map(map));
    
    return (0);
}
