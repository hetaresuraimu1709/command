// field.h
#ifndef _FIELD_H_
#define _FIELD_H_

class Window;

class Field
{
public:
	Field();
	~Field();
	void Init();
	void Updata(Player *player, Music music);
	void Draw(Player * player, Comment_string * comment, Window * window);
private:
	void MenuWindow(Player *player);
	int m_key_graph[8];
	int counter;
	int m_now_frame[1];
	bool command_flag[3];
	bool behavior_flag[3];
	int m_key_count[4];
	int m_count_graph[10];
	int m_count_graph_orange[10];
	int m_count_graph_red[10];
	Vector2 menu_pos[4];
	Vector2 m_key_pos[4];
	std::string menu_1st_item[5];
};

#endif//_FIELD_H_