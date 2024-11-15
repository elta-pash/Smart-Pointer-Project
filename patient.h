#ifndef PATIENT_H
#define PATIENT_H

#include<iostream>
#include<stdexcept>
#include<set>

class Patient {
    private:
    std::string name;
    int age;
    std::set<Illness> illnesses;
    unsigned wealth;
    public:
    Patient(std::string, int, const std::set<Illness>&, unsigned=200);
    void increase_wealth(unsigned);
    bool pay_procedure(unsigned);
    void catch_disease(const Illness&);
    bool requires_treatment_in(Medical_Specialty) const;
    bool healthy() const;
    std::string get_name() const;
    unsigned cure(Medical_Specialty);
    bool operator==(const Patient&);
    std::ostream& print(std::ostream& o) const;
};

std::ostream& operator<<(std::ostream&,const Patient&);

#endif
