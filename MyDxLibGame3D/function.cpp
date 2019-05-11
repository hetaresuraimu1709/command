#include "Save.h"
#include "Header.h"

//向き変え
void Turn_Around(float &now_dir, float aim_dir, float speed_dir, bool &turn_flag)
{
	//正面から左に向くとき
	if (now_dir == PLAYER_REAR && (aim_dir == PLAYER_LEFT || aim_dir == PLAYER_LEFT - 45.f || aim_dir == PLAYER_LEFT + 45.f))
	{
		now_dir = 0;
	}
	//例外1
	if (aim_dir == PLAYER_REAR && (now_dir <= PLAYER_LEFT || now_dir <= PLAYER_LEFT - 45.f || now_dir <= PLAYER_LEFT + 45.f))
	{
		now_dir -= speed_dir;
		if (now_dir <= 0.f)
		{
			now_dir = aim_dir;
			turn_flag = false;
		}
	}
	//例外2
	else if (aim_dir == PLAYER_RIGHT && now_dir <= 45.f)
	{
		now_dir -= speed_dir;
		if (now_dir <= -90.f)
		{
			now_dir = aim_dir;
			turn_flag = false;
		}
	}
	//例外3
	else if (aim_dir == PLAYER_RIGHT + 45.f && (now_dir <= 45.f || now_dir <= PLAYER_LEFT))
	{
		now_dir -= speed_dir;
		if (now_dir <= -45.f)
		{
			now_dir = aim_dir;
			turn_flag = false;
		}
	}
	//例外4
	else if (aim_dir == 45.f && (now_dir >= PLAYER_RIGHT + 45.f || now_dir >= PLAYER_RIGHT))
	{
		now_dir += speed_dir;
		if (now_dir >= PLAYER_REAR + 45.f)
		{
			now_dir = aim_dir;
			turn_flag = false;
		}
	}
	//例外5
	else if (aim_dir == PLAYER_LEFT && (now_dir >= PLAYER_RIGHT + 45.f || now_dir >= PLAYER_RIGHT))
	{
		now_dir += speed_dir;
		if (now_dir >= PLAYER_REAR + PLAYER_LEFT)
		{
			now_dir = aim_dir;
			turn_flag = false;
		}
	}
	//上から見て反時計回り
	else if (now_dir > aim_dir)
	{
		now_dir -= speed_dir;
		if (now_dir <= aim_dir)
		{
			now_dir = aim_dir;
			turn_flag = false;
		}
	}
	//上から見て時計回り
	else if (now_dir < aim_dir)
	{
		now_dir += speed_dir;
		if (now_dir >= aim_dir)
		{
			now_dir = aim_dir;
			turn_flag = false;
		}
	}
}
//ステータスチェック
void Status_Check(int *data1, int *data2, int *data3)
{
	for (int i = 0; i < 13; i++)
	{
		switch (i)
		{
		case 0:
			printfDx("Lv. ");
			break;
		case 1:
			printfDx("MHP ");
			break;
		case 2:
			printfDx("HP  ");
			break;
		case 3:
			printfDx("MMP ");
			break;
		case 4:
			printfDx("MP  ");
			break;
		case 5:
			printfDx("POW ");
			break;
		case 6:
			printfDx("DEF ");
			break;
		case 7:
			printfDx("MPW ");
			break;
		case 8:
			printfDx("MRS ");
			break;
		case 9:
			printfDx("SKI ");
			break;
		case 10:
			printfDx("SPD ");
			break;
		case 11:
			printfDx("EXP ");
			break;
		case 12:
			printfDx("EXG ");
			break;
		}
		printfDx("%d  %d  %d\n", data1[i], data2[i], data3[i]);
	}
}

void Chara_Status_Load(Chara *chara ,int num)
{
	LOAD_FILE->FileLoader("data/save/chara_stats.csv", 3);

	for (int j = 0; j < num; j++)
	{
		for (int i = 0; i < 13; i++)
		{
			chara[j].status[i] = LOAD_FILE->FileGeter(j,i);
		}
	}
}
void Chara_Status_Save(Chara *chara)
{
	LOAD_FILE->File_Status_Writier("data/save/chara_stats_test.csv", 3, chara);
}

