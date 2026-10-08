#ifndef ORDERMANAGER_H
#define ORDERMANAGER_h
# include <iostream>
# include <string>
# include "order.h"
# include "../../ds/Queue.h"
using namespace std;
class OrderManager {
	private:
		Queue<Order> q;
		int timeQuantum;
	public:
		OrderManager(Order arr[], int len, int tq)
		{
			timeQuantum=tq;
			for(int i=0; i<len; i++)
			{
				q.enqueue(arr[i]);
			}
		}
		void processOrders(){
			int c = q.getNoofElements();
			for(int i=0; !q.isEmpty(); i++)
			{
				for(int j=0; j<q.getNoofElements(); j++){
				Order a = q.dequeue();
				int t = a.getPreparationTime();
				t = t-timeQuantum;
				
				if(t <= 0)
				{
					cout<<"Order("<<a.getId()<<","<<a.getName()<<") completed preperation \n";
				}
				else if(t>0)
				{
					cout<<"Order("<<a.getId()<<","<<a.getName()<<") prepared for " <<t<<" units \n";
				}
				else if(t<0)
				{
					cout<<"Order("<<a.getId()<<","<<a.getName()<<") prepared for " <<a.getPreparationTime()<<" units \n";
				}
				if(t>0)
				{
					a.setPreparationTime(t);
					q.enqueue(a);
				}
			}
				cout<<endl;
			}
			cout<<"orders completed \n";
		}
};
#endif