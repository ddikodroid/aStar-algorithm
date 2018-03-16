#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;



// Structure containing minimum Child Expansion Information

struct	Neighbor{
	string	Name;
	int	Distance;
};

//Node containing necessary information for A* search

class City{
public:

	vector<Neighbor>::iterator	NeighborNumber;
	vector<Neighbor>		Neighbors;

	string				Name;
	string				AccumulatedPath;
	int				AccumulatedDistance;
	int				StraightLineDistance;

	City();
	City(string, int);

	void	AddNeighbor	(string, int);
};

//Constructor for Non-Initialized City

City::City(){
	Name="";
	NeighborNumber=Neighbors.begin();
	AccumulatedPath="";
	AccumulatedDistance=0;
	StraightLineDistance=0;
}


//Constructor for Initialized City

City::City(string name, int sld){
	Name=name;
	NeighborNumber=Neighbors.begin();
	AccumulatedPath=name;
	AccumulatedDistance=0;
	StraightLineDistance=sld;
}

//Add Neighbor Method - requires Name of Neighbor and distance to City

void	City::AddNeighbor(string name, int distance){
	Neighbor	TempNeighbor;

	TempNeighbor.Name		= name;
	TempNeighbor.Distance	= distance;
	Neighbors.push_back(TempNeighbor);
	NeighborNumber=Neighbors.begin();
}

vector<City>	Cities;
vector<City>	Frontier;

//Function used to enter Romanian Map manually

