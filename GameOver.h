#include "cocos2d.h"
USING_NS_CC;

class CGameOver : public Scene
{
public:
	static Scene *createOverScene();
	virtual bool init();

	CREATE_FUNC(CGameOver);
private:
};