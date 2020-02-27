#include "Supervisor.h"
//#include "Worker.h"
#include <iostream>
#include <thread>
#include <chrono>

void Supervisor::callout(){
    std::cout<<"I'm a supervisor!"<<std::endl;
}

void Supervisor::recruitWorker(){
    workers.push_back(new Worker(workers.size(), this));
    std::cout<<"Recruited new woker!  Current number of worker are: "<<workers.size()<<std::endl;
}

void Supervisor::aquireJobBoard(JobBoard *jB) {
    jobBoard = jB;
}

void Supervisor::addJobManualHub(JobManualHub *jobManualHub) {
    myJobManualHub = jobManualHub;
}
JobManualHub* Supervisor::getJobManualHub() {
    return myJobManualHub;
}
Job* Supervisor::giveJob(){
    return jobBoard -> nextJob();
}

void Supervisor::startWork(){
    std::vector<std::thread*> threads;
    for(auto &worker : workers){
        //worker -> startWork();

        threads.push_back(new std::thread(&Worker::startWork, worker));

    }

    for(auto &t : threads){
        t -> join();
    }

   // std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void Supervisor::postJob(Job *job){
    jobBoard -> pushJob(job);
}

void Supervisor::postResult(){
    riceCount++;
    jobBoard -> addFinishedJobs();
    std::cout<<"###############rice count: "<<riceCount<<std::endl; 
}