
#include <iostream>
#include <fstream>
#include <iterator>
#include <cstdio>
#include <ctime>
using namespace std; 

int insertioncounter=0;
int deletioncounter=0;
int retrievalcounter=0;
int sizeofentries=0;
int arraysize=1000;


struct Person{
    string name;
    string SSN;
};


int Lookup(string lookupSSN, Person * &personlist){
	
  int location=-1;

  int x=0;
    
  while (x<sizeofentries){ 
    if(lookupSSN.compare(personlist[x].SSN) == 0){

      location = x;
      return location; 

    }
        
    x++;
        
}

return location; 



}



void insertion(string SocialSecurity, string firstName, string lastName, Person * &personlist){

int nlocation= Lookup(SocialSecurity,personlist);


if(nlocation <0){

  if(sizeofentries >= arraysize)    {
    arraysize=2*arraysize;
    Person *NewPersonList= new Person[arraysize];	

    for(int i=0; i<sizeofentries; i++) {

      NewPersonList[i]=personlist[i]; 
    }
   

    delete [] personlist;

    personlist=NewPersonList;


  }

  string completename= firstName+ " "+ lastName;
  personlist[sizeofentries]. SSN= SocialSecurity;   
  personlist[sizeofentries]. name= completename;
  sizeofentries++;
  insertioncounter++;
}

else{
 // cout << "In insertion. Element already exists"<< endl;

}

}


void deletion(string SocialSecurity, Person * &personlist){

  int nlocation= Lookup(SocialSecurity,personlist);


  if(nlocation >= 0){

    for(int i= nlocation; i< sizeofentries; i++)
    {
        personlist[i]= personlist[i+1];
      
    }


    sizeofentries--;
    deletioncounter++;


    if(sizeofentries <  arraysize/4)    {
      
      arraysize=arraysize/2;

      Person *NewPersonList= new Person[arraysize];  

      for(int i=0; i<sizeofentries; i++) {

        NewPersonList[i]=personlist[i]; 
      }
   

      delete [] personlist;

      personlist=NewPersonList;

  }
  
}

else{
   // cout << " In Deletion. Element doesn't  exists"<< endl;

  }
}

void retrieval(string SocialSecurity, Person * &personlist){
 //cout << "Entering retrieval method.." << endl;
  int nlocation= Lookup(SocialSecurity,personlist);

  //cout << "location:"<< nlocation << endl;

  if(nlocation >= 0){
    retrievalcounter++;
   //cout << "Location in retrieval" << nlocation<< endl;
  }
  else{
    //cout << "In Retrieval. Element doesn't exist!" << endl;


  }
}






int main(int argc, char *argv[]){
     
 
clock_t start, end;
  double duration;

  start = clock();




  char op; 
  string inputSSN; 
  string InputFirstName, InputLastName; 
  string lSSN; 
   

  ifstream input(argv[1]);

  Person *personlist= new Person[arraysize];
  
 
    
  while(!input.eof()){
 
      
    input >> op >> inputSSN >> InputFirstName >> InputLastName;
    
 
       
    switch(op){

      case 'i' :

  

       	insertion(inputSSN, InputFirstName, InputLastName, personlist);
       			
       
       	break;

      case 'd' :

       	deletion(inputSSN,personlist);

       	break;

      case 'r' :

       	retrieval(inputSSN, personlist);

       	break;

       	default: 
       	 cout << "Operation not found!" << endl;
      }

   }

   cout << " Number of valid insertions " << insertioncounter << endl;
   cout << " Number of valid deletions " << deletioncounter << endl;
   cout << " Number of valid retrievals " << retrievalcounter << endl;
   cout << "Size of Entries "<< sizeofentries << endl;
   cout << "Array Size:" << arraysize << endl;
    
  end = clock();
  duration = ( end - start ) / (double) CLOCKS_PER_SEC;

  cout<<"elapsed time: "<< duration <<'\n';


    input.close();
 

  return 0;
}