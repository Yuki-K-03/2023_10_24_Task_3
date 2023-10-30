#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "HeroEnemy.h"
using namespace std;

const int MAX_NAME = 16;

void Hero::operator = (const Hero& other) {
    char* __pName = new char[other._nameSize + 1];

    delete[] _pName;
    _pName = __pName;
    _nameSize = other._nameSize;
    copy(other._pName, other._pName + _nameSize, _pName);
    _hp = other._hp;
    _attack = other._attack;
    _diffence = other._diffence;
}

// コンストラクタ
Hero::Hero(char* pName, int hp) {
    // 名前をコピー
    _nameSize = strlen(pName);
    _pName = new char[_nameSize + 1];   // +1は\0分
    strcpy(_pName, pName);

    // 他のパラメータ初期化
    _hp = hp;
    _attack = 75;
    _diffence = 20;
}

Hero::Hero(const Hero& other) {
    //printf("copy\n");
    _pName = new char[other._nameSize + 1];
    _nameSize = other._nameSize;
    _hp = other._hp;
    _attack = other._attack;
    _diffence = other._diffence;

    copy(other._pName, other._pName + _nameSize, _pName);
}

// デストラクタ
Hero::~Hero() {
    if (_pName != NULL)
    {
        delete[] _pName;
        _pName = NULL;
    }
}

void Hero::show() {
    printf("名前：%s\n", _pName);
    printf("体力：%d\n", _hp);
    printf("攻撃力：%d, ", _attack);
    printf("防御力：%d\n", _diffence);
}

void Enemy::operator = (const Enemy& other) {
    char* __pName = new char[other._nameSize + 1];

    delete[] _pName;
    _pName = __pName;
    _nameSize = other._nameSize;
    copy(other._pName, other._pName + _nameSize, _pName);
    _hp = other._hp;
    _attack = other._attack;
    _diffence = other._diffence;
}

// コンストラクタ
Enemy::Enemy(char* pName, int hp) {
    // 名前をコピー
    _nameSize = strlen(pName);
    _pName = new char[_nameSize + 1];   // +1は\0分
    strcpy(_pName, pName);

    // 他のパラメータ初期化
    _hp = hp;
    _attack = 75;
    _diffence = 20;
}

Enemy::Enemy(const Enemy& other) {
    //printf("copy\n");
    _pName = new char[other._nameSize + 1];
    _nameSize = other._nameSize;
    _hp = other._hp;
    _attack = other._attack;
    _diffence = other._diffence;

    copy(other._pName, other._pName + _nameSize, _pName);
}

// デストラクタ
Enemy::~Enemy() {
    if (_pName != NULL)
    {
        delete[] _pName;
        _pName = NULL;
    }
}

void Enemy::show() {
    printf("名前：%s\n", _pName);
    printf("体力：%d\n", _hp);
    printf("攻撃力：%d, ", _attack);
    printf("防御力：%d\n", _diffence);
}

void Hero::attack(Enemy* enemy) {
    int deffence = enemy->getDiffence();
    int damage = 0;
    damage = _attack - deffence;
    printf("%sの攻撃！\n%dのダメージを与えた\n", _pName, damage);

    int hp = enemy->getHp();
    enemy->setHp(hp - damage);
    printf("相手の残りHP : %d\n", enemy->getHp());
}

void Enemy::attack(Hero* hero) {
    int deffence = hero->getDiffence();
    int damage = 0;
    damage = _attack - deffence;
    printf("%sの攻撃！\n%dのダメージを与えた\n", _pName, damage);

    int hp = hero->getHp();
    hero->setHp(hp - damage);
    printf("相手の残りHP : %d\n", hero->getHp());
}

void Hero::heal() {
    int healHp = 0;
    printf("どのくらい回復しますか\n> ");
    cin >> healHp;
    _hp += healHp;

    printf("%sの残りHP : %d\n", _pName, _hp);
}

void Enemy::heal() {
    int healHp = 0;
    printf("どのくらい回復しますか\n> ");
    cin >> healHp;
    _hp += healHp;

    printf("%sの残りHP : %d\n", _pName, _hp);
}