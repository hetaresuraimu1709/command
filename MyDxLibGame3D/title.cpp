#include "Header.h"

Graph Get_Graph(const TCHAR *FileName, Vector2 pos, float enl)
{
	Graph data;

	data.graph = LoadGraph(FileName);
	data.pos = pos;
	data.enl = enl;
	data.flag = false;

	return data;
}

void graph_up_down(Graph *graph, float *value, float max, float min, float variable)
{
	if (*value > max)
	{
		graph->flag = true;
	}
	else if (*value < min)
	{
		graph->flag = false;
	}
	if (graph->flag)
	{
		*value -= variable;
	}
	else
	{
		*value += variable;
	}
}

Title::Title()
{
	//カーソル
	LoadDivGraph("data/command/key.png", 8, 8, 1, 35, 25, cursor_graph);
	main_title = Get_Graph("data/title/title.png", VectorGet((float)(SCREEN_W / 2), 200.0f), 0.8f);
	title_back = Get_Graph("data/title/title_back.png", VectorGet((float)(SCREEN_W / 2), (float)(SCREEN_H / 2)), 1.5f);
	for (int i = 0; i < 3; i++)
	{
		miffy[i] = Get_Graph("data/title/title_miffy.png", VectorGet((float)((SCREEN_W / 4) * (1 + i)), 600.0f + (i * 20)), 0.8f);
	}
	for (int i = 0; i < 2; i++)
	{
		suraimu[i] = Get_Graph("data/title/title_suraimu.png", VectorGet((float)((SCREEN_W / 4) * (1 + i) + 250), 705.0f + (i * 25)), 0.8f);
		cursor_count[i] = 0;
	}
	m_anim_count = 0;
	anim_frame = 0;
	gamestart_pos = VectorGet(800.0f, (float)((SCREEN_H / 2) + 200));
	cursor_pos = VectorGet(gamestart_pos.x - 20.0f, gamestart_pos.y + 10.0f);
	window_pos = VectorGet(gamestart_pos.x - 220.0f, gamestart_pos.y - 50.0f);
	window_size = VectorGet(KEY_3RD_COMMAND_SIZE_X, KEY_3RD_COMMAND_SIZE_Y + 130.0f);
}

Title::~Title()
{
}

void Title::Move(int *scene, Music *music, bool *game_end_flag, Player *player)
{
	graph_up_down(&main_title, &main_title.enl, 0.85f, 0.75f, 0.001f);
	for (int i = 0; i < 3; i++)
	{
		graph_up_down(&miffy[i], &miffy[i].pos.y, 650.0f, 600.0f, 1.0f);
	}
	for (int i = 0; i < 2; i++)
	{
		graph_up_down(&suraimu[i], &suraimu[i].pos.y, 755.0f, 700.0f, 1.0f);
	}
	Set_Move_Cursor(&cursor_pos.y, KEY_INPUT_W, KEY_INPUT_S, gamestart_pos.y + 10.0f, 3, 100.0f, &cursor_count[0], &cursor_count[1], *music);
	if (getKey(KEY_INPUT_RETURN) == KEY_STATE_PULLUP)
	{
		if (cursor_pos.y == gamestart_pos.y + 10.0f)
		{
			music->title_enter();
			music->title_theme_Stop();
			music->title_theme_flag_reset();
			Chara_Status_Load(player->c_ally, 3, 0);
			if (getKey(KEY_INPUT_Z) == KEY_STATE_PRESSED)
			{
				Chara_Status_Load(player->c_ally, 3, -1);
			}
			*scene = s_field;
		}
		else if (cursor_pos.y == gamestart_pos.y + 110.0f)
		{
			music->title_enter();
			music->title_theme_Stop();
			music->title_theme_flag_reset();
			Chara_Status_Load(player->c_ally, 3, 1);
			*scene = s_field;
		}
		else
		{
			music->title_enter();
			*game_end_flag = true;
		}
	}
}

void Title::Draw(Comment_string *comment, Music *music, Window *window)
{
	//アニメーション用カウント
	m_anim_count++;
	if (m_anim_count % KEY_ANIM_LOAD == 0)
	{
		anim_frame++;
		if (anim_frame >= KEY_ANIM_FRAME)
		{
			anim_frame = 0;
		}
	}
	music->title_theme(0);
	DrawRotaGraph((int)title_back.pos.x, (int)title_back.pos.y, (double)title_back.enl, 0.0f, title_back.graph, true);
	for (int i = 0; i < 3; i++)
	{
		DrawRotaGraph((int)miffy[i].pos.x, (int)miffy[i].pos.y, (double)miffy[i].enl, 0.0f, miffy[i].graph, true);
	}
	for (int i = 0; i < 2; i++)
	{
		DrawRotaGraph((int)suraimu[i].pos.x, (int)suraimu[i].pos.y, (double)suraimu[i].enl, 0.0f, suraimu[i].graph, true);
	}
	window->Command_Draw(window_pos.x, window_pos.y, window_size.x, window_size.y);
	comment->Draw(gamestart_pos.x, gamestart_pos.y, "さいしょから！");
	comment->Draw(gamestart_pos.x, gamestart_pos.y + 100.0f, "つづきから！");
	comment->Draw(gamestart_pos.x, gamestart_pos.y + 200.0f, "げーむおわり！");
	DrawGraph((int)cursor_pos.x, (int)cursor_pos.y, cursor_graph[anim_frame], true);
	DrawRotaGraph((int)main_title.pos.x, (int)main_title.pos.y, (double)main_title.enl, 0.0f, main_title.graph, true);
}

End::End()
{
}

End::~End()
{
}

void End::Move(int *scene)
{
	if (getKey(KEY_INPUT_RETURN) == KEY_STATE_PULLUP)
	{
		*scene = s_title;
	}
}

void End::Draw(Comment_string *comment, Music *music)
{
	comment->Draw(800, SCREEN_H / 2, "ゲームクリア！");
	comment->Draw(740, SCREEN_H / 2 + 60, "ＳＰＡＣＥをおしてね");
	//printfDx("SPACEキーを押すのじゃ！！！\n");
}
