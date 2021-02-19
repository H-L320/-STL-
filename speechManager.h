#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <functional>
#include <numeric>
#include <string>
#include <fstream>
#include "speaker.h"
using namespace std;

//设计演讲管理类
class SpeechManager
{
public:

	SpeechManager();

	void show_Menu();

	void exitSystem();

	~SpeechManager();

	void initSpeech();

	void createSpeaker();

	void startSpeech();

	void speechDraw();

	void speechContest();

	void showScore();

	void saveRecord();

	void loadRecord();
	bool fileIsempty;
	map<int, vector<string>> m_Record;

	void showRecord();

	void clearRecord();

	vector<int> v1;
	vector<int> v2;
	vector<int> vVictory;
	map<int, Speaker> m_Speaker;
	int m_Index;
};
