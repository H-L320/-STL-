***bug解决***

```
1.查看往届记录，若文件不存在或为空，并未提示
解决方式：在showRecord函数中，开始判断文件状态并加以判断
void SpeechManager::showRecord()
{
	if (this->fileIsempty)
	{
		cout << "文件为空或文件不存在！" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_Record.size(); i++)
		{
			cout << "第" << i + 1 << "届" << endl;
			cout << "冠军编号：" << this->m_Record[i][0] << " 得分：" << this->m_Record[i][1] << endl;
			cout << "亚军编号：" << this->m_Record[i][2] << " 得分：" << this->m_Record[i][2] << endl;
			cout << "季军编号：" << this->m_Record[i][4] << " 得分：" << this->m_Record[i][5] << endl;
		}
	}
	system("pause");
	system("cls");
}
```

```
2.若记录为空或不存在，比完赛后依然提示记录为空
解决方式：saveRecord中更新文件为空的标志
void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);//用追加的方式写文件

	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," << this->m_Speaker[*it].m_Score[1]<< ",";

	}
	ofs << endl;
	ofs.close();
	cout << "记录已经保存" << endl;
	this->fileIsempty = false;
}
```

```
3.比完赛后查不到本届比赛的记录，没有实时更新
解决方式：比赛完毕后，所有数据重置
//开始比赛 比赛整个流程控制函数
void SpeechManager::startSpeech()
{
	this->speechDraw();
	this->speechContest();
	this->showScore();

	this->m_Index++;
	this->speechDraw();
	speechContest();
	this->showScore();

	this->saveRecord();

	this->initSpeech();
	this->createSpeaker();
	this->loadRecord();

	cout << "本届比赛完毕！" << endl;
	system("pause");
	system("cls");
}
```

```
4.在初始化时，没有初始化记录容器
解决方式：initSpeech添加初始化记录容器
void SpeechManager::initSpeech()
{
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	this->m_Index = 1;
	this->m_Record.clear();
}
```

```
5.每次记录都是一样的
解决方式：在main函数开始添加随机数种子
srand((unsigned int)time(NULL));
```
