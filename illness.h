#ifndef ILLNESS_H
#define ILLNESS_H

#include<iostream>
#include<stdexcept>
#include<string>

enum class Medical_Specialty {Cardiology, Dermatology, Endocrinology, Gynecology, Neurology, Oncology, Pathology, Pediatrics, Pulmonology, Urology};
//const std::vector<std::string> med_names{"Cardiology", "Dermatology", "Endocrinology", "Gynecology", "Neurology", "Oncology", "Pathology", "Pediatrics", "Pulmonology", "Urology"};

class Illness {
    private:
    Medical_Specialty med;
    std::string name;
    public:
    Illness(Medical_Specialty, const std::string&);
    Medical_Specialty get_specialty()const;
    std::string get_name() const;
    bool operator== (const Illness&) const;
    bool operator< (const Illness&) const;

};

std::ostream& operator<<(std::ostream&, const Illness&);
std::ostream& operator<<(std::ostream&, const Medical_Specialty);
//   return o << med_names.at(static_cast<size_t>(m));
/*Puts a string representationof m intoostreamo. Thestringrepresentationof mshouldreflect the nameoftheconstant,e.g.Medical_Specialty::Pathologyshouldbetransformedto Pathology.*/
#endif
