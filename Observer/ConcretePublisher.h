#pragma once
#include"IPublisher.h"
#include"ISubject.h"

class ConcretePublisher : public IPublisher
{
	ISubject* _subject;
	Topic _topic;
public:
	ConcretePublisher(ISubject*,const Topic&);
	void publish(Event& e)override;
};