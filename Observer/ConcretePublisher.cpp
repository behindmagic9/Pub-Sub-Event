#include "ConcretePublisher.h"

ConcretePublisher::ConcretePublisher(ISubject* subject ,const Topic &topic) : _subject(subject),  _topic(topic){
	
}

void ConcretePublisher::publish(Event& e) {

	if (e.topic != _topic) {
		return;
	}
	this->_subject->notify(e);
}