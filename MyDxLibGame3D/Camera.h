//***********************************************
// Camera.h
//
// �J�����֌W�̃v���O����
// �t�B�[���h�A�퓬���̃J�����̓����Ȃ�
//***********************************************

#ifndef _CAMERA_H_
#define _CAMERA_H_

//�N���X�̃v���g�^�C�v�錾
class Player;

//�J�����N���X
class Camera
{
public:
	//�֐��錾
	Camera();
	~Camera();
	void Init();
	void Flag_Reset(Player &player);
	void Sight_Point_Flag_Reset();
	void Move(Player &player, Map *map);
	void Battle_Move(Player &player, Enemy &enemy, Battle &battle, Map *map);
	
	//�ϐ��錾
	Vector3 f_pos,b_pos,up;				//���W
	VECTOR sight_point;					//�J����������Ƃ���
	float v_rotate, h_rotate, t_rotate;	//�J�����̉�]�x
	bool turn_flag;						//�R�}���h�ł�����A�J�����؂�ւ��̃t���O
    bool sight_point_flag[20];			//���ꂼ��̃J�����؂�ւ��̃t���O
	bool sight_point_flag2[3];			//���ꂼ��̃J�����؂�ւ��̃t���O
	bool ones_flag;						//�������񏉊����p�̃t���O
	bool reset_flag;					//�������񏉊����p�̃t���O
};
#endif // _camera_H_