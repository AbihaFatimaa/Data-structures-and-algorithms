#ifndef ORDER_H
#define ORDER_h
# include <iostream>
# include <string>
using namespace std;
class Order {
	private:
		int orderId;
		string customerName;
		int preparationTime;
	public:
		Order() {
		orderId = 0;
		customerName = "";
		preparationTime = 0;
		}
		Order(int id, string name, int time);
		int getId();
		string getName();
		int getPreparationTime();
		void setPreparationTime(int t);
};
Order::Order(int id, string name, int time){
			orderId = id;
			customerName=name;
			preparationTime = time;
		}
int Order::getId()
		{
			return orderId;
		}
string Order::getName(){
			return customerName;
		}
int Order::getPreparationTime()
		{
			return preparationTime;
		}
void Order::setPreparationTime(int t)
		{
			preparationTime = t;
		}
#endif