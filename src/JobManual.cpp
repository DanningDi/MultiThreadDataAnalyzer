#include "JobManual.h"
#include <thread>

Job* JobManual::doJob(Job* jobToDo) {
    Job* job_done;
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
    std::string jType = jobToDo -> getType();
    if(jType == "sand to gold"){
        job_done = new Job("gold to seed");
    }else if (jType == "gold to seed"){
        job_done = new Job("seed to plant");
    }else if (jType == "seed to plant") {
        job_done = new Job("plant to rice");
    }else if (jType == "plant to rice") {
        job_done = nullptr;
    }
    return job_done;
}