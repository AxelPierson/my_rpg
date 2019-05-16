/*
** EPITECH PROJECT, 2019
** game
** File description:
** game
*/

#ifndef GAME_H_
#define GAME_H_

#include "lib.h"
#include "link.h"
#include "music.h"
#include "scene.h"
#include "fade.h"
#include "../src/arraylist/include_vector/vector.h"
#include "ui.h"
#include "checkpoint.h"
#include "text_box.h"

typedef struct fade_s fade_t;
typedef struct link_s link_t;
typedef struct npc_s npc_t;
typedef struct people_s people_t;

typedef struct game_s {
    scene_t *scene;
    link_t *link;
    music_t *music;
    ui_t ui;
    checkpoint_t *sign;
    fade_t *fade;
    text_box_t *box;
    people_t *pop;
    int checkpoint;
    arraylist_t *zones;
    int end;
} game_t;

#endif /* !GAME_H_ */