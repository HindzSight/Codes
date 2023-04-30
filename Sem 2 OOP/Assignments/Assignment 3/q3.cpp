#include<iostream>
#include<string.h>
using namespace std;
class Landline{
protected:
   string subscriber_name;
   long long int subscriber_number;
public:
   Landline();
   Landline(string,long long int);
   void call(long long int);
   void receive();
};
Landline::Landline(){
   subscriber_name="null";
   subscriber_number=1234567890;
}
Landline::Landline(string subscriber_name_in,long long int subscriber_number_in){
   subscriber_name=subscriber_name_in;
   subscriber_number=subscriber_number_in;
}
void Landline::call(long long int number_in){
   cout<<"Calling to number: "<<number_in<<" ..."<<endl;
}
void Landline::receive(){
   cout<<"Receiving call ...."<<endl;
}

class Mobile : public Landline{
protected:
   string subscriber_name;
   long long int subscriber_number;
   vector< pair<string,long long int> > Phonebook;
   long long int dailed_numbers[20];
   int dialed_count;
public:
   void call_by_name();
   long long int getNumberForName(string);
   void init_Phonebook(vector< pair<string,long long int> >);
   void update_dailed_numbers();
   void call_from_dailed_numbers();
   Mobile();
   Mobile(string,long long int);
};
Mobile::Mobile(){
   subscriber_name="MobileUserName";
   subscriber_number=1234567890;
   dialed_count=0;
}
Mobile::Mobile(string Mob_sub_name,long long int mob_sub_number){
   subscriber_name=Mob_sub_name;
   subscriber_number=mob_sub_number;
   dialed_count=0;
}
void Mobile::call_by_name(){
   cout<<"Printing PhoneBook contacts ...."<<endl;
for (int i=0; i<Phonebook.size(); i++)
{
// "first" and "second" are used to access
// 1st and 2nd element of pair respectively
cout << Phonebook[i].first << " "
<< Phonebook[i].second << endl;
}
string name_in;
cout<<"\nEnter Name from above list to call : ";
cin>>name_in;
long long int number_in=0;
for (int i=0; i<Phonebook.size(); i++)
{
if(Phonebook[i].first==name_in)
   number_in=Phonebook[i].second;
}
if(number_in!=0)
   Landline:call(number_in);
else
       cout<<"name is not there in phonebook !"<<endl;  
}
long long int Mobile::getNumberForName(string name_in){
   long long int num=0;
   return num;
}
void Mobile::init_Phonebook(vector< pair<string,long long int> > vec_in){
   Phonebook=vec_in;
}
void Mobile::update_dailed_numbers(){
  
}
void Mobile::call_from_dailed_numbers(){
   long long int number_new_in;
   int index_in;
   if(dailed_count==0){
       cout<<"there are no dailed numbers.."<<endl;
       cout<<"Enter number you want to call: ";
       cin>>number_new_in;
   }
   else{
       cout<<" list of Dailed numbers : "<<endl;
       int i=0;
       for(i=0;i<dailed_count;i++){
           cout<<i+1<<") "<<dailed_numbers[i]<<endl;
       }
       cout<<"Enter your choice : ";
       cin>>index_in;
       //Landline:call(dailed_numbers[index_in-1]);
       number_new_in=dailed_numbers[index_in-1];
   }
   Landline:call(number_new_in);
   if(dailed_count<20){
       dailed_numbers[dailed_count]=number_new_in;
       dailed_count++;
   }
   else if(dailed_count=20){
       dailed_numbers[0]=dailed_numbers[index_in-1];
   }
}
int main(){
   //creating a vector for storing names and numbers
   vector< pair<string,long long int> > Phonebook_vector;
// initialising 1st and 2nd element of
// pairs with array values
string names[] = {"name1","name2","name3","name4","name5","name6","name7","name8","name9","name10","name11","name12" ,"name13" ,"name14", "name15","name16", "name17","name18","name19","name20"};
long long int numbers[] = {9999999991,9999999992,9999999993,9999999994,9999999995, 9999999996,9999999997,9999999998,9999999999,9999999910,9999999911,9999999912,9999999913,9999999914,9999999915,9999999916,9999999917,9999999918,9999999919,9999999920};
  
//calculating number of elements;
   int n = sizeof(names)/sizeof(names[0]);
  
// Entering values in vector of pairs(inserting)
for (int i=0; i<n; i++)
Phonebook_vector.push_back( make_pair(names[i],numbers[i]) );
  
   Mobile MobileObject("IronMan",1234567890);
   MobileObject.init_Phonebook(Phonebook_vector);
  
   //calling call_by_name functionality which first displays phonebook and take a string name to be called then calling call function
   MobileObject.call_by_name();
  
   //calling call_from_dailed_numbers functionality
   MobileObject.call_from_dailed_numbers();
  
   //calling again to check dailed_numbers updated or not
   MobileObject.call_from_dailed_numbers();
  
   return 0;
}