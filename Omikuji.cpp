#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

class Omikuji{
	int un;
public:
	Omikuji();
	void hiku();
};

Omikuji::Omikuji(){
	srand((unsigned)time(NULL));
	cout<<"自分のラッキーナンバーを入力してください"<<endl;
	cin>>un;
}

//おみくじを引く
void Omikuji::hiku(){
	int x;
	x = rand()%5+1;
	if(x == un){
		cout<<"大吉ということです"<<endl;
	}else{
		cout<<"まあまあです"<<endl;
	}
}

int main(){
	Omikuji today;
	today.hiku();
}
