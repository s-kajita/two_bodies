/**
   A simplest controller
   @author S.Kajita
*/

#include <cnoid/SimpleController>
#include <cnoid/Link>
#include <cnoid/BodyMotion>

#include "MarkerController.h"

using namespace std;
using namespace cnoid;

const int X=0;
const int Y=1;
const int Z=2;

class BallController : public SimpleController
{
  BodyPtr ioBody;

  int timeCount;
  double time;

  double Dtime;

  SimpleControllerIO* io;
  MarkerController* markerControl;
  
public:

  virtual bool initialize(SimpleControllerIO* io)
  {
    this->io = io;
    ioBody = io->body();
    
    io->enableInput(ioBody->rootLink(), LINK_POSITION);
    io->enableOutput(ioBody->rootLink());
    
    io->os() << "BallController: LINK_POSITION mode." << endl;

    Dtime = io->timeStep();
    io->os() << "body->mass() = " << ioBody->mass() << " [kg]" << endl;
    Position T = ioBody->rootLink()->position();
    io->os() << "position = " << T.translation() << " [m]" << endl;
    
    return true;
  }

  virtual bool start() override
  {
    markerControl = MarkerController::get_instance();  // <======== This line makes a CRASH!! ====
    return true;
  }

  virtual bool control() override
  {
    timeCount++;
    time = Dtime*timeCount;

    Position T = ioBody->rootLink()->position();
    Vector3 p = T.translation();

    if(markerControl){
      p(Z) = 0.3;		// keep constant marker height 
      markerControl->setMarkerPosition(p);
    }
    
    return true;
  }
        
};

CNOID_IMPLEMENT_SIMPLE_CONTROLLER_FACTORY(BallController)
