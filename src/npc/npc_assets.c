/*
** EPITECH PROJECT, 2019
** assets
** File description:
** assets
*/

#include "lib.h"

sfTexture **fill_texture(char *file, int size)
{
    FILE *fd = fopen(file, "r");
    sfTexture **txt = malloc(sizeof(sfTexture *) * (size + 1));
    int i = 0;
    size_t n = 0;
    char *buf = NULL;

    for (; i < size; i++) {
        getline(&buf, &n, fd);
        for (int j = 0; buf[j]; j++)
            buf[j] = ((buf[j] == '\n') ? '\0' : buf[j]);
        txt[i] = sfTexture_createFromFile(buf, NULL);
        free(buf);
        buf = NULL;
        n = 0;
    }
    fclose(fd);
    return (txt);
}

sfSprite *set_sprite(sfTexture *txt)
{
    sfSprite *spr = sfSprite_create();

    sfSprite_setTexture(spr, txt, sfTrue);
    return (spr);
}

sfSprite **fill_sprites(int size, sfTexture **texture)
{
    int i = 0;
    sfSprite **spr = malloc(sizeof(sfSprite *) * (size + 1));

    while (i < size) {
        spr[i] = set_sprite(texture[i]);
        i++;
    }
    return (spr);
}