#include "Supervisor.h"
#include <chrono>
#include <iostream>

int main(){
    auto start = std::chrono::high_resolution_clock::now();
    Supervisor *s = new Supervisor();
    s -> callout();
    JobBoard *jobBoard = new JobBoard();
    JobManualHub* jobManualHub = new JobManualHub();
    jobManualHub -> addManual(new JobManual("sand to gold"));
    jobManualHub -> addManual(new JobManual("gold to seed"));
    jobManualHub -> addManual(new JobManual("seed to plant"));
    jobManualHub -> addManual(new JobManual("plant to rice"));
    s -> aquireJobBoard(jobBoard);
    s -> addJobManualHub(jobManualHub);
    s -> recruitWorker();
    s -> recruitWorker();
    s -> recruitWorker();
    s -> recruitWorker();
    
    s -> startWork();

    auto stop = std::chrono::high_resolution_clock::now();  
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start); 
  
    std::cout << "Time taken by function: "
         << duration.count() << " miliseconds" << std::endl;
    return 0;
}