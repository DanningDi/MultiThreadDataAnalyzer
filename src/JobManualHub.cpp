#include "JobManualHub.h"
#include <thread>

Job* JobManualHub::doJob(Job* jobToDo) {
    std::string jType = jobToDo -> getType();
    if(existingManuals.find(jType) == existingManuals.end())
        return nullptr;

    return existingManuals[jType] -> doJob(jobToDo);;
}

void JobManualHub::addManual(JobManual* newManual) {
    existingManuals[newManual -> getType()] = newManual;
}