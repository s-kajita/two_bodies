/**
   Marker control
   @author S.Kajita
*/

#include <cnoid/SimpleController>
#include <cnoid/Config>
#include <cnoid/Link>
#include <cnoid/BodyMotion>

namespace cnoid {

class CNOID_GENERAL_EXPORT marker_control : public SimpleController
{
  SimpleControllerIO* io;
  BodyPtr ioBody;
  double Dtime;
  
public:
  static marker_control* instance();

  marker_control();
  virtual bool initialize(SimpleControllerIO* io) override;
  virtual bool control() override;
  void setMarkerPosition(Vector3& p);      
};

}
