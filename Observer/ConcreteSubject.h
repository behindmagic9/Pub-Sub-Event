#pragma once
#include"ISubject.h"
#include<unordered_map>
#include "IObserver.h"
#include<vector>

class ConcreteSubject  : public ISubject
{	
	std::unordered_map<Topic, std::vector<IObserver*>,Topichash> record;
public:
	void subscribe(IObserver*,const Topic&) override;
	void unsubscribe(IObserver*,const Topic&) override;
	void notify(Event& e) override;
};