/*
** EPITECH PROJECT, 2019
** create_sound
** File description:
** create_sound
*/

#include "my_rpg.h"

sound_t create_sound(char *path, float volume, sfBool repeat)
{
    sound_t element;

    element.music = sfMusic_createFromFile(path);
    sfMusic_setVolume(element.music, volume);
    sfMusic_setLoop(element.music, repeat);
    element.is_sound = false;
    element.volume = volume;
    return (element);
}