void MakeMap(){
    City	TempCity;
//Enter data for Arad

    TempCity.Name="Arad";
    TempCity.StraightLineDistance=366;
    TempCity.Neighbors.clear();

    TempCity.AddNeighbor("Zerind",75);
    TempCity.AddNeighbor("Sibiu", 140);
    TempCity.AddNeighbor("Timisoara",118);
    Cities.push_back(TempCity);

//Enter data for Bucharest

    TempCity.Name="Bucharest";
    TempCity.StraightLineDistance=0;
    TempCity.Neighbors.clear();
    TempCity.AddNeighbor("Giurgiu",90);
    TempCity.AddNeighbor("Urziceni",85);
    TempCity.AddNeighbor("Fagaras",211);
    TempCity.AddNeighbor("Pitesti",101);
    Cities.push_back(TempCity);


//Enter data for Craiova

    TempCity.Name="Craiova";
    TempCity.StraightLineDistance=160;
    TempCity.Neighbors.clear();
    TempCity.AddNeighbor("Pitesti",138);
    TempCity.AddNeighbor("Rimnicu Vilcea",97);
    TempCity.AddNeighbor("Drobeta",120);
    Cities.push_back(TempCity);

//Enter data for Drobeta

    TempCity.Name="Drobeta";
    TempCity.StraightLineDistance=242;
    TempCity.Neighbors.clear();
    TempCity.AddNeighbor("Craiova",120);
    TempCity.AddNeighbor("Mehadia",75);
    Cities.push_back(TempCity);

//Enter data for Eforie

    TempCity.Name="Eforie";
    TempCity.StraightLineDistance=161;
    TempCity.Neighbors.clear();
    TempCity.AddNeighbor("Hirsova",86);
    Cities.push_back(TempCity);

//Enter data for Fagaras

    TempCity.Name="Fagaras";
    TempCity.StraightLineDistance=176;
    TempCity.Neighbors.clear();
    TempCity.AddNeighbor("Bucharest",211);
    TempCity.AddNeighbor("Sibiu",99);
    Cities.push_back(TempCity);

//Enter data for Giurgiu

    TempCity.Name="Giurgiu";
    TempCity.StraightLineDistance=77;
    TempCity.Neighbors.clear();
    TempCity.AddNeighbor("Bucharest",90);
    Cities.push_back(TempCity);

//Enter data for Hirsova

    TempCity.Name="Hirsova";
    TempCity.StraightLineDistance=151;
    TempCity.Neighbors.clear();
    TempCity.AddNeighbor("Eforie",86);
    TempCity.AddNeighbor("Uriceni",98);
    Cities.push_back(TempCity);

//Enter data for Iasi

    TempCity.Name="Iasi";
    TempCity.StraightLineDistance=226;
    TempCity.Neighbors.clear();
    TempCity.AddNeighbor("Valsui",92);
    TempCity.AddNeighbor("Neamt",87);
    Cities.push_back(TempCity);

//Enter data for Lugoj

    TempCity.Name="Lugoj";
    TempCity.StraightLineDistance=244;
    TempCity.Neighbors.clear();
    TempCity.AddNeighbor("Mehadia",70);
    TempCity.AddNeighbor("Timisoara",111);
    Cities.push_back(TempCity);

//Enter data for Mehadia

    TempCity.Name="Mehadia";
    TempCity.StraightLineDistance=241;
    TempCity.Neighbors.clear();
    TempCity.AddNeighbor("Drobeta",75);
    TempCity.AddNeighbor("Lugoj",70);
    Cities.push_back(TempCity);

//Enter data for Neamt

    TempCity.Name="Neamt";
    TempCity.StraightLineDistance=234;
    TempCity.Neighbors.clear();
    TempCity.AddNeighbor("Iasi",87);
    Cities.push_back(TempCity);

//Enter data for Oradea

    TempCity.Name="Oradea";
    TempCity.StraightLineDistance=380;
    TempCity.Neighbors.clear();
    TempCity.AddNeighbor("Zerind",71);
    TempCity.AddNeighbor("Sibiu",151);
    Cities.push_back(TempCity);

//Enter data for Pitesti

    TempCity.Name="Pitesti";
    TempCity.StraightLineDistance=100;
    TempCity.Neighbors.clear();
    TempCity.AddNeighbor("Bucharest",101);
    TempCity.AddNeighbor("Rimnicu Vilcea",97);
    TempCity.AddNeighbor("Craiova",138);
    Cities.push_back(TempCity);

//Enter data for Rimnicu Vilcea

    TempCity.Name="Rimnicu Vilcea";
    TempCity.StraightLineDistance=193;
    TempCity.Neighbors.clear();
    TempCity.AddNeighbor("Pitesti",97);
    TempCity.AddNeighbor("Sibiu",80);
    TempCity.AddNeighbor("Craiova",146);
    Cities.push_back(TempCity);

//Enter data for Sibiu

    TempCity.Name="Sibiu";
    TempCity.StraightLineDistance=253;
    TempCity.Neighbors.clear();

    TempCity.AddNeighbor("Rimnicu Vilcea",80);
    TempCity.AddNeighbor("Fagaras",99);
    TempCity.AddNeighbor("Oradea",151);
    TempCity.AddNeighbor("Arad",140);
    Cities.push_back(TempCity);

//Enter data for Timsoara

    TempCity.Name="Timisoara";
    TempCity.StraightLineDistance=329;
    TempCity.Neighbors.clear();
    TempCity.AddNeighbor("Lugoj",70);
    TempCity.AddNeighbor("Arad",118);
    Cities.push_back(TempCity);

//Enter data for Urziceni

    TempCity.Name="Urziceni";
    TempCity.StraightLineDistance=80;
    TempCity.Neighbors.clear();
    TempCity.AddNeighbor("Hirsova",98);
    TempCity.AddNeighbor("Bucharest",85);
    Cities.push_back(TempCity);

//Enter data for Valusi

    TempCity.Name="Valsui";
    TempCity.StraightLineDistance=199;
    TempCity.Neighbors.clear();
    TempCity.AddNeighbor("Iasi",92);
    TempCity.AddNeighbor("Urziceni",142);
    Cities.push_back(TempCity);

//Enter data for Zerind

    TempCity.Name="Zerind";
    TempCity.StraightLineDistance=374;
    TempCity.Neighbors.clear();
    TempCity.AddNeighbor("Oradea",71);
    TempCity.AddNeighbor("Arad",75);
    Cities.push_back(TempCity);
}
bool	GetChildCity (Neighbor Parent, City* ChildCity){
    vector<City>::iterator	CityNumber;

    for(CityNumber=Cities.begin();CityNumber<Cities.end();CityNumber++){
        *ChildCity=*CityNumber;
        if(ChildCity->Name == Parent.Name)
            return true;
    }
    return false;
}

//C++ Minimum Priority Queue Equivalent - Based on Distance to Goal