//ステータス代入
Chara Status_Get(std::string chara_name, char *file_name, Vector3 f_pos, Vector3 b_pos,int _hp, int _mp, int _pow, int _def, int _m_pow, int _m_res, int _ski, int _spd, int _exp,bool ally_or_enemy_flag)
{
	Chara name;
	name.modelHandle			= MV1LoadModel(file_name);
    name.name					= chara_name;
	name.name_origin			= chara_name;
    name.status[_level_]		= 1;
	name.f_pos					= f_pos;
	name.b_pos					= b_pos;
	name.first_pos				= b_pos;
	name.status[_max_hp_]		= _hp;
	name.status[_hp_]			= _hp;
	name.status[_max_mp_]		= _mp;
	name.status[_mp_]			= _mp;
	name.status[_pow_]			= _pow;
	name.status[_def_]			= _def;
	name.status[_m_pow_]		= _m_pow;
	name.status[_m_res_]		= _m_res;
	name.status[_ski_]			= _ski;
	name.status[_spd_]			= _spd;
	name.status[_exp_]			= _exp;
	name.status[_exp_goal_]		= EXP_GOAL_1ST;
	name.ally_or_enemy_flag		= ally_or_enemy_flag;
	//name.ally_or_enemy_flag = false;
	name.first_command_flag = false;
	for (int i = 0; i < KEY_1ST_MAX_COMMAND; i++)
	{
		name.first_behavior_flag[i] = false;
	}
	name.second_command_flag = false;
	for (int i = 0; i < KEY_2ND_MAX_COMMAND_Y * KEY_2ND_MAX_COMMAND_X; i++)
	{
		name.second_behavior_flag[i] = false;
	}
	name.magic_command_flag = false;
	for (int i = 0; i < KEY_3RD_MAX_COMMAND_Y; i++)
	{
		name.who_command_flag[i] = false;
	}
	name.turn_flag			= false;
	name.command_play_flag	= false;
	name.attack_flag		= false;
	name.set_flag			= false;
	name.chara_move_flag	= false;
	name.chara_move_flag2	= false;
	name.chara_move_flag3	= false;

	name.puls_pow			= 0;
	name.puls_def			= 0;
	name.puls_spd			= 0;

	name.damage_ones_flag	= false;

	return name;
}

//持ってるInventoryの中身を代入
Inventory Inventory_Have_Get(Inventory Inve[6], Inventory one, Inventory two, Inventory three, Inventory four, Inventory five, Inventory six)
{
	Inve[0] = one;
	Inve[1] = two;
	Inve[2] = three;
	Inve[3] = four;
	Inve[4] = five;
	Inve[5] = six;
	return *Inve;
}

//Inventoryの中身を代入
Inventory Inventory_Get(int number,bool use_flag,int damage_bonus,int force, std::string name)
{
	Inventory Inv;
	Inv.number = number;
	Inv.use_flag = use_flag;
	Inv.damage_bonus = damage_bonus;
	Inv.force = force;
	Inv.name = name;
	return Inv;
}

//エネミーの一定距離に入った時
bool Enemy_notice(Vector3 pos1, Vector3 pos2)
{
	bool flag = false;
	float f_between = 0;
	Vector3 v_between;
	v_between = Sub_Vector_Vector(pos1, pos2);
	f_between = Vector_Length(v_between);
	if (f_between < 0)
	{
		f_between *= -1;
	}
	if (f_between < ENEMY_NOTICE)
	{
		flag = true;
	}
	return flag;
}

// (camera_x,camera_z)の点を(player_x,player_z)を中心にang角回転する
void rotate(float *camera_x, float *camera_z, const float ang, const float player_x, const float player_z) {
	const float ox = *camera_x - player_x, oz = *camera_z - player_z;
	*camera_x = ox * cos(ang) + oz * sin(ang);
	*camera_z = -ox * sin(ang) + oz * cos(ang);
	*camera_x += player_x;
	*camera_z += player_z;
}

void Command_Smooth(Vector2 *origin_vector, Vector2 goal_vector, float cut)
{
    Vector2 sub_vector = Sub_Vector_Vector(goal_vector, *origin_vector);
    *origin_vector = Add_Vector_Vector(*origin_vector, Mul_Vector_Scaler(sub_vector, cut));
}

void Chara_Smooth(Vector3 *origin_vector, Vector3 goal_vector, float cut)
{
	Vector3 sub_vector = Vector_Normalize(Sub_Vector_Vector(goal_vector, *origin_vector));
	*origin_vector = Add_Vector_Vector(*origin_vector, Mul_Vector_Scaler(sub_vector, cut));
}

