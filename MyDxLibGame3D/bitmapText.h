//********************************************************************
// BitmapText.h
// 
// ���������ʕ\������v���O����
// �����`�A���t�@�x�b�g�����񂾃r�b�g�}�b�v�摜���t�H���g�Ƃ��ēo�^
//********************************************************************

#ifndef __BITMAPTEXT_H__
#define __BITMAPTEXT_H__

// �w�b�_�[�t�@�C���̌Ăяo��
#include "DxLib.h"

class BitmapText
{
public:
	BitmapText();
	~BitmapText();

	void          Set_Back_Ground_Alpha(bool bg_alpha_on) { m_bgalpha = bg_alpha_on; }						// �t�H���g�w�i�𓧉߂��邩�H
	void          Set_Font_Image(int x_num, int y_num, char *font_img_file_name);							// �t�H���g�摜���t�H���g���Z�b�g����
	void          Set_Font_Color(int r, int g, int b);														// �t�H���g�J���[�Z�b�g
	void          Set_Font_Color_Shadow(int r, int g, int b);												// �e�J���[���Z�b�g
	void          Text_Draw_Random(int x, int y, char *string, int max_rand, int count_down);				// �����_�������\��
	
	void          Set_Font_Shadow_Offset(int ofs_x, int ofs_y);												// �e�t�H���g�ʒu�I�t�Z�b�g
	void          Text_Draw(int x, int y, char *string);													// �e�L�X�g��`��
	void          Text_Draw_With_Shadow(int x, int y, char *string);										// �e�t���Ńe�L�X�g�`��

	void          Text_Draw_Message(int x, int y, char *string, unsigned int display_lengh);				// ���b�Z�[�W���\���i��������������j
	void          Text_Draw_Message_With_Shadow(int x, int y, char *string, unsigned int display_lengh);	// ���b�Z�[�W���\���i��������������j
	void          Re_Map_Text(char *remapText);																// �r�b�g�}�b�v�ɕ���ł��镶��������āA�e�L�X�g���當���������悤�ɂ���B�i�������ŕK�v�j

private:
	int           m_fontImg[256];		// �t�H���g�C���[�W�z��
	int           m_fontMap[256];		// �����}�b�v char�^�������t�H���g�C���[�W�z��Y�����ԍ��̃}�b�s���O

	unsigned int  m_size_x;				// �t�H���g1���������T�C�Y
	unsigned int  m_size_y;				// �t�H���g1�������c�T�C�Y	
	int           m_shadow_offset_x;	// �e�t�H���g�ʒu�I�t�Z�b�gX
	int           m_shadow_offset_y;	// �e�t�H���g�ʒu�I�t�Z�b�gY
	bool          m_use_flag;			// �t�H���g�g�p�\�t���O
	bool          m_bgalpha;			// �����w�i�𓧉߂����邩

	int           Is_String(char c);	// �������C���[�W�z��̓Y�����ɕϊ�
	unsigned char red, green, blue;		// �����F 
	unsigned char m_shadow_red;
	unsigned char m_shadow_green;
	unsigned char m_shadow_blue;
};

#endif