	#include <iostream>
	#include <string>

	using namespace std;

	//class of character coordinates
	class Point {
	public: 
		int x, y;
	};

	//class of game character
	class Character {
	private:
		string name;
		bool isalive = true;
		int hp, max_hp, damage, defence;
		Point position;
	public:
		//to set up our character we'll use setters
		void setDamage(int _damage) {
			if (_damage < 1) _damage = 1;
			damage = _damage; 
		}
		void moveCh(int x, int y) {
			if (hp > 0 && isalive) {
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
					if (hp <= 0) {
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
				cout << "Can't move, character is DEAD" << endl;
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
		//to print information to the screen we'll use getters, they return the number
		//or string, which will be printed in MAIN
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
	
	// func which prints the status of the character
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
		//initilazing variables
		Character ch;
		string name, status;
		Point pos;
		int hp, max_hp, damage, defence, x, y;

		cout << "Hello, this is Character 1.0" << endl << "Are you ready? Write any word if you want to proceed" << endl;
		string first_cmd;
		cin >> first_cmd;

		//filling in variables
		cout << endl << "Please write character's name: " << endl;
		cin >> name;
		cout << "Max HP: " << endl;
		cin >> max_hp;
		cout << "Current HP: " << endl;
		cin >> hp;
		cout << "Attack damage: " << endl;
		cin >> damage;
		cout << "Armor points: " << endl;
		cin >> defence;
		cout << "X coordinate:" << endl;
		cin >> x;
		cout << "Y coordinate: " << endl;
		cin >> y;
		pos.x = x;
		pos.y = y;

		//setting properties of character
		ch.setName(name);
		ch.setMaxHp(max_hp);
		ch.setHp(hp);
		ch.setDamage(damage);
		ch.setDefence(defence);
		ch.setPos(pos);

		//number of console commands
		cout << endl << "1. To print the status of the character, please write \"status\"" << endl;
		cout << "2. To move the character, please write \"move\" and then X and Y coordinates" << endl;
		cout << "3. To exit the program, please write \"exit\"" << endl << endl;
		cout << "Please notice that some regions of the map can affect your character" << endl;
		cout << "In the first quater of coordinated plane is good weather, so nothing will happen with character" << endl;
		cout << "In the second quater is a desert, it decreases the current HP by 5 points and attack by 1 point" << endl;
		cout << "In the third quater are mountains, if your character has more than 100 armor points, it is losing 2 HP" << endl;
		cout << "In the last, fourth quater is a swamp, by surprise it increases the armor by one point" << endl;
		cout << "Dead character can't move" << endl;
		cout << "This is all you have to know, GLHF!" << endl << endl;

		string cmd;
		//filling in our command to start
		cin >> cmd;
		//this loop will work until user writes EXIT command
		while (cmd != "exit") {
			if (cmd == "status") {
				printInfo(ch);
			}
			if (cmd == "move") {
				//getting coordinates if needed
				cin >> x >> y;
				ch.moveCh(x, y);
			}
			cin >> cmd;
		}

		cout << "Goodbye!" << endl;

		system("pause");
		return 0;
	}