void Chara_turn_Smooth(Vector3 *origin_vector, Vector3 goal_vector, float cut)
{
	Vector3 sub_vector = Vector_Normalize(Sub_Vector_Vector(goal_vector, *origin_vector));
	*origin_vector = Sub_Vector_Vector(*origin_vector, Mul_Vector_Scaler(sub_vector, cut));
}

//マップのマス目でポジション決め（マスの中心にセット）
Vector3 Map_On_Pos(Vector2 map_chip_size, Vector2 set_pos)
{
	Vector3 pos;
	pos.x = map_chip_size.x / 2 + (map_chip_size.x * set_pos.x);
	pos.y = 0.0f;
	pos.z = map_chip_size.y / 2 + (map_chip_size.y * set_pos.y);
	return pos;
}

//Vector3型をVECTOR型に変換
VECTOR Vector3_VECTOR_In(Vector3 vector)
{
	VECTOR v;
	v.x = vector.x;
	v.y = vector.y;
	v.z = vector.z;
	return v;
}

//VECTOR型をVector3型に変換
Vector3 VECTOR_Vector3_In(VECTOR vector)
{
	Vector3 v;
	v.x = vector.x;
	v.y = vector.y;
	v.z = vector.z;
	return v;
}

//Vecto3型、Vecto2型を取得
Vector3 VectorGet(float x, float y, float z)
{
	Vector3 r;
	r.x = x;
	r.y = y;
	r.z = z;
	return r;
}
Vector2 VectorGet(float x, float y)
{
    Vector2 r;
    r.x = x;
    r.y = y;
    return r;
}

//（ベクトル）＋（ベクトル）
Vector3 Add_Vector_Vector(Vector3 &v1, Vector3 v2)
{
	Vector3 r;
	r.x = v1.x + v2.x;
	r.y = v1.y + v2.y;
	r.z = v1.z + v2.z;
	return r;
}
Vector2 Add_Vector_Vector(Vector2 &v1, Vector2 v2)
{
    Vector2 r;
    r.x = v1.x + v2.x;
    r.y = v1.y + v2.y;
    return r;
}

//（ベクトル）ー（ベクトル）
Vector3 Sub_Vector_Vector(Vector3 &v1, Vector3 v2)
{
	Vector3 r;
	r.x = v1.x - v2.x;
	r.y = v1.y - v2.y;
	r.z = v1.z - v2.z;
	return r;
}
Vector2 Sub_Vector_Vector(Vector2 &v1, Vector2 v2)
{
    Vector2 r;
    r.x = v1.x - v2.x;
    r.y = v1.y - v2.y;
    return r;
}

Vector3 Square_Vector(Vector3 &v)
{
	Vector3 r;
	r.x = v.x * v.x;
	r.y = v.y * v.y;
	r.z = v.z * v.z;
	return r;
}
Vector2 Square_Vector(Vector2 &v)
{
    Vector2 r;
    r.x = v.x * v.x;
    r.y = v.y * v.y;
    return r;
}

//（ベクトル）×（スカラー）
Vector3 Mul_Vector_Scaler(Vector3 &v, float s)
{
	Vector3 r;
	r.x = v.x * s;
	r.y = v.y * s;
	r.z = v.z * s;
	return r;
}
Vector2 Mul_Vector_Scaler(Vector2 &v, float s)
{
    Vector2 r;
    r.x = v.x * s;
    r.y = v.y * s;
    return r;
}

//ベクトルの長さを獲得
float Vector_Length(Vector3 v)
{
	float l = sqrtf(v.x * v.x +
					v.y * v.y +
					v.z * v.z);
	return l;
}
float Vector_Length(Vector2 v)
{
    float l = sqrtf(v.x * v.x +
        v.y * v.y);
    return l;
}

//ベクトルを正規化
Vector3 Vector_Normalize(Vector3 v)
{
	float l = Vector_Length(v);
	Vector3 n;
	n.x = v.x / l;
	n.y = 0.0f;
	n.z = v.z / l;

	return n;
}
Vector2 Vector_Normalize(Vector2 v)
{
    float l = Vector_Length(v);
    Vector2 n;
    n.x = v.x / l;
    n.y = v.y / l;

    return n;
}

