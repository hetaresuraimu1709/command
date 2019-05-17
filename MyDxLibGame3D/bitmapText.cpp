#include "bitmapText.h"

const int maxImageNum = 256;

BitmapText::BitmapText()
{
	m_use_flag      = false;
	m_bgalpha      = true ;

	for (int i = 0; i < maxImageNum; i++)
	{
		m_fontMap[i] = -1;
	}
	red = green = blue = 255;
	m_shadow_red = 64;
	m_shadow_green = 64;
	m_shadow_blue = 64;

	m_shadow_offset_x = 1;
	m_shadow_offset_y = 1;

}

BitmapText::~BitmapText()
{
	// フォントイメージの解放
	if (m_use_flag)
	{
		for (int i = 0; i < maxImageNum; i++)
		{
			DeleteGraph(m_fontImg[i]);
		}
	}
	m_use_flag = false;
}

void BitmapText::Set_Font_Image(int x_num, int y_num, char * font_img_file_name)
{
	int tmpImg, imgX, imgY;

	// ファイル仮読み込み
	tmpImg = LoadGraph(font_img_file_name);
	if (tmpImg == -1)
	{
		printf("fontfile load failed:[%s]", font_img_file_name);
		return;
	}
	//　画像サイズ縦横取得
	GetGraphSize(tmpImg, &imgX, &imgY);
	DeleteGraph(tmpImg);

	// フォント1個分の縦横サイズ取得
	m_size_x = imgX / x_num;
	m_size_y = imgY / y_num;

	// 画像読み込み
	LoadDivGraph(font_img_file_name, x_num*y_num, x_num, y_num, m_size_x, m_size_y, m_fontImg);
	m_use_flag = true;
}

void BitmapText::Text_Draw(int x, int y, char * string)
{
	//フォント使用可能か
	if (!m_use_flag)
		return;

	//テキスト描画開始
	int text_x, text_y, img;
	text_x = x;
	text_y = y;

	while (*string)
	{

		// 文字が改行の場合は改行＋戻す
		if (*string == '\n')
		{
			text_x = x;
			text_y += m_size_y;
			string++;
			continue;
		}

		//文字描画
		img = Is_String(*string);
		if (img >= 0)
		{
			DrawGraph(text_x, text_y, m_fontImg[img], m_bgalpha);
		}

		// 文字描画位置進める
		text_x += m_size_x;
		string++;
	}

	SetDrawBright(255, 255, 255);
}

void BitmapText::Text_Draw_With_Shadow(int x, int y, char * string)
{
	//影文字描画
	SetDrawBright(m_shadow_red, m_shadow_green, m_shadow_blue);
	Text_Draw(x + m_shadow_offset_x, y + m_shadow_offset_y, string);

	//文字描画
	SetDrawBright(red, green, blue);
	Text_Draw(x, y, string);

}

void BitmapText::Text_Draw_Random(int x, int y, char* string, int max_rand, int count_down)
{
	char randloopWidth = 'z' - '!';
	char *randString;

	int cnt=0;
	while (string[cnt])
		cnt++;

	randString = new char[cnt + 1];

	//現在の文字からランダム文字列作成
	cnt = 0;
	char randCount;
	while (*string)
	{
		randCount = (max_rand % randloopWidth - count_down) < 0 ? 0 : (max_rand % randloopWidth - count_down);
		randString[cnt] = *string + randCount;
		cnt++;
		string++;
	}
	randString[cnt] = '\0';

	Text_Draw(x, y, randString);

	delete[] randString;
}

void BitmapText::Text_Draw_Message(int x, int y, char * string, unsigned int display_lengh)
{
	// 文字数をカウントし、表示文字数が本来の文字数より多ければそのまま表示
	size_t len = strlen(string);
	if (len < display_lengh)
	{
		Text_Draw(x, y, string);
		return;
	}

	// 文字数をdisplay_length内で表示
	char* tmpStr = new char[display_lengh + 1];
	for (unsigned int i = 0; i < display_lengh; i++)
	{
		tmpStr[i] = string[i];
	}
	tmpStr[display_lengh] = '\0';

	Text_Draw(x, y, tmpStr);

	delete[] tmpStr;
}

void BitmapText::Text_Draw_Message_With_Shadow(int x, int y, char * string, unsigned int display_lengh)
{
	// 文字数をカウントし、表示文字数が本来の文字数より多ければそのまま表示
	size_t len = strlen(string);
	if (len < display_lengh)
	{
		Text_Draw_With_Shadow(x, y, string);
		return;
	}

	// 文字数をdisplay_length内で表示
	char* tmpStr = new char[display_lengh + 1];
	for (unsigned int i = 0; i < display_lengh; i++)
	{
		tmpStr[i] = string[i];
	}
	tmpStr[display_lengh] = '\0';

	Text_Draw_With_Shadow(x, y, tmpStr);

	delete[] tmpStr;
}


void BitmapText::Set_Font_Color(int r, int g, int b)
{
	red = r; green = g; blue = b;
	SetDrawBright(red, green, blue);
}

void BitmapText::Set_Font_Color_Shadow(int r, int g, int b)
{
	m_shadow_red = r;
	m_shadow_green = g;
	m_shadow_blue = b;
}

void BitmapText::Set_Font_Shadow_Offset(int ofs_x, int ofs_y)
{
	m_shadow_offset_x = ofs_x;
	m_shadow_offset_y = ofs_y;
}
	
void BitmapText::Re_Map_Text(char *remapText)
{
	int num = 0;
	char *p ;

	p = remapText;
	char n = 0;
	while (*p && n < 255)
	{
		m_fontMap[*p++] = n++;
	}

}

int BitmapText::Is_String(char c)
{
	return m_fontMap[c];
}
