#include "ConcreteSubject.h"
#include <string>

// std::unordered_map<std::string, std::vector<IObserver*>> record;

void ConcreteSubject::subscribe(IObserver* obs,const Topic& topic) {
	// add the observer to the particular topic 's vector
	record[topic].push_back(obs);
}

void ConcreteSubject::unsubscribe(IObserver* obs,const Topic& topic) {
	// remove the observer from the particular topic 's vector
	auto it = record.find(topic);

	if (it == record.end()) {
		return;
	}

	auto& vec = it->second;

	// "Move all matching elements to the end, .. remove move all elements to the last of the vector and then in series it then erase them."
	vec.erase(	
		std::remove(vec.begin(), vec.end(), obs), vec.end()
	);
}

void ConcreteSubject::notify(Event& e) {
	// find the topic in the map and call update function related to all the observer 
	const Topic& topic = e.topic;
	auto it = record.find(topic);

	if (it == record.end()) {
		return;
	}

	for (auto& c : it->second) {
		c->update(e);
	}
}