//ベクトル同士の内積
float Vector_Dot(Vector3 v1, Vector3 v2)
{
	float r;
	r = ((v1.x * v2.x) +
		(v1.y * v2.y) +
		(v1.z * v2.z)) /
		(Vector_Length(v1) *
		Vector_Length(v2));
	return r;
}

//ベクトル同士の外積
Vector3 Vector_Cross(Vector3 v1, Vector3 v2)
{
	Vector3 r;
	r.x = v1.y * v2.z - v1.z * v2.y;
	r.y = v1.z * v2.x - v1.x * v2.z;
	r.z = v1.x * v2.y - v1.y * v2.x;
	return r;
}

//３点からの外積
Vector3 Vector_Cross(Vector3 p1, Vector3 p2, Vector3 p3)
{
	Vector3 v1 = Sub_Vector_Vector(p2, p1);
	Vector3 v2 = Sub_Vector_Vector(p3, p2);

	return Vector_Cross(v1, v2);
}

//Vector3型用変数のポジションデバッグ用関数（一応カメラ用）
//（ｚ押しながら上下左右でvectorをｘｚ移動、ｘ押しながら上下でvectorをｙ移動、上下左右でcenter_pointをｘｚ移動、ｃ押しながら上下でcenter_pointをｙ移動）
void Debug_Vector3_Pos(Vector3 *vector, Vector3 *center_point, float pos_speed, float cen_speed)
{
	//デバッグ用
	if (getKey(KEY_INPUT_Z) == KEY_STATE_PRESSED && getKey(KEY_INPUT_UP) == KEY_STATE_PRESSED)
	{
		vector->z += pos_speed;
	}
	if (getKey(KEY_INPUT_Z) == KEY_STATE_PRESSED && getKey(KEY_INPUT_DOWN) == KEY_STATE_PRESSED)
	{
		vector->z -= pos_speed;
	}
	if (getKey(KEY_INPUT_Z) == KEY_STATE_PRESSED && getKey(KEY_INPUT_LEFT) == KEY_STATE_PRESSED)
	{
		vector->x -= pos_speed;
	}
	if (getKey(KEY_INPUT_Z) == KEY_STATE_PRESSED && getKey(KEY_INPUT_RIGHT) == KEY_STATE_PRESSED)
	{
		vector->x += pos_speed;
	}
	if (getKey(KEY_INPUT_X) == KEY_STATE_PRESSED && getKey(KEY_INPUT_UP) == KEY_STATE_PRESSED)
	{
		vector->y += pos_speed;
	}
	if (getKey(KEY_INPUT_X) == KEY_STATE_PRESSED && getKey(KEY_INPUT_DOWN) == KEY_STATE_PRESSED)
	{
		vector->y -= pos_speed;
	}
	if (getKey(KEY_INPUT_C) != KEY_STATE_PRESSED && getKey(KEY_INPUT_Z) != KEY_STATE_PRESSED && getKey(KEY_INPUT_UP) == KEY_STATE_PRESSED)
	{
		center_point->z += cen_speed;
	}
	if (getKey(KEY_INPUT_C) != KEY_STATE_PRESSED && getKey(KEY_INPUT_Z) != KEY_STATE_PRESSED && getKey(KEY_INPUT_DOWN) == KEY_STATE_PRESSED)
	{
		center_point->z -= cen_speed;
	}
	if (getKey(KEY_INPUT_Z) != KEY_STATE_PRESSED && getKey(KEY_INPUT_LEFT) == KEY_STATE_PRESSED)
	{
		center_point->x -= cen_speed;
	}
	if (getKey(KEY_INPUT_Z) != KEY_STATE_PRESSED && getKey(KEY_INPUT_RIGHT) == KEY_STATE_PRESSED)
	{
		center_point->x += cen_speed;
	}
	if (getKey(KEY_INPUT_C) == KEY_STATE_PRESSED && getKey(KEY_INPUT_UP) == KEY_STATE_PRESSED)
	{
		center_point->y += cen_speed;
	}
	if (getKey(KEY_INPUT_C) == KEY_STATE_PRESSED && getKey(KEY_INPUT_DOWN) == KEY_STATE_PRESSED)
	{
		center_point->y -= cen_speed;
	}
	printfDx("Pos　%f : %f : %f\nCen　%f : %f : %f\n", vector->x, vector->y, vector->z, center_point->x, center_point->y, center_point->z);
}

