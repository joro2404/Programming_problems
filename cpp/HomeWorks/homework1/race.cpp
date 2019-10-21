#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Contestant {

    string name;
    double speed;
    double distance;

    public:

        Contestant(){}

        Contestant(string name, double speed){

            this->name = name;
            this->speed = speed;
            this->distance = 0;
        }

        string getName(){

            return name;
        }

        double getSpeed(){

            return speed;
        }

        double getDistance(){

            return distance;
        }

        double calcDistance(int iteration_count){

            distance = speed * iteration_count;
            return distance;
        }
};

class Race {

    vector<Contestant> contestants;

    public:

        vector<Contestant> getContestants(){

            return contestants;
        }

        void addContestant(Contestant new_contestant){
            
            contestants.push_back(new_contestant);
        }

        void resetContestants(){

            for(int i=0;i<contestants.size();i++){
                
                contestants[i].getDistance(0);
            }
        }
};