#pragma once
//#include <cstdio>
#include <iostream>	//input-output�� Ưȭ�� ���̺귯����
#include <string>
#include <vector>	//STL vector

// Namespace
using namespace std; //�̰� ���ϸ� std.��¼����¼�� ����������!

class Music {
private:
	string title;
	string artist;
	string album;
	int year;
public:
	//������
	Music(string title, string artist, string album, int year);
	//���⼭ this��, music(~~~)���� ���Ե� ������ �ٸ� ������ �Ű��ִ� ������ ��. ( �ٵ� this�� ��� ����Ȱ���?)
	string this = Music();//??
	this->title = title;
	this->artist = artist;
	this->album = album;
	this->year = year;	//�� �ڽ� ��ü�� year�� �ǹ���.

	//mymusic(


};

class MusicStreamingService {
private:
	class service_name;
	class<>music_list;

	MusicStreamingService(string:music_list);
	//���� �߰����

	{

		cout << title << "by" << artist << "added to" << service_name << endl;
	}
	//���� ã�ƺ��� ����
	vector<Music*> searchByTitle(string title) {	// <���⼭ *�� ������ �����Ͷ� �׷���. �迭�� �ּҰ��� �����ؾ� �ؼ� ���������� ���°���.
		for (int i = 0; i < music_list.size(); i++) {
			if (music_list[i].getTitle() == title) return &music_list[i];
		}
		return NULL;
	}

	vector<Music*> searchByArtist(string artist) {
		vector<music*>result;
		for (int i = 0; i < music_list.size(); i++) {
			if (music_list[i].getArtist() == artist) {	//����غ��� : �� ���⼭ &&�� �پ��°�? : �ֳĸ� �ּҰ��̱� ������. 
				result.push_back(&music_list[i]);
			}
		}
	}
	

};

void addMusic(string title, string artist, string album, int year);
music.new_music