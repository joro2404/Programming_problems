#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class CarCatalogue {

    private:

        string producer;
        vector<string> models;

    public:

        CarCatalogue() {}

        CarCatalogue(string produer, vector<string> models) {

            this->producer = producer;
            this->models = models;
        }

        string getBrand() {

            return producer;
        }

        vector<string> getModels(){

            return models;
        }

        void addModel(string model_name){

            models.push_back(model_name);
        }

        int hasModel(string model_name){

            for(int i=0;i<models.size();i++){

                if(models[i] == model_name)return 1;
            }
            
            return 0;
        }

        string toString() {

            ostringstream out;
            out << producer << ": " << "\n  ";

            for(int i=0;i<models.size();i++){

                out << models[i] << "\n  ";
            }
                
            string data = out.str();

            return data;
        }

        void removeModelAt(int index) {
            
            models.erase(models.begin()+index);
        }

        void replaceModelAt(int index, string model_name){

            replace(models.begin(), models.end(), models[index], model_name);
        }
};