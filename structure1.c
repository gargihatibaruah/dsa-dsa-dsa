#include<stdio.h>
int main(){
struct pokemon{ //struct is used for making variables of different data types // user defined data types
int hp;
int speed;
int attack;
char tier;
};
struct pokemon pikachu;
pikachu.hp = 100;//initialisation in structure
pikachu.speed=50;//dot operator
pikachu.attack=90;
pikachu.tier='A';

struct pokemon charizard;
charizard.hp = 70;
charizard.speed=40;
charizard.attack=100;
charizard.tier='R';

printf("%d\n",pikachu.hp);
printf("%d\n",charizard.attack);
printf("%c\n",charizard.tier);

return 0;

}