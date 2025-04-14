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
	//Music myMusic("");		//class에 대한 이해 - 이제부터 mymusic은 music 클래스에 의해 생성된 객체가 됨!
	MusicStreamingService my_service("spotify");

	//adding music to music streaming service.
	my_service.addMusic("PolaroidLove, aaaaaaa,dddddddd,2021");


	
	//add music in bash (diy)
	//hint : music 객체 선언 후 사용자 입력받기(cin 사용으로)
	//입력받은 값을 선언한 music 객체 멤버변수에 하나씩 채운 후,
	//usic 객체 my_service의 music_list에 push_back()하면됨.




	// search music by title 
	string music_title;
	cout << "Enter the Music title";
	cin >> music_title;	//이게 입력받는거임.
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