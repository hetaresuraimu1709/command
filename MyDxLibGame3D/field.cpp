#include "Header.h"

Field::Field()
{
	LoadDivGraph("data/command/key.png", 8, 8, 1, 35, 25, key_graph);
	LoadDivGraph("data/command/number.png", NUMBER_MAX_X * NUMBER_MAX_Y, NUMBER_MAX_X, NUMBER_MAX_Y, (int)NUMBER_SIZE_X, (int)NUMBER_SIZE_Y, count_graph);
	LoadDivGraph("data/command/number_orange.png", NUMBER_MAX_X * NUMBER_MAX_Y, NUMBER_MAX_X, NUMBER_MAX_Y, (int)NUMBER_SIZE_X, (int)NUMBER_SIZE_Y, count_graph_orange);
	LoadDivGraph("data/command/number_red.png", NUMBER_MAX_X * NUMBER_MAX_Y, NUMBER_MAX_X, NUMBER_MAX_Y, (int)NUMBER_SIZE_X, (int)NUMBER_SIZE_Y, count_graph_red);
	menu_1st_item[0] = "どうぐ";
	menu_1st_item[1] = "まほう";
	menu_1st_item[2] = "スキル";
	menu_1st_item[3] = "ステータス";
	menu_1st_item[4] = "オプション";
}

Field::~Field()
{
}

void Field::Init()
{
	counter = 0;
	now_frame[0] = 0;
	menu_pos[0] = VectorGet(-MENU_WINDOW_SIZE_X_0, 50.0f);
	menu_pos[1] = VectorGet(50.0f, (float)SCREEN_H + 10.0f);
	key_pos[0] = VectorGet(menu_pos[0].x + KEY_POS_X_0, menu_pos[0].y + KEY_POS_Y_0);
	for (int i = 0; i < 3; i++)
	{
		command_flag[i] = false;
		behavior_flag[i] = false;
	}
}

void Field::Updata(Player *player, Music music)
{
	counter++;
	key_pos[0].x = menu_pos[0].x + 55.0f;
	if (player->menu_open_flag)
	{
		for (int i = 0; i < 3; i++)
		{
			now_frame[i] = (counter / 2) % 8;
			Set_Move_Cursor(&key_pos[i].y, KEY_INPUT_W, KEY_INPUT_S, menu_pos[i].y + 52.5f, KEY_MAX_COMMAND_0, KEY_MOVE_Y_0, &key_count[0], &key_count[1], music);
			if (!command_flag[i])
			{
				if (i != 2)
				{
					Decide_Command_2(key_pos[i],
						&key_pos[i + 1],
						&command_flag[i], &behavior_flag[i],
						menu_pos[0].y + KEY_POS_Y_0, KEY_MOVE_Y_0, 0,
						menu_pos[0].x + KEY_POS_X_0, 0, 0,
						VectorGet(KEY_2ND_COMMAND_X + KEY_2ND_POS_X, KEY_2ND_COMMAND_Y + KEY_2ND_POS_Y), music);
				}
			}
		}
	}
	MenuWindow(player);
}

void Field::Draw(Player * player, Comment_string * comment, Window * window)
{
	float rate = 0.8f;
	int space = 350;
	window->Command_Draw(menu_pos[0].x, menu_pos[0].y, MENU_WINDOW_SIZE_X_0, MENU_WINDOW_SIZE_Y_0);
	window->Command_Draw(menu_pos[1].x, menu_pos[1].y, MENU_WINDOW_SIZE_X_1, MENU_WINDOW_SIZE_Y_1);
	if (player->menu_open_flag)
	{
		for (int i = 0; i < 5; i++)
		{
			comment->Draw(menu_pos[0].x + 90.0f, menu_pos[0].y + 40.0f + (i*100.0f), menu_1st_item[i]);
		}
		status_Draw(player->c_ally, menu_pos[1], count_graph, count_graph_orange, count_graph_red, rate, comment);
	}
	//１つ目のコマンド用のカーソル
	DrawGraph((int)key_pos[0].x, (int)key_pos[0].y, key_graph[now_frame[0]], TRUE);
}

void Field::MenuWindow(Player * player)
{
	if (getKey(KEY_INPUT_Q) == KEY_STATE_PUSHDOWN)
	{
		if (player->menu_open_flag)
		{
			player->menu_open_flag = false;
		}
		else
		{
			player->menu_open_flag = true;
		}
	}
	if (player->menu_open_flag)
	{
		Command_Smooth(&menu_pos[0], VectorGet(50.0f, 50.0f), 0.3f);
		Command_Smooth(&menu_pos[1], VectorGet(50.0f, (float)(SCREEN_H - (MENU_WINDOW_SIZE_Y_1 + 50.0f))), 0.3f);
	}
	else
	{
		Command_Smooth(&menu_pos[0], VectorGet(-MENU_WINDOW_SIZE_X_0, 50.0f), 0.3f);
		Command_Smooth(&menu_pos[1], VectorGet(50.0f, (float)SCREEN_H + 10.0f), 0.3f);
	}
}

