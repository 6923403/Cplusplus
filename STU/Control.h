#ifndef _CONTROL_H_
#define _CONTROL_H_

#include "Student.h"

class Control : public Student
{
    public:
        Control();
        ~Control();
        
        void changeStu_info();
        void ChangeStu_grade();
};

#endif
