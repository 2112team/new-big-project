#include "cocos2d.h"
USING_NS_CC;

class CGameLose : public Scene
{
public:
	static Scene *createLoseScene();
	virtual bool init();

	CREATE_FUNC(CGameLose);
private:
};