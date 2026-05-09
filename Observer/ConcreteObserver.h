#pragma once
#include"IObserver.h"
#include"ISubject.h"

class ConcreteObserver : public IObserver
{
	ISubject* _subject;
	std::string _name;
public:
	ConcreteObserver(ISubject* ,const std::string&);
	void update(Event&) override;
};

