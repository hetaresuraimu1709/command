//Map.h

#ifndef _MAP_H_
#define _MAP_H_

class Map
{
public:
	Map();
	~Map();
	void Init();
	void Draw(int map_data[BATTLE_MAP_CHIP][BATTLE_MAP_CHIP]);
	void Cloud_P_Move();
	void Cloud_M_Move();
	void Sky_Draw();
	void Field_Draw(Effect *effect);
	void Battle_Draw();
	/*bool loadMapData(char *filename);
	bool loadMapChip(char* chipGraphFilename);
	void mapDraw(int offsetX, int offsetY);
	void mapRelease();*/
	//unsigned char *mapData = NULL; //マップ配列へのポインタ
	//int mapXnum;                   //マップの横ブロック個数
	//int mapYnum;                   //マップの縦ブロック個数
	//int* mapGraph = NULL;          //マップチップの画像ID配列へのポインタ
	//int graphchipSizeX;            // 画像ファイルの横チップドット数
	//int graphchipSizeY;            // 画像ファイルの縦チップドット数
	int GetMapIndexX(float x);
	int GetMapIndexZ(float z);
	int GetMapType(float x, float z, int map_data[BATTLE_MAP_CHIP][BATTLE_MAP_CHIP], Map *map);
	int now_floor;
	int sky_model;
	float sky_move_x;
	int sky_graph;
	int cloud_graph[3];
	Vector2 cloud_pos[3];
	int map_data_1[BATTLE_MAP_CHIP][BATTLE_MAP_CHIP] =
	{
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1 },
		{ 1,1,1,1,1,1,1,0,0,1,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1 },
		{ 1,1,1,1,1,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1,1,1,1,1 },
		{ 1,1,1,1,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,1,1,1,1 },
		{ 1,1,1,1,0,0,1,0,0,1,1,0,0,0,1,1,0,0,1,0,0,1,1,1,1 },
		{ 1,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1 },
		{ 1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,1 },
		{ 1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1 },
		{ 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1 },
		{ 1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1 },
		{ 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1 },
		{ 1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1 },
		{ 1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,1 },
		{ 1,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1 },
		{ 1,1,1,1,0,0,1,0,0,1,1,0,0,0,1,1,0,0,1,0,0,1,1,1,1 },
		{ 1,1,1,1,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,1,1,1,1 },
		{ 1,1,1,1,1,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1,1,1,1,1 },
		{ 1,1,1,1,1,1,1,0,0,1,0,0,2,0,0,1,0,0,1,1,1,1,1,1,1 },
		{ 1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	};
	int map_data_2[BATTLE_MAP_CHIP][BATTLE_MAP_CHIP] =
	{
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1 },
		{ 1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1 },
		{ 1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1 },
		{ 1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1 },
		{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
		{ 1,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1 },
		{ 1,1,1,0,0,0,1,1,1,1,1,0,0,0,1,1,1,1,1,0,0,0,1,1,1 },
		{ 1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,1 },
		{ 1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1 },
		{ 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1 },
		{ 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1 },
		{ 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1 },
		{ 1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1 },
		{ 1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,1 },
		{ 1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1 },
		{ 1,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1 },
		{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
		{ 1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,1,1,1,1,1 },
		{ 1,1,1,1,1,1,1,0,0,0,1,0,0,0,1,0,0,0,1,1,1,1,1,1,1 },
		{ 1,1,1,1,1,1,1,0,0,0,1,0,2,0,1,0,0,0,1,1,1,1,1,1,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	};
	int map_data_3[BATTLE_MAP_CHIP][BATTLE_MAP_CHIP] =
	{
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1 },
		{ 1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1 },
		{ 1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1 },
		{ 1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1 },
		{ 1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1 },
		{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
		{ 1,1,1,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1,0,0,0,1,1,1 },
		{ 1,1,1,0,0,0,1,0,0,1,0,1,0,1,0,1,0,0,1,0,0,0,1,1,1 },
		{ 1,1,0,0,0,0,0,0,1,0,0,1,0,1,0,0,1,0,0,0,0,0,0,1,1 },
		{ 1,1,0,0,0,0,0,0,1,0,0,1,0,1,0,0,1,0,0,0,0,0,0,1,1 },
		{ 1,1,0,0,1,1,0,0,0,0,1,0,0,0,1,0,0,0,0,1,1,0,0,1,1 },
		{ 1,1,0,0,1,0,1,0,0,0,1,1,1,1,1,0,0,0,1,0,1,0,0,1,1 },
		{ 1,1,0,0,1,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,1,0,0,1,1 },
		{ 1,1,1,0,0,1,0,0,0,1,1,1,1,1,1,1,0,0,0,1,0,0,1,1,1 },
		{ 1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,1 },
		{ 1,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,1,1 },
		{ 1,1,1,1,0,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,1,1,1,1 },
		{ 1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,1,0,0,0,0,1,1,1,1,1 },
		{ 1,1,1,1,1,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1,1,1,1,1 },
		{ 1,1,1,1,1,1,1,0,0,1,0,1,2,1,0,1,0,0,1,1,1,1,1,1,1 },
		{ 1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	};
	int battle_map_data[BATTLE_MAP_CHIP][BATTLE_MAP_CHIP] =
	{
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1 },
		{ 1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1 },
		{ 1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1 },
		{ 1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1 },
		{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
		{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
		{ 1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1 },
		{ 1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1 },
		{ 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1 },
		{ 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1 },
		{ 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1 },
		{ 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1 },
		{ 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1 },
		{ 1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1 },
		{ 1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1 },
		{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
		{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
		{ 1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1 },
		{ 1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1 },
		{ 1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1 },
		{ 1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	};
private:
	int graph[3];
	int map_ground[3];
};

#endif