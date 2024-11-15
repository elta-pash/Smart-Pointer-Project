#include<iostream>
#include<stdexcept>
#include<set>
#include<algorithm>
#include "patient.h"
#include "illness.h"

Patient::Patient(std::string name, int age, const std::set<Illness>& illnesses, unsigned wealth=200): name{name}, age{age}, illnesses{illnesses} {
    if ((name.empty()) || (age < 0)) {
        throw std::runtime_error("name is empty or age is less than 0");
    }
    if (illnesses.empty()) {
        throw std::runtime_error("no illnesses found");
    }
}

void Patient::increase_wealth(unsigned x) {
    wealth += x;
}

bool Patient::pay_procedure(unsigned x) {
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

void Patient::catch_disease(const Illness& x){
    illnesses.insert(x);
}

bool Patient::requires_treatment_in(Medical_Specialty x) const{
    unsigned count{0};
    for (auto it = illnesses.begin(); it != illnesses.end(); ++it) {
        if (it->get_specialty() == x) {
            ++count;
        }
    if (count > 0) {
        return true;
    }
    return false;
}
}

bool Patient::healthy() const {
    if (illnesses.empty()) {
        return true;
    }
    return false;
}

std::string Patient::get_name() const {
    return name;
}

unsigned Patient::cure(Medical_Specialty x){
    unsigned count{0};
    for (auto it = illnesses.begin(); it != illnesses.end();) {
        if (it->get_specialty() == x) {
            it = illnesses.erase(it);
            ++count;
        }
        else {
            ++it;
        }
    }
    return count;
    /*std::set<Illness> removed;
    for (int i{0}; i < illnesses.size(); ++i) {
        if (illnesses.at(i).get_specialty() == x) {
            removed.insert(illnesses.at(i));
            ++count;
        }
    }
    for (int j{0}; j < removed.size(); ++j){
        illnesses.erase(removed.at(j));
    }
    return count;*/
}

bool Patient::operator==(const Patient& rop){
    if (name == rop.name) {
        if (age == rop.age) {
            if (illnesses == rop.illnesses) {
                if (wealth == rop.wealth){
                    return true;
                }
            }
        }
    }
}

std::ostream& print(std::ostream& o) const{
    o << "[" << name << ", " << age << " years, {";
    for (auto it = illnesses.begin(); i != illnesses.end(); ++i) {
        o << static_cast<std::string>(*it);
        if (it != std::prev(illnesses.end())) {
            o << ", ";
        }
    }
    return o << "}, " << wealth << "moneyz]";
}

std::ostream& operator<<(std::ostream& o,const Patient& p){
    return p.print(o);
}