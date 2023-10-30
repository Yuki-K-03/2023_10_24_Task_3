#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "HeroEnemy.h"
using namespace std;

const int MAX_NAME = 16;

void showStatus(Hero hero, Enemy enemy) {

    printf("\nステータス表示\n");
    printf("Hero\n");
    //printf("名前：%s\n", );
    printf("体力：%d\n", hero.getHp());
    printf("攻撃力：%d, ", hero.getAttack());
    printf("防御力：%d\n", hero.getDiffence());

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

int main()
{
    bool turn = false;
    //Hero hero = InputHeroStatus();
    //Enemy enemy = InputEnemyStatus();
    char name[MAX_NAME]{ "" };
    int hp = 0;

    printf("ヒーロー名を入力\n> ");
    cin >> name;
    printf("HPを入力\n> ");
    cin >> hp;

    Hero hero(&name[0], hp);

    // ステータス表示
    hero.show();

    printf("エネミー名を入力\n> ");
    cin >> name;
    printf("HPを入力\n> ");
    cin >> hp;



    Enemy enemy(&name[0], hp);

    // ステータス表示
    enemy.show();

    char name2[MAX_NAME] = { "" };
    Hero hero2(&name2[0], 10);
    hero2 = hero;
    Enemy enemy2(&name2[0], 10);
    enemy2 = enemy;
    showStatus(hero2, enemy2);

    int select = 0;
    while (true) {
        // プレイヤーターン
        printf("攻撃 : 1\, 回復 : 2\n> ");
        cin >> select;

        switch (select)
        {
        case 1:
            hero.attack(&enemy);
            break;
        case 2:
            hero.heal();
            break;
        default:
            break;
        }
        if (enemy.getHp() <= 0) { break; }

        // エネミーターン
        printf("攻撃 : 1\, 回復 : 2\n> ");
        cin >> select;

        switch (select)
        {
        case 1:
            enemy.attack(&hero);
            break;
        default:
            break;
        }
        if (hero.getHp() <= 0) { break; }
    }
}