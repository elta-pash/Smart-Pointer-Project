#include<iostream>
#include<stdexcept>
#include<map>
#include<vector>
#include<memory>
#include<algorithm>
#include "hcp.h"
#include "illness.h"
#include "patient.h"

Health_Care_Provider::Health_Care_Provider(std::string n,const std::set<Medical_Specialty>& topics, unsigned wealth=500): name{n}, topics{topics} {
    if (name.empty()){
        throw std::runtime_error("name is empty");
    }
}

std::string Health_Care_Provider::get_name() const{
    return name;
}

virtual Health_Care_Provider::∼Health_Care_Provider(){
    //delete[];  
}

void Health_Care_Provider::increase_wealth(unsigned x) {
    wealth += x;
}

virtual unsigned Health_Care_Provider::perform_procedure(unsigned, shared_ptr<Patient>, Medical_Specialty)=0;
virtual std::string Health_Care_Provider::hcp_type()const = 0;
bool Health_Care_Provider::pay_license(unsigned x){
    int left{0};
    left = wealth - x;
    if (left < 0) {
        return false;
    }
    else {
        wealth = left;
        return true;
    }
}

virtual void Health_Care_Provider::receive_license(Medical_Specialty x){
    topics.insert(x);
}

bool Health_Care_Provider::eligible_for(Medical_Specialty m){
    bool here{false};
    if (topics.find(m) != topics.end()) {
        here = true;
    }
    return here;
}

std::ostream& Health_Care_Provider::print(std::ostream& o) const{
    o << "[" << name << ", {";
    for (int i{0}; i < topics.size(); ++i) {
        o << topics.at(i);
        if (i < topics.size()-1) {
            o << ", ";
        }
    }
    return o << wealth << " moneyz, " << hcp_type << "]";
}
    

std::ostream& operator<<(std::ostream& o, const Health_Care_Provider& h){
    return h.print(o);
}

//TEACHING_HCP


Teaching_Health_Care_Provider::Teaching_Health_Care_Provider(unsigned fee, std::string n, const set<Medical_Specialty>& topics, unsigned wealth=500): fee{fee}, name{n}, topics{topics} {
    if (name.empty()){
        throw std::runtime_error("name is empty");
    }
}

unsigned Teaching_Health_Care_Provider::perform_procedure(unsigned x, std::shared_ptr<Patient> p, Medical_Specialty m) override{
    if (this->eligible_for(m)) {
        if (p->requires_treatment_in(m)) {
            if (p->pay_procedure(x)) {
                increase_wealth(x);
                return p->cure(m);
            }
        }
    }
}

std::string Teaching_Health_Care_Provider::hcp_type() const override{
    //???
    return "Teacher";
}

bool Teaching_Health_Care_Provider::teach(Medical_Specialty m, std::shared_ptr<Health_Care_Provider> target){
    if (target.get() == this || target->eligible_for(m) || !(target->pay_license(fee)) || !(this->eligible_for(m))) {
        return false;
    }
    increase_wealth(fee);
    target->pay_license(fee);
    target->receive_license(m);
    return true;
}

//SMART_HCP


Smart_Health_Care_Provider::Smart_Health_Care_Provider(unsigned fee, std::string n, const set<Medical_Specialty>& topics, unsigned wealth=500) : fee{fee}, name{n}, topics{topics} {
    if (name.empty()){
        throw std::runtime_error("name is empty");
    }
}

unsigned Smart_Health_Care_Provider::perform_procedure(unsigned x, std::shared_ptr<Patient> p, Medical_Specialty m) override{
    return 0;
}

std::string Smart_Health_Care_Provider::hcp_type() const override{
    return "Smart";
}
void Smart_Health_Care_Provider::receive_license(Medical_Specialty m) override {
    topics.insert(m);
    this->increase_wealth(fee);
}