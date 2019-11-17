#include "HeadBackend.hpp"
#include "HeadFrontend.hpp"

void printClosestCab(std::vector<coordinates> dcc,const coordinates myLocation){
	std::cout << "\nThe 5 Closest Cabs" <<"\n";
	for(int i=0;i<5;i++){
		std::cout<<i+1<<". "<<myLocation.distance(dcc[i])<<" Km away at "<<dcc[i].get_address()<<".    ( "<< dcc[i].get_latitude()<<" , "<< dcc[i].get_longitude()<<" )\n";
	}
}

void printClosestAuto(std::vector<coordinates> dcc,const coordinates myLocation){
	std::cout << "\nThe 5 Closest Autos" <<"\n";
	for(int i=0;i<5;i++){
		std::cout<<i+1<<". "<<myLocation.distance(dcc[i])<<" Km away at "<<dcc[i].get_address()<<".    ( "<< dcc[i].get_latitude()<<" , "<< dcc[i].get_longitude()<<" )\n";
	}
}


void cabBooked(int i,std::vector<coordinates> dcc,const coordinates myLocation){
	system("clear");
	std::cout <<"Your Cab is Booked"<<"\n";
	std::cout <<"It will arrive in "<<(int)((myLocation.distance(dcc[i-1])/45)*60)<<" mins.";
	std::cout <<"\n______________________________________________________________________________________________________________________\n";	
	std::cout <<"\nBase Fare                    $2";
	std::cout <<"\nFare per Km                  $0.5";
	std::cout <<"\n______________________________________________________________________________________________________________________\n";	
	std::cout <<"\n"<<"Thank You For Booking a Cab With Us!!"<<"\n\n";
	std::cout <<"Press Enter to exit.....";
	std::cin.get();	
	if (std::cin.get() == '\n')
		exit(0);
}

void autoBooked(int i,std::vector<coordinates> dcc,const coordinates myLocation){
	system("clear");
	std::cout <<"Your Auto is Booked"<<"\n";
	std::cout <<"It will arrive in "<<(int)((myLocation.distance(dcc[i-1])/30)*60)<<" mins.";
	std::cout <<"\n______________________________________________________________________________________________________________________\n";
	std::cout <<"\nBase Fare                    $1";
	std::cout <<"\nFare per Km                  $0.25";	
	std::cout <<"\n______________________________________________________________________________________________________________________\n";
	std::cout <<"\n"<<"Thank You For Booking a Auto With Us!!"<<"\n\n";
	std::cout <<"Press Enter to exit.....";
	std::cin.get();
	if (std::cin.get() == '\n')
		exit(0);
}




void start(std::vector<coordinates> dcc, coordinates myLocation){
 	int ch;
 	do{
	std::cout <<"######################################################################################################################";
	std::cout << "\n";
	std::cout << "\t" <<"   				Cab Booking System   ";
	std::cout << "\n" <<"######################################################################################################################";
	std::cout << "\n\n";
	std::cout << "My Location :-"; myLocation.print_coordinates();
	std::cout <<"______________________________________________________________________________________________________________________\n";
	


	std::cout << "\n" <<"Enter >1< Book a Cab";
 	std::cout << "\n" <<"Enter >2< Book a Auto";
 	std::cout << "\n" <<"Enter >0< To Exit ";

 	std::cout << "\n" <<"Enter your Choice :-";
	std::cin >> ch;
	system("clear");

  	switch (ch){

		case 1:
				int h;
			do{
	std::cout <<"######################################################################################################################";
	std::cout << "\n";
	std::cout << "\t" <<"   				Cab Booking System   ";
	std::cout << "\n" <<"######################################################################################################################";
	std::cout << "\n\n";
	std::cout << "My Location :-"; myLocation.print_coordinates();
	std::cout <<"______________________________________________________________________________________________________________________\n";


				printClosestCab(dcc,myLocation);
							
				std::cout << "\n" <<"Enter The Cab Number To Book";
				std::cout << "\n" <<"Enter >0< To Main Page ";
				std::cout << "\n" <<"Enter your Choice :-";
				std::cin >> h;
				system("clear");
				switch (h){

					case 1:
						cabBooked(1,dcc,myLocation);
					break;

					case 2:
						cabBooked(2,dcc,myLocation);
					break;

					case 3:
						cabBooked(3,dcc,myLocation);
					break;

					case 4:
						cabBooked(4,dcc,myLocation);
					break;

					case 5:
						cabBooked(5,dcc,myLocation);
					break;
					
					case 0:
					break;
				}
			}while(h!=0);
		break;

		case 2:
			int r;
			do{
	std::cout <<"######################################################################################################################";
	std::cout << "\n";
	std::cout << "\t" <<"   				Cab Booking System   ";
	std::cout << "\n" <<"######################################################################################################################";
	std::cout << "\n\n";
	std::cout << "My Location :-"; myLocation.print_coordinates();
	std::cout <<"______________________________________________________________________________________________________________________\n";

				printClosestAuto(dcc,myLocation);
							
				std::cout << "\n" <<"Enter The Auto Number To Book";
				std::cout << "\n" <<"Enter >0< To Main Page ";
				std::cout << "\n" <<"Enter your Choice :-";
				std::cin >> r;
				system("clear");
				switch (r){

					case 1:
						autoBooked(1,dcc,myLocation);
					break;

					case 2:
						autoBooked(2,dcc,myLocation);
					break;

					case 3:
						autoBooked(3,dcc,myLocation);
					break;

					case 4:
						autoBooked(4,dcc,myLocation);
					break;

					case 5:
						autoBooked(5,dcc,myLocation);
					break;
					
					case 0:
					break;
				}
			}while(r!=0);
			

    		break;

		case 0:
    		exit(0);
    		break;

    		default:
		std::cout <<"Wrong choice !";
    		break;
   	}
	}while(ch!=0);
}
