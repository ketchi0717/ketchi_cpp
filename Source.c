#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

struct stat {
    char name[20];
    int hp;
    int mp;
    int a1;
    int a2;
    int de;
};

void intro() {
    char start[20];

    char message[200] = "Welcome to EZRPG!";
    int length = strlen(message);
    for (int i = 0; i < length; i++) {
        printf("%c", message[i]);
        Sleep(40);
    }
    printf("\n");
    Sleep(1000);
    system("cls");

    strcpy(message, "Press any key to start");
    length = strlen(message);
    for (int i = 0; i < length; i++) {
        printf("%c", message[i]);
        Sleep(40);
    }
    printf("\n");

    scanf("%s", &start);
    system("cls");
}

void name_creation(char* name, char* yesno) {
    system("cls");
    char message[200] = "Enter username(within 20letters) : ";
    int length = strlen(message);
    for (int i = 0; i < length; i++) {
        printf("%c", message[i]);
        Sleep(40);
    }
    scanf("%s", name);
    system("cls");

    strcpy(message, "Your username is : ");
    length = strlen(message);
    for (int i = 0; i < length; i++) {
        printf("%c", message[i]);
        Sleep(40);
    }

    strcpy(message, name);
    length = strlen(message);
    for (int i = 0; i < length; i++) {
        printf("%c", message[i]);
        Sleep(40);
    }
    printf("\n");

    strcpy(message, "Confirm ? input yes or no\n");
    length = strlen(message);
    for (int i = 0; i < length; i++) {
        printf("%c", message[i]);
        Sleep(40);
    }

    scanf("%s", yesno);
    system("cls");
}

void tut() {
    int anykey = 0;

    char message[200] = "You and enemy can only do one move per turn.\n";
    int length = strlen(message);
    for (int i = 0; i < length; i++) {
        printf("%c", message[i]);
        Sleep(40);
    }
    strcpy(message, "And all moves cost MP, so be smart with your MP usage.\n");
    length = strlen(message);
    for (int i = 0; i < length; i++) {
        printf("%c", message[i]);
        Sleep(40);
    }
    strcpy(message, "After every turn your MP recovers by 7+-3.\nAt the end of the round, your HP and MP fully recovers\n");
    length = strlen(message);
    for (int i = 0; i < length; i++) {
        printf("%c", message[i]);
        Sleep(40);
    }
    strcpy(message, "Input a for Att1, s for Att2, d for Def.\n");
    length = strlen(message);
    for (int i = 0; i < length; i++) {
        printf("%c", message[i]);
        Sleep(40);
    }
    scanf("%d", &anykey);
    system("cls");
}

void enemy_tut_encounter(struct stat slime, struct stat user) {
    system("cls");

    printf("Enemy : %s\n  HP : %d\n  MP : %d\n  Att1 : %d\n  Att2 : %d\n  Def : %d\n", slime.name, slime.hp, slime.mp, slime.a1, slime.a2, slime.de);
    printf("\nYou : \n  HP : %d\n  MP : %d\n  Att1 : %d\n  Att2 : %d\n  Def : %d\n", user.hp, user.mp, user.a1, user.a2, user.de);
}

void enemy_goblin_encounter(struct stat goblin, struct stat user) {
    system("cls");

    printf("Enemy : %s\n  HP : %d\n  MP : %d\n  Att1 : %d\n  Att2 : %d\n  Def : %d", goblin.name, goblin.hp, goblin.mp, goblin.a1, goblin.a2, goblin.de);
    printf("\nYou : \n  HP : %d\n  MP : %d\n  Att1 : %d\n  Att2 : %d\n  Def : %d\n", user.hp, user.mp, user.a1, user.a2, user.de);
}

void enemy_boss_encounter(struct stat boss, struct stat user) {
    system("cls");

    printf("Enemy : %s\n  HP : %d\n  MP : %d\n  Att1 : %d\n  Att2 : %d\n  Def : %d", boss.name, boss.hp, boss.mp, boss.a1, boss.a2, boss.de);
    printf("\nYou : \n  HP : %d\n  MP : %d\n  Att1 : %d\n  Att2 : %d\n  Def : %d\n", user.hp, user.mp, user.a1, user.a2, user.de);
}
void end() {
    printf("Congrats");
}

