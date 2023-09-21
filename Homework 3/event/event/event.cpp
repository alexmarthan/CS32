#include <iostream>
#include <string>
using namespace std;

class Event
{
    
public:
    Event(std::string name): m_name(name){}
    virtual ~Event(){}
    
    std::string name() const{
        return m_name;
    }
    virtual bool isSport() const{
        return true;
    }
    virtual std::string need() const = 0; // this is pure virtual
private:
    std::string m_name;
};

class Concert : public Event
{
private:
    std::string m_genre;
public:
    Concert(std::string name, std::string genre): Event(name), m_genre(genre){}
    ~Concert(){
        std::cout << "Destroying the " << name() << ' ' << m_genre << " concert" << '\n';
    }
    
    virtual std::string need() const{
        std::string ConcertNeed = "a stage";
        return ConcertNeed;
    }
    
    virtual bool isSport() const{
        return false;
    }
    
};

class BasketballGame: public Event
{

public:
    BasketballGame(std::string name): Event(name){}
    ~BasketballGame(){
        std::cout << "Destroying the " << name() << " basketball game" << '\n';
    }
    
    virtual std::string need() const{
        std::string ballGameNeed = "hoops";
        return ballGameNeed;
    }
};

class HockeyGame: public Event
{
public:
    HockeyGame(std::string name): Event(name){}
    ~HockeyGame(){
        std::cout << "Destroying the " << name() << " hockey game" << '\n';
    }
    virtual std::string need() const{
        std::string hockeyNeed = "ice";
        return hockeyNeed;
    }
};



void display(const Event* e)
{
    cout << e->name() << ": ";
    if (e->isSport())
        cout << "(sport) ";
    cout << "needs " << e->need() << endl;
}


 int main()
 {
 Event* events[4];
 events[0] = new BasketballGame("Lakers vs. Warriors");
 // Concerts have a name and a genre.
 events[1] = new Concert("Ricardo Arjona", "Latin pop");
 events[2] = new Concert("Erykah Badu", "neo soul");
 events[3] = new HockeyGame("Kings vs. Oilers");

 cout << "Here are the events." << endl;
 for (int k = 0; k < 4; k++)
 display(events[k]);

 // Clean up the events before exiting
 cout << "Cleaning up." << endl;
 for (int k = 0; k < 4; k++)
 delete events[k];

 }