//カーソルキーの比較用
//(座標のXroY、終着点)
bool Cursor(float pos, float max) { return pos >= max - BOKASI && pos <= max + BOKASI; }

//カーソルを動かすもの、上or下or右or左の１方向で上限も決めれる
//(カーソルの座標、どのキー押したか、カーソルがいける限界の座標、コマンドの数、１コマンド間のカーソルの移動量、長押しで動くようのカウント)
void Move_Cursor(float *key_pos, unsigned char key_code, float max, int command_max, float move, int *count, Music music)
{
	if (getKey(key_code) == KEY_STATE_PUSHDOWN)
	{
		music.cursor_move();
		if (!Cursor(*key_pos, max))
		{
			*key_pos += move;
		}
		else if (Cursor(*key_pos, max))
		{
			*key_pos = max + (-move * (command_max - 1));
		}
	}
	else if (getKey(key_code) == KEY_STATE_PRESSED)
	{
		*count += 1;
		if (*count > 20)
		{
			music.cursor_move();
			if (!Cursor(*key_pos, max))
			{
				*key_pos += move;
			}
			else if (Cursor(*key_pos, max))
			{
				*key_pos = max + (-move * (command_max - 1));
			}
		}
	}
	else if (getKey(key_code) == KEY_STATE_PULLUP)
	{
		*count = 0;
	}
}

//Move_Cursorを上下or左右でまとめたもの
//(カーソルの座標、どのキー押したか１、どのキー押したか２、カーソルがいける限界の座標、コマンドの数、１コマンド間のカーソルの移動量、長押しで動くようのカウント１、長押しで動くようのカウント２)
void Set_Move_Cursor(float *key_pos, unsigned char key_code_1, unsigned char key_code_2, float max, int command_max, float move, int *count_1, int *count_2, Music music)
{
	Move_Cursor(key_pos, key_code_1, max, command_max, -move, count_1, music);
	Move_Cursor(key_pos, key_code_2, max + (move * (command_max - 1)), command_max, move, count_2, music);
}

//カーソルにあったコマンドを入力するもの、入力後のカーソルの場所も指定する
//(今選択してるコマンドのカーソルの座標、次選択するコマンドのカーソルの座標、何番目のコマンドを決定したか、どの行動をしたか、カーソルがいける限界のY座標、１コマンド間のカーソルの移動量、コマンドの数、カーソルがいける限界のX座標、１コマンド間のカーソルの移動量、コマンドの数)
void Decide_Command(Vector2 key_pos_1, Vector2 *key_pos_2, bool *command_flag, bool *behavior_flag, float max_y, float move_y, int comand_y, float max_x, float move_x, int comand_x, Vector2 setpos, Music music)
{
	if (getKey(KEY_INPUT_RETURN) == KEY_STATE_PUSHDOWN && Cursor(key_pos_1.y, max_y + (move_y * comand_y))
		&& Cursor(key_pos_1.x, max_x + (move_x * comand_x)))
	{
		music.cursor_enter();
		*command_flag = true;
		*behavior_flag = true;
		*key_pos_2 = VectorGet(setpos.x, setpos.y);
	}
}

//カーソルにあったコマンドを入力するもの、入力後のカーソルの場所も指定する（片方のみ）
//(今選択してるコマンドのカーソルの座標、次選択するコマンドのカーソルの座標、何番目のコマンドを決定したか、どの行動をしたか、カーソルがいける限界のY座標、１コマンド間のカーソルの移動量、コマンドの数、カーソルがいける限界のX座標、１コマンド間のカーソルの移動量、コマンドの数)
void Decide_Command_2(Vector2 key_pos_1, Vector2 *key_pos_2, bool *command_flag, bool *behavior_flag, float max_y, float move_y, int comand_y, float max_x, float move_x, int comand_x, Vector2 setpos, Music music)
{
	if (getKey(KEY_INPUT_RETURN) == KEY_STATE_PUSHDOWN && Cursor(key_pos_1.y, max_y + (move_y * comand_y))
		|| Cursor(key_pos_1.x, max_x + (move_x * comand_x)))
	{
		music.cursor_enter();
		*command_flag = true;
		*behavior_flag = true;
		*key_pos_2 = VectorGet(setpos.x, setpos.y);
	}
}

