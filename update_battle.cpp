#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Hero{
	int power;
public:
	Hero():power(100){}
	int getPower(){return power;}
	void attack(int n);
	void enemy_attack(int n);
};

void Hero::attack(int n){
	cout<<"悪党め、正義の攻撃を受けてみよ。"<<endl;
	cout<<"どかーん！！"<<endl;
	power -= n;

	if(power >= 0){
		cout<<"現在のパワーは"<<power<<"です"<<endl;
	}else{
		cout<<"しまった！パワーを使いすぎた"<<endl;
		cout<<"もうおしまいだ＞＜"<<endl;
	}
}

void Hero::enemy_attack(int n){
	cout<<"くそっ。悪党の攻撃も当たることあるのか。"<<endl;
	power -= n;
	if(power >= 0){
		cout<<"現在のパワーは"<<power<<"だ"<<endl;
	}else{
		cout<<"やられた。がくっ"<<endl;
		cout<<"ヒーローは倒れました。"<<endl;
	}
}

class Enemy{
	int power;
public:
	Enemy():power(100){}
	int getPower(){return power;}
	void attack(int n);
	void enemy_attack(int n);
};

void Enemy::attack(int n){
	cout<<"大魔王の一撃を受けてみよ。"<<endl;
	cout<<"どかーん"<<endl;
	power -= n;
	if(power < 0){
		cout<<"やられたっ"<<endl;
		cout<<"大魔王は倒れました。"<<endl;
	}
}

void Enemy::enemy_attack(int n){
	cout<<"くそっ正義の味方の攻撃も当たることがあるのか・"<<endl;
	power -= n;
	if(power < 0){
		cout<<"しまった！！パワーを使いすぎた。"<<endl;
		cout<<"大魔王は倒れました。"<<endl;
	}
}

class Battle_place{
	Enemy bu;
	Hero ferret;
	int bu_place;
	int ferret_place;
public:
	Battle_place();
	void battle();
	void continue_battle();
};

Battle_place::Battle_place(){
	srand((unsigned)time(NULL));
	bu_place = rand()%5+1;	//1~5
	cout<<"あなたと大魔王ブーとの決戦です。"<<endl;
	cout<<"大魔王ブーは座標1~5のどこかに潜んでます。"<<endl;
	cout<<"あなたもどこかに身を潜めてください"<<endl;
	cout<<"身をひそめる座標(1~5)を入力してください"<<endl;
	cin>>ferret_place;
}

void Battle_place::battle(){
	int place,attack;
	cout<<"さあ、あなたの攻撃です。"<<endl;
	cout<<"攻撃の位置(1~5)を入力してください"<<endl;
	cin>>place;
	cout<<"攻撃に使うパワー(100以下の数値)を入力してください"<<endl;
	cin>>attack;
	cout<<endl;
	ferret.attack(attack);	//この時ヒーローのパワーは減る
	if(ferret.getPower() < 0){
		return;
	}
	if(bu_place == place){
		bu.enemy_attack(attack * 2);
		if(bu.getPower() < 0){	//攻撃されてパワーが０未満になれば終わり
			return;
		}
	}else{
		cout<<"あなたの攻撃は外れたようです。"<<endl;	//外れたら何も怒らない
	}
	cout<<endl;
	cout<<"大魔王の攻撃です。"<<endl;
	cout<<"(Enterキーを押してください)"<<endl;
	cin.sync();
	cin.get();
	place = rand()%5+1;		//大魔王の攻撃位置
	attack = rand()%100+1;	//大魔王の攻撃量
	bu.attack(attack);
	if(bu.getPower() < 0){
		return;
	}
	if(ferret_place == place){
		ferret.enemy_attack(attack * 2);	//攻撃される。
		if(ferret.getPower() < 0){
			return;
		}
	}else{
		cout<<"大魔王ブーの攻撃は外れたようです。"<<endl;
	}
}

void Battle_place::continue_battle(){
	while(1){
		battle();
		if(ferret.getPower() < 0){
			cout<<"\n大魔王の前に正義のヒーローは負けました。"<<endl;
			break;
		}
		if(bu.getPower() < 0){
			cout<<"\n正義のヒーローの前に大魔王は負けました。"<<endl;
			break;
		}
	}
}

int main(){
	Battle_place dokoka;	//対決場所の生成
	dokoka.continue_battle();
	int a;
	cin>>a;
}
