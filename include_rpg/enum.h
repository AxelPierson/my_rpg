/*
** EPITECH PROJECT, 2019
** enum
** File description:
** enum
*/

#ifndef ENUM_H_
#define ENUM_H_

typedef enum  {
    NEW_PARTY,
    LOAD_PARTY,
    SETTINGS,
    CREDIT,
    QUIT
} button_main_menu_t;

typedef enum {
    RESUME,
    HOW_TO_PLAY,
    SETTINGS_GAME,
    BACK_TO_MENU
} button_settings_game_t;

typedef enum {
    VOL_EFFECT_D,
    VOL_EFFECT_U,
    VOL_MUSIC_D,
    VOL_MUSIC_U,
    VOL_ON,
    VOL_OFF
} button_settings_t;

typedef enum {
    MUSIC,
    EFFECT
} sound_type_t;

typedef enum {
    S_MAIN_MENU,
    S_GAME,
    S_LOAD_GAME,
    S_SETTINGS_MENU,
    S_CREDIT,
    S_PAUSE_GAME,
    S_SETTINGS_PAUSE,
    S_HOWTOPLAY
} scene_type_t;

typedef enum {
    NORMAL_LINK,
    DARK_LINK
} char_selec_t;

typedef enum {
    H_EMPTY,
    H_MID,
    H_FULL,
    L_DEAD,
    L_ALIVE,
    L_DAMAGE,
    L_HEAL
} status_heart_t;

typedef enum {
    EMPTY,
    SWORD,
    BOW,
    LOCK
} logo_t;

enum {
    I_HEAD,
    I_CHAT
};

enum {
    SND_SWORD,
    SND_ATTACK,
    SND_ATTACK1,
    SND_ATTACK2
};

enum {
    M_GREY,
    M_BLUE,
    M_GREEN,
    M_RED,
    M_GHOST,
    M_BIRD,
};

enum {
    MGREY,
    MBLUE,
    MGREEN,
    M_BOSS
};

#endif /* !ENUM_H_ */
