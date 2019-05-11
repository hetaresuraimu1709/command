#include "Header.h"

Save* Save::save_instance = NULL;

Save* Save::GetInstance()
{
	if (save_instance == NULL)
	{
		save_instance = new Save();
	}
	return save_instance;
}

Save::Save()
{
	// 処理なし
}

Save::~Save()
{
	// 処理なし
}

bool Save::FileLoader(const char * _filename)
{
	//ファイルを開く
	std::ifstream ifs(_filename);
	if (!ifs) { printfDx("それはひらけねえぞ！"); return false; }

	//列保存
	std::string line;
	//ファイルの最後までループ
	while (getline(ifs, line))
	{
		//ここでカンマ区切りで読み込み
		std::vector<std::string> strvec = Split(line, ',');

		for (int row = 0; row < (int)strvec.size(); row++)
		{
			//数字に変換（string ==> int）
			m_data_case_1[row] = stoi(strvec.at(row));
		}
	}
	return true;
}
bool Save::FileLoader(const char * _filename, const int line_num)
{
	//ファイルを開く
	std::ifstream ifs(_filename);
	if (!ifs) { printfDx("それはひらけねえぞ！"); return false; }

	//列保存
	std::string line;
	//ファイルの最後までループ
	int lineIndex = 0;
	while (getline(ifs, line))
	{
		//ここでカンマ区切りで読み込み
		std::vector<std::string> strvec = Split(line, ',');

		for (int row = 0; row < (int)strvec.size(); row++)
		{
			//数字に変換（string ==> int）
			m_data_case_2[row][lineIndex] = stoi(strvec.at(row));
		}
		++lineIndex;

		if (lineIndex > line_num)
		{
			// 警告
			break;
		}
	}
	return true;
}

int Save::FileGeter(const int col, const int row)
{
	return m_data_case_2[row][col];
}

int Save::FileGeter(const int row)
{
	return m_data_case_1[row];
}

bool Save::Filewritier(const char * _filename, const float data)
{
	//ファイルに追加して書き込み
	std::ofstream fout(_filename);
	if (!fout) { printfDx("そいつはひらけねえぜ\n"); return false; }

	fout << data << "," << std::flush;
	return true;
}

bool Save::Filewritier(const char * _filename, const int size, const int size_2, const int * data)
{
	//ファイルに追加して書き込み
	std::ofstream fout(_filename);
	if (!fout) { printfDx("そいつはひらけねえぜ\n"); return false; }

	for (int j = 0; j < size_2; j++)
	{
		for (int i = 0; i < size; i++)
		{
			fout << data[i] << "," << std::flush;
		}
		fout << "\n" << std::flush;
	}
	return true;
}

bool Save::File_Status_Writier(const char * _filename, const int chara_size, Chara * data)
{
	//ファイルに追加して書き込み
	std::ofstream fout(_filename);
	if (!fout) { printfDx("そいつはひらけねえぜ\n"); return false; }

	for (int j = 0; j < chara_size; j++)
	{
		for (int i = 0; i < 13; i++)
		{
			fout << data[j].status[i] << "," << std::flush;
		}
		fout << "\n" << std::flush;
	}
	return true;
}

std::vector<std::string> Save::Split(std::string & input, char split)
{
	std::istringstream stream(input);

	std::string field;
	std::vector<std::string> result;

	while (getline(stream, field, split))
	{
		result.push_back(field);
	}
	return result;
}
