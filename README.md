# Smart-Pointer-Project 

A C++ project simulating a healthcare system using modern object-oriented programming practices, including smart pointers (`shared_ptr`, `weak_ptr`). The system manages patients, healthcare providers, and hospitals with advanced functionalities.

### Basic Implementation
1. **Medical Specialties**: Enum for specialties like Cardiology, Neurology, and more.
2. **Illness**: Represents diseases linked to medical specialties.
3. **Patient**: Tracks patient details, illnesses, and wealth.
4. **Health Care Provider (HCP)**:
   - Base class for healthcare professionals.
   - Supports procedures, wealth management, and specialization.
5. **Hospital**:
   - Manages HCPs and patients using smart pointers.
   - Supports operations like admitting/dismissing patients and hiring HCPs.
6. **Teaching HCP**: Can teach other HCPs for a fee.
7. **Smart HCP**: Gains wealth when acquiring new licenses.
