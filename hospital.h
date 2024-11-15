#ifndef HOSPITAL_H
#define HOSPITAL_H

#include<iostream>
#include<stdexcept>
#include<set>
#include<memory>
#include<map>

#include "illness.h"
#include "patient.h"
#include "hcp.h"

class Hospital{
    private:
    std::string name;
    std::map<std::string, std::shared_ptr<Health_Care_Provider>> hcps;
    std::map<std::string, std::weak_ptr<Patient>> patients;
    public:
    Hospital(std::string);
    bool sign_hcp(std::shared_ptr<Health_Care_Provider>);
    bool admit_patient(std::shared_ptr<Patient>);
    bool dismiss_hcp(std::string);
    std::shared_ptr<Health_Care_Provider> get_hcp(std::string) const;
    std::shared_ptr<Patient> get_patient(std::string) const;
    bool dismiss_patient(std::string);
    std::ostream& print(std::ostream&) const;
};

std::ostream& operator<<(std::ostream&, const Hospital&);

#endif
