#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int Welcome();

int Operation(int* psel){

	int selection,balance,deposit,withdraw,transfer,condition,pin;

    printf("Previous selection is : %d\n" , *psel);
 
    char acc[7];
	balance=10000;

    scanf("%d",&selection,Welcome(selection)); 
    FILE *outfile;
	do{
	 if(selection == 1){
	   outfile=fopen("data.txt","w");
	   printf("Your current balance is:%d\n",balance);
	   fprintf(outfile,"You checked your balance.%d",balance);
	   fclose(outfile);        
	      
	   printf("If you want to return or exit please select an operation from here:\n");
	   printf("8.RETURN      9.EXIT\n");
	   *psel = selection;

	   scanf("%d",&selection);
	
	   if(selection == 8) {       
		Operation(&selection);  
		}
	    else if(selection == 9) {
	     printf("Please take your card from shown place.");
	    }		
                   
		*psel = selection;
				 
	  }     
	  else if(selection==2){
	   printf("%d",&selection);
	
	   outfile=fopen("data.txt","w");	
       printf("Your Balance:%d\n",balance);
	   printf("Please Enter The Deposit Amount: ");
	   scanf("%d",&deposit);
	   balance=balance+deposit;
       printf("Your Current Balance:%d\n",balance);
	   fprintf(outfile,"You have just did the deposit operation.\n",deposit);
	                
	   printf("If you want to return or exit please select an operation from here:\n");
       printf("8.RETURN      9.EXIT\n");
	   *psel=selection;

        scanf("%d",&selection);
	    if(selection==8) {
	                            
	     Operation(&selection); 
		 fclose(outfile);  					  
	                              
	    }
	    else if(selection == 9) {
	     printf("Please take your card from shown place.");
	    }
	                        
	    *psel = selection;
	  }     
	  else if(selection==3){
     
	   outfile=fopen("data.txt","w");
	   printf("Your Balance:%d\n",balance);
	   printf("Please Enter the Withdrawing amount:");
	                     
	   scanf("%d",&withdraw);
	   if(balance<withdraw) {
		
         printf("You do not have %d amount of balance.\n",withdraw);
		
	    }	
	    else if(balance>withdraw){
	     balance -=withdraw;
	     printf("Your current balance:%d\n",balance);
	     fprintf(outfile,"You have just did the withdraw operation.%d\n",withdraw);
	     fclose(outfile);
	                             
	    }	
		
	    printf("If you want to return or exit please select an operation from here:\n");
	    printf("8.RETURN      9.EXIT\n");
	    *psel= selection;

		scanf("%d",&selection);
	    if(selection==8) {
	                    
	     Operation(&selection);
	              	 
        }
        else if(selection == 9) {
	     printf("Please take your card from shown place.");
	          }
            
              *psel = selection;
               
	  }          
	  else if(selection==4){
		 
       outfile=fopen("data.txt","w");
	   do{
	     printf("Your current balance is:%d\n",balance);
	     do{
	       printf("Please enter the transfer account number which is 6 digits:\n");
	       scanf("%s",acc);
	       if(strlen(acc) == 6){
	        condition=1;
	       }
	       else{
	        condition=0;
	        printf("Please enter the correct account number.");
	       }
		
	     }while(condition != 1);
	
	     printf("Please enter the transfer amount:");
         scanf("%d",&transfer);
	
	     if(transfer>balance) 
	     printf("You do not have sufficient balance.\nPlease do the operation again.");
	
	     else
	     printf("%d amount of money has been transfered.\n",transfer );
	         
        }while(transfer > balance);

	    balance -=transfer;
	    printf("Your current balance is=%d\n",balance);
	    fprintf(outfile,"You have just did the transfer operation.%d",transfer);
	    fclose(outfile);
	 
	    printf("If you want to return or exit please select an operation from here:\n");
	    printf("8.RETURN      9.EXIT\n");
	    *psel=selection;

	    scanf("%d",&selection);
	    if(selection == 8) {
		
	     Operation(&selection);
				
	    }
	    else if(selection == 9) {
	     	 
	     printf("Please take your card from shown place.");
	
	    }
	      
        *psel = selection;
             
	  }  
	  else if(selection==5){ 

	    char pin[5];
	    outfile=fopen("data.txt","w");
	    do{
	      printf("Please do not use your current pin number for your security.\nOtherwise, your current pin number will be accepted as a new pin number!\n");
	      printf("Please enter your new pin number which is 4 digits:");
	      scanf("%s",pin);
	      if(strlen(pin)==4){
	        condition==1;
	        printf("Your pin number has been changed.\n");
	        fprintf(outfile,"You have just changed your pin number.%d\n",pin);
	        fclose(outfile);
	                        
	        printf("If you want to return or exit please select an operation from here:\n");
	        printf("8.RETURN      9.EXIT\n");
	        *psel=selection;

	        scanf("%d",&selection);
	        if(selection == 8) {
                            
	          Operation(&selection);
	                        
	        }
	        else if(selection == 9) {

              printf("Please take your card from shown place.");
	        }   
	                              
	        *psel=selection;
                                 
	      }
	      else{
				
	        printf("Please enter the true amount of number. :\n");
	        condition=0;
	      }
        }while(condition != 1);

	  }        
	   
	  else if(selection == 6){
		
	    if(*psel == 1){
		  char st1[50];
		  outfile= fopen("data.txt","r");
		  fread(st1,1,50,outfile);
	      printf("%s\n",st1);
	      printf("If you want to return or exit please select an operation from here:\n");
	      printf("8.RETURN      9.EXIT\n");
	      *psel=selection;
          scanf("%d",&selection);
            
	      if(selection == 8) {
            Operation(&selection);
	                    
	      }
	      else if(selection == 9) {
	        printf("Please take your card from shown place.");
	      }
	      *psel=selection;
	       fclose(outfile);
        }
		else if(*psel == 2){
		  char st2[50];
	      outfile=fopen("data.txt","r");
	      fread(st2,1,39,outfile);
	      printf("%s\n",st2);
	                  
		  printf("If you want to return or exit please select an operation from here:\n");
	      printf("8.RETURN      9.EXIT\n");
	      *psel=selection;

		  scanf("%d",&selection);
	                  
		  if(selection == 8) {
            Operation(&selection);
	        fclose(outfile);
		  }
		  else if(selection == 9) {
	        printf("Please take your card from shown place.");
	      }
	      *psel=selection;
	    }
		else if(*psel == 3){
		  char st3[50];
	      outfile=fopen("data.txt","r");
	      fread(st3,1,50,outfile);
	      printf("%s\n",st3);
	      printf("If you want to return or exit please select an operation from here:\n");
	      printf("8.RETURN      9.EXIT\n");
	      *psel=selection;

		  scanf("%d",&selection);
	      if(selection == 8) {
                        
	        Operation(&selection);
	        fclose(outfile);
	      }
	      else if(selection == 9) {
	         		    
            printf("Please take your card from shown place.");
	      }
	                    
	      *psel=selection;            
						
		}	
		else if(*psel == 4){
		  char st4[50];
	      outfile=fopen("data.txt","r");
	      fread(st4,1,41,outfile);
	      printf("%s\n",st4);
	                  
	      printf("If you want to return or exit please select an operation from here:\n");
	      printf("8.RETURN      9.EXIT\n");
	      *psel=selection;

		  scanf("%d",&selection);
	      if(selection == 8) {
                      
	        Operation(&selection);
	        fclose(outfile);	
	      }
	      else if(selection == 9) {
	         		    
            printf("Please take your card from shown place.");
	      }
	                    
	      *psel=selection;
	                  	
		}
		else if(*psel == 5){
		  char st5[50];
	      outfile=fopen("data.txt","r");
	      fread(st5,1,41,outfile);
	      printf("%s\n",st5);
	                
	      printf("If you want to return or exit please select an operation from here:\n");
	      printf("8.RETURN      9.EXIT\n");
	      *psel=selection;

		  scanf("%d",&selection);
	      if(selection == 8) {
                        
	        Operation(&selection);
	        fclose(outfile);
	      }
	      else if(selection == 9) {
	         		    
            printf("Please take your card from shown place.");
	      } 
	                    
	      *psel=selection;
	                  
		}        
        else if(*psel==6) {
	      printf("You haven't done anything yet.\n");          
   		  printf("If you want to return or exit please select an operation from here:\n");
	      printf("8.RETURN      9.EXIT\n");
	      *psel=selection;
	      

		  scanf("%d",&selection);
				    
	      if(selection == 8) {
	                       
	        Operation(&selection);
	        fclose(outfile);
	      }
	      else if(selection == 9) {
	         		    
            printf("Please take your card from shown place.");
	      }
	                    
	      *psel=selection;
	                
	    }
		                     
	  }                
	  else if (selection==7){
	    printf("Your card has been returned.");
	    exit(1);
	    *psel=selection;
	  }  
	  *psel=selection;
     
	}while(selection!=9);
	        
      if(selection==9){
	
        printf("Please take your card from shown place.");
      }
       
      *psel=selection;


}
	
