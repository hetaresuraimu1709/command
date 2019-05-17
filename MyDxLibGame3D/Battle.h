//*************************************************
// Battle.h
//
// �퓬���֌W�̃v���O����
// �퓬���̓����A�_���[�W�v�Z�ȂǂȂ�
//*************************************************
#ifndef _BATTLE_H_
#define _BATTLE_H_

// �N���X�̃v���g�^�C�v�錾
class Window;

// �_���[�W���o�����߂̃X�g���N�g
struct Damege
{
	int damage;				// battle�ł̃_���[�W������Ƃ�
	bool critical_hit_flag;	// ��S�̈ꌂ���ǂ����̃t���O
	bool damege_once_flag;	// �_���[�W�v�Z����񂾂����邽�߂̃t���O
};

//battle�N���X
class Battle
{
public:

	// �֐��v���g�^�C�v�錾
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

	// �ϐ��錾
	int first_count;		// �ŏ��̂��\�������鎞��
	int command_play_count;	// �ł����R�}���h��play���Ă�Ƃ��ɕ\�������鎞��
	bool camera_flag[7];	// ���ꂪ�s�����Ă邩���J�����Ŕ��ʂ��邽�߂̃t���O
    int turn_count;			// ���݂Ȃ�^�[���ڂ�
	Damege damege[7];		// ���ꂼ��󂯂�_���[�W

    Chara m_ally[3];		// ����������Ƃ���
    Chara m_enemy[4];		// �G������Ƃ���

	// enum�^�錾�i�I�񂾃R�}���h�p�j
	enum first_command // �ŏ��̃R�}���h
	{
		battle,	// �키
		see,	// ����
		escape,	// ������
	};
	enum second_command // 2�Ԗڂ̃R�}���h
	{
		attack,	// �U��
		skill,	// ���Z
		magic,	// ���@
		guard,	// �h��
		item,	// ����
		sink,	// ���߂�
	};

private:

	// battle�ł����g��Ȃ��֐��̃v���g�^�C�v�錾
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

	// battle�ł����g��Ȃ��ϐ�
	std::string m_first_behavior[KEY_1ST_MAX_COMMAND];								// ���������A�݂�A�ɂ���
	std::string m_second_behavior[KEY_2ND_MAX_COMMAND_Y * KEY_2ND_MAX_COMMAND_X];	// ���������A�Ƃ����A�܂ق��A�ڂ�����A�ǂ����A���߂�
	Vector2		m_key_pos[4];														// �J�[�\���̍��W
	Vector2		m_command_word_pos[9];												// �����������̕����̍��W
    Vector2		m_command_pos[10];													// �R�}���h�g�̍��W
	float		m_key_move_pos[4];													// �J�[�\���̈ړ����W
	bool		m_reset_command_pos_flag;											// �R�}���h�����ɖ߂������̃t���O
	bool		m_reset_command_pos_flag2;											// �R�}���h�����ɖ߂������̃t���O
	int			m_key_graph[8];														// �J�[�\���̉摜
	int			m_anim_count;														// �A�j���[�V�����̂��߂̃J�E���g
	int			m_now_frame[4];														// �A�j���[�V�����̂��߂̃t���[��
	int			m_first_frame_graph;												// �`�����ꂽ�I�̎��̃R�}���h�E�B���h�E�̉摜
	int			m_count_graph[10];													// �����̉摜
    int			m_count_graph_orange[10];											// �����̉摜
    int			m_count_graph_red[10];												// �����̉摜
	int			m_key_count[4];														// ������
    int			m_rand_count;														// �����_���Ŏg���悤�̕ϐ�
	bool		m_end_flag;															// �퓬�I���̃t���O
	int			m_rast_count;														// �Ō�A�G���^�[����������
};

#endif // _BATTLE_H_