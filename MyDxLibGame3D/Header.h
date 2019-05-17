//********************************************************
// Header.h
//
// いろいろなHeaderファイルをまとめてるとこ
//********************************************************

#ifndef _HEADER_H_
#define _HEADER_H_

//いろんなヘッダーのまとめ
#include "DxLib.h"				//DXライブラリ
#include "EffekseerForDXLib.h"	//エフェクシアをDXライブラリで使えるように
#include <math.h>				//平方根出すのに使用
#include <iostream>				//CommentString用
#include <map>					//CommentString用
#include "Define.h"				//#define系の定数まとめファイル
#include "Music.h"				//サウンド系のファイル
#include "Player.h"				//プレイヤー関係のファイル
#include "Effect.h"				//エフェクト関係のファイル
#include "Camera.h"				//カメラ関係のファイル
#include "Map.h"				//フィールドマップ関係のファイル
#include "Inputkey.h"			//キー入力関係のファイル
#include "Enemy.h"				//敵関係のファイル
#include "CommentString.h"		//画像から切り抜いた文字を打ち込むプログラム関係のファイル
#include "Battle.h"				//戦闘中関係のファイル
#include "Title.h"				//タイトル関係のファイル
#include "Memory.h"				//特技やアイテムのステータス関係のファイル
#include "Npc.h"				//NonPlayerCharacter関係のファイル
#include "Window.h"				//コマンドウィンドウを書くプログラム関係のファイル
#include "Field.h"				//フィールド中のアクション関係のファイル
#include "Save.h"				//セーブ、ロード関係のファイル

//function.cppで作った関数のプロトタイプ宣言
void Turn_Around(float &now_dir, float max_dir, float speed_dir, bool &turn_flag);
void Status_Check(int *data1, int *data2, int *data3);
void Status_Loader(Chara *chara, int num, const char *_filename);
void Chara_Status_Load(Chara *chara, int num, int pattern);
void Chara_Status_Save(Chara *chara);
Chara Status_Get(std::string chara_name, char *file_name, Vector3 f_pos, Vector3 b_pos, int _hp, int _mp, int _pow, int _def, int _m_pow, int _m_res, int _ski, int _spd, int _exp, bool ally_or_enemy_flag);
Inventory Inventory_Have_Get(Inventory Inve[6], Inventory one, Inventory two, Inventory three, Inventory four, Inventory five, Inventory six);
Inventory Inventory_Get(int number, bool use_flag, int damage_bonus, int force, std::string name);
void Jump(Chara *chara);
bool Enemy_notice(Vector3 pos1, Vector3 pos2);
void rotate(float *x, float *y, const float ang, const float mx, const float my);
void Command_Smooth(Vector2 *origin_vector, Vector2 goal_vector, float cut);
void Chara_Smooth(Vector3 *origin_vector, Vector3 goal_vector, float cut);
void Chara_turn_Smooth(Vector3 *origin_vector, Vector3 goal_vector, float cut);
Vector3 Map_On_Pos(Vector2 map_chip_size, Vector2 set_pos);
VECTOR Vector3_VECTOR_In(Vector3 vector);
Vector3 VECTOR_Vector3_In(VECTOR vector);
Vector3 VectorGet(float x, float y ,float z);
Vector2 VectorGet(float x, float y);
Vector3 Add_Vector_Vector(Vector3 &v1, Vector3 v2);
Vector2 Add_Vector_Vector(Vector2 &v1, Vector2 v2);
Vector3 Sub_Vector_Vector(Vector3 &v1, Vector3 v2);
Vector2 Sub_Vector_Vector(Vector2 &v1, Vector2 v2);
Vector3 Square_Vector(Vector3 &v);
Vector2 Square_Vector(Vector2 &v);
Vector3 Mul_Vector_Scaler(Vector3 &v, float s);
Vector2 Mul_Vector_Scaler(Vector2 &v, float s);
float Vector_Length(Vector3 v);
float Vector_Length(Vector2 v);
Vector3 Vector_Normalize(Vector3 v);
Vector2 Vector_Normalize(Vector2 v);
float Vector_Dot(Vector3 v1, Vector3 v2);
Vector3 Vector_Cross(Vector3 v1, Vector3 v2);
Vector3 Vector_Cross(Vector3 p1, Vector3 p2, Vector3 p3);
void Debug_Vector3_Pos(Vector3 *pos, Vector3 *center_point,float pos_speed, float cen_speed);//デバッグ用
//コマンド用関数
bool Cursor(float pos, float max);
void Move_Cursor(float *m_key_pos, unsigned char key_code, float max, int command_max, float move, int *count, Music music);
void Set_Move_Cursor(float *m_key_pos, unsigned char key_code_1, unsigned char key_code_2, float max, int command_max, float move, int *count_1, int *count_2, Music music);
void Decide_Command(Vector2 key_pos_1, Vector2 *key_pos_2, bool *command_flag, bool *behavior_flag, float max_y, float move_y, int comand_y, float max_x, float move_x, int comand_x, Vector2 setpos, Music music);
void Decide_Command_2(Vector2 key_pos_1, Vector2 *key_pos_2, bool *command_flag, bool *behavior_flag, float max_y, float move_y, int comand_y, float max_x, float move_x, int comand_x, Vector2 setpos, Music music);
void Command_Back(bool *behavior_flag, bool *command_flag, int max_command, Music music);
void Command_Pos_Reset(Vector2 *command_origin_pos, Vector2 command_goal_pos, Vector2 *key_origin_pos, Vector2 key_goal_pos);
void Count_Draw_2D(int *number_graph, int draw_count, float x, float y);
void Count_Draw_2D(int *number_graph, int draw_count, float x, float y, float size_rate);
void Count_Draw_3D(int *number_graph, int draw_count, float x, float y, float z);
void Enemy_Count_Draw_3D(int *number_graph, int draw_count, float x, float y, float z);
void Set_HPber(float pos_x, float pos_y, float rate, int color);
void Pos_Adjustment(Vector2 *pos);
void Pos_Adjustment(Vector3 *pos);
void Status_Draw(Chara *chara, int chara_num, Vector2 m_command_pos, int *normal_graph, int *orange_graph, int *red_graph, float rate, Comment_string *comment);
#endif // _HEADER_H_