#ifndef _MockEventDisplayManager_hh
#define _MockEventDisplayManager_hh

#include <ROOT/REveElement.hxx>
#include <ROOT/REveScene.hxx>
#include <condition_variable>
#include <limits>
#include <mutex>
#include <stdexcept>
#include <iostream>
namespace ROOT::Experimental {
  class REveManager;
}

namespace ots {

  constexpr auto invalid_event = std::numeric_limits<unsigned>::max();

  class MockEventDisplayManager : public ROOT::Experimental::REveElement {
  public:
    MockEventDisplayManager() = default; // ROOT needs a dictionary

    explicit MockEventDisplayManager(ROOT::Experimental::REveManager* eveMgr,
                                     std::condition_variable& cv,
                                     std::mutex& m);

    void NextEvent();
    void QuitRoot();

  private:
    ROOT::Experimental::REveManager* eveMng_{nullptr};
    std::condition_variable* cv_{nullptr};
    std::mutex* m_{nullptr};
    bool doneProcessingEvents_{false};
  };
}

#endif /* MockEventDisplayManager_h */
