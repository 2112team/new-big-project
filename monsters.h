class Monster : public	Entity{
	public:
		Monster();
		~Monster();
		CREAT_FUNC(Monster);
		virtual bool init();
	public:
		void show();
		void hide();
		void reset();
		void isAlive();
	private:
		bool m_isAlive;
};
