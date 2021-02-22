	#include <iostream>
	#include <string>

	using namespace std;

	class Point {
	public: 
		int x, y;
	};

	class Character {
	private:
		string name;
		bool isalive = true;
		int hp, max_hp, damage, defence;
		Point position;
	public:
		void setDamage(int _damage) {
			if (_damage < 1) _damage = 1;
			damage = _damage; 
		}
		void moveCh(int x, int y) {
			if (hp > 0) {
				position.x = x;
				position.y = y;
				if (x < 0 && y > 0) {
					hp -= 5;
					damage--;
					if (hp < 0) {
						hp = 0;
						isalive = false;
					}
				}
				else if (x < 0 && y < 0 && defence > 100) {
					hp -= 2;
					if (hp < 0) {
						hp = 0;
						isalive = false;
					}
				}
				else if (x > 0 && y < 0) {
					defence++;
				}
				else if (x == 0 && y == 0) {
					hp = max_hp;
				}
			}
			else {
				isalive = false;
			}
		}
		void setDefence(int _defence) {
			if (_defence < 0) _defence = 0;
			defence = _defence;
		}
		void setMaxHp(int _max_hp) {
			if (_max_hp < 0) _max_hp = 1;
			max_hp = _max_hp;
		}
		void setName(string _name) {
			name = _name;
		}
		void setHp(int _hp) {
			if (_hp > max_hp) _hp = max_hp;
			if (_hp < 0) _hp = 0;
			hp = _hp;
			if (hp > 0)
				isalive = true;
			else
				isalive = false;
		}
		void setPos(Point pos) {
			position.x = pos.x;
			position.y = pos.y;
		}
		string getName() {
			return name;
		}
		int getHp() {
			return hp;
		}
		int getMaxHp() {
			return max_hp;
		}
		int getDefence() {
			return defence;
		}
		int getDamage() {
			return damage;
		}
		bool getStatus() {
			return isalive;
		}
		Point getPosition() {
			return position;
		}
	};
	
	void printInfo(Character ch) {
		string status;
		if (ch.getStatus() == true)
			status = "alive";
		else
			status = "died";
		cout << "Name: " << ch.getName() << endl 
			<< "Status: " << status << endl 
			<< "HP: " << ch.getHp() << "/" << ch.getMaxHp() << endl 
			<< "Damage: " << ch.getDamage() << endl 
			<< "Defence: " << ch.getDefence() << endl 
			<< "Position: (" << ch.getPosition().x << ", " 
			<< ch.getPosition().y << ")" << endl;
	}

	int main() {	
		Character ch;
		string name, status;
		Point pos;
		int hp, max_hp, damage, defence, x, y;
		cin >> name >> max_hp >> hp >> damage >> defence >> x >> y;
		pos.x = x;
		pos.y = y;
		ch.setName(name);
		ch.setMaxHp(max_hp);
		ch.setHp(hp);
		ch.setDamage(damage);
		ch.setDefence(defence);
		ch.setPos(pos);
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			string cmd;
			cin >> cmd;
			if (cmd == "status") {
				printInfo(ch);
			}
			if (cmd == "move") {
				cin >> x >> y;
				ch.moveCh(x, y);
			}
		}
		system("pause");
		return 0;
	}
