#pragma once

class Enemy;    //‘O•ûéŒ¾

class Hero {
public :
    void operator = (const Hero& other);

public:
    Hero(const Hero& other);
    Hero(char* pName, int hp);
    ~Hero();

public:
    int getAttack() { return _attack; }
    int getDiffence() { return _diffence; }
    int getHp() { return _hp; }
    void setHp(int hp) { _hp = hp; }
    void show();

public:
    void attack(Enemy* enemy);
    void heal();

private:
    char* _pName;
    int _nameSize;

private:
    int _hp = 0;
    int _attack = 75;
    int _diffence = 20;
};


class Enemy {
public:
    void operator = (const Enemy& other);

public:
    Enemy(const Enemy& other);
    Enemy(char* pName, int hp);
    ~Enemy();

public:
    int getAttack() { return _attack; }
    int getDiffence() { return _diffence; }
    int getHp() { return _hp; }
    void setHp(int hp) { _hp = hp; }
    void show();

public:
    void attack(Hero* hero);
    void heal();

private:
    char* _pName;
    int _nameSize;

private:
    int _hp = 0;
    int _attack = 75;
    int _diffence = 20;
};
