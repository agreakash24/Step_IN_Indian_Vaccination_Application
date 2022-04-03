#ifndef REGIST_C
#define REGIST_C


int check_reg(long pd );


int quitregist();


int check_vac(int );

//Function for take input from users
typedef struct patient{
    int persone_age;
    long aadhar_card_num;
    int mobile_number;
    int unique_code;
    int different_vac;
    int vac_take;
}patient_details;


patient_details pd[1000];

#endif
