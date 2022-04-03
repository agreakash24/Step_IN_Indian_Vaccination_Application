#include "stdio.h"
#include "registration.h"


// Main program begain here
int main(){
    
    int update;         // callback variable which check status of user
    long aadhar_num;     // fFor storing user aadhar number        
    int vaccine_1=0,vaccine_2=0;        //Choose any one options
    
    
    quitregist();
    
    int attmpt=1000;    // total nuumber of run perform
    while(attmpt>0){
        
    aply:
    printf("\nWelcome to Vaccination App!!!\n");
    printf("Please enter your Aadhar Number:");
    scanf("%li",&aadhar_num);
   
    
    update = check_reg(aadhar_num);
    int i,j=0,vaccine_check=0,choice=0,pno;
    
    i=1;
    while(i<=1000){
        if(pd[i].aadhar_card_num==aadhar_num)
            j=i;
    i++;
    }
    
    if(update==-1){
        quitregist();
        i=1;
        while(i<=1000){
            if(pd[i].aadhar_card_num==0){
                printf("Please fill details for vaccine registration\n");
                pd[i].aadhar_card_num=pd[0].aadhar_card_num;
                printf("Enter your phone number: ");
                scanf("%d",&pd[i].mobile_number);
                printf("Enter your age: ");
                scanf("%d",&pd[i].persone_age);
                printf("Enter your Unique Code: ");
                scanf("%d",&pd[i].unique_code);
                break;}
            i++;
        }
        printf("Account has been created, Please Log in with your credentials\n");
        goto aply;
    }
    else if (update==0){
        //Check
        printf("User Authentication , Enter your Mobile Number\n");
        prvaccine_1:
        scanf("%d",&pno);
        if(pno==pd[j].mobile_number)
            goto nxt1;
        else
            printf("Wrong credentials!!!!!, Please try again\n");
            goto prvaccine_1;
        nxt1:
        printf("Please Select Vaccine\nSelect type\n");
        printf("1:Covishield\n2:Sputnik\n");
        scanf("%d",&choice);
        if(pd[j].different_vac==0){
            switch (choice){
                case 1:
                    pd[j].different_vac=1;
                    break;
                case 2:
                    pd[j].different_vac=2;
                    break;
                default:
                    printf("Please select the option 1 or 2\n");
                    break;
                }
        }
    }
    else{
        //check
        printf("User Authentication, enter Mobile Number\n");
        prvaccine_2:
        scanf("%d",&pno);
        if(pno==pd[j].mobile_number)
            goto nxt2;
        else
            printf("Wrong credentials!!!!!, Please try again\n");
            goto prvaccine_2;
        }nxt2:

    vaccine_check=check_vac(j);       //update of user till now

    if(vaccine_check==1)
        printf("Please take your first vaccine\nYou have been vaccinated for Dose 1\n");
    else if (vaccine_check==2)
        printf("Please take your second vaccine\nYou have been vaccinated for Dose 2\n");
    else if (vaccine_check==3)
        printf("Congratulations !!!\nYou have been vaccinated\n");
    
    // how many dose has been taken
    if(pd[j].different_vac==1 && (vaccine_check==1 || vaccine_check==2))
        vaccine_1++;
    else if(pd[j].different_vac==2 && (vaccine_check==1 || vaccine_check==2))
        vaccine_2++;
    
    attmpt--;
    
    }

    printf("\nList of users and dose taken by users\n");
    int i=1;
    while(i<=1000){
        if(pd[i].aadhar_card_num!=0){
            printf("P%d Aadhar Number:%li\n",i,pd[i].aadhar_card_num);
            printf("P%d Mobile number:%d\n",i,pd[i].mobile_number);
            printf("P%d Age:%d\n",i,pd[i].persone_age);
            printf("P%d Unique code:%d\n",i,pd[i].unique_code);
            printf("P%d Vaccine taken:%d\n",i,pd[i].different_vac);
            printf("P%d Vaccine type:%d\n",i,pd[i].vac_take);
        }
    i++;
    }
    printf("\nVaccine type 1(Covishield):%d\n",vaccine_1);
    printf("Vaccine type 2(Sputnik):%d\n",vaccine_2);
}