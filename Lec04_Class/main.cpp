//#include "Car.h"
#include "Music.h"
/*int main() {
	
	Car myCar;	// (1, "AAA", 1);
	Car momsCar(10, "K5", 2);
	SportsCar mySecondCar(100, "Tycan", 3);


	myCar.whereAmI();
	momsCar.whereAmI();
	myCar.changeGear(3);


	momsCar.speedUp();
	momsCar.display();
	
	mySecondCar.setTurbo(true)
}*/

int main() {
	//Music myMusic("");		//class�� ���� ���� - �������� mymusic�� music Ŭ������ ���� ������ ��ü�� ��!
	MusicStreamingService my_service("spotify");

	//adding music to music streaming service.
	my_service.addMusic("PolaroidLove, aaaaaaa,dddddddd,2021");


	
	//add music in bash (diy)
	//hint : music ��ü ���� �� ����� �Է¹ޱ�(cin �������)
	//�Է¹��� ���� ������ music ��ü ��������� �ϳ��� ä�� ��,
	//usic ��ü my_service�� music_list�� push_back()�ϸ��.




	// search music by title 
	string music_title;
	cout << "Enter the Music title";
	cin >> music_title;	//�̰� �Է¹޴°���.
	Music* result = my_Service.searchByTitle(music_title_;
	if(result!=NULL){
		cout << "found" << result->getTitle() << "by" << result->getArtist() << endl;
	}
	else {
		count<<"not found" << endl;
	}
	string artist_name;
	cout << "enter the artist name:";
	cin >> artist_name;
	vector<Music> artist_result = my_service.searchByArtist(artist_name);
	if (artist_name.size() > 0) {
		cout << "Found" << artist_result.size() << "songs by" << artist_name << ":" << endl;
		for (int i = 0; i < artist_result.size(); i++); {
			cout << artist_result[i]->getTitle() << "by" << result->getArtist() << endl;
		}

	}
	else cout << "notfound" << endl;


}