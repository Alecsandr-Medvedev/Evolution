//#include <iostream>
//#include <sstream>
//#include <list>
//#include <vector>
//#include <SFML/Graphics.hpp>
//#include "level.h"
//#include "WedlecGUE.h"
//using namespace std;
//using namespace sf;
//
//
///*
//class text {
//private:
//
//	string shribe;
//
//public:
//	Text txt;
//	text(string shribeName) {
//		txt.setCharacterSize(20);
//		��������� ����
//		txt.setFillColor(Color(0, 0, 0));
//		txt.setString(shribeName);
//		shribe = shribeName;
//	}
//	����� ����� ������� �� ��������
//	virtual void sleditForSprite(Sprite& s, float x, float y) {
//		txt.setPosition(s.getPosition().x + x, s.getPosition().y + y);
//	}
//	���� ����� ������
//	void getChislo(float n) {
//		ostringstream chislo;
//		chislo << n;
//		txt.setString(shribe + chislo.str());
//	}
//	�-� ��� ������
//	void setString(string name) {
//		txt.setString(name);
//	}
//	virtual void setPosition(float x, float y) {
//		txt.setPosition(x, y);
//	}
//	void setFillTextColor(float R, float G1, float B) {
//		txt.setFillColor(Color(R, G1, B));
//	}
//
//	�������� ������ ������
//	void setCharacterSize(float a) {
//		txt.setCharacterSize(a);
//	}
//	���������� � ����
//	virtual void draw(RenderWindow& window) {
//		window.draw(txt);
//	};
//};*/
//������
//class Button {
//public:
//    float w, h;
//	bool press;
//	RectangleShape button;//��� ��������
//	Button(float W, float H, string shribeName) {
//		w = W;
//		h = H;
//		press = false;
//		button.setSize(Vector2f(W, H));
//	}
//	������ ������ �� ��������
//	void sleditForSprite(Sprite& s, float x, float y) override {
//		button.setPosition(s.getPosition().x + x, s.getPosition().y + y);
//		txt.setPosition(s.getPosition().x + x, s.getPosition().y + y);
//	}
//	//������ � �����(�������) � �����
//	void draw(RenderWindow& window) {
//		window.draw(button);
//	}
//	�������
//	void update(bool click, Vector2f  pos) {
//		if (button.getGlobalBounds().contains(pos.x, pos.y)) {
//
//
//			setFillRacktengelColor(0, 255, 255);
//			if (click && !press) {
//				press = 1;
//
//			}
//			else if (press && !click) {
//				press = 0;
//
//			}
//
//		}
//		else {
//			setFillRacktengelColor(255, 255, 255);
//		}
//	}
//
//	void setButtonSize(float W, float H) {
//		w = W;
//		h = H;
//		button.setSize(Vector2f(W, H));
//	}
//	�������� �� �����
//	void setOringCenter() {
//		button.setOrigin(w / 2, h / 2);
//	}
//	�������� �������
//void setPosition(float x, float y) {
//		button.setPosition(x, y);
//	}
//	�������� ���� ��������
//	void setFillRacktengelColor(float R, float G, float B) {
//		button.setFillColor(Color(R, G, B));
//	}
//};
//
