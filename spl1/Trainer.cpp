#include <trainer.h>

    Trainer::Trainer(int t_capacity){
        capacity=t_capacity;

    }
    int Trainer:: getCapacity()const{
        return capacity
    }
    void Tariner::addCustomer(Customer* customer){
        if(customerList.size()<capacity){
            customer.push_back(customer);


        }
        else {cout<<'Trainer is full'<<endl;}

    }
    void Trainer ::removeCustomer(int id){
        for(int i=0; i<customerList.size();i++){
            if (customerList.at(i).getId() == id){
                customerList.erase(i);
            }
        }
    }
    Customer* Trainer::getCustomer(int id){
        for(int i=0; i<customerList.size();i++){
            if (customerList.at(i).getId() == id){
                return customerList.at(i);
            }
        }
    }
    std::vector<Customer*>& Trainer::getCustomers(){
        return customerList;

    }
    std::vector<OrderPair>& Trainer::getOrders(){
        return orderList;
    }
    void Trainer::order(const int customer_id, const std::vector<int> workout_ids, const std::vector<Workout>& workout_options){
        for( int i=0 i<workout_ids.size();i++){
            for(int j=0;j<workout_options.size();j++)
            {if (workout_ids.at(i) == workout_options.at(j).getId()){
                OrderPair p{customer_id,workout_options.at(j)}
                orderList.push_back(p);
                
            }
            }
        }

    }
    void Trainer::openTrainer(){
        open=true;
     // maybe print (now open)
    }
    void Trainer::closeTrainer(){
        open=false;

    }
    ~Trainer();


Trainer::Trainer(/* args */)
{
}

Trainer::~Trainer()
{
}
