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

// �R���X�g���N�^
Hero::Hero(char* pName, int hp) {
    // ���O���R�s�[
    _nameSize = strlen(pName);
    _pName = new char[_nameSize + 1];   // +1��\0��
    strcpy(_pName, pName);

    // ���̃p�����[�^������
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

// �f�X�g���N�^
Hero::~Hero() {
    if (_pName != NULL)
    {
        delete[] _pName;
        _pName = NULL;
    }
}

void Hero::show() {
    printf("���O�F%s\n", _pName);
    printf("�̗́F%d\n", _hp);
    printf("�U���́F%d, ", _attack);
    printf("�h��́F%d\n", _diffence);
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

// �R���X�g���N�^
Enemy::Enemy(char* pName, int hp) {
    // ���O���R�s�[
    _nameSize = strlen(pName);
    _pName = new char[_nameSize + 1];   // +1��\0��
    strcpy(_pName, pName);

    // ���̃p�����[�^������
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

// �f�X�g���N�^
Enemy::~Enemy() {
    if (_pName != NULL)
    {
        delete[] _pName;
        _pName = NULL;
    }
}

void Enemy::show() {
    printf("���O�F%s\n", _pName);
    printf("�̗́F%d\n", _hp);
    printf("�U���́F%d, ", _attack);
    printf("�h��́F%d\n", _diffence);
}

void Hero::attack(Enemy* enemy) {
    int deffence = enemy->getDiffence();
    int damage = 0;
    damage = _attack - deffence;
    printf("%s�̍U���I\n%d�̃_���[�W��^����\n", _pName, damage);

    int hp = enemy->getHp();
    enemy->setHp(hp - damage);
    printf("����̎c��HP : %d\n", enemy->getHp());
}

void Enemy::attack(Hero* hero) {
    int deffence = hero->getDiffence();
    int damage = 0;
    damage = _attack - deffence;
    printf("%s�̍U���I\n%d�̃_���[�W��^����\n", _pName, damage);

    int hp = hero->getHp();
    hero->setHp(hp - damage);
    printf("����̎c��HP : %d\n", hero->getHp());
}

void Hero::heal() {
    int healHp = 0;
    printf("�ǂ̂��炢�񕜂��܂���\n> ");
    cin >> healHp;
    _hp += healHp;

    printf("%s�̎c��HP : %d\n", _pName, _hp);
}

void Enemy::heal() {
    int healHp = 0;
    printf("�ǂ̂��炢�񕜂��܂���\n> ");
    cin >> healHp;
    _hp += healHp;

    printf("%s�̎c��HP : %d\n", _pName, _hp);
}