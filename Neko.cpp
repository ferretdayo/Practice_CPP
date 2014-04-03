#include<iostream>
#include<string>

using namespace std;

class Neko{
	string name;
	int hp;
public:
	Neko(string n):name(n),hp(10){}
	int eat();
	int naku();
};

int Neko::eat(){
	cout<<name<<"に食事させます。どれだけ食べさせますか？"<<endl;
	cout<<"半角数字で入力してください"<<endl;
	int food;
	cin>>food;
	hp += food;
	return hp;
}

int Neko::naku(){
	cout<<"にゃぁ俺様は"<<name<<"だ"<<endl;
	hp -= 5;
	return hp;
}

int main(){
	cout<<"猫をメモリ上に生成します。名前を決めてください"<<endl;
	string temp;
	cin>>temp;
	Neko kaineko(temp);
	cout<<endl;
	for(int i=0;i<5;i++){
		cout<<"どうします？"<<endl;
		cout<<"1.食事を与える"<<endl;
		cout<<"2.鳴かす"<<endl;
		cout<<"半角数字で入力してください。"<<endl;
		int ans;
		cin>>ans;
		if(ans == 1){
			int t;
			t = kaineko.eat();
			cout<<"猫の体力="<<t<<endl;
		}else if(ans == 2){
			int t;
			t = kaineko.naku();
			cout<<"猫の体力="<<t<<endl;
			if(t < 0){
				cout<<"食事が不十分だったので、猫は隣のお金持ちの家に行ってしまいました。"<<endl;
				break;
			}
		}
		cout<<endl;
	}
	cout<<"おわり"<<endl;
}
