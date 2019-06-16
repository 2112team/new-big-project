Monster::Monster(){
	m_isAlive=false;
}
Monster::~Monster(){};
bool::init(){
	return ture;
}
void Monster::show(){
	if(getSprite()!=NULL){
		setVisible(true);/set to can see/
		m_isAlive=ture;/guai wu we can see/
	}
}
void Monster::hide(){
	if(getSprite()!=NULL){
		setPosition(Point(800,200));
	}
}

bool Monster::isAlive(){
	return m_isAlive;
}
