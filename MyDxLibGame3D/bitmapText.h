//********************************************************************
// BitmapText.h
// 
// 文字列を画面表示するプログラム
// 数字～アルファベットが並んだビットマップ画像をフォントとして登録
//********************************************************************

#ifndef __BITMAPTEXT_H__
#define __BITMAPTEXT_H__

// ヘッダーファイルの呼び出し
#include "DxLib.h"

class BitmapText
{
public:
	BitmapText();
	~BitmapText();

	void          Set_Back_Ground_Alpha(bool bg_alpha_on) { m_bgalpha = bg_alpha_on; }						// フォント背景を透過するか？
	void          Set_Font_Image(int x_num, int y_num, char *font_img_file_name);							// フォント画像よりフォントをセットする
	void          Set_Font_Color(int r, int g, int b);														// フォントカラーセット
	void          Set_Font_Color_Shadow(int r, int g, int b);												// 影カラーをセット
	void          Text_Draw_Random(int x, int y, char *string, int max_rand, int count_down);				// ランダム文字表示
	
	void          Set_Font_Shadow_Offset(int ofs_x, int ofs_y);												// 影フォント位置オフセット
	void          Text_Draw(int x, int y, char *string);													// テキストを描画
	void          Text_Draw_With_Shadow(int x, int y, char *string);										// 影付きでテキスト描画

	void          Text_Draw_Message(int x, int y, char *string, unsigned int display_lengh);				// メッセージ風表示（文字数制限あり）
	void          Text_Draw_Message_With_Shadow(int x, int y, char *string, unsigned int display_lengh);	// メッセージ風表示（文字数制限あり）
	void          Re_Map_Text(char *remapText);																// ビットマップに並んでいる文字列を入れて、テキストから文字列を作れるようにする。（初期化で必要）

private:
	int           m_fontImg[256];		// フォントイメージ配列
	int           m_fontMap[256];		// 文字マップ char型文字→フォントイメージ配列添え字番号のマッピング

	unsigned int  m_size_x;				// フォント1文字分横サイズ
	unsigned int  m_size_y;				// フォント1文字分縦サイズ	
	int           m_shadow_offset_x;	// 影フォント位置オフセットX
	int           m_shadow_offset_y;	// 影フォント位置オフセットY
	bool          m_use_flag;			// フォント使用可能フラグ
	bool          m_bgalpha;			// 文字背景を透過させるか

	int           Is_String(char c);	// 文字をイメージ配列の添え字に変換
	unsigned char red, green, blue;		// 文字色 
	unsigned char m_shadow_red;
	unsigned char m_shadow_green;
	unsigned char m_shadow_blue;
};

#endif