#include "cocos2d.h"


/*���巽��ö��*/
typedef enum direction
{
	STAY = 0,  // ͣ��
	UP,
	DOWN,
	LEFT,
	RIGHT,

}RDIRECTION;

/*�ӵ�ö��*/
typedef enum bullet
{
	HERO = 0,
	ENEMY,

}BULLET;

/*��������ö��*/
typedef enum monster
{
	SOLDIER = 1,
	TOWER,
	CRYSTAL,

}MONSTER;

// ��ȡ�����ľ���
extern float getDist(Point curPos, Point distPos);