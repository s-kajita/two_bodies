/**
   A simplest controller
   @author S.Kajita
*/

#include <cnoid/SimpleController>
#include <cnoid/Link>
#include <cnoid/BodyMotion>

using namespace std;
using namespace cnoid;

const int X=0;
const int Y=1;
const int Z=2;

class ball_control : public cnoid::SimpleController
{
  BodyPtr ioBody;

  int timeCount;
  int holdCount;
  double time;

  double Dtime;
  
public:

  virtual bool initialize(SimpleControllerIO* io)
  {
    ioBody = io->body();
    
    io->enableInput(ioBody->rootLink(), LINK_POSITION);
    io->enableOutput(ioBody->rootLink());
    
    io->os() << "ball_control: LINK_POSITION mode." << endl;

    Dtime = io->timeStep();
    io->os() << "body->mass() = " << ioBody->mass() << " [kg]" << endl;
    Position T = ioBody->rootLink()->position();
    io->os() << "position = " << T.translation() << " [m]" << endl;
    
    return true;
  }

  virtual bool control()
  {
    timeCount++;
    time = Dtime*timeCount;

    Position T = ioBody->rootLink()->position();
    Vector3 p = T.translation();

    
    //ioBody->rootLink()->setTranslation(p);
    
    return true;
  }
        
};

CNOID_IMPLEMENT_SIMPLE_CONTROLLER_FACTORY(ball_control)
