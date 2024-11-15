#include<iostream>
#include<stdexcept>
#include<map>
#include<vector>
#include<memory>
#include<algorithm>
#include "hcp.h"
#include "illness.h"
#include "patient.h"
#include "hospital.h"

Hospital::Hospital(std::string name): name{name} {
    if (name.empty()) {
        throw std::runtime_error ("Hospital has no name");
    }
}

bool Hospital::sign_hcp(std::shared_ptr<Health_Care_Provider> m){
    bool added{false};
    auto it = hcps.find(m->get_name());
    if (it == hcps.end()) {
        hcps.emplace(m->get_name(), m);
        added = true;
    }
    return added;
}

bool Hospital::admit_patient(std::shared_ptr<Patient> m){
    bool present{false};
    auto it = patients.find(m->get_name());
    if (it == patients.end() || patients[m->get_name()].expired()) {
        patients.emplace(m->get_name(), m);
        present = true;
    }
    return present;
}

bool Hospital::dismiss_hcp(std::string n){
    int count{0};
    auto it = hcps.find(n);
    if (it != hcps.end()) {
        hcps.erase(n);
        ++count;
    }
    if (count){
        return true;
    }
    else {
        return false;
    }
}

std::shared_ptr<Health_Care_Provider> Hospital::get_hcp(std::string n) const{
    auto it = hcps.find(n);
    if (it == hcps.end()) {
        throw std::runtime_error ("no hcp with this name was found");
    }
    return it->second;
}

std::shared_ptr<Patient> Hospital::get_patient(std::string n) const{
    auto it = patients.find(n);
    if (it == patients.end() || it->second.expired()) {
        throw std::runtime_error("no name was found ot ptr is expired");
    }
    return it->second.lock();
}

bool Hospital::dismiss_patient(std::string n){
    auto it = patients.find(n);
    int count{0};
    if (it != patients.end() && !it->second.expired()) {
        patients.erase(n);
        return true;
    }
    return false;
}
std::ostream& Hospital::print(std::ostream& o) const{
    //[name, hcps {hcp0, ..., hcpn}, patients {patient0,..., patientn}]
    o << "[" << name << ", hcps {";
    for (auto it = hcps.begin(); it != hcps.end(); ++it) {
        o << it->first;
        if (it != std::prev(hcps.end())) {
            o << ", ";
        }
    }
    o << "}, patients {";
    for (auto it = patients.begin(); it != patients.end(); ++it) {
        o << it->first;
        if (it != std::prev(patients.end())) {
            o << ", ";
        }
    }
    return o << "}]";
}

std::ostream& operator<<(std::ostream& o, const Hospital& p) {
    return p.print(o);
}