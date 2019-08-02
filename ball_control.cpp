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
  bool SetRobotModel(SimpleControllerIO* io)
  {
    ioBody = io->body();
    io->os() << "body->mass() = " << ioBody->mass() << " [kg]" << endl;

    Dtime = io->timeStep();

    return true;
  }
  
  //-------------------------------------------------------------------
  virtual bool initialize(SimpleControllerIO* io)
  {
    io->setJointOutput(JOINT_ANGLE);
    io->setJointInput(JOINT_ANGLE);
    io->os() << "ball_control: position mode." << endl;
    
    if(!SetRobotModel(io) ) return false;
    
    return true;
  }

  virtual bool control()
  {
    timeCount++;
    time = Dtime*timeCount;

    return true;
  }
        
};

CNOID_IMPLEMENT_SIMPLE_CONTROLLER_FACTORY(ball_control)
