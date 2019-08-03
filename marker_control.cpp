/**
   Marker controller
   @author S.Kajita
*/

#include "marker_control.h"
#include <cnoid/EigenUtil>

using namespace std;
using namespace cnoid;

static MarkerController* instance = nullptr;

MarkerController* MarkerController::instance()
{
  return ::instance;
}

MarkerController::MarkerController()
{
  ::instance = this;
}

bool MarkerController::initialize(SimpleControllerIO* io)
{
  this->io = io;
  
  ioBody = io->body();
    
  ioBody->rootLink()->setActuationMode(Link::LINK_POSITION);
  io->enableInput(ioBody->rootLink(), Link::LINK_POSITION);
    
  io->os() << "MarkerController: LINK_POSITION mode." << endl;
  io->enableOutput(ioBody->rootLink());
    
  return true;
}

bool MarkerController::control()
{
  return true;
}

void MarkerController::setMarkerPosition(Vector3& p)
{
  ioBody->rootLink()->setTranslation(p);
}

CNOID_IMPLEMENT_SIMPLE_CONTROLLER_FACTORY(MarkerController)
