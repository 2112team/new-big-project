#include "cocos2d.h"


/*定义方向枚举*/
typedef enum direction
{
	STAY = 0,  // 停留
	UP,
	DOWN,
	LEFT,
	RIGHT,

}RDIRECTION;

/*子弹枚举*/
typedef enum bullet
{
	HERO = 0,
	ENEMY,

}BULLET;

/*怪物类型枚举*/
typedef enum monster
{
	SOLDIER = 1,
	TOWER,
	CRYSTAL,

}MONSTER;

// 获取两点间的距离
extern float getDist(Point curPos, Point distPos);