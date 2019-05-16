/*
** EPITECH PROJECT, 2019
** sound
** File description:
** sound
*/

#include "my_rpg.h"

int is_sound_activated(void)
{
    if (sound_activated == true)
        return (true);
    return (false);
}

void music_play_effect_if_activated(sound_t sound)
{
    if (is_sound_activated() == true)
        sfMusic_play(sound.music);
}

void free_music(scene_t *scene, int nb_music)
{
    for (int i = 0; i < nb_music; i++)
        sfMusic_destroy(scene->sound[i].music);
}

void update_volume(sound_t element)
{
    if (element.type == EFFECT) {
        sfMusic_setVolume(element.music, effect_vol);
        return ;
    }
    if (element.type == MUSIC) {
        sfMusic_setVolume(element.music, music_vol);
        return ;
    }
}

void music_update(sound_t *element, int nb_sound)
{
    for (int i = 0; i < nb_sound; i++) {
        update_volume(element[i]);
        if (element[i].is_sound == false && is_sound_activated() == true) {
            if (element[i].is_sound == false) {
                element[i].is_sound = true;
                sfMusic_play(element[i].music);
            }
        }
        if (element[i].is_sound == true && is_sound_activated() == false) {
            sfMusic_stop(element[i].music);
            element[i].is_sound = false;
        }
    }
}