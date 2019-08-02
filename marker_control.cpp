/**
   Marker control
   @author S.Kajita
*/

#include "marker_control.h"

using namespace std;
using namespace cnoid;

static marker_control* instance = nullptr;

marker_control* marker_control::instance()
{
  return ::instance;
}

marker_control::marker_control()
{
  ::instance = this;
}

bool marker_control::initialize(SimpleControllerIO* io)
{
  ioBody = io->body();
    
  ioBody->rootLink()->setActuationMode(Link::LINK_POSITION);
  io->enableInput(ioBody->rootLink(), Link::LINK_POSITION);
    
  io->os() << "marker_control: LINK_POSITION mode." << endl;
  io->enableOutput(ioBody->rootLink());
    
  return true;
}

bool marker_control::control()
{
  return true;
}

void marker_control::setMarkerPosition(Vector3& p)
{
  ioBody->rootLink()->setTranslation(p);
}

CNOID_IMPLEMENT_SIMPLE_CONTROLLER_FACTORY(marker_control)
