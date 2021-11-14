#include "Customer.h"


using namespace std;

Customer::Customer(string c_name, int c_id):
name(c_name), 
id(c_id) 
{}

string Customer::getName() const { return name; }
int Customer::getId() const { return id; }


SweatyCustomer::SweatyCustomer(string name, int id): Customer(name, id) {}

vector<int> SweatyCustomer::order(const vector<Workout> &workout_options){
    vector<int> orders;
    for (Workout w : workout_options) {
        if (w.getType() == WorkoutType::CARDIO) {
            orders.push_back(w.getId());
        }
    }
    return orders;
}
string SweatyCustomer::toString() const { 
    return to_string(getId()) + " " + getName();
}

CheapCustomer::CheapCustomer(string name, int id): Customer(name, id) {}

vector<int> CheapCustomer::order(const vector<Workout> &workout_options) {
    // assumes that workout_options is sorted by price, lowest first.
    vector<int> orders;
    orders.push_back(workout_options.at(0).getId());
    return orders;
}
string CheapCustomer::toString() const { 
    return to_string(getId()) + " " + getName();
}


HeavyMuscleCustomer::HeavyMuscleCustomer(string name, int id) : Customer(name, id) {}

vector<int> HeavyMuscleCustomer::order(const vector<Workout> &workout_options) {
    // assumes that workout_options is sorted by price, lowest first.
    vector<int> orders;
    for (Workout w : workout_options) {
        if (w.getType() == WorkoutType::ANAEROBIC) {
            orders.push_back(w.getId());
            break;
        }
    }
    return orders;
}
string HeavyMuscleCustomer::toString() const { 
    return to_string(getId()) + " " + getName();
}

FullBodyCustomer::FullBodyCustomer(string name, int id) : Customer(name, id) {}

vector<int> FullBodyCustomer::order(const vector<Workout> &workout_options){
    // assumes that workout_options is sorted by price, lowest first.
    vector<int> orders;
    bool done_cardio = false, done_mix = false, done_anaerobic = false;
    for (int i = 0; i < workout_options.size() & !done_cardio; i++) {
        if (workout_options.at(i).getType() == WorkoutType::CARDIO) {
            orders.push_back(workout_options.at(i).getId());
            done_cardio = true;
        }
    }

    for (int j = workout_options.size()-1; j > 0 & !done_mix; j--) {
        if (workout_options.at(j).getType() == WorkoutType::MIXED) {
            orders.push_back(workout_options.at(j).getId());
            done_mix = true;
        }
    }

    for (int k = 0; k < workout_options.size() & !done_anaerobic; k++) {
        if (workout_options.at(k).getType() == WorkoutType::ANAEROBIC) {
            orders.push_back(workout_options.at(k).getId());
            done_cardio = true;
        }
    }

    if (done_anaerobic && done_cardio && done_mix) {
        return orders;
    }
    else {
        vector<int> empty;
        return empty;
    }

}
string FullBodyCustomer::toString() const { 
    return to_string(getId()) + " " + getName();
}
