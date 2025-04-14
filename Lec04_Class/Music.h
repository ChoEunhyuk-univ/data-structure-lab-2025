#pragma once
//#include <cstdio>
#include <iostream>	//input-output에 특화된 라이브러리임
#include <string>
#include <vector>	//STL vector

// Namespace
using namespace std; //이거 안하면 std.어쩌고저쩌고 생략가능함!

class Music {
private:
	string title;
	string artist;
	string album;
	int year;
public:
	//생성자
	Music(string title, string artist, string album, int year);
	//여기서 this는, music(~~~)에서 기입된 정보를 다른 변수에 옮겨주는 역할을 함. ( 근데 this는 어디서 선언된거임?)
	string this = Music();//??
	this->title = title;
	this->artist = artist;
	this->album = album;
	this->year = year;	//내 자신 객체의 year를 의미함.

	//mymusic(


};

class MusicStreamingService {
private:
	class service_name;
	class<>music_list;

	MusicStreamingService(string:music_list);
	//음악 추가기능

	{

		cout << title << "by" << artist << "added to" << service_name << endl;
	}
	//음악 찾아보는 서비스
	vector<Music*> searchByTitle(string title) {	// <여기서 *가 붙은건 포인터라 그래요. 배열에 주소값을 저장해야 해서 저런식으로 쓰는거임.
		for (int i = 0; i < music_list.size(); i++) {
			if (music_list[i].getTitle() == title) return &music_list[i];
		}
		return NULL;
	}

	vector<Music*> searchByArtist(string artist) {
		vector<music*>result;
		for (int i = 0; i < music_list.size(); i++) {
			if (music_list[i].getArtist() == artist) {	//고민해볼거 : 왜 여기서 &&가 붙었는가? : 왜냐면 주소값이기 때문임. 
				result.push_back(&music_list[i]);
			}
		}
	}
	

};

void addMusic(string title, string artist, string album, int year);
music.new_music