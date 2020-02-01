#include <iostream>
#include <string>

using namespace std;

class Food {
private:
	int calorie;
	int price;
	int weight;
public:
	Food(int c, int p, int w)
	{
		calorie = c;
		price = p;
		weight = w;
	}
	void setCalorie(int c)
	{
		calorie = c;
	}
	void setPrice(int p)
	{
		price = p;
	}
	void setWeight(int w)
	{
		weight = w;
	}
	int getCalorie()
	{
		return calorie;
	}
	int getPrice()
	{
		return price;
	}
	int getWeight()
	{
		return weight;
	}
};

class Melon : public Food{
private:
	string farm;
public:
	Melon(int c, int p, int w, string f) : Food(c, p, w)
	{
		farm = f;
	}
	void setFarm(string f)
	{
		farm = f;
	}
	string getFarm()
	{
		return farm;
	}
};
int main()
{
	return 0;
}
