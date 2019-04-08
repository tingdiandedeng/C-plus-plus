class Cat{
public:
	Cat();
	void createCat();
	void printCat() const;
	static bool fightCat();
private:
	char* eyeColor;
	char* furColor;
	char* furLength;
	static int Egr;
	static int Ebl;
	static int Ebr;
	static int Fbl;
	static int Fgr;
	static int Fbr;
	static int count;
};
