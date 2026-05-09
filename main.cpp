// Project1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Observer/ConcreteObserver.h"
#include"Observer/ConcreteSubject.h"
#include "Observer/IObserver.h"
#include "Observer/ConcretePublisher.h"

#include <iostream>

int main()
{
    ISubject *broker = new ConcreteSubject();

    const Topic& animal = Topic::Animal;
    const Topic& birds = Topic::Birds;

    IObserver* obs1 = new ConcreteObserver(broker, "obs1");
    IObserver* obs2 = new ConcreteObserver(broker, "obs2");
    IObserver* obs3 = new ConcreteObserver(broker, "obs3");
    IObserver* obs4 = new ConcreteObserver(broker, "obs4");
    IObserver* obs5 = new ConcreteObserver(broker, "obs5");
    IObserver* obs6 = new ConcreteObserver(broker, "obs6");
    IObserver* obs7 = new ConcreteObserver(broker, "obs7");
    IObserver* obs8 = new ConcreteObserver(broker, "obs8");
    IObserver* obs9 = new ConcreteObserver (broker, "obs9");

    ConcretePublisher publisher1(broker, animal);
    ConcretePublisher publisher2(broker, birds);

    broker->subscribe(obs1, animal);
    broker->subscribe(obs2, animal);
    broker->subscribe(obs3, animal);
    broker->subscribe(obs4, animal);
    broker->subscribe(obs5, animal);
    broker->subscribe(obs6, animal);
    broker->subscribe(obs7, animal);
    broker->subscribe(obs8, animal);
    broker->subscribe(obs9, animal);

    broker->subscribe(obs1, birds);
    broker->subscribe(obs2, birds);
    broker->subscribe(obs3, birds);
    broker->subscribe(obs4, birds);
    broker->subscribe(obs5, birds);
    broker->subscribe(obs6, birds);
    broker->subscribe(obs7, birds);
    broker->subscribe(obs8, birds);
    broker->subscribe(obs9, birds);

    Event e1 {
        animal,
        "tiger fled",
    };

    Event e2{
        birds,
        "birds fled",
    };


    publisher1.publish(e1);
    publisher1.publish(e2);

    publisher2.publish(e1);
    publisher2.publish(e2);

}
    