City	FindShortestPath(int *LowestPathDistance){
    vector<City>::iterator	FrontierNumber;
    vector<City>::iterator	LowestNodeNumber;

    City	CurrentCity;

    FrontierNumber=Frontier.begin();
    CurrentCity=*FrontierNumber;
    *LowestPathDistance=CurrentCity.AccumulatedDistance +
                        CurrentCity.StraightLineDistance;
    LowestNodeNumber=FrontierNumber;
    FrontierNumber++;

    while(FrontierNumber<Frontier.end()){
        CurrentCity=*FrontierNumber;
        if(*LowestPathDistance>CurrentCity.AccumulatedDistance +
                               CurrentCity.StraightLineDistance){
            *LowestPathDistance=CurrentCity.AccumulatedDistance +
                                CurrentCity.StraightLineDistance;
            LowestNodeNumber=FrontierNumber;
        }
        FrontierNumber++;
    }
    CurrentCity=*LowestNodeNumber;
    Frontier.erase(LowestNodeNumber);
    return CurrentCity;
}

bool AStarSearch(string StartName, string GoalName){
    vector<City>::iterator	CityNumber;

    City		CurrentCity;
    City		StartCity;
    City		ChildCity;

    Neighbor	CurrentNeighbor;

    bool		StartCityFound=false;
    bool		GoalFound=false;

    int		MinPossibleDistance=0;
    int		GoalDistance=0;

    string		GoalPath;

    if(StartName=="" || GoalName=="") return false;

//Search for Start Location Match

    for(CityNumber=Cities.begin();CityNumber<Cities.end();CityNumber++){
        CurrentCity=*CityNumber;
        if(CurrentCity.Name==StartName)
        {
            StartCity=CurrentCity;
            StartCityFound=true;
            StartCity.AccumulatedPath=StartName;
        }
    }

    if(StartCityFound==false) return false;

    Frontier.push_back(StartCity);

    cout<<"\nRecording Exploratory Process:\n"<<"Start Location: "<<
        StartName<<"\t Ending Location: "<<GoalName<<endl;

//Get Next Location on the Frontier

    while(!Frontier.empty() && (GoalDistance>MinPossibleDistance || GoalFound==false)){
        CurrentCity=FindShortestPath(&MinPossibleDistance);
        if(GoalDistance>MinPossibleDistance || GoalFound==false){
            for(	CurrentCity.NeighborNumber=CurrentCity.Neighbors.begin();
                    CurrentCity.NeighborNumber<CurrentCity.Neighbors.end();
                    CurrentCity.NeighborNumber++)
            {
                CurrentNeighbor=*CurrentCity.NeighborNumber;
                if(GetChildCity(CurrentNeighbor, &ChildCity)==false){
                    cout<<"Child City not found - Terminating\n";
                    return false;
                }

                ChildCity.AccumulatedPath=CurrentCity.AccumulatedPath +
                                          " - " + ChildCity.Name;
                ChildCity.AccumulatedDistance=CurrentCity.AccumulatedDistance +
                                              CurrentNeighbor.Distance;
                cout<<"Current Expanded Path: "<<ChildCity.AccumulatedPath<<
                    " Distance: "<<ChildCity.AccumulatedDistance<<endl;

                if(ChildCity.Name==GoalName){
                    GoalDistance=ChildCity.AccumulatedDistance;
                    GoalPath=ChildCity.AccumulatedPath;
                    cout<<"Goal Path: "<<GoalPath<<" Distance: "<<
                        GoalDistance<<endl;
                    GoalFound=true;
                }
                Frontier.push_back(ChildCity);
            }
        }
    }

    cout<<"\n\nBest Goal Path:\n";
    cout<<GoalPath<<" Distance: "<<GoalDistance<<endl;
    cout<<"Evaluation Complete\n";
    return true;
}

bool	GetChildCity(Neighbor, City*);

void	MakeMap();

City	FindShortestPath(int *LowestPathDistance);

bool 	AStarSearch(string, string);


int	main(){
    string start, end;
    MakeMap();
    cout<<"Enter start city: ";
    cin>>start;
    cout<<"Enter end city: ";
    cin>>end;
    AStarSearch(start, end);
    //AStarSearch("Arad", "Oradea");
    return 0;
}