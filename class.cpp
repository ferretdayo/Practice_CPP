/*#include <iostream>
#include <string>
using namespace std;

class Neko{
	string name;
public:
	Neko(string s) : name(s){}
	//Neko(string s) : name(s){} コンストラクタはこれでもおｋ
	void const naku(){
		cout<<"にゃあ。俺様は"<<name<<"だ"<<endl;
	}
};
	

int main(){
	string s;
	cout<<"猫を生成します。名前を入力してください"<<endl;
	cin>>s;
	Neko dora(s);	//コンストラクタが実行され文字列sの名前のdoraが生成される。
	cout<<"あなたの名づけた猫がメモリ上に生成されました。"<<endl;
	cout<<"猫が鳴きます。"<<endl;

	dora.naku();	//naku()というメソッドが呼ばれる。
}*/
#include <iostream>
#include <string>
using namespace std;

class Neko
{
    string name;
public:
    Neko(string s);
    void const naku();
};

Neko::Neko(string s) : name(s){}

void const Neko::naku(){
    cout<<"にゃあ。俺様は"<<name<<"だ。"<<endl;
}

int main()
{
    string s;
	int i;
    cout<<"猫を生成します。名前を入力してください。"<<endl;
    cin>>s;

    Neko dora(s);  //コンストラクタが実行され、文字列sの名前のdoraが生成される
    cout<<"あなたの名づけた猫がメモリ上に生成されました。"<<endl;
    cout<<"猫が鳴きます。"<<endl;

    dora.naku();   //doraに対してnakuを実行
	cin>>i;
}
