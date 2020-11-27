#ifndef ENCRYPTION_HELPER_H
#define ENCRYPTION_HELPER_H
#include <iostream>
#include <string>
using namespace std;
class EncryptionHelper{
	
	public:
		string encrypt(string password){
			//encryption
			for(int i=0;i<password.size();i++){
				password[i]+=2;
			}
			return password;
		}
		
		string decrypt(string encryptedPassword){
			//decryption
			
			for(int i=0;i<encryptedPassword.size();i++){
				
			    encryptedPassword[i]-=2;
			    
			}
			
			return encryptedPassword;
		}
};

#endif
