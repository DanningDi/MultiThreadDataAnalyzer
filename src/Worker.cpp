#include "Worker.h"
#include "Job.h"
#include <iostream>
#include "Supervisor.h"
#include <thread>
#include <chrono>
#include <mutex>

void Worker::callout(){
    std::cout<<"I'm worker No."<<workerID<<" I'm start working!"<<std::endl;
}

void Worker::startWork(){
    callout();
    myJobManualHub = supervisor -> getJobManualHub();
    while(isActive){
        bool ret = requestJob();
        if(!ret)
            break;
        //do work
        doJob();
        //submit work
        submmitJob();
    }
//    std::cout<<"I'm worker No."<<workerID<<" end working"<<std::endl;
}

Worker::Worker(Supervisor *s){
    supervisor = s;
}
Worker::Worker(int _workerID, Supervisor *s){
   // std::cout<<"new worker recuited!, ID: "<<workerID<<
    workerID = _workerID;
    supervisor = s;
}

bool Worker::requestJob(){
    job_todo = supervisor -> giveJob();
    if(job_todo == nullptr){
        return false;
    }
    return true;
}

void Worker::doJob(){
    std::cout<<"I'm worker No."<<workerID<<" my job to do is : "<<job_todo -> getType()<<std::endl;
    job_done = myJobManualHub -> doJob(job_todo);
    delete job_todo;
}

void Worker::submmitJob(){
    if (job_done != nullptr) {
        supervisor -> postJob(job_done);
    }else{
        supervisor -> postResult();
    }
   // std::cout<<"I'm worker No."<<workerID<<"my job is : "<<job -> getType()<<std::endl;
}