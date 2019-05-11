//Header.h
#ifndef _HEADER_H_
#define _HEADER_H_

//いろんなヘッダーのまとめ
#include "DxLib.h"
#include "EffekseerForDXLib.h"
#include <math.h>
#include <iostream>
#include <map>
#include "Define.h"
#include "Music.h"
#include "Player.h"
#include "Effect.h"
#include "Camera.h"
#include "Map.h"
#include "Inputkey.h"
#include "Enemy.h"
#include "Comment_string.h"
#include "Battle.h"
#include "Title.h"
#include "Memory.h"
#include "Npc.h"
#include "Window.h"
#include "Field.h"
#include "Save.h"

//function.cppで作った関数のプロトタイプ宣言
void Turn_Around(float &now_dir, float max_dir, float speed_dir, bool &turn_flag);
void Status_Check(int *data1, int *data2, int *data3);
void Chara_Status_Load(Chara *chara, int num);
void Chara_Status_Save(Chara *chara);
Chara Status_Get(std::string chara_name, char *file_name, Vector3 f_pos, Vector3 b_pos, int _hp, int _mp, int _pow, int _def, int _m_pow, int _m_res, int _ski, int _spd, int _exp, bool ally_or_enemy_flag);
Inventory Inventory_Have_Get(Inventory Inve[6], Inventory one, Inventory two, Inventory three, Inventory four, Inventory five, Inventory six);
Inventory Inventory_Get(int number, bool use_flag, int damage_bonus, int force, std::string name);
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
void Move_Cursor(float *key_pos, unsigned char key_code, float max, int command_max, float move, int *count, Music music);
void Set_Move_Cursor(float *key_pos, unsigned char key_code_1, unsigned char key_code_2, float max, int command_max, float move, int *count_1, int *count_2, Music music);
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
#endif // _HEADER_H_