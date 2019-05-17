//***********************************************
// Camera.h
//
// カメラ関係のプログラム
// フィールド、戦闘中のカメラの動きなど
//***********************************************

#ifndef _CAMERA_H_
#define _CAMERA_H_

//クラスのプロトタイプ宣言
class Player;

//カメラクラス
class Camera
{
public:
	//関数宣言
	Camera();
	~Camera();
	void Init();
	void Flag_Reset(Player &player);
	void Sight_Point_Flag_Reset();
	void Move(Player &player, Map *map);
	void Battle_Move(Player &player, Enemy &enemy, Battle &battle, Map *map);
	
	//変数宣言
	Vector3 f_pos,b_pos,up;				//座標
	VECTOR sight_point;					//カメラが見るところ
	float v_rotate, h_rotate, t_rotate;	//カメラの回転度
	bool turn_flag;						//コマンド打った後、カメラ切り替えのフラグ
    bool sight_point_flag[20];			//それぞれのカメラ切り替えのフラグ
	bool sight_point_flag2[3];			//それぞれのカメラ切り替えのフラグ
	bool ones_flag;						//いったん初期化用のフラグ
	bool reset_flag;					//いったん初期化用のフラグ
};
#endif // _camera_H_