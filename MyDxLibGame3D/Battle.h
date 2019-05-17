//*************************************************
// Battle.h
//
// 戦闘中関係のプログラム
// 戦闘中の動き、ダメージ計算などなど
//*************************************************
#ifndef _BATTLE_H_
#define _BATTLE_H_

// クラスのプロトタイプ宣言
class Window;

// ダメージを出すためのストラクト
struct Damege
{
	int damage;				// battleでのダメージを入れるとこ
	bool critical_hit_flag;	// 会心の一撃かどうかのフラグ
	bool damege_once_flag;	// ダメージ計算を一回だけするためのフラグ
};

//battleクラス
class Battle
{
public:

	// 関数プロトタイプ宣言
	Battle();
	~Battle();
	void Init(Camera *camera, Player *player);
    void In(Chara *ally1, Chara *ally2, Chara *ally3, Chara *enemy1, Chara *enemy2, Chara *enemy3, Chara *enemy4);
	void Commanding(Player *player, Enemy *enemy, Camera *camera, Map *map, Music music);
	void Playing(Player *player, Enemy *enemy, Camera *camera);
	void Updata(int *scene, Player *player, Enemy *enemy, Camera *camera, Map *map, Music *music);
	void Draw(int *scene, Player *player, Enemy *enemy, Map *map, Camera *camera, Comment_string *comment, Effect *effect, Music *music, Window *window, Memory *memory);
	bool probability(int max);
	void Flag_Reset();
	void Move_Flag_Reset();

	// 変数宣言
	int first_count;		// 最初のやつを表示させる時間
	int command_play_count;	// 打ったコマンドをplayしてるときに表示させる時間
	bool camera_flag[7];	// だれが行動してるかをカメラで判別するためのフラグ
    int turn_count;			// 現在なんターン目か
	Damege damege[7];		// それぞれ受けるダメージ

    Chara m_ally[3];		// 味方を入れるところ
    Chara m_enemy[4];		// 敵を入れるところ

	// enum型宣言（選んだコマンド用）
	enum first_command // 最初のコマンド
	{
		battle,	// 戦う
		see,	// 見る
		escape,	// 逃げる
	};
	enum second_command // 2番目のコマンド
	{
		attack,	// 攻撃
		skill,	// 特技
		magic,	// 魔法
		guard,	// 防御
		item,	// 道具
		sink,	// 溜める
	};

private:

	// battleでしか使わない関数のプロトタイプ宣言
	void Have_Spell_Draw(Chara ally, int behavior, Inventory *ally_inv, Inventory *all_inv, Comment_string *comment);
	void Command(int number, Music music);
	void Key_Anim(int number);
	Chara No_1_Speed_Get(Chara *speed0, Chara *speed1, Chara *speed2, Chara *speed3, Chara *speed4, Chara *speed5, Chara *speed6);
	void Command_Play_Move();
	void Command_Play_Draw(Comment_string *comment, Chara *chara0, Chara *chara1, Chara *chara2, Chara *chara3, Chara *chara4, Chara *chara5, Chara *chara6, int count_max);
	void Command_Choice_Draw(int number, Comment_string *comment, Window *window, Memory *memory);
    void Enemy_Kill_Next(Chara *chara, Chara *enemy, int enemy_num);
	void Hit_And_Awey(Chara *chara, Chara *enemy, bool *chara_move_flag2, bool *chara_move_flag3, int enemy_num);
	void Playing_Move(Chara *ally, Chara *enemy, int ally_num, int enemy_num);
	void Damage_Adjustment(int *damege);
	void Damage_Calculation(Chara *chara_case, int damege_source, int damege_bonus, bool physics_flag);
	void Damage_Calculation_Set(Comment_string *comment, Chara *chara_case, float command_x, float command_y, int damege_source, int damege_bonus, bool physics_flag);

	// battleでしか使わない変数
	std::string m_first_behavior[KEY_1ST_MAX_COMMAND];								// たたかう、みる、にげる
	std::string m_second_behavior[KEY_2ND_MAX_COMMAND_Y * KEY_2ND_MAX_COMMAND_X];	// こうげき、とくぎ、まほう、ぼうぎょ、どうぐ、ためる
	Vector2		m_key_pos[4];														// カーソルの座標
	Vector2		m_command_word_pos[9];												// たたかう等の文字の座標
    Vector2		m_command_pos[10];													// コマンド枠の座標
	float		m_key_move_pos[4];													// カーソルの移動座標
	bool		m_reset_command_pos_flag;											// コマンドを元に戻したかのフラグ
	bool		m_reset_command_pos_flag2;											// コマンドを元に戻したかのフラグ
	int			m_key_graph[8];														// カーソルの画像
	int			m_anim_count;														// アニメーションのためのカウント
	int			m_now_frame[4];														// アニメーションのためのフレーム
	int			m_first_frame_graph;												// ～が現れた！の時のコマンドウィンドウの画像
	int			m_count_graph[10];													// 数字の画像
    int			m_count_graph_orange[10];											// 数字の画像
    int			m_count_graph_red[10];												// 数字の画像
	int			m_key_count[4];														// 長押し
    int			m_rand_count;														// ランダムで使うようの変数
	bool		m_end_flag;															// 戦闘終了のフラグ
	int			m_rast_count;														// 最後、エンターを押した回数
};

#endif // _BATTLE_H_