//ひとつ前のコマンドに戻るもの
//(どの行動をしたか、何番目のコマンドを決定したか、コマンドの数)
void Command_Back(bool *behavior_flag, bool *command_flag, int max_command, Music music)
{
	if (getKey(KEY_INPUT_BACK) == KEY_STATE_PUSHDOWN)
	{
		music.cursor_cancel();
		for (int i = 0; i < max_command; i++)
		{
			behavior_flag[i] = false;
		}
		*command_flag = false;
	}
}
//座標を一つ前に戻す（上とセットで使う）
//(コマンドの今の座標、コマンドの目指す座標、カーソルの今の座標、カーソルの目指す座標)
void Command_Pos_Reset(Vector2 *command_origin_pos, Vector2 command_goal_pos, Vector2 *key_origin_pos, Vector2 key_goal_pos)
{
	if (getKey(KEY_INPUT_BACK) == KEY_STATE_PUSHDOWN)
	{
		*command_origin_pos = command_goal_pos;
		*key_origin_pos = key_goal_pos;
	}
}

//入れた数字を描画するもの(２Ｄ)
//(数字の画像、描画したい数字、この数字を描画するｘ座標、ｙ座標)
void Count_Draw_2D(int *number_graph, int draw_count, float x, float y)
{
	if (draw_count < 10)
	{
		DrawGraph((int)x, (int)y, number_graph[draw_count], TRUE);
	}
	else if (draw_count < 100)
	{
		DrawGraph((int)x, (int)y, number_graph[draw_count / 10], TRUE);
		DrawGraph((int)(x + NUMBER_SIZE_X - 10), (int)y, number_graph[draw_count % 10], TRUE);
	}
	else if (draw_count < 1000)
	{
		DrawGraph((int)x, (int)y, number_graph[draw_count / 100], TRUE);
		DrawGraph((int)(x + NUMBER_SIZE_X - 10), (int)y, number_graph[draw_count / 10 % 10], TRUE);
		DrawGraph((int)(x + ((NUMBER_SIZE_X - 10) * 2)), (int)y, number_graph[draw_count % 10], TRUE);
	}
}

//入れた数字を描画するもの(２Ｄ)（拡大率付き）
//(数字の画像、描画したい数字、この数字を描画するｘ座標、ｙ座標、拡大率)
void Count_Draw_2D(int *number_graph, int draw_count, float x, float y, float size_rate)
{
	if (draw_count < 10)
	{
		DrawRotaGraph((int)x, (int)y, size_rate, 0.0f, number_graph[draw_count], TRUE);
	}
	else if (draw_count < 100)
	{
		DrawRotaGraph((int)x, (int)y, size_rate, 0.0f, number_graph[draw_count / 10], TRUE);
		DrawRotaGraph((int)(x + ((NUMBER_SIZE_X - 10) * size_rate)), (int)y, size_rate, 0.0f, number_graph[draw_count % 10], TRUE);
	}
	else if (draw_count < 1000)
	{
		DrawRotaGraph((int)x, (int)y, size_rate, 0.0f, number_graph[draw_count / 100], TRUE);
		DrawRotaGraph((int)(x + ((NUMBER_SIZE_X - 10) * size_rate)), (int)y, size_rate, 0.0f, number_graph[draw_count / 10 % 10], TRUE);
		DrawRotaGraph((int)(x + (((NUMBER_SIZE_X - 10) * 2) * size_rate)), (int)y, size_rate, 0.0f, number_graph[draw_count % 10], TRUE);
	}
	else if(draw_count < 10000)
	{
		DrawRotaGraph((int)x, (int)y, size_rate, 0.0f, number_graph[draw_count / 1000], TRUE);
		DrawRotaGraph((int)(x + ((NUMBER_SIZE_X - 10) * size_rate)), (int)y, size_rate, 0.0f, number_graph[draw_count / 100 % 10], TRUE);
		DrawRotaGraph((int)(x + (((NUMBER_SIZE_X - 10) * 2) * size_rate)), (int)y, size_rate, 0.0f, number_graph[draw_count / 10 % 10], TRUE);
		DrawRotaGraph((int)(x + (((NUMBER_SIZE_X - 10) * 3) * size_rate)), (int)y, size_rate, 0.0f, number_graph[draw_count % 10], TRUE);
	}
}

