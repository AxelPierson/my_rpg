/*
** EPITECH PROJECT, 2019
** h
** File description:
** h
*/

#ifndef MY_RPG_H_
#define MY_RPG_H_

#include "lib.h"

#include "menu.h"
#include "window.h"
#include "button.h"
#include "sprite.h"
#include "sound.h"
#include "text.h"
#include "rectangle.h"
#include "globals.h"
#include "link.h"
#include "enum.h"
#include "scene.h"
#include "game.h"

typedef struct link_s link_t;

// -------------------------------------------------- SCENE

int loop_main_menu(window_t *window, game_t *game);

    scene_t create_scene_main_menu(void);
    int event_main_menu(window_t *window, game_t *game,
     int *button_selected);
    void update_button_selected(sfEvent event, int *index,
     int *info, scene_t *scene);
    void init_sound_main_menu(sound_t *element);
    void init_text_main_menu(text_t *element);
    void init_button_main_menu(button_t *element, sound_t *sound);
    void init_sprite_main_menu(sprite_t *element);

int new_game(game_t *game, window_t *window, void *extra);

    scene_t create_scene_game(void);
    int char_selec(game_t *game, window_t *window, void *extra);
    void write_save(game_t *game);
    void reset_spawn_value(game_t *game, sfIntRect rect_spawn);
    void init_sound_game(sound_t *element);
    void init_button_game(button_t *element, sound_t *sound);
    void init_sprite_game(sprite_t *element);
    void init_text_game(text_t *element);

int load_game(game_t *game, window_t *window, void *extra);

    scene_t create_scene_load_game(void);
    void init_text_load_game(text_t *element);
    void error_load_game(game_t *game, window_t *window);

int settings_in_menu(game_t *game, window_t *window, void *extra);

    scene_t create_scene_settings(void);
    void init_button_settings(button_t *element, sound_t *sound);
    void init_sound_settings(sound_t *element);
    void init_text_settings(text_t *element);

int credit(game_t *game, window_t *window, void *extra);

    scene_t create_scene_credit(void);
    void init_rectangle_credit(rectangle_t *element);
    void init_text_credit(text_t *element);

int pause_game(game_t *game, window_t *window, void *extra);

    scene_t create_scene_pause(void);

int settings_pause(game_t *game, window_t *window, void *extra);

    scene_t create_scene_settings_pause(void);
    void init_button_settings_pause(button_t *e, sound_t *sound);
    void init_sound_settings_pause(sound_t *element);
    void init_text_settings_pause(text_t *element);
    void init_rectangle_pause(rectangle_t *element);
    void init_button_pause(button_t *element, sound_t *sound);
    void init_sound_pause(sound_t *element);
    void init_text_pause(text_t *element);

int how_to_play(game_t *game, window_t *window, void *extra);
    
    scene_t create_scene_how_to_play(void);
    void init_sprite_htp(sprite_t *element);
    void init_text_htp(text_t *element);

void play_game(game_t *game, window_t *window);

        scene_t create_scene_game(void);
        int event_game(window_t *window, game_t *game);
        void update_game(game_t *game, window_t *window, scene_t *scene);
        int end_game(game_t *game, window_t *window);

game_t *init_game(void);
int init_globals(void);

// -------------------------------------------------- BUTTON_ACTION

int effect_vol_d(game_t *game, window_t *window, void *extra);
int effect_vol_u(game_t *game, window_t *window, void *extra);
int effect_music_d(game_t *game, window_t *window, void *extra);
int effect_music_u(game_t *game, window_t *window, void *extra);
int vol_off(game_t *game, window_t *window, void *extra);
int vol_on(game_t *game, window_t *window, void *extra);
int leave_game(game_t *game, window_t *window, void *extra);
int resume(game_t *game, window_t *window, void *extra);
int back_to_menu(game_t *game, window_t *window, void *extra);

// -------------------------------------------------- DRAW

void draw_x_button(int nb_button, button_t *button, window_t *
window, int button_selected);
void draw_button(button_t button, window_t *window, int index);
void draw_x_text(int nb_text, text_t *text, window_t *window);
void draw_parallax_menu(window_t *window, scene_t *scene);
void draw_ui(game_t *game, window_t *window);

// -------------------------------------------------- GENERIC

text_t create_text(char *path, char *str, sfVector2f
 position, sfVector2f scale);
sprite_t create_sprite(char *path, sfVector2f
 position, sfVector2f size);
sound_t create_sound(char *path, float volume
, sfBool repeat);
button_t create_button(char *b_unpressed, char *
b_pressed, sfVector2f position, sfVector2f size);
window_t *init_window(void);

void center_text(sfVector2f pos_zone, sfVector2f
 size_zone, sfText *text);
char *get_file(void);
char *strcopy(char *str);
char *cat(char *str_1, char *str_2);
int my_strlen(char const *str);
char *int_char(int nbr);
int str_ncomp(char *str1, char *str2, int length);
char **str_to_word_array(char *str, char c);
int my_getnbr (char const *str);


void update_arrow_counter(game_t *game);
void get_lock(game_t *game);
void get_bow(game_t *game);

void update_button_selected(sfEvent event, int *index,
int *info, scene_t *scene);
void played_sound_button_selected(int *index, button_t *
button, int nb_button);

void write_save(game_t *game);
int fill_map(void);

// -------------------------------------------------- MUSIC

int is_sound_activated(void);
void music_update(sound_t *element, int nb_sound);
void free_music(scene_t *scene, int nb_music);
void music_play_effect_if_activated(sound_t sound);
void pool_music(scene_t *scene, scene_t *settings);
void update_ef_vol(game_t *game);

// -------------------------------------------------- UI

checkpoint_t create_checkpoint(sfVector2f pos);
heart_t create_heart(char *path, sfVector2f position);
item_t create_item(char *path, sfVector2f position);
icon_t create_icon(char *path, sfVector2f position, sfVector2f size);
counter_t create_counter(int n, sfVector2f pos, sfVector2f scale);

void init_heart(heart_t *heart, game_t *game);
void init_item(game_t *game, item_t *item);
void init_icon(icon_t *icon);
void init_ui(game_t *game);
void init_checkpoint(game_t *game);
void init_tex(sfTexture **tex);
sfVector2f set_icon(sfVector2f i_size);

void draw_icon(game_t *game, window_t *window, int index);
void draw_map(game_t *game, window_t *window);
void draw_ui(game_t *game, window_t *window);

void increase_life(game_t *game);
void decrease_life(game_t *game);

void icon_sign(game_t *game, window_t *window);
void set_sign(checkpoint_t sign, sfIntRect ground);
void update_sign(game_t *game);

void increase_arrow(game_t *game);
void decrease_arrow(game_t *game);
void update_arrow_counter(game_t *game);
void reset_arrow(game_t *game);

void get_bow(game_t *game);
void get_lock(game_t *game);

int link_rectbox(sfVector2f r_pos, sfVector2f r_size, link_t *l);

void reset_link(game_t *game);
void reset_function(game_t *game);
void reset_item(game_t *game);

void update_ui(game_t *game);

void apply_checkpoint(game_t *game);

// -------------------------------------------------- LINK

void update_link(game_t *game);

void update_view(game_t *game, scene_t *game_scene, link_t *
link, float delta_time);

void destroy_sound_tab(game_t *game);

#endif /* !MY_RPG_H_ */