void fight(struct stat user, struct stat mob, int* u_dmg, int* m_dmg) {
    char inp;
    srand(time(NULL));
    int random_a1 = (rand() % (10 + 4 + 1)) - 4;
    int random_a2 = (rand() % (50 + 50 + 1)) - 60;
    int random_de = (rand() % (15 + 5 + 1)) - 5;
    int random_mp = (rand() % (3 + 3 + 1)) - 3;
    int random_enemy = (rand() % (100 - 1 + 1)) + 1;
    int random_a1_e = (rand() % ((mob.a1 / 10 + 3 * 2 - 2) + (mob.a1 / 10 * 2 - 2) + 1)) - (mob.a1 / 10 * 2 - 2);
    int random_a2_e = (rand() % ((mob.a2 / 10 * 5) + (mob.a2 / 10 * 5) + 1)) - (mob.a2 / 10 * 5);
    int random_de_e = (rand() % (((mob.de / 10 + 1) * 3) + (mob.de / 10 * 3) + 1)) - (mob.de / 10 * 3);

    scanf("%c", &inp);
    if (inp == 'a') {
        user.mp = user.mp - 8;
        if( random_enemy > 0 && random_enemy <= 66) {
            mob.mp = mob.mp - 8;
            *u_dmg = user.a1 + random_a1;
            printf("Enemy is hit by %d\n", user.a1 + random_a1);
            printf("You are hit by %d\n", mob.a1 + random_a1_e);
            *m_dmg = mob.a1 + random_a1_e;
        }
        else if (random_enemy > 66 && random_enemy <= 88) {
            mob.mp = mob.mp - 15;
            *u_dmg = user.a1 + random_a1;
            printf("Enemy is hit by %d\n", user.a1 + random_a1);
            printf("You are hit by %d\n", mob.a2 + random_a2_e);
            *m_dmg = mob.a2 + random_a2_e;
        }
        else if (random_enemy > 88 && random_enemy <= 100) {
            mob.mp = mob.mp - 10;
            *u_dmg = user.a1 + random_a1 - mob.de - random_de_e;
            printf("Enemy is hit by %d\n", user.a1 + random_a1 - mob.de - random_de_e);
            printf("You are hit by 0\n");
        }
    }
    else if (inp == 's') {
        user.mp = user.mp - 15;
        if (random_enemy > 0 && random_enemy <= 66) {
            mob.mp = mob.mp - 8;
            *u_dmg = user.a2 + random_a2;
            printf("Enemy is hit by %d\n", user.a2 + random_a2);
            *m_dmg = mob.a1 + random_a1_e;
            printf("You are hit by %d\n", mob.a1 + random_a1_e);
        }
        else if (random_enemy > 66 && random_enemy <= 88) {
            mob.mp = mob.mp - 15;
            *u_dmg = user.a2 + random_a2;
            printf("Enemy is hit by %d\n", user.a2 + random_a2);
            *m_dmg = mob.a2 + random_a2_e;
            printf("You are hit by %d\n", user.a2 + random_a2);
        }
        else if (random_enemy > 88 && random_enemy <= 100) {
            mob.mp = mob.mp - 10;
            *u_dmg = user.a2 + random_a2 - mob.de - random_de_e;
            printf("Enemy is hit by %d\n", user.a1 + random_a1 - mob.de - random_de_e);
            printf("You are hit by 0\n");
        }
    }
    else if (inp == 'd') {
        user.mp = user.mp - 10;
        if (random_enemy > 0 && random_enemy <= 66) {
            printf("Enemy is hit by 0\n");
            mob.mp = mob.mp - 8;
            *m_dmg = mob.a1 + random_a1_e - user.de - random_de;
            printf("You are hit by %d\n", mob.a1 + random_a2 - user.de - random_de);
        }
        else if (random_enemy > 66 && random_enemy <= 88) {
            mob.mp = mob.mp - 15;
            printf("Enemy is hit by 0\n");
            *m_dmg = mob.a2 + random_a2_e - user.de - random_de;
            printf("You are hit by %d\n", user.a2 + random_a2 - user.de - random_de);
        }
        else if (random_enemy > 88 && random_enemy <= 100) {
            mob.mp = mob.mp - 10;
            printf("Enemy is hit by 0\n");
            printf("You are hit by 0\n");
        }
    }
    user.mp = user.mp + 7 + random_mp;
    Sleep(1000);
}

int main() {
    char name[20] = "shibal";
    char yesno[5];
    strcpy(yesno, "no");
    int user_dmg, mob_dmg;

    struct stat goblin = { "Goblin", 200, 40, 25, 70, 10 };
    struct stat slime = { "Slime", 100, 20, 5, 10, 5 };
    struct stat user = { "shibal", 600, 80, 70, 110, 50 };
    struct stat boss = { "Boss", 600, 100, 70, 120, 50 };

    /*intro();
    while (strcmp(yesno, "no") != 1) {
        name_creation(&name, &yesno);
    }
    tut();*/
    while (user.hp >= 0) {
        enemy_tut_encounter(slime, user);
        fight(user, slime, &user_dmg, &mob_dmg);
        user.hp = user.hp - mob_dmg;
        slime.hp = slime.hp - user_dmg;
        user_dmg = 0;
        mob_dmg = 0;
        if (user.hp > 0 && slime.hp <= 0) {
            printf("Congrats! You killed the enemy!");
            Sleep(2000);
            break;
        }
        else if (user.hp <= 0 && slime.hp > 0) {
            printf("You died");
            Sleep(2000);
            break;
        }
    }
    user.hp = 600;
    user.mp = 80;


    while (user.hp > 0 && goblin.hp > 0) {
        enemy_goblin_encounter(goblin, user);
        fight(user, goblin, &user_dmg, &mob_dmg);
        user.hp = user.hp - mob_dmg;
        goblin.hp = goblin.hp - user_dmg;
        user_dmg = 0;
        mob_dmg = 0;
        if (user.hp > 0 && goblin.hp <= 0) {
            printf("Congrats! You killed the enemy!");
            Sleep(2000);
            break;
        }
        else if (user.hp <= 0 && goblin.hp > 0) {
            printf("You died");
            Sleep(2000);
            break;
        }
    }
    user.hp = 600;
    user.mp = 80;


    while (user.hp > 0 && boss.hp > 0) {
        enemy_boss_encounter(boss, user);
        fight(user, boss, &user_dmg, &mob_dmg);
        user.hp = user.hp - mob_dmg;
        boss.hp = boss.hp - user_dmg;
        user_dmg = 0;
        mob_dmg = 0;
        if (user.hp > 0 && boss.hp <= 0) {
            printf("Congrats! You killed the BOSS!!@@#!@$%!@#$");
            Sleep(2000);
            break;
        }
        else if (user.hp <= 0 && boss.hp > 0) {
            printf("You died");
            Sleep(2000);
            break;
        }
    }
    user.hp = 600;
    user.mp = 80;


    system("cls");
    printf("Credits\n All : gegateungo game anmandeulm\n");
    Sleep(5000);
    return 0;
}