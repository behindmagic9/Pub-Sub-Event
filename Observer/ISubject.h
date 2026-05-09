#pragma once
#include"IObserver.h"
#include"IPublisher.h"
#include<string>
#include"../Event.h"

class IPublisher;
class IObserver;
class ISubject {
	public:
		virtual void subscribe(IObserver*,const Topic&) = 0;
		virtual void unsubscribe(IObserver*,const Topic&) = 0;
		virtual void notify(Event&) = 0;
		virtual ~ISubject() = default;
};