#include "Offline/GeometryService/inc/GeomHandle.hh"
#include "EventDisplay/inc/GeomUtil.hh"

namespace REX = ROOT::Experimental;
using namespace std;
using namespace mu2e;

double GeomUtil::FindStoppingTarget_z(){
  CLHEP::Hep3Vector _detSysOrigin = mu2e::GeomHandle<mu2e::DetectorSystem>()->getOrigin();
  GeomHandle<StoppingTarget> target;
  std::cout<<"Target "<<target->centerInMu2e().z()<<" "<<_detSysOrigin.z()<<std::endl;
  StoppingTarget_z = target->centerInMu2e().z() - _detSysOrigin.z();
  return StoppingTarget_z;
}
