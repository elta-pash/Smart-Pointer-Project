#ifndef HPC_H
#define HPC_H

#include<iostream>
#include<stdexcept>
#include<set>
#include<vector>
#include<memory>

class Health_Care_Provider {
    private:
    std::string name;
    std::set<Medical_Specialty> topics;
    unsigned wealth;
    public:
    Health_Care_Provider(std::string,const set<Medical_Specialty>&, unsigned=500);
    std::string get_name()const;
    virtual ∼Health_Care_Provider();
    void increase_wealth(unsigned);
    virtual unsigned perform_procedure(unsigned, shared_ptr<Patient>, Medical_Specialty)=0;
    virtual string hcp_type()const = 0;
    bool pay_license(unsigned);
    virtual void receive_license(Medical_Specialty);
    bool eligible_for(Medical_Specialty);
    std::ostream& print(std::ostream&) const; 
};

std::ostream& operator<<(std::ostream&, const Health_Care_Provider&);

class Teaching_Health_Care_Provider : public Health_Care_Provider {
    private:
    unsigned fee;
    std::string name;
    std::set<Medical_Specialty> topics;
    unsigned wealth;
    public:
    Teaching_Health_Care_Provider(unsigned, std::string, const set<Medical_Specialty>&, unsigned=500);
    unsigned perform_procedure(unsigned, std::shared_ptr<Patient>, Medical_Specialty) override;
    std::string hcp_type() const override;
    bool teach(Medical_Specialty, std::shared_ptr<Health_Care_Provider>);
};

class Smart_Health_Care_Provider : public Health_Care_Provider {
    private:
    unsigned fee;
    std::string name;
    std::set<Medical_Specialty> topics;
    unsigned wealth;
    public:
    Smart_Health_Care_Provider(unsigned, std::string, const set<Medical_Specialty>&, unsigned=500);
    unsigned perform_procedure(unsigned, std::shared_ptr<Patient>, Medical_Specialty) override;
    std::string hcp_type() const override;
    void receive_license(Medical_Specialty) override;
};

#endif