//入れた数字を描画するもの(３Ｄ)
//(数字の画像、描画したい数字、この数字を描画するｘ座標、ｙ座標)
void Count_Draw_3D(int *number_graph, int draw_count, float x, float y, float z)
{
	if (draw_count < 10)
	{
		DrawBillboard3D(VGet(x, y, z), 0.5f, 0.5f, 5.0f, 0.0f, number_graph[draw_count], TRUE);
	}
	else if (draw_count < 100)
	{
		DrawBillboard3D(VGet(x + 2.5f, y, z), 0.5f, 0.5f, 5.0f, 0.0f, number_graph[draw_count / 10], TRUE);
		DrawBillboard3D(VGet(x - 2.5f, y, z), 0.5f, 0.5f, 5.0f, 0.0f, number_graph[draw_count % 10], TRUE);
	}
	else if (draw_count < 1000)
	{
		DrawBillboard3D(VGet(x + 5.0f, y, z), 0.5f, 0.5f, 5.0f, 0.0f, number_graph[draw_count / 100], TRUE);
		DrawBillboard3D(VGet(x, y, z), 0.5f, 0.5f, 5.0f, 0.0f, number_graph[draw_count / 10 % 10], TRUE);
		DrawBillboard3D(VGet(x - 5.0f, y, z), 0.5f, 0.5f, 5.0f, 0.0f, number_graph[draw_count % 10], TRUE);
	}
}

//敵の入れた数字を描画するもの(３Ｄ)
//(数字の画像、描画したい数字、この数字を描画するｘ座標、ｙ座標)
void Enemy_Count_Draw_3D(int *number_graph, int draw_count, float x, float y, float z)
{
	if (draw_count < 10)
	{
		DrawBillboard3D(VGet(x, y, z), 0.5f, 0.5f, 5.0f, 0.0f, number_graph[draw_count], TRUE);
	}
	else if (draw_count < 100)
	{
		DrawBillboard3D(VGet(x - 2.5f, y, z), 0.5f, 0.5f, 5.0f, 0.0f, number_graph[draw_count / 10], TRUE);
		DrawBillboard3D(VGet(x + 2.5f, y, z), 0.5f, 0.5f, 5.0f, 0.0f, number_graph[draw_count % 10], TRUE);
	}
	else if (draw_count < 1000)
	{
		DrawBillboard3D(VGet(x - 5.0f, y, z), 0.5f, 0.5f, 5.0f, 0.0f, number_graph[draw_count / 100], TRUE);
		DrawBillboard3D(VGet(x, y, z), 0.5f, 0.5f, 5.0f, 0.0f, number_graph[draw_count / 10 % 10], TRUE);
		DrawBillboard3D(VGet(x + 5.0f, y, z), 0.5f, 0.5f, 5.0f, 0.0f, number_graph[draw_count % 10], TRUE);
	}
}

//HPバーをつくる関数
void Set_HPber(float pos_x, float pos_y, float rate, int color)
{
	DrawBox((int)(pos_x - 7), (int)(pos_y - 7), (int)(pos_x + 157), (int)(pos_y + 37), GetColor(100, 100, 100), true);
	DrawBox((int)(pos_x - 5), (int)(pos_y - 5), (int)(pos_x + 155), (int)(pos_y + 35), GetColor(200, 200, 200), true);
	DrawBox((int)(pos_x), (int)(pos_y), (int)(pos_x + 150), (int)(pos_y + 30), GetColor(100, 0, 0), true);
	DrawBox((int)(pos_x), (int)(pos_y), (int)(pos_x + (150 * rate)), (int)(pos_y + 30), color, true);
}

void Pos_Adjustment(Vector2 *pos)
{
	printfDx("%f %f\n", pos->x, pos->y);
	if (CheckHitKey(KEY_INPUT_UP))
	{
		pos->y--;
	}
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		pos->y++;
	}
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		pos->x--;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		pos->x++;
	}
}

void Pos_Adjustment(Vector3 *pos)
{
	printfDx("%f %f %f\n", pos->x, pos->y, pos->z);
	if (CheckHitKey(KEY_INPUT_UP))
	{
		if (CheckHitKey(KEY_INPUT_Z))
		{
			pos->z++;
		}
		else
		{
			pos->y--;
		}
	}
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		if (CheckHitKey(KEY_INPUT_Z))
		{
			pos->z--;
		}
		else
		{
			pos->y++;
		}
	}
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		pos->x--;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		pos->x++;
	}
}