int Welcome() {
		
	printf("                   WELCOME SCREEN\n");
	printf("OPERATIONS\n");
	printf("1.Check Balance      5.Change Pin\n2.Cash Deposit      6.Check Statements\n3.Cash Withdraw      7.Card return\n4.Cash Transfer\n");
	printf("Select an operation:");
	

}

    int main(){
	
    int card,selection,balance,deposit,withdraw,transfer;
    FILE *infile;
    char acc[7];
	balance=10000;
	
	int* _selection = (int*) malloc(sizeof(int)) ; 
	
	
	char food1[20];
	char food2[20];
	char teacher1[20];
	char teacher2[20];	
	char season1[20];
	char season2[20];
	int comp_result,number;
   	
    //////////////////////////////////////////////////////////////////////////////////////////// SECURITY ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	printf("SECURITY SCREEN\n");
	printf("Some questions will be asked to you in order to protect your information if anything happens.\n In order to see the questions please enter 10:");
	scanf("%d",&number);
	if(number == 10){
		
			printf("Please answer the questions with one word. Otherwise, your first word will be taken and accepted!\n");
			printf("If you do not comply with the warning, the actions you will take after this operation will not work properly.\n");
			printf("1.What is your favorite food?\n 2.What is your favorite teacher name?\n 3.What is your favorite season?\n");
			printf("Please select a question:");
			scanf("%d", &selection);
			if(selection == 1){
				printf("What is your favorite food?:\n");
				scanf("%s",food1);
				printf("Your favorite food is:%s",food1);
	    	}
	    	else if(selection == 2) {
				printf("What is your favorite teacher name?:\n");
				scanf("%s",teacher1);
				printf("Your favorite teacher name is:%s",teacher1);
			}
			else if(selection == 3){
				printf("What is your favorite teacher name?:\n");
				scanf("%s",season1);
				printf("Your favorite teacher name is:%s",season1);
			}

			
			}
			
			
	else if(number != 10){
		printf("Invalid operation.");
		exit(1);
	}

	////////////////////////////////////////////////////////////////////////////////// ACCOUNT NUMBER /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    int trialCounter=0;
	int condition = 0;
	char input[12];
	int wrongEnt = 0;
	
	printf("                   LOGIN SCREEN\n");
	
	do{
		if(wrongEnt == 0){
			printf("Please enter your card number/Account number which is 11 digits: %d\n",trialCounter);
   			scanf("%s",input);
   			trialCounter++;
   			
   			if(strlen(input)==11){
				condition=1;
			}
   			else{
   				wrongEnt = 1;
   				printf("Wrong entrance...%d Please re-enter your card number/Account number:\n",trialCounter);
   				condition = 0;
			}
   		}
   		else{
   			if(trialCounter < 3){
   				scanf("%s",input);
   				trialCounter++;
   				if(strlen(input)==11){
   					wrongEnt = 0;
					condition=1;
				}
   				else{
   					wrongEnt = 1;
   					printf("Wrong entrance...%d Please re-enter your card number/Account number:\n", trialCounter);
   				}
			}
			else{
				condition = 1;
			}
   		}
	  			
    }while(condition != 1);
    
    if((wrongEnt == 1) && (trialCounter >= 3)){
				printf("You entered wrong for 3 times. So we have to ask a question whether it's you or not?\n");
			
			if(selection == 1){
					printf("Please enter your favorite food:");
                    scanf("%s",food2);
                    comp_result = strcmp(food1, food2);
                    if (comp_result > 0){
                    	printf("(%s) > (%s)\n", food1, food2);
                        printf("You entered false.\n");
                        printf("We will end the operations to protect this customer's information.\n");
                        exit(1);
					}
					
                    
                    else if (comp_result < 0){
                    	printf("(%s) < (%s)\n", food1, food2);
                        printf("You entered false.\n");
                        printf("We will end the operations to protect this customer's information.\n");
                        exit(1);
					}
                    
                    else{
                    	printf("(%s) == (%s)\n", food1, food2);
                        printf("You entered true.\n");
                        
					}
                    
				}
				
			
			else if(selection == 2){
					printf("Please enter your favorite teacher name:");
                    scanf("%s",teacher2);
                    comp_result = strcmp(teacher1, teacher2);
                    if (comp_result > 0){
                    	printf("(%s) > (%s)\n", teacher1, teacher2);
                        printf("You entered false.\n");
                        printf("We will end the operations in order to protect this customer's information.\n");
                        exit(1);
					}
                    
                    else if (comp_result < 0){
                    	printf("(%s) < (%s)\n", teacher1, teacher2);
                        printf("You entered false.\n");
                        printf("We will end the operations to protect this customer's information.\n");
                        exit(1);
                        
					}
                    
                    else{
                    	printf("(%s) == (%s)\n", teacher1, teacher2);
                        printf("You entered true.\n");
					}
					
					}
						else if(selection == 3){
						printf("Please enter your favorite teacher name:");
                        scanf("%s",season2);
                        comp_result = strcmp(season1, season2);
                        if (comp_result > 0){
                    	printf("(%s) > (%s)\n", season1, season2);
                        printf("You entered false.\n");
                        printf("We will end the operations to protect this customer's information.\n");
                        exit(1);
                        
					   }
                    
                        else if (comp_result < 0){
                    	printf("(%s) < (%s)\n", season1, season2);
                        printf("You entered false.\n");
                        printf("We will end the operations to protect this customer's information.\n");
                        exit(1);
                        
    
					   }
                    
                    else{
                    	printf("(%s) == (%s)\n", season1, season2);
                        printf("You entered true.\n");
					}
                    
					
				}
	
	
	}
	
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
	
	
 /////////////////////////////////////////////////////////////////////////////////// PIN NUMBER ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	trialCounter=0;
	condition = 0;
	wrongEnt = 0;
	char pin[5];
	do{
			if(wrongEnt == 0){
			    printf("Please enter your pin number which is 4 digits: %d\n",trialCounter);

   			scanf("%s",pin);
   			trialCounter++;
   			
   			if(strlen(pin)==4){
				condition=1;
			}
   			else{
   				wrongEnt = 1;
   				printf("Wrong entrance...%d Please re-enter your pin number:\n",trialCounter);
   				condition = 0;
			}
   		}
   		else{
   			if(trialCounter < 3){
   				scanf("%s",pin);
   				trialCounter++;
   				if(strlen(pin)==4){
   					wrongEnt = 0;
					condition=1;
				}
   				else{
   					wrongEnt = 1;
   					printf("Wrong entrance...%d Please re-enter your pin number:\n", trialCounter);
   				}
			}
			else{
				condition = 1;
			}
   		}
	  			
    }while(condition != 1);
    
    if((wrongEnt == 1) && (trialCounter >= 3)){
				printf("You entered wrong for 3 times. So we have to ask a question whether it's you or not?\n");
			
			if(selection == 1){
					printf("Please enter your favorite food:");
                    scanf("%s",food2);
                    comp_result = strcmp(food1, food2);
                    if (comp_result > 0){
                    	printf("(%s) > (%s)\n", food1, food2);
                        printf("You entered false.\n");
                        printf("We will end the operations to protect this customer's information.\n");
                        exit(1);
					}
					
                    
                    else if (comp_result < 0){
                    	printf("(%s) < (%s)\n", food1, food2);
                        printf("You entered false.\n");
                        printf("We will end the operations to protect this customer's information.\n");
                        exit(1);
					}
                    
                    else{
                    	printf("(%s) == (%s)\n", food1, food2);
                        printf("You entered true.\n");
                        
					}
                    
				}
				
			
			else if(selection == 2){
					printf("Please enter your favorite teacher name:");
                    scanf("%s",teacher2);
                    comp_result = strcmp(teacher1, teacher2);
                    if (comp_result > 0){
                    	printf("(%s) > (%s)\n", teacher1, teacher2);
                        printf("You entered false.\n");
                        printf("We will end the operations in order to protect this customer's information.\n");
                        exit(1);
					}
                    
                    else if (comp_result < 0){
                    	printf("(%s) < (%s)\n", teacher1, teacher2);
                        printf("You entered false.\n");
                        printf("We will end the operations to protect this customer's information.\n");
                        exit(1);
                        
					}
                    
                    else{
                    	printf("(%s) == (%s)\n", teacher1, teacher2);
                        printf("You entered true.\n");
					}
					
					}
						else if(selection == 3){
						printf("Please enter your favorite teacher name:");
                        scanf("%s",season2);
                        comp_result = strcmp(season1, season2);
                        if (comp_result > 0){
                    	printf("(%s) > (%s)\n", season1, season2);
                        printf("You entered false.\n");
                        printf("We will end the operations to protect this customer's information.\n");
                        exit(1);
                        
					   }
                    
                        else if (comp_result < 0){
                    	printf("(%s) < (%s)\n", season1, season2);
                        printf("You entered false.\n");
                        printf("We will end the operations to protect this customer's information.\n");
                        exit(1);
                        
    
					   }
                    
                    else{
                    	printf("(%s) == (%s)\n", season1, season2);
                        printf("You entered true.\n");
					}
                    
					
				}
	
	
	}
	
	scanf("%d",&selection,Welcome(selection));     
///////////////////////////////////////////////////////////////////////////////////////////// OPERATIONS ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
switch(selection) {
		



	
	FILE *outfile;
	
	case 1:
		
	 outfile=fopen("data.txt","w");
	 printf("Your current balance is:%d\n",balance);
	 fprintf(outfile,"You checked your balance.%d",balance);
	 fclose(outfile);
	      
	 printf("If you want to return or exit please select an operation from here:\n");
	 printf("8.RETURN      9.EXIT\n");
	        
	 *_selection = selection;
	 scanf("%d",&selection);
	
	 if(selection == 8) {
	     	
	   Operation(_selection);  
	       
      }	
	  else if(selection == 9) {
	    printf("Please take your card from shown place.");
	                
	  }
	      
	  *_selection = selection;
          
	break;

	case 2:
	
	 outfile=fopen("data.txt","w");
     printf("Your Balance:%d\n",balance);
	 printf("Please Enter The Deposit Amount: ");
	 scanf("%d",&deposit);
	 balance = balance + deposit;
	 printf("Your Current Balance:%d\n",balance);
	 fprintf(outfile,"You have just did the deposit operation.\n",deposit);
	 fclose(outfile);
			  

	 printf("If you want to return or exit please select an operation from here:\n");
	 printf("8.RETURN      9.EXIT\n");
	 *_selection = selection;

	 scanf("%d",&selection);
	 if(selection == 8) {
	  Operation(_selection);  
	                   
	  }
	  else if(selection == 9) {
	   printf("Please take your card from shown place.");
	          
	  }
	         
	  *_selection = selection;
	break;
	
	
	case 3:
	
	 outfile=fopen("data.txt","w");
	
	 printf("Your Balance:%d\n",balance);
	 printf("Please Enter the Withdrawing amount:");
	      
	 scanf("%d",&withdraw);
	 if(balance < withdraw) {
			
      printf("You do not have %d amount of balance.\n",withdraw);
	 }	      
	 else if(balance > withdraw){
	   balance -=withdraw;		
	   printf("Your current balance:%d\n",balance);
	   fprintf(outfile,"You have just did the withdraw operation.%d",withdraw);
	   fclose(outfile);
	 }	
			
	 printf("If you want to return or exit please select an operation from here:\n");
     printf("8.RETURN      9.EXIT\n");
	 *_selection = selection;

	 scanf("%d",&selection);
	 if(selection == 8) {
	   Operation(_selection);   
	 }   
	 else if(selection == 9) {
	   printf("Please take your card from shown place.");
	               
	 }
	      
	 *_selection = selection;
		      
		      
	break;

	case 4:
    
    outfile=fopen("data.txt","w");
   
	 do{
	   printf("Your current balance is:%d\n",balance);
	   do{
	     printf("Please enter the transfer account number which is 6 digits:\n");
	     scanf("%s",acc);
	     if(strlen(acc) == 6){
	        condition=1;
	     }
	     else{
	        condition=0;
	        printf("Please enter the correct account number.");
	      }
		
	    }while(condition != 1);
	
	    printf("Please enter the transfer amount:");
        scanf("%d",&transfer);
	
	    if(transfer>balance){
	                	
	      printf("You do not have sufficient balance.\nPlease do the operation again.");
		} 
	    else{
	      printf("%d amount of money has been transfered.\n",transfer );
		}
	                    
	         
      }while(transfer > balance);

	  balance -=transfer;
	  printf("Your current balance is=%d\n",balance);
	  fprintf(outfile,"You have just did the transfer operation.");
	  fclose(outfile);
	                
	  printf("If you want to return or exit please select an operation from here:\n");
      printf("8.RETURN      9.EXIT\n");
                	
      *_selection = selection;
	  scanf("%d",&selection);
	  if(selection == 8) {
			
	    Operation(_selection);  
				
	 }     
	 else if(selection == 9) {
	     	
	   printf("Please take your card from shown place.");
	                     
	 }
	                  
	 *_selection = selection;
	                 
   			    
    break;
	
	
	char pin[5];
	case 5:
		
	 outfile=fopen("data.txt","w");
	
	  do{
	    printf("Please do not use your current pin number for your security.\nOtherwise, your current pin number will be accepted as a new pin number!\n");
	    printf("Please enter your new pin number which is 4 digits:");
	    scanf("%s",pin);
	    if(strlen(pin)==4){
	      condition==1;
	      printf("Your pin number has been changed.\n");
	      fprintf(outfile,"You have just changed your pin number.");
	      fclose(outfile);
	                       
	      printf("If you want to return or exit please select an operation from here:\n");
	      printf("8.RETURN      9.EXIT\n");
		  *_selection = selection;

          scanf("%d",&selection);
	      if(selection == 8) {
	        Operation(_selection);  
					
	       }
	       else if(selection == 9) {
	          printf("Please take your card from shown place.");
	        }
	        *_selection = selection;
	      
	    }      
	    else{
	                        
	      printf("Please enter the true amount of number. :\n");
	      condition=0;
	    }
      }while(condition != 1);
                
	break;
	
	
	
	case 6: 
		
     if(*_selection == 1){
			
	  char st1[50];
	  outfile= fopen("data.txt","r");
	  fread(st1,1,50,outfile);
	  printf("%s\n",st1);
			         
	  printf("If you want to return or exit please select an operation from here:\n");
      printf("8.RETURN      9.EXIT\n");
                	
      *_selection = selection;
	  scanf("%d",&selection);
	  if(selection == 8) {
			
	    Operation(_selection);   
	                      
	   }     	
	   else if(selection == 9) {
	    
	    printf("Please take your card from shown place.");
	            
	    }
	                  
	    *_selection = selection;
	    fclose(outfile);
	                 
	  } 
	             
	  else if(*_selection == 2){
		char st2[50];
	    outfile=fopen("data.txt","r");
	    fread(st2,1,39,outfile);
	    printf("%s\n",st2);
	                  
	    printf("If you want to return or exit please select an operation from here:\n");
        printf("8.RETURN      9.EXIT\n");
               	
        *_selection = selection;
	    scanf("%d",&selection);
	    if(selection == 8) {
			
	      Operation(_selection);   
	      fclose(outfile);
				
	    }     
	    else if(selection == 9) {
	     	
	      printf("Please take your card from shown place.");
	                     
	    }
	                  
	    *_selection = selection;
		            	
	   }  
	      
	   else if(*_selection == 3){
		 char st3[50];
	     outfile=fopen("data.txt","r");
	     fread(st3,1,50,outfile);
	     printf("%s\n",st3);
	                
	     printf("If you want to return or exit please select an operation from here:\n");
         printf("8.RETURN      9.EXIT\n");
                	
         *_selection = selection;
	     scanf("%d",&selection);
	     if(selection == 8) {
			
	       Operation(_selection);  
	       fclose(outfile);
				
	      }     
	      else if(selection == 9) {
	     	
	         printf("Please take your card from shown place.");
	                     
	       }
	                  
	       *_selection = selection;
						
		}
		
		else if(*_selection == 4){
		  char st4[50];
	      outfile=fopen("data.txt","r");
	      fread(st4,1,41,outfile);
	      printf("%s\n",st4);
	                  
	      printf("If you want to return or exit please select an operation from here:\n");
          printf("8.RETURN      9.EXIT\n");
                	
          *_selection = selection;
	      scanf("%d",&selection);
	      if(selection == 8) {
			
	        Operation(_selection);  
	        fclose(outfile);
				
	      }     
	      else if(selection == 9) {
	     	
	        printf("Please take your card from shown place.");
	                     
	      }
	                  
	      *_selection = selection;
	
						
		} 
		 
		else if(*_selection == 5){
		  char st5[50];
	      outfile=fopen("data.txt","r");
	      fread(st5,1,41,outfile);
	      printf("%s\n",st5);
	                  
	      printf("If you want to return or exit please select an operation from here:\n");
          printf("8.RETURN      9.EXIT\n");
                	
          *_selection = selection;
	      scanf("%d",&selection);
	      if(selection == 8) {
			
	        scanf("%d",&selection,Operation(selection)); 
	        fclose(outfile);
			
	        }     
	        else if(selection == 9) {
	     	
	          printf("Please take your card from shown place.");
	                     
	        }
	                  
	        *_selection = selection;
			
		}
		  
        else if(*_selection==6) {
        
	      printf("You haven't done anything yet.\n");
	                   
   		  printf("If you want to return or exit please select an operation from here:\n");
          printf("8.RETURN      9.EXIT\n");
                	
          *_selection = selection;
	      scanf("%d",&selection);
	      if(selection == 8) {
			
	        Operation(_selection);  
	                
	       }     
	       else if(selection == 9) {
	     	
	          printf("Please take your card from shown place.");
	                     
	        }
	                  
	        *_selection = selection;
   					   

	    }    	
					
    
			
	break;
	
	case 7:
		
	   printf("Your card has been returned.");
			
	break;
	
	
  }

    return 0;
    
	}
