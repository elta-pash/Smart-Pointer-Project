#include "illness.h"
#include<vector>
#include<string>
#include<iostream>

Illness::Illness(Medical_Specialty med, const std::string& name): med{med}, name{name} {
    if (name.empty()) {
        throw std::runtime_error ("name is empty"); 
    }   
}

Medical_Specialty Illness::get_specialty() const {
    return med;
}

std::string Illness::get_name() const {
    return name;
}

/*std::ostream& Illness::print(std::ostream& o) const {
    //[med, name]
    return o << "[" << med_names.at(static_cast<size_t>(med)) << ", " << name << "]";
}*/

bool Illness::operator==(const Illness& rop) const {
    if (name == rop.name) {
        if (med == rop.med) {
            return true;
        }
    }
    return false;
}

bool Illness::operator<(const Illness& rop) const {
    if (get_specialty() < rop.get_specialty()) {
        return true;
    }
    if (get_specialty() == rop.get_specialty()) {
        if (get_name() < rop.get_name()) {
            return true;
        }
    }
    return false;
}

std::ostream& operator<<(std::ostream& o, const Illness& ill){
    //return ill.print(o);
    return o << "[" << ill.med << ", " << ill.name << "]";
    
}

/*std::ostream& print(std::ostream& o) const {
    return o << med_names.at(static_cast<size_t>(m));
}*/

/*std::ostream& operator<<(std::ostream& o, const Medical_Specialty m){
    //return o << med_names.at(static_cast<size_t>(ill.med));
    switch(m){
        case Medical_Specialty::Cardiology:
        o << "Cardiology";
        break;
        case Medical_Specialty::Dermatology:
        o << "Dermatology";
        break;
        case Medical_Specialty::Endocrinology:
        o << "Endocrinology";
        break;
        case Medical_Specialty::Gynecology:
        o << "Gynecology";
        break;
        case Medical_Specialty::Neurology:
        o << "Neurology";
        break;
        case Medical_Specialty::Oncology:
        o << "Oncology";
        break;
        case Medical_Specialty::Pathology:
        o << "Pathology";
        break;
        case Medical_Specialty::Pediatrics:
        o << "Pediatrics";
        break;
        case Medical_Specialty::Pulmonology:
        o << "Pulmonology";
        break;
        case Medical_Specialty::Urology:
        o << "Urology";
        break;
        default:
        o << "Unknown Specialty";
        break;
    }
    return o;
}*/