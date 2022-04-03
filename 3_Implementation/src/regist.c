#include <stdio.h>
#include "registration.h"

int check_reg(long p){

    // Status for registration details of new users  
    pd[0].aadhar_card_num=p;
    int i=1;
    while(i<=1000){
        if(pd[i].aadhar_card_num==pd[0].aadhar_card_num){
            if(pd[i].different_vac==0)
                return 0;
            else
                return 1;
        }
        i++;
    }
    return -1;
}

// Status till now how many vaccine should be given
int check_vac(int i){
     
    if (pd[i].vac_take==0){
        pd[i].vac_take++;
        return 1;}
    else if(pd[i].vac_take==1){
        pd[i].vac_take++;
        return 2;}
    else if (pd[i].vac_take==2){
        return 3;}
    else
        return 0;

}