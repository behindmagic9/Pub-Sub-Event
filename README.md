                           +-------------------+
                           |       Event       |
                           +-------------------+
                           | Topic topic       |
                           | string data       |
                           +-------------------+


                           +-------------------+
                           |       Topic       |
                           +-------------------+
                           | Animal            |
                           | Birds             |
                           +-------------------+



        +------------------------------------------------+
        |                    ISubject                    |
        |              << Broker Interface >>            |
        +------------------------------------------------+
        | + subscribe(IObserver*, Topic)                |
        | + unsubscribe(IObserver*, Topic)              |
        | + notify(Event&)                              |
        +------------------------------------------------+
                               ^
                               |
                               |
                    +----------------------+
                    |   ConcreteSubject    |
                    |       (Broker)       |
                    +----------------------+
                    | unordered_map<       |
                    | Topic,               |
                    | vector<IObserver*>>  |
                    +----------------------+
                    | + subscribe()        |
                    | + unsubscribe()      |
                    | + notify()           |
                    +----------------------+
                         ^            ^
                         |            |
                         |            |
              ISubject* |            | ISubject*
                         |            |
          +-------------------+   +----------------------+
          | ConcreteObserver  |   | ConcretePublisher    |
          +-------------------+   +----------------------+
          | ISubject* subject |   | ISubject* subject    |
          | string name       |   | Topic topic          |
          +-------------------+   +----------------------+
          | + update(Event&)  |   | + publish(Event&)    |
          +-------------------+   +----------------------+
                    ^                         ^
                    |                         |
                    |                         |
             +-------------+          +---------------+
             | IObserver   |          | IPublisher    |
             +-------------+          +---------------+
             | + update()  |          | + publish()   |
             +-------------+          +---------------+



===================== EVENT FLOW =====================

        Publisher.publish(Event)
                    |
                    v
          Broker.notify(Event)
                    |
                    v
      Find observers subscribed to:
             Event.topic
                    |
                    v
         Observer.update(Event)
