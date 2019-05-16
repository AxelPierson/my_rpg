##
## EPITECH PROJECT, 2019
## make
## File description:
## make
##

NAME	= my_rpg

CC	= gcc

RM	= rm -f

SRCS	= ./src/arraylist/create_delete_list.c \
	  ./src/arraylist/manage_elem.c \
	  ./src/collisions/check_collision.c \
	  ./src/collisions/collide.c \
	  ./src/function_generic/cat.c \
	  ./src/function_generic/special_str_tab.c \
	  ./src/function_generic/center_text.c \
	  ./src/function_generic/create_button.c \
	  ./src/function_generic/create_rect.c \
	  ./src/function_generic/create_rectangle.c \
	  ./src/function_generic/fill_map.c \
	  ./src/function_generic/create_sound.c \
	  ./src/function_generic/create_sprite.c \
	  ./src/function_generic/create_text.c \
	  ./src/function_generic/create_window.c \
	  ./src/function_generic/draw_button.c \
	  ./src/function_generic/draw_text.c \
	  ./src/function_generic/fade_screen.c \
	  ./src/function_generic/function_sound.c \
	  ./src/function_generic/int_char.c \
	  ./src/function_generic/my_getnbr.c \
	  ./src/function_generic/my_strlen.c \
	  ./src/function_generic/played_b_sound.c \
	  ./src/function_generic/random.c \
	  ./src/function_generic/str_ncomp.c \
	  ./src/function_generic/str_to_word_array.c \
	  ./src/function_generic/strcopy.c \
	  ./src/function_generic/update_button.c \
	  ./src/function_generic/write_save.c \
	  ./src/function_generic/update_ef_vol.c \
	  ./src/link/arrow.c \
	  ./src/link/create_link_anim_tab.c \
	  ./src/link/link.c \
	  ./src/link/link_attack.c \
	  ./src/link/link_walk.c \
	  ./src/link/ocarina.c \
	  ./src/link/sound.c \
	  ./src/link/music.c \
	  ./src/link/update_link.c \
	  ./src/main.c \
	  ./src/math/calc_direction.c \
	  ./src/math/calc_distance.c \
	  ./src/monster_functions/anim_monster.c \
	  ./src/monster_functions/check_tile_collision.c \
	  ./src/monster_functions/complete_monster_list.c \
	  ./src/monster_functions/create_slime.c \
	  ./src/monster_functions/create_boss.c \
	  ./src/monster_functions/create_ghost.c \
	  ./src/monster_functions/create_big_bird.c \
	  ./src/monster_functions/fill_list_monster.c \
	  ./src/monster_functions/monster_rand_spawn.c \
	  ./src/monster_functions/update_monst_list.c \
	  ./src/monster_functions/check_monst_collision.c \
	  ./src/monster_functions/check_monst_link_attack.c \
	  ./src/monster_functions/random_disp.c \
	  ./src/monster_functions/move_big_bird.c \
	  ./src/npc/npc.c \
	  ./src/npc/talk_npc.c \
	  ./src/npc/text_box.c \
	  ./src/npc/npc_assets.c \
	  ./src/npc/quest.c \
	  ./src/scene/credit_menu/create_scene_credit.c \
	  ./src/scene/credit_menu/credit.c \
	  ./src/scene/credit_menu/init_scene_credit.c \
	  ./src/scene/exit_game/menu.c \
	  ./src/scene/exit_menu/leave_game.c \
	  ./src/scene/game/game.c \
	  ./src/scene/game/init_game_main.c \
	  ./src/scene/new_game_menu/create_scene_game.c \
	  ./src/scene/game/end.c \
	  ./src/scene/how_to_play_game/create_scene_htp.c \
	  ./src/scene/how_to_play_game/how_to_play.c \
	  ./src/scene/how_to_play_game/init_scene_htp.c \
	  ./src/scene/load_game_menu/create_scene_load_game.c \
	  ./src/scene/load_game_menu/error_load_game.c \
	  ./src/scene/load_game_menu/init_scene_load_game.c \
	  ./src/scene/load_game_menu/load_game.c \
	  ./src/scene/main_menu/function_event.c \
	  ./src/scene/main_menu/function_init.c \
	  ./src/scene/main_menu/loop_main_menu.c \
	  ./src/scene/new_game_menu/char_selec.c \
	  ./src/scene/new_game_menu/init_scene_new_game.c \
	  ./src/scene/new_game_menu/new_game.c \
	  ./src/scene/new_game_menu/reset_spawn_value.c \
	  ./src/scene/pause_game/create_scene_pause.c \
	  ./src/scene/pause_game/init_scene_pause_game.c \
	  ./src/scene/pause_game/pause.c \
	  ./src/scene/resume_game/resume.c \
	  ./src/scene/settings_game/create_scene_settings_pause.c \
	  ./src/scene/settings_game/init_scene_settings_pause.c \
	  ./src/scene/settings_game/settings_pause.c \
	  ./src/scene/settings_menu/create_scene_settings_menu.c \
	  ./src/scene/settings_menu/init_scene_settings_menu.c \
	  ./src/scene/settings_menu/ptr_effect.c \
	  ./src/scene/settings_menu/ptr_on_off.c \
	  ./src/scene/settings_menu/settings_in_menu.c \
	  ./src/ui/apply_check.c \
	  ./src/ui/arrow.c \
	  ./src/ui/create_ui.c \
	  ./src/ui/draw_ui.c \
	  ./src/ui/extra_init.c \
	  ./src/ui/init_ui.c \
	  ./src/ui/item.c \
	  ./src/ui/life.c \
	  ./src/ui/link_rectbox.c \
	  ./src/ui/reset.c \
	  ./src/ui/sign.c \
	  ./src/ui/update_ui.c \
	  ./src/zone_manage/check_current_zone.c \
	  ./src/zone_manage/update_zone.c \
	  ./src/zone_manage/create_zone_list.c \

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include_rpg/
CFLAGS += -Wall -Wextra -lm -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
